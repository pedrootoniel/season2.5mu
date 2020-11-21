#include "stdafx.h"

//----------------------------------------------------------------------------------------//
//definições de ponteiros e etc...
#define ITEMGET(x,y)    ((x)*512 + (y))
#define GS_GOBJPONTEIRO (0x3D995F8)
#define GS_GOBJTAMANHO  (0x197C)
#define MAX_C1LEN       (255)
#define MIN_PLAYERID	(0x9C4)

#define MIN_MONSTERID	(0)
#define MAX_MONSTERID	(5800)
#define OBJECT_MIN 	    0
#define OBJECT_MAX 	    5800
#define OBJECT_BASE   	0x3D995F8
#define OBJECT_SIZE     0x197C

#define GAMESERVER_WIDTH   550
#define GAMESERVER_HEIGHT  700

#define GS_GOBJPOINTER(aIndex)  ((aIndex * GS_GOBJTAMANHO) + GS_GOBJPONTEIRO)
#define OBJECT_POINTER(aIndex)  ((aIndex * OBJECT_SIZE) + OBJECT_BASE)

#define OBJ_EMPTY 	-1
#define OBJ_MONSTER 2
#define	OBJ_USER 	1
#define	OBJ_NPC 	3

#define	igObjTotalUser          *(int*)0x00567C918
#define	gDisconnect             *(int*)0x00567C91C
#define	iServerMaxUser          *(int*)0x00735980
#define	igObjCount				*(int*)0x003D995F0
#define gObjMakePreviewCharSet  ((void(*)(int aIndex))0x00501930)
#define MsgOutput				((void(*)(DWORD aIndex,char *szMsg, ...))	0x0051ABD0)
#define GDGetWarehouseList		((void(*)(int aIndex, char* AccountID))		0x0042A900)


#define CLASS_WIZARD			0x0
#define CLASS_KNIGHT			0x1
#define CLASS_ELF				0x2
#define CLASS_MAGUMSA			0x3
#define CLASS_DARKLORD			0x4


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

//----------------------------------------------------------------------------------------//
//definições
typedef BOOL(*pProtocolCore)(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
typedef void(*pProtocolCoreDS)(BYTE protoNum, unsigned char* aRecv, int aLen);
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
typedef void(*pLogAddFuncColor)(BYTE Color, char* szLog, ...);
typedef int(*pgObjAddMonster)(unsigned char);
typedef void(*pgObjSetMonster)(int, WORD);
typedef void (*pCGDurationMagicRecv) (PBYTE,int);
//----------------------------------------------------------------------------------------//
//definições
extern pCGDurationMagicRecv CGDurationMagicRecv;
extern pgObjSetMonster gObjSetMonster;
extern pgObjAddMonster gObjAddMonster;
extern pLogAddFuncColor LogAddFuncColor;
extern pProtocolCore ProtocolCore;
extern pProtocolCoreDS ProtocolCoreDS;
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

//----------------------------------------------------------------------------------------//
//funcão de hookar
void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset);
void hook_proc(DWORD DToffset, DWORD DTfunc);
void SetByte(DWORD dwOffset,BYTE btValue);
void SetNop(DWORD dwOffset,int Size);
void SetDWord(DWORD dwOffset,DWORD btValue);
void SetJMP(DWORD NewOffset);
//----------------------------------------------------------------------------------------//
//inicializar todos os hooks
void iniciar_hook();
void  PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void  PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size);
void  ChatSendAlliance(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID);
void  ChatSendGuild(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID);
void  ChatSendNormal(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID);
void  ChatSendParty(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID);
void  ChatSendWhisper(LPSTR Mensagem, DWORD PlayerID);
void  MakeBarMsg(DWORD PlayerID,LPCTSTR szText, BYTE RGB1, BYTE RGB2, BYTE RGB3);
void SetCompleteHook(BYTE btHead, DWORD dwOffset, DWORD* dwFunction);
void WriteMemoryInt(DWORD Offset, DWORD bValue, DWORD bValueMax, DWORD OffsetLen);
void HookFunc(DWORD offset, DWORD funcao);
DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue);
DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd);
DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize);
void GCFireworkSend(int aIndex,int X,int Y,int Amount);
int MosterAdd(int MobID, int MapID, int CoordX, int CoordY);
void CheckPet(LPOBJ lpObj);