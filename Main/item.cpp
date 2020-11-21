#include "stdafx.h"

// cores:
// 0x00 = branco
// 0x01 = azul
// 0x02 = vermelho
// 0x03 = amarelo
// 0x04 = verde
// 0x05 = branco no vermelho
// 0x06 = cinza
// 0x07 = branco no azul
// 0x08 = branco no amarelo
// 0x09 = verde no azul
// 0x0A = cinza (2)
// 0x0B = cinza escuro

//variaveis usadas
char * jewel_infor = "";

int   joia_ID      = 0;
short item_ID      = 0;
int   invcolor     = 0;
int   color        = 0;
int   text         = 0;
char  number       = 0;
float RR           = 0.0f;
float GG           = 0.0f;
float BB           = 0.0f;



__declspec(naked) void gObjItemColorInventory()
{
	_asm
	{
		mov dx,word ptr ds:[ebp]
		mov joia_ID, edx
	}

	if(joia_ID == ITEMGET(12,15))
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(12,30))
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(12,31))
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(14,13))
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(14,14))
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(14,16))
	{
		invcolor = 3;
	}
	else if(joia_ID == ITEMGET(14,22))
	{
		invcolor = 3;
	}

	else if(joia_ID >= ITEMGET(14,68) && joia_ID <= ITEMGET(14,84) ) // Jewel Customs
	{
		invcolor = 3;
	}
	
	else if(joia_ID >= ITEMGET(12,0) && joia_ID <= ITEMGET(12,3) ) // Wings Customs
	{
		invcolor = 3;
	}

	else if(joia_ID >= ITEMGET(12,36) && joia_ID <= ITEMGET(12,66) ) // Wings Customs
	{
		invcolor = 3;
	}
	else if(joia_ID >= ITEMGET(15,22) && joia_ID <= ITEMGET(15,31) ) // Scroll Custom
	{
		invcolor = 3;
	}	
	//inserir novos items
	else
	{
		_asm // retornar para a função original
		{
			mov eax, 0x005FD93F //00615379
			jmp eax
		}
	}

	_asm // função da cor
	{
		mov edi, invcolor;
		mov eax,dword ptr ds:[0x79F4B00]//[7A27BF8]
		mov dword ptr ss:[esp+0x20],edi
			mov eax, 0x005FDA10//00615416 
			jmp eax
	}
}

__declspec(naked) void gObjItemInformation()
{
	_asm
	{
		mov dx, word ptr ss:[ebp]
		mov joia_ID, edx
	}

	if(joia_ID == ITEMGET(14,16))
	{
		color = 0;
		text  = 0;
		jewel_infor = (char*)0x077D7C34;


	}
	else if(joia_ID == ITEMGET(14,68))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Torna o seu Item Excellente";
	}
	else if(joia_ID == ITEMGET(14,69))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Aprimora o Level do seu Item para +13";
	}
	else if(joia_ID == ITEMGET(14,70))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Torna o seu Item Ancientt";
	}
	else if(joia_ID == ITEMGET(14,71))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Adiciona Luck à qualquer Item";
	}
	else if(joia_ID == ITEMGET(14,72))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Adiciona Skill à qualquer Item";
	}
	else if(joia_ID == ITEMGET(14,73))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Adiciona Option+16 à qualquer Item";
	}
	else if(joia_ID == ITEMGET(14,74))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Aprimora o seu Item em 1 Level ( +14 // +15 )";
	}
	else if(joia_ID == ITEMGET(14,75))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Remove todos os Options Harmony";
	}
	else if(joia_ID == ITEMGET(14,76))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Remove todas as Options Ancientt";
	}
	else if(joia_ID == ITEMGET(14,77))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Premia o jogador com Cash!";
	}
	else if(joia_ID == ITEMGET(14,78))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Premia o jogador com Gold!";
	}
	else if(joia_ID == ITEMGET(14,79))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Adiciona 1 Reset ao seu Personagem...";
	}
	else if(joia_ID == ITEMGET(14,80))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Retorna o seu Item em 1 Level ( +15 // +14 )";
	}
	else if(joia_ID == ITEMGET(14,81))
	{
		color = 0;
		text  = 0;
		jewel_infor = "Transfere o jogador para uma área exclusiva, com Drop & EXP. Especiais!!";
	}
	else if(joia_ID == ITEMGET(14,82))
	{
		color = 7;
		text  = 0;
		jewel_infor = "Bronze Box - Drop de Item +15";
	}
	else if(joia_ID == ITEMGET(14,83))
	{
		color = 7;
		text  = 0;
		jewel_infor = "Silver Box - Drop de Item Semi-Full Options";
	}
	else if(joia_ID == ITEMGET(14,84))
	{
		color = 7;
		text  = 0;
		jewel_infor = "Golden Box - Drop de Item Full Options";
	}
	else if(joia_ID >= ITEMGET(14,82) && joia_ID <= ITEMGET(14,84) )
	{
		color = 7;
		text  = 1;
		jewel_infor = "Box Especial Edition";
	}
	else if(joia_ID >= ITEMGET(12,36) && joia_ID <= ITEMGET(12,41) )
	{
		color = 7;
		text  = 0;
		jewel_infor = "Custom Wings";
	}

	else if(joia_ID >= ITEMGET(0,33) && joia_ID <= ITEMGET(0,38) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(5,14) && joia_ID <= ITEMGET(5,15) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(6,17) && joia_ID <= ITEMGET(6,21) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(7,40) && joia_ID <= ITEMGET(7,55) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(8,40) && joia_ID <= ITEMGET(9,55) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(9,40) && joia_ID <= ITEMGET(9,55) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(10,40) && joia_ID <= ITEMGET(10,55) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(11,40) && joia_ID <= ITEMGET(11,55) )
	{
		color = 5;
		text  = 0;
		jewel_infor = "Origin Edition";
	}

	else if(joia_ID >= ITEMGET(15,22 ) && joia_ID <= ITEMGET(15,31) )
	{
		color = 7;
		text  = 0;
		jewel_infor = "Golden Summon Book";
	}

	//inserir novos items
	else
	{
		_asm
		{
			mov edi, 0x006010E8//00619171
			jmp edi
		}
	}

	_asm
	{
		lea eax,dword ptr ds:[eax+eax*4]
		PUSH jewel_infor
			lea edx,dword ptr ds:[eax+eax*4]
		lea eax,dword ptr ds:[edx*4+0x79C1E10]//79F4F00
		push eax
			call CALL_INFOR
			mov eax,dword ptr ds:[0x79F4B00] //7A27BF8
		add esp,8
			mov esi, color
			mov dword ptr ds:[EAX*4+0x79C2FAC],esi//79F609C
			mov edi, text
			mov dword ptr ds:[EAX*4+0x79F1FA0],edi//7A25098
			inc eax
			mov dword ptr ds:[0x79F4B00],eax//7A27BF8
			mov edi, 0x006010E8//619171
			jmp edi
CALL_INFOR:
		mov edi, 0x00755E60 //00791B10


			jmp edi
	}
}

