#include "stdafx.h"

bool CGItemDropScrollRequestEx(PMSG_ITEMTHROW* lpMsg,int aIndex)
{
	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)(aIndex * OBJECT_SIZE + OBJECT_BASE);

	int DropBag = -1;

	int type = gObj->pInventory[lpMsg->Ipos].m_Type;

	switch(type)
	{
	case ITEMGET(15, 22):
		{		
			DropBag = 1;
			// - Adiciona o monstro.
			MosterAdd(43,gObj->MapNumber,gObj->X,gObj->Y);
		}
		break;
	case ITEMGET(15, 23):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(44,gObj->MapNumber,gObj->X,gObj->Y);

		}
		break;
	case ITEMGET(15, 24):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(78,gObj->MapNumber,gObj->X,gObj->Y);
		}
		break;
	case ITEMGET(15, 25):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(53,gObj->MapNumber,gObj->X,gObj->Y);

		}
		break;
	case ITEMGET(15, 26):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(79,gObj->MapNumber,gObj->X,gObj->Y);
		}
		break;
	case ITEMGET(15, 27):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(80,gObj->MapNumber,gObj->X,gObj->Y);
		}
		break;
	case ITEMGET(15, 28):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(82,gObj->MapNumber,gObj->X,gObj->Y);

		}
		break;
	case ITEMGET(15, 29):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(83,gObj->MapNumber,gObj->X,gObj->Y);

		}
		break;
	case ITEMGET(15, 30):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(81,gObj->MapNumber,gObj->X,gObj->Y);

		}
		break;
	case ITEMGET(15, 31):
		{		
			// - Adiciona o monstro.
			DropBag = 1;
			MosterAdd(54,gObj->MapNumber,gObj->X,gObj->Y);
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