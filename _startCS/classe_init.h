#pragma once

#include "stdafx.h"

//----------------------------------------------------------------------------------------//
class init
{
public:
	//----------- virtual
	init(void);
	virtual ~init(void);

	//----------- funções
	void iniciar_func();
	//----------- retornar private int
	int  iniciar_getprivateint(char * inicio, char * string, int valor, char * patch);

	//----------- variaveis
	char  iniciar_checksum;
	char  iniciar_elfbuffdef;
	char  iniciar_elfbuffatk;
	char  iniciar_soulsl;
	char  iniciar_soulcl;
	char  iniciar_life;
	char  iniciar_char_del;
	char  iniciar_guild_del;
	int   iniciar_port;
	int   iniciar_tempo;
	char  iniciar_chaoscastle;
	char  iniciar_alianca;
	char  iniciar_mixitem0;
	char  iniciar_mixitem1;
	char  iniciar_mixitem2;
	char  iniciar_mixitem3;
	char  iniciar_mixitem4;
	char  iniciar_mixitem5;
	char  iniciar_mixitem6;
	char  iniciar_mixitem7;
	char  iniciar_mixitem8;
	char  iniciar_mixitem9;
	char  iniciar_mixitem10;
	char  iniciar_mixitem11;
	char  iniciar_mixitem12;
	int   iniciar_manashield0;
	int   iniciar_manashield1;
	int   iniciar_manashield2;
	int   iniciar_great0;
	int   iniciar_great1;
	int   iniciar_maxlevelsoldier;
	BYTE  iniciar_buffdefense;
	BYTE  iniciar_buffattack;
	int   iniciar_expparty0;
	int   iniciar_expparty1;
	int   iniciar_expparty2;
	int   iniciar_expparty3;
	int   iniciar_expparty4;
	int   iniciar_expparty5;
	int   iniciar_expparty6;
	int   iniciar_drop0;
	int   iniciar_drop1;
	int   iniciar_drop2;
	int   iniciar_drop3;
	int   iniciar_drop4;
	int   iniciar_skill0;
	int   iniciar_skill1;
	int   iniciar_skill2;
	int   iniciar_skill3;
	int   iniciar_skill4;
	char  iniciar_harmonytrade;
	char  iniciar_zendrop;
	char  iniciar_notice[200][255]; // menor mensagem, maior indetificação
	char  iniciar_skillsiege;
	char  iniciar_balanco;
	char  iniciar_camera;
	char  iniciar_pkshop;
	char  iniciar_reset;
	int   iniciar_resetq;
	int  iniciar_protocolo;

	
	char  jewel_up01;
	char  jewel_up02;
	char  jewel_up03;
	char  jewel_up04;
	char  jewel_up05;
	char  jewel_up06;
	char  jewel_up07;
	char  jewel_up08;
	char  jewel_up09;
	char  jewel_up10;
	char  jewel_up11;
	char  jewel_up12;
	char  jewel_up13;
	char  jewel_up14;

private:

};

//----------------------------------------------------------------------------------------//
//extern
extern init iniciar_dll;