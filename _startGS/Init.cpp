#include "stdafx.h"

void iniciar_hook()
{
	_iniciar_comandos._comandos_config();
	_mensagem_all->_mensagem_load(".\\configurações\\_administrador.settings\\_settings.mensagem.ID");
	_maximo.loadfile(".\\configurações\\_player.settings\\_settings.pontos.ID");
	_experiencia.iniciar_experiencia();
	_blood._iniciar_blood_castle(".\\configurações\\_eventos.settings\\_settings.blood_castle.ID");
	_chaos._iniciar_chaos_castle(".\\configurações\\_eventos.settings\\_settings.chaos_castle.ID");
	_devil._iniciar_devil_square(".\\configurações\\_eventos.settings\\_settings.devil_square.ID");
	_drop._drop_custom_load(".\\configurações\\_administrador.settings\\_settings.drop.ID");
	HookFunc(0x004017C6, (DWORD)(&gObjGameMonsterAllAdd));
	_reset_iniciar._reset_loadfile(".\\configurações\\_administrador.settings\\_settings.reset.ID");
	hook_proc(0x00403314, (DWORD)(&_ProtocolCore));
	hook_proc(0x0040533F, (DWORD)(DataSend_Hook));
	hook_proc(0x00402B08, (DWORD)(&gObjCalCharacter_Hook));
	hook_proc(0x00404D4F, (DWORD)(&_gObjLevelUpPointAdd));
	HookFunc(0x004060C3, (DWORD)(&gObjGCLevelUpMsgSend));
	hook_proc(0x004057EA, (DWORD)(&_gObjSetCharacter));
	HookFunc(0x00401F3C, (DWORD)(&gObjLotteryItemMix));
	hook_proc(0x004E2C20, (DWORD)(&_experience_hook));                 iniciar_nopear(0x004E2C25, 9);
	hook_proc(0x004E3315, (DWORD)(&_experience_hook_party));           iniciar_nopear(0x004E331A, 9);
	hook_proc(0x004E3452, (DWORD)(&_experience_hook_party_zen));       iniciar_nopear(0x004E3457, 9);
	hook_proc(0x004658B9, (DWORD)(&_experience_hook_devil));           iniciar_nopear(0x004658BE, 9);
	hook_proc(0x00465F0E, (DWORD)(&_experience_hook_party_devil));     iniciar_nopear(0x00465F13, 9);
	hook_proc(0x00466069, (DWORD)(&_experience_hook_party_devil_zen)); iniciar_nopear(0x0046606E, 9);
	_vip.VipSettings();
	hook_proc(0x004033F5, (DWORD)(&_blood_castle_hook));
	hook_proc(0x00401CAD, (DWORD)(&_chaos_castle_hook));
	hook_proc(0x00467E5A, (DWORD)(&_devil_square_hook)); iniciar_nopear(0x00467E5A+5, 3);
	hook_proc(0x00404E4E, (DWORD)(&_gObjMonsterDrop));
	hook_proc(0x00402FB3, (DWORD)(&_NpcTalk));
	hook_proc(0x00405E7A, (DWORD)(&_gObjAttack));
	hook_proc(0x0040202C, (DWORD)(&GCGuildWarRequestResult));
	SetOp((LPVOID)0x004057BD, (LPVOID)ProtocolDS, ASM::JMP);
	HookFunc(0x00496607, (DWORD)(&gObjRateMixLevel));
	HookNop(0x00496607+5, 239);
	HookFunc(0x004051EB, (DWORD)(&gObjSecondProcEx));
	HookThis((DWORD)&InterfaceTimeCheck_,         0x00405BDC);
	OFFTrade.Init();	
	//Monster Item Drop
	*(DWORD*)((0x00404E4E+1)) = (DWORD)&MygEventMonsterItemDrop - (0x00404E4E+5);
	HookThis((DWORD)&CGSellRequestRecv_Hook,0x00403120);
	HookThis((DWORD)&CGPShopReqBuyItem_Hook,0x00406226);

	//
	ReadyLicense();
}
