#include "stdafx.h"
#include "BaseWindow.h"

CBaseWindow::CBaseWindow(void) : m_bIsGameRun(SDL_TRUE)
{
	SDL_Init(SDL_INIT_EVERYTHING);
}

CBaseWindow::~CBaseWindow(void)
{
	SDL_Quit();
}

bool CBaseWindow::Initialize()
{
	m_pWnd = SDL_CreateWindow("SDL_GameBase", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
	m_pRender = SDL_CreateRenderer(m_pWnd, -1, 0);

	return true;
}

void CBaseWindow::Terminate()
{
	SDL_DestroyRenderer(m_pRender);
	SDL_DestroyWindow(m_pWnd);
}