#pragma once

typedef struct S_BUTTON
{
	enum eButtonState { BUTTONDOWN, BUTTONUP };

	SDL_Texture* imgUp;
	SDL_Texture* imgDown;
	SDL_Texture* imgOver;
	SDL_Texture* imgCurrent;

	SDL_Rect rtClip;

	int nX, nY;
	bool bIsVisible = true;

	void(*func)(void);

}BUTTON;

BUTTON* InitButton(SDL_Renderer* screen, const char* szUp, const char* szDown, const char* szOver, int x, int y, void(*f)(void)); //�ʱ�ȭ
void Release(BUTTON* pBtn); //�޸�����
void Draw(SDL_Renderer* screen, BUTTON* pBtn); //�׸���

BUTTON::eButtonState GetState(BUTTON* pBtn); //��ư����
void ClickDown(BUTTON* pBtn);
void ClickUp(BUTTON* pBtn);

bool IsOver(BUTTON* pBtn, int px, int py); //��ǥ �����ֳ�
void Toggle(BUTTON* pBtn); //�ݴ�
void ResetOnUp(BUTTON* pBtn); //up����
void SetCoord(BUTTON* btn, int x, int y); //��ǥ�ٲٱ�
void SetVisible(BUTTON* btn, bool visible); //����
bool IsVisible(BUTTON* btn); //����°�

void MouseDown(BUTTON* pBtn, int px, int py);
void MouseUp(BUTTON* pBtn, int px, int py);
void MouseOver(BUTTON* pBtn, int px, int py);