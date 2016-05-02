
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


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


	CBitmap _hMap;
	CBitmap _hMapEle[6];



	Raccoon _Rac;
	Enemy	_Ene[7];
	Item	_Item[12];
	jump	_StandJump[10];
	jump	_LeftShortJump[11];
	jump	_LeftLongJump[17];

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void LoadMap(CDC* dc, CDC* memdc, CDC* objectdc);
	void CheckCollision();
	void CheckCollision_Enemy();
	void Init();
};

