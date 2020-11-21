#include "stdafx.h"
//----------------------------------------------------------------------------------------//
//definições
pLogAddFuncColor              LogAddFuncColor             =    (pLogAddFuncColor)0x004B5470;
pProtocolCore                 ProtocolCore                =    (pProtocolCore)0x00432C50;
pProtocolCoreDS               ProtocolCoreDS              =    (pProtocolCoreDS)0x00425EB0;
pGCServerMsgStringSend        GCServerMsgStringSend       =    (pGCServerMsgStringSend)0x00435D70;
pgObjCalcMaxLifePower         gObjCalcMaxLifePower        =    (pgObjCalcMaxLifePower)0x005176A0;
pgObjCalCharacter             gObjCalCharacter            =    (pgObjCalCharacter)0x004D4420;
pgObjSetCharacter             gObjSetCharacter            =    (pgObjSetCharacter)0x004E5240;
pGCStateInfoSend              GCStateInfoSend             =    (pGCStateInfoSend)0x0044D990;
pItemSerialCreateSend         ItemSerialCreateSend        =    (pItemSerialCreateSend)0x0042BA20;
pItemGetNumberMake            ItemGetNumberMake           =    (pItemGetNumberMake)0x00529590;
pgObjMonsterTopHitDamageUser  gObjMonsterTopHitDamageUser =    (pgObjMonsterTopHitDamageUser)0x004154E0;
pgObjMonsterDrop              gObjMonsterDrop             =    (pgObjMonsterDrop)0x0041DA50;
pNpcTalk                      NpcTalk                     =    (pNpcTalk)0x00587EE0;
pChatTargetSend				  ChatTargetSend			  =    (pChatTargetSend)0x004350F0;
pGCLevelUpMsgSend             GCLevelUpMsgSend            =    (pGCLevelUpMsgSend)0x004378A0;
pGCMoneySend                  GCMoneySend                 =    (pGCMoneySend)0x00438570;
pDataSend                     DataSend                    =    (pDataSend)0x0049CCC0;
pGCReFillSend                 GCReFillSend                =    (pGCReFillSend)0x00453280;
pgObjSetBP                    gObjSetBP                   =    (pgObjSetBP)0x004E4F40;
pGCManaSend                   GCManaSend                  =    (pGCManaSend)0x00453330;
pgObjTeleport                 gObjTeleport                =    (pgObjTeleport)0x0050FE30;
pgObjInventoryDeleteItem      gObjInventoryDeleteItem     =    (pgObjInventoryDeleteItem)0x004F7FD0;
pGCInventoryItemDeleteSend    GCInventoryItemDeleteSend   =    (pGCInventoryItemDeleteSend)0x00453420;
pGCKillPlayerExpSend          GCKillPlayerExpSend         =    (pGCKillPlayerExpSend)0x0044CBA0;
pLotteryItemMix               LotteryItemMix              =    (pLotteryItemMix)0x004AF6B0;
pgObjIsConnected              gObjIsConnected             =    (pgObjIsConnected)0x004EBA50;
pDataSend2                    DataSend2                   =    (pDataSend2)0x0049CCC0;
pGCPkLevelSend                GCPkLevelSend               =    (pGCPkLevelSend)0x00437D30;
pgObjViewportList             gObjViewportList            =    (pgObjViewportList)0x00509B00;
pGameMonsterAllCloseAnd       GameMonsterAllCloseAnd      =    (pGameMonsterAllCloseAnd)0x00535B60;
pShopDataLoad                 ShopDataLoad                =    (pShopDataLoad)0x0052D1C0;
pgObjGetIndex                 gObjGetIndex                =    (pgObjGetIndex)0x004EC600;
pCGWarehouseUseEnd            CGWarehouseUseEnd           =    (pCGWarehouseUseEnd)0x0044A240;
pgObjDel                      gObjDel                     =    (pgObjDel)0x004EB4C0;
pgObjCloseSet                 gObjCloseSet                =    (pgObjCloseSet)0x004E2730;
pCGPShopAnsClose              CGPShopAnsClose             =    (pCGPShopAnsClose)0x00443F90;
pGJPUserClose                 GJPUserClose                =    (pGJPUserClose)0x00430F70;
pJGGetCharacterInfo           JGGetCharacterInfo          =    (pJGGetCharacterInfo)0x004299B0;
pGJSetCharacterInfo           GJSetCharacterInfo          =    (pGJSetCharacterInfo)0x0042A4D0;
pGCInventoryItemOneSend       GCInventoryItemOneSend      =    (pGCInventoryItemOneSend)0x00437C60;
pgObjAttack					  gObjAttack				  =    (pgObjAttack)0x004F4A60;
pGCDamageSend                 GCDamageSend                =    (pGCDamageSend)0x0044C9A0;
prCloseClient                 rCloseClient                =    (prCloseClient)0x0049D930;
pResponErrorCloseClient       ResponErrorCloseClient      =    (pResponErrorCloseClient)0x0049DA20;
pgObjAddMonster			      gObjAddMonster			  =    (pgObjAddMonster)0x004E9FC0;
pgObjSetMonster				  gObjSetMonster			  =    (pgObjSetMonster)0x004E8950;
pCGDurationMagicRecv		  CGDurationMagicRecv		  =	   (pCGDurationMagicRecv)0x0044F440;	
//----------------------------------------------------------------------------------------//
//funcão de hookar
void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1)=dwMyFuncOffset-(dwJmpOffset+5);
}
void hook_proc(DWORD DToffset, DWORD DTfunc)
{
	*(BYTE*)  (DToffset)   = 0xE9;
	*(DWORD*) (DToffset+1) = (DWORD)(DTfunc)-(DToffset+5);
}
void SetByte(DWORD dwOffset,BYTE btValue)
{
	*(BYTE*)(dwOffset) = btValue;
}
void SetDWord(DWORD dwOffset,DWORD btValue)
{
	*(PDWORD)(dwOffset) = btValue;
}
void SetJMP(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0xEB;
}
void SetNop(DWORD dwOffset,int Size)
{
	for(int n = 0; n < Size; n++)
	{
		*(BYTE*)(dwOffset+n) = 0x90;
	}
}
void SetCompleteHook(BYTE btHead, DWORD dwOffset, DWORD* dwFunction)
{
	if(btHead != 0xFF)
	{
		*(BYTE*)(dwOffset) = btHead;
	}

	*(DWORD*)(dwOffset+1) = (DWORD)dwFunction - (dwOffset+5);
}
void WriteMemoryInt(DWORD Offset, DWORD bValue, DWORD bValueMax, DWORD OffsetLen)
{
	HANDLE hProc = GetCurrentProcess();
	if(bValue > bValueMax) bValue = bValueMax;
	WriteProcessMemory(hProc, (LPVOID)Offset, &bValue, OffsetLen, NULL);
}
void HookFunc(DWORD offset, DWORD funcao)
{
	*(BYTE*)  (offset)  = 0xE9;
	*(DWORD*)(offset+1) = (DWORD)(funcao)-(offset+5);
}
DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue)
{
	BYTE * lpBuf = new BYTE[wCount];

	memset(lpBuf, btValue, wCount);

	return WriteMemory(dwAddress, (LPVOID)lpBuf, wCount);
}
DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;
	// ----
	btBuf[0]		= cmd;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));
	// ----
	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
}
DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize)
{
    DWORD dwErrorCode   = 0;
    DWORD dwOldProtect  = 0;

    int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);

    if( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }

    memcpy(lpAddress, lpBuf, uSize);

    DWORD dwBytes   = 0;

    iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);

    if ( iRes == 0 )
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }

    return 0x00;
}

