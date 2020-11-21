#include "stdafx.h"
#include "packets.h"

void ProtocolDS(BYTE protoNum, unsigned char* aRecv, int aLen);
void aRecvPlayerInfo(PLAYER_OBJECT * pDataServer);
int  DataServerSend(unsigned char* buf, int len);
void JGPGetCharList(unsigned char * lpRecv);
void JGCharacterCreateRequest(SDHP_CREATECHARRESULT* lpMsg);



BYTE LevelSmallConvert(int level);


#define CURRENT_DB_VERSION	3
#define CHAR_SET_SIZE		18
#define CS_CLASS		0
#define CS_WEAPON1_TYPE	1
#define CS_WEAPON2_TYPE	2

#define CS_WEAPON1_DATA	12
#define CS_WEAPON2_DATA	13

#define CS_HELMET1		13
#define CS_HELMET2		9
#define CS_HELMET3		3

#define CS_ARMOR1		14
#define CS_ARMOR2		9
#define CS_ARMOR3		3

#define CS_PANTS1		14
#define CS_PANTS2		9
#define CS_PANTS3		4

#define CS_GLOVES1		15
#define CS_GLOVES2		9
#define CS_GLOVES3		4

#define CS_BOOTS1		15
#define CS_BOOTS2		9
#define CS_BOOTS3		5



#define CHECK_LIMIT(value, limit) ( ((value)<0)?FALSE:((value)>((limit)-1))?FALSE:TRUE  )
#define CHECK_LIMIT2(value, base, limit) ( ((value)<base)?FALSE:((value)>((limit)-1))?FALSE:TRUE  )
#define CHECK_CLASS(value, type) ( ((value)!=(type))?FALSE:TRUE )


#define CS_GET_CLASS(x) ( (((x)>>4)<<5)&(0xE0) )
#define CS_GET_CHANGEUP(x) ( ((x)&0x07) )
#define CS_SET_CLASS(x) ( ((x)<<5)& 0xE0 )
#define CS_SET_CHANGEUP(x) ( ((x) << 4) & 0x10 )

#define CS_SET_HELMET1(x) ( ((x) & 0x1E0) >> 5 )
#define CS_SET_HELMET2(x) ( ((x) & 0x10 ) << 3 )
#define CS_SET_HELMET3(x) ( ((x) & 0x0F ) << 4 )

#define CS_SET_ARMOR1(x) ( ((x) & 0x1E0) >> 1 )
#define CS_SET_ARMOR2(x) ( ((x) & 0x10 ) << 2 )
#define CS_SET_ARMOR3(x) ( ((x) & 0x0F )      )

#define CS_SET_PANTS1(x) ( ((x) & 0x1E0) >> 5 )
#define CS_SET_PANTS2(x) ( ((x) & 0x10 ) << 1 )
#define CS_SET_PANTS3(x) ( ((x) & 0x0F ) << 4 )

#define CS_SET_GLOVES1(x) ( ((x) & 0x1E0) >> 1 )
#define CS_SET_GLOVES2(x) ( ((x) & 0x10 )      )
#define CS_SET_GLOVES3(x) ( ((x) & 0x0F )      )

#define CS_SET_BOOTS1(x) ( ((x) & 0x1E0) >> 5 )
#define CS_SET_BOOTS2(x) ( ((x) & 0x10 ) >> 1 )
#define CS_SET_BOOTS3(x) ( ((x) & 0x0F ) << 4 )

#define CS_SET_WING1(x)  ( ((x) & 0x03 ) << 2 )
#define CS_SET_HELPER(x) ( ((x) & 0x03 )      )
#define MAX_ACCOUNT_LEN 10
#define CS_SET_SMALLLEVEL_RH(x)		( (x)       )
#define CS_SET_SMALLLEVEL_LH(x)		( (x) << 3  ) 
#define CS_SET_SMALLLEVEL_HELMET(x)	( (x) << 6  )
#define CS_SET_SMALLLEVEL_ARMOR(x)	( (x) << 9  )
#define CS_SET_SMALLLEVEL_PANTS(x)	( (x) << 12 )
#define CS_SET_SMALLLEVEL_GLOVES(x)	( (x) << 15 )
#define CS_SET_SMALLLEVEL_BOOTS(x)	( (x) << 18 )

#define CS_SET_SMALLLEVEL1(x)		( ((x) >> 16) & 0xFF )
#define CS_SET_SMALLLEVEL2(x)		( ((x) >> 8 ) & 0xFF )
#define CS_SET_SMALLLEVEL3(x)		((x) & 0xFF )

#define MAX_TYPE_PLAYER 5
#define MAX_ITEM_LEVEL	15
// ItemAttribute Begin:9439368 END 9446B68 Array[512]
// **************************
// Item Limits
// **************************
#define MAX_TYPE_ITEMS 16
#define MAX_SUBTYPE_ITEMS 512
#define MAX_EXOPTION_SIZE 8
// **************
// Pet Level
// **************
#define MAX_PET_LEVEL 50
#define MAX_ITEM_DURABILITY	255
#define MAX_ITEMS (MAX_TYPE_ITEMS * MAX_SUBTYPE_ITEMS)
#define MAX_ITEM_SPECIAL_ATTRIBUTE 7

#define DBI_GET_TYPE(x) ( ((x)&((MAX_TYPE_ITEMS-1)<<8))>>4 )
#define DBI_GET_INDEX(x) ( (x) & 0xFF )
#define DBI_GET_LEVEL(x)  ( ((x)>>3)& MAX_ITEM_LEVEL )
#define DBI_GET_SKILL(x)  ( ((x) >> 7) & 0x01 )
#define DBI_GET_LUCK(x)  ( ((x) >> 2) & 0x01)
#define DBI_GET_OPTION(x)  ( ( (x) ) & 0x03 )
#define DBI_GET_OPTION16(x) ( (x) & 0x40  )
#define DBI_GET_DINO_OPTION(x)  ( DBI_GET_OPTION16((x)) >> 4 )
#define DBI_GET_NOPTION(x)  ( (x) & 0x3F  )
#define DBI_GET_380OPTION(x) ( ((x) & 0x08) << 4  )
#define ITEM_GET_TYPE(x)  ( (x)/MAX_SUBTYPE_ITEMS  )
#define ITEM_GET_INDEX(x) ( (x)%MAX_SUBTYPE_ITEMS  )

#define DBI_TYPE			0
#define DBI_OPTION_DATA		1
#define DBI_DUR				2
#define DBI_SERIAL1			3
#define DBI_SERIAL2			4
#define DBI_SERIAL3			5
#define DBI_SERIAL4			6
#define DBI_NOPTION_DATA	7
#define DBI_SOPTION_DATA	8
#define DBI_OPTION380_DATA	9
#define DBI_JOH_DATA		10

#define MAX_ITEM_INFO	7

#define I_TYPE		0
#define I_OPTION	1
#define I_DUR		2
#define I_NOPTION	3
#define I_SOPTION	4
#define I_380OPTION	5
#define I_JOHOPTION	6

#define ITEM_DUR_RANGE(x) (((x)<0)?FALSE:((x)>MAX_ITEM_DURABILITY-1)?FALSE:TRUE)

#define gObjIsAccontConnect ((BOOL(*)(int aIndex, char *accountid)) 0x4EBAE0)
#define CloseClient			((void(*)(int aIndex)) 0x49D930)
