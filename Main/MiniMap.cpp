#include "StdAfx.h"

char CurrentDir1[_MAX_PATH];
char configname[_MAX_PATH];
int  LastMap;
bool IsMiniMap;
bool ShowMiniMap;

typedef int(*TLoadImage)(char[64], int, int, int, int, int);
typedef int(*TUnBlend2) ();

BYTE *Main_MiniMapShow	= (BYTE*)0x00412DDD;
int *Map				= (int*)0x7A4DC0;
TUnBlend2 UnBlend2		= (TUnBlend2)0x0069A944;
TLoadImage LoadImg		= (TLoadImage)0x006B801B;


void MiniMap()
{
	char path[64];
	char mypath[MAX_PATH];
	LastMap = 100;
	if (LastMap != *Map)
	{
		sprintf_s(path, "Maps\\MiniMap%d.jpg", *Map + 1);
		sprintf_s(mypath, "%sData\\Maps\\MiniMap%d.OZJ", CurrentDir1, *Map + 1);

		if (FileExists(mypath))
		{
			LoadImg(path, 0x703, 0x2601, 0x2900, 0, 1);
			IsMiniMap = true;
		}
		else
		IsMiniMap = false;
		LastMap = *Map;
	}

	if (IsMiniMap == true)
		*Main_MiniMapShow = 0xEB;
	else
		*Main_MiniMapShow = 0x74;
	UnBlend2();
}

void HookMiniMap()
{
	HookOffset((DWORD)&MiniMap, 0x005EC1F1, 0xE8);
}



