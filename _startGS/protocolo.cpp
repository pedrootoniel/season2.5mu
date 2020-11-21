#include "stdafx.h"

unsigned char const fcaTable[]={0xFC, 0xCF, 0xAB};

BYTE Fixar_ProtocolCore(BYTE aRecv)
{
	switch(aRecv)
	{
	case PROTOCOL_WALK:		return WALK;	 break; // - Andar
	case PROTOCOL_BEATTACK: return BEATTACK; break; // - Skill
	case PROTOCOL_POSITION: return POSITION; break; // - Dano
	case PROTOCOL_ATTACK:	return ATTACK;	 break; // - Ataque
	}
	return aRecv;

}

BYTE Fixar_ProtocolSend(BYTE aRecv)
{	
	switch(aRecv)
	{
	case WALK:		return PROTOCOL_WALK;		break; // - Andar
	//case BEATTACK: return PROTOCOL_BEATTACK;	break; // - Skill, Não é necessário fixar!
	case POSITION:	return PROTOCOL_POSITION;	break; // - Dano
	case ATTACK:	return PROTOCOL_ATTACK;		break; // - Ataque
	}
	return aRecv;

}

void MiniXor(unsigned char*Buff,int Len)
{
	for(int i=0;i<Len;i++)
		Buff[i]=Buff[i]^fcaTable[i%3];
}

void _ProtocolCore	(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)
{
	if(aRecv[0] == 0xC1)
	{
		BYTE bFix = Fixar_ProtocolCore(aRecv[2]);
		aRecv[2] = bFix;
		protoNum = bFix;
	}

	//----------- OBJECTSTRUCT
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	//----------- case
	switch(protoNum)
	{
	case 0x00:
		_iniciar_comandos._comandos_protocolo(aRecv,aIndex);
		cmds.ChatProto(aRecv,aIndex);
		break;
	case 0x03:
		_ConnectGame(lpObj);
		gObjPlayerLoad(aIndex);
		break;
	case 0x1E:
		FixSkillsNoWeapor(aRecv,aIndex);
		break;
	case 0x23:
		if(CGItemDropRequestEx((PMSG_ITEMTHROW *)aRecv,aIndex))
		{
				return;
		}
		if(CGItemDropScrollRequestEx((PMSG_ITEMTHROW *)aRecv,aIndex))
		{
				return;
		}
	break;
	case 0x26:			
		UseItemRecv((PMSG_USEITEM*)aRecv,aIndex);
		break;
	case 0xBC:
		if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 1)
		{
			_mensagem(aIndex,10,0,0,0);
			return;
		}
		break;
		//wolf conexão vip
	case 0xF1:
		OFFTrade.OffTradeLogin(aIndex,aRecv);
		if(_subC.subCSQLativarvip == 1)
		{
			if(aRecv[3] == 0x01)
			{
				char szQuery[255];
				unsigned char szLogin[11] = {0};
				CRecordSet Rec;
				Rec.bThrowErrors = false;
				memset(&szQuery[0], 0x00, 255);
				memcpy(&szLogin[0], &aRecv[4], 10);
				MiniXor((unsigned char*)&szLogin[0], 10);
				SQLSyntaxCheckConvert((char*)&szLogin[0]);
				wsprintf(szQuery,_subC.subCSQLconexao_vip,szLogin);
				if(!_iniciar_csql.Execute(szQuery, &Rec))
				{
					return;
				}
				else
				{
					if(Rec.RowCount > 0)
					{
					}
					else
					{
						unsigned char szBuff[5] = {0xC1, 0x05, 0xF1, 0x01, 0x0B};
						DataSend(aIndex,(unsigned char*)&szBuff[0], (BYTE)szBuff[1]);
						return;
					}
				}
				Rec.Close();
			}
		}
		break;
	case 0xF3:
		{
			PMSG_DEFAULT2 * lpDef = (PMSG_DEFAULT2 *)aRecv;

			switch(lpDef->subcode)
			{
			case 0x03:
				gObjPlayerDataLoad((PMSG_CHARMAPJOIN *)aRecv,aIndex);
				break;
			}
		}
		break;
	}

	//----------- retorna para o protocolo original	
	ProtocolCore(protoNum, aRecv, aLen, aIndex, Encrypt, serial);
}

bool DataSend_Hook(int aIndex, PBYTE tpProtocol, DWORD ProtocolLen)
{
	if(tpProtocol[0] == 0xC1) tpProtocol[2] = Fixar_ProtocolSend(tpProtocol[2]);
	return DataSend(aIndex, tpProtocol, ProtocolLen);
}

void _ConnectGame(LPOBJ lpObj)
{
	//----------- Sistema do Auto Reset
	lpObj->autoreset = false;

	//----------- seleciona a tabela vip e retorna o valor
	lpObj->vip = _subC.subCSQL_retornar(lpObj->AccountID,_subC.subCSQLcoluna_retornar,_subC.subCSQLtabela,_subC.subCSQLcoluna_id,lpObj->vip,"*");

	//----------- connect notice por indetificação vip
	char _mensagem[255];
	wsprintf(_mensagem,iniciar_dll.iniciar_notice[lpObj->vip],lpObj->Name);
	GCServerMsgStringSend(_mensagem,lpObj->m_Index,0);

	if(subCheckConnect == true)
	{
		GCServerMsgStringSend("aguarde a reconexão com o banco de dados",lpObj->m_Index,0);
		GCServerMsgStringSend("seu personagem sera relogado até retorne a conexão",lpObj->m_Index,0);
		subCheckConnect = false;
		lpObj->CloseType  = 1;
		lpObj->CloseCount = 5;
	}

	if(_vip.vip[0] == 1)
	{

		if(_vip.vip[1] >= 1)
		{
			if(lpObj->vip < _vip.vip[1])
			{
				GCServerMsgStringSend("Sua Conta não possui previlegios para acessar a Sala",lpObj->m_Index,0);
				lpObj->CloseType  = 2;
				lpObj->CloseCount = 5;

			}
		}
	}
}

void gObjPlayerLoad(int aIndex)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);
	/* */
	gClient.GSMixLevel(player);
	/* */
	gClient.GSPointsUP(player);
	/* */
	gClient.GSCalChart(player);
	/* */
	PMSG_NAME n;
	PHeadSetB((LPBYTE)&n, 0xFE, sizeof(n));
	memcpy(n.name, player->Name, sizeof(n.name));
	DataSend(aIndex,(unsigned char *)&n,n.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s",n.name);

	if(player->vip > 0)
	{
		player->m_ViewSkillState |= 0x8000000;
		GCStateInfoSend(player, TRUE, 0x8000000);
		//Effect Seals users VIP
	}
	
	if((player->Authority & 2) == 2 || (player->Authority & 8) == 8 || (player->Authority & 32) == 32)
	{
		player->m_ViewSkillState |= 0x1000000;
		GCStateInfoSend(player, 1, player->m_ViewSkillState);
	}
}

void gObjPlayerDataLoad(PMSG_CHARMAPJOIN * lpRecv, int aIndex)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	PLAYER_INFOR pDataServer;

	PHeadSetB((LPBYTE)&pDataServer, 0xE0, sizeof(pDataServer));

	memcpy(pDataServer.account, player->AccountID, 10);
	memcpy(pDataServer.name, lpRecv->name, 10);
	pDataServer.aIndex = aIndex;

	DataServerSend((BYTE*)&pDataServer, pDataServer.h.size);
}