__declspec(naked) void gObjItemInsertOne()
{
	_asm
	{
		mov joia_ID, esi
	}

	if(joia_ID == ITEMGET(14,13)) // jewel of bless
	{
	}
	else if(joia_ID >= ITEMGET(14,68) && joia_ID <= ITEMGET(14,81) ) // jewel
	{
	}

	else
	{
		_asm
		{
			mov edi, 0x0061921E
				jmp edi
		}
	}

	_asm // função de inserir na jewel
	{
		MOV EDI, 0x0061925F
			JMP EDI
	}
}

__declspec(naked) void gObjItemInsertTwo()
{
	_asm
	{
		mov joia_ID, edx
	}

	switch(joia_ID)
	{
	case ITEMGET(14,16): // jewel of life
		break;
	case ITEMGET(14,68): // jewel
		break;
	case ITEMGET(14,69): // jewel
		break;
	case ITEMGET(14,70): // jewel
		break;
	case ITEMGET(14,71): // jewel
		break;
	case ITEMGET(14,72): // jewel
		break;
	case ITEMGET(14,73): // jewel
		break;
	case ITEMGET(14,74): // jewel
		break;
	case ITEMGET(14,75): // jewel
		break;
	case ITEMGET(14,76): //jewel
		break;
	case ITEMGET(14,80): //jewel
		break;

	default: // caso não ache a joia volta para a função original
		_asm
		{
			mov edx,dword ptr ds:[0x79C29C8] // fix
			mov eax, 0x0062F940
				jmp eax
		}
		break;
	}

	_asm // função de inserir na jewel
	{
		mov eax, 0x0062F959
			jmp eax
	}
}

__declspec(naked) void gObjItemColorDrop()
{
	_asm
	{
		mov item_ID, ax
	}

	if(item_ID == ITEM_GET(14,13)) // jewel of bless
	{
		RR = 1.000000f;
		GG = 0.800000f;
		BB = 0.100000f;
	}	
	else if(joia_ID == ITEMGET(14,68) && joia_ID == ITEMGET(14,84))
	{
		RR = 1.000000f;
		GG = 0.800000f;
		BB = 0.100000f;
	}
	//adicionar cores dos novos items drops
	else
	{
		_asm // retornar para a função original
		{
			mov edx, 0x00606456
				jmp edx
		}
	}

	_asm // função das cores
	{
		mov edx,dword ptr ds:[0x5841E44]
		mov eax,dword ptr ds:[0x5841DD8]
		push edx
			push eax
			call ebx
			push BB
			push GG
			push RR
			call dword ptr ds:[0x78337C]
		mov edx, 0x006075B2
			jmp edx
	}
}

