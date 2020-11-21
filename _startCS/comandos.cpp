#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_comandos _iniciar_comandos;

//----------------------------------------------------------------------------------------//
//reload
void _comandos::_reload()
{
	_iniciar_comandos.variavelgamemaster = 0;
    memset(_iniciar_comandos._struct, 0, sizeof(_iniciar_comandos._struct));
}

//----------------------------------------------------------------------------------------//
//configurações
void _comandos::_comandos_gmsystem(char* filename)
{

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(filename), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			strcpy_s(_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].nome, sizeof(_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].nome), (section.Rows[i].GetStringPtr(0)) );
			_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].comando[1]       = section.Rows[i].GetInt(1);
			_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].comando[2]       = section.Rows[i].GetInt(2);
			_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].comando[3]       = section.Rows[i].GetInt(3);
			_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].comando[4]       = section.Rows[i].GetInt(4);
			_iniciar_comandos._struct[_iniciar_comandos.variavelgamemaster].comando[5]       = section.Rows[i].GetInt(5);
			_iniciar_comandos.variavelgamemaster++;
		}
	}
}

//----------------------------------------------------------------------------------------//
//configurações
void _comandos::_comandos_config()
{

	  this->_reload();

	  this->_comandos_gmsystem   (".\\configurações\\_administrador.settings\\_settings.gamemaster.ID");

	  //----------------------------------------------------------------------------------------//
	  //strings
      GetPrivateProfileString("settings","iniciar_string[0]", "vazio",_iniciar_comandos._struct->string[0], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[1]", "vazio",_iniciar_comandos._struct->string[1], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[2]", "vazio",_iniciar_comandos._struct->string[2], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[3]", "vazio",_iniciar_comandos._struct->string[3], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[4]", "vazio",_iniciar_comandos._struct->string[4], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[5]", "vazio",_iniciar_comandos._struct->string[5], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[6]", "vazio",_iniciar_comandos._struct->string[6], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[7]", "vazio",_iniciar_comandos._struct->string[7], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[8]", "vazio",_iniciar_comandos._struct->string[8], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[9]", "vazio",_iniciar_comandos._struct->string[9], 30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[10]","vazio",_iniciar_comandos._struct->string[10],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[11]","vazio",_iniciar_comandos._struct->string[11],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[12]","vazio",_iniciar_comandos._struct->string[12],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[13]","vazio",_iniciar_comandos._struct->string[13],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[14]","vazio",_iniciar_comandos._struct->string[14],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[15]","vazio",_iniciar_comandos._struct->string[15],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[16]","vazio",_iniciar_comandos._struct->string[16],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[17]","vazio",_iniciar_comandos._struct->string[17],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[18]","vazio",_iniciar_comandos._struct->string[18],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[19]","vazio",_iniciar_comandos._struct->string[19],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[20]","vazio",_iniciar_comandos._struct->string[20],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[21]","vazio",_iniciar_comandos._struct->string[21],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[22]","vazio",_iniciar_comandos._struct->string[22],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[23]","vazio",_iniciar_comandos._struct->string[23],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  GetPrivateProfileString("settings","iniciar_string[24]","vazio",_iniciar_comandos._struct->string[24],30,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  //----------------------------------------------------------------------------------------//
	  //ints
	  _iniciar_comandos._struct->ativar[0] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[0]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[0]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[0]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[0]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[0]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[0]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[0]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->corpost   = iniciar_dll.iniciar_getprivateint("settings","iniciar_cor[0]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[1] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[1]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[1]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[1]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[1]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[1]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[1]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[1]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[2] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[2]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[2]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[2]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[2]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[2]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[2]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[2]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[3] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[3]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[3]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[3]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[3]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[3]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[3]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[3]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[4] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[4]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[4]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[4]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[4]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[4]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[4]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[4]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[5] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[5]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[5]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[5]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[5]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[5]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[5]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[5]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[6] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[6]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[6]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[6]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[6]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[6]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[6]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[6]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[7] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[7]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[7]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[7]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[7]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[7]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[7]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[7]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->gm[7]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_gm[7]",     0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[8] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[8]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[8]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[8]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[8]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[8]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[8]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[8]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->gm[8]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_gm[8]",     0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[9] = iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[9]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[9]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[9]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[9]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[9]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[9]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[9]",  0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->gm[9]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_gm[9]",     0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[10]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[10]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[10] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[10]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[10]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[10]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[10] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[10]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->gm[10]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_gm[10]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[11]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[11]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[11] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[11]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[11]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[11]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[11] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[11]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->gm[11]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_gm[11]",    0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[12]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[12]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[12] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[12]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[12]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[12]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[12] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[12]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[13]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[13]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[13] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[13]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[13]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[13]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[13] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[13]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->maxbau[0] = iniciar_dll.iniciar_getprivateint("settings","iniciar_maxbau[0]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->maxbau[1] = iniciar_dll.iniciar_getprivateint("settings","iniciar_maxbau[1]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->maxbau[2] = iniciar_dll.iniciar_getprivateint("settings","iniciar_maxbau[2]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->maxbau[3] = iniciar_dll.iniciar_getprivateint("settings","iniciar_maxbau[3]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->maxbau[4] = iniciar_dll.iniciar_getprivateint("settings","iniciar_maxbau[4]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->maxbau[5] = iniciar_dll.iniciar_getprivateint("settings","iniciar_maxbau[5]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[14]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[14]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[14] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[14]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[14]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[14]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[14] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[14]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[15]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[15]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[15] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[15]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[15]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[15]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[15] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[15]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[16]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[16]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[16] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[16]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[16]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[16]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[16] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[16]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[17]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[17]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[17] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[17]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[17]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[17]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[17] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[17]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[18]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[18]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[18] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[18]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[18]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[18]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[18] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[18]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[19]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[19]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[19] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[19]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[19]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[19]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[19] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[19]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[20]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[20]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[20] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[20]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[20]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[20]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[20] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[20]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[22]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[22]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[22] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[22]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[22]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[22]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[22] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[22]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

	  _iniciar_comandos._struct->ativar[23]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[23]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[23] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[23]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[23]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[23]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[23] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[23]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

  	  _iniciar_comandos._struct->ativar[24]= iniciar_dll.iniciar_getprivateint("settings","iniciar_ativar[24]",0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->level[24] = iniciar_dll.iniciar_getprivateint("settings","iniciar_level[24]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->vip[24]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_vip[24]",   0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");
	  _iniciar_comandos._struct->money[24] = iniciar_dll.iniciar_getprivateint("settings","iniciar_money[24]", 0,".\\configurações\\_administrador.settings\\_settings.comandos.ID");

}

//----------------------------------------------------------------------------------------//
//post
void _comandos::_comando_post(LPOBJ lpObj, char * String)
{

	int reset = _subC.subCSQL_retornar(lpObj->Name,_subC.subCSQLcoluna_retornar_r,_subC.subCSQLtabela_r,_subC.subCSQLcoluna_id_r,lpObj->reset,"*");

	if(subCheckConnect == true)
	{
		GCServerMsgStringSend("aguarde a reconexão com o banco de dados.",lpObj->m_Index,0);
		subCheckConnect = false;
		return;
	}

	if(_iniciar_comandos._struct->ativar[0] == 0)
	{
		_mensagem(lpObj->m_Index,13,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[0])
	{
		_mensagem(lpObj->m_Index,14,_iniciar_comandos._struct->level[0],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[0])
	{
		_mensagem(lpObj->m_Index,15,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[0])
	{
		_mensagem(lpObj->m_Index,16,_iniciar_comandos._struct->money[0],0,0);
		return;
	}

    for(int x = MIN_PLAYERID; x < MAX_PLAYERID; x++)
	{
		TCHAR post[512];
	   	wsprintf(post,"[post]: %s",String);
	    if(gObjIsConnected(x) == 1)
		{
			switch(_iniciar_comandos._struct->corpost)
			{
			case 0:
		        ChatSendParty(lpObj->Name,post,x);
			break;
			case 1:
		        ChatSendGuild(lpObj->Name,post,x);
			break;
			case 2:
		        ChatSendNormal(lpObj->Name,post,x);
			break;
			case 3:
		        ChatSendAlliance(lpObj->Name,post,x);
			break;
			}
		}
	}
	
	lpObj->Money -= _iniciar_comandos._struct->money[0];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//add
void _comandos::_comando_adicionar(LPOBJ lpObj, char * String, char switchs, char arrays)
{
	if(_iniciar_comandos._struct->ativar[arrays] == 0)
	{
		_mensagem(lpObj->m_Index,17,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[arrays])
	{
		_mensagem(lpObj->m_Index,18,_iniciar_comandos._struct->level[arrays],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[arrays])
	{
		_mensagem(lpObj->m_Index,19,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[arrays])
	{
		_mensagem(lpObj->m_Index,20,_iniciar_comandos._struct->money[arrays],0,0);
		return;
	}

	sscanf(String,"%d",&this->_pontos);

	if(this->_comando_status(lpObj,switchs,this->_pontos) == 0)
	{
	    lpObj->Money -= _iniciar_comandos._struct->money[arrays];
		GCMoneySend(lpObj->m_Index,lpObj->Money);
	}
}

//----------------------------------------------------------------------------------------//
//pkclear
void _comandos::_comando_pkclear(LPOBJ lpObj, char npc_or_comando, DWORD* NpcIndex)
{
	if(_iniciar_comandos._struct->ativar[6] == 0)
	{
		if(npc_or_comando == 0)
		{
		    _mensagem(lpObj->m_Index,22,0,0,0);
		}
		else
		{
			_mensagem(lpObj->m_Index,22,0,NpcIndex,1);
		}
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[6])
	{
		if(npc_or_comando == 0)
		{
		    _mensagem(lpObj->m_Index,23,_iniciar_comandos._struct->level[6],0,0);
		}
		else
		{
			_mensagem(lpObj->m_Index,23,_iniciar_comandos._struct->level[6],NpcIndex,1);
		}
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[6])
	{
		if(npc_or_comando == 0)
		{
		    _mensagem(lpObj->m_Index,24,0,0,0);
		}
		else
		{
			_mensagem(lpObj->m_Index,24,0,NpcIndex,1);
		}
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[6])
	{
		if(npc_or_comando == 0)
		{
		    _mensagem(lpObj->m_Index,25,_iniciar_comandos._struct->money[6],0,0);
		}
		else
		{
			_mensagem(lpObj->m_Index,25,_iniciar_comandos._struct->money[6],NpcIndex,1);
		}
		return;
	}

	if(lpObj->m_PK_Level < 4)
	{
		if(npc_or_comando == 0)
		{
		    _mensagem(lpObj->m_Index,26,0,0,0);
		}
		else
		{
			_mensagem(lpObj->m_Index,26,0,NpcIndex,1);
		}
		return;
	}	

	if(npc_or_comando == 0)
	{
		_mensagem(lpObj->m_Index,27,0,0,0);
	}
	else
	{
	    _mensagem(lpObj->m_Index,27,0,NpcIndex,1);
	}

	lpObj->Money -= _iniciar_comandos._struct->money[6];
	lpObj->m_PK_Level = 3;
	GCPkLevelSend(lpObj->m_Index,lpObj->m_PK_Level);
	GCLevelUpMsgSend(lpObj->m_Index,1);
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//drop
void _comandos::_comando_drop(LPOBJ lpObj, char * String)
{
	if(_iniciar_comandos._struct->ativar[7] == 0)
	{
		_mensagem(lpObj->m_Index,28,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[7])
	{
		_mensagem(lpObj->m_Index,29,_iniciar_comandos._struct->level[7],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[7])
	{
		_mensagem(lpObj->m_Index,30,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[7])
	{
		_mensagem(lpObj->m_Index,31,_iniciar_comandos._struct->money[7],0,0);
		return;
	}

	if(_iniciar_comandos._struct->gm[7] == 0)
	{ 
		if(this->gamemaster(lpObj,1) == 1)
		{
		    return;
		}
	}
	else
	{ 
	    if(lpObj->Authority < 2)
		{
		   return;
		}
		else
		{
			if(this->gamemaster(lpObj,1) == 1)
			{
				return;
			}
	    }
	}

    sscanf(String,"%d %d %d %d %d %d %d %d",&this->_index,&this->_id,&this->_level,&this->_skill,&this->_luck,&this->_addopt,&this->_addoptex,&this->_quantidade);

	if(this->_quantidade > 10)
	{
		this->_quantidade = 10;
	}

	for(char x = 0; x < this->_quantidade; x++)
	{
	  DWORD Item = this->_index * 512 + this->_id;
	  ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Item,this->_level,0,this->_skill,this->_luck,this->_addopt,lpObj->m_Index,this->_addoptex,0);
	}

	lpObj->Money -= _iniciar_comandos._struct->money[7];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//skin
void _comandos::_comando_skin(LPOBJ lpObj, char * String)
{
	if(_iniciar_comandos._struct->ativar[8] == 0)
	{
		_mensagem(lpObj->m_Index,32,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[8])
	{
		_mensagem(lpObj->m_Index,33,_iniciar_comandos._struct->level[8],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[8])
	{
		_mensagem(lpObj->m_Index,34,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[8])
	{
		_mensagem(lpObj->m_Index,35,_iniciar_comandos._struct->money[8],0,0);
		return;
	}

	if(_iniciar_comandos._struct->gm[8] == 0)
	{ 
		if(this->gamemaster(lpObj,2) == 1)
		{
		    return;
		}
	}
	else
	{ 
	    if(lpObj->Authority < 2)
		{
		   return;
		}
		else
		{
			if(this->gamemaster(lpObj,2) == 1)
			{
				return;
			}
	    }
	}

    sscanf(String,"%d",&this->_pontos);
	lpObj->m_Change = this->_pontos;
	gObjViewportList(lpObj);
	lpObj->Money -= _iniciar_comandos._struct->money[8];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//reload
void _comandos::_comando_reload(LPOBJ lpObj, char * String)
{
	if(_iniciar_comandos._struct->ativar[9] == 0)
	{
		_mensagem(lpObj->m_Index,36,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[9])
	{
		_mensagem(lpObj->m_Index,37,_iniciar_comandos._struct->level[9],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[9])
	{
		_mensagem(lpObj->m_Index,38,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[9])
	{
		_mensagem(lpObj->m_Index,39,_iniciar_comandos._struct->money[9],0,0);
		return;
	}

	if(_iniciar_comandos._struct->gm[9] == 0)
	{ 
		if(this->gamemaster(lpObj,3) == 1)
		{
		    return;
		}
	}
	else
	{ 
	    if(lpObj->Authority < 2)
		{
		   return;
		}
		else
		{
			if(this->gamemaster(lpObj,3) == 1)
			{
				return;
			}
	    }
	}

    sscanf(String,"%d",&this->_quantidade);

	switch(this->_quantidade)
	{
	case 0:
	    iniciar_dll.iniciar_func();
	    _mensagem(lpObj->m_Index,40,0,0,0);
	   break;
	case 1:
        GameMonsterAllCloseAnd();
		_mensagem(lpObj->m_Index,41,0,0,0);
		break;
	case 2:
        ShopDataLoad();
	    _mensagem(lpObj->m_Index,42,0,0,0);
		break;
	default:
		_mensagem(lpObj->m_Index,43,0,0,0);
	    return;
	}

	lpObj->Money -= _iniciar_comandos._struct->money[9];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//move
void _comandos::_comando_move(LPOBJ lpObj, char * String)
{
	if(_iniciar_comandos._struct->ativar[10] == 0)
	{
		_mensagem(lpObj->m_Index,44,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[10])
	{
		_mensagem(lpObj->m_Index,45,_iniciar_comandos._struct->level[10],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[10])
	{
		_mensagem(lpObj->m_Index,46,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[10])
	{
		_mensagem(lpObj->m_Index,47,_iniciar_comandos._struct->money[10],0,0);
		return;
	}

	if(_iniciar_comandos._struct->gm[10] == 0)
	{ 
		if(this->gamemaster(lpObj,4) == 1)
		{
		    return;
		}
	}
	else
	{ 
	    if(lpObj->Authority < 2)
		{
		   return;
		}
		else
		{
			if(this->gamemaster(lpObj,4) == 1)
			{
				return;
			}
	    }
	}

    sscanf(String,"%s %d %d %d",&this->_nome,&this->_index,&this->_id,&this->_level);

	int index = gObjGetIndex(this->_nome);
	OBJECTSTRUCT* xxxx = (OBJECTSTRUCT*)GS_GOBJPOINTER(index);
	gObjTeleport(index,this->_index,this->_id,this->_level);

	lpObj->Money -= _iniciar_comandos._struct->money[10];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//money
void _comandos::_comando_money(LPOBJ lpObj)
{
	if(_iniciar_comandos._struct->ativar[11] == 0)
	{
		_mensagem(lpObj->m_Index,48,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[11])
	{
		_mensagem(lpObj->m_Index,49,_iniciar_comandos._struct->level[11],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[11])
	{
		_mensagem(lpObj->m_Index,50,0,0,0);
	    return;
	}

	if(_iniciar_comandos._struct->gm[11] == 0)
	{ 
		if(this->gamemaster(lpObj,5) == 1)
		{
		    return;
		}
	}
	else
	{ 
	    if(lpObj->Authority < 2)
		{
		   return;
		}
		else
		{
			if(this->gamemaster(lpObj,5) == 1)
			{
				return;
			}
	    }
	}

	lpObj->Money += _iniciar_comandos._struct->money[11];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//limpar inventario
void _comandos::_comando_limpar(LPOBJ lpObj)
{
	if(_iniciar_comandos._struct->ativar[12] == 0)
	{
		_mensagem(lpObj->m_Index,52,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[12])
	{
		_mensagem(lpObj->m_Index,53,_iniciar_comandos._struct->level[12],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[12])
	{
		_mensagem(lpObj->m_Index,54,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[12])
	{
		_mensagem(lpObj->m_Index,55,_iniciar_comandos._struct->money[12],0,0);
		return;
	}

	for(unsigned p = 12; p < 76; p++)
	{
		gObjInventoryDeleteItem(lpObj->m_Index,p);
		GCInventoryItemDeleteSend(lpObj->m_Index,p,1);
	}

	lpObj->Money -= _iniciar_comandos._struct->money[12];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//bau
void _comandos::_comando_ware(LPOBJ lpObj, char * String)
{
	if(_iniciar_comandos._struct->ativar[13] == 0)
	{
		_mensagem(lpObj->m_Index,56,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[13])
	{
		_mensagem(lpObj->m_Index,57,_iniciar_comandos._struct->level[13],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[13])
	{
		_mensagem(lpObj->m_Index,58,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[13])
	{
		_mensagem(lpObj->m_Index,59,_iniciar_comandos._struct->money[13],0,0);
		return;
	}

	sscanf(String,"%d",&_iniciar_comandos._bau);

	if(_iniciar_comandos._bau > _iniciar_comandos._struct->maxbau[lpObj->vip])
	{
		_mensagem(lpObj->m_Index,62,_iniciar_comandos._struct->maxbau[lpObj->vip],0,0);
		return;
	}

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)mudarbau,(void*)lpObj->m_Index,0,0);

	lpObj->Money -= _iniciar_comandos._struct->money[13];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//classe
void _comandos::_comando_classe(LPOBJ lpObj, char * String, char token, char classe)
{
	if(_iniciar_comandos._struct->ativar[token] == 0)
	{
		_mensagem(lpObj->m_Index,63,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[token])
	{
		_mensagem(lpObj->m_Index,64,_iniciar_comandos._struct->level[token],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[token])
	{
		_mensagem(lpObj->m_Index,65,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[token])
	{
		_mensagem(lpObj->m_Index,66,_iniciar_comandos._struct->money[token],0,0);
		return;
	}

	for(int i = 0; i < 11; i++)
	{
		if(lpObj->pInventory[i].m_Type > 0)
		{
			_mensagem(lpObj->m_Index,67,0,0,0);
			return;
		}
	}

	if(lpObj->m_IfState.use == 1)
	{
		_mensagem(lpObj->m_Index,68,0,0,0);
		return;
	}

	lpObj->DbClass    = classe;
	lpObj->CloseCount = 1;
	lpObj->CloseType  = 1;
	lpObj->Money -= _iniciar_comandos._struct->money[token];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//infor
void _comandos::_comando_infor(LPOBJ lpObj)
{

	int reset = _subC.subCSQL_retornar(lpObj->Name,_subC.subCSQLcoluna_retornar_r,_subC.subCSQLtabela_r,_subC.subCSQLcoluna_id_r,lpObj->reset,"*");

	if(_iniciar_comandos._struct->ativar[19] == 0)
	{
		_mensagem(lpObj->m_Index,69,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[19])
	{
		_mensagem(lpObj->m_Index,70,_iniciar_comandos._struct->level[19],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[19])
	{
		_mensagem(lpObj->m_Index,71,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[19])
	{
		_mensagem(lpObj->m_Index,72,_iniciar_comandos._struct->money[19],0,0);
		return;
	}

	char mensagem[500];
	wsprintf(mensagem,"nome: %s  -  level: %d  -  zen: %d  -  vip: %d  -  resets: %d  -  experiencia: %d  -  experiencia obtida: %d  -  pontos: %d",
	lpObj->Name,lpObj->Level,lpObj->Money,lpObj->vip,reset,_experiencia.experiencia[lpObj->vip],lpObj->Experience,lpObj->LevelUpPoint);
	MakeBarMsg(lpObj->m_Index,mensagem,0,255,100);
	lpObj->Money -= _iniciar_comandos._struct->money[19];
	GCMoneySend(lpObj->m_Index,lpObj->Money);
}

//----------------------------------------------------------------------------------------//
//OpenWare
void _comandos::_comando_openware(LPOBJ lpObj)
{
	if(_iniciar_comandos._struct->ativar[22] == 0)
	{
		_mensagem(lpObj->m_Index,73,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[22])
	{
		_mensagem(lpObj->m_Index,74,_iniciar_comandos._struct->level[22],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[22])
	{
		_mensagem(lpObj->m_Index,75,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[22])
	{
		_mensagem(lpObj->m_Index,76,_iniciar_comandos._struct->money[22],0,0);
		return;
	}

	if(lpObj->pTransaction == 1)
	{
		MsgOutput(lpObj->m_Index,"%s Feche o Trade Para Usar o Comando!",lpObj->Name);		
		return;
	}

	if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 7 )
	{
		MsgOutput(lpObj->m_Index,"%s Feche o ChaosBox Para Usar o Comando!",lpObj->Name);	
		return;
	}

	if(lpObj->m_ReqWarehouseOpen != 0  || lpObj->WarehouseSave != 0 )
	{
		MsgOutput(lpObj->m_Index,"%s Feche o Baú Para Usar o Comando!",lpObj->Name);
		return;
	}


	lpObj->m_ReqWarehouseOpen = 1;
	lpObj->m_IfState.type = 6;
	lpObj->m_IfState.use = 1;
	lpObj->m_IfState.state = 0;
	lpObj->WarehouseSave = TRUE;
	lpObj->WarehouseCount = 0;
	lpObj->Money -= _iniciar_comandos._struct->money[22];
	GDGetWarehouseList(lpObj->m_Index,lpObj->AccountID);
	MsgOutput(lpObj->m_Index,"%s Baú aberto com sucesso ",lpObj->Name);
}

//----------------------------------------------------------------------------------------//
//off trade
void _comandos::_comando_offtrade(LPOBJ lpObj)
{
	if(_iniciar_comandos._struct->ativar[20] == 0)
	{
		_mensagem(lpObj->m_Index,73,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[20])
	{
		_mensagem(lpObj->m_Index,74,_iniciar_comandos._struct->level[20],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[20])
	{
		_mensagem(lpObj->m_Index,75,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[20])
	{
		_mensagem(lpObj->m_Index,76,_iniciar_comandos._struct->money[20],0,0);
		return;
	}

	GCServerMsgStringSend("comando desabilitado por trazer problemas",lpObj->m_Index,0);

}

//----------------------------------------------------------------------------------------//
//reset
void _comandos::_comando_reset(LPOBJ lpObj)
{
	_reset_iniciar._reset_init(lpObj,0,1);
}

//----------------------------------------------------------------------------------------//
//Auto reset
void _comandos::_comando_autoreset(LPOBJ lpObj)
{
	
	if(_iniciar_comandos._struct->ativar[24] == 0)
	{
		_mensagem(lpObj->m_Index,73,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[24])
	{
		_mensagem(lpObj->m_Index,74,_iniciar_comandos._struct->level[24],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[24])
	{
		_mensagem(lpObj->m_Index,75,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[24])
	{
		_mensagem(lpObj->m_Index,76,_iniciar_comandos._struct->money[24],0,0);
		return;
	}

	if(lpObj->autoreset == true)
	{
		lpObj->autoreset = false;
		MsgOutput(lpObj->m_Index,"%s Desativou o Auto reset!",lpObj->Name);	
		return;
	}

	lpObj->autoreset = true;
	MsgOutput(lpObj->m_Index,"%s Ativou o Auto reset!",lpObj->Name);	
}

//----------------------------------------------------------------------------------------//
//status add
bool _comandos::_comando_status(LPOBJ lpObj, char switchs, int pontos)
{
    PMSG_USE_STAT_FRUIT pResult;
	PHeadSetB((LPBYTE)&pResult,0x2C,sizeof(pResult));

	if(lpObj->LevelUpPoint < pontos || pontos < 1)
	{
		_mensagem(lpObj->m_Index,21,lpObj->LevelUpPoint,0,0);
		return TRUE;
	}

	for(int i = 0; i < _maximo.variavel; i++)
	{
		if(lpObj->DbClass == _maximo.pontos[i]._classe)
		{
	        switch(switchs)
	        {
	        case 0: //força
			  if(lpObj->Strength + pontos > _maximo.pontos[i]._forca)
			  {
				  _mensagem(lpObj->m_Index,0,_maximo.pontos[i]._forca,0,0);
				  return TRUE;
			  }
			  else
			  {
		          pResult.result = 0;
		          pResult.btStatValue = pontos;
		          pResult.btFruitType = 3;
		          DataSend(lpObj->m_Index,(BYTE *)&pResult,pResult.h.size);
	              lpObj->Strength += pontos;
			  }
		    break;
	        case 1: //agilidade
			  if(lpObj->Dexterity + pontos > _maximo.pontos[i]._agilidade)
			  {
				  _mensagem(lpObj->m_Index,1,_maximo.pontos[i]._agilidade,0,0);
				  return TRUE;
			  }
			  else
			  {
		          pResult.result = 0;
		          pResult.btStatValue = pontos;
		          pResult.btFruitType = 2;
		          DataSend(lpObj->m_Index,(BYTE *)&pResult,pResult.h.size);
	              lpObj->Dexterity += pontos;
			  }
		    break;
	        case 2: //vitalidade
			  if(lpObj->Vitality + pontos > _maximo.pontos[i]._vitalidade)
			  {
				  _mensagem(lpObj->m_Index,2,_maximo.pontos[i]._vitalidade,0,0);
				  return TRUE;
			  }
			  else
			  {
		          pResult.result = 0;
		          pResult.btStatValue = pontos;
		          pResult.btFruitType = 1;
		          DataSend(lpObj->m_Index,(BYTE *)&pResult,pResult.h.size);
	              lpObj->Vitality += pontos;
				  lpObj->MaxLife += lpObj->VitalityToLife * pontos;
			  }
		    break;
	        case 3: //energia
			  if(lpObj->Energy + pontos > _maximo.pontos[i]._energia)
			  {
				  _mensagem(lpObj->m_Index,3,_maximo.pontos[i]._energia,0,0);
				  return TRUE;
			  }
			  else
			  {
		          pResult.result = 0;
		          pResult.btStatValue = pontos;
		          pResult.btFruitType = 0;
		          DataSend(lpObj->m_Index,(BYTE *)&pResult,pResult.h.size);
	              lpObj->Energy += pontos;
				  lpObj->MaxMana += lpObj->EnergyToMana * pontos;
			  }
		    break;
	        case 4: //comando
			  if(lpObj->DbClass == 64)
			  {
			     if(lpObj->Leadership + pontos > _maximo.pontos[i]._comando)
			     {
				   _mensagem(lpObj->m_Index,1,_maximo.pontos[i]._comando,0,0);
				   return TRUE;
			     }
		          pResult.result = 0;
		          pResult.btStatValue = pontos;
		          pResult.btFruitType = 4;
		          DataSend(lpObj->m_Index,(BYTE *)&pResult,pResult.h.size);
	              lpObj->Leadership += pontos;
			  }
			  else
			  {
				  return TRUE;
			  }
		    break;
			}
		}
	}

	lpObj->LevelUpPoint -= pontos;
	gClient.GSPointsUP(lpObj);
	gObjCalCharacter(lpObj->m_Index);
	GCReFillSend(lpObj->m_Index,lpObj->MaxLife + lpObj->AddLife,0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
    gObjSetBP(lpObj->m_Index);
	GCManaSend(lpObj->m_Index,lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
	return FALSE;
}

//----------------------------------------------------------------------------------------//
//status readd
void _comandos::_comando_readd(LPOBJ lpObj)
{
	if(_iniciar_comandos._struct->ativar[23] == 0)
	{
		_mensagem(lpObj->m_Index,73,0,0,0);
		return;
	}
    if(lpObj->Level < _iniciar_comandos._struct->level[23])
	{
		_mensagem(lpObj->m_Index,74,_iniciar_comandos._struct->level[23],0,0);
		return;
	}
	if(lpObj->vip < _iniciar_comandos._struct->vip[23])
	{
		_mensagem(lpObj->m_Index,75,0,0,0);
	    return;
	}
    if(lpObj->Money < _iniciar_comandos._struct->money[23])
	{
		_mensagem(lpObj->m_Index,76,_iniciar_comandos._struct->money[23],0,0);
		return;
	}

	PMSG_USE_STAT_FRUIT pResult;
	PHeadSetB((LPBYTE)&pResult,0x2C,sizeof(pResult));

	//Adiciona os pontos ao LevelUpPoints
	lpObj->LevelUpPoint += (lpObj->Strength + lpObj->Dexterity + lpObj->Vitality + lpObj->Energy + lpObj->Leadership - 120);
	gClient.GSPointsUP(lpObj);
	
	//Remove o status
	//força
	pResult.result = 3;
	pResult.btStatValue = lpObj->Strength;
	pResult.btFruitType = 3;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Strength -= lpObj->Strength;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 3;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Strength += 30;
	// agilidade
	pResult.result = 3;
	pResult.btStatValue = lpObj->Dexterity;
	pResult.btFruitType = 2;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Dexterity -= lpObj->Dexterity;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 2;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Dexterity += 30;
	// vitalidade
	pResult.result = 3;
	pResult.btStatValue = lpObj->Vitality;
	pResult.btFruitType = 1;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Vitality -= lpObj->Vitality;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 1;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Vitality += 30;
	lpObj->MaxLife = lpObj->VitalityToLife * 30;
	// energia
	pResult.result = 3;
	pResult.btStatValue = lpObj->Energy;
	pResult.btFruitType = 0;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Energy -= lpObj->Energy;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 0;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Energy += 30;
	lpObj->MaxMana = lpObj->EnergyToMana * 30;
	// comando
	if(lpObj->DbClass == 64)
	{
		pResult.result = 3;
		pResult.btStatValue = lpObj->Leadership;
		pResult.btFruitType = 4;
		DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
		lpObj->Leadership -= lpObj->Leadership;
		pResult.result = 0;
		pResult.btStatValue = 30;
		pResult.btFruitType = 4;
		DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
		lpObj->Leadership += 30;
	}

	gObjCalCharacter(lpObj->m_Index);
	GCReFillSend(lpObj->m_Index,lpObj->MaxLife + lpObj->AddLife,0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);	
	gObjSetBP(lpObj->m_Index);	
	GCManaSend(lpObj->m_Index,lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
	MsgOutput(lpObj->m_Index,"%s Pontos Re-Adicionados!",lpObj->Name);
	LogAddFuncColor(2,"[ ReAdd System] %s Re-Adicionou os Pontos ",lpObj->Name);
	
}

//----------------------------------------------------------------------------------------//
//thread mudar bau
void WINAPI mudarbau(int aIndex)
{

	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	while(true)
	{

		for(int i = 5; i >= 1; i--)
		{

			if(i == 5)
			{
                CGWarehouseUseEnd(aIndex);
		        lpObj->m_IfState.state = 0;
		        lpObj->m_IfState.type  = 0;
		        lpObj->m_IfState.use   = 0;
			}
            
			lpObj->m_ReqWarehouseOpen = true;
			lpObj->LoadWareHouseInfo  = false;
			lpObj->WarehouseSave      = false;
			_mensagem(lpObj->m_Index,60,i,0,0);

			if(i == 3) // muda o bau em 3 segundos
			{
				char _query[100];
                wsprintf(_query,"EXEC lpObj_change_warehouse '%s', %d",lpObj->AccountID,_iniciar_comandos._bau);
	            _iniciar_csql.Execute(_query, &crec);
			}

			if(i == 1)
			{
				_mensagem(lpObj->m_Index,61,_iniciar_comandos._bau,0,0);
				GCLevelUpMsgSend(aIndex,1);
	            lpObj->m_ReqWarehouseOpen = false;
			}

			Sleep(1000);
		}
		break;
	}

	_endthread();
}

//----------------------------------------------------------------------------------------//
//gmsystem
bool _comandos::gamemaster(LPOBJ lpObj, BYTE tipo)
{
	if(lpObj->Authority >= 2)
	{
	   for(int i = 0; i <  _iniciar_comandos.variavelgamemaster; i++)
	   {
		  if(strcmp(lpObj->Name,_iniciar_comandos._struct[i].nome) == 0)
		  {
			 if(_iniciar_comandos._struct[i].comando[tipo] == 0)
			 {
				_mensagem(lpObj->m_Index,84,0,0,0);
				return TRUE;
			 }
			 return FALSE;
		  }
	   }
	}
	else
	{
		return FALSE;
	}

	_mensagem(lpObj->m_Index,85,0,0,0);
	return TRUE;
}

//----------------------------------------------------------------------------------------//
//hook protocolo
void _comandos::_comandos_protocolo(LPBYTE Protocolo, int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[0],strlen(_iniciar_comandos._struct->string[0])))
	{
	  this->_comando_post(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[0]));
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[1],strlen(_iniciar_comandos._struct->string[1])))
	{
	  this->_comando_adicionar(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[1]),0,1);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[2],strlen(_iniciar_comandos._struct->string[2])))
	{
	  this->_comando_adicionar(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[2]),1,2);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[3],strlen(_iniciar_comandos._struct->string[3])))
	{
	  this->_comando_adicionar(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[3]),2,3);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[4],strlen(_iniciar_comandos._struct->string[4])))
	{
	  this->_comando_adicionar(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[4]),3,4);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[5],strlen(_iniciar_comandos._struct->string[5])))
	{
	  this->_comando_adicionar(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[5]),4,5);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[6],strlen(_iniciar_comandos._struct->string[6])))
	{
	  this->_comando_pkclear(lpObj,0,0);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[7],strlen(_iniciar_comandos._struct->string[7])))
	{
	  this->_comando_drop(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[7]));
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[8],strlen(_iniciar_comandos._struct->string[8])))
	{
	  this->_comando_skin(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[8]));
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[9],strlen(_iniciar_comandos._struct->string[9])))
	{
	  this->_comando_reload(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[9]));
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[10],strlen(_iniciar_comandos._struct->string[10])))
	{
	  this->_comando_move(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[10]));
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[11],strlen(_iniciar_comandos._struct->string[11])))
	{
	  this->_comando_money(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[12],strlen(_iniciar_comandos._struct->string[12])))
	{
	  this->_comando_limpar(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[13],strlen(_iniciar_comandos._struct->string[13])))
	{
	  this->_comando_ware(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[13]));
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[14],strlen(_iniciar_comandos._struct->string[14])))
	{
	  this->_comando_classe(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[14]),14,1);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[15],strlen(_iniciar_comandos._struct->string[15])))
	{
	  this->_comando_classe(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[15]),15,17);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[16],strlen(_iniciar_comandos._struct->string[16])))
	{
	  this->_comando_classe(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[16]),16,33);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[17],strlen(_iniciar_comandos._struct->string[17])))
	{
	  this->_comando_classe(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[17]),17,48);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[18],strlen(_iniciar_comandos._struct->string[18])))
	{
	  this->_comando_classe(lpObj,(char*)Protocolo+13+strlen(_iniciar_comandos._struct->string[18]),18,64);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[19],strlen(_iniciar_comandos._struct->string[19])))
	{
	  this->_comando_infor(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[20],strlen(_iniciar_comandos._struct->string[20])))
	{
	  this->_comando_offtrade(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[21],strlen(_iniciar_comandos._struct->string[21])))
	{
	  this->_comando_reset(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[22],strlen(_iniciar_comandos._struct->string[22])))
	{
	  this->_comando_openware(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[23],strlen(_iniciar_comandos._struct->string[23])))
	{
	  this->_comando_readd(lpObj);
	}
	if(!memicmp(&Protocolo[13],_iniciar_comandos._struct->string[24],strlen(_iniciar_comandos._struct->string[24])))
	{
	  this->_comando_autoreset(lpObj);
	}

}