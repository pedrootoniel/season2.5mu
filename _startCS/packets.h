#pragma once

#define SET_NUMBERH(x)  ( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x)  ( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x) ( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x) ( (WORD)((DWORD)(x) & 0xFFFF) )

#include "stdafx.h"

struct PWMSG_HEAD	// Packet - Word Type
{
public:

	void set( LPBYTE lpBuf, BYTE head, int size)
	{
		lpBuf[0] = 0xC2;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	void setE( LPBYTE lpBuf, BYTE head, int size)	// line : 49
	{
		lpBuf[0] = 0xC4;
		lpBuf[1] = SET_NUMBERH(size);
		lpBuf[2] = SET_NUMBERL(size);
		lpBuf[3] = head;
	};

	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};


struct PBMSG_HEAD	// Packet - Byte Type
{
public:
	void set ( LPBYTE lpBuf, BYTE head, BYTE size)	// line : 18
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	// line : 22

	void setE ( LPBYTE lpBuf, BYTE head, BYTE size)	// line : 25
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	// line : 29

	BYTE c;
	BYTE size;
	BYTE headcode;
};

struct PMSG_USE_STAT_FRUIT {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char result;
  /*<thisrel this+0x4>*/ /*|0x1|*/ WORD btStatValue;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char btFruitType;

  // base classes -----------------------------------

  // friends ----------------------------------------

  // static functions -------------------------------

  // non-virtual functions --------------------------

  // virtual functions ------------------------------
};

struct PMSG_RESULT
{
	PBMSG_HEAD h;
	unsigned char result;
};

struct SDHP_DBCHAR_INFORESULT
{
	PWMSG_HEAD h;
	unsigned char result;	
	short Number;	
	char AccountID[10];	
	char Name[11];	
	BYTE Class;	
	short Level;	
	int LevelUpPoint;	
	int Exp;	
	int NextExp;	
	int Money;	
	short Str;	
	short Dex;	
	short Vit;	
	short Energy;	
	WORD Life;	
	WORD MaxLife;	
	WORD Mana;	
	WORD MaxMana;	
	BYTE dbInventory[1728];	
	BYTE dbMagicList[180];	
	BYTE MapNumber;	
	BYTE MapX;	
	BYTE MapY;	
	BYTE Dir;	
	int PkCount;	
	int PkLevel;	
	int PkTime;	
	BYTE CtlCode;	
	BYTE DbVersion;	
	BYTE AccountCtlCode;
	BYTE dbQuest[50];	
	WORD Leadership;	
	WORD ChatLitmitTime;	
	int iFruitPoint;
};

struct PMSG_USEITEM
{
	PBMSG_HEAD h;
	BYTE inventoryPos;
	BYTE invenrotyTarget;
	BYTE btItemUseType;
};

struct PMSG_CHARINFOMAIN	// Custom 
{
	PBMSG_HEAD h;
	BYTE Code;
	BYTE Class;
	WORD Dexterity;
	WORD AttackSpeed;
	WORD MagicSpeed;
}; 

struct PLAYER_POINTS
{
	PBMSG_HEAD h;
	int points;
};

struct PLAYER_STATUS
{
	PBMSG_HEAD h;
	WORD  forca;
	WORD  agilidade;
	WORD  vitalidade;
	WORD  energia;
	WORD  comando;
	WORD  manamax;
};

struct PLAYER_RESET
{
	PBMSG_HEAD h;
	WORD  forca;
	WORD  agilidade;
	WORD  vitalidade;
	WORD  energia;
	WORD  comando;
	int   points;
	DWORD exp;
	DWORD nextexp;
	short level;
};

struct GLOBIN_MIX
{
	PBMSG_HEAD h;
	int mix10;
	int mix11;
	int mix12;
	int mix13;
	int mix10luck;
	int mix11luck;
	int mix12luck;
	int mix13luck;
	int fenrir1;
	int fenrir2;
	int fenrir3;
};

struct CALCHARACTER
{
	PBMSG_HEAD h;
	int elf1;
	int elf2;
	int bkmg1;
	int bkmg2;
	int dl1;
	int dl2;
	int sm1;
	int sm2;
};

struct MAIN
{
	PBMSG_HEAD h;
	int skillsiege;
	int reflete;
};

struct PMSG_NAME
{
	PBMSG_HEAD h;
	char name[11];
};

struct ACCOUNT_WARE
{
	PBMSG_HEAD h;
	char account[11];
	int  ware;
};

struct PMSG_CHARMAPJOIN
{
	PBMSG_HEAD h;
	BYTE subcode;
	char name[10];	
};

struct PLAYER_INFOR
{
	PBMSG_HEAD h;
	char account[11];
	char name[11];
	int  index;
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};


struct PLAYER_OBJECT
{
	PBMSG_HEAD h;
	int  index;
	int  vip;
	int  resets;
	char account[11];
	char name[11];
};

class CPacket
{
public:

	CPacket();
	virtual ~CPacket();
	CPacket(BYTE header,BYTE head);
	CPacket(BYTE header,BYTE head,BYTE subhead);

	LPBYTE buff();
	DWORD size();

	void AddByte(BYTE Value);
	void AddWord(WORD Value,int dir);

private:

    DWORD m_size;
	BYTE m_Packet[4096];
};

struct PBMSG_HEAD_
{
	unsigned char c;
	unsigned char size;
	unsigned char headcode;
};

struct PMSG_ITEMTHROW
{
	PBMSG_HEAD_ h;
	unsigned char px;
	unsigned char py;
	unsigned char Ipos;
};

struct SDHP_CREATECHARRESULT
{
	PBMSG_HEAD h;
	unsigned char Result;	// 3
	short Number;	// 4
	char AccountId[10];	// 6
	char Name[10];	// 10
	BYTE Pos;	// 1A
	BYTE ClassSkin;	// 1B
	BYTE Equipment[24];	// 1C
	WORD Level;	// 34
};

struct SDHP_CHARLISTCOUNT
{
	PWMSG_HEAD h;
	short Number;	// 4
	BYTE Count;	// 6
	int DbNumber;	// 8
	BYTE Magumsa;	// C
	char AccountId[11];	// D
	BYTE MoveCnt;	// 18
};

struct SDHP_CHARLIST
{
	BYTE Index;	// 0
	char Name[10];	// 1
	WORD Level;	// C
	BYTE Class;	// E
	BYTE CtlCode;	// F
	BYTE dbInventory[48];	// 10
	BYTE DbVersion;	// 40
	BYTE btGuildStatus;	// 41
};

struct PMSG_CHARLISTCOUNT
{
	PBMSG_HEAD h;	// C1:F3:00
	BYTE subcode;	// 3
	BYTE MaxClass;	// 4
	BYTE MoveCnt;	// 5
	BYTE Count;	// 6
};

struct PMSG_CHARLIST
{
	BYTE Index;	// 0
	char Name[10];	// 1
	WORD Level;	// C
	BYTE CtlCode;	// E
	BYTE CharSet[18];	// F
	BYTE btGuildStatus;	// 21
};

struct PMSG_CHARCREATERESULT
{
	PBMSG_HEAD h;	// C1:F3:01
	BYTE subcode;	// 3
	unsigned char Result;	// 4
	unsigned char Name[10];	// 5
	BYTE pos;	// F
	WORD Level;	// 10
	BYTE Class;	// 12
	BYTE Equipment[24];	// 13
};