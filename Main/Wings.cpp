#include "StdAfx.h"


DWORD iWingAddExcellentOption_Buff;
__declspec(naked) void WingAddExcellentOption()
{
	_asm
	{
		MOV iWingAddExcellentOption_Buff, EAX
	}

	if((iWingAddExcellentOption_Buff >= ITEMGET(12, 0) && iWingAddExcellentOption_Buff <= ITEMGET(12, 6)) ||
		(iWingAddExcellentOption_Buff >= ITEMGET(12, 36) && iWingAddExcellentOption_Buff <= ITEMGET(12, 66)))
	{
		_asm
		{
			MOV EAX, 0x0058468B//005978CB  |. 8B45 EC        MOV EAX,DWORD PTR SS:[EBP-14]
			JMP EAX
		}
	}

	_asm
	{
		MOV EAX, 0x005847C7//00597A07
		JMP EAX
	}

}

DWORD iWingAddLuckOption_Buff;
__declspec(naked) void WingAddLuckOption()
{
	_asm
	{
		MOV iWingAddLuckOption_Buff, EAX
	}

	if((iWingAddLuckOption_Buff >= ITEMGET(12, 0)  && iWingAddLuckOption_Buff <= ITEMGET(12, 6))	||
	   (iWingAddLuckOption_Buff >= ITEMGET(12, 36) && iWingAddLuckOption_Buff <= ITEMGET(12, 66)	|| 
	    iWingAddLuckOption_Buff == ITEMGET(15, 30)))
	{
		_asm
		{
			MOV EAX, 0x00584ACE//00597E1F
			JMP EAX
		}
	}

	_asm
	{
		MOV EAX, 0x00584AEC //00597E3E  |> 8B4D 08        MOV ECX,DWORD PTR SS:[EBP+8]
		JMP EAX
	}
}

DWORD iWingAddLifeOption_Buff;
__declspec(naked) void WingAddLifeOption()
{
	_asm
	{
		MOV iWingAddLifeOption_Buff, EDX
	}

	if(iWingAddLifeOption_Buff == ITEMGET(12, 5) ||
		(iWingAddLifeOption_Buff >= ITEMGET(12, 36) && iWingAddLifeOption_Buff <= ITEMGET(12, 66)))
	{
		_asm
		{
			MOV EAX, 0x0058508F //0059841C
			JMP EAX
		}
	}

	_asm
	{
		MOV EAX, 0x00585108 //00598495  
		JMP EAX
	}
}

WORD iWingShowDurability_Buff;
__declspec(naked) void WingShowDurability()
{
	_asm
	{
		MOV iWingShowDurability_Buff, CX
	}

	if( iWingShowDurability_Buff < ITEMGET(12, 0)
		|| (iWingShowDurability_Buff >= ITEMGET(12, 36) && iWingShowDurability_Buff <= ITEMGET(12, 66))
		|| (iWingShowDurability_Buff >= ITEMGET(13, 0) && iWingShowDurability_Buff < ITEMGET(14, 0)) )
	{
		_asm
		{
			MOV ECX, 0x00602177 //00619DF3   > BA 01000000    MOV EDX,1


			JMP ECX
		}
	}

	_asm
	{
		MOV ECX, 0x00602165 //00619DD3 
		JMP ECX
	}
}


