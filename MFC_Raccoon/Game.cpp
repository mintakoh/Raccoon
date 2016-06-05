#include "stdafx.h"
#include "Game.h"
#include "resource.h"
#include "MainFrm.h"

const int DEFAULT_RACCOON_Y = 376;


CGame::CGame()
	: _bIsDrawAll(false)
	, _GameState(0)
	, _iAni(0)
	, _iLevel(1)
	, _ScoreShow(0)
	, _iTime(0)
	, _iScore(0)
	, _iItemScoreRate(0)
	, _bIsDrop_Sound(FALSE)
	, _Map(this)
	, _adjY(0)
	, _OnMagma(false)
	, _Magma_time(0)
	, _Magma_index(0)
{
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

	//�Ʊ�
	_hBaby.LoadBitmapW(IDB_BABY);

	//���
	_hLava.LoadBitmapW(IDB_LAVA);
	//���
	_hWarn.LoadBitmapW(IDB_WARNING);
	//��Ϲٴ�
	_hotfloor[0].LoadBitmapW(IDB_HOTFLOOR);
	_hotfloor[1].LoadBitmapW(IDB_HOTFLOOR_TOP);
}


CGame::~CGame()
{
}


void CGame::GameIntro()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	//�ð�
	if (_iAni == 1000)
		_iAni = 0;
	else
		_iAni++;

	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	pView->GetClientRect(&rect);

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
		objectdc.SelectObject(_Rac._hLeft);

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
		objectdc.SelectObject(&_Rac._hStand);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni < 250)
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (1 - _iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
		else
			memdc.TransparentBlt(620, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));

		if (_iAni > 220 && _iAni < 255) {
			objectdc.SelectObject(_Rac._hSurprise);
			memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));
		}

		objectdc.SelectObject(_Rac._hStand);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, (_iAni / 19 % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
	}
	else {
		objectdc.SelectObject(_Rac._hRight);
		for (int i = 120; i <= 520; i += 100)
			memdc.TransparentBlt(i, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_Rac._hStand);
		memdc.TransparentBlt(620, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

		objectdc.SelectObject(_Rac._hSurprise);
		memdc.TransparentBlt(640, 435, 29, 21, &objectdc, 0, 0, 29, 21, RGB(0, 0, 0));

		objectdc.SelectObject(_Rac._hLeft);
		memdc.TransparentBlt(720, 450, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
	}

	if (_iAni == 171) {
		objectdc.SelectObject(_hLets);
		memdc.BitBlt(220, 120, 455, 218, &objectdc, 0, 0, SRCCOPY);

		PlaySound(MAKEINTRESOURCE(IDR_INTRO), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	}

	pView->Invalidate(false);
}

void CGame::GamePlay()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView(); 
	
	pView->GetClientRect(&rect);
	CClientDC dc(pView);
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
	brush.CreateSolidBrush(RGB(255, 50, 50));
	OldBrush = memdc.SelectObject(&brush);

	////���ϸ��̼� ������ ���� 	
	////�ʱ����� ������ �������� ���ߴ� �͵��� _iTime�� �������� ���ϸ��̼�
	////�ʱ����� �����鼭 �ϴ� �������� _iAni�� �̿� 	
	_iAni++;

	//// Play���� ���� 

	//// ���� �� ���� 
	//// _ScoreShow == 1 �� �� ������ ���������� ���� ���� ���� ���� �����ַ��� 
	if (Item::_iEat == 8 && _ScoreShow == 1) {
		Sleep(500);
		_iAni = 0;
		//_iScore = 0;
		_iItemScoreRate += 500;
		_iLevel++;
		Item::_iEat = 0;
		_iTime += 100;
		//_GameState = 2;		// ��� ���� �������� Ŭ���� ��� ����
	}
	//// �ʱ��� ���� 	
	if (_Rac.state == 11) {
		PlaySound(NULL, AfxGetInstanceHandle(), 0);
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		Sleep(1500);

		Init();
		_GameState = 3;	// gameover
		//_OnMagma = false;

		//if (Raccoon::_iLive == 0) { // ������ �ʱ����� ������ 
		//	Init();
		//	_GameState = 3;	//gameover
		//}
		//else {
		//	Raccoon::_iLive--;
		//	Init();
		//	_Map.LoadMap(rect, _Ene, _Item, _Rac, _iLevel, _iScore, _hScore);
		//}
	}

	// ��ֹ��̳� ���� �ε����� ü���� ���̰� ��� ���� ���
	else if (_Rac.is_collision && _Rac.is_ghost == false)
	{
		Sleep(100);

		_iTime -= 30;

		if (_iTime <= 0)
		{
			_iTime = 0;
			_Rac.is_ghost = false;
			_Rac.is_collision = false;
			_Rac.ghost_time = 0;
			_Rac.state = 10;	//gameover
		}

		else
			_Rac.is_ghost = true;
	}

	// ���� ����� ���� ��� ���ؿ� ���������� ���� ( 150 )
	if (_Rac.is_ghost)
	{
		_Rac.ghost_time += 1;

		if (_Rac.ghost_time >= 150)
		{
			_Rac.is_ghost = false;
			_Rac.is_collision = false;
			_Rac.ghost_time = 0;
		}
	}


	//// ���� �ð�	
	//// �ʱ����� �������ų� ������ �ð��� �����.
	if (_iAni % 5 == 0 && _Rac.state != 10 && _Rac.state != 11) {
		_iTime--;
		//���
		_Magma_time += 1;
		if (_Magma_time == 10){
			_OnMagma = true;
		}
		if (_Magma_time == 20){
			_OnMagma = false;
			_Magma_time = 0;
			//_OnMqmq�� ��������, ���׸� ���Ӵ� ������ �ٽ� �׷��ش�
			if (_OnMagma == false){

				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Magma_index * 25, 150 - 8, 25, 550, &objectdc, _Magma_index * 25, 150 - 8, SRCCOPY);
				//�����
				memdc.BitBlt(_Magma_index * 25, 150 - 58, 25, 25, &objectdc, _Magma_index * 25, 150 - 58, SRCCOPY);
				
				while (1){
					//srand((unsigned)time(NULL));
					_Magma_index = rand() % 29;
					if (_Magma_index != 0 && _Magma_index != 1 )
						break;
				}
			}
			
		}

		if (_iTime == 0)
			_Rac.state = 10;	//�ʱ��� ���� 		
	}
	

	//// ��(ó�� ���� �Ҷ� �� ��ü�� �ѹ� �׸���.)
 	if (_iAni == 1 || _Rac.state == 4){
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(0, 0, rect.Width(), rect.Height(), &objectdc, 0, 0, SRCCOPY);
	}

	else {
		//�ʱ��� ����  
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(_Rac.x - 5, _Rac.y - 5, 60, 60, &objectdc, _Rac.x - 5, _Rac.y - 5, SRCCOPY);
		//�� ���� 
		for (i = 0; i < Enemy::_EnemyCount; i++)
		{
			objectdc.SelectObject(&_Map._hMap);
			memdc.BitBlt(_Ene[i].x, _Ene[i].y, 55, 55, &objectdc, _Ene[i].x, _Ene[i].y, SRCCOPY);
		}


		memdc.BitBlt(_Rac.x - 5, _Rac.y - 15, 70, 12, &objectdc, _Rac.x - 5, _Rac.y - 15, SRCCOPY);

		//��Ͽ���
		if (_OnMagma == false){
			
			objectdc.SelectObject(&_Map._hMap);
			memdc.BitBlt(_Magma_index * 25, 150 - 8, 25, 550, &objectdc, _Magma_index * 25, 150 - 8, SRCCOPY);
			//�����
			memdc.BitBlt(_Magma_index * 25, 150 - 58, 25, 25, &objectdc, _Magma_index * 25, 150 - 58, SRCCOPY);
		}
		

	}

	//// ���� ǥ�� (������ ��ȭ�� ���� ���� �׸���.)
	static int Score;
	if (_iScore != Score || _iAni == 1 || _Rac.state == 4){
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(20, 50, 86, 25, &objectdc, 20, 50, SRCCOPY);
		DrawDigit(memdc, 25, 50, _iScore, _hDigit, 7);
		Score = _iScore;
	}

	// �ð� �� ǥ�� 
	if (_iAni % 50 == 0 || _iAni == 1 || _Rac.state == 4) {
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(600 - _iTime, 25, 50, 25, &objectdc, 200, 0, SRCCOPY);
		memdc.Rectangle(650 - _iTime, 25, 650, 50);
	}

	//���� ���� �� (������ ��ȭ�� ���� ���� �׸���.)
	static char Eat = -1;
	if (Item::_iEat != Eat || _Rac.state == 4) {
	
		BITMAP info;
		_Item[0]._hFruit[_iLevel - 1].GetBitmap(&info);

		// ���� ���� �� ����
		objectdc.SelectObject(&_Map._hMap);
		memdc.BitBlt(760, 510, 100, 50, &objectdc, 760, 510, SRCCOPY);

		objectdc.SelectObject(&_Item[0]._hFruit[_iLevel - 1]);
		memdc.TransparentBlt(750, 433, info.bmWidth, info.bmHeight, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
		DrawDigit(memdc, 760, 510, Item::_iEat, _hDigit);
	

		// ���� ������ ���ų� �׾��ٰ� �ٽ� �����ϴ� �� ���� ���� �� �׸� ���� ����� �� �ֵ��� ���� ������ ������Ű�� ����
		if (Item::_iEat != 0)
			Eat = Item::_iEat;
	}

	// ���� (���� ��ܿ� ���� ������ �˼� �ִ� ���ϵ�)
	// ��� , �޵� ...		������ ���� �� �ݿ��ϱ� ���ؼ�
	objectdc.SelectObject(&_Map._hMap);
	memdc.TransparentBlt((670 - (_iLevel - 1) * 55), 70, 55 * _iLevel, 50, &objectdc, 200, 0, 50, 50, RGB(0, 0, 0));

	/*for (i = 0; i < _iLevel; i++)(_Item[i].ch == 'N' || _Item[i].ch == 'M')
	{
		BITMAP info;
		_Item[0]._hFruit[i].GetBitmap(&info);
		objectdc.SelectObject(&_Item[0]._hFruit[i]);
		memdc.TransparentBlt((670 - (_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	}*/


	// ��ٸ� ���� ǥ��
	objectdc.SelectObject(&_Map._hMapEle[5]);
	memdc.BitBlt(810, 510, 25, 25, &objectdc, 0, 0, SRCCOPY);
	
	objectdc.SelectObject(&_Map._hMap);
	memdc.BitBlt(840, 510, 100, 100, &objectdc, 200, 0, SRCCOPY);
	DrawDigit(memdc, 840, 510, _Rac.ladder_count, _hDigit);

	// �׾Ƹ� & ���� ǥ�� 
	for (i = 0; i < Item::_ItemCount; i++) {
		//�׾Ƹ� 
		if (_Item[i].ch == 'M' || _Item[i].ch == 'N' || _Item[i].ch == 'O' || _Item[i].ch == 'P' || _Item[i].ch == 'Z')
		{
			objectdc.SelectObject(&_Item[0]._hPot);
			BITMAP info;
			_Item[0]._hPot.GetBitmap(&info);
			memdc.TransparentBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
		}

		//���� 
		else if (_Item[i].ch >= 'Q')
		{
			objectdc.SelectObject(&_Item[0]._hFruit[_iLevel - 1]);
			BITMAP info;
			_Item[0]._hFruit[_iLevel - 1].GetBitmap(&info);
			memdc.TransparentBlt(_Item[i].x, _Item[i].y, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
		}

		//�ʱ����� ���� �Ϳ� ���� ���� ǥ�� 
		//�ʱ����� ������ *�� ��ġ�ϰ� ������ ǥ���Ѵ����� .�� �ٲ�

		else if (_Item[i].ch == '*') {
			//���� ����� ���� ǥ�� 

			if (_ScoreShow == 0)
			{
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, _Item[i].x, _Item[i].y, SRCCOPY);
			}

			DrawDigit(memdc, _Item[i].x, _Item[i].y + 25, _iItemScoreRate, _hDigit_sm);

			//������ 10������ ���� ������ 			
			if (++_ScoreShow == 11) {
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y + 25, 40, 14, &objectdc, 200, 0, SRCCOPY);
				_Item[i].ch = '.';
				_ScoreShow = 0;

				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, _Item[i].x, _Item[i].y, SRCCOPY);
			}
		}
		else if (_Item[i].ch == '#') {
			objectdc.SelectObject(&_Map._hMap);
			memdc.BitBlt(_Item[i].x, _Item[i].y, 50, 50, &objectdc, 200, 0, SRCCOPY);
			_Item[i].ch = '.';
		}
	}

	//�� ǥ�� 
	//��� �Ϲ����� ���� ���� �׸��� ������ ���� ȿ��(Alpha) ������.	

	for (i = 0; i < Enemy::_EnemyCount; i++) {

		//��
		if (_Ene[i].type == 1) {

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
					objectdc.SelectObject(&_Map._hMap);
					memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, _Ene[i].x, _Ene[i].y, SRCCOPY); //���������� ������ ���� ����� (200,0 ~ 250,50�� ������)

					objectdc.SelectObject(&_Ene[0]._hSnakeRight);

					BITMAP info;
					_Ene[0]._hSnakeRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));

					DrawDigit(memdc, _Ene[i].x + 15, _Ene[i].y + 10, (255 - _Ene[i].alpha) / 50, _hDigit);
				}

				else
				{
					objectdc.SelectObject(&_Ene[0]._hSnakeRight);
					BITMAP info;
					_Ene[0]._hSnakeRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			else if (_Ene[i].alpha != 255) {
				_Ene[i].alpha += 5;	//�����ϰ�  
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, _Ene[i].x, _Ene[i].y, SRCCOPY); //���������� ������ ���� ����� (200,0 ~ 250,50�� ������)

				objectdc.SelectObject(&_Ene[0]._hSnakeLeft);

				BITMAP info;
				_Ene[0]._hSnakeLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));

				DrawDigit(memdc, _Ene[i].x + 15, _Ene[i].y + 10, (255 - _Ene[i].alpha) / 50, _hDigit);
			}

			else // ����(������ ���� ������)
			{
				objectdc.SelectObject(&_Ene[0]._hSnakeLeft);

				BITMAP info;
				_Ene[0]._hSnakeLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni / 5 % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
			}
		}

		//����
		else if (_Ene[i].type == 2)
		{
			if (_Rac.state != 10 && _Rac.state != 11 && _Ene[i].alpha == 255)
			{
				_Ene[i].x += _Ene[i].speed;
				_Ene[i].y += _Ene[i].speed_y;
			}

			if (_Ene[i].x <= 20) {	//���� ��
				_Ene[i].x = 20;
				_Ene[i].speed = (rand() % 3 + 1);
				_Ene[i].state = !_Ene[i].state;
			}
			else if (_Ene[i].x >= 680) { //������ ��
				_Ene[i].x = 680;
				_Ene[i].speed = - (rand() % 3 + 1);
				_Ene[i].state = !_Ene[i].state;
			}

			if (_Ene[i].y < 150)
			{
				_Ene[i].y = 150;
				_Ene[i].speed_y = (rand() % 3 + 1);
				_Ene[i].state_y = !_Ene[i].state;
			}

			else if (_Ene[i].y > 500)
			{
				_Ene[i].y = 500;
				_Ene[i].speed_y = - (rand() % 3 + 1);
				_Ene[i].state_y = !_Ene[i].state;
			}

			if (_Ene[i].state == FALSE) //����(�������� ���� ������)
				if (_Ene[i].alpha != 255) {
					_Ene[i].alpha += 5;	//�����ϰ�
					objectdc.SelectObject(&_Map._hMap);
					memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, _Ene[i].x, _Ene[i].y, SRCCOPY); //������ ���� �����

					objectdc.SelectObject(&_Ene[0]._hGhostRight);

					BITMAP info;
					_Ene[0]._hGhostRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));

					DrawDigit(memdc, _Ene[i].x + 15, _Ene[i].y + 10, (255 - _Ene[i].alpha) / 50, _hDigit);
				}
				else
				{
					objectdc.SelectObject(&_Ene[0]._hGhostRight);
					BITMAP info;
					_Ene[0]._hGhostRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
				}

			else if (_Ene[i].alpha != 255) {
				_Ene[i].alpha += 5;	//�����ϰ�  
				objectdc.SelectObject(&_Map._hMap);
				memdc.BitBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, _Ene[i].x, _Ene[i].y, SRCCOPY); //������ ���� �����

				objectdc.SelectObject(&_Ene[0]._hGhostLeft);

				BITMAP info;
				_Ene[0]._hGhostLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));

				DrawDigit(memdc, _Ene[i].x + 15, _Ene[i].y + 10, (255 - _Ene[i].alpha) / 50, _hDigit);
			}

			else // ����(������ ���� ������)
			{
				objectdc.SelectObject(&_Ene[0]._hGhostLeft);
				BITMAP info;
				_Ene[0]._hGhostLeft.GetBitmap(&info);
				memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
			}
		}
	}



	//�Ϲ����� �� 
	for (i = 0; i < Enemy::_EnemyCount; i++) {

		if (_Ene[i].type == 0) {

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
					objectdc.SelectObject(&_Ene[0]._hEnemyRightRed);
					BITMAP info;
					_Ene[0]._hEnemyRightRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}

				else
				{
					objectdc.SelectObject(&_Ene[0]._hEnemyLeftRed);
					BITMAP info;
					_Ene[0]._hEnemyLeftRed.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			}
			else {
				if (_Ene[i].state == FALSE) //����
				{
					objectdc.SelectObject(&_Ene[0]._hEnemyRight);
					BITMAP info;
					_Ene[0]._hEnemyRight.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
				else
				{
					objectdc.SelectObject(&_Ene[0]._hEnemyLeft);
					BITMAP info;
					_Ene[0]._hEnemyLeft.GetBitmap(&info);
					memdc.TransparentBlt(_Ene[i].x, _Ene[i].y, 50, 50, &objectdc, (_iAni % 2) * 50, 0, info.bmWidth / 2, info.bmHeight, RGB(0, 0, 0));
				}
			}
		}
	}
	
	//���� ��
	objectdc.SelectObject(_Map._hMapEle[1]);
	for (int i = 5; i < 28; i++){
		memdc.TransparentBlt(9, i * 25, 25, 25, &objectdc, 0,0,25,25,RGB(0,0,0));
	}
	//������  �ϴ� �Ϻ� ��������
	for (int i = 25; i < 28; i++){
		memdc.TransparentBlt(725, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
	}

	// ���ھ�� �׸���
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 33; j++){
			if (i == 6 && j != 29) continue;
			if (_Map._cMap[i][j] >= 'A' && _Map._cMap[i][j] <= 'F'){
				objectdc.SelectObject(_Map._hMapEle[_Map._cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
		}
	}


	//���
	objectdc.SelectObject(&_hWarn);
	if (_Magma_time % 2 == 0)
		memdc.TransparentBlt(_Magma_index * 25, 150 - 58, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
	//�����
	objectdc.SelectObject(_hLava);
	if (_OnMagma == true){
		for (int i = 6; i < 22; i++){
			
				if (_Magma_time % 2 == 0)
					memdc.TransparentBlt(_Magma_index * 25, (i * 25) - 8, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
				else
					memdc.TransparentBlt(_Magma_index * 25, (i * 25) - 8, 25, 25, &objectdc, 25, 0, 25, 25, RGB(0, 0, 0));
			
		}
		_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);
	}
	
	//�������
	
	for (int i = 11; i < 14; i++){
		for (int j = 0; j < 14; j++){
			if (i == 11){
				objectdc.SelectObject(_hotfloor[1]);
				memdc.TransparentBlt(j * 50 + 25, i * 50 - 10, 50, 50, &objectdc, (_iTime % 2) * 50, 0, 50, 50, RGB(0, 0, 0));
			}
			else{
				objectdc.SelectObject(_hotfloor[0]);
				memdc.BitBlt(j * 50 + 25, i * 50 - 10, 50, 50, &objectdc, (_iTime % 2) * 50, 0, SRCCOPY);
			}
		}
	}
	
	////�� �浹 ���� 
	_Rac.CheckCollision_Enemy(_Ene);
	_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);

	////�ʱ��� 
	switch (_Rac.state) {
	case 1:
		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperStand);
		else
			objectdc.SelectObject(&_Rac._hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 2:
		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperLeft);
		else
			objectdc.SelectObject(&_Rac._hLeft);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 3:
		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperRight);
		else
			objectdc.SelectObject(&_Rac._hRight);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 4:
		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperUpDown);
		else
			objectdc.SelectObject(&_Rac._hUpDown);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, _Rac.step * 50, 0, 50, 50, RGB(0, 0, 0));
		break;

	case 5:
		// ���� ������ �о� �ͼ� �׸� 
		_Rac.x += _Rac._StandJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._StandJump[_Rac._JumpFrame].y;

		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperStand);
		else
			objectdc.SelectObject(&_Rac._hStand);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._StandJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 10) {
			_Rac._JumpFrame = 0;	//�ʱ�ȭ 
			_Rac.state = 1;	//���� �ϸ� �ٽ� 1���·� 
		}
		break;

	case 6:
		//ȭ�� ���� ���̹Ƿ� ȭ�� ������ �ȳ����� 
		if (_Rac.x >= 30)
			_Rac.x += _Rac._LeftShortJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftShortJump[_Rac._JumpFrame].y;

		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperLeftJump);
		else
			objectdc.SelectObject(&_Rac._hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftShortJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 11) {
			_Rac._JumpFrame = 0;
			_Rac.state = 2;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.

			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate,_iTime, _iScore, _iLevel, _adjY);

			//����浹����
			_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);

		}

		break;

	case 7:
		//ȭ�� ���� ���̹Ƿ� ȭ�� ������ �ȳ����� 
		if (_Rac.x >= 30)
			_Rac.x += _Rac._LeftLongJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftLongJump[_Rac._JumpFrame].y;

		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperLeftJump);
		else
			objectdc.SelectObject(&_Rac._hLeftJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftLongJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 17) {
			_Rac._JumpFrame = 0;
			_Rac.state = 2;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.
			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate,_iTime, _iScore, _iLevel, _adjY);
			//����浹����
			_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);
		}
		break;

	case 8:
		//������ ���� 
		//1���� y��ǥ 775, 2���̻��� y��ǥ 670 
		if (_Rac.x <= 670)
			_Rac.x -= _Rac._LeftShortJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftShortJump[_Rac._JumpFrame].y;

		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperRightJump);
		else
			objectdc.SelectObject(&_Rac._hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftShortJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));


		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 11) {
			_Rac._JumpFrame = 0;
			_Rac.state = 3;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.

			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iTime, _iScore, _iLevel, _adjY);
			//����浹����
			_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);


		}

		break;

	case 9:
		//������ ���� 
		//1���� y��ǥ 775, 2���̻��� y��ǥ 670 
		if (_Rac.x <= 670)
			_Rac.x -= _Rac._LeftLongJump[_Rac._JumpFrame].x;
		_Rac.y += _Rac._LeftLongJump[_Rac._JumpFrame].y;

		if (_Rac.is_ghost)
			objectdc.SelectObject(&_Rac._hSuperRightJump);
		else
			objectdc.SelectObject(&_Rac._hRightJump);
		memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_Rac._LeftLongJump[_Rac._JumpFrame].frame) * 50, 0, 50, 50, RGB(0, 0, 0));

		_Rac._JumpFrame++;

		if (_Rac._JumpFrame == 17) {
			_Rac._JumpFrame = 0;
			_Rac.state = 3;
			//�浹 �˻� 
			//�� ���α׷��� ȭ��ǥŰ�� �����϶� �浿 �˻縦 (����, ��������)�Ѵ�.
			//������ �ʱ����� ������ ������ �ٴڿ� ���� �ϸ� 
			//����Ű�� �ȴ����� ������ �浹 �˻簡 �ȵȴ�.
			//���� �����ϸ� �浹�˻縦 �Ѵ�.

			_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iTime, _iScore, _iLevel, _adjY);
			//����浹����
			_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);


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

			objectdc.SelectObject(&_Rac._hDie);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, 0, 0, 50, 50, RGB(0, 0, 0));

			_Rac.state = 11;
		}
		else {
			_Rac.y += 5;
			//�� ������ ���� 

			objectdc.SelectObject(&_Rac._hDrop);
			memdc.TransparentBlt(_Rac.x, _Rac.y, 50, 50, &objectdc, (_iAni / 2 % 6) * 50, 0, 50, 50, RGB(0, 0, 0));
		}
		break;

	case 11: //�ʱ��� ������ ���� 				
		break;

	}

	// ���� ��� ���� �ð� ��� 
	if (_Rac.is_ghost)
	{
		if (150 - _Rac.ghost_time > 100)
			DrawDigit(memdc, _Rac.x + 16, _Rac.y - 15, 150 - _Rac.ghost_time, _hDigit_sm);
		else if (150 - _Rac.ghost_time > 10)
			DrawDigit(memdc, _Rac.x + 26, _Rac.y - 15, 150 - _Rac.ghost_time, _hDigit_sm);
		else if (150 - _Rac.ghost_time > 100)
			DrawDigit(memdc, _Rac.x + 28, _Rac.y - 15, 150 - _Rac.ghost_time, _hDigit_sm);
	}

	pView->Invalidate(FALSE);
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

