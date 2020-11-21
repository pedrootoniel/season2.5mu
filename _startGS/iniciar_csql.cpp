#include "stdafx.h"

bool subCheckConnect;

//----------------------------------------------------------------------------------------//
//extern global
subCSQL _subC;

//----------------------------------------------------------------------------------------//
//construtor
subCSQL::subCSQL(void)
{
}

//----------------------------------------------------------------------------------------//
//descontrutor
subCSQL::~subCSQL(void)
{
}

//----------------------------------------------------------------------------------------//
//conexão CSQL
void subCSQL::subCSQL_conectar()
{
	//----------- ip de conexão sql
	GetPrivateProfileString("settings","iniciar_subCSQL","vazio",this->subCSQL_ip,255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	//----------- configurações das tabelas
	GetPrivateProfileString("settings","iniciar_subCSQLtabela",      "vazio",_subC.subCSQLtabela,255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLcoluna_id",   "vazio",_subC.subCSQLcoluna_id,255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
    GetPrivateProfileString("settings","iniciar_subCSQLcoluna_cl",   "vazio",_subC.subCSQLcoluna_retornar, 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	GetPrivateProfileString("settings","iniciar_subCSQLtabela_r",    "vazio",_subC.subCSQLtabela_r,255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLcoluna_id_r", "vazio",_subC.subCSQLcoluna_id_r,255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
    GetPrivateProfileString("settings","iniciar_subCSQLcoluna_cl_r", "vazio",_subC.subCSQLcoluna_retornar_r, 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	GetPrivateProfileString("settings","iniciar_subCSQLupdate[0]",   "vazio",_subC.subCSQLcoluna_update[0], 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLupdate[1]",   "vazio",_subC.subCSQLcoluna_update[1], 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLupdate[2]",   "vazio",_subC.subCSQLcoluna_update[2], 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLupdate[3]",   "vazio",_subC.subCSQLcoluna_update[3], 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLupdate[4]",   "vazio",_subC.subCSQLcoluna_update[4], 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLupdate[5]",   "vazio",_subC.subCSQLcoluna_update[5], 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	GetPrivateProfileString("settings","iniciar_jewelcash",			 "vazio",_query_cash,  255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_jewelgold",			 "vazio",_query_gold,  255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_jewelreset",		 "vazio",_query_reset, 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	GetPrivateProfileString("settings","iniciar_bonus_on_gold",			 "vazio",_query_bonus_on_gold,  255,".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_bonus_on_cash",			 "vazio",_query_bonus_on_cash,  255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	//protectsystem
	GetPrivateProfileString("settings","protect_system",	 "bloc_code = 1",_protect_server, 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");


	_subC.subCSQLativarvip = iniciar_dll.iniciar_getprivateint("settings","iniciar_subCSQLativarvip", 0, ".\\configurações\\_administrador.settings\\_settings.csql.ID");
	GetPrivateProfileString("settings","iniciar_subCSQLconexaoquery","vazio",_subC.subCSQLconexao_vip, 255,".\\configurações\\_administrador.settings\\_settings.csql.ID");

	_iniciar_csql.bThrowErrors = false;
	
	//----------- verifica se a conexão é valida
	if(!_iniciar_csql.Connect(this->subCSQL_ip))
	{
			MessageBox(0,"arquivo: configurações\\_administrador.settings\\_settings.csql.ID -> iniciar_subCSQL: configuração invalida", "Configuração->error", 0);
			ExitProcess(0);
	}
}

//----------------------------------------------------------------------------------------//
//conexão CSQL >> retornar, update, etc...(ver se funciona)
int subCSQL::subCSQL_retornar(char * id_or_name, char * sub_coluna_retornar, char * sub_tabela, char * sub_coluna_id, int objectstruct, char * inc)
{
	//----------- variavel
	char _query[255];

	//----------- switch para seleção
	switch(inc[0])
	{
		//----------- seleciona a tabela
	    case '*':
	        wsprintf(_query, "SELECT %s FROM %s WHERE %s = '%s'",sub_coluna_retornar,sub_tabela,sub_coluna_id,id_or_name);
	        if(_iniciar_csql.Execute(_query, &crec) == 1)
	         {
		         objectstruct = _iniciar_csql.GetInt();
	         }
			 else
			 {
				 //tentar fazer uma tentativa de reconexão
				 subCheckConnect = true;
				 //desconecta do sql
				 _iniciar_csql.Disconnect();
				 //conecta ao sql novamente
				 _subC.subCSQL_conectar();

			 }
	    break;
		//----------- faz update na tabela
	    case '+':
	        wsprintf(_query,"UPDATE %s SET %s WHERE %s = '%s'",sub_tabela,sub_coluna_retornar,sub_coluna_id,id_or_name);
	        if(_iniciar_csql.Execute(_query, &crec) == 1)
	         {
	         }
			 else
			 {
				 //tentar fazer uma tentativa de reconexão
				 subCheckConnect = true;
				 //desconecta do sql
				 _iniciar_csql.Disconnect();
				 //conecta ao sql novamente
				 _subC.subCSQL_conectar();
			 }
	    return 1;
	}

	//----------- retornar o valor
	crec.Close();

	return objectstruct;
}