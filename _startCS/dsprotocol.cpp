#include "stdafx.h"


void ProtocolDS(BYTE protoNum, unsigned char* aRecv, int aLen)
{
	switch(protoNum)
	{
		case 0x01:
			JGPGetCharList(aRecv);
			break;
		case 0x04:
			JGCharacterCreateRequest((SDHP_CREATECHARRESULT *)aRecv);
			break;
		case 0xE0:
			aRecvPlayerInfo((PLAYER_OBJECT*)aRecv);
		break;
		default:
			ProtocolCoreDS(protoNum, aRecv, aLen);
			break;
	}
}

void aRecvPlayerInfo(PLAYER_OBJECT * pDataServer)
{
	player_struct[pDataServer->index].vip    = pDataServer->vip;
	player_struct[pDataServer->index].resets = pDataServer->resets;
}

int DataServerSend(unsigned char* buf, int len)
{
	int result;

	_asm
	{
		mov eax, 0x004019F6;
		push len;
		mov edx, dword ptr ds:[buf];
		push edx;
		mov ecx, 0x754CB0
		call eax;
		mov result, eax;
	}

	return result;
}

BYTE LevelSmallConvert(int level)
{
	if(level >= 15) //max item lvl
	{
		return 7;
	}
	
	if(level >= 13 && level <= 14)
	{
		return 6;
	}

	if(level >= 11 && level <=12)
	{
		return 5;
	}

	if(level >= 9 && level <= 10)
	{
		return 4;
	}

	if(level >= 7 && level <= 8)
	{
		return 3;
	}

	if(level >= 5 && level <= 6)
	{
		return 2;
	}

	if(level >= 3 && level <= 4)
	{
		return 1;
	}
	
	return 0;
}

