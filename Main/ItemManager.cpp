#include "StdAfx.h"

void LoadModels()
{
	((void(*)())0x00682F3F)();

	char model_name[50];

	for (int n = 0; n < MAXITEM; n++)
	{
		if (n > 23 && n < 31 || n > 31)
		{
			sprintf_s(model_name, "Sword%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((0*MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}
		if (n > 8) // Axe
		{
			sprintf_s(model_name, "Axe%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((1 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}
		if (n > 14) //Mace
		{
			sprintf_s(model_name, "Mace%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((2 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}
		if (n > 10) //Spear
		{
			sprintf_s(model_name, "Spear%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((3 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}

		if (n > 12) // Staff
		{
			sprintf_s(model_name, "Staff%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((5 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}

		if (n > 16) //Shield
		{
			sprintf_s(model_name, "Shield%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((6 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}

		if (n >= 36 && n <= 60) //Wings
		{
			sprintf_s(model_name, "Wing%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((12 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}

		if (n >= 68 && n <= 81) //Jewels
		{
			sprintf_s(model_name, "Jewel%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((14 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}

		if (n >= 22 && n <= 31) //Scroll
		{
			sprintf_s(model_name, "Scroll%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((15 * MAXITEM) + n + 0x246, "Data\\Item\\", model_name, -1);
		}

		if (n > 32 ) // Helm
		{
			sprintf_s(model_name, "HelmMale%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((7 * MAXITEM) + n + 0x246, "Data\\Player\\", model_name, -1);
		}

		if (n > 33) // Armor
		{
			sprintf_s(model_name, "ArmorMale%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((8 * MAXITEM) + n + 0x246, "Data\\Player\\", model_name, -1);
		}

		if (n > 33) // Pant
		{
			sprintf_s(model_name, "PantMale%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((9 * MAXITEM) + n + 0x246, "Data\\Player\\", model_name, -1);
		}

		if (n > 33) // Glove
		{
			sprintf_s(model_name, "GloveMale%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((10 * MAXITEM) + n + 0x246, "Data\\Player\\", model_name, -1);
		}

		if (n > 33) //Boot
		{
			sprintf_s(model_name, "BootMale%d", n + 1);
			((void(*)(int, char*, char*, int))0x0067FFA3)((11 * MAXITEM) + n + 0x246, "Data\\Player\\", model_name, -1);
		}

	}
}

void LoadTextures()
{
	((void(*)())0x00684FB7 )();

	for (int n = 0; n < MAXITEM ; n++)
	{
		
		if(n > 23 && n < 31 || n > 31) // Sword
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((0 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n > 8) // Axe
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((1 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n > 14) //Mace
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((2 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n > 10) //Spear
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((3 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST,GL_TRUE);
		}


		if (n > 12) // Staff
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((5 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n > 16) //Shield
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((6 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
			
		if (n >= 36 && n <= 80) //Wings
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((12 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n >= 68 && n <= 81) //Jewels
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((14 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n >= 22 && n <= 31)
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((15 * MAXITEM) + n + 0x246, "Item\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}

		if (n > 33) // Helm
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((7 * MAXITEM) + n + 0x246, "Player\\", GL_REPEAT, GL_NEAREST,GL_TRUE);
		}
		if (n > 33) // Armor
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((8 * MAXITEM) + n + 0x246, "Player\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (n > 33) // pants
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((9 * MAXITEM) + n + 0x246, "Player\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (n > 33) // gloves
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((10 * MAXITEM) + n + 0x246, "Player\\", GL_REPEAT, GL_NEAREST, GL_TRUE);
		}
		if (n > 33) // Boots
		{
			((void(*)(int, char*, int, int, int))0x0067FB27)((11 * MAXITEM) + n + 0x246, "Player\\", GL_REPEAT, GL_NEAREST,GL_TRUE);
		}

	}
}

void ReadyItemManager()
{
	SetOp((LPVOID)0x0069607F, (LPVOID)&LoadModels, ASM::CALL);
	SetOp((LPVOID)0x00696094, (LPVOID)&LoadTextures, ASM::CALL);
}