#include "sqFunction.h"
//#include "sqUtils.h"

void sq_playTheme(char* musicInst)
{
		if (zmusic) zmusic->Stop();		
	zmusic->PlayThemeByScript(musicInst, 0, 0);
}

void sq_stopMusic()
{
	if(zmusic) zmusic->Stop();
}

/* void sq_getTheme() {
	zCMusicTheme* GetActiveTheme();
	// figure out how to return this
} */

void sq_muteMusic()
{
	if(zmusic) zmusic->Mute();
}