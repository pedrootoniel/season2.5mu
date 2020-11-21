#include "stdafx.h"

void iniciar_nopear(DWORD off, int quantidade)
{
	for(int i = 0; i < quantidade; i++)
	{
		*(BYTE*)  (off+i)   = 0x90;
	}
}

__declspec(naked) void get_durability()
{
	_asm
	{
		CMP DWORD PTR SS:[EBP+0xC],0x0E
		JNZ ITEM_15
		MOV ECX,DWORD PTR SS:[EBP+8]
		IMUL ECX,ECX,0x6C
		XOR EDX,EDX
		MOV DL,BYTE PTR DS:[ECX+0x5C20308]
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
		MOV DL,BYTE PTR DS:[ECX+0x5C20308]
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		LEA ECX,DWORD PTR DS:[EDX+EAX*2+8]
		MOV DWORD PTR SS:[EBP-4],ECX
		JMP LOCAL
LOCAL:
		MOV EDI, 0x0052978A
		JMP EDI
RETURN:
		MOV EAX,DWORD PTR SS:[EBP+8]
		IMUL EAX,EAX,0x6C
		XOR ECX,ECX
		MOV CL,BYTE PTR DS:[EAX+0x5C20308]
		MOV EDX,DWORD PTR SS:[EBP+0xC]
		LEA EAX,DWORD PTR DS:[ECX+EDX*2-4]
		MOV DWORD PTR SS:[EBP-4],EAX
		MOV EDI, 0x0052978A
		JMP EDI
	}
}

