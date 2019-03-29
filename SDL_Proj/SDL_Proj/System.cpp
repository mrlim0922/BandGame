#include "stdafx.h"

//bool bIsGameRun = true;

int state;
BACKGROUND *bg;
bool bIsSong1 = true;
Ani* Panda;
Ani* Rabit;
Ani* Hamster;
Ani* Dog;
Ani* Cat;
SoundManager* Sound;
float frame = 1;

enum {
	MAIN, INGAME, HOWTO, CREDIT, STOP = 0, PLAY, PAUSE
};


CSystem::CSystem(void)
{

}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize()
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(7);


	m_pInputManager = new CInputManager;
	m_pInputManager->SetInputHandler(this);

	Sound = new SoundManager;
	Sound->AddSong("song1.mp3");
	Sound->AddSong("song2.mp3");
	Sound->AddSong("song3.mp3");
	Sound->AddSong("song4.mp3");
	Sound->AddSong("song5.mp3");

	bg = InitBackGround(m_pRender);

	Panda = InitAni(m_pRender, "../Image/Animation/panda", 5 - 65, 210);
	Rabit = InitAni(m_pRender, "../Image/Animation/rabit", 380, -30);
	Hamster = InitAni(m_pRender, "../Image/Animation/Hamster", 420, 210);
	Dog = InitAni(m_pRender, "../Image/Animation/dog", 70, -30);
	Cat = InitAni(m_pRender, "../Image/Animation/cat", 170, 210);

	btnQuit = InitButton(m_pRender,
		"../Image/Button/ExitBtn_up.bmp", "../Image/Button/ExitBtn_down.bmp","../Image/Button/ExitBtn_down.bmp",
		940, 580, HitButton); //버튼 이미지 초기화
	btnCredit = InitButton(m_pRender,
		"../Image/Button/CreditBtn_up.bmp", "../Image/Button/CreditBtn_down.bmp", "../Image/Button/CreditBtn_up.bmp",
		700, 580, CreditButton); //버튼 이미지 초기화
	btnHowTo = InitButton(m_pRender,
		"../Image/Button/HowToBtn_up.bmp", "../Image/Button/HowToBtn_down.bmp", "../Image/Button/HowToBtn_down.bmp",
		455, 580, HowToButton); //버튼 이미지 초기화
	btnMain1 = InitButton(m_pRender,
		"../Image/Button/MainBtn_up.bmp", "../Image/Button/MainBtn_down.bmp", "../Image/Button/MainBtn_down.bmp",
		100, 75, MainButton1);
	btnMain2 = InitButton(m_pRender,
		"../Image/Button/MainBtn_up.bmp", "../Image/Button/MainBtn_down.bmp", "../Image/Button/MainBtn_down.bmp",
		100, 75, MainButton2);
	btnMain3 = InitButton(m_pRender,
		"../Image/Button/MainBtn_up.bmp", "../Image/Button/MainBtn_down.bmp", "../Image/Button/MainBtn_down.bmp",
		100, 75, MainButton2);
	btnIngame = InitButton(m_pRender,
		"../Image/Button/PlayBtn_up.bmp", "../Image/Button/PlayBtn_down.bmp", "../Image/Button/PlayBtn_down.bmp",
		155, 560, IngameButton);

	btnSound = InitButton(m_pRender,
		"../Image/Button/PlayBtn.bmp", "../Image/Button/PauseBtn.bmp", "../Image/Button/PauseBtn.bmp",
		1020, 130, SoundButton);

	btnSongs[0] = InitButton(m_pRender,
		"../Image/Button/song1_up.bmp", "../Image/Button/song1_down.bmp", "../Image/Button/song1_over.bmp",
		960, 230, SongButton1);
	btnSongs[1] = InitButton(m_pRender,
		"../Image/Button/song2_up.bmp", "../Image/Button/song2_down.bmp", "../Image/Button/song2_over.bmp",
		960, 330, SongButton2);
	btnSongs[2] = InitButton(m_pRender,
		"../Image/Button/song3_up.bmp", "../Image/Button/song3_down.bmp", "../Image/Button/song3_over.bmp",
		960, 430, SongButton3);
	btnSongs[3] = InitButton(m_pRender,
		"../Image/Button/song4_up.bmp", "../Image/Button/song4_down.bmp", "../Image/Button/song4_over.bmp",
		960, 530, SongButton4);
	btnSongs[4] = InitButton(m_pRender,
		"../Image/Button/song5_up.bmp", "../Image/Button/song5_down.bmp", "../Image/Button/song5_over.bmp",
		960, 630, SongButton5);
	//ball = InitAni(m_pRender);
	return true;
}

