#include "StdAfx.h"

CFruits gFruits;

void CFruits::Load()
{
	SetRange((LPVOID)0x004FB0C5, 21, ASM::NOP);				// -> Altera Packet BYTE -> WORD //0x004FB1B5
	SetJmp((LPVOID)0x004FB0C0, this->SelectByteWord);		// -> Altera Packet BYTE -> WORD //004FB1B0

	SetRange((LPVOID)0x004FB1E6, 18, ASM::NOP);				// -> seleciona o case 0: energia e altera de BYTE para WORD //0x004FB2D6
	SetJmp((LPVOID)0x004FB1E1, this->SelectCaseAddPoint_0);	// -> seleciona o case 0: energia e altera de BYTE para WORD //004FB2D1
	
	SetRange((LPVOID)0x004FB242, 15, ASM::NOP);				// -> seleciona o case 1: vitalidade e altera de BYTE para WORD //004FB332
	SetJmp((LPVOID)0x004FB23D, this->SelectCaseAddPoint_1);	// -> seleciona o case 1: vitalidade e altera de BYTE para WORD //004FB32D

	SetRange((LPVOID)0x004FB256, 15, ASM::NOP);				// -> seleciona o case 2: agilidade e altera de BYTE para WORD //004FB346
	SetJmp((LPVOID)0x004FB251, this->SelectCaseAddPoint_2);	// -> seleciona o case 2: agilidade e altera de BYTE para WORD //004FB341
	 
	SetRange((LPVOID)0x004FB26A, 15, ASM::NOP);				// -> seleciona o case 3: força e altera de BYTE para WORD  //004FB5FA
	SetJmp((LPVOID)0x004FB265, this->SelectCaseAddPoint_3);	// -> seleciona o case 3: força e altera de BYTE para WORD  //004FB5F5

	SetRange((LPVOID)0x004FB27E, 13, ASM::NOP);				// -> seleciona o case 4: comando e altera de BYTE para WORD //004FB36E
	SetJmp((LPVOID)0x004FB279, this->SelectCaseAddPoint_4);	// -> seleciona o case 4: comando e altera de BYTE para WORD //004FB369

	SetRange((LPVOID)0x004FB290, 16, ASM::NOP);					// -> seleciona o case default: caso seja invalido //004FB380
	SetJmp((LPVOID)0x004FB28B, this->SelectCaseAddPoint_default);	// -> seleciona o case default: caso seja invalido //004FB37B
	
	*(BYTE*)(0x004FB379+2)	= 0xFF; // altera o valor 0xFF: 255 para 0xFFFF: 65535 //004FB469

	 /* retirar pontos sem relogar 100% by kinhomace */

	SetRange((LPVOID)0x004FB4B5, 12, ASM::NOP);					// -> seleciona o case 0: energia e altera de BYTE para WORD //004FB5A5
	SetJmp((LPVOID)0x004FB4B0, this->SelectCaseRetPoint_0);	// -> seleciona o case 0: energia e altera de BYTE para WORD //004FB5A0 

	SetRange((LPVOID)0x004FB4F9, 12, ASM::NOP);					// -> seleciona o case 1: vitalidade e altera de BYTE para WORD //004FB5E9
	SetJmp((LPVOID)0x004FB4F4, this->SelectCaseRetPoint_1);	// -> seleciona o case 1: vitalidade e altera de BYTE para WORD//004FB5E4

	SetRange((LPVOID)0x004FB50A, 12, ASM::NOP);					// -> seleciona o case 2: agilidade e altera de BYTE para WORD //004FB5FA
	SetJmp((LPVOID)0x004FB505, this->SelectCaseRetPoint_2);	// -> seleciona o case 2: agilidade e altera de BYTE para WORD//004FB5F5

	SetRange((LPVOID)0x004FB51B, 12, ASM::NOP);					// -> seleciona o case 3: força e altera de BYTE para WORD //004FB60B
	SetJmp((LPVOID)0x004FB516, this->SelectCaseRetPoint_3);	// -> seleciona o case 3: força e altera de BYTE para WORD //004FB606

	SetRange((LPVOID)0x004FB52C, 12, ASM::NOP);					// -> seleciona o case 4: comando e altera de BYTE para WORD //004FB61C
	SetJmp((LPVOID)0x004FB527, this->SelectCaseRetPoint_4);	// -> seleciona o case 4: comando e altera de BYTE para WORD //004FB617

	SetRange((LPVOID)0x004FB53D, 19, ASM::NOP);					// -> seleciona o case default: caso seja invalido - fazer direto no main//004FB62D
	SetJmp((LPVOID)0x004FB538, this->SelectCaseRetPoint_default);	// -> seleciona o case default: caso seja invalido - fazer direto no main //004FB628



	*(BYTE*)(0x004FB5A0+2)	= 0xFF; // altera o valor 0xFF: 255 para 0xFFFF: 65535 //004FB690

	//===================================================================================
	// Retira messagebox das fruits
	//===================================================================================
	SetNop(0x004FB3A8, 5);
	SetNop(0x004FB5E5, 5);
	SetNop(0x004FB608, 5);
	SetNop(0x004FB5D3, 5);
}

