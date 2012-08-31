// ============================================================================
//
// This file contains the actions, conditions and expressions your object uses
// 
// ============================================================================

#include "Common.h"

//Custom Function Definitions
	//Conversion Functions
string UInt64ToString(UInt64 Val)
{
	stringstream StrStream;
	StrStream << Val;
	return(StrStream.str());
}

UInt64 StringToUInt64(string Str)
{
	istringstream StrStream;
	StrStream.str(Str);
	UInt64 Ret;
	StrStream >>Ret;
	return(Ret);
}

string SInt64ToString(SInt64 Val)
{
	stringstream StrStream;
	StrStream << Val;
	return(StrStream.str());
}

SInt64 StringToSInt64(string Str)
{
	istringstream StrStream;
	StrStream.str(Str);
	SInt64 Ret;
	StrStream >>Ret;
	return(Ret);
}

	//Main Functions
unsigned int FindUVar(LPRDATA rdPtr, string UVarName)
{
	unsigned int i;
	for(i = 0; i < rdPtr->UIndex->size(); i++)
	{
		if((*rdPtr->UIndex)[i] == UVarName)
		{
			return(i);
		}
	}
	rdPtr->UIndex->resize(rdPtr->UIndex->size()+1, UVarName);
	rdPtr->UVars->resize(rdPtr->UVars->size()+1, 0);
	return(i);
}

unsigned int FindSVar(LPRDATA rdPtr, string SVarName)
{
	unsigned int i;
	for(i = 0; i < rdPtr->SIndex->size(); i++)
	{
		if((*rdPtr->SIndex)[i] == SVarName)
		{
			return(i);
		}
	}
	rdPtr->SIndex->resize(rdPtr->SIndex->size()+1, SVarName);
	rdPtr->SVars->resize(rdPtr->SVars->size()+1, 0);
	return(i);
}

	/*Random Functions
UInt64 URandom(UInt64 Min, UInt64 Max) //Unsigned
{
	srand(clock());

	int Temp = rand();
	UInt64 Final = (UInt64)Temp;

	//Generate seeds for this 64 bit integer random function
	int Seeds[200];
	for(unsigned char i = 0; i < 200; i++)
	{
		Seeds[i] = rand();
	}

	//Using the seeds, run a loop a whole lotta times, and use random to either add, subtract, multiply, or divide the Final result by one of the random numbers from a random position in the seeds array
	for(unsigned short i = 0; i < 1000; i++)
	{
		switch (rand() % 4)
		{
		case 0:
			Final += Seeds[rand() % 200];
			break;
		case 1:
			Final -= Seeds[rand() % 200];
			break;
		case 2:
			Final *= Seeds[rand() % 200];
			break;
		case 3:
			Final /= Seeds[rand() % 200];
			break;
		}
	}

	//The final result should be within the bounds specified by the function parameters
	UInt64 Range = 1;
	Range += Max;
	Range -= Min;
	Final %= Range;
	Final += Min;
	return(Final);
}

SInt64 SRandom(SInt64 Min, SInt64 Max) //Unsigned
{
	srand(clock());

	int Temp = rand();
	SInt64 Final = (SInt64)Temp;

	//Generate seeds for this 64 bit integer random function
	int Seeds[200];
	for(unsigned char i = 0; i < 200; i++)
	{
		Seeds[i] = rand();
	}

	//Using the seeds, run a loop a whole lotta times, and use random to either add, subtract, multiply, or divide the Final result by one of the random numbers from a random position in the seeds array
	for(unsigned short i = 0; i < 1000; i++)
	{
		switch (rand() % 4)
		{
		case 0:
			Final += Seeds[rand() % 200];
			break;
		case 1:
			Final -= Seeds[rand() % 200];
			break;
		case 2:
			Final *= Seeds[rand() % 200];
			break;
		case 3:
			Final /= Seeds[rand() % 200];
			break;
		}
	}

	//The final result should be within the bounds specified by the function parameters
	SInt64 Range = 1;
	Range += Max;
	Range -= Min;
	Final %= Range;
	Final += Min;
	return(Final);
}*/

// ============================================================================
//
// CONDITIONS
// 
// ============================================================================

	/* ******* UNSIGNED ******* */
CONDITION(
	/* ID */			0,
	/* Name */			"%0 == %1 (Unsigned)",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int UVarIndexA = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int UVarIndexB = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->UVars)[UVarIndexA] == (*rdPtr->UVars)[UVarIndexB]);
}

CONDITION(
	/* ID */			1,
	/* Name */			"%0 >= %1 (Unsigned)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int UVarIndexA = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int UVarIndexB = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->UVars)[UVarIndexA] >= (*rdPtr->UVars)[UVarIndexB]);
}

