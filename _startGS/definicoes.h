#include "stdafx.h"
#include "users.h"

#define ITEMGET(x,y)            ((x)*512 + (y))

#define GS_GOBJPONTEIRO	        (0x660F078)
#define GS_GOBJTAMANHO		    (0x1968)

#define MAX_C1LEN               (255)
#define MIN_PLAYERID		    (0x1900)

#define MIN_MONSTERID		    (0)
#define MAX_MONSTERID		    (5800)

#define MAX_VIEWPORT             75 
#define MAX_VIEWPORT_MONSTER     20

#define GAMESERVER_WIDTH   550
#define GAMESERVER_HEIGHT  700

#define GS_GOBJPOINTER(aIndex)  ((aIndex * GS_GOBJTAMANHO) + GS_GOBJPONTEIRO)
#define	OBJECT_POINTER(aIndex)  ((aIndex * OBJECT_SIZE) + OBJECT_BASE)

#define OBJECT_RANGE(x)                     (((x) < 0)  ? 0: ((x) >= 10000) ? 0 :1)
#define CC_MAP_RANGE(x)                     (((x) < 18) ? 0: ((x) > 23) ? (((x) == 53 ) ? 1:0 ) :1)

#define MAX_MAP_RANGE(x)		(((x)<0)?FALSE:((x)>50-1)?FALSE:TRUE)
#define MAKE_NUMBERW(x,y)		((WORD)(((BYTE)((y)&0xFF)) | ((BYTE)((x)&0xFF)<<8 ))) 
#define SET_NUMBERH(x)			( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x)			( (BYTE)((DWORD)(x) & 0xFF) )

#define	OBJECT_MIN				6400
#define OBJECT_MAX				7400
#define	OBJECT_BASE   	        0x660F078
#define	OBJECT_SIZE   			0x1968

#define OBJ_EMPTY				-1
#define OBJ_MONSTER				2
#define OBJ_USER				1
#define OBJ_NPC					3

#define CLASS_WIZARD			0x0
#define CLASS_KNIGHT			0x1
#define CLASS_ELF				0x2
#define CLASS_MAGUMSA			0x3
#define CLASS_DARKLORD			0x4


#define MsgOutput							((void(*)(DWORD aIndex,char *szMsg, ...))	0x005077B0)
#define gObjMakePreviewCharSet				((void(*)(int)) 0x004EF330) // OK
#define GCServerCmd							((void(*)(int aIndex, BYTE type, unsigned char Cmd1, unsigned char Cmd2)) 0x00401997)
#define igObjTotalUser                      *(int*)0x0093F5858 // 567C918
#define gDisconnect                         *(int*)0x0093F585C // 567C91C
#define iServerMaxUser                      *(int*)0x006DEC10  // 735980
#define igObjCount							*(int*)0x00660F070 // 3D995F0
#define gObjGetStatPointState				((void(*)(int aIndex, short& AddPoint, short& MaxAddPoint, short& MinusPoint, short& MaxMinusPoint))                               0x005022D0)
#define GCItemListSend						((void(*)(int aIndex))                                                                                                             0x00428980)
#define GCMagicListMultiSend				((void(*)(OBJECTSTRUCT* lpObj, BYTE btListType))                                                                                   0x00435030)
#define CGRequestQuestInfo					((void(*)(int aIndex))                                                                                                             0x00452800)
#define DGGuildMemberInfoRequest			((void(*)(int aIndex))                                                                                                             0x0045BB80)
#define FriendListRequest					((void(*)(int aIndex))                                                                                                             0x0045F020)
#define gObjViewportListProtocolCreate		((void(*)(OBJECTSTRUCT*))																										   0x004F7020)
#define GCMagicAttackNumberSend				((void(*)(OBJECTSTRUCT* lpObj, BYTE MagicNumber, int usernumber,  unsigned char skillsuccess))									   0x0044AEA0)
#define MsgOutput							((void(*)(DWORD aIndex,char *szMsg, ...))	0x005077B0)
#define GDGetWarehouseList					((void(*)(int aIndex, char* AccountID)) 0x00428FA0)
#define gObjSecondProc                      ((void(*)()) 0x004F5560)
#define gObjInventoryCommit					((int(*)(int aIndex)) 0x004E5040)
#define gObjInterfaceTimeCheck				((void(*)(LPOBJ lpObj))	0x004DF780)