void __declspec(naked) CFruits::SelectByteWord()
{
	_asm
	{
		SUB ESP,0x26C
		MOV EAX,DWORD PTR SS:[ESP+0x270]
		PUSH EBX
		PUSH EBP
		PUSH ESI
		MOV DX,WORD PTR DS:[EAX+4]
		MOV CL,BYTE PTR DS:[EAX+6]
		MOV WORD PTR SS:[ESP+0xC],DX
		MOV EDI, 0x004FB0DA//004FB1CA
		JMP EDI
	}
}

void __declspec(naked) CFruits::SelectCaseAddPoint_0() // case 0: energy
{
	_asm
	{
		MOV CX,WORD PTR SS:[ESP+0x10]
		MOV DWORD PTR SS:[ESP+0x14],0x0A8
		ADD WORD PTR DS:[EAX+0x1E],CX
		JMP SelectCaseAddPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseAddPoint_1() // case 1: vitality
{
	_asm
	{
		MOV DX,WORD PTR SS:[ESP+0x10]
		MOV DWORD PTR SS:[ESP+0x14],0x0A9
		ADD WORD PTR DS:[EAX+0x1C],DX
		JMP SelectCaseAddPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseAddPoint_2() // case 2: agility
{
	_asm
	{
		MOV CX,WORD PTR SS:[ESP+0x10]
		MOV DWORD PTR SS:[ESP+0x14],0x0A7
		ADD WORD PTR DS:[EAX+0x1A],CX
		JMP SelectCaseAddPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseAddPoint_3() // case 3: strenght
{
	_asm
	{
		MOV DX,WORD PTR SS:[ESP+0x10]
		MOV DWORD PTR SS:[ESP+0x14],0x0A6
		ADD WORD PTR DS:[EAX+0x18],DX
		JMP SelectCaseAddPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseAddPoint_4() // case 4: command
{
	_asm
	{
		MOV CX,WORD PTR SS:[ESP+0x10]
		MOV DWORD PTR SS:[ESP+0x14],0x76C
		ADD WORD PTR DS:[EAX+0x20],CX
		JMP SelectCaseAddPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseAddPoint_default() // case default:
{
	_asm
	{
		MOV DX,WORD PTR SS:[ESP+0x10]
		MOV EBX,DWORD PTR DS:[0x7772ABC]//[77706B4]
		ADD WORD PTR DS:[EAX+0x4C],DX
		MOV EAX,DWORD PTR DS:[0x5841988] //583F580
		MOV EDI, 0x004FB2A0 //004FB390
		JMP EDI
	}
}

void __declspec(naked) CFruits::SelectCaseRetPoint_0() // case 0: energy
{
	_asm
	{
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		MOV EDI,0x0A8
		SUB WORD PTR DS:[EAX+0x1E],BX
		JMP SelectCaseRetPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseRetPoint_1() // case 1: vitality
{
	_asm
	{
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		MOV EDI,0x0A9
		SUB WORD PTR DS:[EAX+0x1C],BX
		JMP SelectCaseRetPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseRetPoint_2() // case 2: agility
{
	_asm
	{
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		MOV EDI,0x0A7
		SUB WORD PTR DS:[EAX+0x1A],BX
		JMP SelectCaseRetPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseRetPoint_3() // case 3: strenght
{
	_asm
	{
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		MOV EDI,0x0A6
		SUB WORD PTR DS:[EAX+0x18],BX
		JMP SelectCaseRetPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseRetPoint_4() // case 4: command
{
	_asm
	{
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		MOV EDI,0x76C
		SUB WORD PTR DS:[EAX+0x20],BX
		JMP SelectCaseRetPoint_default
	}
}

void __declspec(naked) CFruits::SelectCaseRetPoint_default() // case default:
{
	_asm
	{
		MOV EDI,DWORD PTR SS:[ESP+0x1C]
		MOV EBX,DWORD PTR SS:[ESP+0x10]
		MOV ESI,DWORD PTR DS:[0x7772ABC]//[77706B4]
		ADD WORD PTR DS:[EAX+0x70],BX
		JMP LOCAL
		LOCAL:
		MOV EAX, 0x004FB550
		JMP EAX
	}
}