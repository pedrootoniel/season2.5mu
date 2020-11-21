#include "stdafx.h"

int    map          = 0;
char * loren_market = "\\Custom\\Maps\\MapName_MarketRolen.OZT";
char * name_load    = "";

__declspec(naked) void interface_load()
{
	_asm
	{
		mov dword ptr ss:[ebp-0x94],0x27
			push 0x7B6A5C
			lea eax, dword ptr ss:[ebp-0x94]
		push eax
			mov ecx, dword ptr ss:[ebp-0x98]
		add ecx,4
			call load_1
			mov ecx, eax
			call load_2
			//
			mov dword ptr ss:[ebp-0x94],0x28
			push loren_market
			lea eax, dword ptr ss:[ebp-0x94]
		push eax
			mov ecx, dword ptr ss:[ebp-0x98]
		add ecx,4
			call load_1
			mov ecx, eax
			call load_2
			//
			mov edi, 0x006D9C56
			jmp edi
load_1:
		mov edi, 0x006DA070
			jmp edi
load_2:
		mov edi, 0x004142E0
			jmp edi
			mov esp, ebp
			pop ebp
			retn
	}
}

__declspec(naked) void name_map_load()
{
	_asm
	{
		mov map, eax
	}

	if(map == 37)
	{
		name_load = (char*)0x0784D510;
	}
	else if(map == 40)
	{
		name_load = "Loren Market";
	}
	else
	{
		_asm
		{
			mov ecx, 0x0064B185
				jmp ecx
		}
	}

	_asm
	{
		mov eax,name_load
			retn
	}
}

void LoadMapas()
{
	hook_extended(0x006D9C2B,                (DWORD)(&interface_load));
	func_nop(0x006D9C2B+5, 38);

	hook_extended(0x0064B17A,                (DWORD)(&name_map_load));
	func_nop(0x0064B17A+5, 6);
}