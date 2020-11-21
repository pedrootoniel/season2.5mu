#include "stdafx.h"

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
	  *(BYTE*) (0x00431BDA)  = 0xEB; 
	  *(BYTE*) (0x00431C38)  = 0xEB;
	}
	//----------- buff de defesa da elf
	iniciar_dll.iniciar_elfbuffdef = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfbuffdef", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_elfbuffdef == 1)
	{
		iniciar_nopear(0x004B9FFB, 10);
	}
	//----------- buff de attack da elf
	iniciar_dll.iniciar_elfbuffatk = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfbuffatk", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_elfbuffatk == 1)
	{
		iniciar_nopear(0x004BA28B, 10);
	}
	//----------- rate de soul sem luck
	iniciar_dll.iniciar_soulsl = iniciar_dll.iniciar_getprivateint("settings","iniciar_soulsl", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x004FEA5B+3)  = iniciar_dll.iniciar_soulsl;
	//----------- rate de soul com luck
	iniciar_dll.iniciar_soulcl = iniciar_dll.iniciar_getprivateint("settings","iniciar_soulcl", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x004FE97C+3)  = iniciar_dll.iniciar_soulcl;
	//----------- rate de life
	iniciar_dll.iniciar_life = iniciar_dll.iniciar_getprivateint("settings","iniciar_life", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x004FF1EA+3)  = iniciar_dll.iniciar_life;
	//----------- deletar char sem personal ID
	iniciar_dll.iniciar_char_del = iniciar_dll.iniciar_getprivateint("settings","iniciar_char_del", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_char_del == 1)
	{
		*(BYTE*) (0x00434524)    = 0xEB;
	}
	//----------- deletar guild sem personal ID
	iniciar_dll.iniciar_guild_del = iniciar_dll.iniciar_getprivateint("settings","iniciar_guild_del", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_guild_del == 1)
	{
		iniciar_nopear(0x0044521A, 6);
	    iniciar_nopear(0x00445370, 2);
	}
	//----------- udp port
	iniciar_dll.iniciar_port = iniciar_dll.iniciar_getprivateint("settings","iniciar_port", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x0052112F+1)  = iniciar_dll.iniciar_port;
	//----------- tempo dos items
	iniciar_dll.iniciar_tempo = iniciar_dll.iniciar_getprivateint("settings","iniciar_tempo", 0, ".\\configurações\\_settings.ID");
		
	*(unsigned int*) (0x00493A42+1)   = iniciar_dll.iniciar_tempo * 1000;
	*(unsigned int*) (0x00493BF3+1)   = iniciar_dll.iniciar_tempo * 1000;
	//----------- chaos castle minimo de players
	iniciar_dll.iniciar_chaoscastle = iniciar_dll.iniciar_getprivateint("settings","iniciar_chaoscastle", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x005442F0+3)  = iniciar_dll.iniciar_chaoscastle;
	//----------- guild aliança minimo de membros
	iniciar_dll.iniciar_alianca = iniciar_dll.iniciar_getprivateint("settings","iniciar_alianca", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(BYTE*) (0x00457DEB+2)  = iniciar_dll.iniciar_alianca;
	//----------- mix item + 10 até + 13 
    iniciar_dll.iniciar_mixitem0  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem1  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem2  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem3  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem4  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[4]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem5  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[5]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem6  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[6]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem7  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[7]", 0, ".\\configurações\\_settings.ID");
	//------------ Adiciona Rate Luck
	iniciar_dll.iniciar_mixitem8  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[8]", 0, ".\\configurações\\_settings.ID");
	//------------ mix wings & capa
	iniciar_dll.iniciar_mixitem9  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[9]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem10  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[10]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem11  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[11]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_mixitem12  = iniciar_dll.iniciar_getprivateint("settings","iniciar_mixitem[12]", 0, ".\\configurações\\_settings.ID");
	//----------- mix item + 10 até + 13 
	//*(BYTE*) (0x00496626+6)  = iniciar_dll.iniciar_mixitem0;
	//*(BYTE*) (0x00496651+6)  = iniciar_dll.iniciar_mixitem2;
	//*(BYTE*) (0x0049667C+6)  = iniciar_dll.iniciar_mixitem4;
	//*(BYTE*) (0x004966A7+6)  = iniciar_dll.iniciar_mixitem6;
		//------------ Adiciona Rate Luck
	*(BYTE*) (0x004966D6+2)  = iniciar_dll.iniciar_mixitem8;
		//------------ mix wings & capa
	*(BYTE*) (0x004966E5+6)  = iniciar_dll.iniciar_mixitem9;
	*(BYTE*) (0x004966F1+6)  = iniciar_dll.iniciar_mixitem9;
	*(BYTE*) (0x00497DF0+6)  = iniciar_dll.iniciar_mixitem10;
	*(BYTE*) (0x00497DFC+6)  = iniciar_dll.iniciar_mixitem10;
	*(BYTE*) (0x00498499+6)  = iniciar_dll.iniciar_mixitem11;
	*(BYTE*) (0x004984A5+6)  = iniciar_dll.iniciar_mixitem11;
	*(BYTE*) (0x00497E11+6)  = iniciar_dll.iniciar_mixitem12;
	*(BYTE*) (0x00497E1D+6)  = iniciar_dll.iniciar_mixitem12;



	//----------- mana shield
	iniciar_dll.iniciar_manashield0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_manashield[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_manashield1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_manashield[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_manashield2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_manashield[2]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004B9DEB+1)  = iniciar_dll.iniciar_manashield0;
	*(unsigned int*) (0x004B9E0B+1)  = iniciar_dll.iniciar_manashield1;
	*(unsigned int*) (0x004B9E36+1)  = iniciar_dll.iniciar_manashield2;
	//----------- great fortitude
	iniciar_dll.iniciar_great0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_great[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_great1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_great[1]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004B99DF+1)  = iniciar_dll.iniciar_great0;
	*(unsigned int*) (0x004B99FF+1)  = iniciar_dll.iniciar_great1;
	//----------- elf soldier
	iniciar_dll.iniciar_maxlevelsoldier = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfsoldier[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_buffdefense     = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfsoldier[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_buffattack      = iniciar_dll.iniciar_getprivateint("settings","iniciar_elfsoldier[2]", 0, ".\\configurações\\_settings.ID");
	//----------
	*(unsigned int*) (0x00554DEF+1)  = iniciar_dll.iniciar_maxlevelsoldier;
	*(BYTE*)         (0x00554E32+2)  = iniciar_dll.iniciar_buffdefense;
	*(BYTE*)         (0x00554E50+2)  = iniciar_dll.iniciar_buffattack;
	//----------- party experiencia
	iniciar_dll.iniciar_expparty0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty3 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty4 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[4]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty5 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[5]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_expparty6 = iniciar_dll.iniciar_getprivateint("settings","iniciar_expparty[6]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x004E30B7+3)  = iniciar_dll.iniciar_expparty0;
	*(unsigned int*) (0x00465CF6+3)  = iniciar_dll.iniciar_expparty0;
	*(unsigned int*) (0x004E30C6+3)  = iniciar_dll.iniciar_expparty1;
	*(unsigned int*) (0x00465D05+3)  = iniciar_dll.iniciar_expparty1;
	*(unsigned int*) (0x004E30D5+3)  = iniciar_dll.iniciar_expparty2;
	*(unsigned int*) (0x00465D14+3)  = iniciar_dll.iniciar_expparty2;
	*(unsigned int*) (0x004E30E4+3)  = iniciar_dll.iniciar_expparty3;
	*(unsigned int*) (0x00465D23+3)  = iniciar_dll.iniciar_expparty3;
	*(unsigned int*) (0x004E3081+3)  = iniciar_dll.iniciar_expparty4;
	*(unsigned int*) (0x00465CC0+3)  = iniciar_dll.iniciar_expparty4;
	*(unsigned int*) (0x004E3090+3)  = iniciar_dll.iniciar_expparty5;
	*(unsigned int*) (0x00465CCF+3)  = iniciar_dll.iniciar_expparty5;
	*(unsigned int*) (0x004E309F+3)  = iniciar_dll.iniciar_expparty6;
	*(unsigned int*) (0x00465CDE+3)  = iniciar_dll.iniciar_expparty6;
	//----------- item drop
	iniciar_dll.iniciar_drop0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop3 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_drop4 = iniciar_dll.iniciar_getprivateint("settings","iniciar_drop[4]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x0041B0F8+1)  = iniciar_dll.iniciar_drop0;
	*(unsigned int*) (0x0041B44C+6)  = iniciar_dll.iniciar_drop1;
	*(unsigned int*) (0x0041B456+6)  = iniciar_dll.iniciar_drop2;
	*(unsigned int*) (0x0041B4A5+6)  = iniciar_dll.iniciar_drop3;
	*(unsigned int*) (0x0041B4AF+6)  = iniciar_dll.iniciar_drop4;

	//----------- skill level
	iniciar_dll.iniciar_skill0 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[0]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill1 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[1]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill2 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[2]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill3 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[3]", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_skill4 = iniciar_dll.iniciar_getprivateint("settings","iniciar_skill[4]", 0, ".\\configurações\\_settings.ID");
	//-----------
	*(unsigned int*) (0x00483640+7)  = iniciar_dll.iniciar_skill0;
	*(unsigned int*) (0x00483659+7)  = iniciar_dll.iniciar_skill1;
	*(unsigned int*) (0x00483672+7)  = iniciar_dll.iniciar_skill2;
	*(unsigned int*) (0x004836A4+7)  = iniciar_dll.iniciar_skill3;
	*(unsigned int*) (0x004836BD+7)  = iniciar_dll.iniciar_skill4;
	//----------- trade harmony
	iniciar_dll.iniciar_harmonytrade = iniciar_dll.iniciar_getprivateint("settings","iniciar_harmonytrade", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_harmonytrade == 1)
	{
	   *(BYTE*) (0x00575AB9)  = 0xEB;
	}
	//----------- zen drop
	iniciar_dll.iniciar_zendrop = iniciar_dll.iniciar_getprivateint("settings","iniciar_zendrop", 0, ".\\configurações\\_settings.ID");
	//-----------
	if(iniciar_dll.iniciar_zendrop == 1)
	{
	   *(BYTE*) (0x00490560)  = 0xC3;
	}
	//----------- skill siege
	iniciar_dll.iniciar_skillsiege = iniciar_dll.iniciar_getprivateint("settings","iniciar_skillsiege", 0, ".\\configurações\\_settings.ID");
	//----------
	if(iniciar_dll.iniciar_skillsiege == 1)
	{
	   *(BYTE*) (0x004BF154)  = 0xEB;
	   *(BYTE*) (0x004BF164)  = 0xEB;
	   *(BYTE*) (0x004BF247)  = 0xEB;
	   *(BYTE*) (0x004BF257)  = 0xEB;
	   *(BYTE*) (0x004BF364)  = 0xEB;
	   *(BYTE*) (0x004BF374)  = 0xEB;
	   *(BYTE*) (0x004BF447)  = 0xEB;
	   *(BYTE*) (0x004BF457)  = 0xEB;
	   *(BYTE*) (0x004BF564)  = 0xEB;
	   *(BYTE*) (0x004BF574)  = 0xEB;
	   *(BYTE*) (0x004BF654)  = 0xEB;
	   *(BYTE*) (0x004BF664)  = 0xEB;
	   *(BYTE*) (0x004BF737)  = 0xEB;
	   *(BYTE*) (0x004BF747)  = 0xEB;
	}
	//----------- shop PK
	iniciar_dll.iniciar_pkshop = iniciar_dll.iniciar_getprivateint("settings","iniciar_pkshop", 0, ".\\configurações\\_settings.ID");
	//----------
	if(iniciar_dll.iniciar_pkshop == 1)
	{
		*(BYTE*) (0x0043BC24+2)  = 0x64;
	}
	//----------- reset minimos
	iniciar_dll.iniciar_reset  = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.iniciar_resetq = iniciar_dll.iniciar_getprivateint("settings","iniciar_resetq",0, ".\\configurações\\_settings.ID");
	
	//----------- Titulo do GameServer
	char tmp[50];
	char dwTmp;
	char* GSname = (char*)(0x006BF098);
	dwTmp = GetPrivateProfileString("GameServerInfo","ServerName"," _-=| PREMIUM |=-_ ",tmp,50,".\\Data\\ServerInfo.dat"); 
	memset(&GSname[0],0x00,50);
	memcpy(&GSname[0],tmp,50);



	//----------- Cores da Barra do GameServer
	*(unsigned int*) (0x004A9747+1)  = RGB (0,250,154);		// GSBarColor			
	*(unsigned int*) (0x004A9D17+1)  = RGB (255, 255, 255);	// GSBarTextColor		
	*(unsigned int*) (0x004A9758+1)  = RGB (255,0,0);		// GSBarDisconnectColor

	// - Fala do guarda
	DWORD *Offset = (DWORD*)(0x6B3D10);
	memset(&Offset[0],0,50);
	memcpy(&Offset[0],"Seja Bem Vindo",sizeof("Seja Bem Vindo"));

	//----------- Chaos Castle
	SetByte(0x00544936+3,PROTOCOL_POSITION);
	SetByte(0x005449EA+1,PROTOCOL_POSITION);
	SetByte(0x00543434+1,PROTOCOL_WALK);

	//----------- CGameServerAuth::~CGameServer (0x00000 Memory Error)
	SetRetn(0x0040635C);
	SetNop(0x0040635D,4);

	//----------- Party Zen Bug
	for(DWORD i = 0x0046604E; i <= 0x00466054; i++)
	SetByte(i,0xCC);
	SetByte(0x0046604E,0xE9);
	hook_proc(0x0046604E, (DWORD)(&CheckZenMonster));

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

	iniciar_dll.horasonline = iniciar_dll.iniciar_getprivateint("settings","TempoAtivar", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.tempo_online = iniciar_dll.iniciar_getprivateint("settings","TempoOnline", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.premio_type = iniciar_dll.iniciar_getprivateint("settings","moeda", 0, ".\\configurações\\_settings.ID");
	iniciar_dll.premio_valor = iniciar_dll.iniciar_getprivateint("settings","valor", 0, ".\\configurações\\_settings.ID");

}