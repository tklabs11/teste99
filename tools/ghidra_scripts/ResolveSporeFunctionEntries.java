// Ghidra 12.1 resolver: maps requested addresses to their containing function
// so a lift can start at a real entry instead of a shared mid-function block.
// It reads existing analysis only and never disassembles or creates anything.
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;

public class ResolveSporeFunctionEntries extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException(
                "usage: <output.json> <address> [<address> ...]");
        }
        File output = new File(args[0]);
        FunctionManager functions =
            currentProgram.getFunctionManager();
        StringBuilder json = new StringBuilder();
        json.append("{\"addresses\":[");
        for (int index = 1; index < args.length; index++) {
            if (index > 1) {
                json.append(",");
            }
            String text = args[index].trim();
            Address address = toAddr(text);
            Function at = functions.getFunctionAt(address);
            Function containing = functions.getFunctionContaining(address);
            Instruction instruction =
                currentProgram.getListing().getInstructionAt(address);
            json.append("{\"address\":\"").append(address).append("\"");
            json.append(",\"function_at\":");
            json.append(at == null ? "null"
                : "\"" + at.getEntryPoint() + "\"");
            json.append(",\"function_containing\":");
            json.append(containing == null ? "null"
                : "\"" + containing.getEntryPoint() + "\"");
            json.append(",\"instruction_start\":")
                .append(instruction != null);
            json.append("}");
        }
        json.append("]}");
        try (Writer writer = new OutputStreamWriter(
                new FileOutputStream(output), StandardCharsets.UTF_8)) {
            writer.write(json.toString());
        }
        println("resolved " + (args.length - 1) + " addresses into "
            + output.getAbsolutePath());
    }
}
