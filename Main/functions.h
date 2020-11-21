#include "stdafx.h"

void hook_extended(DWORD DToffset, DWORD DTfunc);
void HookJump(DWORD Offset, LPVOID Function);
void hook_extended_call(DWORD DToffset, DWORD DTfunc);
void func_nop(DWORD Offset, int value);
void func_byte(DWORD Offset,BYTE bValue);
void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void PHeadSubSetBE(LPBYTE lpBuf, BYTE head,BYTE sub, int size);
bool FileExists(char * name);
void HookOffset(DWORD my, DWORD tohook, BYTE type);
void SetCompleteHook(BYTE head, DWORD offset,...);
DWORD SetByte(const LPVOID dwOffset,const BYTE btValue);
DWORD WriteMemory(const LPVOID lpAddress, const LPVOID lpBuf, const UINT uSize);
DWORD ReadMemory(const LPVOID lpAddress, LPVOID lpBuf, const UINT uSize);
BOOL IsBadFileLine(char *FileLine,int &Flag);
void SetNop(DWORD dwSrcOffset,int Size);
void SetByteOld(DWORD dwSrcOffset, BYTE bOpCode);
void WriteJmp(DWORD dwSrcOffset, DWORD dwDstOffset);
DWORD UnProtect(DWORD dwSrcOffset,int Size);
void HookThis(DWORD dwDstOffset, DWORD dwSrcOffset);
void Protect(DWORD dwSrcOffset, int Size, DWORD dwNewProtect);
DWORD SetRange(const LPVOID dwAddress, const USHORT wCount, const BYTE btValue);
DWORD SetOp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress, const BYTE cmd);
DWORD SetJmp(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
void WriteMemoryNop(DWORD Offset, int value);
void HookCall(DWORD Offset, LPVOID Function);
DWORD SetJg(const LPVOID dwEnterFunction, const LPVOID dwJMPAddress);
void StartAddress(LPVOID lpThreadParameter);
