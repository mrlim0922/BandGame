#include "stdafx.h"

#define STR_MAX		256

const char strAniArray[][STR_MAX] = {
	"1.bmp",
	"2.bmp",
	"3.bmp",
	"4.bmp",
	//"5.bmp",
	//"6.bmp",
	//"7.bmp",
	NULL };


Ani* InitAni(SDL_Renderer* pRenderer, const char* szUp, int nx, int ny)         //오브젝트 생성
{
	Ani* Temp;
	Temp = new Ani; //동적할당

	Temp->pRender = pRenderer;
	char array[4][STR_MAX] = {
		"",
		"",
		"",
		""
		//"",
		//"",
		//""
	};

	for (int i = 0; i < 4; i++) {

		strcat_s(array[i], (char*)szUp);
		strcat_s(array[i], strAniArray[i]);

		SDL_Surface* pAniImage = SDL_LoadBMP(array[i]);
		//스프라이트 처리=======================================
		Uint32 ColorKey = SDL_MapRGB(pAniImage->format, 255, 0, 255);
		SDL_SetColorKey(pAniImage, SDL_TRUE, ColorKey);
		//======================================================
		Temp->pObjImg[i] = SDL_CreateTextureFromSurface(pRenderer, pAniImage);
		Temp->rtClip.x = nx;
		Temp->rtClip.y = ny;
		Temp->rtClip.w = pAniImage->w;
		Temp->rtClip.h = pAniImage->h;

		SDL_FreeSurface(pAniImage);
	}
	return Temp;
}

void Draw(Ani* obj)
{
	if (obj == NULL) return;
	static int AniCount = 0;

	if (obj->bIsSing)SDL_RenderCopy(obj->pRender, obj->pObjImg[AniCount], NULL, &obj->rtClip);
	else SDL_RenderCopy(obj->pRender, obj->pObjImg[0], NULL, &obj->rtClip);

	if (AniCount >= 3) AniCount = 0;
	else AniCount++;
}

void Release(Ani* obj)
{
	if (obj == NULL) return;
	for (int j = 0; j < 4; j++) {
		obj->pRender = NULL;
		SDL_DestroyTexture(obj->pObjImg[j]);
		free(obj);
	}
}