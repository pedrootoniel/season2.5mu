#include "stdafx.h"

DWORD pItemType = 0;

float R = 0.0f;
float G = 0.0f;
float B = 0.0f;

int g_iItemCount = 0;

cSmokeEffect::sEffect eColor[256];

cSmokeEffect gSmokeEffect;


cSmokeEffect::cSmokeEffect()
{
	/**/
}

cSmokeEffect::~cSmokeEffect()
{
	/**/
}

INT cSmokeEffect::GetLineId(DWORD ItemType)
{
	for(int i = 0;i < g_iItemCount;i++)
	{
		if(pItemType == ITEM_GET(11,eColor[i].Id)) // Boots type (11)
		{
			return i;
		}
	}

	return -1;
}

__declspec(naked) void SetItemEffect()
{
	_asm
	{
		Mov pItemType, EAX
	}

	if(gSmokeEffect.GetLineId(pItemType) > -1)
	{
		_asm
		{
			MOV ESI, HDK_ITEM_EFFECT_ALLOW
				JMP ESI
		}
	}

	_asm
	{
		MOV ESI, HDK_ITEM_EFFECT_NOT_ALLOW 
			JMP ESI
	}
}

__declspec(naked) void SetColorEffect()
{
	_asm
	{
		Mov pItemType, ECX
	}

	int i;
	i = gSmokeEffect.GetLineId(pItemType);

	for(int i = 0; i < g_iItemCount; i++)
	{
		if(pItemType == ITEM_GET(11,eColor[i].Id))
		{
			R = eColor[i].R;
			G = eColor[i].G;
			B = eColor[i].B;

			_asm
			{
				// R
				MOV ECX,DWORD PTR SS:[EBP+0xC] // struct RGB
				MOV EDX, R
				MOV DWORD PTR DS:[ECX+0x128],EDX // float =D
				// G
				MOV EDX,DWORD PTR SS:[EBP+0xC]  // struct RGB
				MOV EAX, G
				MOV DWORD PTR DS:[EDX+0x12C],EAX // float =D
				// B
				MOV EAX,DWORD PTR SS:[EBP+0xC]  // struct RGB
				MOV ECX, B
				MOV DWORD PTR DS:[EAX+0x130],ECX
				MOV ESI, 0x0052F273
				JMP ESI
			}
		}
	}

	_asm
	{
		MOV ESI, HDK_NEXT_ITEM_COLOR
			JMP ESI
	}
}

#pragma warning(disable: 4996)
void cSmokeEffect::Load()
{
	FILE *File;
	File = fopen(CONFIG_SMOKE_FILE,"r"); // Put at config.h

	if(File != NULL)
	{
		int Flag = 0;
		char zBuffer[1024],C[12] = {0};

		g_iItemCount = 0;

		// Fix for removed items from file
		memset(eColor,-1,sizeof(eColor));

		while(!feof(File))
		{
			fgets(zBuffer,sizeof(zBuffer),File);

			if(IsBadFileLine(zBuffer,Flag))
			{
				continue;
			}

			if(Flag == 0)
			{
				sscanf_s(zBuffer,"%d %f %f %f",&eColor[g_iItemCount].Id,&eColor[g_iItemCount].R,&eColor[g_iItemCount].G,&eColor[g_iItemCount].B);

				g_iItemCount++;
			}
		}

		fclose(File);

		SetNop(HDK_SET_ITEM_EFFECT, 12);
		WriteJmp(HDK_SET_ITEM_EFFECT, (DWORD)&SetItemEffect);

		SetNop(HDK_SET_COLOR_EFFECT, 46);
		WriteJmp(HDK_SET_COLOR_EFFECT, (DWORD)&SetColorEffect);
	}
	else
	{
		MessageBox(NULL,"Unable to open SmokeEffect.txt","Error opening file",MB_OK|MB_ICONERROR);
		ExitProcess(0);
	}
}