#include "StdAfx.h"

CHAR *ItemDir		= "Data\\Npc\\";
CHAR *ItemFolder	= "Npc\\";
CHAR * NpcName		= "Titus";


void __declspec(naked) main()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP-0x18],0x18f //Compare mob 400  
			jnz noes;
		PUSH 0x2c4
			mov eax,0x0685FFD
			call eax
			ADD ESP,0x4
			PUSH 0
			MOV CL,BYTE PTR SS:[EBP+0x10]
		PUSH ECX
			MOV DL,BYTE PTR SS:[EBP+0xC]
		PUSH EDX
			PUSH 0x2c4
			MOV EAX,DWORD PTR SS:[EBP+0x14]
		PUSH EAX
			mov eax,0x0531B17
			call eax
			ADD ESP,0x14
			MOV DWORD PTR SS:[EBP-0x4],EAX
			MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV DWORD PTR SS:[EBP-0xC],ECX
			mov eax,0x053788D
			jmp eax;
noes:
		CMP DWORD PTR SS:[EBP-0x18],0x18f //compare mob 400
			jnz noes2;
		PUSH 0x2c5
			mov eax,0x0685FFD
			call eax
			ADD ESP,0x4
			PUSH 0
			MOV CL,BYTE PTR SS:[EBP+0x10]
		PUSH ECX
			MOV DL,BYTE PTR SS:[EBP+0xC]
		PUSH EDX
			PUSH 0x2c5
			MOV EAX,DWORD PTR SS:[EBP+0x14]
		PUSH EAX
			mov eax,0x0531B17
			call eax
			ADD ESP,0x14
			MOV DWORD PTR SS:[EBP-0x4],EAX
			MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV DWORD PTR SS:[EBP-0xC],ECX
			mov eax,0x053788D
			jmp eax;
noes2:
		CMP DWORD PTR SS:[EBP-0x18],0x176
			mov eax,0x0534150
			jmp eax;




	}


}

void __declspec(naked) load2()
{
	_asm
	{

		cmp edx,0x2c4
			jnz noes;
		xor ecx,ecx
			push -1
			push NpcName
			push ItemDir
			push 0x2c4
			mov eax,0x067FFA3
			call eax
			add esp,0x10
			push 0x1
			push 0x2600
			push 0x2901
			PUSH 0x7A99E4
			push 0x2c4
			mov eax,0x067FB27
			call eax
			add esp,0x14
			mov eax,0x0686C60
			jmp eax
noes:
		cmp edx,0x2c5
			jnz noes2;
		xor ecx,ecx
			push -1
			push NpcName
			push ItemDir
			push 0x2c5
			mov eax,0x067FFA3
			call eax
			add esp,0x10
			push 0x1
			push 0x2600
			push 0x2901
			PUSH 0x7A99E4
			push 0x2c5
			mov eax,0x067FB27
			call eax
			add esp,0x14
			mov eax,0x0686C60
			jmp eax
noes2:
		CMP DWORD PTR SS:[EBP-0xC],0x43
			ja seguir;
		MOV EDX,DWORD PTR SS:[EBP-0xC]
		XOR ECX,ECX
			MOV CL,BYTE PTR DS:[EDX+0x686D64]
		JMP DWORD PTR DS:[ECX*0x4+0x686CC0]


seguir:
		mov eax,0x0686C60
			jmp eax;


	}
}

void __declspec(naked) NpcTalk()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP+0xC],0x190 //cmp mob 400 
			jnz falso
			MOV EAX,DWORD PTR SS:[EBP-0x8]
		MOV BYTE PTR DS:[EAX+0xBC],4 //--- 4 = NPC(Enable Talk) --- 2 = MOB? --- 1 = Player?
			mov eax,0x0533ED7
			jmp eax
falso:
		CMP DWORD PTR SS:[EBP+0xC],0xC8
			mov eax,0x0533E6A
			jmp eax;


	}
}

void MonsterLoad()
{
	*(DWORD*)(0x0534149+1) = (DWORD)&main - (0x0534149+5);
	*(BYTE*)(0x0534149) = 0xE9;
	*(DWORD*)(0x0686044+1) = (DWORD)&load2 - (0x0686044+5);
	*(BYTE*)(0x0686044) = 0xE9;
	*(DWORD*)(0x0533E55+1) = (DWORD)&NpcTalk - (0x0533E55+5);
	*(BYTE*)(0x0533E55) = 0xE9;
}