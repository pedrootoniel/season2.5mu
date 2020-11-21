#pragma once

#include "stdafx.h"

//----------------------------------------------------------------------------------------//
class subCSQL
{
public:
	//----------- virtual
	subCSQL(void);
	virtual ~subCSQL(void);

	//-----------  funções
	void subCSQL_conectar();
	int  subCSQL_retornar(char * id_or_name, char * sub_coluna_retornar, char * sub_tabela, char * sub_coluna_id, int objectstruct, char * inc);

	//----------- variaveis
	char subCSQLtabela[20];
	char subCSQLcoluna_id[20];
	char subCSQLcoluna_retornar[20];

	char subCSQLtabela_r[20];
	char subCSQLcoluna_id_r[20];
	char subCSQLcoluna_retornar_r[20];

	char subCSQLativarvip;
	char subCSQLconexao_vip[255];

	char subCSQLcoluna_update[200][210];

	char _query_cash[255];
	char _query_gold[255];
	char _query_reset[255];

private:
	//----------- variaveis
	char subCSQL_ip[255];

};

//----------------------------------------------------------------------------------------//
//extern
extern subCSQL _subC;
extern bool subCheckConnect;