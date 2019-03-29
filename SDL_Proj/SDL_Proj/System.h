#include "stdafx.h"

class CSystem : public CBaseWindow,
	public CTimeManager,
	public IInputHandler
	//public SoundManager
{
public:

public:
	CFrameSkip*		m_pGameFrame;
	CInputManager*	m_pInputManager;

public:
	CSystem(void);
	~CSystem(void);

private:
	void Pulse();

public:
	bool Initialize();
	void Terminate();
	void Run();

public:
	void KeyboardHandler();
	virtual void MouseHandler(MOUSESTATE mouseState);
public:
	SDL_Surface* imgSurface;
	SDL_Texture* imgBg;
	SDL_Texture* imgGame;
	SDL_Texture* imgCd;
	SDL_Texture* imgHowto;
public:
	BUTTON* btnIngame;
	BUTTON* btnHowTo;
	BUTTON* btnQuit;
	BUTTON* btnCredit;
	BUTTON* btnMain1;
	BUTTON* btnMain2;
	BUTTON* btnMain3;
	BUTTON* btnSound;
	BUTTON* btnSongs[5];

};

void IngameButton();
void HitButton();
void CreditButton();
void HowToButton();
void MainButton1();
void MainButton2();
void MainButton3();
void SoundButton();
void SongButton1();
void SongButton2();
void SongButton3();
void SongButton4();
void SongButton5();
void DrawAni();
