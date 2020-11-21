#include "stdafx.h"

__declspec(naked) void get_durability()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP+0xC],0x0E
			JNZ ITEM_15
			MOV ECX,DWORD PTR SS:[EBP+8]
		IMUL ECX,ECX,0x6C
			XOR EDX,EDX
			MOV DL,BYTE PTR DS:[ECX+0x9DD3228]
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		LEA ECX,DWORD PTR DS:[EDX+EAX*2+7]
		MOV DWORD PTR SS:[EBP-4],ECX
			JMP LOCAL
ITEM_15:
		CMP DWORD PTR SS:[EBP+0xC],0x0F
			JNZ RETURN
			MOV ECX,DWORD PTR SS:[EBP+8]
		IMUL ECX,ECX,0x6C
			XOR EDX,EDX
			MOV DL,BYTE PTR DS:[ECX+0x9DD3228]
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		LEA ECX,DWORD PTR DS:[EDX+EAX*2+8]
		MOV DWORD PTR SS:[EBP-4],ECX
			JMP LOCAL
LOCAL:
		MOV EDI, 0x0051636A
			JMP EDI
RETURN:
		MOV EAX,DWORD PTR SS:[EBP+8]
		IMUL EAX,EAX,0x6C
			XOR ECX,ECX
			MOV CL,BYTE PTR DS:[EAX+0x9DD3228]
		MOV EDX,DWORD PTR SS:[EBP+0xC]
		LEA EAX,DWORD PTR DS:[ECX+EDX*2-4]
		MOV DWORD PTR SS:[EBP-4],EAX
			MOV EDI, 0x0051636A
			JMP EDI
	}
}

