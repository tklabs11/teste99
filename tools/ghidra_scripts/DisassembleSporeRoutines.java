// Ghidra script: recursive-descent disassembly of explicit routine entries.
// Used for CRT routines that Ghidra's analysis never reached (no function and no
// instructions). Works on a throwaway -noanalysis import and writes the same
// record schema as ExportSporeFunctionBatch.java.
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeMap;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

public class DisassembleSporeRoutines extends GhidraScript {
    private static final int MAX_INSTRUCTIONS = 16_384;
    private static final long MAX_SPAN = 0x8000L;

    @Override
    protected void run() throws Exception {
        if (currentProgram == null) {
            throw new IllegalStateException("Open the selected Spore program in Ghidra first.");
        }
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException("usage: <output.json> <address> [<address> ...]");
        }
        File output = new File(args[0]);
        StringBuilder json = new StringBuilder(64 * 1024);
        json.append("{\"functions\": [");
        boolean firstRecord = true;
        for (int index = 1; index < args.length; index++) {
            Address entry = currentProgram.getAddressFactory().getAddress(args[index]);
            TreeMap<Long, Instruction> body = disassembleRoutine(entry);
            if (body.isEmpty()) {
                throw new IllegalStateException("nothing decoded at " + args[index]);
            }
            if (!firstRecord) {
                json.append(", ");
            }
            firstRecord = false;
            json.append("{\"function\": ");
            appendRecord(json, entry, body);
            json.append("}");
            println("decoded " + body.size() + " instructions at " + args[index]
                + " spanning 0x" + Long.toHexString(body.firstKey()) + "..0x"
                + Long.toHexString(body.lastKey()));
        }
        json.append("]}\n");
        try (Writer writer = new OutputStreamWriter(
                new FileOutputStream(output), StandardCharsets.UTF_8)) {
            writer.write(json.toString());
        }
        println("written " + output.getAbsolutePath());
    }

    private TreeMap<Long, Instruction> disassembleRoutine(Address entry) {
        TreeMap<Long, Instruction> decoded = new TreeMap<>();
        Deque<Long> pending = new ArrayDeque<>();
        Set<Long> visited = new HashSet<>();
        Function entryFunction = getFunctionContaining(entry);
        long min = entry.getOffset();
        long max = entry.getOffset() + MAX_SPAN;
        pending.add(entry.getOffset());
        while (!pending.isEmpty() && decoded.size() < MAX_INSTRUCTIONS) {
            long offset = pending.removeFirst();
            if (!visited.add(offset) || offset < min || offset >= max) {
                continue;
            }
            Address address = currentProgram.getAddressFactory()
                .getDefaultAddressSpace().getAddress(offset);
            Instruction instruction = currentProgram.getListing().getInstructionAt(address);
            if (instruction == null) {
                disassemble(address);
                instruction = currentProgram.getListing().getInstructionAt(address);
            }
            if (instruction == null) {
                println("decode failed at 0x" + Long.toHexString(offset));
                continue;
            }
            decoded.put(offset, instruction);
            String mnemonic = instruction.getMnemonicString().toUpperCase();
            long fallthrough = instruction.getMaxAddress().getOffset() + 1;
            boolean conditional = instruction.getFlowType().isConditional();
            boolean isCall = instruction.getFlowType().isCall();
            boolean isJump = instruction.getFlowType().isJump();
            if (isCall) {
                pending.add(fallthrough);
                continue;
            }
            if (isJump) {
                Address[] flows = instruction.getFlows();
                for (Address flow : flows) {
                    if (flow == null) {
                        continue;
                    }
                    // An unconditional jump into another function is a tail
                    // call: the body ends here and the target is measured on its
                    // own. A conditional branch must still be followed, because
                    // compilers merge identical tails into a neighbouring
                    // function's address range.
                    Function flowFunction = getFunctionContaining(flow);
                    if (!conditional && entryFunction != null
                            && flowFunction != null
                            && !entryFunction.equals(flowFunction)) {
                        continue;
                    }
                    pending.add(flow.getOffset());
                }
                if (conditional) {
                    pending.add(fallthrough);
                }
                continue;
            }
            if (mnemonic.startsWith("RET")) {
                continue;
            }
            pending.add(fallthrough);
        }
        return decoded;
    }

    private void appendRecord(StringBuilder json, Address entry,
            TreeMap<Long, Instruction> body) throws Exception {
        long first = body.firstKey();
        long last = body.lastKey();
        long covered = 0;
        for (Instruction instruction : body.values()) {
            covered += instruction.getLength();
        }
        json.append("{");
        json.append("\"entry\": ").append(quote("0x" + entry.toString())).append(", ");
        json.append("\"name\": ").append(quote("decoded_" + entry.toString())).append(", ");
        json.append("\"body_address_count\": ").append(covered).append(", ");
        json.append("\"instructions\": [");
        boolean firstInstruction = true;
        for (Instruction instruction : body.values()) {
            if (!firstInstruction) {
                json.append(", ");
            }
            firstInstruction = false;
            json.append("{\"address\": ").append(quote("0x" + instruction.getAddress().toString()));
            json.append(", \"bytes\": ").append(quote(bytesHex(instruction.getBytes())));
            json.append(", \"length\": ").append(instruction.getLength());
            json.append(", \"mnemonic\": ").append(quote(instruction.getMnemonicString()));
            json.append(", \"operands\": [");
            for (int operand = 0; operand < instruction.getNumOperands(); operand++) {
                if (operand > 0) {
                    json.append(", ");
                }
                json.append(quote(instruction.getDefaultOperandRepresentation(operand)));
            }
            json.append("], \"flow\": ").append(quote(instruction.getFlowType().toString()));
            json.append(", \"flows_to\": [");
            Address[] flows = instruction.getFlows();
            for (int flow = 0; flow < flows.length; flow++) {
                if (flow > 0) {
                    json.append(", ");
                }
                json.append(quote("0x" + flows[flow].toString()));
            }
            json.append("], \"references\": [");
            Reference[] references = currentProgram.getReferenceManager()
                .getReferencesFrom(instruction.getAddress());
            for (int reference = 0; reference < references.length; reference++) {
                if (reference > 0) {
                    json.append(", ");
                }
                json.append("{\"to\": ").append(quote("0x" + references[reference].getToAddress().toString()));
                json.append(", \"type\": ").append(quote(references[reference].getReferenceType().toString()));
                json.append(", \"is_call\": ").append(references[reference].getReferenceType().isCall()).append("}");
            }
            json.append("]}");
        }
        json.append("], \"instruction_count_exported\": ").append(body.size());
        json.append(", \"instructions_truncated\": ").append(body.size() >= MAX_INSTRUCTIONS);
        json.append(", \"references_truncated\": false");
        json.append(", \"span\": ").append(quote("0x" + Long.toHexString(first) + "..0x" + Long.toHexString(last)));
        json.append("}");
    }

    private String bytesHex(byte[] bytes) {
        StringBuilder value = new StringBuilder(bytes.length * 2);
        for (byte item : bytes) {
            value.append(String.format("%02x", item & 0xff));
        }
        return value.toString();
    }

    private String quote(String value) {
        if (value == null) {
            return "null";
        }
        StringBuilder result = new StringBuilder(value.length() + 2);
        result.append('"');
        for (int index = 0; index < value.length(); index++) {
            char character = value.charAt(index);
            switch (character) {
                case '"': result.append("\\\""); break;
                case '\\': result.append("\\\\"); break;
                case '\n': result.append("\\n"); break;
                case '\r': result.append("\\r"); break;
                case '\t': result.append("\\t"); break;
                default:
                    if (character < 0x20) {
                        result.append(String.format("\\u%04x", (int) character));
                    } else {
                        result.append(character);
                    }
                    break;
            }
        }
        result.append('"');
        return result.toString();
    }
}
