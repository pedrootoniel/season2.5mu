#pragma once

#include "stdafx.h"

static HHOOK MouseHook = NULL; static HHOOK KeyboardHook = NULL;
#pragma data_seg()

BOOL KeyboardSetHook(BOOL set_or_remove);
BOOL MouseSetHook(BOOL set_or_remove);
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK MouseProc(int code, WPARAM wParam, LPARAM lParam);
extern bool Enable;