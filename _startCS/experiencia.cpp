#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_EXPERIENCIA _experiencia;

//----------------------------------------------------------------------------------------//
//leitura do arquivo
void _EXPERIENCIA::iniciar_experiencia()
{
	//----------- arquivos de configuração
	_experiencia.experiencia[0] = iniciar_dll.iniciar_getprivateint("settings","iniciar_experiencie[0]", 0, ".\\configurações\\_player.settings\\_settings.experiencia.ID");
	_experiencia.experiencia[1] = iniciar_dll.iniciar_getprivateint("settings","iniciar_experiencie[1]", 0, ".\\configurações\\_player.settings\\_settings.experiencia.ID");
	_experiencia.experiencia[2] = iniciar_dll.iniciar_getprivateint("settings","iniciar_experiencie[2]", 0, ".\\configurações\\_player.settings\\_settings.experiencia.ID");
	_experiencia.experiencia[3] = iniciar_dll.iniciar_getprivateint("settings","iniciar_experiencie[3]", 0, ".\\configurações\\_player.settings\\_settings.experiencia.ID");
	_experiencia.experiencia[4] = iniciar_dll.iniciar_getprivateint("settings","iniciar_experiencie[4]", 0, ".\\configurações\\_player.settings\\_settings.experiencia.ID");
	_experiencia.experiencia[5] = iniciar_dll.iniciar_getprivateint("settings","iniciar_experiencie[5]", 0, ".\\configurações\\_player.settings\\_settings.experiencia.ID");
}

//----------------------------------------------------------------------------------------//
//experiencia, creditos shatter, modificado por kinhomace
long _add_experience(LPOBJ lpObj,DWORD ExpBase)
{
	//----------- variavel de experiencia
	float Experience = 0;

	//----------- experiencia por vip
	Experience = _experiencia.experiencia[lpObj->vip];

	//----------- retorna
    float Result = ExpBase * Experience;

	return float(Result); 
}

//----------------------------------------------------------------------------------------//
//hook devil square
__declspec(naked) void _experience_hook_devil()
{
    _asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x08]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP+0x08]
		PUSH EDX
		LEA EBX,_add_experience
		CALL EBX
		MOV DWORD PTR SS:[EBP-0x8],EAX
        MOV EBX,0x0046B448
        JMP EBX
	}
}

//----------------------------------------------------------------------------------------//
//hook party devil square
__declspec(naked) void _experience_hook_party_devil()
{
    _asm
	{
        MOV EAX,DWORD PTR SS:[EBP-0x0C]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x58]
		PUSH EDX
		LEA EBX,_add_experience
		CALL EBX
		MOV DWORD PTR SS:[EBP-0x0C],EAX
		MOV EBX,0x0046BA9D
		JMP EBX
	}
}

//----------------------------------------------------------------------------------------//
//hook party zen devil square
__declspec(naked) void _experience_hook_party_devil_zen()
{
    _asm
	{
        MOV EAX,DWORD PTR SS:[EBP-0x0C]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x58]
		PUSH EDX
		LEA EBX,_add_experience
		CALL EBX
		MOV DWORD PTR SS:[EBP-0x0C],EAX
		MOV EBX,0x0046BBB7
		JMP EBX
	}
}

//----------------------------------------------------------------------------------------//
//hook
__declspec(naked) void _experience_hook()
{
    _asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x04]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP+0x08]
		PUSH EDX
		LEA EBX,_add_experience
		CALL EBX
		MOV DWORD PTR SS:[EBP-0x04],EAX
		MOV EBX, 0x004F4E76
		JMP EBX
	}
}

//----------------------------------------------------------------------------------------//
//hook party
__declspec(naked) void _experience_hook_party()
{
    _asm
	{
        MOV EAX,DWORD PTR SS:[EBP-0x08]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x54]
		PUSH EDX
		LEA EBX,_add_experience
		CALL EBX
		MOV DWORD PTR SS:[EBP-0x08],EAX
		MOV EBX,0x004F556B
		JMP EBX
	}
}

//----------------------------------------------------------------------------------------//
//hook party zen
__declspec(naked) void _experience_hook_party_zen()
{
    _asm
	{
        MOV EAX,DWORD PTR SS:[EBP-0x08]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x54]
		PUSH EDX
		LEA EBX,_add_experience
		CALL EBX
		MOV DWORD PTR SS:[EBP-0x08],EAX
		MOV EBX,0x004F5670
		JMP EBX
	}
}