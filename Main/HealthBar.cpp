#include "StdAfx.h"

std::vector<HEALTH_BAR> HealthBar;

void cHealthBar::ClearNewHealthBar()
{
	HealthBar.clear();
}

void cHealthBar::InsertNewHealthBar(short Index, BYTE Rate)
{
	HEALTH_BAR Bar;

	Bar.Index = Index;
	Bar.Rate = Rate;

	HealthBar.push_back(Bar);
}

HEALTH_BAR* cHealthBar::GetNewHealthBar(short Index)
{
	for (std::vector<HEALTH_BAR>::iterator it = HealthBar.begin(); it != HealthBar.end(); ++it)
	{
		if (it->Index == Index)
		{
			return &(*it);
		}
	}

	return NULL;
}

void cHealthBar::DrawHealthBar()
{ 
	((void(*)())0x5EB1D0)();

	int PosX, PosY, Color;
	float LifeBarWidth = 50.0f;
	char LifeDisplay[20];

	VAngle Angle;

	HEALTH_BAR* NewHealthBar;

		for (int i = 0; i < 400; i++)
		{
			DWORD ViewPort = *(DWORD*)(0x07518F94) + (i * 1144);

			if ((*(BYTE*)ViewPort != 0x0) && (*(BYTE*)(ViewPort + 188) == 2))
			{
				NewHealthBar = HPBar.GetNewHealthBar(*(WORD*)(ViewPort + 564));

				if (NewHealthBar == 0)
				{
					continue;
				}

				int LifePercent = NewHealthBar->Rate / 10;

				Angle.X = *(float*)(ViewPort + 16); 
				Angle.Y = *(float*)(ViewPort + 20);
				Angle.Z = *(float*)(ViewPort + 364) + *(float*)(ViewPort + 24) + 100.0f;

				GetPosFromAngle(&Angle, &PosX, &PosY);

				PosX -= (int)floor(LifeBarWidth / (double) 2.0);
				if(pGetCursorWorkSize(PosX,PosY,100,150,1))
				{

					SetBlend(true);

					glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
					DrawBarForm((float)(PosX + 1), (float)(PosY + 1), LifeBarWidth + 3.0f, -7.0f); 

					pDrawTextFix();

					wsprintf(LifeDisplay,"Life: %d0%%", LifePercent);
					glColor3f(1.0f,0.84f,0.0f);   // Gold
					pDrawText(PosX + 27 , PosY - 6, LifeDisplay, 102, 1, 0);

					SetBlend(true);

					glColor4f(0.0f, 0.0f, 0.0f, 0.5f);
					DrawBarForm((float)(PosX + 1), (float)(PosY + 1), LifeBarWidth + 4.0f, 4.0f);

					GLSwitchBlend();

					Color = 2; // - Color == 1 -> Vermelho, Color == 2 -> Colorido.

					if (Color == 1)
					{
						glColor4f(2.0f, 0.0f, 0.0f, 0.6f);
					}
					else if (Color == 2)
					{
						if (NewHealthBar->Rate >= 70 && NewHealthBar->Rate <= 100)
						{
							glColor3f(0.01039216f, 0.939215688f, 0.0);
						}
						else if (NewHealthBar->Rate >= 30 && NewHealthBar->Rate <= 70) 
						{
							glColor3f(0.58039216f, 0.539215688f, 0.0);
						}
						else if (NewHealthBar->Rate <= 30)
						{
							glColor3f(0.98039216f, 0.039215688f, 0.0);
						}
					}

					DrawBarForm((float)(PosX) + 2.5f, (float)(PosY) + 2.5f, (float)((NewHealthBar->Rate * LifeBarWidth) / 100.0f), 3.0f);

					GLSwitch();
				}
			}

			GLSwitch();

			glColor3f(1.0f, 1.0f, 1.0f);
		}
}

cHealthBar HPBar;