void CSystem::Pulse()
{
	CTimeManager::Pulse();
	m_pInputManager->Pulse();

	float fTimeStep = CTimeManager::GetTimeStep();
	float fTimeGet = CTimeManager::GetTime();

	printf("%f ", fTimeGet);

	if (m_pGameFrame->Update(fTimeStep))
	{
		SDL_SetRenderDrawColor(m_pRender, MIN8, MIN8, MAX8, MAX8);
		SDL_RenderClear(m_pRender);

		Draw(bg);

		switch (state) {
		case MAIN:
			//Sound->ChangeCurrentState(0);
			Draw(m_pRender, btnHowTo);
			Draw(m_pRender, btnCredit);
			Draw(m_pRender, btnQuit);
			Draw(m_pRender, btnIngame);
			break;
		case CREDIT:
			Draw(m_pRender, btnMain2);
			break;
		case HOWTO:
			Draw(m_pRender, btnMain1);
			break;
		case INGAME:
			Draw(m_pRender, btnSound);
			Draw(m_pRender, btnMain3);
			Draw(Panda);
			Draw(Rabit);
			Draw(Hamster);
			Draw(Dog);
			Draw(Cat);
			for (int i = 0; i < 5; i++)
				Draw(m_pRender, btnSongs[i]);
			break;
		}
	}
	SDL_RenderPresent(m_pRender);
	
}

void CSystem::Terminate()
{
	//오브젝트 종료
	for (int i = 0; i < 5; i++)
		Release(btnSongs[i]);
	Sound->Release();
	Release(btnSound);
	Release(btnMain1);
	Release(btnMain2);
	Release(btnMain3);
	Release(btnIngame);
	Release(btnQuit);
	Release(btnCredit);
	Release(btnHowTo);
	Release(Panda);
	Release(Rabit);
	Release(Hamster);
	Release(Dog);
	Release(Cat);
	Release(bg);

	m_pInputManager->Terminate();

	CBaseWindow::Terminate();
	CTimeManager::Terminate();
}

void CSystem::Run()
{
	while (m_bIsGameRun)
	{
		Pulse(); //Update()
	}
}

void MainButton1()
{
	bg->select = BACKGROUND::MAIN;
	Select(bg, bg->select);
	state = MAIN;
}

void MainButton2()
{
	bg->select = BACKGROUND::MAIN;
	Select(bg, bg->select);
	state = MAIN;
}

void MainButton3()
{
	bg->select = BACKGROUND::MAIN;
	Select(bg, bg->select);
	state = MAIN;
}

void HowToButton()
{
	bg->select = BACKGROUND::HOWTO;
	Select(bg, bg->select);
	state = HOWTO;
}

void CreditButton()
{
	bg->select = BACKGROUND::CREDIT;
	Select(bg, bg->select);
	state = CREDIT;
}

void IngameButton()
{
	bg->select = BACKGROUND::INGAME;
	Select(bg, bg->select);
	state = INGAME;
}

void HitButton()
{
	Sound->ChangeCurrentState(0);
	SDL_Quit();
}

void SoundButton()
{
	if (bIsSong1 == true)
	{
		Sound->ChangeCurrentState(PLAY);
		frame = 7;
		Sound->SongStateSet();
		bIsSong1 = false;
		Panda->bIsSing = true;
		Rabit->bIsSing = true;
		Hamster->bIsSing = true;
		Dog->bIsSing = true;
		Cat->bIsSing = true;
	}
	else if (bIsSong1 == false)
	{
		Sound->ChangeCurrentState(PAUSE);
		frame = 1;
		Sound->SongStateSet();
		bIsSong1 = true;
		Panda->bIsSing = false;
		Rabit->bIsSing = false;
		Hamster->bIsSing = false;
		Dog->bIsSing = false;
		Cat->bIsSing = false;
	}
}

