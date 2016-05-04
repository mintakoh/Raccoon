#pragma once

#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "Raccoon.h"
#include "Enemy.h"
#include "Item.h"

// ���ӿ��� ����ϴ� Ű ���� 
#define LEFT		VK_LEFT
#define RIGHT		VK_RIGHT
#define UP			VK_UP
#define DOWN		VK_DOWN
#define	JUMP		VK_SPACE

// ó���� �־����� �ʱ��� �� 
#define	LIVE		7

// ������ ���� 
#define LAST_LEVEL	4

//�����Ҷ� ��ǥ  
struct jump
{
	char x;
	char y;
	char frame; //��������Ʈ�߿��� � �κ��� ������ ���ΰ�?
};

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
	void LoadMap();
	void CheckCollision();
	void CheckCollision_Enemy();
	void Init();

	CRect rect;

	bool _bIsDrawAll;
	char _GameState;
	int _iAni;
	char _iLevel;
	char _cMap[26][33];
	int _EnemyCount;

	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];
	jump	_StandJump[10];
	jump	_LeftShortJump[11];
	jump	_LeftLongJump[17];


	//���� ���۸��� ����  
	CBitmap		_cBit;

	//���� ���� ��
	char		_iEat;

	//���� �������� ���� ǥ�� �ð� 
	char		_ScoreShow;

	// ���� �ʱ��� ��
	char		_iLive;

	// ���� �ð�
	int			_iTime;

	// ����
	int			_iScore;




	// �⺻ �� ���� �̹��� 
	CBitmap _hMap;
	CBitmap _hMapEle[6];

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

	// �׾Ƹ�
	CBitmap		_hPot;

	//����
	CBitmap		_hFruit[4];

	// �ʱ��� �̹��� 
	CBitmap		_hLeft;
	CBitmap		_hRight;
	CBitmap		_hUpDown;
	CBitmap		_hStand;
	CBitmap		_hLeftJump;
	CBitmap		_hRightJump;
	CBitmap		_hDrop;
	CBitmap		_hDie;

	//��¦ ��� ����
	CBitmap _hSurprise;

	// ��
	CBitmap		_hEnemyRight;
	CBitmap		_hEnemyLeft;
	CBitmap		_hEnemyRightRed;
	CBitmap		_hEnemyLeftRed;

	//��
	CBitmap		_hSnakeLeft;
	CBitmap		_hSnakeRight;

	//�Ʊ�
	CBitmap		_hBaby;

	// ���� �����̳� �׾Ƹ� ���� ������ (2�辿 ����)
	int			_iItemScoreRate;

	// ������ �����ٶ� �ʿ��� ī����
	char _JumpFrame;
	// �ʱ����� �׾ �������� ���� ���� ����
	BOOL _bIsDrop_Sound;

};