void CGame::GameClear()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);
	pView->GetClientRect(&rect);
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
			_Map.LoadMap(rect, _Ene, _Item, _Rac, _iLevel, _iScore, _hScore);
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
		_Item[0]._hFruit[_iLevel].GetBitmap(&info);
		objectdc.SelectObject(&_Item[0]._hFruit[_iLevel]);
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

	pView->Invalidate(false);
}

void CGame::GameOver()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);

	pView->GetClientRect(&rect);

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
	drop_racoondc.SelectObject(&_Rac._hDrop);
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
		drop_racoondc.SelectObject(&_Rac._hDie);
		memdc.TransparentBlt(430, 540, 50, 50, &drop_racoondc, 0, 0, 50, 50, RGB(0, 0, 0));
	}


	//���� �����Ʈ
	if (_iAni == 1)
		PlaySound(MAKEINTRESOURCE(IDR_GAMEOVER), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	if (_iAni == 110)
		PlaySound(MAKEINTRESOURCE(IDR_RAC_DIE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	pView->Invalidate(false);
}

void CGame::Init()
{
	//�ʱ�ȭ
	_Rac.state = 1;			//�ʱ����� ������ ���� �ִ� 
	_Rac.x = 375;			//�ʱ����� ���� ��ġ 
	_Rac.y = DEFAULT_RACCOON_Y;			//�ʱ����� ���� ��ġ 
	_Rac.speedx = 5;		//�ʱ��� �̵� �ӵ� 
	_Rac.speedy = 5;		//�ʱ��� �̵� �ӵ� 
	Item::_iEat = 0;
	_iTime = 500;			//���� ���� �ð� 
	_iItemScoreRate = 500;	//������ ����, 2�辿 �������鼭 ����
	_iAni = 0;				//�ִϸ��̼� ȿ���� ���� 
	_bIsDrop_Sound = FALSE;	//�ʱ����� �������� ���� �Ҹ� ���� 

	Enemy::_EnemyCount = 0;	//���� ����
	Item::_ItemCount = 0;	//�������� ����

	_ScoreShow = 0;			//���� ���� ���� ǥ�� �ð� 
	_Rac._JumpFrame = 0;	//������ ���� �ٶ� �ʿ� (ī����)

	_adjY = 0;

	// ��ٸ� ����
	_Rac.ladder_count = 3;

	// �ʱ��� ���� ����
	_Rac.is_ghost = false;
	_Rac.is_collision = false;
	_Rac.ghost_time = 0;

	//���� �ε��� ���� __ ������ �����ٰ� ��� ��� / ��� ���
	//�̶�, ������ ����, �� ���� ù���� ����������. �� 33��, �� 26
	_OnMagma = false;
	_Magma_time = 0;
	if (_OnMagma == false){
		while (1){
			
			srand((unsigned)time(NULL));
			_Magma_index = rand() % 28;
			if (_Magma_index != 0 && _Magma_index != 15 && _Magma_index != 1)
				break;
		}
	}

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

	//���ڸ� �ڸ����� ����Ͽ� ������ �ְ� ���� ǥ��  
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
			//Raccoon::_iLive = LIVE;
			_iScore = 0;
			Init();
			_Map.LoadMap(rect, _Ene, _Item, _Rac, _iLevel, _iScore, _hScore);
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
				if (_Map._cMap[(_Rac.y) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50 - _adjY) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 5;
			}
			else if (GetAsyncKeyState('Z') < 0 && _Rac.ladder_count > 0) {
				if ((_Map._cMap[((_Rac.y) / 25) - 3][(_Rac.x + 20) / 25] == 'E' || _Map._cMap[((_Rac.y) / 25) - 2][(_Rac.x + 20) / 25] == '.') == false) // ��ٸ� ���°��� �����̰ų� �����̸� �ȳ���
				{
					for (int i = -1; i < 4; i++)
						_Map._cMap[((_Rac.y) / 25) - i][(_Rac.x + 20) / 25] = 'F';

					_Map.MakeRadder();
					_Rac.ladder_count--;
					if (_Rac.ladder_count < 0)
						_Rac.ladder_count = 0;
					_Rac.state = 4;
				}
			}

			break;

		case 2:
			if (GetAsyncKeyState(LEFT) < 0) {
				if (_Rac.x >= 25) {
					_Rac.x -= _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);

					_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iTime, _iScore, _iLevel, _adjY);
					//����浹����
					_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);


				} //Ű ���� 
				if (GetAsyncKeyState(JUMP) < 0) {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 7;
				}
			}
			else if (GetAsyncKeyState(RIGHT) < 0)
				_Rac.state = 3;

			else if (GetAsyncKeyState(UP) < 0) {
				if (_Map._cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50 - _adjY) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 6;
			}
			else if (GetAsyncKeyState('Z') < 0 && _Rac.ladder_count > 0) {
				if ((_Map._cMap[((_Rac.y) / 25) - 3][(_Rac.x + 20) / 25] == 'E' || _Map._cMap[((_Rac.y) / 25) - 2][(_Rac.x + 20) / 25] == '.') == false) // ��ٸ� ���°��� �����̰ų� �����̸� �ȳ���
				{
					for (int i = -1; i < 4; i++)
						_Map._cMap[((_Rac.y) / 25) - i][(_Rac.x + 20) / 25] = 'F';

					_Map.MakeRadder();
					_Rac.ladder_count--;
					if (_Rac.ladder_count < 0)
						_Rac.ladder_count = 0;
					_Rac.state = 4;
				}
			}

			break;

		case 3:
			if (GetAsyncKeyState(LEFT) < 0)
				_Rac.state = 2;

			else if (GetAsyncKeyState(RIGHT) < 0) {
				if (_Rac.x <= 670) {
					_Rac.x += _Rac.speedx;
					_Rac.step = !_Rac.step;
					if (_Rac.x % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);

					_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iTime, _iScore, _iLevel, _adjY);
					//����浹����
					_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);


				} // Ű ���� 
				if (GetAsyncKeyState(JUMP) < 0)  {
					PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					_Rac.state = 9;
				}
			}
			else if (GetAsyncKeyState(UP) < 0) {
				if (_Map._cMap[(_Rac.y - 25) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50 - _adjY) / 25][(_Rac.x + 20) / 25] == 'F')
					_Rac.state = 4;
			}
			else if (GetAsyncKeyState(JUMP) < 0) {
				PlaySound(MAKEINTRESOURCE(IDR_RAC_JUMP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				_Rac.state = 8;
			}
			else if (GetAsyncKeyState('Z') < 0 && _Rac.ladder_count > 0) {
				if ((_Map._cMap[((_Rac.y) / 25) - 3][(_Rac.x + 20) / 25] == 'E' || _Map._cMap[((_Rac.y) / 25) - 2][(_Rac.x + 20) / 25] == '.') == false) // ��ٸ� ���°��� �����̰ų� �����̸� �ȳ���
				{
					for (int i = -1; i < 4; i++)
						_Map._cMap[((_Rac.y) / 25) - i][(_Rac.x + 20) / 25] = 'F';

					_Map.MakeRadder();
					_Rac.ladder_count--;
					if (_Rac.ladder_count < 0)
						_Rac.ladder_count = 0;
					_Rac.state = 4;
				};
			}

			break;

		case 4:
			if (GetAsyncKeyState(LEFT) < 0)
			{
				if (_Map._cMap[(_Rac.y + 20 - _adjY) / 25][(_Rac.x - _Rac.speedx + 20) / 25] == 'F')
				{
					if (_Rac.x >= 25) {
						_Rac.x -= _Rac.speedx;
						_Rac.step = !_Rac.step;
						if (_Rac.x % 20 == 0)
							PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);

						_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iTime, _iScore, _iLevel, _adjY);
						//����浹����
						_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);
					}
				}
			}

			else if (GetAsyncKeyState(RIGHT) < 0) {
				if (_Map._cMap[(_Rac.y + 20 - _adjY) / 25][(_Rac.x + _Rac.speedx + 20) / 25] == 'F')
				{
					if (_Rac.x <= 670) {
						_Rac.x += _Rac.speedx;
						_Rac.step = !_Rac.step;
						if (_Rac.x % 20 == 0)
							PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);

						_Rac.CheckCollision(_Map, _Item, _Ene, _iItemScoreRate, _iTime, _iScore, _iLevel, _adjY);
						//����浹����
						_Rac.CheckCollision_Magma(_Magma_index, _OnMagma);
					}
				}
			}

			if (GetAsyncKeyState(UP) < 0) {

				if (_Map._cMap[(_Rac.y + 20 - _adjY) / 25][(_Rac.x + 20) / 25] == 'F') {
					//_Rac.y -= _Rac.speedy;

					if (DEFAULT_RACCOON_Y < _Rac.y) {
						_Rac.y -= _Rac.speedy;
						_Rac.step = !_Rac.step;
						return;
					}

					_adjY += _Rac.speedy;
					if (_adjY >= _Rac.speedy * 5) {
						_adjY = 0;
					}

					_Map.MoveMap();

					for (int i = 0; i < Item::_ItemCount; i++){
						_Item[i].y += _Rac.speedy;
					}
					for (int i = 0; i < Enemy::_EnemyCount; i++){
						_Ene[i].y += _Rac.speedy;
					}

					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else {
					_Rac.state = 1;
				}
			}
			else if (GetAsyncKeyState(DOWN) < 0) {
				if (_Map._cMap[(_Rac.y + 50 - _adjY) / 25][(_Rac.x + 20) / 25] == 'F') {
					_Rac.y += _Rac.speedy;
					_Rac.step = !_Rac.step;
					if ((_Rac.y - 3) % 20 == 0)
						PlaySound(MAKEINTRESOURCE(IDR_RAC_STEP), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_NOSTOP);
				}
				else {
					_Rac.state = 1;
				}
			}
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
void CGame::Magma()
{	
}