CONDITION(
	/* ID */			2,
	/* Name */			"%0 > %1 (Unsigned)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int UVarIndexA = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int UVarIndexB = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->UVars)[UVarIndexA] > (*rdPtr->UVars)[UVarIndexB]);
}

CONDITION(
	/* ID */			3,
	/* Name */			"%0 <= %1 (Unsigned)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int UVarIndexA = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int UVarIndexB = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->UVars)[UVarIndexA] <= (*rdPtr->UVars)[UVarIndexB]);
}

CONDITION(
	/* ID */			4,
	/* Name */			"%0 < %1 (Unsigned)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int UVarIndexA = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int UVarIndexB = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->UVars)[UVarIndexA] < (*rdPtr->UVars)[UVarIndexB]);
}

	/* ******* SIGNED ******* */
CONDITION(
	/* ID */			5,
	/* Name */			"%0 == %1 (Signed)",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int SVarIndexA = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int SVarIndexB = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->SVars)[SVarIndexA] == (*rdPtr->SVars)[SVarIndexB]);
}

CONDITION(
	/* ID */			6,
	/* Name */			"%0 >= %1 (Signed)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int SVarIndexA = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int SVarIndexB = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->SVars)[SVarIndexA] >= (*rdPtr->SVars)[SVarIndexB]);
}

CONDITION(
	/* ID */			7,
	/* Name */			"%0 > %1 (Signed)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int SVarIndexA = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int SVarIndexB = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->SVars)[SVarIndexA] > (*rdPtr->SVars)[SVarIndexB]);
}

CONDITION(
	/* ID */			8,
	/* Name */			"%0 <= %1 (Signed)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int SVarIndexA = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int SVarIndexB = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->SVars)[SVarIndexA] <= (*rdPtr->SVars)[SVarIndexB]);
}

CONDITION(
	/* ID */			9,
	/* Name */			"%0 < %1 (Signed)",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(2,PARAM_STRING,"Variable A",PARAM_STRING,"Variable B")
) {
	unsigned int SVarIndexA = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned int SVarIndexB = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));

	return((*rdPtr->SVars)[SVarIndexA] < (*rdPtr->SVars)[SVarIndexB]);
}

	/* ******* Loops ******* */
CONDITION(
	/* ID */			10,
	/* Name */			"%o: On Unsigned Variable Loop",
	/* Flags */			0,
	/* Params */		(0)
) {
	return(true);
}

CONDITION(
	/* ID */			11,
	/* Name */			"%o: On Signed Variable Loop",
	/* Flags */			0,
	/* Params */		(0)
) {
	return(true);
}

	/* ******* Misc ******* */
CONDITION(
	/* ID */			12,
	/* Name */			"%o: Unsigned Variable %0 Exists",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(1,PARAM_STRING,"Variable Name")
) {
	string LookFor = string((char *)Param(TYPE_STRING));
	for(unsigned int i = 0; i < rdPtr->UIndex->size(); i++)
	{
		if((*rdPtr->UIndex)[i] == LookFor)
		{
			return(true);
		}
	}
	return(false);
}

CONDITION(
	/* ID */			13,
	/* Name */			"%o: Signed Variable %0 Exists",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(1,PARAM_STRING,"Variable Name")
) {
	string LookFor = string((char *)Param(TYPE_STRING));
	for(unsigned int i = 0; i < rdPtr->SIndex->size(); i++)
	{
		if((*rdPtr->SIndex)[i] == LookFor)
		{
			return(true);
		}
	}
	return(false);
}

// ============================================================================
//
// ACTIONS
// 
// ============================================================================

	/* ******* UNSIGNED ******* */
ACTION(
	/* ID */			0,
	/* Name */			"Unsigned: Set %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Set the Variable to")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] = StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			1,
	/* Name */			"Unsigned: Add %1 to %0",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Add to the Variable")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] += StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			2,
	/* Name */			"Unsigned: Subtract %1 from %0",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Subtract from the Variable")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] -= StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			3,
	/* Name */			"Unsigned: Multiply %0 by %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Multiply the Variable by")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] *= StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			4,
	/* Name */			"Unsigned: Divide %0 by %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Divide the Variable by")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] /= StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			5,
	/* Name */			"Unsigned: Raise %0 to the power of %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Raise the Variable to the Power of")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] ^= StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			6,
	/* Name */			"Unsigned: Set %0 to %0 mod %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to perform the Modulo operator with the Variable")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->UVars)[UVarIndex] %= StringToUInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			7,
	/* Name */			"Unsigned: Set Byte %1 in %0 to %2",
	/* Flags */			0,
	/* Params */		(3,PARAM_STRING,"Name of Variable",PARAM_NUMBER,"Byte to Adjust (0-7)",PARAM_NUMBER,"Unsigned Byte Value (0-255)")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned char AdjustChar = (unsigned char)Param(TYPE_INT) % 8;
	unsigned char AdjustCharVal = (unsigned char)Param(TYPE_INT);
	((char *) &(*rdPtr->UVars)[UVarIndex])[AdjustChar] = AdjustCharVal;
}

