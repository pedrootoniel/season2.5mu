#include "stdafx.h"

cConfig gConfig;

cConfig::cConfig()
{
	GetPrivateProfileStringA("SystemMain","SystemScreenShots","ScreenShots",SystemScreenShots,sizeof(SystemScreenShots),CONFIG_MAIN_FILE);
#ifdef CLASSIC
	GetPrivateProfileStringA("SystemMain","SystemTitle","MuSupremo - Season II",SystemTitle,sizeof(SystemTitle),CONFIG_MAIN_FILE);
#endif
#ifdef Ex201
		GetPrivateProfileStringA("SystemMain","SystemTitle","MuSupremo Season2",SystemTitle,sizeof(SystemTitle),CONFIG_MAIN_FILE);
#endif
	GetPrivateProfileStringA("Connect","Ip","192.168.0.102",SystemIP,sizeof(SystemIP),CONFIG_MAIN_FILE);
	GetPrivateProfileStringA("Connect","Serial","0000000000000000",SystemSerial,sizeof(SystemSerial),CONFIG_MAIN_FILE);
}

DWORD OptimizeBack = 0x6B4A4A;
__declspec(naked) void Optimize()
{
	__asm
	{
		PUSH 1;
		CALL DWORD PTR DS : [0x783164];
		CALL DWORD PTR DS : [0x783160];

		JMP OptimizeBack;
	}
}

