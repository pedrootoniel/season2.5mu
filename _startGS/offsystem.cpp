#include "stdafx.h"

//==================================================================================================
// Offline Trade System
//==================================================================================================
CRITICAL_SECTION criti;

COFFTrade OFFTrade;
OFFLINETRADE OfflineShop[OBJECT_MAX];

//==========================
// Functions Hook
//==========================
void COFFTrade::Init()
{
	HookThis((DWORD)&CloseClient2Hook,0x004054F7);
	HookThis((DWORD)&CGPShopAnsCloseHook,0x00404174);
	HookThis((DWORD)&ResponErrorCloseClientHook,0x00403CF1);
	HookThis((DWORD)&CloseClientHook,0x00401046);
}

//==========================
// OffTradeLogin Close
//==========================
void COFFTrade::OffTradeLogin(int aIndex,LPBYTE aRecv)
{
	PMSG_IDPASS *lpMsg = (PMSG_IDPASS*)aRecv;

	char AccountID[11];
	AccountID[10] = 0;
	memcpy(AccountID,lpMsg->Id,sizeof(lpMsg->Id));
	BuxConvert(AccountID,10);

	for(int i = OBJECT_MIN; i < OBJECT_MAX; i++)
	{
		if (gObj[i].Connected == 3)
		{
			if (!strcmp(AccountID,gObj[i].AccountID))
			{
				if (OfflineShop[i].IsOffTrade == 1)
				{
					OfflineShop[i].IsOffTrade = 0;
				}

				GJPUserClose(gObj[i].AccountID);
				gObjDel(i);
			}
		}
	}
}

//==========================
// Shop Close
//==========================
void CGPShopAnsCloseHook(int aIndex, BYTE btResult)
{
	if(OfflineShop[aIndex].IsOffTrade)
		gObjDel(aIndex);
	OfflineShop[aIndex].IsOffTrade = 0;
	CGPShopAnsClose(aIndex,btResult);
}

//==========================
// Client Close
//==========================
void CloseClientHook(int aIndex)
{	
	if ( aIndex < 0 || aIndex > OBJECT_MAX-1 )
	{
		return;
	}

	if ( gObj[aIndex].Connected == 0 )
	{	
		return;
	}

	if(OfflineShop[aIndex].IsOffTrade != 0)
	{	
		gObj[aIndex].CheckTick = GetTickCount();
		return; 
	}

	if(gObj->m_socket != INVALID_SOCKET)
	{
		closesocket(gObj[aIndex].m_socket );
		gObj[aIndex].m_socket = INVALID_SOCKET;
	}
}

//==========================
// Error Checker
//==========================
void ResponErrorCloseClientHook(int aIndex)
{	
	if ( aIndex < 0 || aIndex > OBJECT_MAX-1 )
	{	
	}

	if ( gObj[aIndex].Connected == 0 )
	{
		return;
	}

	if(OfflineShop[aIndex].IsOffTrade != 0)
	{	
		gObj[aIndex].CheckTick = GetTickCount();
		return; 
	}
	closesocket(gObj->m_socket);
	gObj[aIndex].m_socket = INVALID_SOCKET;

	if(gObj[aIndex].m_socket == INVALID_SOCKET )
	{
	}	
	if(gObj[aIndex].m_socket != INVALID_SOCKET)
	{
		gObjDel(aIndex);
	}
}

//==========================
// Client Close 2
//==========================
void CloseClient2Hook(_PER_SOCKET_CONTEXT * lpPerSocketContext, int result)
{
	int index = -1;
	index = lpPerSocketContext->nIndex ;    

	if ( index >= OBJECT_MIN && index < OBJECT_MAX )
	{	
		OBJECTSTRUCT *gObj = (OBJECTSTRUCT*) OBJECT_POINTER(index);
		if(OfflineShop[index].IsOffTrade != 0)
		{	
			gObj->CheckTick = GetTickCount();
			return; 
		}

		if ( gObj->m_socket != INVALID_SOCKET )
		{
			if (closesocket(gObj->m_socket) == -1 )
			{
				if (WSAGetLastError() != WSAENOTSOCK)
				{
					return;
				}
			}

			gObj->m_socket = INVALID_SOCKET;
		}

		gObjDel(index);
	}
}


//==========================
//CGSellRequestRecv_Hook
//==========================
void CGSellRequestRecv_Hook(PMSG_SELLREQUEST * lpMsg, int aIndex) 
{ 
	OBJECTSTRUCT *gObj = (OBJECTSTRUCT*)OBJECT_POINTER(aIndex);

	if(OfflineShop[aIndex].IsOffTrade == 1)
	{

		PMSG_SELLRESULT pResult; 
		PHeadSetB((LPBYTE)&pResult, 0x33, sizeof(pResult)); 
		pResult.Result = false; 
		pResult.Money = gObj->Money; 

		int iAddSum = gObj->pInventory[lpMsg->Pos].m_SellMoney;


		if ( gObj->CloseType != -1 ) 
		{ 
			DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
			return; 
		} 

		if ( gObj->m_IfState.use > 0 && gObj->m_IfState.type != 3 ) 
		{ 
			DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
			return; 
		} 

		if ( gObj->pTransaction == 1 ) 
		{ 
			return; 
		} 

		if ( lpMsg->Pos > MAIN_INVENTORY_SIZE - 1 ) 
		{ 
			DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
			return; 
		} 


		unsigned short gems = 50; 

		gObjInventoryDeleteItem(aIndex, lpMsg->Pos); 
		GCInventoryItemDeleteSend(aIndex, lpMsg->Pos, 1); 

		pResult.Result = true; 
		DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size); 
		return; 

	}
	CGSellRequestRecv(lpMsg, aIndex); 
}

//==========================
//CGPShopReqBuyItem_Hook
//==========================
void CGPShopReqBuyItem_Hook(PMSG_REQ_BUYITEM_FROM_PSHOP * lpMsg, int aIndex) 
{
	OBJECTSTRUCT *pObj = (OBJECTSTRUCT*)OBJECT_POINTER(MAKE_NUMBERW(lpMsg->NumberH, lpMsg->NumberL));

	DWORD dwCost	= 0;	
	DWORD Procent	= 0;
	float  OfftradeProcent = GetPrivateProfileInt("OffTrade","OfftradeProcent",0.3,"..\\EData\\EOffTrade.ini");

	dwCost	= pObj->pInventory[lpMsg->btItemPos].m_iPShopValue;

	if (OfftradeProcent == 0.0)
	{
		Procent = 0;
	}
	else
	{
		Procent = dwCost * OfftradeProcent;
	}
	if (pObj->Money < pObj->pInventory[lpMsg->btItemPos].m_iPShopValue)
	{
		MsgOutput(aIndex,"%s Você não possui zen o suficiente",pObj->Name);
		return;
	}

	gObj->Money += dwCost;
	pObj->Money -= dwCost;

	GCMoneySend(aIndex, gObj->Money);
	GCMoneySend(pObj->m_Index, pObj->Money);
	CGPShopReqBuyItem(lpMsg,aIndex);
}