//----------------------------------------------------------------------------------------//
//inicializar todos os hooks
void iniciar_hook()
{
	_iniciar_comandos._comandos_config();

	_mensagem_all->_mensagem_load(".\\configurações\\_administrador.settings\\_settings.mensagem.ID");
	//----------- configuração de maximo de pontos
	_maximo.loadfile(".\\configurações\\_player.settings\\_settings.pontos.ID");
	//----------- configuração da experiencia
	_experiencia.iniciar_experiencia();
	//----------- configuração do drops do blood castle
	_blood._iniciar_blood_castle(".\\configurações\\_eventos.settings\\_settings.blood_castle.ID");
	//----------- configuração do drops do chaos castle
	_chaos._iniciar_chaos_castle(".\\configurações\\_eventos.settings\\_settings.chaos_castle.ID");
	//----------- configuração do drops do devil square
	_devil._iniciar_devil_square(".\\configurações\\_eventos.settings\\_settings.devil_square.ID");
	//----------- configuração do drops custom
	_drop._drop_custom_load(".\\configurações\\_administrador.settings\\_settings.drop.ID");
	//----------- configuração do npc talk
	_npc.loadfile(".\\configurações\\_administrador.settings\\_settings.npc.ID");
	//----------- configuração do sistema de reset
	_reset_iniciar._reset_loadfile(".\\configurações\\_administrador.settings\\_settings.reset.ID");
	//----------- hook protocolo
	hook_proc(0x004036AC, (DWORD)(&_ProtocolCore));	
	hook_proc(0x004056FA, (DWORD)(DataSend_Hook));

	//----------- Hook função gObjCalCharacter
	hook_proc(0x00402FE0, (DWORD)(&gObjCalCharacter_Hook));
	//----------- hook função de adicionar pontos
	hook_proc(0x00405010, (DWORD)(&_gObjLevelUpPointAdd));
	hook_proc(0x004066A9, (DWORD)(&gObjGCLevelUpMsgSend));
	//----------- hook função balão do GM
	hook_proc(0x00405C59, (DWORD)(&_gObjSetCharacter));
	//----------- hook função loterry mix
	hook_proc(0x004021CB, (DWORD)(&_LotteryItemMix));
	//----------- hook do sistema de experiencia
	hook_proc(0x004F4E30, (DWORD)(&_experience_hook));                 iniciar_nopear(0x004F4E35, 9);
	hook_proc(0x004F5525, (DWORD)(&_experience_hook_party));           iniciar_nopear(0x004F552A, 9);
	hook_proc(0x004F5662, (DWORD)(&_experience_hook_party_zen));       iniciar_nopear(0x004F5667, 9);
	hook_proc(0x0046B3F9, (DWORD)(&_experience_hook_devil));           iniciar_nopear(0x0046B3FE, 9);
	hook_proc(0x0046BA4E, (DWORD)(&_experience_hook_party_devil));     iniciar_nopear(0x0046BA53, 9);
	hook_proc(0x0046BBA9, (DWORD)(&_experience_hook_party_devil_zen)); iniciar_nopear(0x0046BBAE, 9);
	//----------- hook do sistema de drops dos eventos
	hook_proc(0x00403733, (DWORD)(&_blood_castle_hook));
	//hook_proc(0x00401ED8, (DWORD)(&_chaos_castle_hook));
	hook_proc(0x0046D99A, (DWORD)(&_devil_square_hook)); iniciar_nopear(0x0046D99A+5, 3);
	//----------- hook do sistema de drops custom
	hook_proc(0x0040513C, (DWORD)(&_gObjMonsterDrop));
	//----------- npc reset & pkclear
	hook_proc(0x00406B5E, (DWORD)(&_NpcTalk));
	//----------- objattack
	hook_proc(0x004063FC, (DWORD)(&_gObjAttack));
}

