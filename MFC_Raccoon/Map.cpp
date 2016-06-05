#include "stdafx.h"
#include "Map.h"
#include "MainFrm.h"
#include "Game.h"


Map::Map(CGame* game)
	: m_index(0), m_game(game)
{
	//�̹��� ó�� �� ����ǰ
	_hMapEle[0].LoadBitmapW(IDB_MAP_A);
	_hMapEle[1].LoadBitmapW(IDB_MAP_B);
	_hMapEle[2].LoadBitmapW(IDB_MAP_C);
	_hMapEle[3].LoadBitmapW(IDB_MAP_D);
	_hMapEle[4].LoadBitmapW(IDB_MAP_E);
	_hMapEle[5].LoadBitmapW(IDB_MAP_F);

	_hBackground.LoadBitmapW(IDB_BACKGROUND);
}

Map::~Map()
{
}


void Map::LoadMap(CRect& rect, Enemy* _Ene, Item* _Item, Raccoon& _Rac, int _iLevel, int _iScore, CBitmap& _hScore)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	pView->GetClientRect(&rect);

	HRSRC hRSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAP), _T("TEXT"));
	DWORD size = SizeofResource(AfxGetInstanceHandle(), hRSrc);
	HGLOBAL hMem = LoadResource(AfxGetInstanceHandle(), hRSrc);
	PVOID ptr = LockResource(hMem);
	char *str = (char*)malloc(size + 1);
	memcpy(str, ptr, size);
	str[size] = 0;
	m_index = size - 913 + 3;
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

	m_index = size - 913;

	if (_hMap.m_hObject == NULL)
		_hMap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());

	memdc.SelectObject(&_hMap);

	memdc.FillSolidRect(&rect, RGB(0, 0, 0));

	for (int i = 6; i < 26; i++){
		for (int j = 1; j < 29; j++){
			objectdc.SelectObject(_hBackground);
			memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
		}
	}
	
	for (i = 0; i < 26; i++){
		for (j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}

			else if (_cMap[i][j] >= 'G' && _cMap[i][j] <= 'H')
			{
				PlaySound(MAKEINTRESOURCE(IDR_SNAKE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

				_Ene[Enemy::_EnemyCount].x = j * 25;
				_Ene[Enemy::_EnemyCount].y = i * 25 - 25;
				_Ene[Enemy::_EnemyCount].type = 2;
				_Ene[Enemy::_EnemyCount].alpha = 10;

				if (rand() % 2)
					_Ene[Enemy::_EnemyCount].state_y = TRUE;		// ��
				else
					_Ene[Enemy::_EnemyCount].state_y = FALSE;		// �Ʒ�

				if (_cMap[i][j] == 'G') {
					_Ene[Enemy::_EnemyCount].state = TRUE;
					_Ene[Enemy::_EnemyCount].speed = - (rand() % 3 + 1);
					if (_Ene[Enemy::_EnemyCount].state_y)
						_Ene[Enemy::_EnemyCount].speed_y = - (rand() % 3 + 1);
					else
						_Ene[Enemy::_EnemyCount].speed_y = (rand() % 3 + 1);

				}
				else {
					_Ene[Enemy::_EnemyCount].state = FALSE;
					_Ene[Enemy::_EnemyCount].speed = (rand() % 3 + 1);
					if (_Ene[Enemy::_EnemyCount].state_y)
						_Ene[Enemy::_EnemyCount].speed_y = - (rand() % 3 + 1);
					else
						_Ene[Enemy::_EnemyCount].speed_y = (rand() % 3 + 1);
				}

				//_Item[i].ch = '.';
				Enemy::_EnemyCount++;
			}

			else if (_cMap[i][j] >= 'I' && _cMap[i][j] <= 'L'){
				_Ene[Enemy::_EnemyCount].x = j * 25;
				_Ene[Enemy::_EnemyCount].y = i * 25 - 25;
				_Ene[Enemy::_EnemyCount].type = 0;
				_Ene[Enemy::_EnemyCount].state = (_cMap[i][j] - 'G') % 2;
				_Ene[Enemy::_EnemyCount].alpha = 255;
				if (_Ene[Enemy::_EnemyCount].state)
					_Ene[Enemy::_EnemyCount].speed = (2 + (_cMap[i][j] - 'G') / 2)* (-1);
				else
					_Ene[Enemy::_EnemyCount].speed = 2 + (_cMap[i][j] - 'G') / 2;
				Enemy::_EnemyCount++;
			}
			else if (_cMap[i][j] >= 'M'){
				_Item[Item::_ItemCount].x = j * 25;
				_Item[Item::_ItemCount].y = i * 25 - 26;
				_Item[Item::_ItemCount].ch = _cMap[i][j];
				Item::_ItemCount++;
			}
		}
	}

	// ���� (���� ��ܿ� ���� ������ �˼� �ִ� ���ϵ�)
	// ��� , �޵� ... 
	/*for (i = 0; i < _iLevel; i++)
	{
		BITMAP info;
		_Item[0]._hFruit[i].GetBitmap(&info);
		objectdc.SelectObject(&_Item[0]._hFruit[i]);
		memdc.TransparentBlt((670 - (_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	}*/


	// 'SCORE'
	objectdc.SelectObject(&_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	//// ���� �ʱ��� ��
	//for (i = 0; i < Raccoon::_iLive; i++)
	//{
	//	objectdc.SelectObject(&_Rac._hStand);
	//	memdc.BitBlt(840, 600 - (i * 55), 50, 50, &objectdc, 0, 0, SRCCOPY);
	//}

	free(str);
}


void Map::MoveMap()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CRect rect;
	pView->GetClientRect(&rect);

	HRSRC hRSrc = FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAP), _T("TEXT"));
	DWORD size = SizeofResource(AfxGetInstanceHandle(), hRSrc);
	HGLOBAL hMem = LoadResource(AfxGetInstanceHandle(), hRSrc);
	PVOID ptr = LockResource(hMem);
	char *str = (char*)malloc(size + 1);
	memcpy(str, ptr, size);
	str[size] = 0;
	char ch;

	// �� ���پ� �а�, �� 5��°���� A ��, �� 29��° ���� B�� ä��
	if (m_game->_adjY == 0) {
		
		for (int i = 25; i - 1 > 0 ; i--){
			for (int j = 32; j > 0; j--){
				if (_cMap[i - 1][j] != 'A')
					_cMap[i][j] = _cMap[i - 1][j];
				if (j < 29)
					_cMap[5][j] = 'A';
				
				if ( i == 5)
					_cMap[i][29] = 'B';
				
			}
		}
		
		for (int i = 32; i >= 0; i--)
		{
			if (m_index < 0)				// ���� ������ ���� �� index �� - ���� �Ǽ� �� ó���� ������ �� ����
				break;
			ch = str[m_index--];
			if (ch != '\n')
				_cMap[6][i] = ch;

			// ���� ���̴� �ٿ� ���� ������ �� �߰�

			if (_cMap[6][i] >= 'G' && _cMap[6][i] <= 'H')
			{
				PlaySound(MAKEINTRESOURCE(IDR_SNAKE), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

				m_game->_Ene[Enemy::_EnemyCount].x = i * 25;
				m_game->_Ene[Enemy::_EnemyCount].y = 6 * 25 - 25;
				m_game->_Ene[Enemy::_EnemyCount].type = 2;
				m_game->_Ene[Enemy::_EnemyCount].alpha = 10;

				if (rand() % 2)
					m_game->_Ene[Enemy::_EnemyCount].state_y = TRUE;		// ��
				else
					m_game->_Ene[Enemy::_EnemyCount].state_y = FALSE;		// �Ʒ�

				if (_cMap[6][i] == 'G') {
					m_game->_Ene[Enemy::_EnemyCount].state = TRUE;
					m_game->_Ene[Enemy::_EnemyCount].speed = - (rand() % 3 + 1);
					if (m_game->_Ene[Enemy::_EnemyCount].state_y)
						m_game->_Ene[Enemy::_EnemyCount].speed_y = - (rand() % 3 + 1);
					else
						m_game->_Ene[Enemy::_EnemyCount].speed_y = (rand() % 3 + 1);

				}
				else {
					m_game->_Ene[Enemy::_EnemyCount].state = FALSE;
					m_game->_Ene[Enemy::_EnemyCount].speed = (rand() % 3 + 1);
					if (m_game->_Ene[Enemy::_EnemyCount].state_y)
						m_game->_Ene[Enemy::_EnemyCount].speed_y = - (rand() % 3 + 1);
					else
						m_game->_Ene[Enemy::_EnemyCount].speed_y = (rand() % 3 + 1);
				}

				//_Item[i].ch = '.';
				Enemy::_EnemyCount++;
			}

			else if (_cMap[6][i] >= 'I' && _cMap[6][i] <= 'L'){
				m_game->_Ene[Enemy::_EnemyCount].x = i * 25;
				m_game->_Ene[Enemy::_EnemyCount].y = 6 * 25 - 25;
				m_game->_Ene[Enemy::_EnemyCount].type = 0;
				m_game->_Ene[Enemy::_EnemyCount].state = (_cMap[6][i] - 'G') % 2;
				m_game->_Ene[Enemy::_EnemyCount].alpha = 255;
				if (m_game->_Ene[Enemy::_EnemyCount].state)
					m_game->_Ene[Enemy::_EnemyCount].speed = (2 + (_cMap[6][i] - 'G') / 2)* (-1);
				else
					m_game->_Ene[Enemy::_EnemyCount].speed = 2 + (_cMap[6][i] - 'G') / 2;
				Enemy::_EnemyCount++;
			}
			else if (_cMap[6][i] >= 'M'){
				m_game->_Item[Item::_ItemCount].x = i * 25;
				m_game->_Item[Item::_ItemCount].y = 6 * 25 - 31;
				m_game->_Item[Item::_ItemCount].ch = _cMap[6][i];
				Item::_ItemCount++;
			}
		}

	
		m_index -= 2;
	}

	if (_hMap.m_hObject == NULL){
		_hMap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	}
	memdc.SelectObject(&_hMap);
	memdc.FillSolidRect(&rect, RGB(0, 0, 0));

	for (int i = 6; i < 26; i++){
		for (int j = 1; j < 29; j++){
			objectdc.SelectObject(_hBackground);
			memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
		}
	}

	for (int i = 6; i < 26; i++){
		for (int j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25 + m_game->_adjY, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
		}
	}
	
	/*for (int i = 0; i < m_game->_iLevel; i++)
	{
		BITMAP info;
		m_game->_Item[0]._hFruit[i].GetBitmap(&info);
		objectdc.SelectObject(&m_game->_Item[0]._hFruit[i]);
		memdc.TransparentBlt((670 - (m_game->_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	}*/


	// 'SCORE'
	objectdc.SelectObject(&m_game->_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	//// ���� �ʱ��� ��
	//for (int i = 0; i < Raccoon::_iLive; i++)
	//{
	//	objectdc.SelectObject(&m_game->_Rac._hStand);
	//	memdc.BitBlt(840, 600 - (i * 55), 50, 50, &objectdc, 0, 0, SRCCOPY);
	//}
	
}





void Map::MakeRadder()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CChildView* pView = (CChildView*)pFrame->GetChildView();

	CClientDC dc(pView);
	CDC memdc, objectdc;
	memdc.CreateCompatibleDC(&dc);
	objectdc.CreateCompatibleDC(&memdc);

	CRect rect;
	pView->GetClientRect(&rect);

	if (_hMap.m_hObject == NULL){
		_hMap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	}
	memdc.SelectObject(&_hMap);
	
	memdc.FillSolidRect(&rect, RGB(0, 0, 0));

	for (int i = 6; i < 26; i++){
		for (int j = 1; j < 29; j++){
			objectdc.SelectObject(_hBackground);
			memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
		}
	}

	for (int i = 6; i < 26; i++){
		for (int j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25 + m_game->_adjY, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
		}
	}
	
	//for (int i = 0; i < m_game->_iLevel; i++)
	//{
	//	BITMAP info;
	//	m_game->_Item[0]._hFruit[i].GetBitmap(&info);
	//	objectdc.SelectObject(&m_game->_Item[0]._hFruit[i]);
	//	memdc.TransparentBlt((670 - (m_game->_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	//}


	// 'SCORE'
	objectdc.SelectObject(&m_game->_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));
}