ACTION(
	/* ID */			8,
	/* Name */			"Unsigned: Delete %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Name of Variable to Delete")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)Param(TYPE_STRING)));
	rdPtr->UIndex->erase(rdPtr->UIndex->begin()+UVarIndex);
	rdPtr->UVars->erase(rdPtr->UVars->begin()+UVarIndex);
}

ACTION(
	/* ID */			9,
	/* Name */			"Unsigned: Delete All Variables",
	/* Flags */			0,
	/* Params */		(0)
) {
	rdPtr->UIndex->clear();
	rdPtr->UVars->clear();
}

	/* ******* SIGNED ******* */
ACTION(
	/* ID */			10,
	/* Name */			"Signed: Set %0 to %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Set the Variable to")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] = StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			11,
	/* Name */			"Signed: Add %1 to %0",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Add to the Variable")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] += StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			12,
	/* Name */			"Signed: Subtract %1 from %0",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Subtract from the Variable")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] -= StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			13,
	/* Name */			"Signed: Multiply %0 by %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Multiply the Variable by")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] *= StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			14,
	/* Name */			"Signed: Divide %0 by %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Divide the Variable by")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] /= StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			15,
	/* Name */			"Signed: Raise %0 to the power of %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to Raise the Variable to the Power of")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] ^= StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			16,
	/* Name */			"Signed: Set %0 to %0 mod %1",
	/* Flags */			0,
	/* Params */		(2,PARAM_STRING,"Name of Variable to Modify",PARAM_STRING,"Value to perform the Modulo operator with the Variable")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	(*rdPtr->SVars)[SVarIndex] %= StringToSInt64(string((char *)Param(TYPE_STRING)));
}

ACTION(
	/* ID */			17,
	/* Name */			"Signed: Set Byte %1 in %0 to %2",
	/* Flags */			0,
	/* Params */		(3,PARAM_STRING,"Name of Variable",PARAM_NUMBER,"Byte to Adjust (0-7)",PARAM_NUMBER,"Unsigned Byte Value (0-255)")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	unsigned char AdjustChar = (unsigned char)Param(TYPE_INT) % 8;
	unsigned char AdjustCharVal = (unsigned char)Param(TYPE_INT);
	((char *) &(*rdPtr->SVars)[SVarIndex])[AdjustChar] = AdjustCharVal;
}

ACTION(
	/* ID */			18,
	/* Name */			"Signed: Delete %0",
	/* Flags */			0,
	/* Params */		(1,PARAM_STRING,"Name of Variable to Delete")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)Param(TYPE_STRING)));
	rdPtr->SIndex->erase(rdPtr->SIndex->begin()+SVarIndex);
	rdPtr->SVars->erase(rdPtr->SVars->begin()+SVarIndex);
}

ACTION(
	/* ID */			19,
	/* Name */			"Signed: Delete All Variables",
	/* Flags */			0,
	/* Params */		(0)
) {
	rdPtr->SIndex->clear();
	rdPtr->SVars->clear();
}

	/* ******* Loops ******* */
ACTION(
	/* ID */			20,
	/* Name */			"Loop Through Variables (Mode=%0)",
	/* Flags */			0,
	/* Params */		(1,PARAM_NUMBER,"0 = unsigned, 1 = signed, anything else = both")
) {
	char Type = (char)Param(TYPE_INT);
	if(Type != 1)
	{
		for(rdPtr->UVarsIterator = 0; rdPtr->UVarsIterator < rdPtr->UIndex->size(); rdPtr->UVarsIterator++)
		{
			rdPtr->rRd->GenerateEvent(10);
		}
	}
	if(Type != 0)
	{
		for(rdPtr->SVarsIterator = 0; rdPtr->SVarsIterator < rdPtr->SIndex->size(); rdPtr->SVarsIterator++)
		{
			rdPtr->rRd->GenerateEvent(11);
		}
	}
}

// ============================================================================
//
// EXPRESSIONS
// 
// ============================================================================

EXPRESSION(
	/* ID */			0,
	/* Name */			"GetUnsignedVar$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(1,EXPPARAM_STRING,"Variable Name")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)ExParam(TYPE_STRING)));
	string RetStr = UInt64ToString((*rdPtr->UVars)[UVarIndex]);
	ReturnStringSafe(RetStr.c_str());
}

EXPRESSION(
	/* ID */			1,
	/* Name */			"GetSignedVar$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(1,EXPPARAM_STRING,"Variable Name")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)ExParam(TYPE_STRING)));
	string RetStr = SInt64ToString((*rdPtr->SVars)[SVarIndex]);
	ReturnStringSafe(RetStr.c_str());
}

