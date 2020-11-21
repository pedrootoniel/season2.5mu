#include "stdafx.h"

void ProtocolCore(DWORD protoNum, LPBYTE lpRecv, int Len, int aIndex)
{
	BYTE Head    = lpRecv[(lpRecv[0] == 0xC2 || lpRecv[0] == 0xC4) ? 3 : 2];
	BYTE SubCode = lpRecv[(lpRecv[0] == 0xC2 || lpRecv[0] == 0xC4) ? 4 : 3];

	switch (Head)
	{
		case 0xF3:
	    {
			switch (SubCode)
			{
				case 0xE2:
				{
					HPBar.ClearNewHealthBar();

					PMSG_HEALTHBAR* lpMsg = (PMSG_HEALTHBAR*)(lpRecv);

					for (int i = 0; i < lpMsg->Count; i++)
					{
						PMSG_HEALTHBAR_INFO* Info = (PMSG_HEALTHBAR_INFO*)(&lpRecv[sizeof(PMSG_HEALTHBAR) + (sizeof(PMSG_HEALTHBAR_INFO) * i)]);
						HPBar.InsertNewHealthBar(Info->Index, Info->Rate);
					}
				}
				break;
			}
		}
		break;

	case 0xFE:
		{
			switch (SubCode)
			{
			case 0x07:
				{ 
					PMSG_CHARINFOMAIN* Info = (PMSG_CHARINFOMAIN*)(lpRecv);

					Player.Class			= Info->Class;
					Player.Dexterity		= Info->Dexterity;
					Player.AttackSpeed		= Info->AttackSpeed;
					Player.MagicSpeed		= Info->MagicSpeed;

					ApplyDexterityFix();
				}
				break;
			}
		}
		break;
	case 0xFF:
		{
			switch (SubCode)
			{
			case 0: // receber os pontos do GS
				gObjPoints((PLAYER_POINTS*)lpRecv);
				break;
			case 3: // receber as % do mix
				gObjMix((GLOBIN_MIX*)lpRecv);
				break;
			case 4: // receber os valores do speed
				gObjCalCharacter((CALCHARACTER*)lpRecv);
				break;
			case 0x08: // [#] - correção do travamento do reset
				*(BYTE*) (0x004E9E0B)    = 0x2B;
				*(BYTE*) (0x004E9E0B+1)  = 0xF6;
				break;
			} 
		}
		break;
	}

   ProtocoloCore(protoNum, lpRecv,Len,aIndex);
}

void ProtocolLoad()
{
	SetOp((LPVOID)0x004FF68D,(LPVOID)ProtocolCore,ASM::CALL);	
	//1.02.44 004FFD5D


}

void gObjPoints(PLAYER_POINTS * p)
{
	points = p->points;
	OBJECTSTRUCT  * lpMainObj = &*(OBJECTSTRUCT*)*(DWORD*)0x7772AB8;

	DWORD object          = (DWORD)lpMainObj;
	*(WORD*)(object+0x70)  = (WORD)p->points;
}

void gObjMix(GLOBIN_MIX * p)
{
	*(BYTE*) (0x00664987+2)    = (BYTE)p->mix10luck;//00663BA7  |. 83E2 19        AND EDX,19
	*(BYTE*) (0x0066498A+2)    = (BYTE)p->mix10;//00663BAA  |. 83C2 32        ADD EDX,32
	*(BYTE*) (0x006649C4+2)    = (BYTE)p->mix11luck;//00663BE4  |. 83E2 19        AND EDX,19
	*(BYTE*) (0x006649C7+2)    = (BYTE)p->mix11;//00663BE7  |. 83C2 2D        ADD EDX,2D
	*(BYTE*) (0x00664A01+2)    = (BYTE)p->mix12luck;//00663C21  |. 83E2 19        AND EDX,19
	*(BYTE*) (0x00664A04+2)    = (BYTE)p->mix12;//00663C24  |. 83C2 2D        ADD EDX,2D
	*(BYTE*) (0x00664A3E+2)    = (BYTE)p->mix13luck;//00663C5E  |. 83E2 19        AND EDX,19
	*(BYTE*) (0x00664A41+2)    = (BYTE)p->mix13;//00664A41  |. 83C2 2D        ADD EDX,2D
	*(BYTE*) (0x00664A9D+6)    = (BYTE)p->fenrir1;//00663CBD  |> C785 7CFFFFFF >MOV DWORD PTR SS:[EBP-84],46
	*(BYTE*) (0x00664ACC+6)    = (BYTE)p->fenrir2;//00663CEC  |> C785 7CFFFFFF >MOV DWORD PTR SS:[EBP-84],32
	*(BYTE*) (0x00664AFB+6)    = (BYTE)p->fenrir3;//00663D1B  |> C785 7CFFFFFF >MOV DWORD PTR SS:[EBP-84],1E
}

