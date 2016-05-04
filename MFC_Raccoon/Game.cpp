#include "stdafx.h"
#include "Game.h"
#include "resource.h"


CGame::CGame()
	: _bIsDrawAll(false)
	, _GameState(0)
	, _iAni(0)
	, _iLevel(1)
	, _EnemyCount(0)
	, _iEat(0)
	, _ScoreShow(0)
	, _iLive(0)
	, _iTime(0)
	, _iScore(0)
	, _iItemScoreRate(0)
	, _JumpFrame(0)
	, _bIsDrop_Sound(FALSE)
{
	// ���ڸ� ���� 
	_StandJump[0] = { 1, -5, 0 };
	_StandJump[1] = { 1, -5, 0 };
	_StandJump[2] = { -1, -5, 0 };
	_StandJump[3] = { -1, -5, 1 };
	_StandJump[4] = { -1, -5, 1 };
	_StandJump[5] = { -1, 5, 1 };
	_StandJump[6] = { 1, 5, 1 };
	_StandJump[7] = { 1, 5, 0 };
	_StandJump[8] = { 0, 5, 0 };
	_StandJump[9] = { 0, 5, 0 };

	//���� ª�� ���� 
	_LeftShortJump[0] = { -5, -5, 0 };
	_LeftShortJump[1] = { -5, -4, 0 };
	_LeftShortJump[2] = { -5, -4, 1 };
	_LeftShortJump[3] = { -5, -4, 1 };
	_LeftShortJump[4] = { -5, -3, 1 };
	_LeftShortJump[5] = { 0, 0, 1 };
	_LeftShortJump[6] = { -5, 3, 2 };
	_LeftShortJump[7] = { -5, 4, 2 };
	_LeftShortJump[8] = { -5, 4, 2 };
	_LeftShortJump[9] = { -5, 4, 2 };
	_LeftShortJump[10] = { -5, 5, 3 };

	//���� �� ���� 
	_LeftLongJump[0] = { -5, -6, 0 };
	_LeftLongJump[1] = { -5, -6, 0 };
	_LeftLongJump[2] = { -5, -5, 0 };
	_LeftLongJump[3] = { -5, -5, 1 };
	_LeftLongJump[4] = { -5, -4, 1 };
	_LeftLongJump[5] = { -5, -3, 1 };
	_LeftLongJump[6] = { -5, -2, 1 };
	_LeftLongJump[7] = { -5, -1, 1 };
	_LeftLongJump[8] = { 0, 0, 1 };
	_LeftLongJump[9] = { -5, 1, 2 };
	_LeftLongJump[10] = { -5, 2, 2 };
	_LeftLongJump[11] = { -5, 3, 2 };
	_LeftLongJump[12] = { -5, 4, 2 };
	_LeftLongJump[13] = { -5, 5, 2 };
	_LeftLongJump[14] = { -5, 5, 2 };
	_LeftLongJump[15] = { -5, 6, 2 };
	_LeftLongJump[16] = { -5, 6, 3 };



	//�̹��� ó�� �� ����ǰ
	_hMapEle[0].LoadBitmapW(IDB_MAP_A);
	_hMapEle[1].LoadBitmapW(IDB_MAP_B);
	_hMapEle[2].LoadBitmapW(IDB_MAP_C);
	_hMapEle[3].LoadBitmapW(IDB_MAP_D);
	_hMapEle[4].LoadBitmapW(IDB_MAP_E);
	_hMapEle[5].LoadBitmapW(IDB_MAP_F);

	//LETS
	_hLets.LoadBitmapW(IDB_LETS);
	//SCORE
	_hScore.LoadBitmapW(IDB_SCORE);
	//GAMEOVER
	_hGameOver.LoadBitmapW(IDB_GAMEOVER);
	//BONUS
	_hBonus.LoadBitmapW(IDB_BONUS);
	//NEXT
	_hNext.LoadBitmapW(IDB_NEXT);
	//ENDING
	_hEnding.LoadBitmapW(IDB_ENDING);

	// ���� 
	_hDigit.LoadBitmapW(IDB_DIGIT);
	_hDigit_sm.LoadBitmapW(IDB_DIGIT_SM);

	// �׾Ƹ� 
	_hPot.LoadBitmapW(IDB_MAP_N);

	// ���� 
	_hFruit[0].LoadBitmapW(IDB_MAP_Q);
	_hFruit[1].LoadBitmapW(IDB_MAP_R);
	_hFruit[2].LoadBitmapW(IDB_MAP_S);
	_hFruit[3].LoadBitmapW(IDB_MAP_T);

	// �ʱ���
	_hLeft.LoadBitmapW(IDB_LEFT);
	_hStand.LoadBitmapW(IDB_STAND);
	_hRight.LoadBitmapW(IDB_RIGHT);
	_hUpDown.LoadBitmapW(IDB_UPDOWN);
	_hLeftJump.LoadBitmapW(IDB_LEFT_JUMP);
	_hRightJump.LoadBitmapW(IDB_RIGHT_JUMP);
	_hDrop.LoadBitmapW(IDB_DROP);
	_hDie.LoadBitmapW(IDB_DIE);

	//SURPRISE
	_hSurprise.LoadBitmapW(IDB_SURPRISE);

	//��
	_hEnemyLeft.LoadBitmapW(IDB_ENEMY_LEFT);
	_hEnemyRight.LoadBitmapW(IDB_ENEMY_RIGHT);
	_hEnemyLeftRed.LoadBitmapW(IDB_ENEMY_LEFT_RED);
	_hEnemyRightRed.LoadBitmapW(IDB_ENEMY_RIGHT_RED);

	//��
	_hSnakeLeft.LoadBitmapW(IDB_SNAKE_LEFT);
	_hSnakeRight.LoadBitmapW(IDB_SNAKE_RIGHT);

	//�Ʊ�
	_hBaby.LoadBitmapW(IDB_BABY);
}