//----------------------------------------------------------------------------------------//
//envio de packets
void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] =0xC1;
	lpBuf[1] =size;
	lpBuf[2] =head;
}

//----------------------------------------------------------------------------------------//
//envio de packets
void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size)
{
	lpBuf[0] =0xC3;
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}

//----------------------------------------------------------------------------------------//
//chat
void ChatSendAlliance(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID)
{ 
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+16;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x40;
	Buffer[14]=0x40;
	strncpy((char*)&Buffer[15],Mensagem,Len);
	DataSend2(PlayerID,(char*)Buffer,Buffer[1]);
}

//----------------------------------------------------------------------------------------//
//chat
void ChatSendGuild(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID)
{ 
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+15;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x40;
	strncpy((char*)&Buffer[14],Mensagem,Len);
	DataSend2(PlayerID,(char*)Buffer,Buffer[1]);
}

//----------------------------------------------------------------------------------------//
//chat
void ChatSendNormal(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID)
{ 
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+14;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	strncpy((char*)&Buffer[13],Mensagem,Len);
	DataSend2(PlayerID,(char*)Buffer,Buffer[1]);
}

//----------------------------------------------------------------------------------------//
//chat
void ChatSendParty(LPCSTR Nome, LPSTR Mensagem, DWORD PlayerID)
{ 
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+15;
	Buffer[2]=0x00;
	strncpy((char*)&Buffer[3],Nome,10);
	Buffer[13]=0x7E;
	strncpy((char*)&Buffer[14],Mensagem,Len);
	DataSend2(PlayerID,(char*)Buffer,Buffer[1]);
}

