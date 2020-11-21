#include "stdafx.h"

#define CS_SET_WING1(x)  ( ((x) & 0x03 ) << 2 )

void gObjMakePreviewCharSet_(int aIndex) //OK
{

	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);
	//-----
	gObjMakePreviewCharSet(aIndex);
	//-----
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
		JNZ End

		Allow:
		MOV EDI,0x00511BC5
		JMP EDI

		End:
		MOV EDI,0x00511C02
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
		CMP EDX,ITEMGET(12,44);
		JNZ End

		Allow:
		MOV EDI,0x0051167F
		JMP EDI

		End:
		MOV EDI,0x005116BC
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
		CMP EDX,ITEMGET(12,44);
		JNZ End


		Allow:
		MOV EDI,0x00512385
		JMP EDI

		End:
		MOV EDI,0x005123C2
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

		MOV EDI,0x00522936
		JMP EDI;

		Allow:
		MOV EDI,0x00522938
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
		
		MOV EDI,0x00522B71
		JMP EDI;

		Allow:
		MOV EDI,0x00522B73
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
		MOV EDI,0x0050E978
		JMP EDI;

		Allow:
		MOV EDI,0x0050E97A
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
		MOV EDI,0x0052275A
		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0052270F
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
		MOV EDI,0x0052296F
		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x00522958
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
		MOV EDI,0x00522B6A
		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x00522B35
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
		MOV EDI,0x00522E98
		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x00522E63
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
		MOV EDI,0x005232D5
		JMP EDI

		Check:
		CMP DWORD PTR SS:[EBP-0x08],ITEMGET(12,66);
		JLE FixExcOpt
		JMP Exit

		FixExcOpt:
		MOV EDI,0x0052321E
		JMP EDI
	}
}
__declspec(naked) void ThirdWingsRequiredLevel()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x08],0x1874;
		JL Jump1;
		CMP DWORD PTR SS:[EBP-0x08],0x1888;
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
		MOV EDI,0x00522060
		JMP EDI

		Continue2:
		MOV EDI,0x0052204E
		JMP EDI

		Exit:
		MOV EDI,0x0052204C
		JMP EDI
	}
}
__declspec() void ThirdItemsRepairFix()
{
	BYTE cFix1[54] = {0x8B,0x45,0xF0,0x3D,0x00,0x1C,0x00,0x00,0x7D,0x3E,0x3D,0x00,0x1A,0x00,0x00,0x7C,0x07,0x3D,0x04,0x1A,0x00,0x00,0x7C,0x30,0x3D,0x0A,0x1A,0x00,0x00,0x74,0x29,0x3D,0x07,0x18,0x00,0x00,0x7C,0x10,0x3D,0x24,0x18,0x00,0x00,0x7C,0x1B,0x3D,0x00,0x1A,0x00,0x00,0x7D,0x3B,0x90,0x90};
	memcpy((BYTE*)0x00440C8B,cFix1,sizeof(cFix1));
}
__declspec() void ThirdWingsRepairFix()
{
	BYTE cFix1[7] = {0xE9,0xEC,0x01,0x00,0x00,0x90,0x90};
	BYTE cFix2[41] = {0x81,0x7D,0xF0,0x24,0x18,0x00,0x00,0x7C,0x0E,0x81,0x7D,0xF0,0x28,0x1C,0x00,0x00,0x7F,0x05,0xE9,0x2E,0xFE,0xFF,0xFF,0x81,0x7D,0xF0,0x00,0x1C,0x00,0x00,0x0F,0x8D,0x33,0xFE,0xFF,0xFF,0xE9,0xEF,0xFD,0xFF,0xFF};
	memcpy((BYTE*)0x00440C8B,cFix1,sizeof(cFix1));
	memcpy((BYTE*)0x00440E7C,cFix2,sizeof(cFix2));
}

void ReadyNewWings()
{
	HookFunc(0x00403936,(DWORD)(&gObjMakePreviewCharSet_));
	
	// 3rd Wings (Jewels)
	*(DWORD*)((0x00511BBD+1)) = (DWORD)&ThirdWingsEnableSoul - (0x00511BBD+5);
	*(BYTE*)(0x00511BBD) = 0xE9;
	*(DWORD*)((0x00511677+1)) = (DWORD)&ThirdWingsEnableBless - (0x00511677+5);
	*(BYTE*)(0x00511677) = 0xE9;
	*(DWORD*)((0x0051237D+1)) = (DWORD)&ThirdWingsEnableLife - (0x0051237D+5);
	*(BYTE*)(0x0051237D) = 0xE9;

	//Wings (Options)
	*(DWORD*)((0x0052292F+1)) = (DWORD)&ThirdWingsFixLuck - (0x0052292F+5);
	*(BYTE*)(0x0052292F) = 0xE9;
	*(DWORD*)((0x00522B6A+1)) = (DWORD)&ThirdWingsFixOpt - (0x00522B6A+5);
	*(BYTE*)(0x00522B6A) = 0xE9;

	//Wings (Excellent Options)
	*(DWORD*)((0x00522706+1)) = (DWORD)&ThirdWingsExc1Fix - (0x00522706+5);
	*(BYTE*)(0x00522706) = 0xE9;
	iniciar_nopear(0x00522706+5,2);
	*(DWORD*)((0x0052294F+1)) = (DWORD)&ThirdWingsExc2Fix - (0x0052294F+5);
	*(BYTE*)(0x0052294F) = 0xE9;
	iniciar_nopear(0x0052294F+5,2);
	*(DWORD*)((0x00522B2C+1)) = (DWORD)&ThirdWingsExc3Fix - (0x00522B2C+5);
	*(BYTE*)(0x00522B2C) = 0xE9;
	iniciar_nopear(0x00522B2C+5,2);
	*(DWORD*)((0x00522E5A+1)) = (DWORD)&ThirdWingsExc4Fix - (0x00522E5A+5);
	*(BYTE*)(0x00522E5A) = 0xE9;
	iniciar_nopear(0x00522E5A+5,2);
	*(DWORD*)((0x00523211+1)) = (DWORD)&ThirdWingsExc5Fix - (0x00523211+5);
	*(BYTE*)(0x00523211) = 0xE9;
	iniciar_nopear(0x00523211+5,2);

	//(Entering)
	*(DWORD*)((0x0050E972+1)) = (DWORD)&ThirdWingsFlyToIcarus - (0x0050E972+5);
	*(BYTE*)(0x0050E972) = 0xE9;

	//(Required Level)
	*(DWORD*)((0x0052203F+1)) = (DWORD)&ThirdWingsRequiredLevel - (0x0052203F+5);
	*(BYTE*)(0x0052203F) = 0xE9;
	iniciar_nopear(0x0052203F+5,8);
	*(BYTE*)(0x00521F92) = 0x28;

	//Wings & Items Repair
	ThirdItemsRepairFix();
	ThirdWingsRepairFix();
}