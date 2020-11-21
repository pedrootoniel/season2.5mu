#include "stdafx.h"

//----------------------------------------------------------------------------------------//
init iniciar_dll;

//----------------------------------------------------------------------------------------//
//construtor
init::init(void)
{
}

//----------------------------------------------------------------------------------------//
//descontrutor
init::~init(void)
{
}

//----------------------------------------------------------------------------------------//
//retornar 
int init::iniciar_getprivateint(char * inicio, char * string, int valor, char * patch)
{
	return  GetPrivateProfileInt(inicio,string,valor,patch);
}



//----------------------------------------------------------------------------------------//
//função principal
void init::iniciar_func()
{
	_iniciar_csql.Disconnect();
	EmptyWorkingSet(GetCurrentProcess());
	_mkdir(".\\configurações\\_administrador.log");
	_subC.subCSQL_conectar();
	iniciar_correcoes();
	iniciar_configuracoes();
    iniciar_hook();
	iniciar_full_calcharacter();
	HookThis((DWORD)&cDisplay::ViewPaint,0x0040424B);
	HookThis((DWORD)&cDisplay::LogTextPaintProcEx,0x00403DC8);
	HookThis((DWORD)&cDisplay::LogTextAddEx,0x00402630);
	IniciaIni();
	cmds.load();
	AssemblyExcShops();
	ReadyGCMagicAttackNumberSend();
	_balance.iniciar_balance();
	ReadyNewWings();
	EventLoad();

	//Box Customs
	BronzeCustom.LoadDropBox();
	SilverCustom.LoadDropBox();
	GoldenCustom.LoadDropBox();
}