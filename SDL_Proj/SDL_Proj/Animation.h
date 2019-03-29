#pragma once

typedef struct tagAni
{
	SDL_Renderer* pRender;
	SDL_Texture* pObjImg[7];
	SDL_Rect rtClip;

	bool bIsSing = false;
	int numAni;
	 
}Ani;

Ani* InitAni(SDL_Renderer* pRenderer, const char* szUp, int nx, int ny);//������Ʈ ����
void Draw(Ani* obj); //������Ʈ �׸���
void Release(Ani* obj); //������Ʈ ���� or ����