WORD iWingShowAdditional_Buff;
DWORD iWingSaltBuff;
DWORD iWingShowAdditionalAllow = 0x00601482;
DWORD iWingShowAdditionalReturn = 0x0060150C;
__declspec(naked) void WingShowAdditional()
{

	_asm
	{
		CMP CX, ITEMGET(12, 0)
		JL CheckNext
		CMP CX, ITEMGET(12, 6)
		JG CheckNext
		
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA ECX,DWORD PTR DS:[EDI+EDI+0x20]
		PUSH ECX
		PUSH 0x077D8210
		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
		LEA EAX,DWORD PTR DS:[EDX*4+0x79C1E10]
		PUSH EAX
		MOV iWingSaltBuff, 0x00755E60
		CALL iWingSaltBuff
		MOV EAX,DWORD PTR DS:[0x79F4B00]
		ADD ESP,0x0C
		LEA ECX,DWORD PTR DS:[EDI+EDI+0x19]
		MOV DWORD PTR DS:[EAX*4+0x79C2FAC],EBX
		MOV DWORD PTR DS:[EAX*4+0x79F1FA0],EBX
		INC EAX
		PUSH ECX
		MOV DWORD PTR DS:[0x79F4B00],EAX
		PUSH 0x077D833C
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
		LEA EAX,DWORD PTR DS:[EDX*4+0x79C1E10]
		PUSH EAX
		MOV iWingSaltBuff, 0x00755E60
		CALL iWingSaltBuff
		MOV EAX,DWORD PTR DS:[0x79F4B00]
		ADD ESP,0x0C
		MOV DWORD PTR DS:[EAX*4+0x79C2FAC],EBX
		MOV DWORD PTR DS:[EAX*4+0x79F1FA0],EBX
		INC EAX
		PUSH 0x077D8468
		MOV DWORD PTR DS:[0x79F4B00],EAX
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA ECX,DWORD PTR DS:[EAX+EAX*4]
		LEA EDX,DWORD PTR DS:[ECX*4+0x79C1E10]
		PUSH EDX
		MOV iWingSaltBuff, 0x00601386
		JMP iWingSaltBuff
CheckNext:
		CMP CX, ITEMGET(12, 36)
		JL CheckNext1
		CMP CX, ITEMGET(12, 66)
		JG CheckNext1

		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA ECX,DWORD PTR DS:[EDI+EDI+0x50]
		PUSH ECX
		PUSH 0x077D8210
		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
		LEA EAX,DWORD PTR DS:[EDX*4+0x79C1E10]
		PUSH EAX
		MOV iWingSaltBuff, 0x00755E60
		CALL iWingSaltBuff
		MOV EAX,DWORD PTR DS:[0x79F4B00]
		ADD ESP,0x0C
		LEA ECX,DWORD PTR DS:[EDI+EDI+0x89]
		MOV DWORD PTR DS:[EAX*4+0x79C2FAC],EBX
		MOV DWORD PTR DS:[EAX*4+0x79F1FA0],EBX
		INC EAX
		PUSH ECX
		MOV DWORD PTR DS:[0x79F4B00],EAX
		PUSH 0x077D833C
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
		LEA EAX,DWORD PTR DS:[EDX*4+0x79C1E10]
		PUSH EAX
		MOV iWingSaltBuff, 0x00755E60
		CALL iWingSaltBuff
		MOV EAX,DWORD PTR DS:[0x79F4B00]
		ADD ESP,0x0C
		MOV DWORD PTR DS:[EAX*4+0x79C2FAC],EBX
		MOV DWORD PTR DS:[EAX*4+0x79F1FA0],EBX
		INC EAX
		PUSH 0x077D8468
		MOV DWORD PTR DS:[0x79F4B00],EAX
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA ECX,DWORD PTR DS:[EAX+EAX*4]
		LEA EDX,DWORD PTR DS:[ECX*4+0x79C1E10]
		PUSH EDX
		MOV iWingSaltBuff, 0x00601386
		JMP iWingSaltBuff

CheckNext1:
		CMP CX, ITEMGET(13, 30)
		JL Return
		CMP CX, ITEMGET(13, 30)
		JG Return

		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA ECX,DWORD PTR DS:[EDI+EDI+0x50]
		PUSH ECX
		PUSH 0x077D8210
		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
		LEA EAX,DWORD PTR DS:[EDX*4+0x79C1E10]
		PUSH EAX
		MOV iWingSaltBuff, 0x00755E60
		CALL iWingSaltBuff
		MOV EAX,DWORD PTR DS:[0x79F4B00]
		ADD ESP,0x0C
		LEA ECX,DWORD PTR DS:[EDI+EDI+0x89]
		MOV DWORD PTR DS:[EAX*4+0x79C2FAC],EBX
		MOV DWORD PTR DS:[EAX*4+0x79F1FA0],EBX
		INC EAX
		PUSH ECX
		MOV DWORD PTR DS:[0x79F4B00],EAX
		PUSH 0x077D833C
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA EDX,DWORD PTR DS:[EAX+EAX*4]
		LEA EAX,DWORD PTR DS:[EDX*4+0x79C1E10]
		PUSH EAX
		MOV iWingSaltBuff, 0x00755E60
		CALL iWingSaltBuff
		MOV EAX,DWORD PTR DS:[0x79F4B00]
		ADD ESP,0x0C
		MOV DWORD PTR DS:[EAX*4+0x79C2FAC],EBX
		MOV DWORD PTR DS:[EAX*4+0x79F1FA0],EBX
		INC EAX
		PUSH 0x077D8468
		MOV DWORD PTR DS:[0x79F4B00],EAX
		LEA EAX,DWORD PTR DS:[EAX+EAX*4]
		LEA ECX,DWORD PTR DS:[EAX+EAX*4]
		LEA EDX,DWORD PTR DS:[ECX*4+0x79C1E10]
		PUSH EDX
		MOV iWingSaltBuff, 0x00601386
		JMP iWingSaltBuff

Return:

		JMP iWingShowAdditionalReturn
	}
}


