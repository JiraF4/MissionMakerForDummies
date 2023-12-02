class PS_CommandPrint : PS_Command // "print"
{
	override PS_Variable ExecuteUnholded(PS_Variable left, PS_Variable right, PS_VirtualMachine vm) {
		string val = right.GetValueName();
		Print(val + "");
		return right;
	};
}