void JGPGetCharList(unsigned char * lpRecv)
{
	SDHP_CHARLISTCOUNT * lpCount = (SDHP_CHARLISTCOUNT *)lpRecv;
	SDHP_CHARLIST * lpCL;
	char szId[10 + 1];
	BYTE sendbuf[256];
	int lOfs = 0;
	int lsOfs = sizeof(SDHP_CHARLISTCOUNT);
	int aIndex = lpCount->Number;
	BYTE index;
	PMSG_CHARLISTCOUNT pCLCount;	// Packet Char List Count
	PMSG_CHARLIST pCList;
	WORD TempInventory[12];

	pCLCount.h.c = 0xC1;
	pCLCount.h.headcode = 0xF3;
	pCLCount.subcode = 0x00;
	pCLCount.Count = lpCount->Count;

	szId[10] = 0;
	memcpy(szId, lpCount->AccountId, 10);

	if (gObjIsAccontConnect(aIndex, szId) == FALSE)
	{
		CloseClient(aIndex);
		return;
	}

	OBJECTSTRUCT* gObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	gObj->Magumsa = lpCount->Magumsa;
	pCLCount.MaxClass = gObj->Magumsa + 2;
	pCLCount.MoveCnt = lpCount->MoveCnt;

	memset(sendbuf, 0, sizeof(sendbuf));
	lOfs += sizeof(PMSG_CHARLISTCOUNT);

	if (pCLCount.Count > 0)
	{
		for (int n = 0; n < pCLCount.Count; n++)
		{
			memset(&pCList, 0, sizeof(pCList));
			lpCL = (SDHP_CHARLIST *)&lpRecv[lsOfs];
			pCList.Index = lpCL->Index;
			pCList.Level = lpCL->Level;
			pCList.CtlCode = lpCL->CtlCode;
			pCList.btGuildStatus = lpCL->btGuildStatus;

			if(gObj->m_cAccountItemBlock != 0)
			{
				pCList.CtlCode |= 0x10;	// Set Block Item
			}

			memcpy(pCList.Name, lpCL->Name, MAX_ACCOUNT_LEN);
			pCList.CharSet[CS_CLASS] = CS_GET_CLASS(lpCL->Class);
			int changeup = CS_GET_CHANGEUP(lpCL->Class);
			pCList.CharSet[CS_CLASS] |= CS_SET_CHANGEUP(changeup);
			pCList.CharSet[9] = 0;
	

			if (lpCL->DbVersion == 0)
			{
				if (lpCL->dbInventory[0] != (BYTE)-1)
				{
					WORD wItemCode = lpCL->dbInventory[0] / MAX_TYPE_ITEMS * MAX_SUBTYPE_ITEMS + lpCL->dbInventory[0] % MAX_TYPE_ITEMS;
					pCList.CharSet[1] = wItemCode;
					pCList.CharSet[12] |= DBI_GET_TYPE(wItemCode);
				}
				else
				{
					pCList.CharSet[1] = -1;
					pCList.CharSet[12] |= 0xF0;
				}

				if (lpCL->dbInventory[2] != (BYTE)-1)
				{
					WORD wItemCode = lpCL->dbInventory[2] / MAX_TYPE_ITEMS * MAX_SUBTYPE_ITEMS + lpCL->dbInventory[2] % MAX_TYPE_ITEMS;
					pCList.CharSet[2] = wItemCode;
					pCList.CharSet[13] |= DBI_GET_TYPE(wItemCode);
				}
				else
				{
					pCList.CharSet[2] = -1;
					pCList.CharSet[13] |= 0xF0;
				}

				if (lpCL->dbInventory[4] == (BYTE)-1)
				{
					index = 0xF0;
				}
				else
				{
					index = (lpCL->dbInventory[4] & 0x0F) * MAX_TYPE_ITEMS;
				}

				if (lpCL->dbInventory[6] == (BYTE)-1)
				{
					index |= 0x0F;
				}
				else
				{
					index |= (lpCL->dbInventory[6] & 0x0F);
				}

				pCList.CharSet[3] = index;

				if (lpCL->dbInventory[8] == (BYTE)-1)
				{
					index = 0xF0;
				}
				else
				{
					index = (lpCL->dbInventory[8] & 0x0F) * MAX_TYPE_ITEMS;
				}

				if (lpCL->dbInventory[10] == (BYTE)-1)
				{
					index |= 0x0F;
				}
				else
				{
					index |= (lpCL->dbInventory[10] & 0x0F);
				}

				pCList.CharSet[4] = index;

				if (lpCL->dbInventory[12] == (BYTE)-1)
				{
					index = 0xF0;
				}
				else
				{
					index = (lpCL->dbInventory[12] & 0x0F) * MAX_TYPE_ITEMS;
				}

				if (lpCL->dbInventory[14] == (BYTE)-1)
				{
					index |= 0x0C;
				}
				else
				{
					index |= ((lpCL->dbInventory[14] & 0x03) * 4);
				}

				if (lpCL->dbInventory[16] == (BYTE)-1)
				{
					index |= 0x03;
				}
				else
				{
					index |= (lpCL->dbInventory[16] & 0x03);
				}

				pCList.CharSet[5] = index;

				if (lpCL->dbInventory[4] == (BYTE)-1)
					pCList.CharSet[9] = 0x80;

				if (lpCL->dbInventory[6] == (BYTE)-1)
					pCList.CharSet[9] |= 0x40;

				if (lpCL->dbInventory[8] == (BYTE)-1)
					pCList.CharSet[9] |= 0x20;

				if (lpCL->dbInventory[10] == (BYTE)-1)
					pCList.CharSet[9] |= 0x10;

				if (lpCL->dbInventory[12] == (BYTE)-1)
					pCList.CharSet[9] |= 0x08;

				int levelindex = LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[1]));
				levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[3])) << 3;
				levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[5])) << 6;
				levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[7])) << 9;
				levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[9])) << 12;
				levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[11])) << 15;
				levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[13])) << 18;

				pCList.CharSet[6] = levelindex >> 16 & 0xFF;
				pCList.CharSet[7] = (levelindex >> 8) & 0xFF;
				pCList.CharSet[8] = (levelindex) & 0xFF;
				pCList.CharSet[10] = 0;
				pCList.CharSet[11] = 0;

				if (lpCL->dbInventory[4] == (BYTE)-1)
					pCList.CharSet[13] |= 0x0F;

				if (lpCL->dbInventory[8] == (BYTE)-1)
					pCList.CharSet[14] |= 0xF0;

				if (lpCL->dbInventory[10] == (BYTE)-1)
					pCList.CharSet[14] |= 0x0F;

				if (lpCL->dbInventory[12] == (BYTE)-1)
					pCList.CharSet[15] |= 0xF0;

				if (lpCL->dbInventory[14] == (BYTE)-1)
					pCList.CharSet[15] |= 0x0F;

				pCList.CharSet[16] = 0;
				pCList.CharSet[17] = 0;
			}
			else if (lpCL->DbVersion <= 2)
			{
				if (lpCL->dbInventory[0] != (BYTE)-1)
				{
					TempInventory[0] = (lpCL->dbInventory[0] / 32) * MAX_SUBTYPE_ITEMS + lpCL->dbInventory[0] % 32;
				}
				else
				{
					TempInventory[0] = -1;
				}

				if (lpCL->dbInventory[3] != (BYTE)-1)
				{
					TempInventory[1] = (lpCL->dbInventory[3] / 32) * MAX_SUBTYPE_ITEMS + lpCL->dbInventory[3] % 32;
				}
				else
				{
					TempInventory[1] = -1;
				}

				if (lpCL->dbInventory[6] == (BYTE)-1 && (lpCL->dbInventory[8] & 0x80) == 0x80)
				{
					TempInventory[2] = -1;
				}
				else
				{
					TempInventory[2] = (lpCL->dbInventory[6] + ((lpCL->dbInventory[8] >> 7) << 8)) % 32;
				}

				if (lpCL->dbInventory[9] == (BYTE)-1 && (lpCL->dbInventory[11] & 0x80) == 0x80)
				{
					TempInventory[3] = -1;
				}
				else
				{
					TempInventory[3] = (lpCL->dbInventory[9] + ((lpCL->dbInventory[11] >> 7) << 8)) % 32;
				}

				if (lpCL->dbInventory[12] == (BYTE)-1 && (lpCL->dbInventory[14] & 0x80) == 0x80)
				{
					TempInventory[4] = 0x1F;
				}
				else
				{
					TempInventory[4] = (lpCL->dbInventory[12] + ((lpCL->dbInventory[14] >> 7) << 8)) % 32;
				}

				if (lpCL->dbInventory[15] == (BYTE)-1 && (lpCL->dbInventory[17] & 0x80) == 0x80)
				{
					TempInventory[5] = 0x1F;
				}
				else
				{
					TempInventory[5] = (lpCL->dbInventory[15] + ((lpCL->dbInventory[17] >> 7) << 8)) % 32;
				}

				if (lpCL->dbInventory[18] == (BYTE)-1 && (lpCL->dbInventory[20] & 0x80) == 0x80)
				{
					TempInventory[6] = 0x1F;
				}
				else
				{
					TempInventory[6] = (lpCL->dbInventory[18] + ((lpCL->dbInventory[20] >> 7) << 8)) % 32;
				}

				if (lpCL->dbInventory[21] == (BYTE)-1 && (lpCL->dbInventory[23] & 0x80) == 0x80)
				{
					TempInventory[7] = 0x1F;
				}
				else
				{
					TempInventory[7] = (lpCL->dbInventory[21] + ((lpCL->dbInventory[23] >> 7) << 8)) % 32;
				}

				if (lpCL->dbInventory[24] == (BYTE)-1 && (lpCL->dbInventory[26] & 0x80) == 0x80)
				{
					TempInventory[8] = 0x1F;
				}
				else
				{
					TempInventory[8] = (lpCL->dbInventory[24] + ((lpCL->dbInventory[26] >> 7) << 8)) % 32;
				}

				if (TempInventory[0] != (WORD)-1)
				{
					pCList.CharSet[1] = TempInventory[0];
					pCList.CharSet[12] |= DBI_GET_TYPE(TempInventory[0]);
				}
				else
				{
					pCList.CharSet[1] = -1;
					pCList.CharSet[12] |= 0xF0;
				}

				if (TempInventory[1] != (WORD)-1)
				{
					pCList.CharSet[2] = TempInventory[1];
					pCList.CharSet[13] |= DBI_GET_TYPE(TempInventory[1]);
				}
				else
				{
					pCList.CharSet[2] = -1;
					pCList.CharSet[13] |= 0xF0;
				}

				pCList.CharSet[3] = TempInventory[2] % MAX_TYPE_ITEMS * MAX_TYPE_ITEMS + TempInventory[3] % MAX_TYPE_ITEMS;
				pCList.CharSet[4] = TempInventory[4] % MAX_TYPE_ITEMS * MAX_TYPE_ITEMS + TempInventory[5] % MAX_TYPE_ITEMS;
				index = TempInventory[6] % MAX_TYPE_ITEMS * MAX_TYPE_ITEMS;

				if (TempInventory[7] == 0x1F)
				{
					index |= 0x0C;
				}
				else
				{
					index |= (TempInventory[7] & 0x03) * 4;
				}

				if ((TempInventory[8] & 0x04) == 0)
				{
					if (TempInventory[8] == 0x1F)
					{
						index |= 0x03;
					}
					else
					{
						index |= TempInventory[8] & 0x03;
					}
				}
				else
				{
					index |= 0x03;
				}

				pCList.CharSet[5] = index;
				int levelindex = 0;

				if (TempInventory[0] != (WORD)-1)
				{
					levelindex = LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[1]));
				}

				if (TempInventory[1] != (WORD)-1)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[4])) << 3;
				}

				if (TempInventory[2] < 0x1F)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[7])) << 6;
				}

				if (TempInventory[3] < 0x1F)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[10])) << 9;
				}

				if (TempInventory[4] < 0x1F)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[13])) << 12;
				}

				if (TempInventory[5] < 0x1F)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[16])) << 15;
				}

				if (TempInventory[6] < 0x1F)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[19])) << 18;
				}

				pCList.CharSet[6] = ((int)levelindex >> 16) & 0xFF;
				pCList.CharSet[7] = ((int)levelindex >> 8) & 0xFF;
				pCList.CharSet[8] = levelindex & 0xFF;

				if (TempInventory[2] > 0x0F)
					pCList.CharSet[9] = 0x80;

				if (TempInventory[3] > 0x0F)
					pCList.CharSet[9] |= 0x40;

				if (TempInventory[4] > 0x0F)
					pCList.CharSet[9] |= 0x20;

				if (TempInventory[5] > 0x0F)
					pCList.CharSet[9] |= 0x10;

				if (TempInventory[6] > 0x0F)
					pCList.CharSet[9] |= 0x8;

				if ((TempInventory[7] >= 3 && TempInventory[7] <= 6) || TempInventory[7] == 0x1E)
				{
					pCList.CharSet[5] |= 0x0C;

					if (TempInventory[7] == 0x1E)
					{
						pCList.CharSet[9] |= 0x05;
					}
					else
					{
						pCList.CharSet[9] |= (TempInventory[7] - 2) & 0x07;
					}
				}

				pCList.CharSet[10] = 0;

				if ((TempInventory[8] & 0x03) != 0 && TempInventory[8] != 0x1F)
					pCList.CharSet[10] |= 1;

				pCList.CharSet[11] = 0;

				if ((TempInventory[8] & 0x04) != 0 && TempInventory[8] != 0x1F)
					pCList.CharSet[12] |= 1;

				if (TempInventory[2] >= 0x1F) pCList.CharSet[13] |= 0x0F;
				if (TempInventory[3] >= 0x1F) pCList.CharSet[14] |= 0xF0;
				if (TempInventory[4] >= 0x1F) pCList.CharSet[14] |= 0x0F;
				if (TempInventory[5] >= 0x1F) pCList.CharSet[15] |= 0xF0;
				if (TempInventory[6] >= 0x1F) pCList.CharSet[15] |= 0x0F;

				pCList.CharSet[16] = 0;
				pCList.CharSet[17] = 0;
			}
			else	// Case DB 3
			{
				if (lpCL->dbInventory[0] == (BYTE)-1 && (lpCL->dbInventory[2] & 0x80) == 0x80 && (lpCL->dbInventory[3] & 0xF0) == 0xF0)
				{
					TempInventory[0] = -1;
				}
				else
				{
					TempInventory[0] = (lpCL->dbInventory[0] + (lpCL->dbInventory[2] & 0x80) * 2) + (lpCL->dbInventory[3] & 0xF0) * 32;
				}

				if (lpCL->dbInventory[4] == (BYTE)-1 && (lpCL->dbInventory[6] & 0x80) == 0x80 && (lpCL->dbInventory[7] & 0xF0) == 0xF0)
				{
					TempInventory[1] = -1;
				}
				else
				{
					TempInventory[1] = (lpCL->dbInventory[4] + (lpCL->dbInventory[6] & 0x80) * 2) + (lpCL->dbInventory[7] & 0xF0) * 32;
				}

				if (lpCL->dbInventory[8] == (BYTE)-1 && (lpCL->dbInventory[10] & 0x80) == 0x80 && (lpCL->dbInventory[11] & 0xF0) == 0xF0)
				{
					TempInventory[2] = 0x1FF;
				}
				else
				{
					TempInventory[2] = ((lpCL->dbInventory[8] + (lpCL->dbInventory[10] & 0x80) * 2) + (lpCL->dbInventory[11] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				if (lpCL->dbInventory[12] == (BYTE)-1 && (lpCL->dbInventory[14] & 0x80) == 0x80 && (lpCL->dbInventory[15] & 0xF0) == 0xF0)
				{
					TempInventory[3] = 0x1FF;
				}
				else
				{
					TempInventory[3] = ((lpCL->dbInventory[12] + (lpCL->dbInventory[14] & 0x80) * 2) + (lpCL->dbInventory[15] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				if (lpCL->dbInventory[16] == (BYTE)-1 && (lpCL->dbInventory[18] & 0x80) == 0x80 && (lpCL->dbInventory[19] & 0xF0) == 0xF0)
				{
					TempInventory[4] = 0x1FF;
				}
				else
				{
					TempInventory[4] = ((lpCL->dbInventory[16] + (lpCL->dbInventory[18] & 0x80) * 2) + (lpCL->dbInventory[19] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				if (lpCL->dbInventory[20] == (BYTE)-1 && (lpCL->dbInventory[22] & 0x80) == 0x80 && (lpCL->dbInventory[23] & 0xF0) == 0xF0)
				{
					TempInventory[5] = 0x1FF;
				}
				else
				{
					TempInventory[5] = ((lpCL->dbInventory[20] + (lpCL->dbInventory[22] & 0x80) * 2) + (lpCL->dbInventory[23] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				if (lpCL->dbInventory[24] == (BYTE)-1 && (lpCL->dbInventory[26] & 0x80) == 0x80 && (lpCL->dbInventory[27] & 0xF0) == 0xF0)
				{
					TempInventory[6] = 0x1FF;
				}
				else
				{
					TempInventory[6] = ((lpCL->dbInventory[24] + (lpCL->dbInventory[26] & 0x80) * 2) + (lpCL->dbInventory[27] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				if (lpCL->dbInventory[28] == (BYTE)-1 && (lpCL->dbInventory[30] & 0x80) == 0x80 && (lpCL->dbInventory[31] & 0xF0) == 0xF0)
				{
					TempInventory[7] = 0x1FF;
				}
				else
				{
					TempInventory[7] = ((lpCL->dbInventory[28] + (lpCL->dbInventory[30] & 0x80) * 2) + (lpCL->dbInventory[31] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				if (lpCL->dbInventory[32] == (BYTE)-1 && (lpCL->dbInventory[34] & 0x80) == 0x80 && (lpCL->dbInventory[35] & 0xF0) == 0xF0)
				{
					TempInventory[8] = 0x1FF;
				}
				else
				{
					TempInventory[8] = ((lpCL->dbInventory[32] + (lpCL->dbInventory[34] & 0x80) * 2) + (lpCL->dbInventory[35] & 0xF0) * 32) % MAX_SUBTYPE_ITEMS;
				}

				pCList.CharSet[12] |= DBI_GET_TYPE(TempInventory[0]);
				pCList.CharSet[1] = TempInventory[0] % 256;

				pCList.CharSet[13] |= DBI_GET_TYPE(TempInventory[1]);
				pCList.CharSet[2] = TempInventory[1] % 256;

				pCList.CharSet[13] |= (int)(TempInventory[2] & 0x1E0) >> 5;
				pCList.CharSet[9] |= (int)(TempInventory[2] & 0x10) << 3;
				pCList.CharSet[3] |= (int)(TempInventory[2] & 0x0F) << 4;

				pCList.CharSet[14] |= (int)(TempInventory[3] & 0x1E0) >> 1;
				pCList.CharSet[9] |= (int)(TempInventory[3] & 0x10) << 2;
				pCList.CharSet[3] |= (int)(TempInventory[3] & 0x0F);

				pCList.CharSet[14] |= (int)(TempInventory[4] & 0x1E0) >> 5;
				pCList.CharSet[9] |= (int)(TempInventory[4] & 0x10) << 1;
				pCList.CharSet[4] |= (int)(TempInventory[4] & 0x0F) << 4;

				pCList.CharSet[15] |= (int)(TempInventory[5] & 0x1E0) >> 1;
				pCList.CharSet[9] |= (int)(TempInventory[5] & 0x10);
				pCList.CharSet[4] |= (int)(TempInventory[5] & 0x0F);

				pCList.CharSet[15] |= (int)(TempInventory[6] & 0x1E0) >> 5;
				pCList.CharSet[9] |= (int)(TempInventory[6] & 0x10) >> 1;
				pCList.CharSet[5] |= (int)(TempInventory[6] & 0x0F) << 4;

				index = 0;

				if (TempInventory[7] == 0x1FF)
				{
					index |= 0x0C;
				}
				else
				{
					index |= (int)(TempInventory[7] & 0x03) << 2;
				}

				if ((TempInventory[8] & 0x04) == 0)
				{
					if (TempInventory[8] == 0x1FF)
					{
						index |= 0x03;
					}
					else
					{
						index |= (TempInventory[8]) & 0x03;
					}
				}
				else
				{
					index |= 0x03;
				}

				pCList.CharSet[5] |= index;

				int levelindex = 0;

				if (TempInventory[0] != (WORD)-1)
				{
					levelindex = LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[1]));
				}

				if (TempInventory[1] != (WORD)-1)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[5])) << 3;
				}

				if (TempInventory[2] < 0x1FF)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[9])) << 6;
				}

				if (TempInventory[3] < 0x1FF)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[13])) << 9;
				}

				if (TempInventory[4] < 0x1FF)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[17])) << 12;
				}

				if (TempInventory[5] < 0x1FF)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[21])) << 15;
				}

				if (TempInventory[6] < 0x1FF)
				{
					levelindex |= (int)LevelSmallConvert(DBI_GET_LEVEL(lpCL->dbInventory[25])) << 18;
				}

				pCList.CharSet[6] = ((int)levelindex >> 0x10) & 0xFF;
				pCList.CharSet[7] = ((int)levelindex >> 0x08) & 0xFF;
				pCList.CharSet[8] = ((int)levelindex) & 0xFF;

				if ((TempInventory[7] >= 3 && TempInventory[7] <= 6) || TempInventory[7] == 0x1E)
				{
					pCList.CharSet[5] |= 0x0C;

					if (TempInventory[7] == 0x1E)
					{
						pCList.CharSet[9] |= 0x05;
					}
					else
					{
						pCList.CharSet[9] |= (TempInventory[7] - 2) & 0x07;
					}
				}

				pCList.CharSet[10] = 0;

				if ((TempInventory[8] & 0x03) != 0 && TempInventory[8] != 0x1FF)
				{
					pCList.CharSet[10] |= 0x01;
				}

				pCList.CharSet[11] = 0;

				if ((TempInventory[8] & 0x04) != 0 && TempInventory[8] != 0x1FF)
				{
					pCList.CharSet[12] |= 0x01;
				}

				pCList.CharSet[16] = 0;
				pCList.CharSet[17] = 0;

				if (TempInventory[8] == 0x25 && TempInventory[8] != 0x1FF)
				{
					pCList.CharSet[10] &= 0xFE;
					pCList.CharSet[12] &= 0xFE;
					pCList.CharSet[12] |= 0x04;
					BYTE btExcellentOption = lpCL->dbInventory[34] & 0x3F;

					if ((btExcellentOption & 1) == 1)
					{
						pCList.CharSet[16] |= 0x01;
					}

					if ((btExcellentOption & 2) == 2)
					{
						pCList.CharSet[16] |= 0x02;
					}					
					if ((btExcellentOption & 4) == 4) //Golden Fenrir
					{
						pCList.CharSet[17] |= 0x01;
					}
				}

				if ( TempInventory[7] >= 36 && TempInventory[7] <= 66 )
				{
					pCList.CharSet[5]  |= CS_SET_WING1(3);
					pCList.CharSet[17] |= (BYTE)(TempInventory[7] - 36 + 1) << 2;
				}
			}

			memcpy(&sendbuf[lOfs], &pCList, sizeof(pCList));
			lsOfs += sizeof(SDHP_CHARLIST);
			lOfs += sizeof(pCList);
		}
	}

	pCLCount.h.size = lOfs;
	memcpy(sendbuf, &pCLCount, sizeof(PMSG_CHARLISTCOUNT));
	DataSend(aIndex, sendbuf, lOfs);
}

