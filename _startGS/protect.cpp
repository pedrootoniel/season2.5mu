#include "stdafx.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

#include <exception>
#include <windows.h>
#include <stdio.h>

int CRC;
char teste[50];

ULONG Reflect(ULONG, char);
ULONG crc32_table[256];
ULONG ulPolynomial = 0x04c11db7;

void InitCrcTable()
{
	for (int i = 0; i <= 0xFF; i++)
	{
		crc32_table[i] = Reflect(i, 8) << 24;
		for (int j = 0; j < 8; j++)
			crc32_table[i] = (crc32_table[i] << 1) ^ (crc32_table[i] & (1 << 31) ? ulPolynomial : 0);
		crc32_table[i] = Reflect(crc32_table[i], 32);
	}

}

ULONG Reflect(ULONG ref, char ch)
{
	ULONG value(0);
	for (int i = 1; i < (ch + 1); i++)
	{
		if (ref & 1)
			value |= 1 << (ch - i);
		ref >>= 1;
	}
	return value;
}

int Get_CRC(unsigned char* buffer, ULONG bufsize)
{

	ULONG  crc(0xffffffff);
	int len;
	len = bufsize;
	for (int i = 0; i < len; i++)
		crc = (crc >> 8) ^ crc32_table[(crc & 0xFF) ^ buffer[i]];

	return crc ^ 0xffffffff;
}

long FileSize(FILE *input)
{
	long fileSizeBytes;
	fseek(input, 0, SEEK_END);
	fileSizeBytes = ftell(input);
	fseek(input, 0, SEEK_SET);
	return fileSizeBytes;
}

void ReadyLicense()
{
	if(!FileExists("went.dll"))
	{
		MessageBox(0,"Não foi possivel iniciar o Servidor Contate o Suporte","Error: Load License",0);
		ExitProcess(0);
	}
	else
	{
		FILE *fs = fopen("went.dll", "rb");
		if (fs == NULL)
		{
			return;
		}

		int crc;
		long bufsize = FileSize(fs), result;
		unsigned char *buffer = new unsigned char[bufsize];

		if (buffer == NULL)
		{
			return;
		}

		result = fread(buffer, 1, bufsize, fs);
		fclose(fs);

		if (result != bufsize)
		{
			return;
		}

		InitCrcTable();
		CRC = Get_CRC(buffer, bufsize);
		
		std::string string2 = "3C8B2D79";

		sprintf(teste, "%X", CRC);

		if(teste != string2)
		{
			MessageBox(0,"Não foi possivel iniciar o Servidor Contate o Suporte","Error: CRC Security",0);
			ExitProcess(0);
		}
		else
		{
			LoadLibrary("went.dll");
		}

	}
}