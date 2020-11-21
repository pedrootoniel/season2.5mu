#include "stdafx.h"

DWORD points;

__declspec(naked) void gObjPointsFix() //nova variavel de armazenamento
{
	_asm
	{
	mov edx, points
	push edx
	push 0x77BDC30
	push ecx
	mov edi, 0x0064AADA
	jmp edi
	}
}