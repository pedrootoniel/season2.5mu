#include "StdAfx.h"

bool CGItemDropRequestEx(PMSG_ITEMTHROW* lpMsg,int aIndex)
{
	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)(aIndex * OBJECT_SIZE + OBJECT_BASE);

	int DropBag = -1;

	int type = gObj->pInventory[lpMsg->Ipos].m_Type;

	switch(type)
	{
	case ITEMGET(14,82):
		{
			DropBag = 1;
			//Fogos de Artificio ao Dropar a Box
			GCFireworkSend(aIndex,gObj->X,gObj->Y,1);
			// - Dropa o Item
			BronzeCustom.Dropitem(gObj->m_Index);
		}
		break;
	case ITEMGET(14,83):
		{
			DropBag = 2;
			//Fogos de Artificio ao Dropar a Box
			GCFireworkSend(aIndex,gObj->X,gObj->Y,1);
			// - Dropa o Item
			SilverCustom.Dropitem(gObj->m_Index);
		}
		break;
	case ITEMGET(14,84):
		{
			DropBag = 3;
			//Fogos de Artificio ao Dropar a Box
			GCFireworkSend(aIndex,gObj->X,gObj->Y,1);
			// - Dropa o Item
			GoldenCustom.Dropitem(gObj->m_Index);
		}
		break;

	}

	if (DropBag != -1)
	{
		CPacket Packet(0xC1,0x23);
		Packet.AddByte(0x00);
		Packet.AddByte(lpMsg->Ipos);
		DataSend(aIndex,Packet.buff(),Packet.size());

		gObjInventoryDeleteItem(aIndex,lpMsg->Ipos);
		GCInventoryItemDeleteSend(aIndex,lpMsg->Ipos,1);
		return true;
	}

	return false;
}