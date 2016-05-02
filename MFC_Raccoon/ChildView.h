
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "afxwin.h"


struct Raccoon
{
	int x;			//x��ǥ
	int y;			//y��ǥ
	char state;		//�ʱ������� (���丶�� ����)
	bool step;		//�����϶� �ִϸ��̼�
	char speedx;	//x�ӵ�
	char speedy;	//y�ӵ�
};

struct Enemy
{
	int x;			//x��ǥ
	int y;			//y��ǥ
	int alpha;		//�� ����ϴ� �����ϰ�
	char speed;		//�ӵ�
	bool state;		//����(�¿�)
	bool type;		//�Ϲ����� ��, ��
};

struct Item
{
	int x;
	int y;
	char ch;
};

struct jump
{
	char x;
	char y;
	char frame;
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
	CRect rect;
	
	void GameCycle();
	void GameIntro();
	void GamePlay();
	bool _bIsDrawAll;
	char _GameState;
	int _iAni;
	char _iLevel;
	char _cMap[26][33];
	char _EnemyCount;


	
	CBitmap _hSurprise;
	CBitmap _hLets;


	// �⺻ �� ���� �̹��� 
	CBitmap _hMap;
	CBitmap _hMapEle[6];

	// 'SCORE'
	CBitmap		_hScore;


	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];
	jump	_StandJump[10];
	jump	_LeftShortJump[11];
	jump	_LeftLongJump[17];

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void LoadMap();
	void CheckCollision();
	void CheckCollision_Enemy();
	void Init();

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

	// ����
	CBitmap		_hDigit;
	CBitmap		_hDigit_sm;

	//����
	CBitmap		_hFruit[4];

	// �׾Ƹ�
	CBitmap		_hPot;

	// ���� �����̳� �׾Ƹ� ���� ������ (2�辿 ����)
	int			_iItemScoreRate;

	// ��
	CBitmap		_hEnemyRight;
	CBitmap		_hEnemyLeft;
	CBitmap		_hEnemyRightRed;
	CBitmap		_hEnemyLeftRed;

	//��
	CBitmap		_hSnakeLeft;
	CBitmap		_hSnakeRight;

	// �ʱ��� �̹��� 
	CBitmap		_hLeft;
	CBitmap		_hRight;
	CBitmap		_hUpDown;
	CBitmap		_hStand;
	CBitmap		_hLeftJump;
	CBitmap		_hRightJump;
	CBitmap		_hDrop;
	CBitmap		_hDie;

	// ������ �����ٶ� �ʿ��� ī����
	char _JumpFrame;
	// �ʱ����� �׾ �������� ���� ���� ����
	BOOL _bIsDrop_Sound;
};