#define MAIN_INVENTORY_SIZE					76
#define CGSellRequestRecv					((void(*)(PMSG_SELLREQUEST * lpMsg, int aIndex)) 0x0043CE10)
#define CGPShopReqBuyItem					((void(*)(PMSG_REQ_BUYITEM_FROM_PSHOP * lpMsg, int aSourceIndex)) 0x00441B70)
#define DataSendB							((void(*)(DWORD,LPSTR,DWORD)) 0x0048BEF0)
#define DataSendB							((void(*)(DWORD,LPSTR,DWORD)) 0x0048BEF0)
#define gObjAddMonsters						((short(*)()) 0x004D8510) 
//----------------------------------------------------------------------------------------//
//definições
typedef BOOL(*pProtocolCore)(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
typedef void(*pGCServerMsgStringSend)(LPCTSTR text, int index, BYTE type);
typedef void(*pgObjCalcMaxLifePower)(int aIndex);
typedef void(*pgObjCalCharacter)(int aIndex);
typedef bool(*pgObjSetCharacter)(LPBYTE lpdata, int aIndex);
typedef void(*pGCStateInfoSend)(LPOBJ lpObj, BYTE state, int  ViewSkillState);
typedef void(*pItemSerialCreateSend)(int aIndex, BYTE MapNumber, BYTE x, BYTE y, int type, BYTE level, BYTE dur, BYTE Op1, BYTE Op2, BYTE Op3, int LootIndex, BYTE NewOption, BYTE SetOption);
typedef DWORD(*pItemGetNumberMake)(DWORD,DWORD);
typedef int(*pgObjMonsterTopHitDamageUser)(LPOBJ lp);
typedef BOOL(*pgObjMonsterDrop)(LPOBJ lpObj, LPOBJ lpTargetObj);
typedef BOOL(*pNpcTalk)(OBJECTSTRUCT * lpNpc, OBJECTSTRUCT * lpObj);
typedef void(*pGameMonsterAllAdd)();
typedef int(*pgObjAddMonster)(unsigned char);
typedef void(*pgObjSetMonster)(int, WORD);
typedef void (*pChatTargetSend)(DWORD* NpcIndex, LPSTR Buffer, int PlayerId);
typedef void(*pGCLevelUpMsgSend)(int aIndex, int iSendEffect);
typedef void(*pGCMoneySend)(int aIndex, DWORD money);
typedef int(*pDataSend)(int aIndex, unsigned char* pData, int Size);
typedef void(*pGCReFillSend)(int aIndex, WORD Life, BYTE Ipos, unsigned char flag,  WORD wShield);
typedef void(*pgObjSetBP)(int aIndex);
typedef void(*pGCManaSend)(int aIndex, short Mana, BYTE Ipos, unsigned char flag,  WORD BP);
typedef void(*pgObjTeleport)(int uIndex, int Map, int X, int Y);
typedef BYTE(*pgObjInventoryDeleteItem)(int aIndex ,int itempos);
typedef void(*pGCInventoryItemDeleteSend)(int aIndex, BYTE pos, unsigned char flag);
typedef void(*pGCKillPlayerExpSend)(int aIndex, int TargetIndex, int exp, int AttackDamage, BOOL MSBFlag);
typedef void(*pLotteryItemMix)(LPOBJ lpObj);
typedef int(*pgObjIsConnected)(int);
typedef void(*pDataSend2)(DWORD, LPSTR, DWORD);
typedef void(*pGCPkLevelSend)(int, unsigned char);
typedef void(*pgObjViewportList)(LPOBJ lpObj);
typedef void(*pGameMonsterAllCloseAnd)();
typedef bool(*pShopDataLoad)();
typedef int(*pgObjGetIndex)(char * name);
typedef void(*pCGWarehouseUseEnd)(int aIndex);
typedef short(*pgObjDel)(int aIndex);
typedef void(*pgObjCloseSet)(int aIndex, int Flag);
typedef void(*pCGPShopAnsClose)(int aIndex, BYTE btResult);
typedef void(*pGJPUserClose)(LPSTR szAccountID);
typedef void(*pJGGetCharacterInfo)(struct SDHP_DBCHAR_INFORESULT * lpMsg);
typedef void(*pGJSetCharacterInfo)(LPOBJ lpObj, int aIndex, BOOL bMapServerMove);
typedef void(*pGCInventoryItemOneSend)(int aIndex, int pos);
typedef BOOL(*pgObjAttack)(LPOBJ lpObj, LPOBJ lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo);
typedef void(*pGCDamageSend)(int aIndex, int TargetIndex, int AttackDamage, int MSBFlag, int MSBDamage, int iShieldDamage);
typedef void(*prCloseClient)(int aIndex);
typedef void(*pResponErrorCloseClient)(int aIndex);
typedef void(*pWarRequestResult)(LPSTR GuildName, int aIndex, int type);
typedef void (*pCGDurationMagicRecv) (PBYTE,int);
typedef void(*pLogAddFuncColor)(BYTE Color, char* szLog, ...);
typedef void(*pProtocolCoreDS)(BYTE protoNum, unsigned char* aRecv, int aLen);
typedef void (*pGCSendQuestPrize)(int, int, int);
typedef BOOL(__cdecl*pRecvDataParse)(_PER_IO_CONTEXT * context, int index);
typedef void (*pLogAddFunc) (unsigned char Color,char* Text, ...);
typedef void(*pChaosBoxSend)(DWORD, DWORD);
typedef int(*pChaosBoxInit)(DWORD);
typedef int(*pgObjGetItemCountInIventory)(int, WORD);
typedef int (*pGDUserItemSave)(OBJECTSTRUCT*);
typedef bool (*pgEventMonsterItemDrop)(OBJECTSTRUCT*,OBJECTSTRUCT*);

//----------------------------------------------------------------------------------------//
//definições
extern pgEventMonsterItemDrop gEventMonsterItemDrop;
extern pProtocolCore ProtocolCore;
extern pGCServerMsgStringSend GCServerMsgStringSend;
extern pgObjCalcMaxLifePower gObjCalcMaxLifePower;
extern pgObjCalCharacter gObjCalCharacter;
extern pgObjSetCharacter gObjSetCharacter;
extern pGCStateInfoSend GCStateInfoSend;
extern pItemSerialCreateSend ItemSerialCreateSend;
extern pItemGetNumberMake ItemGetNumberMake;
extern pgObjMonsterTopHitDamageUser gObjMonsterTopHitDamageUser;
extern pgObjMonsterDrop gObjMonsterDrop;
extern pNpcTalk NpcTalk;
extern pChatTargetSend ChatTargetSend;
extern pGCLevelUpMsgSend GCLevelUpMsgSend;
extern pGCMoneySend GCMoneySend;
extern pDataSend DataSend;
extern pGCReFillSend GCReFillSend;
extern pgObjSetBP gObjSetBP;
extern pGCManaSend GCManaSend;
extern pgObjTeleport gObjTeleport;
extern pgObjInventoryDeleteItem gObjInventoryDeleteItem;
extern pGCInventoryItemDeleteSend GCInventoryItemDeleteSend;
extern pGCKillPlayerExpSend GCKillPlayerExpSend;
extern pLotteryItemMix LotteryItemMix;
extern pgObjIsConnected gObjIsConnected;
extern pDataSend2 DataSend2;
extern pGCPkLevelSend GCPkLevelSend;
extern pgObjViewportList gObjViewportList;
extern pGameMonsterAllCloseAnd GameMonsterAllCloseAnd;
extern pShopDataLoad ShopDataLoad;
extern pgObjGetIndex gObjGetIndex;
extern pCGWarehouseUseEnd CGWarehouseUseEnd;
extern pgObjDel gObjDel;
extern pgObjCloseSet gObjCloseSet;
extern pCGPShopAnsClose CGPShopAnsClose;
extern pGJPUserClose GJPUserClose;
extern pJGGetCharacterInfo JGGetCharacterInfo;
extern pGJSetCharacterInfo GJSetCharacterInfo;
extern pGCInventoryItemOneSend GCInventoryItemOneSend;
extern pgObjAttack gObjAttack;
extern pGCDamageSend GCDamageSend;
extern prCloseClient rCloseClient;
extern pResponErrorCloseClient ResponErrorCloseClient;
extern pWarRequestResult WarRequestResult;
extern pCGDurationMagicRecv CGDurationMagicRecv;
extern pLogAddFuncColor LogAddFuncColor;
extern pProtocolCoreDS ProtocolCoreDS;
extern pGCSendQuestPrize GCSendQuestPrize;
extern pRecvDataParse RecvDataParse;
extern pChaosBoxInit ChaosBoxInit;
extern pChaosBoxSend ChaosBoxSend;
extern pLogAddFunc LogAddFunc;
extern pgObjGetItemCountInIventory gObjGetItemCountInIventory;
extern pGDUserItemSave GDUserItemSave;
extern pgObjAddMonster gObjAddMonster;
extern pGameMonsterAllAdd GameMonsterAllAdd;
extern pgObjSetMonster gObjSetMonster;

namespace ASM
{
	enum T
	{
		EAX		= 0x50,
		JMP		= 0xE9,
		JMPS	= 0xEB,
		JE		= 0x74,
		JNE		= 0x75,
		JGE		= 0x7D,
		NOP		= 0x90,
		CALL	= 0xE8,
		PUSH	= 0x68,
		RETN	= 0xC3,
	};
};

enum eSkillType
{
	AT_SKILL_POISON = 0x1,
	AT_SKILL_METEO = 0x2,
	AT_SKILL_THUNDER = 0x3,
	AT_SKILL_FIREBALL = 0x4,
	AT_SKILL_FLAME = 0x5,
	AT_SKILL_TELEPORT = 0x6,
	AT_SKILL_SLOW = 0x7,
	AT_SKILL_STORM = 0x8,
	AT_SKILL_EVIL = 0x9,
	AT_SKILL_HELL = 0xa,
	AT_SKILL_POWERWAVE = 0xb,
	AT_SKILL_FLASH = 0xc,
	AT_SKILL_BLAST = 0xd,
	AT_SKILL_INFERNO = 0xe,
	AT_SKILL_TARGET_TELEPORT = 0xf,
	AT_SKILL_MAGICDEFENSE = 0x10,
	AT_SKILL_ENERGYBALL = 0x11,
	AT_SKILL_BLOCKING = 0x12,
	AT_SKILL_SWORD1 = 0x13,
	AT_SKILL_SWORD2 = 0x14,
	AT_SKILL_SWORD3 = 0x15,
	AT_SKILL_SWORD4 = 0x16,
	AT_SKILL_SWORD5 = 0x17,
	AT_SKILL_CROSSBOW = 0x18,
	AT_SKILL_BOW = 0x19,
	AT_SKILL_HEALING = 0x1a,
	AT_SKILL_DEFENSE = 0x1b,
	AT_SKILL_ATTACK  = 0x1c,
	AT_SKILL_CALLMON1 = 0x1e,
	AT_SKILL_CALLMON2 = 0x1f,
	AT_SKILL_CALLMON3 = 0x20,
	AT_SKILL_CALLMON4 = 0x21,
	AT_SKILL_CALLMON5 = 0x22,
	AT_SKILL_CALLMON6 = 0x23,
	AT_SKILL_CALLMON7 = 0x24,
	AT_SKILL_WHEEL = 0x29,
	AT_SKILL_BLOWOFFURY = 0x2a,
	AT_SKILL_STRIKE = 0x2b,
	AT_SKILL_KNIGHTSPEAR = 0x2f,
	AT_SKILL_KNIGHTADDLIFE = 0x30,
	AT_SKILL_KNIGHTDINORANT = 0x31,
	AT_SKILL_ELFHARDEN = 0x33,
	AT_SKILL_PENETRATION = 0x34,
	AT_SKILL_DEFENSEDOWN = 0x37,
	AT_SKILL_SWORD6 = 0x38,
	AT_SKILL_5CROSSBOW = 0x36,
	AT_SKILL_EXPPOISON = 0x26,
	AT_SKILL_EXPICE = 0x27,
	AT_SKILL_EXPHELL = 0x28,
	AT_SKILL_EXPHELL_START = 0x3a,
	AT_SKILL_IMPROVE_AG_REFILL = 0x35,
	AT_SKILL_DEVILFIRE = 0x32,
	AT_SKILL_COMBO = 0x3b,
	AT_SKILL_SPEAR = 0x3c,
	AT_SKILL_FIREBURST = 0x3d,
	AT_SKILL_DARKHORSE_ATTACK = 0x3e,
	AT_SKILL_RECALL_PARTY = 0x3f,
	AT_SKILL_ADD_CRITICALDAMAGE = 0x40,
	AT_SKILL_ELECTRICSPARK = 0x41,
	AT_SKILL_LONGSPEAR = 0x42,
	AT_SKILL_RUSH = 0x2c,
	AT_SKILL_JAVALIN = 0x2d,
	AT_SKILL_DEEPIMPACT = 0x2e,
	AT_SKILL_ONE_FLASH = 0x39,
	AT_SKILL_DEATH_CANNON = 0x49,
	AT_SKILL_SPACE_SPLIT = 0x4a,
	AT_SKILL_BRAND_OF_SKILL = 0x4b,
	AT_SKILL_STUN = 0x43,
	AT_SKILL_REMOVAL_STUN = 0x44,
	AT_SKILL_ADD_MANA = 0x45,
	AT_SKILL_INVISIBLE = 0x46,
	AT_SKILL_REMOVAL_INVISIBLE = 0x47,
	AT_SKILL_REMOVAL_MAGIC = 0x48,
	AT_SKILL_FENRIR_ATTACK = 0x4c,
	AT_SKILL_INFINITY_ARROW = 0x4d,
	AT_SKILL_FIRESCREAM = 0x4e,
	AT_SKILL_EXPLOSION = 0x4f,
	AT_SKILL_SUMMON = 0xc8,
	AT_SKILL_IMMUNE_TO_MAGIC = 0xc9,
	AT_SKILL_IMMUNE_TO_HARM = 0xca,
};

enum LOG_COLORS
{
	COLOR_BLACK		            = 1,
	COLOR_RED		            = 2,
	COLOR_GREEN		            = 3,
	COLOR_BLUE		            = 4,
};

enum MAP_INDEX
{
	MAP_INDEX_RORENCIA = 0x0,
	MAP_INDEX_DUNGEON = 0x1,
	MAP_INDEX_DEVIAS = 0x2,
	MAP_INDEX_NORIA = 0x3,
	MAP_INDEX_LOSTTOWER = 0x4,
	MAP_INDEX_RESERVED = 0x5,
	MAP_INDEX_BATTLESOCCER = 0x6,
	MAP_INDEX_ATHLANSE = 0x7,
	MAP_INDEX_TARKAN = 0x8,
	MAP_INDEX_DEVILSQUARE = 0x9,
	MAP_INDEX_ICARUS = 0xa,
	MAP_INDEX_BLOODCASTLE1 = 0xb,
	MAP_INDEX_BLOODCASTLE2 = 0xc,
	MAP_INDEX_BLOODCASTLE3 = 0xd,
	MAP_INDEX_BLOODCASTLE4 = 0xe,
	MAP_INDEX_BLOODCASTLE5 = 0xf,
	MAP_INDEX_BLOODCASTLE6 = 0x10,
	MAP_INDEX_BLOODCASTLE7 = 0x11,
	MAP_INDEX_BLOODCASTLE8 = 0x34,
	MAP_INDEX_CHAOSCASTLE1 = 0x12,
	MAP_INDEX_CHAOSCASTLE2 = 0x13,
	MAP_INDEX_CHAOSCASTLE3 = 0x14,
	MAP_INDEX_CHAOSCASTLE4 = 0x15,
	MAP_INDEX_CHAOSCASTLE5 = 0x16,
	MAP_INDEX_CHAOSCASTLE6 = 0x17,
	MAP_INDEX_CHAOSCASTLE7 = 0x35,
	MAP_INDEX_KALIMA1 = 0x18,
	MAP_INDEX_KALIMA2 = 0x19,
	MAP_INDEX_KALIMA3 = 0x1a,
	MAP_INDEX_KALIMA4 = 0x1b,
	MAP_INDEX_KALIMA5 = 0x1c,
	MAP_INDEX_KALIMA6 = 0x1d,
	MAP_INDEX_CASTLESIEGE = 0x1e,
	MAP_INDEX_CASTLEHUNTZONE = 0x1f,
	MAP_INDEX_DEVILSQUARE2 = 0x20,
	MAP_INDEX_AIDA = 0x21,
	MAP_INDEX_CRYWOLF_FIRSTZONE = 0x22,
	MAP_INDEX_CRYWOLF_SECONDZONE = 0x23,
	MAP_INDEX_KALIMA7 = 0x24,
	MAP_INDEX_GMMAP = 0x28,
	
};