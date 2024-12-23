#pragma once

#include <sqapi.h>

#include <ZenGin/zGothicAPI.h>
#define ENGINE Engine_G2A

using namespace Gothic_II_Addon;

SQInteger sq_playTheme(HSQUIRRELVM vm);
SQInteger sq_stopTheme(HSQUIRRELVM vm);