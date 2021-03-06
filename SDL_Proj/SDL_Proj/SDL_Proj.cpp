#include "stdafx.h"
DEVMODE devmode;

void ChangeDisplay(int w, int h)
{
	ZeroMemory(&devmode, sizeof(DEVMODE));
	devmode.dmSize = sizeof(DEVMODE);
	devmode.dmBitsPerPel = 32;
	devmode.dmPelsWidth = w;
	devmode.dmPelsHeight = h;
	devmode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);
}

int main(int argc, char* argv[])
{
	int w, h;
	w = (int)GetSystemMetrics(SM_CXSCREEN);
	h = (int)GetSystemMetrics(SM_CXSCREEN);

	ChangeDisplay(1280, 720);

	CSystem* pSystem = new CSystem; //메모리 할당 //객체 생성

	pSystem->Initialize(); //초기화

	pSystem->Run(); //실행

	pSystem->Terminate(); //종료

	delete pSystem; //객체 삭제 //메모리 정리

	ChangeDisplay(w, h);

	return 0;
}

