#pragma once

static unsigned char bBuxCode[3]={0xFC, 0xCF, 0xAB};

class COFFTrade
{
public:
	void Init();
	void OffTradeLogin(int aIndex,LPBYTE aRecv);
}; 

extern COFFTrade OFFTrade;

void CGPShopAnsCloseHook(int aIndex, BYTE btResult); 
void ResponErrorCloseClientHook(int aIndex); 
void CloseClient2Hook(_PER_SOCKET_CONTEXT * lpPerSocketContext, int result); 
void CloseClientHook(int aIndex); 
void CGSellRequestRecv_Hook(PMSG_SELLREQUEST * lpMsg, int aIndex);
void CGPShopReqBuyItem_Hook(PMSG_REQ_BUYITEM_FROM_PSHOP * lpMsg, int aIndex);
