#pragma once

struct VAngle
{
	float X;
	float Y;
	float Z;
};

struct HEALTH_BAR
{
	short Index;
	BYTE Rate;
};

class cHealthBar
{
public:
	void ClearNewHealthBar();
	void InsertNewHealthBar(short Index, BYTE Rate);
	HEALTH_BAR* GetNewHealthBar(short Index);
	static void DrawHealthBar();
};

extern cHealthBar HPBar;

#define pDrawText				((int(*)(int x, int y, LPCSTR Text, int BackgroundWidth, int AlignCenter, int a6))  0x69E4F0)
#define pDrawTextFix            ((bool(__cdecl*)()) 0x69A8A9)
#define pGetCursorWorkSize      ((int(__cdecl*)(int PosX,int PosY,int Width,int Height,int Mode)) 0x475224)