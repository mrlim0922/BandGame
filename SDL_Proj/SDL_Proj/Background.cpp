#include "stdafx.h"

#define STR_MAX		256

char strAniArray[][STR_MAX] = {
	"../Image/BG/Main.bmp",
	"../Image/BG/Ingame.bmp",
	"../Image/BG/Howto.bmp",
	"../Image/BG/Credit.bmp",
	NULL };

BACKGROUND* InitBackGround(SDL_Renderer* pRender)
{
	BACKGROUND* Temp;
	Temp = new BACKGROUND;

	Temp->pRender = pRender;
	Temp->select = BACKGROUND::MAIN;
	SDL_Surface* pImage = SDL_LoadBMP(strAniArray[Temp->select]);
	Temp->imgBackground = SDL_CreateTextureFromSurface(pRender, pImage);
	SDL_FreeSurface(pImage);

	return Temp;
}

void Draw(BACKGROUND* obj)
{
	if (obj == NULL) return;

	SDL_RenderCopy(obj->pRender, obj->imgBackground, NULL, NULL);
}

void Select(BACKGROUND* obj, int sel)
{
	if (obj == NULL) return;
	
	SDL_DestroyTexture(obj->imgBackground);
	SDL_Surface* pImage = SDL_LoadBMP(strAniArray[sel]);
	obj->imgBackground = SDL_CreateTextureFromSurface(obj->pRender, pImage);
	SDL_FreeSurface(pImage);
}

void Release(BACKGROUND* obj)
{
	if (obj == NULL) return;
	obj->pRender = NULL;
	SDL_DestroyTexture(obj->imgBackground);
	free(obj);
}