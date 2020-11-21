#include "stdafx.h"

void BuxConvert(char* buf, int size)
{
	for (int n = 0; n < size; n++)
	{
		buf[n]^=bBuxCode[n%3];
	}
}

void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
{
	lpBuf[0] =0xC1; // Packets
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}

void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1)=dwMyFuncOffset-(dwJmpOffset+5);
}

void SetDWord(DWORD dwOffset,DWORD btValue)
{
	*(PDWORD)(dwOffset) = btValue;
}

void HookJump(DWORD Offset, LPVOID Function)
{
	*(BYTE*) (Offset) = 0xE9;
	*(DWORD*) (Offset + 1) = (DWORD) Function - (Offset + 5);
}

void hook_proc(DWORD DToffset, DWORD DTfunc)
{
	*(BYTE*)  (DToffset)   = 0xE9;
	*(DWORD*) (DToffset+1) = (DWORD)(DTfunc)-(DToffset+5);
}

void SetByte(DWORD NewOffset,BYTE NewByte)
{
	*(BYTE*)(NewOffset) = NewByte;
}


void SetJMP(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0xEB;
}

void SetNop(DWORD dwOffset, int Size)
{
	for(int n=0; n < Size; n++){
	*(BYTE*)(dwOffset+n) = 0x90;
	}
}

void SetRetn(DWORD dwOffset)
{
	*(BYTE*)(dwOffset) = 0xC3;
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

void SetJE(DWORD NewOffset)
{
	*(BYTE*)(NewOffset) = 0x74;
}

void HookFunc(DWORD offset, DWORD funcao)
{
	*(BYTE*)  (offset)  = 0xE9;
	*(DWORD*)(offset+1) = (DWORD)(funcao)-(offset+5);
}

void DeleteItem(int aIndex, int Slot)
{		
	 gObjInventoryDeleteItem(aIndex, Slot);
	 GCInventoryItemDeleteSend(aIndex, Slot, 1);
}

int gObjGetItemCountInInventory(int aIndex, int ItemID,int ItemLevel)
{
	if(aIndex >= OBJECT_MAX)
		return 0;

	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*) OBJECT_POINTER(aIndex);
	int Count = 0;
	for (int i = 0; i < 76; i++)
	{
		if (gObj->pInventory[i].m_Type == ItemID && gObj->pInventory[i].m_Level == ItemLevel)
			Count++;
	}
	return Count;
}

int gObjDeleteItemsCount(int gObjId, short Type, short Level, int Count)
{
	if(gObjId >= OBJECT_MAX)
		return 0;

	int count = 0;
	for(int i = 0; i < 76; i++)
	{
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(gObjId);
		if(gObj->pInventory[i].m_Type == Type && gObj->pInventory[i].m_Level == Level)
		{
			gObjInventoryDeleteItem(gObjId, i);
			GCInventoryItemDeleteSend(gObjId, i, 1);
			count++;

			if(Count == count)
				break;
		}
	}
	return count;
}

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] =0xC1;
	lpBuf[1] =size;
	lpBuf[2] =head;
}

void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size)
{
	lpBuf[0] =0xC3;
	lpBuf[1] =size;
	lpBuf[2] =head;
	lpBuf[3] =sub;
}

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

void CheckPet(LPOBJ lpObj)
{
	short Type = lpObj->pInventory[8].m_Type;

	if(!((Type >= ITEMGET(13,0) && Type <= ITEMGET(13, 5)) || Type == ITEMGET(13, 37)))
	{
		GCInventoryItemDeleteSend(lpObj->m_Index, 8, 0);
	}
}

void GCGuildWarRequestResult(LPSTR GuildName, int aIndex, int type)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

    if(lpObj->m_IfState.use == 1 && lpObj->m_IfState.type == 1)
	{
		GCServerMsgStringSend("necessário fechar o trade antes de pedir war",aIndex,0);
		return;
	}

	WarRequestResult(GuildName,aIndex,type);
}

void Efeito_de_Quest(LPOBJ lpObj)
{
	BYTE btClass = (lpObj->Class * 32) + 24;
	GCSendQuestPrize(lpObj->m_Index, 0xCC, btClass);
	gObjViewportListProtocolCreate(lpObj);
}

long int gObjGetInt(int aIndex,int gObjParam)
{
	return *(long int*)(aIndex * OBJECT_SIZE + OBJECT_BASE + gObjParam);
}

void gObjWrite(int aIndex,int gObjParam,long int Value)
{
	*(long int*)(aIndex * OBJECT_SIZE + OBJECT_BASE + gObjParam) = Value;
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

void iniciar_nopear(DWORD off, int quantidade)
{
	for(int i = 0; i < quantidade; i++)
	{
		*(BYTE*)  (off+i)   = 0x90;
	}
}

void HookNop(DWORD offset, int x)
{
	for(int i = 0; i < x; i++)
	{
		*(BYTE*)(offset+i) = 0x90;
	}
}

void StartAddress(LPVOID lpThreadParameter)
{
	HANDLE v1;
	HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);
		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);
		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}