void Main()
{

	//===================================================================================
	// Titulo
	//===================================================================================
	int *gTitle = (int*)(0x007A2448);
	memset(&gTitle[0],0x00,sizeof(gConfig.SystemTitle));
	memcpy(&gTitle[0],gConfig.SystemTitle,sizeof(gConfig.SystemTitle));
	
	//===================================================================================
	// Ip
	//===================================================================================
	char cAdress[20];
	sprintf(cAdress, "%s", gConfig.SystemIP);
	WriteMemory( (PVOID) 0x007A16C2, cAdress, sizeof( cAdress ) );


	//===================================================================================
	// Serial
	//===================================================================================
	char cSerial[17];
	sprintf(cSerial, "%s", gConfig.SystemSerial);
	WriteMemory( (PVOID) 0x007A2840, cSerial, sizeof( cSerial ) );
}
void SpeedHacker()
{
	//===================================================================================
	//speed
	//===================================================================================
	hook_extended(0x006B458E,                (DWORD)(&speedhacker));
	func_nop(0x006B458E+5, 8);
	hook_extended(0x004DCFC3,                (DWORD)(&character_load));
	func_nop(0x004DCFC3+5, 3);
	hook_extended(0x00589F15,                (DWORD)(&calcharacter_restruct));
	func_nop(0x00589F15+5, 2);
	hook_extended(0x0058A4D7,                (DWORD)(&calcharacter_restruct_speed));
	func_nop(0x0058A4D7+5, 14);
	hook_extended(0x005142AE,                (DWORD)(&attack_speed_restruct));
	func_nop(0x005142AE+5, 2);

}
void Fix()
{
	//===================================================================================
	//protocolo
	//===================================================================================
	ProtocolLoad();

	//===================================================================================
	//pontos fixado acima de 65535
	//===================================================================================
	hook_extended(0x0064AACF,                (DWORD)(&gObjPointsFix));
	func_nop(0x0064AACF+5, 6);

	//===================================================================================
	//mensagem vermelha
	//===================================================================================
	hook_extended(0x004DF452,                (DWORD)(&gObjMessage));
	func_nop(0x004DF452+5, 42);


	//===================================================================================
	//brilho dos items + 14 & + 15
	//===================================================================================
	//fumaça dos sets fixada em + 15
	//===================================================================================
	*(BYTE*)(0x00521567+2)	 = 0x0D;
	*(BYTE*)(0x0052159D+2)	 = 0x0D;
	//===================================================================================
	//extensão até + 16
	//===================================================================================
	*(BYTE*)(0x0067C390+3)  = 0x10; 
	//===================================================================================
	//extensão ate + 15 defesa, danos, etc..., alteração da variavel até + 11
	//===================================================================================
	*(BYTE*)(0x00583B62+3)  = 0x0B;
	*(BYTE*)(0x00583B68+3)  = 0x0B;
	*(BYTE*)(0x00583B91+2)  = 0x0B;
	*(BYTE*)(0x00583C8D+3)  = 0x0B;
	*(BYTE*)(0x00583C93+3)  = 0x0B;
	*(BYTE*)(0x00583CBC+2)  = 0x0B;
	*(BYTE*)(0x00583DAF+3)  = 0x0B;
	*(BYTE*)(0x00583DB5+3)  = 0x0B;
	*(BYTE*)(0x00583DDB+2)  = 0x0B;
	*(BYTE*)(0x00583EC0+3)  = 0x0B;
	*(BYTE*)(0x00583EC6+3)  = 0x0B;
	*(BYTE*)(0x00583EEC+2)  = 0x0B;
	*(BYTE*)(0x00584069+3)  = 0x0B;
	*(BYTE*)(0x0058406F+3)  = 0x0B;
	*(BYTE*)(0x005840A4+3)  = 0x0B;
	*(BYTE*)(0x005840AA+3)  = 0x0B;
	*(BYTE*)(0x005840D1+3)  = 0x0B;
	*(BYTE*)(0x005840D7+3)  = 0x0B;
	*(BYTE*)(0x00584100+2)  = 0x0B;
	*(BYTE*)(0x00584177+3)  = 0x0B;
	*(BYTE*)(0x0058417D+3)  = 0x0B;
	*(BYTE*)(0x005841A6+2)  = 0x0B;

	//===================================================================================
	//deixa a cor das wings level 1 normal
	//retira o nome excellente
	//visualisa as options
	//===================================================================================
	*(BYTE*)(0x005FDA14+3)	= 0x00; 
	*(BYTE*)(0x005FF0D9+3)	= 0x00;
	//*(BYTE*)(0x0058466E+1)	= 0x00;

	//==================================================================================
	//altera o limite de items
	//==================================================================================
	/*int ITENS = 0x7F;
	func_byte(0x006813F3+3, ITENS);
	func_byte(0x006819DD+3, ITENS);
	func_byte(0x00681CDD+3, ITENS);
	func_byte(0x006826E2+3, ITENS);
	func_byte(0x006827B1+3, ITENS);
	func_byte(0x006854A2+3, ITENS);
	func_byte(0x00683B4D+3, ITENS);
	func_byte(0x00683B8A+3, ITENS);
	func_byte(0x00683C36+3, ITENS);
	func_byte(0x00683CFB+3, ITENS);
	func_byte(0x00683A08+3, ITENS);
	func_byte(0x00683C8C+3, ITENS);
	func_byte(0x00684BC3+3, ITENS);
	func_byte(0x00684AED+3, ITENS);*/

	//===================================================================================
	//screenshots
	//===================================================================================
	_mkdir("ScreenShots");
	memset((char*)0x007B5E10,0,60);
	memcpy((char*)0x007B5E10,".\\ScreenShots\\Screen(%02d_%02d-%02d_%02d)-%04d.jpg",60);


	//===================================================================================
	//Fix Consumo CPU
	//===================================================================================
	hook_extended(0x6B4A44,   (DWORD)(&Optimize));

	//==================================================================================
	//Fix
	//==================================================================================
	BYTE MoveListFix[] = { 0xEB, 0x28 };
	WriteMemory( (PVOID) 0x00460338, & MoveListFix, sizeof( MoveListFix ) );

	//==================================================================================
	// Change Folder
	//==================================================================================
	_mkdir(ErrorDir);
	char cTempLog[40] = ErrorLog;
	DWORD *offsetLog = (DWORD*)(0x0079F4D4);
	memset(&offsetLog[0],0,40);
	memcpy(&offsetLog[0],cTempLog,strlen(cTempLog));

	char cTempDump[40] = DumpLog;
	DWORD *offsetDump = (DWORD*)(0x007A25F4);
	memset(&offsetDump[0],0,40);
	memcpy(&offsetDump[0],cTempDump,strlen(cTempDump));

	//==================================================================================
	// Decrypt Logs
	//==================================================================================
	BYTE DecriptLog[5] = { 0x90, 0x90, 0x90, 0x90, 0x90 };
	memcpy((int*)0x00420F8D, DecriptLog, sizeof(DecriptLog));
	memcpy((int*)0x004211A0, DecriptLog, sizeof(DecriptLog));

	//==================================================================================
	// Dont Show IP IN LOG FILE
	//==================================================================================
	SetByte((PVOID)0x004DA2F9, 0x80);
	SetByte((PVOID)0x004DA2FA, 0x7B);
	SetByte((PVOID)0x004DA2FB, 0x87); 
	SetByte((PVOID)0x004DA2FC, 0x05); 


	//==================================================================================
	// Fenrir Style Season 4
	//==================================================================================
	SetByte((PVOID)(0x0045BEE3+3),0x66);
	SetByte((PVOID)(0x0045BEE3+4),0x66);
	SetByte((PVOID)(0x0045BEE3+5),0x66);
	SetByte((PVOID)(0x0045BEE3+6),0x3F);

	//==================================================================================
	//1° Check -- Libera a skill para ser atacada
	//==================================================================================
	*(BYTE*) (0x005E6B17+1)    =   0x2B;
	*(BYTE*) (0x005E6B1C+1)    =   0x26;
	*(BYTE*) (0x005E6B21+1)    =   0x21;
	*(BYTE*) (0x005E6B26+1)    =   0x1C;
	*(BYTE*) (0x005E6B2B+1)    =   0x17;
	*(BYTE*) (0x005E6B30)      =   0xEB;
	//==================================================================================
	//2° Check -- Deixar o icone da skill normal em todos os mapas
	//==================================================================================
	*(BYTE*) (0x005E700F+2)    =   0x00;
	*(BYTE*) (0x005E7014+2)    =   0x00;
	*(BYTE*) (0x005E7019+2)    =   0x00;
	*(BYTE*) (0x005E701E+2)    =   0x00;
	*(BYTE*) (0x005E7023+2)    =   0x00;
	*(BYTE*) (0x005E7028+2)    =   0x00;
	*(BYTE*) (0x005E702B)      =   0xEB;
	//==================================================================================
	//3° Check -- Tirar Mensagem "Use Skill only in siege"
	//==================================================================================
	*(BYTE*) (0x0060600D+1)    =   0x00;
	*(BYTE*) (0x00606011+1)    =   0x00;
	*(BYTE*) (0x00606015+1)    =   0x00;
	*(BYTE*) (0x00606019+1)    =   0x00;
	*(BYTE*) (0x0060601D+1)    =   0x00;
	*(BYTE*) (0x00606021+1)    =   0x00;
	//==================================================================================
	//4° Check - Liberar Dano das Skills
	//==================================================================================
	*(BYTE*) (0x0040D807+3)    =   0x01;

	//==================================================================================
	//Recuo - Reflect
	//==================================================================================
	*(BYTE*) (0x00515B47)  = 0xC3;

	//==================================================================================
	// - HP Bar
	//==================================================================================
	HookCall(0x5E9A67, HPBar.DrawHealthBar);

	//==================================================================================
	// [#] Load
	//==================================================================================
	LoadTexture(".\\Data\\_CustomMain_\\texture\\texture.dat");
	hook_extended(0x0068458B,                (DWORD)(&gObjTexture));
	func_nop(0x0068458B+5, 20);

	LoadLibrary("weapons.dll");
	LoadLibrary("Min.dll");
	LoadLibrary("Texture.dll");

	//=================================================
	// - [Fix] FPS De 40 para 35 
	//=================================================
	//*(BYTE*)(0x006B4A3B+6) = 0x23; 

	//==================================================================================
	// [#] Lag usando CTRL
	//==================================================================================
	SetByte((LPVOID)0x0046F249,0x02);

	//=================================================
	//--  ANTIALIASED  
	//=================================================
	*(BYTE*)(0x4D58AB + 1) = ANTIALIASED_QUALITY;
	*(BYTE*)(0x4D58EB + 1) = ANTIALIASED_QUALITY;
	*(BYTE*)(0x4D592B + 1) = ANTIALIASED_QUALITY;
	*(BYTE*)(0x4D5983 + 1) = ANTIALIASED_QUALITY;

}
void Interface()
{
	//=================================================
	// [#] - Loading Custom
	//=================================================
	int loading;
	srand (time(NULL));
	loading = rand() % 4 + 1;

	if(loading == 1)
	{
		const char lo_Back01[] = {"interface\\lo_back_01.jpg"};
		memcpy((int*)0x007B5A98,lo_Back01,sizeof(lo_Back01));
		const char lo_Back02[] = {"interface\\lo_back_02.jpg"};
		memcpy((int*)0x007B5AB4, lo_Back02, sizeof(lo_Back02));
	}
	if(loading == 2)
	{
		const char lo_Back01[] = {"interface\\lo_back_11.jpg"};  
		memcpy((int*)0x007B5A98,lo_Back01,sizeof(lo_Back01));
		const char lo_Back02[] = {"interface\\lo_back_12.jpg"};
		memcpy((int*)0x007B5AB4, lo_Back02, sizeof(lo_Back02));
	}
	if(loading == 3)
	{
		const char lo_Back01[] = {"interface\\lo_back_21.jpg"};  
		memcpy((int*)0x007B5A98,lo_Back01,sizeof(lo_Back01));
		const char lo_Back02[] = {"interface\\lo_back_22.jpg"};
		memcpy((int*)0x007B5AB4, lo_Back02, sizeof(lo_Back02));
	}

	if(loading == 4)
	{
		const char lo_Back01[] = {"interface\\lo_back_31.jpg"};  
		memcpy((int*)0x007B5A98,lo_Back01,sizeof(lo_Back01));
		const char lo_Back02[] = {"interface\\lo_back_32.jpg"};
		memcpy((int*)0x007B5AB4, lo_Back02, sizeof(lo_Back02));
	}

#ifdef Ex201
	//=================================================
	// Interface Custom Ex702
	//=================================================f
	// Remove Dark Horse
	// Remove Dark Lord
	// Remove Flying Red Dragon
	//=================================================
	memset((int*)0x006B105D,0x90,5);
	memset((int*)0x006B1018,0x90,5);
	memset((int*)0x0068EDE1,0x90,5);
#endif
	////=================================================
	//// [#] - Select Server Custom
	////=================================================
	//*(BYTE*)(0x006B0F7F+6) = 0x1E;
	////=================================================
	//// [#] - Select Char Custom
	////=================================================
	//*(BYTE*)(0x006B0522+6) = 0x36;

	//const char Back01[] = {"Logo\\Login_Back11.jpg"};
	//memcpy((int*)0x007B2F48,Back01,sizeof(Back01));
	//const char Back02[] = {"Logo\\Login_Back12.jpg"};
	//memcpy((int*)0x007B2F60, Back02, sizeof(Back02));

}
void __declspec(naked) WindowIconHook()
{
	static DWORD dwIcon = (DWORD)LoadIcon(gConfig.Instance, MAKEINTRESOURCE(IDI_ICON2));
	static DWORD dwJmp = 0x004D40AE;

	_asm
	{
		MOV EAX, dwIcon
		JMP dwJmp
	}
}
void InitWindowIcon()
{
	SetRange((LPVOID)0x004D40A1, 13, ASM::NOP);
	SetOp((LPVOID)0x004D40A1, WindowIconHook, ASM::CALL);
}