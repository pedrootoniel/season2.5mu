#include "stdafx.h"

#define CS_SET_WING1(x)  ( ((x) & 0x03 ) << 2 )

void gObjMakePreviewCharSet_(int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	gObjMakePreviewCharSet(aIndex);

	if( (lpObj->pInventory[7].m_Type >= ITEMGET(12, 36) && lpObj->pInventory[7].m_Type <= ITEMGET(12, 66)))
	{
		lpObj->CharSet[5]	|= CS_SET_WING1(3);
		lpObj->CharSet[17]	|= (lpObj->pInventory[7].m_Type - ITEMGET(12, 36) + 1) << 2;
	}
}
__declspec(naked) void ThirdWingsEnableBless()
{
	__asm
	{
		CMP ECX,0x1A1E;
		JE Allow;

		CMP ECX,ITEMGET(12,36);
		JE Allow;
		CMP ECX,ITEMGET(12,37);
		JE Allow;
		CMP ECX,ITEMGET(12,38);
		JE Allow;
		CMP ECX,ITEMGET(12,39);
		JE Allow;
		CMP ECX,ITEMGET(12,40);
		JE Allow;
		CMP ECX,ITEMGET(12,41);
		JE Allow;
		CMP ECX,ITEMGET(12,42);
		JE Allow;
		CMP ECX,ITEMGET(12,43);
		JE Allow;
		CMP ECX,ITEMGET(12,44);
		JE Allow;
		CMP ECX,ITEMGET(12,45);
		JE Allow;
		CMP ECX,ITEMGET(12,46);
		JE Allow;
		CMP ECX,ITEMGET(12,47);
		JE Allow;
		CMP ECX,ITEMGET(12,48);
		JE Allow;
		CMP ECX,ITEMGET(12,49);
		JE Allow;
		CMP ECX,ITEMGET(12,50);
		JE Allow;
		CMP ECX,ITEMGET(12,51);
		JE Allow;
		CMP ECX,ITEMGET(12,52);
		JE Allow;
		CMP ECX,ITEMGET(12,53);
		JE Allow;
		CMP ECX,ITEMGET(12,54);
		JNZ End

		Allow:
		MOV EDI,0x004FE32F//004E75CF  |> 8B55 10        MOV EDX,DWORD PTR SS:[EBP+10]
		JMP EDI

		End:
		MOV EDI,0x004FE36C//004E760C  |> 33C0           XOR EAX,EAX
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsEnableSoul()
{
	__asm
	{
		CMP EDX,0x1A1E;
		JE Allow;
	
		CMP EDX,ITEMGET(12,36);
		JE Allow;
		CMP ECX,ITEMGET(12,37);
		JE Allow;
		CMP ECX,ITEMGET(12,38);
		JE Allow;
		CMP ECX,ITEMGET(12,39);
		JE Allow;
		CMP ECX,ITEMGET(12,40);
		JE Allow;
		CMP ECX,ITEMGET(12,41);
		JE Allow;
		CMP ECX,ITEMGET(12,42);
		JE Allow;
		CMP ECX,ITEMGET(12,43);
		JE Allow;
		CMP ECX,ITEMGET(12,44);
		JE Allow;
		CMP ECX,ITEMGET(12,45);
		JE Allow;
		CMP ECX,ITEMGET(12,46);
		JE Allow;
		CMP ECX,ITEMGET(12,47);
		JE Allow;
		CMP ECX,ITEMGET(12,48);
		JE Allow;
		CMP ECX,ITEMGET(12,49);
		JE Allow;
		CMP ECX,ITEMGET(12,50);
		JE Allow;
		CMP ECX,ITEMGET(12,51);
		JE Allow;
		CMP ECX,ITEMGET(12,52);
		JE Allow;
		CMP ECX,ITEMGET(12,53);
		JE Allow;
		CMP EDX,ITEMGET(12,54);
		JNZ End

		Allow:
		MOV EDI,0x004FE875//004E7AF5  |> 8B45 10        MOV EAX,DWORD PTR SS:[EBP+10]
		JMP EDI

		End:
		MOV EDI,0x004FE8B2//004E7B32  |> 33C0           XOR EAX,EAX
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsEnableLife()
{
	__asm
	{
		CMP EDX,0x1A1E;
		JE Allow;

		CMP EDX,ITEMGET(12,36);
		JE Allow;		
		CMP ECX,ITEMGET(12,37);
		JE Allow;
		CMP ECX,ITEMGET(12,38);
		JE Allow;
		CMP ECX,ITEMGET(12,39);
		JE Allow;
		CMP ECX,ITEMGET(12,40);
		JE Allow;
		CMP ECX,ITEMGET(12,41);
		JE Allow;
		CMP ECX,ITEMGET(12,42);
		JE Allow;
		CMP ECX,ITEMGET(12,43);
		JE Allow;
		CMP ECX,ITEMGET(12,44);
		JE Allow;
		CMP ECX,ITEMGET(12,45);
		JE Allow;
		CMP ECX,ITEMGET(12,46);
		JE Allow;
		CMP ECX,ITEMGET(12,47);
		JE Allow;
		CMP ECX,ITEMGET(12,48);
		JE Allow;
		CMP ECX,ITEMGET(12,49);
		JE Allow;
		CMP ECX,ITEMGET(12,50);
		JE Allow;
		CMP ECX,ITEMGET(12,51);
		JE Allow;
		CMP ECX,ITEMGET(12,52);
		JE Allow;
		CMP ECX,ITEMGET(12,53);
		JE Allow;
		CMP EDX,ITEMGET(12,54);
		JNZ End

		Allow:
		MOV EDI,0x004FF035//004E8215  |> 8B45 10        MOV EAX,DWORD PTR SS:[EBP+10]
		JMP EDI

		End:
		MOV EDI,0x004FF072//004E8252  |> 33C0           XOR EAX,EAX
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsFixLuck()
{
	__asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1806;
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,37);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,38);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,39);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,40);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,41);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,42);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,43);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,44);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,44);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,45);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,46);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,47);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,48);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,49);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,50);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,51);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,52);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,53);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,54);
		JE Allow;

		
		MOV EDI,0x0050F516//004F624E  |. 7F 17          JG SHORT GameServ.004F6267
		JMP EDI;
		Allow:
		
		MOV EDI,0x0050F518//004F6250  |. 8B4D FC        MOV ECX,DWORD PTR SS:[EBP-4]
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsFixOpt()
{
	__asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1800;
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,37);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,38);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,39);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,40);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,41);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,42);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,43);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,44);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,45);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,46);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,47);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,48);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,49);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,50);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,51);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,52);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,53);
		JE Allow;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,54);
		JE Allow;
		
		MOV EDI,0x0050F771//004F64A9


		JMP EDI;

		Allow:
		MOV EDI,0x0050F753//004F648B
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsFlyToIcarus()
{
	__asm
	{
		CMP ECX,0x1A1E;
		JE Allow;

		CMP ECX,ITEMGET(12,36);
		JE Allow;
		CMP ECX,ITEMGET(12,37);
		JE Allow;
		CMP ECX,ITEMGET(12,38);
		JE Allow;
		CMP ECX,ITEMGET(12,39);
		JE Allow;
		CMP ECX,ITEMGET(12,40);
		JE Allow;
		CMP ECX,ITEMGET(12,41);
		JE Allow;
		CMP ECX,ITEMGET(12,42);
		JE Allow;
		CMP ECX,ITEMGET(12,43);
		JE Allow;
		CMP ECX,ITEMGET(12,44);
		JE Allow;
		CMP ECX,ITEMGET(12,45);
		JE Allow;
		CMP ECX,ITEMGET(12,46);
		JE Allow;
		CMP ECX,ITEMGET(12,47);
		JE Allow;
		CMP ECX,ITEMGET(12,48);
		JE Allow;
		CMP ECX,ITEMGET(12,49);
		JE Allow;
		CMP ECX,ITEMGET(12,50);
		JE Allow;
		CMP ECX,ITEMGET(12,51);
		JE Allow;
		CMP ECX,ITEMGET(12,52);
		JE Allow;
		CMP ECX,ITEMGET(12,53);
		JE Allow;
		CMP ECX,ITEMGET(12,54);
		JE Allow;

		MOV EDI,0x004FB54D
		JMP EDI;

		Allow:
		MOV EDI,0x004FB59B
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsFlyToKanturu()
{
	__asm
	{
		CMP ECX,0x1A1E;
		JE Allow;


		CMP ECX,ITEMGET(12,36);
		JE Allow;
		CMP ECX,ITEMGET(12,37);
		JE Allow;
		CMP ECX,ITEMGET(12,38);
		JE Allow;
		CMP ECX,ITEMGET(12,39);
		JE Allow;
		CMP ECX,ITEMGET(12,40);
		JE Allow;
		CMP ECX,ITEMGET(12,41);
		JE Allow;
		CMP ECX,ITEMGET(12,42);
		JE Allow;
		CMP ECX,ITEMGET(12,43);
		JE Allow;
		CMP ECX,ITEMGET(12,44);
		JE Allow;
		CMP ECX,ITEMGET(12,44);
		JE Allow;
		CMP ECX,ITEMGET(12,45);
		JE Allow;
		CMP ECX,ITEMGET(12,46);
		JE Allow;
		CMP ECX,ITEMGET(12,47);
		JE Allow;
		CMP ECX,ITEMGET(12,48);
		JE Allow;
		CMP ECX,ITEMGET(12,49);
		JE Allow;
		CMP ECX,ITEMGET(12,50);
		JE Allow;
		CMP ECX,ITEMGET(12,51);
		JE Allow;
		CMP ECX,ITEMGET(12,52);
		JE Allow;
		CMP ECX,ITEMGET(12,53);
		JE Allow;
		CMP ECX,ITEMGET(12,54);
		JE Allow;
		MOV EDI,0x004FB8CE//004E75CD
		JMP EDI;

		Allow:
		MOV EDI,0x004FB918//004E760C
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsFlyToRefinedTower()
{
	__asm
	{
		CMP EDX,0x1A1E;
		JE Allow;

		CMP EDX,ITEMGET(12,36);
		JE Allow;
		CMP EDX,ITEMGET(12,37);
		JE Allow;
		CMP EDX,ITEMGET(12,38);
		JE Allow;
		CMP EDX,ITEMGET(12,39);
		JE Allow;
		CMP EDX,ITEMGET(12,40);
		JE Allow;
		CMP EDX,ITEMGET(12,41);
		JE Allow;
		CMP EDX,ITEMGET(12,42);
		JE Allow;
		CMP EDX,ITEMGET(12,43);
		JE Allow;
		CMP EDX,ITEMGET(12,44);
		JE Allow;
		CMP EDX,ITEMGET(12,44);
		JE Allow;
		CMP EDX,ITEMGET(12,45);
		JE Allow;
		CMP EDX,ITEMGET(12,46);
		JE Allow;
		CMP EDX,ITEMGET(12,47);
		JE Allow;
		CMP EDX,ITEMGET(12,48);
		JE Allow;
		CMP EDX,ITEMGET(12,49);
		JE Allow;
		CMP EDX,ITEMGET(12,50);
		JE Allow;
		CMP EDX,ITEMGET(12,51);
		JE Allow;
		CMP EDX,ITEMGET(12,52);
		JE Allow;
		CMP EDX,ITEMGET(12,53);
		JE Allow;
		CMP EDX,ITEMGET(12,54);
		JE Allow;


		MOV EDI,0x0058384F
		JMP EDI;

		Allow:
		MOV EDI,0x005838E0
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsExc1Fix()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1A1E;
		JE FixExcOpt;

		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JGE Check

		Exit:
		MOV EDI,0x0050F33A//004F6072


		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0050F2EF//004F6027
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsExc2Fix()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1A1E;
		JE FixExcOpt;

		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JGE Check

		Exit:
		MOV EDI,0x0050F54F//004F6287


		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0050F538//004F6270  |. 8B55 FC        MOV EDX,DWORD PTR SS:[EBP-4]
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsExc3Fix()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1A1E;
		JE FixExcOpt;

		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JGE Check

		Exit:
		MOV EDI,0x0050F74A//004F6482


		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0050F715//004F644D
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsExc4Fix()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1A1E;
		JE FixExcOpt;

		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JGE Check

		Exit:
		MOV EDI,0x0050FA78 //004F67B0


		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0050FA43//004F677B
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsExc5Fix()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1A1E;
		JE FixExcOpt;

		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JGE Check

		Exit:
		MOV EDI,0x0050FEB5//004F6BED
		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0050FDFE//004F6B36
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsRequiredLevel()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JL Jump1;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JG Jump1;
		JMP Continue;

		Jump1:
		CMP DWORD PTR SS:[EBP-0x08],0x00;
		JL Continue2;
		CMP DWORD PTR SS:[EBP-0x08],0x1800;
		JL Continue;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,36);
		JL Continue2;
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE Continue;
		JMP Exit;

		Continue:
		MOV EDI,0x0050EC40//004F597A
		JMP EDI

		Continue2:
		MOV EDI,0x0050EC2E//004F5968
		JMP EDI

		Exit:
		MOV EDI,0x0050EC2C//004F5966
		JMP EDI
	}
}
__declspec() void ThirdItemsRepairFix()
{
	BYTE cFix1[54] = {0x8B,0x45,0xF0,0x3D,0x00,0x1C,0x00,0x00,0x7D,0x3E,0x3D,0x00,0x1A,0x00,0x00,0x7C,0x07,0x3D,0x04,0x1A,0x00,0x00,0x7C,0x30,0x3D,0x0A,0x1A,0x00,0x00,0x74,0x29,0x3D,0x07,0x18,0x00,0x00,0x7C,0x10,0x3D,0x24,0x18,0x00,0x00,0x7C,0x1B,0x3D,0x00,0x1A,0x00,0x00,0x7D,0x3B,0x90,0x90};
	memcpy((BYTE*)0x0043DD6B,cFix1,sizeof(cFix1));//0043824B
}
__declspec() void ThirdWingsRepairFix()
{
	BYTE cFix1[7] = {0xE9,0xEC,0x01,0x00,0x00,0x90,0x90};
	BYTE cFix2[41] = {0x81,0x7D,0xF0,0x24,0x18,0x00,0x00,0x7C,0x0E,0x81,0x7D,0xF0,0x28,0x1C,0x00,0x00,0x7F,0x05,0xE9,0x2E,0xFE,0xFF,0xFF,0x81,0x7D,0xF0,0x00,0x1C,0x00,0x00,0x0F,0x8D,0x33,0xFE,0xFF,0xFF,0xE9,0xEF,0xFD,0xFF,0xFF};
	memcpy((BYTE*)0x0043DD6B,cFix1,sizeof(cFix1));//0x0043DD6B
	memcpy((BYTE*)0x0043DF5C,cFix2,sizeof(cFix2));
}
void ProcessAutoRecuperation(void * lpParam)
{
	while(true)
	{
		Sleep(5000);

		for(int i=0; i < (MAX_PLAYERID - MIN_PLAYERID); i++)
		{
			DWORD PlayerID = i+MIN_PLAYERID;

			if(gObjIsConnected(PlayerID))
			{
				BYTE  option, change;
				WORD  ItemSize;
				DWORD pItemDataAddr;

				change = 0;

				//Get GS Item Object Size
				ItemSize           =  0xB0;

				//Get Player Object
				LPOBJ pObj         = (LPOBJ)(PlayerID*OBJECT_SIZE + OBJECT_BASE);

				//Get Player Inventory Object
				pItemDataAddr      = GetItemDataAddr(pObj);

				//Get Item Object in Position
				LPOBJITEM wingsObj = (LPOBJITEM) (pItemDataAddr + 7 * ItemSize);

				//Wings Autorecuperation
				//4 = life 5% recovery
				//8 = mana 5% recovery
				if(((wingsObj->m_Type >= ITEMGET(12,36)) && (wingsObj->m_Type <= ITEMGET(12,66))))
				{
					option = (wingsObj->m_NewOption)&4;
					if(option == 4)
					{
						if(pObj->Life < (pObj->MaxLife + pObj->AddLife))
						{
							float HPtoAdd = ((pObj->MaxLife + pObj->AddLife) * 0.05);
							pObj->Life   += HPtoAdd;
							change        = 1;
						}
					}

					option = (wingsObj->m_NewOption)&8;
					if(option == 8)
					{
						if(pObj->Mana < (pObj->MaxMana + pObj->AddMana))
						{
							float MPtoAdd = ((pObj->MaxMana + pObj->AddMana) * 0.05);
							pObj->Mana   += MPtoAdd;
							change        = 1;
						}
					}

					//Additional HP Recovery
					if(wingsObj->m_NewOption <= 15)
					{
						if(wingsObj->m_Option3 > 0)
						{
							if(pObj->Life < (pObj->MaxLife + pObj->AddLife))
							{
								float HPtoAdd = (pObj->MaxLife + pObj->AddLife) * wingsObj->m_Option3 / 100;
								pObj->Life   += HPtoAdd;
								change        = 1;
							}
						}
					}
				}

				if(change == 1)
				{
					//Send Mana Refill and Life Refill
					GCReFillSend(pObj->m_Index,pObj->MaxLife + pObj->AddLife,0xFE,0,pObj->iMaxShield + pObj->iAddShield);
					GCManaSend  (pObj->m_Index,pObj->MaxMana + pObj->AddMana,0xFE,0,pObj->MaxBP + pObj->AddBP);
				}
			}
		}
	}
}

void ReadyNewWings()
{
	//MakePreviewCharSet
	HookFunc(0x0040378D,(DWORD)(&gObjMakePreviewCharSet_));

	//Wings (Jewels)
	*(DWORD*)((0x004FE86D+1)) = (DWORD)&ThirdWingsEnableSoul - (0x004FE86D+5); //004E7AED  |. 81FA 1E1A0000  CMP EDX,1A1E
	*(BYTE*)(0x004FE86D) = 0xE9;
	*(DWORD*)((0x004FE327+1)) = (DWORD)&ThirdWingsEnableBless - (0x004FE327+5);//004E75C7  |. 81F9 1E1A0000  CMP ECX,1A1E
	*(BYTE*)(0x004FE327) = 0xE9;
	*(DWORD*)((0x004FF02D+1)) = (DWORD)&ThirdWingsEnableLife - (0x004FF02D+5);//004E820D  |. 81FA 1E1A0000  CMP EDX,1A1E
	*(BYTE*)(0x004FF02D) = 0xE9;

	//Wings (Options)
	*(DWORD*)((0x0050F50F+1)) = (DWORD)&ThirdWingsFixLuck - (0x0050F50F+5);//004F6247  |. 817D F8 061800>CMP DWORD PTR SS:[EBP-8],1806
	*(BYTE*)(0x0050F50F) = 0xE9;
	*(DWORD*)((0x0050F74A+1)) = (DWORD)&ThirdWingsFixOpt - (0x0050F74A+5);//004F6482  |> 817D F8 001800>CMP DWORD PTR SS:[EBP-8],1800
	*(BYTE*)(0x0050F74A) = 0xE9;

	//wings (Excellent Options)
	*(DWORD*)((0x0050F2E6+1)) = (DWORD)&ThirdWingsExc1Fix - (0x0050F2E6+5);//004F601E  |> 817D F8 1E1A00>CMP DWORD PTR SS:[EBP-8],1A1E
	*(BYTE*)(0x0050F2E6) = 0xE9;
	HookNop(0x0050F2E6+5,2);
	*(DWORD*)((0x0050F52F+1)) = (DWORD)&ThirdWingsExc2Fix - (0x0050F52F+5);//004F6267  |> 817D F8 1E1A00>CMP DWORD PTR SS:[EBP-8],1A1E
	*(BYTE*)(0x0050F52F) = 0xE9;
	HookNop(0x0050F52F+5,2);
	*(DWORD*)((0x0050F70C+1)) = (DWORD)&ThirdWingsExc3Fix - (0x0050F70C+5);//004F6444  |> 817D F8 1E1A00>CMP DWORD PTR SS:[EBP-8],1A1E
	*(BYTE*)(0x0050F70C) = 0xE9;
	HookNop(0x0050F70C+5,2);
	*(DWORD*)((0x0050FA3A+1)) = (DWORD)&ThirdWingsExc4Fix - (0x0050FA3A+5);//004F6772  |> 817D F8 1E1A00>CMP DWORD PTR SS:[EBP-8],1A1E
	*(BYTE*)(0x0050FA3A) = 0xE9;
	HookNop(0x0050FA3A+5,2);
	*(DWORD*)((0x0050FDF1+1)) = (DWORD)&ThirdWingsExc5Fix - (0x0050FDF1+5);//004F6B29  |> 817D F8 1E1A00>CMP DWORD PTR SS:[EBP-8],1A1E
	*(BYTE*)(0x0050FDF1) = 0xE9;
	HookNop(0x0050FDF1+5,2);

	//Wings (Entering)
	*(DWORD*)((0x004FB547+1)) = (DWORD)&ThirdWingsFlyToIcarus - (0x004FB547+5);//004E4F77  |. 81FA 1E1A0000  CMP EDX,1A1E
	*(BYTE*)(0x004FB547) = 0xE9;
	*(DWORD*)((0x004FB8C8+1)) = (DWORD)&ThirdWingsFlyToKanturu - (0x004FB8C8+5);//004E75C7  |. 81F9 1E1A0000  CMP ECX,1A1E
	*(BYTE*)(0x004FB8C8) = 0xE9;
	*(DWORD*)((0x00583849+1)) = (DWORD)&ThirdWingsFlyToRefinedTower - (0x00583849+5);
	*(BYTE*)(0x00583849) = 0xE9;

	//Wings (Required Level)
	*(DWORD*)((0x0050EC1F+1)) = (DWORD)&ThirdWingsRequiredLevel - (0x0050EC1F+5);//004F5959
	*(BYTE*)(0x0050EC1F) = 0xE9;
	HookNop(0x0050EC1F+5,8);
	*(BYTE*)(0x0050EB72) = 0x28;//004F58AC

	//Wings Efects
	_beginthread(ProcessAutoRecuperation, 0, NULL);

	//Wings & Items Repair
	ThirdItemsRepairFix();
	ThirdWingsRepairFix();
}