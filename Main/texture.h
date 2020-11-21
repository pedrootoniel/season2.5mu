#include "stdafx.h"

struct _texture
{
	int  itemC;
	int  ItemI;
	int  itemOP;
	char patch[255];
	char item[255];
	char ditem[255];
};

extern _texture t[255];

__declspec() void gObjTexture();

void LoadTexture(char* filename);