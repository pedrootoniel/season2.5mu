#include "stdafx.h"

DWORD Exc;

__declspec(naked) void ExcShop()
{
	Exc=0;

	_asm
	{
		MOV EDI,GetNumber
		CALL EDI
		MOV DWORD PTR SS:[EBP-0xBC],EAX
		LEA ECX,DWORD PTR SS:[EBP-0x9C]
		MOV EDI,GetToken
		CALL EDI
		MOV DWORD PTR SS:[EBP-0xA0],EAX
		LEA ECX,DWORD PTR SS:[EBP-0x9C]
		MOV EDI,GetNumber
		CALL EDI
		MOV Exc,EAX
		MOV EDI,ShopExcellentMod_Exit1 
		JMP EDI
	}
}

__declspec(naked) void ExcShopAdd()
{
	_asm
	{
		PUSH Exc
		MOV AL,BYTE PTR SS:[EBP+0x20]
		MOV EDI,ShopExcellentMod_Exit2
		JMP EDI
	}
}

void AssemblyExcShops()
{
	*(DWORD*)((ShopExcellentMod_Hook1+ 1)) = (DWORD)&ExcShop - (ShopExcellentMod_Hook1+ 5); 
	*(BYTE*)(ShopExcellentMod_Hook1) = 0xE9;
		
	*(DWORD*)((ShopExcellentMod_Hook2+ 1)) = (DWORD)&ExcShopAdd - (ShopExcellentMod_Hook2+ 5); 
	*(BYTE*)(ShopExcellentMod_Hook2) = 0xE9;
}
