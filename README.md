# dMusic - G2O Union Module

## Template Module
Refer to [Union Module Template](https://gitlab.com/GothicMultiplayerTeam/modules/union-template).

## Usage
Play Music:
```js
addEventHandler("onCommand", function(cmd, params){
	cmd = cmd.tolower();
	switch(cmd){
		case "music":
			if(!params) return;

			playTheme(params.toupper());
		break;
	}
});```

Stop Music:
```js
addEventHandler("onKeyDown", function(key){
	switch(key){
		case KEY_O:
			stopTheme();
		break;
	}
});
```