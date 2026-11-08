// Ghidra script: export exact function records for explicit entry addresses.
// Same schema as ExportSporeFunctionBatch.java so BatchStaticLift.validate_function_bytes
// can verify every instruction byte against the selected PE.
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;

public class ExportSporeFunctionByAddress extends GhidraScript {
    @Override
    protected void run() throws Exception {
        if (currentProgram == null) {
            throw new IllegalStateException("Open the selected Spore program in Ghidra first.");
        }
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException(
                "usage: <output.json> <address> [<address> ...]");
        }
        File output = new File(args[0]);
        StringBuilder json = new StringBuilder(64 * 1024);
        json.append("{\"functions\": [");
        boolean first = true;
        for (int index = 1; index < args.length; index++) {
            Address entry = currentProgram.getAddressFactory().getAddress(args[index]);
            Function function = currentProgram.getFunctionManager().getFunctionAt(entry);
            if (function == null) {
                throw new IllegalStateException(
                    "no Ghidra function entry at " + args[index]);
            }
            if (!first) {
                json.append(", ");
            }
            first = false;
            json.append("{\"function\": ");
            appendFunction(json, function);
            json.append("}");
            println("exported " + function.getName() + " at " + args[index]);
        }
        json.append("]}\n");
        try (Writer writer = new OutputStreamWriter(
                new FileOutputStream(output), StandardCharsets.UTF_8)) {
            writer.write(json.toString());
        }
        println("written " + output.getAbsolutePath());
    }

    private void appendFunction(StringBuilder json, Function function) throws Exception {
        json.append("{");
        property(json, "entry", address(function.getEntryPoint()), true);
        property(json, "name", function.getName(), true);
        property(json, "calling_convention", function.getCallingConventionName(), true);
        property(json, "body_min", address(function.getBody().getMinAddress()), true);
        property(json, "body_max", address(function.getBody().getMaxAddress()), true);
        json.append("\"body_address_count\": ")
            .append(function.getBody().getNumAddresses()).append(", ");
        json.append("\"instructions\": [");
        InstructionIterator iterator = currentProgram.getListing()
            .getInstructions(function.getBody(), true);
        StringBuilder instructionJson = new StringBuilder();
        int count = 0;
        while (iterator.hasNext()) {
            Instruction instruction = iterator.next();
            if (count++ > 0) {
                instructionJson.append(", ");
            }
            instructionJson.append("{\"address\": ").append(quote(address(instruction.getAddress())));
            instructionJson.append(", \"bytes\": ").append(quote(bytesHex(instruction.getBytes())));
            instructionJson.append(", \"length\": ").append(instruction.getLength());
            instructionJson.append(", \"mnemonic\": ").append(quote(instruction.getMnemonicString()));
            instructionJson.append(", \"operands\": [");
            for (int operand = 0; operand < instruction.getNumOperands(); operand++) {
                if (operand > 0) {
                    instructionJson.append(", ");
                }
                instructionJson.append(quote(instruction.getDefaultOperandRepresentation(operand)));
            }
            instructionJson.append("], \"flow\": ").append(quote(instruction.getFlowType().toString()));
            instructionJson.append(", \"flows_to\": [");
            Address[] flows = instruction.getFlows();
            for (int flow = 0; flow < flows.length; flow++) {
                if (flow > 0) {
                    instructionJson.append(", ");
                }
                instructionJson.append(quote(address(flows[flow])));
            }
            instructionJson.append("], \"references\": [");
            Reference[] instructionRefs = currentProgram.getReferenceManager()
                .getReferencesFrom(instruction.getAddress());
            for (int reference = 0; reference < instructionRefs.length; reference++) {
                if (reference > 0) {
                    instructionJson.append(", ");
                }
                instructionJson.append("{\"to\": ")
                    .append(quote(address(instructionRefs[reference].getToAddress())));
                instructionJson.append(", \"type\": ")
                    .append(quote(instructionRefs[reference].getReferenceType().toString()));
                instructionJson.append(", \"is_call\": ")
                    .append(instructionRefs[reference].getReferenceType().isCall()).append("}");
            }
            instructionJson.append("]}");
        }
        json.append(instructionJson);
        json.append("], \"instruction_count_exported\": ").append(count);
        json.append(", \"instructions_truncated\": false");
        json.append(", \"references_truncated\": false").append("}");
    }

    private void property(StringBuilder json, String key, String value, boolean comma) {
        json.append(quote(key)).append(": ").append(quote(value));
        json.append(comma ? ", " : " ");
    }

    private String address(Address value) {
        return value == null ? null : "0x" + value.toString();
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
                case '\b': result.append("\\b"); break;
                case '\f': result.append("\\f"); break;
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