__declspec(naked) void gObjItemNoDrop()
{
	_asm
	{
		mov item_ID, ax
	}
	if(item_ID == ITEMGET(14,16)) // jewel of life
	{
	}
	else if(joia_ID >= ITEMGET(14,68) && joia_ID <= ITEMGET(14,81)) // jewel
	{
	}
	else if(joia_ID >= ITEMGET(12,36) && joia_ID <= ITEMGET(12,66))
	{
	}
	else
	{
		_asm // retorna para a função original
		{
			mov ebx, 0x006307D2
				jmp ebx
		}
	}

	_asm // função de não dropar
	{
		mov ebx, 0x00630895
			jmp ebx
	}
}

__declspec(naked) void gObjItemClick()
{

	_asm
	{
		mov joia_ID, eax
	}

	switch(joia_ID)
	{
	case ITEMGET(12,35): // scroll fire scream
		break;
	case ITEMGET(14,77): // jewel cash
		break;
	case ITEMGET(14,78): // jewel gold
		break;
	case ITEMGET(14,79): // jewel reset
		break;
	case ITEMGET(14,81): // jewel event
		break;
	default: // caso não ache a joia volta para a função original
		_asm
		{
			mov ecx, 0x00615462
				jmp ecx
		}
		break;
	}

	_asm // função de inserir na jewel
	{
		mov ecx, 0x00616A90
			jmp ecx
	}
}

DWORD	dwItemShineEffect_Pointer;
DWORD	dwItemShineEffect_Level;
bool	bItemShineEffect_Set;
__declspec(naked) void cItemShineEffect()
{
	bItemShineEffect_Set = false;
	dwItemShineEffect_Level = 0;
	// ----
	_asm
	{
		mov dwItemShineEffect_Pointer, ecx
	}
	// ----
	if( dwItemShineEffect_Pointer >= ITEM_GET(14, 68) && dwItemShineEffect_Pointer <= ITEM_GET(14, 84))
	{
		bItemShineEffect_Set = true;
		dwItemShineEffect_Level = 13;
	}
	else if( dwItemShineEffect_Pointer >= ITEM_GET(12, 36) && dwItemShineEffect_Pointer <= ITEM_GET(12, 51))
	{
		bItemShineEffect_Set = true;
		dwItemShineEffect_Level = 0;
	}

	else if( dwItemShineEffect_Pointer >= ITEM_GET(15, 22) && dwItemShineEffect_Pointer <= ITEM_GET(15, 31))
	{
		bItemShineEffect_Set = true;
		dwItemShineEffect_Level = 13;
	}

	if( bItemShineEffect_Set == true )
	{
		_asm
		{
			mov eax, dwItemShineEffect_Level
			mov dword ptr ss:[ebp-8], eax
			mov esi, 0x00679E86
			jmp esi
		}
	}
	// ----
	_asm
	{
		mov esi, 0x00679BBE
		jmp esi
	}
}

void LoadJewels()
{

	//===================================================================================
	//Item Shine Effect
	//===================================================================================
	SetRange((LPVOID)0x00679A24, 6, ASM::NOP);
	SetJg((LPVOID)0x00679A24, cItemShineEffect);

	//===================================================================================
	//novas joias cores
	//===================================================================================
	hook_extended(0x005FD935,                (DWORD)(&gObjItemColorInventory));
	func_nop(0x005FD935+5, 5);

	//===================================================================================
	//novas joias informações
	//===================================================================================
	hook_extended(0x006010AC,                (DWORD)(&gObjItemInformation));
	func_nop(0x006010AC+5, 55);

	//===================================================================================
	//novas joias inserir no item 01
	//===================================================================================
	hook_extended(0x00619217,                (DWORD)(&gObjItemInsertOne));
	func_nop(0x00619217+5, 2);

	//===================================================================================
	//novas joias inserir no item 02
	//===================================================================================
	hook_extended(0x0062F939,                (DWORD)(&gObjItemInsertTwo));
	func_nop(0x0062F939+5, 2);

	//===================================================================================
	//novas joias cor
	//===================================================================================
	hook_extended(0x0060644C,                (DWORD)(&gObjItemColorDrop));
	func_nop(0x0060644C+5, 5);

	//===================================================================================
	//novas joias dropar
	//===================================================================================
	hook_extended(0x006307C8,                (DWORD)(&gObjItemNoDrop));
	func_nop(0x006307C8+5, 5);

	//===================================================================================
	//click
	//===================================================================================
	hook_extended(0x00615458,                (DWORD)(&gObjItemClick));
	func_nop(0x00615458+5, 5);
}
