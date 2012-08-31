// --------------------------------
// Condition menu
// --------------------------------

#ifdef CONDITION_MENU

	SEPARATOR
	SUB_START("Unsigned")
		ITEM(0,"Variable A == Variable B")
		ITEM(1,"Variable A >= Variable B")
		ITEM(2,"Variable A > Variable B")
		ITEM(3,"Variable A <= Variable B")
		ITEM(4,"Variable A < Variable B")
		ITEM(10,"On Variable Loop")
	SUB_END
	SUB_START("Signed")
		ITEM(5,"Variable A == Variable B")
		ITEM(6,"Variable A >= Variable B")
		ITEM(7,"Variable A > Variable B")
		ITEM(8,"Variable A <= Variable B")
		ITEM(9,"Variable A < Variable B")
		ITEM(11,"On Variable Loop")
	SUB_END
	SEPARATOR
	ITEM(12,"Unsigned Variable Exists")
	ITEM(13,"Signed Variable Exists")

#endif

// --------------------------------
// Action menu
// --------------------------------

#ifdef ACTION_MENU

	// You have access to edPtr and you can throw in normal C++
	// code wherever you want in any of these menus. If you want to
	// show certain conditions based on a property (a la OINC socket)
	// use the property's value stored in edPtr:

	// if(edPtr->ShowAdvancedOptions)
	// {
	//		SUB_START("Bake pie")
	//			ITEM(0, "Apple pie")
	//			ITEM(1, "Mince pie")
	//		SUB_END
	// }
	// else
	// {
	//		ITEM(0, "Bake apple pie")
	// }

	// You could do some pretty cool stuff with this, like loading a
	// menu from an external source (ActiveX object?)

	// for(int i=0;i<edPtr->ActionCount;i++)
	//		ITEM(i,edPtr->Actions[i])

	// This will run every time the menu is opened in MMF2, so don't
	// make it too slow or it could get annoying

	SEPARATOR
	SUB_START("Unsigned")
		ITEM(0,"Set Variable")
		ITEM(1,"Add to Variable")
		ITEM(2,"Subtract from Variable")
		ITEM(3,"Multiply Variable")
		ITEM(4,"Divide Variable")
		ITEM(5,"Raise Variable to Power")
		ITEM(6,"Perform Modulo on Variable")
		ITEM(7,"Set Byte in Variable")
		ITEM(8,"Delete Variable")
		ITEM(9,"Delete All Variables")
	SUB_END
	SUB_START("Signed")
		ITEM(10,"Set Variable")
		ITEM(11,"Add to Variable")
		ITEM(12,"Subtract from Variable")
		ITEM(13,"Multiply Variable")
		ITEM(14,"Divide Variable")
		ITEM(15,"Raise Variable to Power")
		ITEM(16,"Perform Modulo on Variable")
		ITEM(17,"Set Byte in Variable")
		ITEM(18,"Delete Variable")
		ITEM(19,"Delete All Variables")
	SUB_END
	ITEM(20,"Loop Through Variables")
	SEPARATOR

#endif


// --------------------------------
// Expression menu
// --------------------------------

#ifdef EXPRESSION_MENU

	SEPARATOR
	ITEM(0,"Get Unsigned Variable")
	ITEM(1,"Get Signed Variable")
	SEPARATOR
	ITEM(2,"Get Unsigned Variable Byte")
	ITEM(3,"Get Signed Variable Byte")
	SEPARATOR
	ITEM(4,"Loop: Get Unsigned Variable Name")
	ITEM(5,"Loop: Get Signed Variable Name")
	SEPARATOR
	SUB_START("Quick Expressions")
		SUB_START("Unsigned")
			ITEM(6, "A + B")
			ITEM(7, "A - B")
			ITEM(8, "A * B")
			ITEM(9, "A / B")
			ITEM(10,"A ^ B")
			ITEM(11,"A % B")
		SUB_END
		SUB_START("Signed")
			ITEM(12,"A + B")
			ITEM(13,"A - B")
			ITEM(14,"A * B")
			ITEM(15,"A / B")
			ITEM(16,"A ^ B")
			ITEM(17,"A % B")
		SUB_END
	SUB_END
	SEPARATOR
	ITEM(18,"Random (Unsigned)")
	ITEM(19,"Random (Signed)")
	SEPARATOR

#endif