DWORD iWingHideExcellentText_Buff;
__declspec(naked) void WingHideExcellentText()
{
	_asm
	{
		CMP CX, 0x1A1E
		JNZ Next

		MOV iWingHideExcellentText_Buff, 0x005FF154
		JMP iWingHideExcellentText_Buff
Next:
		CMP CX, ITEMGET(12, 0)
		JL Next1
		CMP CX, ITEMGET(12, 3)
		JG Next1

		MOV iWingHideExcellentText_Buff, 0x005FF154
		JMP iWingHideExcellentText_Buff
Next1:
		CMP CX, ITEMGET(12, 36)
		JL Return
		CMP CX, ITEMGET(12, 66)
		JG Return

		MOV iWingHideExcellentText_Buff, 0x005FF154
		JMP iWingHideExcellentText_Buff

Return:

		MOV iWingHideExcellentText_Buff, 0x005FF17B
		JMP iWingHideExcellentText_Buff
	}
}

DWORD iWingHideExcellentGlow_Buff;
DWORD iWingHideExcellentGlow_Buff2;
__declspec(naked) void WingHideExcellentGlow()
{
	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP+0x8]
		MOVSX ECX, WORD PTR DS:[EAX+0x2]
		MOV iWingHideExcellentGlow_Buff, ECX
	}

	if( iWingHideExcellentGlow_Buff >= ITEM_GET(12, 0) && iWingHideExcellentGlow_Buff <= ITEM_GET(12, 6) 
	 || iWingHideExcellentGlow_Buff >= ITEM_GET(12, 36) && iWingHideExcellentGlow_Buff <= ITEM_GET(12, 66) )
	{
		_asm
		{
			mov iWingHideExcellentGlow_Buff2, 0x0067C623
			jmp iWingHideExcellentGlow_Buff2
		}
	}
	else
	{
		_asm
		{
			mov iWingHideExcellentGlow_Buff2, 0x0067C570
			jmp iWingHideExcellentGlow_Buff2
		}
	}
}

