#include "stdafx.h"


_BALANCE _balance;

void _BALANCE::iniciar_balance()
{
	// Balance Classe Wizard
	_balance.balance[0] = iniciar_dll.iniciar_getprivateint("Balance","Balance DWvsDW",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[1] = iniciar_dll.iniciar_getprivateint("Balance","Balance DWvsDK",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[2] = iniciar_dll.iniciar_getprivateint("Balance","Balance DWvsELF", 100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[3] = iniciar_dll.iniciar_getprivateint("Balance","Balance DWvsMG",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[4] = iniciar_dll.iniciar_getprivateint("Balance","Balance DWvsDL",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");

	// Balance Classe Knight
	_balance.balance[5] = iniciar_dll.iniciar_getprivateint("Balance","Balance DKvsDW",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[6] = iniciar_dll.iniciar_getprivateint("Balance","Balance DKvsDK",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[7] = iniciar_dll.iniciar_getprivateint("Balance","Balance DKvsELF", 100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[8] = iniciar_dll.iniciar_getprivateint("Balance","Balance DKvsMG",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[9] = iniciar_dll.iniciar_getprivateint("Balance","Balance DKvsDL",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");

	// Balance Classe Elf
	_balance.balance[10] = iniciar_dll.iniciar_getprivateint("Balance","Balance ELFvsDW",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[11] = iniciar_dll.iniciar_getprivateint("Balance","Balance ELFvsDK",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[12] = iniciar_dll.iniciar_getprivateint("Balance","Balance ELFvsELF", 100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[13] = iniciar_dll.iniciar_getprivateint("Balance","Balance ELFvsMG",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[14] = iniciar_dll.iniciar_getprivateint("Balance","Balance ELFVsDL",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");

	// Balance Classe Magic Gladiator
	_balance.balance[15] = iniciar_dll.iniciar_getprivateint("Balance","Balance MGvsDW",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[16] = iniciar_dll.iniciar_getprivateint("Balance","Balance MGvsDK",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[17] = iniciar_dll.iniciar_getprivateint("Balance","Balance MGvsELF", 100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[18] = iniciar_dll.iniciar_getprivateint("Balance","Balance MGvsMG",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[19] = iniciar_dll.iniciar_getprivateint("Balance","Balance MGvsDL",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");

	// Balance Classe Dark Lord
	_balance.balance[20] = iniciar_dll.iniciar_getprivateint("Balance","Balance DLvsDW",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[21] = iniciar_dll.iniciar_getprivateint("Balance","Balance DLvsDK",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[22] = iniciar_dll.iniciar_getprivateint("Balance","Balance DLvsELF", 100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[23] = iniciar_dll.iniciar_getprivateint("Balance","Balance DLvsMG",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
	_balance.balance[24] = iniciar_dll.iniciar_getprivateint("Balance","Balance DLvsDL",  100, ".\\configurações\\_player.settings\\_settings.balance.ID");
}

void _BALANCE::Main(LPOBJ lpObj, LPOBJ lpTargetObj, int & AttackDamage)
{
	if(lpObj->Type == OBJ_USER && lpTargetObj->Type == OBJ_USER)
	{
		if(lpObj->Class == CLASS_WIZARD)
		{
			switch(lpTargetObj->Class)
			{  
			case CLASS_WIZARD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage = novoataque + ( novoataque * _balance.balance[0] ) / 100;
				}
				break;
			case CLASS_KNIGHT:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[1] ) / 100;
				}
				break;
			case CLASS_ELF:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[2] ) / 100;
				}
				break;
			case CLASS_MAGUMSA:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[3] ) / 100;
				}
				break;
			case CLASS_DARKLORD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[4] ) / 100;
				}
				break;
			}
		}
		else if(lpObj->Class == CLASS_KNIGHT)
		{

			switch(lpTargetObj->Class)
			{  
			case CLASS_WIZARD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque - ( novoataque * _balance.balance[5] ) / 100;
				}break;
			case CLASS_KNIGHT:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque - ( novoataque * _balance.balance[6] ) / 100;
				}break;
			case CLASS_ELF:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque - ( novoataque * _balance.balance[7] ) / 100;
				}break;
			case CLASS_MAGUMSA:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque - ( novoataque * _balance.balance[8] ) / 100;
				}break;
			case CLASS_DARKLORD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque - ( novoataque * _balance.balance[9] ) / 100;
				}break;
			}
		}
		else if(lpObj->Class == CLASS_ELF)
		{

			switch(lpTargetObj->Class)
			{  
			case CLASS_WIZARD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[10] ) / 100;
				}break;
			case CLASS_KNIGHT:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[11] ) / 100;
				}break;
			case CLASS_ELF:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[12] ) / 100;
				}break;
			case CLASS_MAGUMSA:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[13] ) / 100;
				}break;
			case CLASS_DARKLORD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[14] ) / 100;
				}break;
			}
		}
		else if(lpObj->Class == CLASS_MAGUMSA)
		{

			switch(lpTargetObj->Class)
			{  
			case CLASS_WIZARD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[15] ) / 100;
				}break;
			case CLASS_KNIGHT:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[16] ) / 100;
				}break;
			case CLASS_ELF:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[17] ) / 100;
				}break;
			case CLASS_MAGUMSA:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[18] ) / 100;
				}break;
			case CLASS_DARKLORD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[19] ) / 100;
				}break;
			}
		}
		else if(lpObj->Class == CLASS_DARKLORD)
		{
			switch(lpTargetObj->Class)
			{  
			case CLASS_WIZARD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[20] ) / 100;
				}break;
			case CLASS_KNIGHT:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[21] ) / 100;
				}break;
			case CLASS_ELF:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[22] ) / 100;
				}break;
			case CLASS_MAGUMSA:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[23] ) / 100;
				}break;
			case CLASS_DARKLORD:
				{
					int novoataque = rand() % (lpObj->m_AttackDamageMaxLeft-lpObj->m_AttackDamageMinLeft + 1) + lpObj->m_AttackDamageMinLeft;
					AttackDamage =  novoataque + ( novoataque * _balance.balance[24] ) / 100;
				}break;
			}
		}
	}
}

BOOL _gObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo)
{
	if(lpObj->Type == OBJ_USER)	
	{
		CheckPet (lpObj);
	}

	if(lpTargetObj->Type == OBJ_USER)	
	{
		CheckPet (lpTargetObj);
	}

	if(lpObj->Name == lpTargetObj->Name || lpTargetObj->Name == lpObj->Name)	
	{
		return TRUE;
	}

	if(lpTargetObj->Type == OBJ_USER)
	{
		for(int i = 0; i <  _iniciar_comandos.variavelgamemaster; i++)
		{
			if(strcmp(lpTargetObj->Name, _iniciar_comandos._struct[i].nome) == 0)
			{
				GCDamageSend(lpObj->m_Index, lpTargetObj->m_Index, 0, 0, 0, 0);
				return TRUE;
			}
		}
	}

	_balance.Main(lpObj,lpTargetObj,AttackDamage);


	return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}