void JGCharacterCreateRequest(SDHP_CREATECHARRESULT* lpMsg)
{
	PMSG_CHARCREATERESULT pResult;
	char szAccountID[MAX_ACCOUNT_LEN+1];
	int aIndex = lpMsg->Number;

	szAccountID[MAX_ACCOUNT_LEN] = 0;
	memcpy(szAccountID, lpMsg->AccountId, sizeof(lpMsg->AccountId));

	if ( gObjIsAccontConnect(aIndex, szAccountID) == FALSE )
	{
		CloseClient(aIndex);
		return;
	}

	pResult.h.c = 0xC1;
	pResult.h.size = sizeof(PMSG_CHARCREATERESULT);
	pResult.h.headcode = 0xF3;
	pResult.subcode = 0x01;
	pResult.Result = lpMsg->Result;
	pResult.pos = lpMsg->Pos;
	pResult.Class = (lpMsg->ClassSkin >> 4 << 5) & 0xE0;
	int changeup = lpMsg->ClassSkin & 0x07; 
	pResult.Class |= (changeup << 4) & 0x10;
	pResult.Class |= (changeup << 4) & 0x20; //Season 2.5 add-on
	pResult.Level = lpMsg->Level;
	memcpy(pResult.Name, lpMsg->Name, sizeof(pResult.Name));

	if ( pResult.Result == 1 )
	{
		memcpy(pResult.Equipment, lpMsg->Equipment, sizeof(pResult.Equipment));
	}

	DataSend(aIndex, (LPBYTE)&pResult, pResult.h.size);
}