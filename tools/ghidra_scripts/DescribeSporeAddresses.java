// Ghidra script: report the containing function and first instruction for
// explicit addresses, so callers can tell function entries from interior code.
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;

public class DescribeSporeAddresses extends GhidraScript {
    @Override
    protected void run() throws Exception {
        if (currentProgram == null) {
            throw new IllegalStateException("Open the selected Spore program in Ghidra first.");
        }
        for (String argument : getScriptArgs()) {
            Address address = currentProgram.getAddressFactory().getAddress(argument);
            Function entry = currentProgram.getFunctionManager().getFunctionAt(address);
            Function containing = currentProgram.getFunctionManager().getFunctionContaining(address);
            Instruction instruction = currentProgram.getListing().getInstructionAt(address);
            String instructionText = instruction == null
                ? "<no instruction>"
                : instruction.getMnemonicString() + " " + instruction.getDefaultOperandRepresentation(0)
                    + " (" + instruction.getAddress() + ", " + instruction.getLength() + " bytes)";
            println(argument
                + " entry=" + (entry == null ? "null" : entry.getEntryPoint() + " " + entry.getName())
                + " containing=" + (containing == null
                    ? "null"
                    : containing.getEntryPoint() + " " + containing.getName()
                        + " body=" + containing.getBody().getMinAddress()
                        + ".." + containing.getBody().getMaxAddress())
                + " instruction=" + instructionText);
        }
    }
}
