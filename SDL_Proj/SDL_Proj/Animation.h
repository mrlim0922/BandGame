#pragma once

typedef struct tagAni
{
	SDL_Renderer* pRender;
	SDL_Texture* pObjImg[7];
	SDL_Rect rtClip;

	bool bIsSing = false;
	int numAni;
	 
}Ani;

Ani* InitAni(SDL_Renderer* pRenderer, const char* szUp, int nx, int ny);//오브젝트 생성
void Draw(Ani* obj); //오브젝트 그리기
void Release(Ani* obj); //오브젝트 해제 or 종료