DWORD AddWingCharSet_Buff;
BYTE	WingsAddCharSet_CharSet17;
WORD	WingsAddCharSet_CharSet17_Pointer;
DWORD	WingsAddCharSet_CharSet17_Buff;
__declspec(naked) void AddWingCharSet()
{
	_asm
    {
		mov ecx, dword ptr ss:[ebp+0x0c]
        xor edx, edx
        mov dl, byte ptr ds:[ecx+0x10]
        sar edx, 2
        and edx, 0x000000F
        mov byte ptr ss:[ebp-4], dl
        mov eax, dword ptr ss:[ebp-4]
        and eax, 0x000000FF
        mov WingsAddCharSet_CharSet17_Buff, eax
    }

	if( WingsAddCharSet_CharSet17_Buff > 0 )
    {
        _asm
        {
            mov cl, byte ptr ss:[ebp-4]
            mov byte ptr ss:[ebp-0x3c], cl
            mov WingsAddCharSet_CharSet17, cl
        }
    }
	else
	{
		goto OriginalFunc;
	}

	if( WingsAddCharSet_CharSet17 > 0 )
    {
		WingsAddCharSet_CharSet17_Pointer = ITEM_GET(12, (35 + WingsAddCharSet_CharSet17));

        _asm
        {
            mov edx, dword ptr ss:[ebp-8]
			mov ax, WingsAddCharSet_CharSet17_Pointer
            mov word ptr ds:[edx+0x338], ax
        }
    }
	
OriginalFunc:

	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP+0x14]
		MOV AddWingCharSet_Buff, EAX
	}

	if(AddWingCharSet_Buff != 0)
	{
		_asm
		{
			MOV AddWingCharSet_Buff,  0x0053344C
			JMP AddWingCharSet_Buff
		}
	}
	else
	{
		_asm
		{
			MOV AddWingCharSet_Buff,  0x0053343E
			JMP AddWingCharSet_Buff
		}
	}
}


DWORD iWingEnableMoveIcarus_Buff;
__declspec(naked) void WingEnableMoveIcarus()
{
	_asm
	{
		MOV iWingEnableMoveIcarus_Buff, ECX
	}


	if(iWingEnableMoveIcarus_Buff == ITEMGET(13, 30) || iWingEnableMoveIcarus_Buff >= ITEMGET(12, 36) && iWingEnableMoveIcarus_Buff <= ITEMGET(12, 66))
	{
		_asm
		{
			MOV EAX, 0x00460F80//0046822F
			JMP EAX
		}
	}
	else
	{
		_asm
		{
			MOV EAX, 0x00460F5D//0046820C
			JMP EAX
		}
	}
}

DWORD iWingEnableMoveIcarus2_Buff;
__declspec(naked) void WingEnableMoveIcarus2()
{
	_asm
	{
		MOV iWingEnableMoveIcarus2_Buff, EDX
	}


	if(iWingEnableMoveIcarus2_Buff == ITEMGET(13, 30) || iWingEnableMoveIcarus2_Buff >= ITEMGET(12, 36) && iWingEnableMoveIcarus2_Buff <= ITEMGET(12, 66))
	{
		_asm
		{
			MOV EAX, 0x004608E4//004689F7
			JMP EAX
		}
	}
	else
	{
		_asm
		{
			MOV EAX, 0x004608C1 //004689D4
			JMP EAX
		}
	}
}

DWORD iWingEnableMoveKanturuEvent_Buff;
__declspec(naked) void WingEnableMoveKanturuEvent()
{
	_asm
	{
		MOV iWingEnableMoveKanturuEvent_Buff, EDX
	}


	if(iWingEnableMoveKanturuEvent_Buff == ITEMGET(13, 30) || iWingEnableMoveKanturuEvent_Buff >= ITEMGET(12, 36) && iWingEnableMoveKanturuEvent_Buff <= ITEMGET(12, 66))
	{
		_asm
		{
			MOV EAX, 0x00431060 //00434FBD 
			JMP EAX
		}
	}
	else
	{
		_asm
		{
			MOV EAX, 0x00431032//00434F90
			JMP EAX
		}
	}

}

