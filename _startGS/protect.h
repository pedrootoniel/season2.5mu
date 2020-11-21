#pragma once

void ReadyLicense();
void InitCrcTable(void);
int Get_CRC(unsigned char*, ULONG);
long FileSize(FILE *input);