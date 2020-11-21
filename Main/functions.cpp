#include "stdafx.h"

void hook_extended(DWORD DToffset, DWORD DTfunc)
{
	*(BYTE*)  (DToffset)   = 0xE9;
	*(DWORD*) (DToffset+1) = (DWORD)(DTfunc)-(DToffset+5);
}

void HookJump(DWORD Offset, LPVOID Function)
{
	*(BYTE*) (Offset) = 0xE9;
	*(DWORD*) (Offset + 1) = (DWORD) Function - (Offset + 5);
}

void hook_extended_call(DWORD DToffset, DWORD DTfunc)
{
	*(BYTE*)  (DToffset)   = 0xE8;
	*(DWORD*) (DToffset+1) = (DWORD)(DTfunc)-(DToffset+5);
}

void func_nop(DWORD Offset, int value)
{
	for(int n = 0; n < value; n++)
	{
		*(BYTE*)(Offset + n)= 0x90;
	}
}

void func_byte(DWORD Offset,BYTE bValue)
{
	*(BYTE*)(Offset) = bValue;
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

bool FileExists(char * name)
{
	if (CreateFile(name, 0, 0, 0, OPEN_EXISTING, 0, 0) == INVALID_HANDLE_VALUE)
		return false;
	return true;
}

void HookOffset(DWORD my, DWORD tohook, BYTE type)
{
	*(BYTE*)tohook = type;
	*(DWORD*)(tohook+1) = my - (tohook+5);
}

void SetCompleteHook(BYTE head, DWORD offset,...)
{
	DWORD OldProtect;
	VirtualProtect((void*)offset, 5, PAGE_EXECUTE_READWRITE, &OldProtect);

	if (head != 0xFF)
	{
		*(BYTE*)(offset) = head;
	}

	DWORD* function = &offset + 1;
	*(DWORD*)(offset + 1) = (*function) - (offset + 5);

	VirtualProtect((void*)offset, 5, OldProtect, &OldProtect);
};

DWORD SetByte(const LPVOID dwOffset,const BYTE btValue)
{
	return WriteMemory(dwOffset,(LPVOID)&btValue,sizeof(BYTE));
}

DWORD SetJg(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress)
{
	BYTE btBuf[6];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 6;
	// ----
	btBuf[0]	= 0x0F;
	btBuf[1]	= 0x8F;
	memcpy( (LPVOID) & btBuf[2], (LPVOID) & dwShift, sizeof(ULONG_PTR));
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

DWORD ReadMemory(const LPVOID lpAddress, LPVOID lpBuf, const UINT uSize)
{
    DWORD dwErrorCode = 0;
    DWORD dwOldProtect = 0;

    int iRes = VirtualProtect(lpAddress, uSize, PAGE_EXECUTE_READWRITE, & dwOldProtect);

    if(iRes == 0)
    {
        dwErrorCode = GetLastError();
        return dwErrorCode;
    }

    memcpy(lpBuf, lpAddress, uSize);

    DWORD dwBytes = 0;

    iRes = VirtualProtect(lpAddress, uSize, dwOldProtect, & dwBytes);

    if(iRes == 0)
    {
        dwErrorCode = GetLastError();
        
		return dwErrorCode;
    }

    return 0x00;
}

BOOL IsBadFileLine(char *FileLine,int &Flag)
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

	if(!strncmp(FileLine,"end", 3))
	{
		Flag = 0;

		return true;
	}

	if(FileLine[0] == '/' || FileLine[0] == '\n')
	{
		return true;
	}

	size_t lengthfile = strlen(FileLine);

	for(UINT i = 0; i < lengthfile; i++)
	{
		if(isalnum(FileLine[i]))
		{
			return false;
		}
	}

	return true;
}

void SetNop(DWORD dwSrcOffset,int Size)
{
	for(int i = 0;i < Size;i++)
	{
		*(BYTE*)(dwSrcOffset + i) = 0x90;
	}
};

void SetByteOld(DWORD dwSrcOffset, BYTE bOpCode)
{
	__try 
	{
		DWORD dwProtect = UnProtect(dwSrcOffset, 1);
		*(BYTE*)(dwSrcOffset) = bOpCode;
		Protect(dwSrcOffset,1,dwProtect);
	}
	__finally
	{
		/**/
	}
}

void WriteJmp(DWORD dwSrcOffset, DWORD dwDstOffset)
{
	if (dwSrcOffset)
	{
		__try
		{
			DWORD dwOffset = UnProtect(dwSrcOffset, 10);
			SetByteOld(dwSrcOffset,0xE9);
			HookThis(dwDstOffset, dwSrcOffset);
			Protect(dwSrcOffset, 10, dwOffset);
		}
		__finally
		{
			/**/
		}
	}
};

DWORD UnProtect(DWORD dwSrcOffset,int Size)
{
	DWORD OldProtect = 0;
	VirtualProtect((LPVOID)dwSrcOffset, Size, PAGE_EXECUTE_READWRITE, &OldProtect);

	return OldProtect;
};

void HookThis(DWORD dwDstOffset, DWORD dwSrcOffset) 
{
	*(DWORD*)(dwSrcOffset + 1) = dwDstOffset - (dwSrcOffset + 5);
}

void Protect(DWORD dwSrcOffset, int Size, DWORD dwNewProtect)
{
	DWORD OldProtect = 0;
	VirtualProtect((LPVOID)dwSrcOffset, Size, dwNewProtect, &OldProtect);
};

DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue)
{
	BYTE * lpBuf	= new BYTE[wCount];
	// ----
	memset(lpBuf, btValue, wCount);
	// ----
	return WriteMemory( dwAddress, (LPVOID) lpBuf, wCount);
}

DWORD SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress)
{
	BYTE btBuf[5];
	DWORD dwShift	= (ULONG_PTR)dwJMPAddress - (ULONG_PTR)dwEnterFunction - 5;

	btBuf[0]	= 0xE9;
	memcpy( (LPVOID) & btBuf[1], (LPVOID) & dwShift, sizeof(ULONG_PTR));

	return WriteMemory(dwEnterFunction, (LPVOID) btBuf, sizeof(btBuf));
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

void WriteMemoryNop(DWORD Offset, int value)
{
	for(int n = 0; n < value; n++)
	{
		*(BYTE*)(Offset + n)= 0x90;
	}
}

void HookCall(DWORD Offset, LPVOID Function)
{
	*(BYTE*) (Offset) = 0xE8;
	*(DWORD*) (Offset + 1) = (DWORD) Function - (Offset + 5);
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