void iniciar_correcoes()
{
	//----------  ProtocolCore (Socket Serial Error)
	SetJMP(0x0042FD6D);

	//----------  gObjCheckSerial0ItemList (Serial 0 Error)
	SetJMP(0x005085B0);
	SetNop(0x005085B2,10);

	//---------- Remove GgSrvDll.dll e GgAuth.dll
	*(BYTE*)(0x00523A54) = 0xEB;

	//----------- item + 14 & + 15
	*(BYTE*)(0x00429454+2) = 0x0F;
	*(BYTE*)(0x004D2DDE+2) = 0x0F;
	hook_proc(0x00516352, (DWORD)(&get_durability));
	iniciar_nopear(0x00516352+5,19);

	//----------- move gate
	*(BYTE*) (0x004FBEF7)    = 0xEB;
	*(BYTE*) (0x004FC458+6)  = 0x01;

	//----------- error-L10
	*(BYTE*) (0x0048A0C0)    = 0xC3;

	//----------- nick : webzen sem autoridade
	*(BYTE*) (0x004D537C+6)  = 0x01; 
	*(BYTE*) (0x004D53BD+6)  = 0x01; 
	*(BYTE*) (0x004D5425+6)  = 0x01; 

	//----------- potions 255
	*(BYTE*) (0x0042970F)    = 0xEB; 
	*(BYTE*) (0x004D304C)    = 0xEB; 
	*(BYTE*) (0x004D302F)    = 0xEB; 
	*(BYTE*) (0x004D30D1)    = 0xEB; 
	*(BYTE*) (0x004D3080)    = 0xEB; 
	*(BYTE*) (0x004D309D)    = 0xEB; 
	*(BYTE*) (0x004D30EE)    = 0xEB;

	//----------- corvo e cavalo bau crash
	*(BYTE*) (0x0042BE36+2)  = 0x00;
	*(BYTE*) (0x0042BE36+3)  = 0x00;
	*(BYTE*) (0x0042BE58+1)  = 0x00;
	*(BYTE*) (0x0042BE58+2)  = 0x00;

	//----------- checar serial 0
	*(BYTE*) (0x00508642)    = 0x90;
	*(BYTE*) (0x00508642+1)  = 0x90;
	*(BYTE*) (0x00508776)    = 0x90;
	*(BYTE*) (0x00508776+1)  = 0x90;

	//----------- pk item drop
	*(BYTE*) (0x004B638A)    = 0xEB;
	*(BYTE*) (0x004B665C)    = 0xEB;
	*(BYTE*) (0x004B6687)    = 0xEB;

	//----------- reload em connectserver
	*(BYTE*) (0x005920DF)    = 0x60;

	//----------- game master locomover pelo M
	*(BYTE*) (0x0051B714+2)  = 0x64;

	//----------- pk count limite retirado
	iniciar_nopear(0x004DE272, 15);

	//----------- anciet options + full
	*(BYTE*) (0x0050E556)    = 0xEB;
	*(BYTE*) (0x005735DB)    = 0xEB;
	SetNop(0x004294B8,2);    //
	SetNop(0x00514EA4,2);    // - JOL
	SetByte(0x004FF1E7,0x7); // - +28
	SetByte(0x004D2E85,0x7); //

	//----------- gameserver unico dataserver fix
	iniciar_nopear(0x0052D77B, 20); 
	iniciar_nopear(0x0052D7A3, 10);
	iniciar_nopear(0x0052D7D2, 10); 
	*(BYTE*)(0x006C5CB9+3) = 0x00;
	*(BYTE*)(0x006C5CB9+4) = 0x00;
	*(BYTE*)(0x006C5CB9+5) = 0x00;
	*(BYTE*)(0x006C5CB9+6) = 0x00;
	*(BYTE*)(0x006C5CB9+7) = 0x00;
	*(BYTE*)(0x006C5CC1)   = 0x00;	
	iniciar_nopear(0x0052D827, 10);
	iniciar_nopear(0x0052D848, 62);
	iniciar_nopear(0x004240C6, 230);
	*(BYTE*)(0x0042400A+2) = 0x9C;
	*(BYTE*)(0x0042400A+3) = 0x01;
	iniciar_nopear(0x004242CF, 9);
	iniciar_nopear(0x004242EE, 20);

	//----------- nao salva o personagem na database quando subir o level
	iniciar_nopear(0x004DC861, 5);

	//----------- party zen
	BYTE party_zen[] = {
	0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8, 0x02,0x74,0x05,0x83,0xF8,0x03,
	0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55, 0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
	0xC8,0x18,0x6E,0x00,0xE8,0x1C,0x55,0x0B,0x00,0x8B, 0x4D,0x0C,0x89,0x81,0xB4,0x00,
	0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3} ;
	memcpy((int*)(0x004E3437),party_zen,sizeof(party_zen));

	//----------- party zen devilsquare
	BYTE party_zen_square[] = {
	0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8,0x02,0x74,0x05,0x83,0xF8,0x03,
	0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55,0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
	0xC8,0x18,0x6E,0x00,0xE8,0x05,0x29,0x13,0x00,0x8B,0x4D,0x0C,0x89,0x81,0xB4,0x00,
	0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC2,0x10,0x00} ;
	memcpy((int*)(0x0046604E),party_zen_square,sizeof(party_zen_square));

	//----------- disconnects &
	iniciar_nopear(0x0048AC47, 5);
	iniciar_nopear(0x0048C11C, 5);
	iniciar_nopear(0x0048C1BF, 5);
	iniciar_nopear(0x0048C2E8, 5);
	//sp2
	*(BYTE*)(0x0048AA9E) = 0xEB;

	//----------- cliente hack check
	*(BYTE*)(0x00433E50) = 0xC3;

	//----------- cliente speed hack
	*(BYTE*)(0x0043192F) = 0xEB;

	//----------- cashshop aceitar item full, original com numero de options
	iniciar_nopear(0x0058622B, 8);
	*(BYTE*)(0x00586246+2) = 0xC0;
	iniciar_nopear(0x00586249, 56);

	//----------- elf mover em level baixo automatico
	*(BYTE*)(0x004DA4B3) = 0xEB;

	//Dragon invasion
	BYTE invasion01[] = {0xEB, 0x47, 0x90};
	memcpy((int*)(0x0046C214),invasion01,sizeof(invasion01));
	BYTE invasion02[] = {0x83, 0xC4, 0x08, 0x50, 0xE8, 0x2C, 0x7F, 0xF9, 0xFF, 0xEB, 0xAF};
	memcpy((int*)(0x0046C25D),invasion02,sizeof(invasion02));
	//Golden Invasion
	BYTE FixInvMsg1[3]={0xEB,0x49,0x90}; 
	memcpy ((int *) (0x46C214), &FixInvMsg1[0], 3 ) ; 
	BYTE FixInvMsg2[11]={0x83,0xC4,0x08,0x50,0xE8,0x2A,0x7F,0xF9,0xFF,0xEB,0xAD}; 
	memcpy ((int *) (0x46C25F), &FixInvMsg2[0], 11 ) ; 
	return; 

	//POP EDI crash fix party
	*(BYTE*)(0x004E2E0B+1) = 0x59;

	//error l2
	*(BYTE*)(0x0048BF3B)   = 0xEB;
	*(BYTE*)(0x0048BF3B+1) = 0x2A;
	*(BYTE*)(0x0048BF3B+2) = 0x90;

	//error invalid socket
	*(BYTE*)(0x0048CBB8)   = 0xEB;
	*(BYTE*)(0x0048CBB8+1) = 0x10;
	*(BYTE*)(0x0048CBB8+2) = 0x90;

	*(BYTE*)(0x0048CCD1)   = 0xEB;
	*(BYTE*)(0x0048CCD1+1) = 0x1E;
	*(BYTE*)(0x0048CCD1+2) = 0x90;

	//personal shop reset
	*(BYTE*)(0x004D4F49)   = 0xE9;
	*(BYTE*)(0x004D4F49+1) = 0x9C;
	*(BYTE*)(0x004D4F49+2) = 0x02;
	*(BYTE*)(0x004D4F49+3) = 0x00;
	*(BYTE*)(0x004D4F49+5) = 0x90;

	// - Protocol Error
	SetNop(0x44AA60,27);
	SetNop(0x449F20,27);

	//-- Fixes Disconnects
	SetNop(0x0048AC47, 5);
	SetNop(0x0048C11C, 5);
	SetNop(0x0048C1BF, 5);
	SetNop(0x0048C2E8, 5);

	//-- PK ITEM DROP FIX 

	*(BYTE*)(0x004DECD0+0) = 0xE9;
	*(BYTE*)(0x004DECD0+1) = 0x1D;
	*(BYTE*)(0x004DECD0+2) = 0x02;
	*(BYTE*)(0x004DECD0+3) = 0x00;
	*(BYTE*)(0x004DECD0+4) = 0x00;
	*(BYTE*)(0x004DECD0+5) = 0x90;

	WriteMemoryInt(0x00421E79+3,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::GetPosition
	WriteMemoryInt(0x00421E79+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::GetPosition
	WriteMemoryInt(0x004226B8+6,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase
	WriteMemoryInt(0x004226B8+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase
	WriteMemoryInt(0x00422894+6,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase
	WriteMemoryInt(0x00422894+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase
	WriteMemoryInt(0x004233FB+6,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase, int iSize
	WriteMemoryInt(0x004233FB+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase, int iSize
	WriteMemoryInt(0x004235F6+6,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase, int iSize
	WriteMemoryInt(0x004235F6+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // CMonsterSetBase::LoadSetBase, int iSize
	WriteMemoryInt(0x004D85A3+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddMonster
	WriteMemoryInt(0x004D85A3+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddMonster
	WriteMemoryInt(0x004D85C8+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddMonster
	WriteMemoryInt(0x004D85C8+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddMonster
	WriteMemoryInt(0x004D85E1+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddMonster
	WriteMemoryInt(0x004D85E1+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddMonster
	WriteMemoryInt(0x004D86F3+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddCallMon
	WriteMemoryInt(0x004D86F3+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddCallMon
	WriteMemoryInt(0x004D8715+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddCallMon
	WriteMemoryInt(0x004D8715+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjAddCallMon
	WriteMemoryInt(0x004D0435+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjInit
	WriteMemoryInt(0x004D8715+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjInit
	WriteMemoryInt(0x004D6B03+3,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // gObjSetPosMonster
	WriteMemoryInt(0x004D6B03+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 1 // gObjSetPosMonster
	//REVER DEPOIS :: NÃO ATACA OS BICHOS COM MAGIA
	//WriteMemoryInt(0x004F1E25+3,      0xEF, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjViewportListCreate
	//WriteMemoryInt(0x004F1E25+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // gObjViewportListCreate
	WriteMemoryInt(0x0056A7AD+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::SetState_START
	WriteMemoryInt(0x0056A7AD+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::SetState_START
	WriteMemoryInt(0x0056A9C6+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::SetState_END
	WriteMemoryInt(0x0056A9C6+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::SetState_END
	WriteMemoryInt(0x0056B195+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::procState_START
	WriteMemoryInt(0x0056B195+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::procState_START
	WriteMemoryInt(0x0056B761+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::NotifyCrywolfBossMonsterInfo
	WriteMemoryInt(0x0056B761+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::NotifyCrywolfBossMonsterInfo
	WriteMemoryInt(0x0056C62C+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::CalcGettingScore
	WriteMemoryInt(0x0056C62C+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CCrywolf::CalcGettingScore
	WriteMemoryInt(0x005226AB+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // GameMonsterAllCloseAndReLoad
	WriteMemoryInt(0x005226AB+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // GameMonsterAllCloseAndReLoad
	WriteMemoryInt(0x00534924+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::ClearMonster
	WriteMemoryInt(0x00534924+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::ClearMonster
	WriteMemoryInt(0x00536B23+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::SendCastleEntranceBlockInfo
	WriteMemoryInt(0x00536B23+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::SendCastleEntranceBlockInfo
	WriteMemoryInt(0x00536D13+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::SendCastleBridgeBlockInfo
	WriteMemoryInt(0x00536D13+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::SendCastleBridgeBlockInfo
	WriteMemoryInt(0x00537023+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::SendCastleDoorBlockInfo
	WriteMemoryInt(0x00537023+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CBloodCastle::SendCastleDoorBlockInfo
	WriteMemoryInt(0x0046ABFE+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CAttackEvent::Active
	WriteMemoryInt(0x0046ABFE+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CAttackEvent::Active
	WriteMemoryInt(0x0046A51E+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CDragonEvent::DragonActive
	WriteMemoryInt(0x0046A51E+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CDragonEvent::DragonActive
	WriteMemoryInt(0x0053FE1C+6,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CChaosCastle::pullObjInnerPlace
	WriteMemoryInt(0x0053FE1C+7,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CChaosCastle::pullObjInnerPlace
	WriteMemoryInt(0x00541071+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CChaosCastle::ClearMonster
	WriteMemoryInt(0x00541071+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CChaosCastle::ClearMonster
	WriteMemoryInt(0x00545CCC+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CChaosCastle::CheckMonsterInDieTile
	WriteMemoryInt(0x00545CCC+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CChaosCastle::CheckMonsterInDieTile
	WriteMemoryInt(0x004650AE+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CDevilSquare::ClearMonstr
	WriteMemoryInt(0x004650AE+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CDevilSquare::ClearMonstr
	WriteMemoryInt(0x0046B7D3+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenGoldGoblen
	WriteMemoryInt(0x0046B7D3+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenGoldGoblen
	WriteMemoryInt(0x0046BA65+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenTitan
	WriteMemoryInt(0x0046BA65+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenTitan
	WriteMemoryInt(0x0046BF6E+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenGoldDercon
	WriteMemoryInt(0x0046BF6E+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenGoldDercon
	WriteMemoryInt(0x0046C355+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenDevilLizardKing
	WriteMemoryInt(0x0046C355+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenDevilLizardKing
	WriteMemoryInt(0x0046C825+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenKantur
	WriteMemoryInt(0x0046C825+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // CEledoradoEvent::RegenKantur
	WriteMemoryInt(0x0055A970+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // TMonsterAI::MonsterAIProc
	WriteMemoryInt(0x0055A970+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // TMonsterAI::MonsterAIProc    
	WriteMemoryInt(0x0055B07B+3,      0xF0, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // TMonsterAI::MonsterMoveProc
	WriteMemoryInt(0x0055B07B+4,      0x23, 255, 1); // LIMITE DE MONSTROS :: MAXIMO 9200 - 0 // TMonsterAI::MonsterMoveProc


	//========================================================================================
	// -- Fix Mana Shield Config   
	//========================================================================================
	BYTE ManaShieldCommonFix[18] = {
	0xEB, 0x68, 0x90, 0x83, 0xF8, 0x32, 0x7E, 0x05, 0xB8, 0x32, 0x00, 0x00, 0x00, 0x8B,0x4D, 0xF0,
	0xEB, 0x8A };                          
	memcpy((int *) (0x4B9E16), &ManaShieldCommonFix[0], 3 ) ;
	memcpy((int *) (0x4B9E80), &ManaShieldCommonFix[3], 15 ) ;

	// --------------------------------------------------
	// - [Fix] Game working response (OfflineTrade)	
	// --------------------------------------------------
	SetNop(0x0048CBC8,2);
	SetByte(0x0048CCE1,0xEB);
	SetByte(0x004F5B9A,0xEB); 
	
	// --------------------------------------------------
	// - gObjGuildWarCheck
	// --------------------------------------------------
	*(DWORD*)(0x500493+1) = 50000;
}

BOOL _gObjSetCharacter(LPBYTE lpdata, int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	BOOL retornar = gObjSetCharacter(lpdata,lpObj->m_Index);

	PMSG_USE_STAT_FRUIT pCase;

	if(iniciar_dll.iniciar_reset == 1)
	{
		int reset = _subC.subCSQL_retornar(lpObj->Name,_subC.subCSQLcoluna_retornar_r,_subC.subCSQLtabela_r,_subC.subCSQLcoluna_id_r,lpObj->reset,"*");

		if(reset > iniciar_dll.iniciar_resetq)
		{
			GCServerMsgStringSend("você ultrapassou o limite de resets para entrar no servidor",lpObj->m_Index,0);
			lpObj->CloseType  = 2;
			lpObj->CloseCount = 1;
		}
	}

	if( (lpObj->Authority & 2) == 2 || (lpObj->Authority & 10) == 10 || (lpObj->Authority & 32) == 32)
	{
		lpObj->m_ViewSkillState |= 0x1000000;
		GCStateInfoSend(lpObj, 1, lpObj->m_ViewSkillState);
	}

	if(retornar == TRUE)
	{
		PMSG_CHARINFOMAIN Result;

		Result.h.c = 0xC1;
		Result.h.size = sizeof(Result);
		Result.h.headcode = 0xFE;
		Result.Code = 0x07;
		Result.Class = lpObj->Class;
		Result.Dexterity = (WORD)(lpObj->Dexterity);
		Result.AttackSpeed = (WORD)(lpObj->m_AttackSpeed);
		Result.MagicSpeed = (WORD)(lpObj->m_MagicSpeed);

		DataSend(aIndex, (LPBYTE)(&Result), Result.h.size);
	}

	return retornar;
}

void gObjLotteryItemMix(OBJECTSTRUCT* lpObj) 
{ 
	for(int i = 0; i < 32; i++) 
	{ 
		if(lpObj->pChaosBox[i].m_Type == ITEMGET(14, 54)) 
		{ 
			LotteryItemMix(lpObj); 
			return;
		}
	} 
}

__declspec(naked) void CheckZenMonster()
{
	__asm 
	{
		MOV ECX, DWORD PTR SS:[EBP+0xC];
		CMP WORD PTR DS:[ECX+0x60], 2;
		JNZ IsNotZero;
		MOV EDX, DWORD PTR DS:[ECX+0xAC];
		MOV EDI, 0x59897C;
		MOV DWORD PTR SS:[EBP-0x8], EDX;
		FILD DWORD PTR SS:[EBP-0x8];
		FMUL DWORD PTR DS:[0x6E18C8];
		CALL EDI;
		MOV ECX,DWORD PTR SS:[EBP+0xC];
		MOV DWORD PTR DS:[ECX+0xAC], EAX;
IsNotZero:
		POP EDI;
		POP ESI;
		POP EBX;
		MOV ESP, EBP;
		POP EBP;
		RETN;
	}
}


void FixSkillsNoWeapor(LPBYTE aRecv, int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	if(lpObj->Class == 1 || lpObj->Class == 3)
	{
		if(lpObj->HaveWeaponInHand == FALSE && aRecv[3] == 0x29)
		{
			GCServerMsgStringSend("Você não pode usar a Skill sem arma.",aIndex,1);
			aRecv[3] = 0xFF;
		}
		else
		{
			CGDurationMagicRecv(aRecv,aIndex);
		}
	}
}
