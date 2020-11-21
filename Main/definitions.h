#include "stdafx.h"


typedef void (__cdecl *pSendChatText) (const char * szSender, const char * szText, BYTE Color);
extern pSendChatText MU_SendChatText;

#define MAXITEM 512
#define ITEMGET(x,y)    ( (x) * MAXITEM + (y) )
#define ITEM_GET(x, y)  ( x   * MAXITEM +  y) + 0x246

#define MAX_ITEM_SECTION 15
#define MAX_ITEM_TYPE 512
#define MAX_ITEM (MAX_ITEM_SECTION*MAX_ITEM_TYPE)

#define ITEM_ATTRIBUTE_ADDR 0x246
#define GET_ITEM(x,y) (((x)*MAX_ITEM_TYPE)+(y))
#define GET_ITEM_MODEL(x,y) ((((x)*MAX_ITEM_TYPE)+(y))+ITEM_ATTRIBUTE_ADDR)


#define Offset_CreateFontA1 0x006BCD36
#define Offset_CreateFontA2 0x004D58CC
#define Offset_CreateFontA3	0x004D590C
#define Offset_CreateFontA4 0x004D594E
#define Offset_CreateFontA5 0x004D59A8

#define HDK_SET_ITEM_EFFECT			0x0052F106
#define HDK_SET_COLOR_EFFECT		0x0052F162
#define HDK_ITEM_EFFECT_ALLOW		0x0052F127
#define HDK_ITEM_EFFECT_NOT_ALLOW	0x0052F76D
#define HDK_NEXT_ITEM_COLOR			0x0052F191

#define MainSpeedFrame1				(float*)(0x783A44)
#define MainSpeedFrame2				(float*)(0x783A18)

#define GetViewPortId				((int(__cdecl*)(int aIndex)) 0x530A4D)
#define CursorX						*(int*)0x7E80704
#define CursorY						*(int*)0x7E80700

#define GetPosFromAngle				((void(__cdecl*)(VAngle * Angle, int * PosX, int * PosY)) 0x69A454)

#define SetBlend					((void(__cdecl*)(BYTE Mode)) 0x69A8A9)
#define GLSwitchBlend				((void(__cdecl*)()) 0x69A944)
#define GLSwitch					((void(__cdecl*)()) 0x69A82A)
#define DrawBarForm					((void(__cdecl*)(float PosX, float PosY, float Width, float Height)) 0x69BD34)

#define iItemShineEffect			0x00679A24
#define iItemShineEffect_Next		0x00679BBE
#define iItemShineEffect_Stack		0x00679E86

typedef void(*pProtocolCore)(DWORD protoNum,LPBYTE lpRecv,int aLen,int aIndex);
extern pProtocolCore ProtocoloCore;

typedef void(*pTextureLoad)(int,char*,char*,int);
extern pTextureLoad TextureLoad;

typedef void(*pTextureCall)(int,char*,int,int,int);
extern pTextureCall TextureCall;

void datasend(LPBYTE buf, int len);

#define CONFIG_MAIN_FILE	".\\Data\\_CustomMain_\\Main.ini"
#define CONFIG_GLOW_FILE	".\\Data\\_CustomMain_\\GlowEffect.txt"
#define CONFIG_SMOKE_FILE	".\\Data\\_CustomMain_\\SmokeEffect.txt"
#define CONFIG_EFFECT_FILE	".\\Data\\_CustomMain_\\ItemEffect.txt"

#define ErrorDir			"Data/_CustomMain_/Log"
#define DumpLog				"Data/_CustomMain_/Log/Error.dmp"
#define ErrorLog			"Data/_CustomMain_/Log/Error.log"



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
