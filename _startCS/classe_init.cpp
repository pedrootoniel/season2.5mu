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
//fun��o principal
void init::iniciar_func()
{
	//----------- desconecta do CSQL - para uso do reload
	_iniciar_csql.Disconnect();

	//----------- limpeza by nam4
	EmptyWorkingSet(GetCurrentProcess());

	//----------- cria uma pasta
	_mkdir(".\\configura��es\\_administrador.log");

	//-----------inicializar conex�o CSQL
	_subC.subCSQL_conectar();

	//----------- inicia as corre��es
	iniciar_correcoes();
	//----------- inicia as configura��es de altera��o
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