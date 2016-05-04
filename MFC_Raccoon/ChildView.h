
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once

#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "afxwin.h"



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

//�ʱ���
struct Raccoon
{
	int x;			//x��ǥ
	int y;			//y��ǥ
	char state;		//�ʱ������� (���丶�� ����)
	bool step;		//�����϶� �ִϸ��̼�
	char speedx;	//x�ӵ�
	char speedy;	//y�ӵ�
};

//�� (���� ���� ���� ó��, ���̴� ���� ���İ��� ������� �ʴ´�, �츸 ���)
struct Enemy
{
	int x;			//x��ǥ
	int y;			//y��ǥ
	int alpha;		//�� ����ϴ� �����ϰ�
	char speed;		//�ӵ�
	bool state;		//����(�¿�)
	bool type;		//�Ϲ����� ��, ��
};

//����, �׾Ƹ� 
struct Item
{
	int x;
	int y;
	char ch;
};

//�����Ҷ� ��ǥ  
struct jump
{
	char x;
	char y;
	char frame; //��������Ʈ�߿��� � �κ��� ������ ���ΰ�?
};


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
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

	///////// �ʱ����̹��� //////////
	// �⺻ �� ���� �̹��� 
	CBitmap _hMapEle[6];
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

	// ����
	CBitmap		_hDigit;
	CBitmap		_hDigit_sm;

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

	//�ϼ��� ���̹���
	//���� �� ������ǰ���� ���� ����� �ϼ��� ���� �ϳ��� �̹����� ����
	CBitmap _hMap;

	//���� ���۸��� ����  
	CBitmap		_cBit;


	//����ü
	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];

	//����
	jump	_StandJump[10];
	//ª�� ����
	jump	_LeftShortJump[11];
	//�� ����
	jump	_LeftLongJump[17];

	
	//���� ����
	int _EnemyCount;

	//���� ����(4���� ����)
	char		_GameState;

	//������
	//���������� �� ó���� �ϱ� ����
	char		_cMap[26][33];

	//����
	char		_iLevel;

	// ���� �ʱ��� ��
	char		_iLive;

	//���� ���� ��
	char		_iEat;

	// ������ �����ٶ� �ʿ��� ī����
	char _JumpFrame;

	//���� �������� ���� ǥ�� �ð� 
	char		_ScoreShow;

	//�ִϸ��̼��� ����
	int _iAni;

	// ���� �ð�
	int			_iTime;

	// ����
	int			_iScore;

	// ���� �����̳� �׾Ƹ� ���� ������ (2�辿 ����)
	int			_iItemScoreRate;

	//�⺻������ ȭ���� ���� �׸��� ���� �ƴϰ� ó������ ���� �׸���
	//���Ŀ��� ���ϴ� �κи� �ٽ� �׸���.
	//������ �������� �̵��ϰų� �ٸ� ������� �����ٸ� ȭ���� ���� �ٽ� �׷��� �Ѵ�.
	//�̸� ���ؼ� �Ʒ��� ������ �ʿ��ϴ�. 
	bool _bIsDrawAll;

	// �ʱ����� �׾ �������� ���� ���� ����
	BOOL _bIsDrop_Sound;

};

