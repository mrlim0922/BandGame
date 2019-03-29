#pragma once

typedef struct tagBackground
{
	enum {
		MAIN, INGAME, HOWTO, CREDIT
	};
	SDL_Renderer* pRender;
	SDL_Texture* imgBackground;
	int select;

}BACKGROUND;

BACKGROUND* InitBackGround(SDL_Renderer* pRender);
void Draw(BACKGROUND* obj);
void Select(BACKGROUND* obj, int sel);
void Release(BACKGROUND* obj);