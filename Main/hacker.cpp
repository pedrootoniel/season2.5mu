#include "stdafx.h"

WORD  dexterity;
WORD  speed;

__declspec(naked) void speedhacker()
{
	_asm
	{
    mov eax, dword ptr ds:[0x7B5784]
	add eax, 0x3C
    sub eax, 0x64
	mov dword ptr ds:[0x7B5784],eax
	mov edx, 0x006B459B
	jmp edx
	}
}

__declspec(naked) void character_load()
{
	_asm
	{
    mov word ptr ds:[eax+0x1A],dx
	mov dexterity, dx
	add dexterity, 0x4D
    mov dx,word ptr ss:[ebp+0x18]
	mov edi, 0x004DCFCB
	jmp edi
	}
}

__declspec(naked) void calcharacter_restruct()
{
	_asm
	{
	mov cx,  dexterity
	sub cx,  0x4d
    mov edx, dword ptr ss:[ebp-0x40]
	mov edi, 0x00589F1C
	jmp edi
	}
}

__declspec(naked) void calcharacter_restruct_speed()
{
	_asm
	{
    mov ecx, dword ptr ss:[ebp-0x40]
	mov ax, word ptr ds:[ecx+0x54]
	mov speed, ax
	add speed, 0x4D
	mov ecx, dword ptr ss:[ebp-0x40]
    add ecx,0x0B74
    push ecx
    push 0x61
    mov edx, dword ptr ss:[ebp-0x40]
    add edx,0x60
    push edx
	mov edi, 0x0058A4EA
	jmp edi
	}
}

__declspec(naked) void attack_speed_restruct()
{
	_asm
	{
    mov dx, speed
	sub dx, 0x4D
    mov dword ptr ss:[ebp-0x14],edx
	mov ecx, 0x005142B5
	jmp ecx
	}
}