CGame::~CGame()
{
}


void CGame::GameIntro()
{
	CClientDC dc(this);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	//�ð�
	if (_iAni == 1000)
		_iAni = 0;
	else
		_iAni++;

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	GetClientRect(&rect);

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memdc.SelectObject(&_cBit);

	//��Ʈ��
	CBrush backBrush;
	backBrush.CreateSolidBrush(RGB(0, 0, 0));
	if (_iAni == 1)
		memdc.FillRect(&rect, &backBrush);
	else {
		memdc.FillRect(CRect(120, 430, 900, 500), &backBrush);
	}

	static BOOL b;		//�ִϸ��̼� ȿ���� ���� 	
	//�ʱ��� �ټ� �ͼ� �ڸ� ��� ���� 
	if (_iAni <= 171) {

		b = !b;
		objectdc.SelectObject(_hLeft);

		if (_iAni <= 50)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else
			memdc.TransparentBlt(720, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 50 && _iAni <= 70)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 70)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 70 && _iAni <= 90)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 90)
			memdc.TransparentBlt(520, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 90 && _iAni <= 110)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 110)
			memdc.TransparentBlt(420, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 110 && _iAni <= 130)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 130)
			memdc.TransparentBlt(320, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 130 && _iAni <= 150)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 150)
			memdc.TransparentBlt(220, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni >= 150 && _iAni <= 170)
			memdc.TransparentBlt(970 - _iAni * 5, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));
		else if (_iAni >= 170)
			memdc.TransparentBlt(120, 450, 50, 50, &objectdc, b * 50, 0, 50, 50, RGB(0, 0, 0));

		//�ʱ��� �� ���� -> Dance �Ѥ�;;
	}
	else if (_iAni < 437) {
		objectdc.SelectObject(&_hStand);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni < 250)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (1 - _iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
		else
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni > 220 && _iAni < 255) {
			objectdc.SelectObject(_hSurprise);
			memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));
		}

		objectdc.SelectObject(_hStand);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
	}
	else {
		objectdc.SelectObject(_hRight);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_hStand);
		memdc.TransparentBlt(620, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_hSurprise);
		memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));

		objectdc.SelectObject(_hLeft);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
	}

	if (_iAni == 171) {
		objectdc.SelectObject(_hLets);
		memdc.BitBlt(220, 120, 455, 218, &objectdc, 0, 0, SRCCOPY);

		PlaySound(MAKEINTRESOURCE(IDR_INTRO), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}

	Invalidate(false);
}

