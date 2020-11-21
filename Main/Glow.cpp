#include "StdAfx.h"

#include <gl\gl.h>
#include <gl\glu.h>

cGlowEffect gGlow;

typedef int(*ToriginalGlow)(DWORD,DWORD,DWORD,cGlowEffect::sFRGB&,BYTE);
ToriginalGlow originalGlow = (ToriginalGlow)0x0067494C;

cGlowEffect::cGlowEffect()
{
	/**/
}

cGlowEffect::~cGlowEffect()
{
	/**/
}

void cGlowEffect::GlowEffect(DWORD dwItemId,DWORD uk1,DWORD uk2,sFRGB& Color,BYTE bUkn)
{
	for(int i = 0;i <= gGlow.g_iItemCount;i++)
	{
		if(dwItemId == ITEM_GET(gGlow.eItem[i].Type,gGlow.eItem[i].Item))
		{
			Color.R = gGlow.eColor[i].R;
			Color.G = gGlow.eColor[i].G;
			Color.B = gGlow.eColor[i].B;

			break; // 100%
		}
		else
		{
			originalGlow(dwItemId,uk1,uk2,Color,bUkn);
		}
	}
}

#pragma warning(disable: 4996)
void cGlowEffect::Load()
{
	FILE *File;
	File = fopen(CONFIG_GLOW_FILE,"r"); // Put at config.h

	if(File != NULL)
	{
		int Flag = 0;
		char zBuffer[1024];

		g_iItemCount = 0;

		// Fix for removed items from file
		memset(eItem,-1,sizeof(eItem));

		while(!feof(File))
		{
			fgets(zBuffer,sizeof(zBuffer),File);

			if(IsBadFileLine(zBuffer,Flag))
			{
				continue;
			}

			if(Flag == 0)
			{
				sscanf_s
				(
					zBuffer,
					"%d %d %f %f %f",
					&eItem[g_iItemCount].Type,
					&eItem[g_iItemCount].Item,
					&eColor[g_iItemCount].R,
					&eColor[g_iItemCount].G,
					&eColor[g_iItemCount].B
				);

				g_iItemCount++;
			}
		}

		fclose(File);

		HookOffset((DWORD)&gGlow.GlowEffect,0x0052EFB5,ASM::CALL);
		HookOffset((DWORD)&gGlow.GlowEffect,0x00679486,ASM::CALL);
	}
	else
	{
		MessageBox(NULL,"Unable to open GlowEffect.txt","Error opening file",MB_OK|MB_ICONERROR);
		ExitProcess(0);
	}
}