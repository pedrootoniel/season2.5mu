#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <SQL.H>
#include <SqlExt.H>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <process.h>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <winsock2.h>
#include <WinInet.h>
#include <ctime>
#include <time.h>
#include <rpc.h>
#include <rpcdce.h>
#include <Psapi.h>
//#include <atlstr.h>

#pragma warning(disable: 4996 4566 4060 4244 4018 4101 4800 4624)

#pragma comment(lib,"wininet.lib")
#define SEND_RQ(MSG) send(sock,MSG,strlen(MSG),0);
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"rpcrt4.lib")
#pragma comment(lib,"Psapi.lib")

//----------------------------------------------------------------------------------------//
#include "classe_init.h"
#include "correcao_base.h"
#include "protocolo.h"
#include "users.h"
#include "definicoes.h"
#include "csql.h"
#include "crecord.h"
#include "iniciar_csql.h"
#include "pontos_maximo.h"
#include "tokenizer.h"
#include "experiencia.h"
#include "bloodcastle.h"
#include "chaoscastle.h"
#include "devilsquare.h"
#include "drops.h"
#include "npctalk.h"
#include "reset.h"
#include "packets.h"
#include "mensagem.h"
#include "comandos.h"
#include "calcharacter.h"
#include "display.h"
#include "move.h"
#include "protect.h"
#include "shop.h"
#include "dsprotocol.h"
#include "gsclient.h"
#include "wings.h"
#include "protocol.h"
#include "map.h"
#include "Version.h"
#include "jewels.h"
#include "box.h"
#include "scroll.h"
#include "Bronze.h"
#include "Silver.h"
#include "Golden.h"
#include "ObjAttack.h"

void ReadCreateWindow();