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
	//----------- desconecta do CSQL - para uso do reload
	_iniciar_csql.Disconnect();

	//----------- limpeza by nam4
	EmptyWorkingSet(GetCurrentProcess());

	//----------- cria uma pasta
	_mkdir(".\\configurações\\_administrador.log");

	//-----------inicializar conexão CSQL
	_subC.subCSQL_conectar();

	//----------- inicia as correções
	iniciar_correcoes();
	//----------- inicia as configurações de alteração
	iniciar_configuracoes();

    //----------- inicializar todos os hooks
    iniciar_hook();

	//----------- inicia calcharacter
	iniciar_full_calcharacter();

	//----------- Inicia Interface
	IniciaIni();
	HookThis((DWORD)&cDisplay::ViewPaint,0x00404340);
	HookThis((DWORD)&cDisplay::LogTextPaintProcEx,0x00403DFA);
	HookThis((DWORD)&cDisplay::LogTextAddEx,0x004029E6);

	//----------- Moves Customs
	cmds.load();
	//----------- Shop Exc
	AssemblyExcShops();

	//New Wings
	ReadyNewWings();

	//Balance 
	_balance.iniciar_balance();

	//Box Customs
	BronzeCustom.LoadDropBox();
	SilverCustom.LoadDropBox();
	GoldenCustom.LoadDropBox();

	SetOp((LPVOID)0x00405C2C, (LPVOID)ProtocolDS, ASM::JMP);

}