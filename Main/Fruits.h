#ifndef _FRUITS_H
#define _FRUITS_H

class CFruits
{
public:
	void Load();
	
	static void SelectByteWord();
	static void SelectCaseAddPoint_0();
	static void SelectCaseAddPoint_1();
	static void SelectCaseAddPoint_2();
	static void SelectCaseAddPoint_3();
	static void SelectCaseAddPoint_4();
	static void SelectCaseAddPoint_default();
	static void SelectCaseRetPoint_0();
	static void SelectCaseRetPoint_1();
	static void SelectCaseRetPoint_2();
	static void SelectCaseRetPoint_3();
	static void SelectCaseRetPoint_4();
	static void SelectCaseRetPoint_default();
};

extern CFruits gFruits;

#endif