EXPRESSION(
	/* ID */			2,
	/* Name */			"GetUnsignedVarByte(",
	/* Flags */			0,
	/* Params */		(2,EXPPARAM_STRING,"Variable Name",EXPPARAM_LONG,"Byte to Get (0-7)")
) {
	unsigned int UVarIndex = FindUVar(rdPtr, string((char *)ExParam(TYPE_STRING)));
	UInt64 Temp = (*rdPtr->UVars)[UVarIndex];
	return(((char *) &Temp)[ExParam(TYPE_INT) % 8]);
}

EXPRESSION(
	/* ID */			3,
	/* Name */			"GetSignedVarByte(",
	/* Flags */			0,
	/* Params */		(2,EXPPARAM_STRING,"Variable Name",EXPPARAM_LONG,"Byte to Get (0-7)")
) {
	unsigned int SVarIndex = FindSVar(rdPtr, string((char *)ExParam(TYPE_STRING)));
	UInt64 Temp = (*rdPtr->SVars)[SVarIndex];
	return(((char *) &Temp)[ExParam(TYPE_INT) % 8]);
}

/* ******* Loops ******* */
EXPRESSION(
	/* ID */			4,
	/* Name */			"GetUnsignedVarName$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(0)
) {
	string RetStr = (*rdPtr->UIndex)[rdPtr->UVarsIterator];
	ReturnStringSafe(RetStr.c_str());
}

EXPRESSION(
	/* ID */			5,
	/* Name */			"GetSignedVarName$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(0)
) {
	string RetStr = (*rdPtr->SIndex)[rdPtr->SVarsIterator];
	ReturnStringSafe(RetStr.c_str());
}

/* ******* ******* ******* Quickspressions ******* ******* ******* */


/* ******* *******          ******* ******* *\
|* ******* ******* UNSIGNED ******* ******* *|
\* ******* *******          ******* ******* */
EXPRESSION(
	/* ID */			6,
	/* Name */			"UAdd$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt64 A = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 B = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	A += B;
	string Temp = UInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			7,
	/* Name */			"USub$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt64 A = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 B = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	A -= B;
	string Temp = UInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			8,
	/* Name */			"UMul$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt64 A = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 B = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	A *= B;
	string Temp = UInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			9,
	/* Name */			"UDiv$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt64 A = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 B = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	A /= B;
	string Temp = UInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			10,
	/* Name */			"UPow$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt64 A = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 B = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	A ^= B;
	string Temp = UInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			11,
	/* Name */			"UMod$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	UInt64 A = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 B = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	A %= B;
	string Temp = UInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}



/* ******* *******          ******* ******* *\
|* ******* *******  SIGNED  ******* ******* *|
\* ******* *******          ******* ******* */
EXPRESSION(
	/* ID */			12,
	/* Name */			"SAdd$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt64 A = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 B = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	A += B;
	string Temp = SInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			13,
	/* Name */			"SSub$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt64 A = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 B = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	A -= B;
	string Temp = SInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			14,
	/* Name */			"SMul$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt64 A = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 B = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	A *= B;
	string Temp = SInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			15,
	/* Name */			"SDiv$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt64 A = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 B = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	A /= B;
	string Temp = SInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			16,
	/* Name */			"SPow$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt64 A = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 B = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	A ^= B;
	string Temp = SInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID */			17,
	/* Name */			"SMod$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(2,EXPPARAM_STRING,"A",EXPPARAM_STRING,"B")
) {
	SInt64 A = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 B = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	A %= B;
	string Temp = SInt64ToString(A);
	ReturnStringSafe(Temp.c_str());
}

/* ******* ******* ******* Random ******* ******* ******* * /
EXPRESSION(
	/* ID * /			18,
	/* Name * /			"URandom$(",
	/* Flags * /			EXPFLAG_STRING,
	/* Params * /		(2,EXPPARAM_STRING,"Min",EXPPARAM_STRING,"Max")
) {
	UInt64 Min = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 Max = StringToUInt64(string((char *)ExParam(TYPE_STRING)));
	UInt64 Result = URandom(Min, Max);
	string Temp = UInt64ToString(Result);
	ReturnStringSafe(Temp.c_str());
}

EXPRESSION(
	/* ID * /			19,
	/* Name * /			"SRandom$(",
	/* Flags * /			EXPFLAG_STRING,
	/* Params * /		(2,EXPPARAM_STRING,"Min",EXPPARAM_STRING,"Max")
) {
	SInt64 Min = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 Max = StringToSInt64(string((char *)ExParam(TYPE_STRING)));
	SInt64 Result = SRandom(Min, Max);
	string Temp = SInt64ToString(Result);
	ReturnStringSafe(Temp.c_str());
}*/