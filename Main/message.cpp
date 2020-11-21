#include "stdafx.h"

__declspec(naked) void gObjMessage()
{
	_asm
	{
    cmp al,1
    jnz gObjMessageRed
    cmp dword ptr ds:[0x7B5658],4
    je call_je
    add esi,0x0D
    push 1
    push esi
    push 0x0584629C
    call call_normal
    add esp,0x0C
    mov dword ptr ds:[0x5846270],0
    pop esi
    add esp,0x64
    retn
    gObjMessageRed:
    cmp al,3
	jnz return_
    cmp dword ptr ds:[0x7B5658],4
    je call_je
    add esi,0x0D
    push 2
    push esi
    push 0x0584629C
    call call_normal
    add esp,0x0C
    mov dword ptr ds:[0x5846270],0
    pop esi
    add esp,0x64
    retn
	call_je:
	mov eax, 0x004DF481
	jmp eax
    call_normal:
	mov eax, 0x0058DDE0
	jmp eax
	return_:
	mov ecx, 0x004DF4BC
	jmp ecx
	}
}