void iniciar_correcoes()
{
	//----------- gObjCheckSerial0ItemList (Serial 0 Error)
	SetJMP(0x0051B9D0);
	SetNop(0x0051B9D2,10);

	//----------- ProtocolCore (Socket Serial Error)
	SetJMP(0x00432D0D);

	//----------- Remove mensage Box Erro Data Castle Siege
	SetNop(0x004B5D16,6);

	//----------- Fix Summon
	*(BYTE*)(0x004CF3B0)   = 0xEB;
	
	//----------- Remove GgSrvDll.dll e GgAuth.dll
	*(BYTE*)(0x00536FB4) = 0xEB;

	//----------- item + 14 & + 15
    *(BYTE*)(0x0042ADB4+2) = 0x0F;
	*(BYTE*)(0x004E468E+2) = 0x0F;
	hook_proc(0x00529772, (DWORD)(&get_durability));
	iniciar_nopear(0x00529772+5,19);

	//----------- error-L10
	*(BYTE*) (0x0049AE90)    = 0xC3;

	//----------- nick : webzen sem autoridade
	*(BYTE*) (0x004E6D83+6)  = 0x01; 
	*(BYTE*) (0x004E6DC4+6)  = 0x01; 
	*(BYTE*) (0x004E6E2C+6)  = 0x01; 

	//----------- potions 255
	*(BYTE*) (0x0042B06F)    = 0xEB; 
	*(BYTE*) (0x004E48FC)    = 0xEB; 
	*(BYTE*) (0x004E48DF)    = 0xEB; 
	*(BYTE*) (0x004E4981)    = 0xEB; 
	*(BYTE*) (0x004E4930)    = 0xEB; 
	*(BYTE*) (0x004E494D)    = 0xEB; 
	*(BYTE*) (0x004E499E)    = 0xEB;

	//----------- corvo e cavalo bau crash
    *(BYTE*) (0x0042D796+2)  = 0x00;
	*(BYTE*) (0x0042D796+3)  = 0x00;
	*(BYTE*) (0x0042D7B8+1)  = 0x00;
	*(BYTE*) (0x0042D7B8+2)  = 0x00;

	//----------- checar serial 0
	*(BYTE*) (0x0051BA62)    = 0x90;
	*(BYTE*) (0x0051BA62+1)  = 0x90;
	*(BYTE*) (0x0051BB96)    = 0x90;
	*(BYTE*) (0x0051BB96+1)  = 0x90;

	//----------- pk item drop
	*(BYTE*) (0x004C7BDA)    = 0xEB;
	*(BYTE*) (0x004C7EAC)    = 0xEB;
	*(BYTE*) (0x004C7ED7)    = 0xEB;

	//----------- reload em connectserver
	*(BYTE*) (0x005C58CE)    = 0x60;

	//----------- game master locomover pelo M
	*(BYTE*) (0x0052EA0D+2)  = 0x64;

	//----------- pk count limite retirado
	iniciar_nopear(0x004F03C4, 15);

	//----------- anciet options + full
	*(BYTE*) (0x00521976)    = 0xEB;
	*(BYTE*) (0x005A964B)    = 0xEB;

	//----------- gameserver unico dataserver fix
	//----------- memset(dataserverip2, 0, sizeof(dataserverip2));
	iniciar_nopear(0x00540B8B, 20);
	//----------- dataserverport2 = 0;
	iniciar_nopear(0x00540BB3, 10);
	//----------- dataserverip, &dataserverport
	iniciar_nopear(0x00540BE2, 10);
	//----------- %s %d %s %d %d %s %d %s %d
	*(BYTE*)(0x00718571+3) = 0x00;
	*(BYTE*)(0x00718571+4) = 0x00;
	*(BYTE*)(0x00718571+5) = 0x00;
	*(BYTE*)(0x00718571+6) = 0x00;
	*(BYTE*)(0x00718571+7) = 0x00;
	*(BYTE*)(0x0071857A)   = 0x00;
	//----------- dataserverport2 = 55962;
	iniciar_nopear(0x00540C37, 10);
	//----------- if(dataserverip2[0] == 0)
    //----------- memcpy(dataserverip2, DataServerIp, sizeof(dataserverip2));
	//----------- if(dataserverip2 == 0)
	//----------- dataserverip2 = 55962;
	iniciar_nopear(0x00540C58, 62);
	//----------- void DBSockMng::Connect()
	//----------- segundo dataserver
	iniciar_nopear(0x00425A26, 230);
	//----------- JNZ alterar para JNZ do MOV ECX,offset antes do ExDB Server Check..
	*(BYTE*)(0x0042596A+2) = 0x9C;
	*(BYTE*)(0x0042596A+3) = 0x01;
    //----------- dataserver standy by test
    iniciar_nopear(0x00425C2F, 9);
	iniciar_nopear(0x00425C4E, 20);

	//----------- nao salva o personagem na database quando subir o level
    iniciar_nopear(0x004EE881, 5);

	//----------- party zen
    BYTE party_zen[] = {
    0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8, 0x02,0x74,0x05,0x83,0xF8,0x03,
    0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55, 0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
    0xC8,0x18,0x6E,0x00,0xE8,0x1C,0x55,0x0B,0x00,0x8B, 0x4D,0x0C,0x89,0x81,0xB4,0x00,
    0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3} ;
	memcpy((int*)(0x004F5647),party_zen,sizeof(party_zen));

	//----------- party zen devilsquare
    BYTE party_zen_square[] = {
    0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8,0x02,0x74,0x05,0x83,0xF8,0x03,
    0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55,0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
    0xC8,0x18,0x6E,0x00,0xE8,0x05,0x29,0x13,0x00,0x8B,0x4D,0x0C,0x89,0x81,0xB4,0x00,
    0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC2,0x10,0x00} ;
	memcpy((int*)(0x0046BB8E),party_zen_square,sizeof(party_zen_square));

	//----------- disconnects &
	iniciar_nopear(0x0049BA17, 5);
	iniciar_nopear(0x0049CEEC, 5);
	iniciar_nopear(0x0049CF8F, 5);
	iniciar_nopear(0x0049D0B8, 5);
	//sp2
	*(BYTE*)(0x0049B86E) = 0xEB;

	//----------- cliente hack check
	*(BYTE*)(0x00436E10) = 0xC3;

	//----------- cliente speed hack
	*(BYTE*)(0x004348EF) = 0xEB;

	//----------- cashshop aceitar item full, original com numero de options
	//BYTE btExOptionValue = 0;
	//BYTE btExOption = 0;
	//nopear
	iniciar_nopear(0x005B9A1B, 8);
	//altera btItemExOption = TokenNumber;
	//para ItemStatus.btExOption = TokenNumber;
	*(BYTE*)(0x005B9A36+2) = 0xC0;
	//nopear o resto da função
	iniciar_nopear(0x005B9A39, 56);

	//----------- elf mover em level baixo automatico
	*(BYTE*)(0x004EBF63) = 0xEB;
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

void _LotteryItemMix(OBJECTSTRUCT* lpObj) 
{ 
	for(int i = 0; i < 32; i++) 
	{ 
		if(lpObj->pChaosBox[i].m_Type == ITEMGET(14, 54)) 
		{ 
			LotteryItemMix(lpObj); 
			return;
		}
	} 

	_mensagem(lpObj->m_Index,11,0,0,0);
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

void iniciar_configuracoes()
{
	//----------- conectar noticia
	GetPrivateProfileString("settings","iniciar_notice[0]","mensagem não definida",iniciar_dll.iniciar_notice[0],255,".\\configurações\\_settings.ID");
	GetPrivateProfileString("settings","iniciar_notice[1]","mensagem não definida",iniciar_dll.iniciar_notice[1],255,".\\configurações\\_settings.ID");
	GetPrivateProfileString("settings","iniciar_notice[2]","mensagem não definida",iniciar_dll.iniciar_notice[2],255,".\\configurações\\_settings.ID");
	GetPrivateProfileString("settings","iniciar_notice[3]","mensagem não definida",iniciar_dll.iniciar_notice[3],255,".\\configurações\\_settings.ID");
	GetPrivateProfileString("settings","iniciar_notice[4]","mensagem não definida",iniciar_dll.iniciar_notice[4],255,".\\configurações\\_settings.ID");
	GetPrivateProfileString("settings","iniciar_notice[5]","mensagem não definida",iniciar_dll.iniciar_notice[5],255,".\\configurações\\_settings.ID");
	//----------- checksum
	iniciar_dll.iniciar_checksum = iniciar_dll.iniciar_getprivateint("settings","iniciar_checksum", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_checksum == 1)
	{
	  *(BYTE*) (0x00434B9A)  = 0xEB; 
	  *(BYTE*) (0x00434BF8)  = 0xEB;
	}
	//----------- buff de defesa da elf
	iniciar_dll.iniciar_elfbuffdef = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfbuffdef", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_elfbuffdef == 1)
	{
		iniciar_nopear(0x004CB9EB, 10);
	}
	//----------- buff de attack da elf
	iniciar_dll.iniciar_elfbuffatk = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfbuffatk", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_elfbuffatk == 1)
	{
		iniciar_nopear(0x004CBC7B, 10);
	}
	//----------- rate de soul sem luck
	iniciar_dll.iniciar_soulsl = iniciar_dll.iniciar_getprivateint("settings","iniciar_soulsl", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x00511DAB+3)  = iniciar_dll.iniciar_soulsl;
	//----------- rate de soul com luck
	iniciar_dll.iniciar_soulcl = iniciar_dll.iniciar_getprivateint("settings","iniciar_soulcl", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x00511CCC+3)  = iniciar_dll.iniciar_soulcl;
	//----------- rate de life
	iniciar_dll.iniciar_life = iniciar_dll.iniciar_getprivateint("settings","iniciar_life", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x0051253A+3)  = iniciar_dll.iniciar_life;
	//----------- deletar char sem personal ID
	iniciar_dll.iniciar_char_del = iniciar_dll.iniciar_getprivateint("settings","iniciar_char_del", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_char_del == 1)
	{
		*(BYTE*) (0x004374E4)    = 0xEB;
	}
	//----------- deletar guild sem personal ID
	iniciar_dll.iniciar_guild_del = iniciar_dll.iniciar_getprivateint("settings","iniciar_guild_del", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_guild_del == 1)
	{
		iniciar_nopear(0x004481CC, 6);
	    iniciar_nopear(0x0044837D, 2);
	}
	//----------- udp port
	iniciar_dll.iniciar_port = iniciar_dll.iniciar_getprivateint("settings","iniciar_port", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x005343CD+1)  = iniciar_dll.iniciar_port;
	//----------- tempo dos items
	iniciar_dll.iniciar_tempo = iniciar_dll.iniciar_getprivateint("settings","iniciar_tempo", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004A4812+1)   = iniciar_dll.iniciar_tempo * 1000;
	*(unsigned int*) (0x004A49C3+1)   = iniciar_dll.iniciar_tempo * 1000;
	//----------- chaos castle minimo de players
	iniciar_dll.iniciar_chaoscastle = iniciar_dll.iniciar_getprivateint("settings","iniciar_chaoscastle", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x00557970+3)  = iniciar_dll.iniciar_chaoscastle;
	//----------- guild aliança minimo de membros
	iniciar_dll.iniciar_alianca = iniciar_dll.iniciar_getprivateint("settings","iniciar_alianca", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x0045927B+2)  = iniciar_dll.iniciar_alianca;
	//----------- mix item + 10 até + 13 - mix wings & capa
    iniciar_dll.iniciar_mixitem0  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem1  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem2  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem3  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem4  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[4]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem5  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[5]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem6  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[6]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem7  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[7]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem8  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[8]", 0, ".\\configurações\\_settings.ID");

	iniciar_dll.iniciar_mixitem9  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[9]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem10  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[10]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem11  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[11]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem12  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[12]", 0, ".\\configurações\\_settings.ID");
	//----------- 
	*(BYTE*) (0x004A73F6+6)  = iniciar_dll.iniciar_mixitem0;
    *(BYTE*) (0x004A7421+6)  = iniciar_dll.iniciar_mixitem1;
	*(BYTE*) (0x004A744C+6)  = iniciar_dll.iniciar_mixitem2;
	*(BYTE*) (0x004A7477+6)  = iniciar_dll.iniciar_mixitem3;
	*(BYTE*) (0x004A74A6+2)  = iniciar_dll.iniciar_mixitem4;
	*(BYTE*) (0x004A74B5+6)  = iniciar_dll.iniciar_mixitem5;
	*(BYTE*) (0x004A74C1+6)  = iniciar_dll.iniciar_mixitem5;
	*(BYTE*) (0x004A8BC0+6)  = iniciar_dll.iniciar_mixitem6;
	*(BYTE*) (0x004A8BCC+6)  = iniciar_dll.iniciar_mixitem6;
	*(BYTE*) (0x004A9269+6)  = iniciar_dll.iniciar_mixitem7;
	*(BYTE*) (0x004A9275+6)  = iniciar_dll.iniciar_mixitem7;
	*(BYTE*) (0x004A8BE1+6)  = iniciar_dll.iniciar_mixitem8;
	*(BYTE*) (0x004A8BED+6)  = iniciar_dll.iniciar_mixitem8;
	//*(unsigned char*)(0x004AC597+3)	= iniciar_dll.iniciar_mixitem9;
	//*(unsigned char*)(0x004AC59D+3)	= iniciar_dll.iniciar_mixitem10;
	//*(unsigned char*)(0x004AC5A3+3)	= iniciar_dll.iniciar_mixitem11;
	//*(unsigned int*) (0x004AC643+3)	= iniciar_dll.iniciar_mixitem12;
	*(BYTE*) (0x004AC597+3)	= iniciar_dll.iniciar_mixitem9;
	*(BYTE*) (0x004AC59D+3)	= iniciar_dll.iniciar_mixitem10;
	*(BYTE*) (0x004AC5A3+3)	= iniciar_dll.iniciar_mixitem11;
	*(unsigned int*) (0x004AC643+3)	= iniciar_dll.iniciar_mixitem12;

	//----------- mana shield
	iniciar_dll.iniciar_manashield0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_manashield[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_manashield1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_manashield[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_manashield2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_manashield[2]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004CB7DB+1)  = iniciar_dll.iniciar_manashield0;
	*(unsigned int*) (0x004CB7FB+1)  = iniciar_dll.iniciar_manashield1;
	*(unsigned int*) (0x004CB826+1)  = iniciar_dll.iniciar_manashield2;
	//----------- great fortitude
	iniciar_dll.iniciar_great0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_great[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_great1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_great[1]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004CB3CF+1)  = iniciar_dll.iniciar_great0;
	*(unsigned int*) (0x004CB3EF+1)  = iniciar_dll.iniciar_great1;
	//----------- elf soldier
	iniciar_dll.iniciar_maxlevelsoldier = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfsoldier[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_buffdefense     = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfsoldier[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_buffattack      = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfsoldier[2]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x0058B0FF+1)  = iniciar_dll.iniciar_maxlevelsoldier;
	*(BYTE*)         (0x0058B142+2)  = iniciar_dll.iniciar_buffdefense;
	*(BYTE*)         (0x0058B160+2)  = iniciar_dll.iniciar_buffattack;
	//----------- party experiencia
	iniciar_dll.iniciar_expparty0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty3 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty4 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[4]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty5 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[5]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty6 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[6]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004F52C7+3)  = iniciar_dll.iniciar_expparty0;
	*(unsigned int*) (0x0046B836+3)  = iniciar_dll.iniciar_expparty0;
	*(unsigned int*) (0x004F52D6+3)  = iniciar_dll.iniciar_expparty1;
	*(unsigned int*) (0x0046B845+3)  = iniciar_dll.iniciar_expparty1;
	*(unsigned int*) (0x004F52E5+3)  = iniciar_dll.iniciar_expparty2;
	*(unsigned int*) (0x0046B854+3)  = iniciar_dll.iniciar_expparty2;
	*(unsigned int*) (0x004F52F4+3)  = iniciar_dll.iniciar_expparty3;
	*(unsigned int*) (0x0046B863+3)  = iniciar_dll.iniciar_expparty3;
	*(unsigned int*) (0x004F5291+3)  = iniciar_dll.iniciar_expparty4;
	*(unsigned int*) (0x0046B800+3)  = iniciar_dll.iniciar_expparty4;
	*(unsigned int*) (0x004F52A0+3)  = iniciar_dll.iniciar_expparty5;
	*(unsigned int*) (0x0046B80F+3)  = iniciar_dll.iniciar_expparty5;
	*(unsigned int*) (0x004F52AF+3)  = iniciar_dll.iniciar_expparty6;
	*(unsigned int*) (0x0046B81E+3)  = iniciar_dll.iniciar_expparty6;
	//----------- item drop
	iniciar_dll.iniciar_drop0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop3 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop4 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[4]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x0041CB68+1)  = iniciar_dll.iniciar_drop0;
	*(unsigned int*) (0x0041CEBC+6)  = iniciar_dll.iniciar_drop1;
	*(unsigned int*) (0x0041CEC6+6)  = iniciar_dll.iniciar_drop2;
	*(unsigned int*) (0x0041CF15+6)  = iniciar_dll.iniciar_drop3;
	*(unsigned int*) (0x0041CF1F+6)  = iniciar_dll.iniciar_drop4;
	//----------- skill level
	iniciar_dll.iniciar_skill0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill3 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill4 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[4]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x00494410+7)  = iniciar_dll.iniciar_skill0;
	*(unsigned int*) (0x00494429+7)  = iniciar_dll.iniciar_skill1;
	*(unsigned int*) (0x00494442+7)  = iniciar_dll.iniciar_skill2;
	*(unsigned int*) (0x00494474+7)  = iniciar_dll.iniciar_skill3;
	*(unsigned int*) (0x0049448D+7)  = iniciar_dll.iniciar_skill4;
	//----------- trade harmony
	iniciar_dll.iniciar_harmonytrade = iniciar_dll.iniciar_getprivateint("settings","iniciar_harmonytrade", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_harmonytrade == 1)
	{
	   *(BYTE*) (0x005ABB29)  = 0xEB;
	}
	//----------- zen drop
	iniciar_dll.iniciar_zendrop = iniciar_dll.iniciar_getprivateint("settings","iniciar_zendrop", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_zendrop == 1)
	{
	   *(BYTE*) (0x004A1330)  = 0xC3;
	}
	//----------- skill siege
	iniciar_dll.iniciar_skillsiege = iniciar_dll.iniciar_getprivateint("settings","iniciar_skillsiege", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_skillsiege == 1)
	{
	   *(BYTE*) (0x004D0E64)  = 0xEB;
	   *(BYTE*) (0x004D0E74)  = 0xEB;
	   *(BYTE*) (0x004D0F57)  = 0xEB;
	   *(BYTE*) (0x004D0F67)  = 0xEB;
	   *(BYTE*) (0x004D1074)  = 0xEB;
	   *(BYTE*) (0x004D1084)  = 0xEB;
	   *(BYTE*) (0x004D1157)  = 0xEB;
	   *(BYTE*) (0x004D1167)  = 0xEB;
	   *(BYTE*) (0x004D1274)  = 0xEB;
	   *(BYTE*) (0x004D1284)  = 0xEB;
	   *(BYTE*) (0x004D1364)  = 0xEB;
	   *(BYTE*) (0x004D1374)  = 0xEB;
	   *(BYTE*) (0x004D1447)  = 0xEB;
	   *(BYTE*) (0x004D1457)  = 0xEB;
	}
	//----------- balanço do reflete
	iniciar_dll.iniciar_balanco = iniciar_dll.iniciar_getprivateint("settings","iniciar_balanco", 0, ".\\configurações\\_settings.ID");
	//----------- camera 3D
	iniciar_dll.iniciar_camera = iniciar_dll.iniciar_getprivateint("settings","iniciar_camera", 0, ".\\configurações\\_settings.ID");
	//----------- shop PK
	iniciar_dll.iniciar_pkshop = iniciar_dll.iniciar_getprivateint("settings","iniciar_pkshop", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_pkshop == 1)
	{
		*(BYTE*) (0x0043EB69+2)  = 0x64;
	}
	//----------- reset minimos
	iniciar_dll.iniciar_reset  = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_resetq = iniciar_dll.iniciar_getprivateint("settings","iniciar_resetq",0, ".\\configurações\\_settings.ID");

	//================================================//
	// Nome da Barra do GS          		     	  //
	//================================================//
	char tmp[50];
	char dwTmp;
	char* GSname = (char*)(0x00711A00);
	dwTmp = GetPrivateProfileString("GameServerInfo","ServerName"," ]+[ PREMIUM ]+[ ",tmp,50,".\\Data\\ServerInfo.dat"); 
	memset(&GSname[0],0x00,50);
	memcpy(&GSname[0],tmp,50);

	//================================================//
	// Cor do Texto e Barra do GS   		     	  //
	//================================================//

	*(unsigned int*) (0x004BAD57+1)  = RGB (0,250,154);		// GSBarColor			
	*(unsigned int*) (0x004A9D17+1)  = RGB (255, 255, 255);	// GSBarTextColor		
	*(unsigned int*) (0x004A9758+1)  = RGB (255,0,0);		// GSBarDisconnectColor

	iniciar_dll.jewel_up01  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[01]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up02  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[02]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up03  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[03]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up04  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[04]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up05  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[05]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up06  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[06]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up07  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[07]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up08  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[08]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up09  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[09]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up10  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[10]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up11  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[11]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up12  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[12]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up13  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[13]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.jewel_up14  = iniciar_dll.iniciar_getprivateint("settings","iniciar_jewelup[14]", 0, ".\\configurações\\_settings.ID");
}

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);
		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);
		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}