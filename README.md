# dMusic - G2O Union Module

## Template Module
Refer to [Union Module Template](https://gitlab.com/GothicMultiplayerTeam/modules/union-template).

## Usage
**It only works on INSTANCES of Music, set in [MusicInst.d](https://github.com/VaanaCZ/gothic-2-addon-scripts/blob/Unified-EN/_work/Data/Scripts/System/Music/MusicInst.d)**

Play Music:
```js
//Example: /music OWD_Day_Std

addEventHandler("onCommand", function(cmd, params){
	cmd = cmd.tolower();
	switch(cmd){
		case "music":
			if(!params) return;

			playTheme(params.toupper());
		break;
	}
});
```

Stop Music:
```js
addEventHandler("onKeyDown", function(key){
	switch(key){
		case KEY_O:
			stopMusic();
		break;
		case KEY_P:
			muteMusic();
		break;
	}
});
```