WORD iWingEnableMoveKanturuEvent2_Buff;
__declspec(naked) void WingEnableMoveKanturuEvent2()
{
	/*_asm
	{
		MOV iWingEnableMoveKanturuEvent2_Buff, CX
	}


	if(iWingEnableMoveKanturuEvent2_Buff == ITEMGET(13, 30) || iWingEnableMoveKanturuEvent2_Buff >= ITEMGET(12, 36) && iWingEnableMoveKanturuEvent2_Buff <= ITEMGET(12, 66))
	{
		_asm
		{
			MOV EAX, 0x005DAFDC
			JMP EAX
		}
	}
	else
	{*/
		_asm
		{
			MOV EAX, 0x0043159D
			JMP EAX
		}
	//}

}

__declspec(naked) void WingsDisableShine()
{
	static DWORD Pointer;
	static DWORD SubPointer;
	static DWORD DisableShine;

	_asm
	{
		MOV Pointer, ECX
			SUB ECX, ITEM_GET(12,15)
			MOV SubPointer, ECX
			MOV DWORD PTR SS:[EBP-0x138], ECX
	}

	if (Pointer >= ITEM_GET(12,36) && Pointer <= ITEM_GET(12,66))
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-8],0
		}
	}

	if (Pointer == ITEM_GET(12,15) /*|| Pointer >= ITEM_GET(14, 0) && Pointer <= ITEM_GET(14, 3)*/)
	{
		_asm
		{
			MOV DWORD PTR SS:[EBP-8],8
		}
	}

	if (SubPointer > 32)
	{
		_asm
		{
			MOV DisableShine, 0x679E86
				JMP DisableShine
		}
	}
	else
	{
		_asm
		{
			MOV DisableShine, 0x679A1A
				JMP DisableShine
		}
	}
}

void NewWingHook()
{
	SetNop(0x679AE2,19);
	HookJump(0x679AE2, WingsDisableShine);

	SetRange((LPVOID)0x0058466E, 10, ASM::NOP);
	SetOp((LPVOID)0x0058466E, (LPVOID)WingAddExcellentOption, ASM::JMP);
	
	SetRange((LPVOID)0x00460F55, 8, ASM::NOP);
	SetOp((LPVOID)0x00460F55, (LPVOID)WingEnableMoveIcarus, ASM::JMP);

	SetRange((LPVOID)0x004608B9, 8, ASM::NOP);
	SetOp((LPVOID)0x004608B9, (LPVOID)WingEnableMoveIcarus2, ASM::JMP);

	SetRange((LPVOID)0x0043102A, 8, ASM::NOP);
	SetOp((LPVOID)0x0043102A, (LPVOID)WingEnableMoveKanturuEvent, ASM::JMP);
	
	SetRange((LPVOID)0x00431585, 10, ASM::NOP);
	SetOp((LPVOID)0x00431585, (LPVOID)WingEnableMoveKanturuEvent2, ASM::JMP);

	SetRange((LPVOID)0x00584AB8, 10, ASM::NOP);
	SetOp((LPVOID)0x00584AB8, (LPVOID)WingAddLuckOption, ASM::JMP);
	

	SetRange((LPVOID)0x00585087, 8, ASM::NOP);
	SetOp((LPVOID)0x00585087, (LPVOID)WingAddLifeOption, ASM::JMP);


	SetRange((LPVOID)0x00602150, 7, ASM::NOP);
	SetOp((LPVOID)0x00602150, (LPVOID)WingShowDurability, ASM::JMP);


	SetRange((LPVOID)0x0060146C, 22, ASM::NOP);
	SetOp((LPVOID)0x0060146C, (LPVOID)WingShowAdditional, ASM::JMP);

	SetRange((LPVOID)0x005FF14D, 7, ASM::NOP);
	SetOp((LPVOID)0x005FF14D, (LPVOID)WingHideExcellentText, ASM::JMP);

	SetRange((LPVOID)0x0067C54F, 7, ASM::NOP);
	SetOp((LPVOID)0x0067C54F, (LPVOID)WingHideExcellentGlow, ASM::JMP);
	

	SetRange((LPVOID)0x00533438, 6, ASM::NOP);
	SetOp((LPVOID)0x00533438, (LPVOID)AddWingCharSet, ASM::JMP);

	
}