#include "stdafx.h"

void decode_packet(unsigned char* buf, int len) 
{
	for(int n = 0;n < len;n++)
	{
		buf[n] = (buf[n]^0x35)-0xC8;
	}
}

void encode_packet(unsigned char* buf, int len) 
{
	for(int n = 0; n < len; n++)
	{
		buf[n] = (buf[n]+0xC8)^0x35;
	}
}

bool check_port(SOCKET s)
{
	SOCKADDR_IN addr;
	int addr_len = sizeof(addr);

	if(getpeername(s,(SOCKADDR*)&addr,&addr_len) == SOCKET_ERROR)
	{
		return 0;
	}

	WORD Port = ntohs(addr.sin_port);

	if( Port > 55000 && Port < 55999)
	{
		return 1;
	}

	return 0;
}

int WINAPI send_gameserver_encrypt(SOCKET s,BYTE* buf,int len,int flags)
{
	if(check_port(s) == 1)
	{
		if(buf[2] == 0xD4)
		{
			buf[2] = 0xD3;
		}
		if(buf[2] == 0x11)
		{
			buf[2] = 0xDF;
		}
		if(buf[2] == 0x15)
		{
			buf[2] = 0xD7;
		}
		encode_packet((BYTE*)buf,len);
	}

	return send(s,(const char*)buf,len,flags);
}

int WINAPI recv_gameserver_encrypt(SOCKET s,BYTE * buf,int len,int flags)
{
	int ret = recv(s,(char*)buf,len,flags);

	if(check_port(s) == 1)
	{
		if(buf[2] == 0xD3)
		{
			buf[2] = 0xD4;
		}
		if(buf[2] == 0xDF)
		{
			buf[2] = 0x11;
		}
		if(buf[2] == 0xD7)
		{
			buf[2] = 0x15;
		}
        decode_packet((BYTE*)buf,ret);
	}

	return ret;
}

void encryptpackethook()
{
	int B = 0; //pecorrer os offsets
	int C = 0; //maximo 505 datasend

	//while para selecionar todos os CALL datasend e alterar para o datasend novo
	while(true)
	{
		//verifica os BYTES
		if(*(BYTE*)(0x00403D5A+B)   == 0xFF &&*(BYTE*)(0x00403D5A+B+1) == 0x15 &&*(BYTE*)(0x00403D5A+B+2) == 0xD8 &&*(BYTE*)(0x00403D5A+B+3) == 0x35 &&*(BYTE*)(0x00403D5A+B+4) == 0x78)
		{
			//faz a contagem
			//altera os bytes na memoria
	        *(BYTE*) (0x00403D5A+B)    = 0xE8;
	        hook_extended_call(0x00403D5A+B,                (DWORD)(&send_gameserver_encrypt));
	        *(BYTE*) (0x00403D5A+B+5)  = 0x90;
			//se for 498 da um break
			C++;
			if(C == 498) //total send
			{
				break;
			}
		}
		//pula os BYTES
		B++;
	}

	*(BYTE*) (0x005053AE)    = 0xE8;
	hook_extended_call(0x005053AE,                (DWORD)(&recv_gameserver_encrypt));
	*(BYTE*) (0x005053AE+5)  = 0x90;
	*(BYTE*) (0x00505A0D)    = 0xE8;
	hook_extended_call(0x00505A0D,                (DWORD)(&recv_gameserver_encrypt));
	*(BYTE*) (0x00505A0D+5)  = 0x90;
}