void SongButton1()
{
	if (bIsSong1 == true) 
	{
		printf("1\n");
		Sound->ChangeCurrentSong(0);
	}
}

void SongButton2()
{
	if (bIsSong1 == true)
	{
		printf("2\n");
		Sound->ChangeCurrentSong(1);
	}
}

void SongButton3()
{
	if (bIsSong1 == true)
	{
		printf("3\n");
		Sound->ChangeCurrentSong(2);
	}
}
void SongButton4()
{
	if (bIsSong1 == true)
	{
		printf("4\n");
		Sound->ChangeCurrentSong(3);
	}
}
void SongButton5()
{
	if (bIsSong1 == true)
	{
		printf("5\n");
		Sound->ChangeCurrentSong(4);
	}
}

void DrawAni()
{

}

#define g_pKeyCodeScan(vk) (m_pInputManager->GetOldKeyState(vk)&&m_pInputManager->GetCurKeyState(vk))

void CSystem::KeyboardHandler() //키보드 입력
{
	if (g_pKeyCodeScan(SDLK_ESCAPE))
		this->m_bIsGameRun = SDL_FALSE;
}

void CSystem::MouseHandler(MOUSESTATE mouseState)
{
	static SDL_bool bIsClk = SDL_TRUE;
	if (mouseState.bIsDown[MouseButton::LEFT] && bIsClk)
	{
		if (state == MAIN)
		{
			MouseDown(btnHowTo, mouseState.x, mouseState.y);
			MouseDown(btnCredit, mouseState.x, mouseState.y);
			MouseDown(btnIngame, mouseState.x, mouseState.y);
			MouseDown(btnQuit, mouseState.x, mouseState.y);
			bIsClk = SDL_FALSE;
		}
		if (state == INGAME)
		{
			bIsClk = SDL_FALSE;
			MouseDown(btnMain3, mouseState.x, mouseState.y);
			MouseDown(btnSound, mouseState.x, mouseState.y);
			for (int i = 0; i < 5; i++)
				MouseDown(btnSongs[i], mouseState.x, mouseState.y);
		}
		if (state == HOWTO)
		{
			MouseDown(btnMain1, mouseState.x, mouseState.y);
			bIsClk = SDL_FALSE;

		}
		if (state == CREDIT)
		{
			MouseDown(btnMain2, mouseState.x, mouseState.y);
			//bIsClk = SDL_FALSE;

		}
	}
	if (mouseState.bIsUp[MouseButton::LEFT])
	{
		if (state == MAIN)
		{
			MouseUp(btnHowTo, mouseState.x, mouseState.y);
			MouseUp(btnCredit, mouseState.x, mouseState.y);
			MouseUp(btnIngame, mouseState.x, mouseState.y);
			MouseUp(btnQuit, mouseState.x, mouseState.y);
			bIsClk = SDL_TRUE;
		}
		if (state == INGAME)
		{
			bIsClk = SDL_TRUE;
			MouseUp(btnMain3, mouseState.x, mouseState.y);
			if (bIsSong1)
				MouseUp(btnSound, mouseState.x, mouseState.y);
			for (int i = 0; i < 5; i++)
				MouseUp(btnSongs[i], mouseState.x, mouseState.y);
		}
		if (state == HOWTO)
		{
			MouseUp(btnMain1, mouseState.x, mouseState.y);
			bIsClk = SDL_TRUE;
		}
		if (state == CREDIT)
		{
			MouseUp(btnMain2, mouseState.x, mouseState.y);
			bIsClk = SDL_TRUE;
		}
	}
	MouseOver(btnHowTo, mouseState.x, mouseState.y);
	MouseOver(btnCredit, mouseState.x, mouseState.y);
	MouseOver(btnIngame, mouseState.x, mouseState.y);
	MouseOver(btnQuit, mouseState.x, mouseState.y);
	MouseOver(btnMain1, mouseState.x, mouseState.y);
	MouseOver(btnMain2, mouseState.x, mouseState.y);
	MouseOver(btnMain3, mouseState.x, mouseState.y);
	for (int i = 0; i < 5; i++)
		MouseOver(btnSongs[i], mouseState.x, mouseState.y);

}
