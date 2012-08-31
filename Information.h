// --------------------
// Object information
// --------------------

// Basic object details
#define	ObjectName			"Advanced Int64 Object"
#define	ObjectAuthor		"LB"
#define	ObjectCopyright		"Copyright © 2010 LB-Stuff"
#define	ObjectComment		"This extension can handle multiple named 64 bit (8 byte) integers, both signed and unsigned (separately).\nRange 0 to 18,446,744,073,709,551,615 unsigned; -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 signed.\nCan also get and set each of the 8 bytes that make up the 64 bit integer, and loop through each of the variables that exist.\nThanks to mojofltr/lost_child for the extension icon! Additional thanks goes to Looki, Werbad, Jamie, and RickyRombo."
#define	ObjectURL			"http://www.LB-Stuff.com/"
#define	ObjectHelp			""

// If you register your object with Clickteam, change this to the ID you were given
#define ObjectRegID			REGID_PRIVATE

// Change N,O,N,E to 4 unique characters (MMF currently still uses this to keep track)
#define	IDENTIFIER			MAKEID(I,N,T,S)

// --------------------
// Version information
// --------------------

// PRODUCT_VERSION_TGF or PRODUCT_VERSION_DEVELOPER
#define ForVersion			PRODUCT_VERSION_STANDARD

// Set this to the latest MMF build out when you build the object
#define	MinimumBuild		249

// --------------------
// Beta information
// --------------------

// #define BETA
// #define POPUP_ON_DROP
// #define POPUP_ON_EXE
// #define POPUP_ON_BUILD
// #define POPUP_MESSAGE	"This is a beta extension- use with caution!"

// --------------------
// Handling priority
// --------------------
// If this extension will handle windows messages, specify the priority
// of the handling procedure, 0 = low and 255 = very high

#define	WINDOWPROC_PRIORITY 100
