#pragma once

#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "Raccoon.h"
#include "Enemy.h"
#include "Item.h"
#include "Map.h"
#include "Logger.h"


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
	Enemy	_Ene[100];
	Item	_Item[100];

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
	
	// 너구리 맵 상대위치 보정값
	int			_adjY;

	// Logger
	CLogger		_log;

	bool is_up;
	
	
	//마그마함수
	void Magma();
	//용암이미지
	CBitmap _hLava;
	//경고 이미지
	CBitmap _hWarn;
	// 마그마 활성화됐니 안됐니
	bool _OnMagma;
	int _Magma_time;	//현재 남은시간과의 비교를 위해
	// 용암 랜덤 인덱스
	int _Magma_index;
};