void CGame::GamePlay()
{
	GetClientRect(&rect);
	CClientDC dc(this);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CBitmap* OldBit;

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	OldBit = memdc.SelectObject(&_cBit);

	CPen pen, *OldPen;
	CBrush brush, *OldBrush;

	char i;

	//// �ð� �ٸ� ǥ���� �귯�ÿ� �� 
	pen.CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
	OldPen = memdc.SelectObject(&pen);
	brush.CreateSolidBrush(RGB(25, 184, 5));
	OldBrush = memdc.SelectObject(&brush);

	////���ϸ��̼� ������ ���� 	
	////�ʱ����� ������ �������� ���ߴ� �͵��� _iTime�� �������� ���ϸ��̼�
	////�ʱ����� �����鼭 �ϴ� �������� _iAni�� �̿� 	
	_iAni++;

	//// Play���� ���� 

	//// ���� �� ���� 
	//// _ScoreShow == 1 �� �� ������ ���������� ���� ���� ���� ���� �����ַ��� 
	if (_iEat == 8 && _ScoreShow == 1) {
		Sleep(500);
		_iAni = 0;
		_GameState = 2;
	}
	//// �ʱ��� ���� 	
	if (_Rac.state == 11) {
		PlaySound(NULL, AfxGetInstanceHandle(), 0);
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		Sleep(1500);
		if (_iLive == 0) { // ������ �ʱ����� ������ 
			Init();
			_GameState = 3;	//gameover
		}
		else {
			_iLive--;
			Init();
			LoadMap();
		}
	}


	//// ���� �ð�	
	//// �ʱ����� �������ų� ������ �ð��� �����.
	if (_iAni % 5 == 0 && _Rac.state != 10 && _Rac.state != 11) {
		_iTime--;
		if (_iTime == 0)
			_Rac.state = 10;	//�ʱ��� ���� 		
	}

	//// ��(ó�� ���� �Ҷ� �� ��ü�� �ѹ� �׸���.)
	if (_iAni == 1){
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(0, 0, rect.Width(), rect.Height(), &objectdc, 0, 0, SRCCOPY);
	}

	else {
		//�ʱ��� ����  
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(_Rac.x - 5, _Rac.y - 5, 60, 60, &objectdc, _Rac.x - 5, _Rac.y - 5, SRCCOPY);
		//�� ���� 
		for (i = 0; i < _EnemyCount; i++)
		{
			objectdc.SelectObject(&_hMap);
			memdc.BitBlt(_Ene[i].x - 2, _Ene[i].y + 5, 54, 53, &objectdc, _Ene[i].x - 2, _Ene[i].y + 5, SRCCOPY);
		}
	}


	//// ���� ǥ�� (������ ��ȭ�� ���� ���� �׸���.)
	static int Score;
	if (_iScore != Score || _iAni == 1){
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(20, 50, 86, 25, &objectdc, 20, 50, SRCCOPY);
		DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);
		Score = _iScore;
	}

	// �ð� �� ǥ�� 
	if (_iAni % 50 == 0 || _iAni == 1) {
		objectdc.SelectObject(&_hMap);
		memdc.BitBlt(600 - _iTime, 25, 50, 25, &objectdc, 200, 0, SRCCOPY);
		memdc.Rectangle(650 - _iTime, 25, 650, 50);
	}

	//���� ���� �� (������ ��ȭ�� ���� ���� �׸���.)
	static char Eat;
	if (_iEat != Eat) {
		for (i = 0; i < _iEat; i++)
		{
			BITMAP info;
			_hFruit[_iLevel - 1].GetBitmap(&info);
			objectdc.SelectObject(&_hFruit[_iLevel - 1]);
			memdc.BitBlt(750, 490 - (i * 55), info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
		}
		Eat = _iEat;
	}

	// �׾Ƹ� & ���� ǥ�� 
	for (i = 0; i < 12; i++) {
		//�׾Ƹ� 
		if (_Item[i].ch == 'M' || _Item[i].ch == 'N' || _Item[i].ch == 'O')
		{
			objectdc.SelectObject(&_hPot);
			BITMAP info;
			_hPot.GetBitmap(&info);
			memdc.BitBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
		}

		//���� 
		else if (_Item[i].ch >= 'Q')
		{
			objectdc.SelectObject(&_hFruit[_iLevel - 1]);
			BITMAP info;
			_hFruit[_iLevel - 1].GetBitmap(&info);
			memdc.BitBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, SRCCOPY);
		}

		//�ʱ����� ���� �Ϳ� ���� ���� ǥ�� 
		//�ʱ����� ������ *�� ��ġ�ϰ� ������ ǥ���Ѵ����� .�� �ٲ�

		else if (_Item[i].ch == '*') {
			//���� ����� ���� ǥ�� 

			if (_ScoreShow == 0)
			{
				objectdc.SelectObject(&_hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
			}

			DrawDigit(memdc, _Item[i].x, _Item[i].y + 25, _iItemScoreRate, _hDigit_sm);

			//������ 10������ ���� ������ 			
			if (++_ScoreShow == 11) {
				objectdc.SelectObject(&_hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y + 25, 40, 14, &objectdc, 200, 0, SRCCOPY);
				_Item[i].ch = '.';
				_ScoreShow = 0;
			}
		}
		else if (_Item[i].ch == '#') {
			objectdc.SelectObject(&_hMap);
			memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
			_Item[i].ch = '.';
		}
	}

	//�� ǥ�� 
	//��� �Ϲ����� ���� ���� �׸��� ������ ���� ȿ��(Alpha) ������.	

	for (i = 0; i <_EnemyCount; i++) {

		//��
		if (_Ene[i].type == FALSE) {

			//�ʱ����� ����ְ� (�ʱ����� ������ ȭ���� ����� �ǹǷ�)
			//���� ���� 255�� �Ǹ� ���� �����δ�.
			if (_Rac.state != 10 && _Rac.state != 11 && _Ene[i].alpha == 255) _Ene[i].x += _Ene[i].speed;

			if (_Ene[i].x <= 30) {	//���� ��
				_Ene[i].x = 30;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}
			else if (_Ene[i].x >= 670) { //������ ��
				_Ene[i].x = 670;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}

			if (_Ene[i].state == FALSE) //����(�������� ���� ������)
				if (_Ene[i].alpha != 255) {
					_Ene[i].alpha += 5;	//�����ϰ�
					objectdc.SelectObject(&_hMap);
					memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY); //���������� ������ ���� ����� (200,0 ~ 250,50�� ������)

					BLENDFUNCTION bf;
					bf.BlendOp = AC_SRC_OVER;
					bf.BlendFlags = 0;
					bf.SourceConstantAlpha = _Ene[i].alpha;
					bf.AlphaFormat = 0;

					objectdc.SelectObject(&_hSnakeRight);

					BITMAP info;
					_hSnakeRight.GetBitmap(&info);
					memdc.AlphaBlend(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, bf);
				}
				else
				{
					objectdc.SelectObject(&_hSnakeRight);
					BITMAP info;
					_hSnakeRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			else if (_Ene[i].alpha != 255) {
				_Ene[i].alpha += 5;	//�����ϰ�  
				objectdc.SelectObject(&_hMap);
				memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY); //���������� ������ ���� ����� (200,0 ~ 250,50�� ������)

				BLENDFUNCTION bf;
				bf.BlendOp = AC_SRC_OVER;
				bf.BlendFlags = 0;
				bf.SourceConstantAlpha = _Ene[i].alpha;
				bf.AlphaFormat = 0;

				objectdc.SelectObject(&_hSnakeLeft);

				BITMAP info;
				_hSnakeLeft.GetBitmap(&info);
				memdc.AlphaBlend(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, bf);
			}

			else // ����(������ ���� ������)
			{
				objectdc.SelectObject(&_hSnakeLeft);
				BITMAP info;
				_hSnakeLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
			}
		}
	}



	//�Ϲ����� �� 
	for (i = 0; i < _EnemyCount; i++) {

		if (_Ene[i].type == TRUE) {

			if (_Rac.state != 10 && _Rac.state != 11) _Ene[i].x += _Ene[i].speed;

			if (_Ene[i].x <= 30) {
				_Ene[i].x = 30;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}
			else if (_Ene[i].x >= 670) {
				_Ene[i].x = 670;
				_Ene[i].speed *= -1;
				_Ene[i].state = !_Ene[i].state;
			}

			if (_Ene[i].speed == 4 || _Ene[i].speed == -4) { // �ӵ��� 4�� ���� ������, �������� �ʷϻ� 
				if (_Ene[i].state == FALSE) //����
				{
					objectdc.SelectObject(&_hEnemyRightRed);
					BITMAP info;
					_hEnemyRightRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}

				else
				{
					objectdc.SelectObject(&_hEnemyLeftRed);
					BITMAP info;
					_hEnemyLeftRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			}
			else {
				if (_Ene[i].state == FALSE) //����
				{
					objectdc.SelectObject(&_hEnemyRight);
					BITMAP info;
					_hEnemyRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
				else
				{
					objectdc.SelectObject(&_hEnemyLeft);
					BITMAP info;
					_hEnemyLeft.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			}
		}
	}

	////�� �浹 ���� 
	CheckCollision_Enemy();

	////�ʱ��� 
	switch (_Rac.state) {
	case 1:
		objectdc.SelectObject(&_hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 2:
		objectdc.SelectObject(&_hLeft);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 3:
		objectdc.SelectObject(&_hRight);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 4:
		objectdc.SelectObject(&_hUpDown);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 5:
		// ���� ������ �о� �ͼ� �׸� 
		_Rac.x += _StandJump[_JumpFrame].x;
		_Rac.y += _StandJump[_JumpFrame].y;

		objectdc.SelectObject(&_hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_StandJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		_JumpFrame++;

		if (_JumpFrame == 10) {
			_JumpFrame = 0;	//�ʱ�ȭ 
			_Rac.state = 1;	//���� �ϸ� �ٽ� 1���·� 
		}
		break;

	case 6:
		//ȭ�� ���� ���̹Ƿ� ȭ�� ������ �ȳ����� 
		if (_Rac.x >= 30)
			_Rac.x += _LeftShortJump[_JumpFrame].x;
		_Rac.y += _LeftShortJump[_JumpFrame].y;

		objectdc.SelectObject(&_hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftShortJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_JumpFrame++;

		if (_JumpFrame == 11) {
			_JumpFrame = 0;
			_Rac.state = 2;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.
			CheckCollision();
		}

		break;

	case 7:
		//ȭ�� ���� ���̹Ƿ� ȭ�� ������ �ȳ����� 
		if (_Rac.x >= 30)
			_Rac.x += _LeftLongJump[_JumpFrame].x;
		_Rac.y += _LeftLongJump[_JumpFrame].y;

		objectdc.SelectObject(&_hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftLongJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_JumpFrame++;

		if (_JumpFrame == 17) {
			_JumpFrame = 0;
			_Rac.state = 2;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.
			CheckCollision();
		}
		break;

	case 8:
		//������ ���� 
		//1���� y��ǥ 775, 2���̻��� y��ǥ 670 
		if (_Rac.x <= 670 || (_Rac.x <= 775 && _Rac.y >= 530))
			_Rac.x -= _LeftShortJump[_JumpFrame].x;
		_Rac.y += _LeftShortJump[_JumpFrame].y;

		objectdc.SelectObject(&_hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftShortJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_JumpFrame++;

		if (_JumpFrame == 11) {
			_JumpFrame = 0;
			_Rac.state = 3;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.
			CheckCollision();

		}

		break;

	case 9:
		//������ ���� 
		//1���� y��ǥ 775, 2���̻��� y��ǥ 670 
		if (_Rac.x <= 670 || (_Rac.x <= 775 && _Rac.y >= 530))
			_Rac.x -= _LeftLongJump[_JumpFrame].x;
		_Rac.y += _LeftLongJump[_JumpFrame].y;

		objectdc.SelectObject(&_hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_LeftLongJump[_JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		_JumpFrame++;

		if (_JumpFrame == 17) {
			_JumpFrame = 0;
			_Rac.state = 3;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.
			CheckCollision();
		}

		break;

	case 10: //�������� �ʱ���  
		if (_bIsDrop_Sound == FALSE) {
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			PlaySound(MAKEINTRESOURCE(IDR_RAC_DROP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			_bIsDrop_Sound = TRUE;
		}

		if (_Rac.y >= 578) {
			_Rac.y = 578;
			//�� ������ ����

			objectdc.SelectObject(&_hDie);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

			_Rac.state = 11;
		}
		else {
			_Rac.y += 5;
			//�� ������ ���� 

			objectdc.SelectObject(&_hDrop);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_iAni / 2 % 6) * 50, 0, 50, 50, RGB(0, 0, 0));
		}
		break;

	case 11: //�ʱ��� ������ ���� 				
		break;

	}
	Invalidate(FALSE);
}

void CGame::GameCycle()
{
	switch (_GameState) {
	case 0:
		_bIsDrawAll = FALSE;
		GameIntro();
		break;

	case 1:
		_bIsDrawAll = FALSE;
		GamePlay();
		break;

	case 2:
		_bIsDrawAll = FALSE;
		GameClear();
		break;

	case 3:
		_bIsDrawAll = FALSE;
		GameOver();
		break;
	}
}

void CGame::LoadMap()
{
	CClientDC dc(this);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	GetClientRect(&rect);

	HRSRC hRSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAP), _T("TEXT"));
	DWORD size = SizeofResource(AfxGetInstanceHandle(), hRSrc);
	HGLOBAL hMem = LoadResource(AfxGetInstanceHandle(), hRSrc);
	PVOID ptr = LockResource(hMem);
	char *str = (char*)malloc(size + 1);
	memcpy(str, ptr, size);
	str[size] = 0;
	int m_index = 0;
	m_index += 913 * (_iLevel - 1) + 3;
	char ch;


	static int i, j;

	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < 35; j++){
			ch = str[m_index++];
			if (ch != '\n')
				_cMap[i][j] = ch;
		}
	}

	if (_hMap.m_hObject == NULL)
		_hMap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memdc.SelectObject(&_hMap);

	memdc.FillSolidRect(&rect, RGB(0, 0, 0));

	int index = 0;

	for (i = 0; i < 26; i++){
		for (j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
			else if (_cMap[i][j] >= 'G' && _cMap[i][j] <= 'L'){
				_Ene[_EnemyCount].x = j * 25;
				_Ene[_EnemyCount].y = i * 25 - 25;
				_Ene[_EnemyCount].type = TRUE;
				_Ene[_EnemyCount].state = (_cMap[i][j] - 'G') % 2;
				_Ene[_EnemyCount].alpha = 255;
				if (_Ene[_EnemyCount].state)
					_Ene[_EnemyCount].speed = (2 + (_cMap[i][j] - 'G') / 2)* (-1);
				else
					_Ene[_EnemyCount].speed = 2 + (_cMap[i][j] - 'G') / 2;
				_EnemyCount++;
			}
			else if (_cMap[i][j] >= 'M'){
				_Item[index].x = j * 25;
				_Item[index].y = i * 25 - 26;
				_Item[index].ch = _cMap[i][j];
				index++;
			}
		}
	}

	// ���� (���� ��ܿ� ���� ������ �˼� �ִ� ���ϵ�)
	// ��� , �޵� ... 
	for (i = 0; i < _iLevel; i++)
	{
		BITMAP info;
		_hFruit[i].GetBitmap(&info);
		objectdc.SelectObject(&_hFruit[i]);
		memdc.TransparentBlt((670 - (_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	}


	// 'SCORE'
	objectdc.SelectObject(&_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	// ���� �ʱ��� ��
	for (i = 0; i < _iLive; i++)
	{
		objectdc.SelectObject(&_hStand);
		memdc.BitBlt(840, 600 - (i * 55), 50, 50, &objectdc, 0, 0, SRCCOPY);
	}

	free(str);
}

void CGame::CheckCollision()
{
	static int x1, y1, x2, y2;
	static int xx1, yy1, xx2, yy2;

	if (_Rac.state == 2 || _Rac.state == 6 || _Rac.state == 7){
		x1 = _Rac.x + 10;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 30;
		y2 = _Rac.y + 45;
	}
	else{
		x1 = _Rac.x + 20;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 40;
		y2 = _Rac.y + 40;
	}

	if (_Rac.state == 2 || _Rac.state == 3){
		if (_cMap[y2 / 25][x1 / 25] == 'E' || _cMap[y2 / 25 + 1][x1 / 25] == '.'){
			xx1 = (x1 / 25 * 25) + 5;
			xx2 = ((x1 / 25 + 1) * 25) - 5;
			if ((xx1 > x1 && xx1 <x2) || (xx2 > x1 && xx2 < x2)){
				_Rac.state = 10;
				return;
			}
		}
		if (_cMap[y2 / 25][x2 / 25] == 'E' || _cMap[y2 / 25 + 1][x2 / 25] == '.') {
			xx1 = (x2 / 25 * 25) + 5;
			xx2 = ((x2 / 25 + 1) * 25) - 5;
			if ((xx1 > x1 && xx1 < x2) || (xx2 > x1 && xx2 < x2)) {
				_Rac.state = 10;
				return;
			}
		}
	}

	//����, �׾Ƹ� �浹 �˻�
	char i;

	for (i = 0; i < 12; i++){
		if (_Item[i].ch >= 'M'){
			xx1 = _Item[i].x + 10;
			yy1 = _Item[i].y + 30;
			xx2 = _Item[i].x + 40;
			yy2 = _Item[i].y + 40;

			if ((xx1 > x1 && xx1 < x2 && yy1 > y1 && yy1 < y2) ||
				(xx1 > x1 && xx1 < x2 && yy2 > y1 && yy2 < y2) ||
				(xx2 > x1 && xx2 < x2 && yy1 > y1 && yy1 < y2) ||
				(xx2 > x1 && xx2 < x2 && yy2 > y1 && yy2 < y2)){

				PlaySound(MAKEINTRESOURCE(IDR_RAC_EAT), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

				if (_Item[i].ch >= 'Q') _iEat++;

				if (_Item[i].ch == 'N' || _Item[i].ch == 'M'){
					PlaySound(MAKEINTRESOURCE(IDR_SNAKE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

					_Ene[_EnemyCount].x = _Item[i].x;
					_Ene[_EnemyCount].y = _Item[i].y;
					_Ene[_EnemyCount].type = FALSE;
					_Ene[_EnemyCount].alpha = 10;

					if (_Item[i].ch == 'N') {
						_Ene[_EnemyCount].state = TRUE;
						_Ene[_EnemyCount].speed = -1;

					}
					else {
						_Ene[_EnemyCount].state = FALSE;
						_Ene[_EnemyCount].speed = 1;
					}

					_Item[i].ch = '.';
					_EnemyCount++;
				}
				else{
					//���� ǥ�� �غ�
					//���߿� ���� ǥ���ϰ� '.'���� ��ü
					_Item[i].ch = '*';
					//���� ���
					_iItemScoreRate *= 2;
					_iScore += _iItemScoreRate;
				}
			}
		}
	}
}

void CGame::CheckCollision_Enemy()
{
	static int x1, y1, x2, y2;
	static int xx1, yy1, xx2, yy2;

	if (_Rac.state == 2 || _Rac.state == 6 || _Rac.state == 7){
		x1 = _Rac.x + 10;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 30;
		y2 = _Rac.y + 45;
	}
	else if (_Rac.state == 3 || _Rac.state == 8 || _Rac.state == 9){
		x1 = _Rac.x + 20;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 40;
		y2 = _Rac.y + 45;
	}
	else{
		x1 = _Rac.x + 5;
		y1 = _Rac.y + 5;
		x2 = _Rac.x + 40;
		y2 = _Rac.y + 45;
	}

	char i;

	for (i = 0; i < _EnemyCount; i++){
		if (_Ene[i].alpha == 255){
			xx1 = _Ene[i].x + 7;
			yy1 = _Ene[i].y + 5;
			xx2 = _Ene[i].x + 43;
			yy2 = _Ene[i].y + 50;

			if ((x1 > xx1 && x1 < xx2 && y1 > yy1 && y1 < yy2) ||
				(x1 > xx1 && x1 < xx2 && y2 > yy1 && y2 < yy2) ||
				(x2 > xx1 && x2 < xx2 && y1 > yy1 && y2 < yy2) ||
				(x2 > xx1 && x2 < xx2 && y2 > yy1 && y2 < yy2))
				_Rac.state = 10;

		}
	}
}

void CGame::GameClear()
{
	CClientDC dc(this);
	GetClientRect(&rect);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CBitmap* OldBit;
	CBrush BackBrush, *OldBrush;

	static int bonus;

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

	OldBit = memdc.SelectObject(&_cBit);

	BackBrush.CreateSolidBrush(RGB(0, 0, 0));
	OldBrush = memdc.SelectObject(&BackBrush);

	// ȭ�� �����
	_iAni++;

	if (_iAni == 1)
		memdc.FillRect(&rect, &BackBrush);


	// ������ ���� ��������	
	if (_iLevel != LAST_LEVEL) {

		if (_iAni == 130) {
			_iScore += bonus;
			_iLevel++;
			Init();
			LoadMap();
			_GameState = 1;
		}

		//���� �ð��� ���� ���ʽ� ���� 
		if (_iTime > 200)
			bonus = 5000;
		else
			bonus = 2000;

		// bonus ����ǥ��
		DrawDigit(memdc, 450, 255, bonus, _hDigit, 7);

		//'BONUS'
		objectdc.SelectObject(&_hBonus);
		memdc.TransparentBlt(340, 255, 87, 22, &objectdc, 0, 0, 87, 22, RGB(0, 0, 0));

		//'Next'
		objectdc.SelectObject(&_hNext);
		memdc.TransparentBlt(765, 622, 51, 22, &objectdc, 0, 0, 51, 22, RGB(0, 0, 0));

		//����
		BITMAP info;
		_hFruit[_iLevel].GetBitmap(&info);
		objectdc.SelectObject(&_hFruit[_iLevel]);
		memdc.TransparentBlt(830, 600, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));

		if (_iAni == 1)
			PlaySound(MAKEINTRESOURCE(IDR_CLEAR), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}
	else {
		//������ ���� ���� 	
		if (_iAni == 400) {
			Init();
			_GameState = 0;
		}
		// ending �޼���
		objectdc.SelectObject(&_hEnding);
		memdc.TransparentBlt(100, 150, 700, 197, &objectdc, 0, 0, 700, 197, RGB(0, 0, 0));
		// �Ʊ�
		objectdc.SelectObject(&_hBaby);
		memdc.BitBlt(750, 420, 42, 43, &objectdc, (_iAni / 4 % 2) * 42, 0, SRCCOPY);
	}

	// 'SCORE' ǥ��
	objectdc.SelectObject(&_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	// ���� ǥ�� 
	DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);

	Invalidate(false);
}

void CGame::GameOver()
{
	CClientDC dc(this);

	GetClientRect(&rect);

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CBitmap* OldBit;

	if (_cBit.m_hObject == NULL)
		_cBit.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	OldBit = memdc.SelectObject(&_cBit);

	//��Ʈ��
	CBrush backBrush;
	backBrush.CreateSolidBrush(RGB(0, 0, 0));

	memdc.FillRect(&rect, &backBrush);

	CDC game_overdc;
	game_overdc.CreateCompatibleDC(&memdc);

	CDC scoredc;
	scoredc.CreateCompatibleDC(&memdc);

	CDC drop_racoondc;
	drop_racoondc.CreateCompatibleDC(&memdc);

	game_overdc.SelectObject(&_hGameOver);
	drop_racoondc.SelectObject(&_hDrop);
	scoredc.SelectObject(&_hScore);


	if (_iAni != 350)
		_iAni++;
	else {
		Init();
		_GameState = 0;
	}
	// 'SCORE' ǥ��
	memdc.BitBlt(25, 25, 75, 23, &scoredc, 0, 0, SRCCOPY);

	// ���� ǥ�� 
	static int Score;
	if (_iScore != Score || _iAni == 1){
		memdc.BitBlt(200, 50, 100, 25, &objectdc, 200, 50, SRCCOPY);
		DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);
		Score = _iScore;
	}



	//�ٴ� �׸��� 
	CBrush brush;
	brush.CreateSolidBrush(RGB(165, 113, 66));
	memdc.Rectangle(0, 585, 900, 670);

	static int i, j;
	j = 0;
	for (i = 585; i < 670; i += j) {
		j++;
		memdc.MoveTo(0, i);
		memdc.LineTo(900, i);
	}
	j = 0;

	//'GAME OVER'
	if (_iAni < 50) {
		memdc.BitBlt(-340 + _iAni * 10, 200, 280, 72, &game_overdc, 0, 0, SRCCOPY);
		memdc.BitBlt(940 - _iAni * 10, 200, 280, 72, &game_overdc, 280, 0, SRCCOPY);
	}
	else
		memdc.BitBlt(160, 200, 560, 72, &game_overdc, 0, 0, SRCCOPY);

	//�������� �ʱ�����
	if (_iAni > 50 && _iAni < 110)
		memdc.BitBlt(430, (_iAni - 55) * 10, 50, 50, &drop_racoondc, (_iAni / 2 % 6) * 50, 0, SRCCOPY);

	else if (_iAni >= 110){
		drop_racoondc.SelectObject(&_hDie);
		memdc.TransparentBlt(430, 540, 50, 50, &drop_racoondc, 0, 0, 50, 50, RGB(0, 0, 0));
	}


	//���� �����Ʈ
	if (_iAni == 1)
		PlaySound(MAKEINTRESOURCE(IDR_GAMEOVER), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	if (_iAni == 110)
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	Invalidate(false);
}

void CGame::Init()
{
	//�ʱ�ȭ
	_Rac.state = 1;			//�ʱ����� ������ ���� �ִ� 
	_Rac.x = 775;			//�ʱ����� ���� ��ġ 
	_Rac.y = 578;			//�ʱ����� ���� ��ġ 
	_Rac.speedx = 5;		//�ʱ��� �̵� �ӵ� 
	_Rac.speedy = 5;		//�ʱ��� �̵� �ӵ� 
	_iTime = 500;			//���� ���� �ð� 
	_iItemScoreRate = 5;	//������ ����, 2�辿 �������鼭 ���� 
	_iEat = 0;				//���� ���ϼ� 
	_iAni = 0;				//�ִϸ��̼� ȿ���� ���� 
	_bIsDrop_Sound = FALSE;	//�ʱ����� �������� ���� �Ҹ� ���� 

	_EnemyCount = 0;		//���� ���� 

	_ScoreShow = 0;			//���� ���� ���� ǥ�� �ð� 
	_JumpFrame = 0;			//������ ���� �ٶ� �ʿ� (ī����)
}

void CGame::DrawDigit(CDC& cDC, int x, int y, int score, CBitmap& cBit, int cipher, COLORREF crTransColor)
{
	CDC MemDC;
	CBitmap *OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC.CreateCompatibleDC(&cDC);
	OldBitmap = MemDC.SelectObject(&cBit);

	cBit.GetBitmap(&bit);
	bx = bit.bmWidth / 10;
	by = bit.bmHeight;

	int len;
	int blank = 0;
	char str[10];

	_itoa_s(score, str, 10);
	len = strlen(str);

	if (cipher)
		blank = cipher - len - 1;

	//���ڸ� �ڸ����� �����Ͽ� ������ �ְ� ���� ǥ��  
	for (int i = 0; i < len; i++)
		cDC.TransparentBlt(x + (blank*bx) + (i*bx), y, bx, by, &MemDC, bx*(str[i] - '0'), 0, bx, by, crTransColor);

	MemDC.SelectObject(&OldBitmap);
	MemDC.DeleteDC();
}

void CGame::HandleKeys()
{
	switch (_GameState) {

		//��Ʈ�� ȭ�� 
	case 0:
		if (GetAsyncKeyState(JUMP) < 0) {
			//��Ʈ�� ���� ���� 
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			// �ʱ�ȭ 
			_iLevel = 1;
			_iLive = LIVE;
			_iScore = 0;
			Init();
			LoadMap();
			_GameState = 1;
			//�����̽��� ���� ��� ������ ������ �������� ���� �ʱ����� �����ϹǷ� 
			//�̸� ���� �ϱ� ���� 
			Sleep(100);
		}
		break;

		//������
		//Ű�� ���ÿ� �ΰ� �������� ó���ϱ� ���ؼ��� API�����δ� �Ұ� 
		//���̷�Ʈ������ ������ Ű ���۸� ������ �� 
		//���⼭�� Ű ���� ����ϰ� ���� 
		//���� �Է��� ���� ���¿��� �����Է��� ������ �Ǵ� 
		//������ �Է��� ���� ���¿��� �����Է��� ������ 
		//�ٽ� ���� ���� �Է��� �����̰� �� ���� �Է��� �������̳� �����̸�
		//��� ���� �� 
		//������ ���� �޸� ���� Ű ���� ���� 

		/************************************************************
		*�Ʒ� �ҽ��� ���丶�� �׸��� ����							*
		*************************************************************/

	case 1:
		switch (_Rac.state) {
		case 1:
			if (GetAsyncKeyState(LEFT) < 0)
				_Rac.state = 2;

			else if (GetAsyncKeyState(RIGHT) < 0)
				_Rac.state = 3;

			// 'F'�� ��ٸ�,  +20 �� ���� �ʱ����� �߽��� ���߱� ���� 
			else if (GetAsyncKeyState(UP) < 0) {
				if (_cMap[(_Rac.y) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 5;
			}

			break;

		case 2:
			if (GetAsyncKeyState(LEFT) < 0) {
				if (_Rac.x >= 25) {
					_Rac.x -= _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
					CheckCollision();
				} //Ű ���� 
				if (GetAsyncKeyState(JUMP) < 0) {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 7;
				}
			}
			else if (GetAsyncKeyState(RIGHT) < 0)
				_Rac.state = 3;

			else if (GetAsyncKeyState(UP) < 0) {
				if (_cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 6;
			}

			break;

		case 3:
			if (GetAsyncKeyState(LEFT) < 0)
				_Rac.state = 2;

			else if (GetAsyncKeyState(RIGHT) < 0) {
				if ((_Rac.x <= 670) || (_Rac.x <= 775 && _Rac.y == 578)) {
					_Rac.x += _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
					CheckCollision();
				} // Ű ���� 
				if (GetAsyncKeyState(JUMP) < 0)  {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 9;
				}
			}
			else if (GetAsyncKeyState(UP) < 0) {
				if (_cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 8;
			}

			break;

		case 4:
			if (GetAsyncKeyState(UP) < 0)
				if (_cMap[(_Rac.y + 20) / 25][(_Rac.x + 20) / 25] == 'F') {
					_Rac.y -= _Rac.speedy;
					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else
					_Rac.state = 1;

			else if (GetAsyncKeyState(DOWN) < 0)
				if (_cMap[(_Rac.y + 50) / 25][(_Rac.x + 20) / 25] == 'F') {
					_Rac.y += _Rac.speedy;
					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else
					_Rac.state = 1;

			break;
		}

		break;


		//���� Ŭ���� 
	case 2:
		break;

		//GAME OVER
	case 3:
		if (GetAsyncKeyState(JUMP) < 0) {
			PlaySound(NULL, AfxGetInstanceHandle(), 0);
			_iAni = 0;
			_GameState = 0;
			Sleep(100);
		}

	}

}