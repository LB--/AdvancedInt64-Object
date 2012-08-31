class rRundata;
typedef rRundata * LPRRDATA;

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// If you want to store anything between actions/conditions/expressions
// you should store it here

typedef struct tagRDATA
{
	#include "MagicRDATA.h"

	vector<string>* UIndex;
	vector<UInt64>* UVars;
	vector<string>* SIndex;
	vector<SInt64>* SVars;
	unsigned long UVarsIterator;
	unsigned long SVarsIterator;
	
	
} RUNDATA;
typedef	RUNDATA	* LPRDATA;

// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------
// These values let you store data in your extension that will be saved in the MFA
// You should use these with properties

typedef struct tagEDATA_V1
{
	extHeader		eHeader;
//	short			swidth;
//	short			sheight;

} EDITDATA;
typedef EDITDATA * LPEDATA;