#pragma once

#include <sqapi.h>

#include <ZenGin/zGothicAPI.h>
#define ENGINE Engine_G2A

using namespace Gothic_II_Addon;

void sq_playTheme(char* musicInst);
void sq_stopMusic();
// void sq_getTheme();
void sq_muteMusic();