//----------------------------------------------------------------------------------------//
//chat
void ChatSendWhisper(LPSTR Mensagem, DWORD PlayerID)
{ 
	BYTE Buffer[MAX_C1LEN] = {0};
	BYTE Len=strlen(Mensagem);
	Buffer[0]=0xC1;
	Buffer[1]=Len+14;
	Buffer[2]=0x02;
	strncpy((char*)&Buffer[13],Mensagem,Len);
	DataSend2(PlayerID,(char*)Buffer,Buffer[1]);
}

//----------------------------------------------------------------------------------------//
//mensagem na barra preta
void MakeBarMsg(DWORD PlayerID,LPCTSTR szText, BYTE RGB1, BYTE RGB2, BYTE RGB3)
{
	BYTE buff[MAX_C1LEN-0x0e];
	FillMemory(buff,(MAX_C1LEN-0x0e),0x20);
	BYTE Len=(BYTE)strlen(szText);
	buff[0]=0xC1;
	buff[1]=Len+0x0E;
	buff[2]=0x0D;
	buff[3]=0x0A;
	buff[4]=0x01;
	buff[5]=0x01;
	buff[6]=0x00;
	buff[7]=0x00;
	buff[8]=RGB1; //R
	buff[9]=RGB2; //G
	buff[10]=RGB3;//B
	buff[11]=0xFF;//Transparencia
	buff[12]=0x14;//Velocidade
	strncpy((char*)&buff[0x0d],szText,Len);
	buff[Len+0x0d]=0;
	DataSend2(PlayerID,(LPSTR)buff,buff[1]);
}

//----------------------------------------------------------------------------------------//
//creditos wolf dark team
void CheckPet(LPOBJ lpObj)
{
	short Type = lpObj->pInventory[8].m_Type;

	if(!((Type >= ITEMGET(13,0) && Type <= ITEMGET(13, 5)) || Type == ITEMGET(13, 37)))
	{
		GCInventoryItemDeleteSend(lpObj->m_Index, 8, 0);
	}
}

//----------------------------------------------------------------------------------------//
// FireWorks Effect
void GCFireworkSend(int aIndex,int X,int Y,int Amount)
{
	BYTE Packet[7] = {0xC1,0x07,0xF3,0x40,0x00,X,Y};

	for (int i = 0; i < Amount; i++)
	{
		DataSend(aIndex,Packet,Packet[1]);
	}
}

//----------------------------------------------------------------------------------------//
// Moster Add Function
int MosterAdd(int MobID, int MapID, int CoordX, int CoordY)
{
	short npc = gObjAddMonster(MapID);

	if(npc == -1)
	{
		return -1;
	}

	gObjSetMonster(npc, MobID);

	
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(npc);

	lpObj->Class		 = MobID;
	lpObj->X		     = CoordX;
	lpObj->Y		     = CoordY;
	lpObj->MapNumber	 = MapID;
	lpObj->TX			= lpObj->X;
	lpObj->TY			= lpObj->Y;
	lpObj->m_OldX		= lpObj->X;
	lpObj->m_OldY		= lpObj->Y;

	lpObj->StartX	 = (unsigned char)lpObj->X;
	lpObj->StartY	 = (unsigned char)lpObj->Y;
	
	lpObj->Live = TRUE;
	lpObj->m_State = 1;

	return npc;
}