void gObjCalCharacter(CALCHARACTER * p)
{
	*(BYTE*)(0x00589F4B+1) = p->elf1;//0058A03F  |. B9 32000000    MOV ECX,32
	*(BYTE*)(0x00589F62+1) = p->elf2;//0058A056  |. B9 32000000    MOV ECX,32
	*(BYTE*)(0x00589F8A+1) = p->bkmg1;//0058A07E  |. B9 0F000000    MOV ECX,0F
	*(BYTE*)(0x00589FA1+1) = p->bkmg2;//0058A095  |. B9 14000000    MOV ECX,14
	*(BYTE*)(0x00589FC0+1) = p->dl1;//0058A0B4  |. B9 0A000000    MOV ECX,0A
	*(BYTE*)(0x00589FD7+1) = p->dl2;//0058A0CB  |. B9 0A000000    MOV ECX,0A
	*(BYTE*)(0x00589FF0+1) = p->sm1;//0058A0E4  |. B9 14000000    MOV ECX,14
	*(BYTE*)(0x0058A007+1) = p->sm2;//0058A0FB  |. B9 0A000000    MOV ECX,0A
}

void ApplyDexterityFix()
{
	switch (Player.Class)
	{
	case 0:
		{
			if (Player.MagicSpeed >= 455 && Player.MagicSpeed <= 479)
			{
				*MainSpeedFrame2 = 0.0024700f;
			}
			else if (Player.MagicSpeed >= 605 && Player.MagicSpeed <= 636)
			{
				*MainSpeedFrame2 = 0.0019000f;
			}
			else if (Player.MagicSpeed >= 637 && Player.MagicSpeed <= 668)
			{
				*MainSpeedFrame2 = 0.0018000f;
			}
			else if (Player.MagicSpeed >= 669 && Player.MagicSpeed <= 688)
			{
				*MainSpeedFrame2 = 0.0017000f;
			}
			else if (Player.MagicSpeed >= 855 && Player.MagicSpeed <= 1040)
			{
				*MainSpeedFrame2 = 0.0016300f;
			}
			else if (Player.MagicSpeed >= 1041 && Player.MagicSpeed <= 1104)
			{
				*MainSpeedFrame2 = 0.0015500f;
			}
			else if (Player.MagicSpeed >= 1301 && Player.MagicSpeed <= 1500)
			{
				*MainSpeedFrame2 = 0.0017500f;
			}
			else if (Player.MagicSpeed >= 1501 && Player.MagicSpeed <= 1524)
			{
				*MainSpeedFrame2 = 0.0015000f;
			}
			else if (Player.MagicSpeed >= 1525 && Player.MagicSpeed <= 1800)
			{
				*MainSpeedFrame2 = 0.0014500f;
			}
			else if (Player.MagicSpeed >= 1801 && Player.MagicSpeed <= 1999)
			{
				*MainSpeedFrame2 = 0.0013000f;
			}
			else if (Player.MagicSpeed >= 2000 && Player.MagicSpeed <= 2167)
			{
				*MainSpeedFrame2 = 0.0012500f;
			}
			else if (Player.MagicSpeed >= 2168 && Player.MagicSpeed <= 2354)
			{
				*MainSpeedFrame2 = 0.0011500f;
			}
			else if (Player.MagicSpeed >= 2855 && Player.MagicSpeed <= 3011)
			{
				*MainSpeedFrame2 = 0.0009000f;
			}
			else if (Player.MagicSpeed >= 3011)
			{
				*MainSpeedFrame2 = 0.0008100f;
			}
			else
			{
				*MainSpeedFrame2 = 0.0020000f;
			}
		}
		break;
	case 1:
		{
			*MainSpeedFrame1 = 0.0040000f;
			*MainSpeedFrame2 = 0.0020000f;
		}
		break;
	case 2:
		{
			if (Player.AttackSpeed >= 509 && Player.AttackSpeed <= 549)
			{
				*MainSpeedFrame1 = 0.0026000f;
			} 
			else if (Player.AttackSpeed >= 550 && Player.AttackSpeed <= 750) 
			{
				*MainSpeedFrame1 = 0.0017000f;
			} 
			else 
			{
				*MainSpeedFrame1 = 0.0040000f;
			}
		}
		break;
	case 3:
		{
			if (Player.Dexterity >= 11001 && Player.Dexterity <= 12000)
			{
				*MainSpeedFrame1 = 0.001800000f;
			}
			else if (Player.Dexterity >= 16000 && Player.Dexterity <= 17000)
			{
				*MainSpeedFrame1 = 0.001800000f;
			}
			else if (Player.Dexterity >= 17001 && Player.Dexterity <= 19000)
			{
				*MainSpeedFrame1 = 0.001700000f;
			}
			else if (Player.Dexterity >= 19001 && Player.Dexterity <= 20000)
			{
				*MainSpeedFrame1 = 0.001600000f;
			}
			else if (Player.Dexterity >= 20001 && Player.Dexterity <= 21000)
			{
				*MainSpeedFrame1 = 0.001500000f;
			}
			else if (Player.Dexterity >= 21001 && Player.Dexterity <= 23000)
			{
				*MainSpeedFrame1 = 0.001400000f;
			}
			else if (Player.Dexterity >= 26000 && Player.Dexterity <= 27000)
			{
				*MainSpeedFrame1 = 0.001900000f;
			}
			else if (Player.Dexterity >= 27001 && Player.Dexterity <= 29000)
			{
				*MainSpeedFrame1 = 0.001900000f;
			}
			else if (Player.Dexterity >= 29001 && Player.Dexterity <= 30000)
			{
				*MainSpeedFrame1 = 0.001900000f;
			}
			else if (Player.Dexterity >= 30001 && Player.Dexterity <= 32767)
			{
				*MainSpeedFrame1 = 0.001600000f;
			}
			else
			{
				*MainSpeedFrame1 = 0.002000000f;
			}

			if (Player.MagicSpeed >= 455 && Player.MagicSpeed <= 479)
			{
				*MainSpeedFrame2 = 0.0024700f;
			}
			else if (Player.MagicSpeed >= 605 && Player.MagicSpeed <= 636)
			{
				*MainSpeedFrame2 = 0.0019000f;
			}
			else if (Player.MagicSpeed >= 637 && Player.MagicSpeed <= 668)
			{
				*MainSpeedFrame2 = 0.0018000f;
			}
			else if (Player.MagicSpeed >= 669 && Player.MagicSpeed <= 688)
			{
				*MainSpeedFrame2 = 0.0017000f;
			}
			else if (Player.MagicSpeed >= 855 && Player.MagicSpeed <= 1040)
			{
				*MainSpeedFrame2 = 0.0016300f;
			}
			else if (Player.MagicSpeed >= 1041 && Player.MagicSpeed <= 1104)
			{
				*MainSpeedFrame2 = 0.0015500f;
			}
			else if (Player.MagicSpeed >= 1301 && Player.MagicSpeed <= 1500)
			{
				*MainSpeedFrame2 = 0.0017500f;
			}
			else if (Player.MagicSpeed >= 1501 && Player.MagicSpeed <= 1524)
			{
				*MainSpeedFrame2 = 0.0015000f;
			}
			else if (Player.MagicSpeed >= 1525 && Player.MagicSpeed <= 1800)
			{
				*MainSpeedFrame2 = 0.0014500f;
			}
			else if (Player.MagicSpeed >= 1801 && Player.MagicSpeed <= 1999)
			{
				*MainSpeedFrame2 = 0.0013000f;
			}
			else if (Player.MagicSpeed >= 2000 && Player.MagicSpeed <= 2167)
			{
				*MainSpeedFrame2 = 0.0012500f;
			}
			else if (Player.MagicSpeed >= 2168 && Player.MagicSpeed <= 2354)
			{
				*MainSpeedFrame2 = 0.0011500f;
			}
			else if (Player.MagicSpeed >= 2855 && Player.MagicSpeed <= 3011)
			{
				*MainSpeedFrame2 = 0.0009000f;
			}
			else if (Player.MagicSpeed >= 3011)
			{
				*MainSpeedFrame2 = 0.0008100f;
			}
			else
			{
				*MainSpeedFrame2 = 0.0020000f;
			}
		}
		break;
	case 4:
		{
			if (Player.Dexterity >= 2000 && Player.Dexterity < 4900)
			{
				*MainSpeedFrame1 = 0.0038000f;
			}
			else if (Player.Dexterity >= 4900 && Player.Dexterity < 5050)
			{
				*MainSpeedFrame1 = 0.0037000f;
			}
			else if (Player.Dexterity >= 5050 && Player.Dexterity < 5200)
			{
				*MainSpeedFrame1 = 0.0036000f;
			}
			else if (Player.Dexterity >= 5200 && Player.Dexterity < 5350)
			{
				*MainSpeedFrame1 = 0.0035000f;
			}
			else if (Player.Dexterity >= 5350 && Player.Dexterity < 5550)
			{
				*MainSpeedFrame1 = 0.0034000f;
			}
			else if (Player.Dexterity >= 5550 && Player.Dexterity < 5700)
			{
				*MainSpeedFrame1 = 0.0033000f;
			}
			else if (Player.Dexterity >= 5700 && Player.Dexterity < 5900)
			{
				*MainSpeedFrame1 = 0.0032000f;
			}
			else if (Player.Dexterity >= 5900 && Player.Dexterity < 6100)
			{
				*MainSpeedFrame1 = 0.0031000f;
			}
			else if (Player.Dexterity >= 6100 && Player.Dexterity < 6300)
			{
				*MainSpeedFrame1 = 0.0030000f;
			}
			else if (Player.Dexterity >= 6300 && Player.Dexterity < 6500)
			{
				*MainSpeedFrame1 = 0.0029000f;
			}
			else if (Player.Dexterity >= 6500 && Player.Dexterity < 6750)
			{
				*MainSpeedFrame1 = 0.0028000f;
			}
			else if (Player.Dexterity >= 6750 && Player.Dexterity < 7000)
			{
				*MainSpeedFrame1 = 0.0027000f;
			}
			else if (Player.Dexterity >= 7000 && Player.Dexterity < 7300)
			{
				*MainSpeedFrame1 = 0.0026000f;
			}
			else if (Player.Dexterity >= 7300 && Player.Dexterity < 7600)
			{
				*MainSpeedFrame1 = 0.0025000f;
			}
			else if (Player.Dexterity >= 7600 && Player.Dexterity < 7900)
			{
				*MainSpeedFrame1 = 0.0024000f;
			}
			else if (Player.Dexterity >= 7900 && Player.Dexterity < 8250)
			{
				*MainSpeedFrame1 = 0.0023000f;
			}
			else if (Player.Dexterity >= 8250 && Player.Dexterity < 8650)
			{
				*MainSpeedFrame1 = 0.0022000f;
			}
			else if (Player.Dexterity >= 8650 && Player.Dexterity < 9050)
			{
				*MainSpeedFrame1 = 0.0021000f;
			}
			else if (Player.Dexterity >= 9050 && Player.Dexterity < 9500)
			{
				*MainSpeedFrame1 = 0.0020000f;
			}
			else if (Player.Dexterity >= 9500 && Player.Dexterity < 10000)
			{
				*MainSpeedFrame1 = 0.0019000f;
			}
			else if (Player.Dexterity >= 10000 && Player.Dexterity < 10550)
			{
				*MainSpeedFrame1 = 0.0018000f;
			}
			else if (Player.Dexterity >= 10550 && Player.Dexterity < 11150)
			{
				*MainSpeedFrame1 = 0.0017000f;
			}
			else if (Player.Dexterity >= 11150 && Player.Dexterity < 11850)
			{
				*MainSpeedFrame1 = 0.0016000f;
			}
			else if (Player.Dexterity >= 11850 && Player.Dexterity < 12600)
			{
				*MainSpeedFrame1 = 0.0015000f;
			}
			else if (Player.Dexterity >= 12600 && Player.Dexterity < 13450)
			{
				*MainSpeedFrame1 = 0.0014000f;
			}
			else if (Player.Dexterity >= 13450 && Player.Dexterity < 16600)
			{
				*MainSpeedFrame1 = 0.0010000f;
			}
			else if (Player.Dexterity >= 16600)
			{
				*MainSpeedFrame1 = 0.0008000f;
			}
			else
			{
				*MainSpeedFrame1 = 0.0040000f;
			}
		}
		break;
	}
}

ObjPlayer Player;