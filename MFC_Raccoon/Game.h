#pragma once

#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "Raccoon.h"
#include "Enemy.h"
#include "Item.h"
#include "Map.h"

// ���ӿ��� ����ϴ� Ű ���� 
#define LEFT		VK_LEFT
#define RIGHT		VK_RIGHT
#define UP			VK_UP
#define DOWN		VK_DOWN
#define	JUMP		VK_SPACE

// ������ ���� 
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

	//���� ���۸��� ����  
	CBitmap		_cBit;

	//���� �������� ���� ǥ�� �ð� 
	char		_ScoreShow;

	// ���� �ð�
	int			_iTime;

	// ����
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

	// ����
	CBitmap		_hDigit;
	CBitmap		_hDigit_sm;
	
	//�Ʊ�
	CBitmap		_hBaby;

	// ���� �����̳� �׾Ƹ� ���� ������ (2�辿 ����)
	int			_iItemScoreRate;

	// �ʱ����� �׾ �������� ���� ���� ����
	BOOL _bIsDrop_Sound;
};