bool FileExists(char * name)
{
	if(CreateFile(name,0,0,0,OPEN_EXISTING,0,0) == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

void gObjSecondProcEx()
{
	gObjSecondProc();
}

DWORD GetItemDataAddr(LPOBJ pObj)
{
	DWORD  pItemDataAddr;

	_asm
	{
		push eax
		push edx
		MOV EDX,pObj
		MOV EAX,DWORD PTR DS:[EDX+0xCAC]
		mov pItemDataAddr,eax
		pop edx
		pop eax
	}
	return pItemDataAddr;
}

void InterfaceTimeCheck_(LPOBJ lpObj) //OK
{
	Premio_Hora_Online(lpObj);

	gObjInterfaceTimeCheck(lpObj);

	if (lpObj->Connected == 3)
	{
		if (lpObj->Type == 1)
		{
			GCNewHealthBarSend(lpObj); 
		}
	}

}

void GCNewHealthBarSend(LPOBJ lpObj) //OK  
{
	BYTE Buffer[1500];

	PMSG_HEALTHBAR Result;
	PMSG_HEALTHBAR_INFO Info;

	Result.h.c = 0xC2;
	Result.h.head = 0xF3;
	Result.Code = 0xE2;
	Result.Count = 0;
	
	int Size = sizeof(Result);

	for (int i = 0; i < 75; i++)
	{
		if (lpObj->VpPlayer[i].state != 1 && lpObj->VpPlayer[i].state != 2)
		{
			continue;
		}

		if (lpObj->VpPlayer[i].type != 2)
		{
			continue;
		}

		if (OBJMAX_RANGE(lpObj->VpPlayer[i].number) == 0)
		{
			continue;
		}

		LPOBJ lpTargetObj = (LPOBJ)OBJECT_POINTER(lpObj->VpPlayer[i].number);  

		if (lpTargetObj->Class == 200 || lpTargetObj->Live == 0 || lpTargetObj->m_State != 2 || BC_MAP_RANGE(lpTargetObj->MapNumber) != 0)
		{
			continue;
		}

		Info.Index = lpObj->VpPlayer[i].number;
		Info.Rate = (BYTE)((lpTargetObj->Life * 100) / (lpTargetObj->MaxLife + lpTargetObj->AddLife));

		memcpy(&Buffer[Size], &Info, sizeof(Info));
		Size += sizeof(Info);
		Result.Count++;
	}

	Result.h.size[0] = HIBYTE(Size);
	Result.h.size[1] = LOBYTE(Size);

	memcpy(Buffer, &Result, sizeof(Result));
	DataSend(lpObj->m_Index, Buffer, Size);
}

bool IsBadFileLine(char *FileLine, int &Flag)
{
	if(Flag == 0)
	{
		if(isdigit(FileLine[0]))
		{
			Flag = FileLine[0] - 48;
			return true;
		}
	}
	else if(Flag < 0 || Flag > 9)
	{
		Flag = 0;
	}

	if(!strncmp(FileLine, "end", 3))
	{
		Flag = 0;
		return true;
	}

	if(FileLine[0] == '/' || FileLine[0] == '\n')
		return true;

	for(UINT i = 0; i < strlen(FileLine); i++)
	{
		if(isalnum(FileLine[i]))
			return false;
	}
	return true;
}

int GenExcOpt(int amount)
{
	// User input errors
	if (amount > 6) amount = 6;
	if (amount < 1) amount = 1;

	int opt_db[6]  = {1, 2, 4, 8, 16, 32};
	int exc = 0;

	std::random_shuffle(opt_db, opt_db + 6);

	for(int n=0; n < amount; n++)
		exc += opt_db[n];

	return exc;
}

void AllServerAnnounce(char *message, ...)
{
	char szBuffer[512] = "";
	va_list pArguments;

	va_start(pArguments, message);
	vsprintf(&szBuffer[0], message, pArguments);
	va_end(pArguments);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if(gObjIsConnected(i) == 1)
		{
			GCServerMsgStringSend(&szBuffer[0], i, 0);
		}
	}
}


bool MygEventMonsterItemDrop(OBJECTSTRUCT* gObj, OBJECTSTRUCT* gTargetObj)
{
	// Multi Drop System
	if (gObj->Class == 54 || gObj->Class == 81 || gObj->Class == 83 || gObj->Class == 80 || gObj->Class == 82)	// Golden Soldier,Vepar,Wheel
	{
		int MaxHitUser = gObjMonsterTopHitDamageUser(gObj);
		unsigned int Rena = 14 * 512 + 21;

		// Drop
		ItemSerialCreateSend(gObj->m_Index,gObj->MapNumber,gObj->X-1,gObj->Y,Rena,0,0,0,0,0,MaxHitUser,0,0);

		// Log
		LogAddFuncColor(2,"[MultiDrop] (%s) Killed Golden Soldier (%d)!",gTargetObj->Name,gObj->Class);
		return true;
	}

	// Zen Drop
	if(gObj->Money > 0)
    {
		DWORD SubMoney = 0;

		if(gObj->Level > 10	&& gObj->Level <= 99)
		{
			SubMoney = (DWORD)(gObj->Money) / 100;
		}
		else if(gObj->Level >= 100 && gObj->Level <= 199)
		{
			SubMoney = (DWORD)(gObj->Money * 2) / 100;
		}
		else if(gObj->Level > 200)
		{
			SubMoney = (DWORD)(gObj->Money * 3) / 100;
		}

		gObj->Money = (gObj->Money - SubMoney) * 0.1;
	}

	return gEventMonsterItemDrop(gObj,gTargetObj);
}

void GCFireworkSend(int aIndex,int X,int Y,int Amount)
{
	BYTE Packet[7] = {0xC1,0x07,0xF3,0x40,0x00,X,Y};

	for (int i = 0; i < Amount; i++)
	{
		DataSend(aIndex,Packet,Packet[1]);
	}
}

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