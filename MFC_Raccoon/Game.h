#pragma once

#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "Raccoon.h"
#include "Enemy.h"
#include "Item.h"
#include "Map.h"

// 게임에서 사용하는 키 지정 
#define LEFT		VK_LEFT
#define RIGHT		VK_RIGHT
#define UP			VK_UP
#define DOWN		VK_DOWN
#define	JUMP		VK_SPACE

// 마지막 레벨 
#define LAST_LEVEL	4

class CGame
{
public:
	CGame();
	~CGame();

	void HandleKeys();
	void GameCycle();
	void GameIntro();
	void GamePlay();
	void DrawDigit(CDC& cDC, int x, int y, int score, CBitmap& cBit, int cipher = 0, COLORREF crTransColor = RGB(0, 0, 0));
	void GameClear();
	void GameOver();
	void Init();

	CRect rect;

	bool _bIsDrawAll;
	char _GameState;
	int _iAni;
	char _iLevel;

	Map _Map;
	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];

	//더블 버퍼링을 위해  
	CBitmap		_cBit;

	//먹은 아이템의 점수 표시 시간 
	char		_ScoreShow;

	// 남은 시간
	int			_iTime;

	// 점수
	int			_iScore;

	//LETS
	CBitmap _hLets;
	// 'SCORE'
	CBitmap		_hScore;
	//Gameover
	CBitmap		_hGameOver;
	//BONUS
	CBitmap		_hBonus;
	//NEXT
	CBitmap		_hNext;
	//ENDING
	CBitmap		_hEnding;

	// 숫자
	CBitmap		_hDigit;
	CBitmap		_hDigit_sm;
	
	//아기
	CBitmap		_hBaby;

	// 먹은 과일이나 항아리 점수 증가폭 (2배씩 증가)
	int			_iItemScoreRate;

	// 너구리가 죽어서 떨어질때 음악 연주 상태
	BOOL _bIsDrop_Sound;
};

