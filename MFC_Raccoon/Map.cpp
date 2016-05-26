#include "stdafx.h"
#include "Map.h"
#include "MainFrm.h"
#include "Game.h"


Map::Map(CGame* game)
	: m_index(0), m_game(game)
{
	//이미지 처리 맵 구성품
	_hMapEle[0].LoadBitmapW(IDB_MAP_A);
	_hMapEle[1].LoadBitmapW(IDB_MAP_B);
	_hMapEle[2].LoadBitmapW(IDB_MAP_C);
	_hMapEle[3].LoadBitmapW(IDB_MAP_D);
	_hMapEle[4].LoadBitmapW(IDB_MAP_E);
	_hMapEle[5].LoadBitmapW(IDB_MAP_F);
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
	
	for (i = 0; i < 26; i++){
		for (j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
			else if (_cMap[i][j] >= 'G' && _cMap[i][j] <= 'L'){
				_Ene[Enemy::_EnemyCount].x = j * 25;
				_Ene[Enemy::_EnemyCount].y = i * 25 - 25;
				_Ene[Enemy::_EnemyCount].type = TRUE;
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

	// 과일 (게임 상단에 현재 레벨을 알수 있는 과일들)
	// 당근 , 앵두 ... 
	for (i = 0; i < _iLevel; i++)
	{
		BITMAP info;
		_Item[0]._hFruit[i].GetBitmap(&info);
		objectdc.SelectObject(&_Item[0]._hFruit[i]);
		memdc.TransparentBlt((670 - (_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	}


	// 'SCORE'
	objectdc.SelectObject(&_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	// 남은 너구리 수
	for (i = 0; i < Raccoon::_iLive; i++)
	{
		objectdc.SelectObject(&_Rac._hStand);
		memdc.BitBlt(840, 600 - (i * 55), 50, 50, &objectdc, 0, 0, SRCCOPY);
	}

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

	// 맵 한줄씩 밀고, 위 5번째줄은 A 로, 옆 29번째 줄은 B로 채움
	if (m_game->_adjY == 0 && m_game->is_up) {

		for (int i = 25; i - 1 > 0 ; i--){
			for (int j = 32; j > 0; j--){
				if (_cMap[i - 1][j] != 'A')
					_cMap[i][j] = _cMap[i - 1][j];
				if (j < 29)
					_cMap[5][j] = 'A';
				if (i < 5)
					_cMap[i][29] = 'B';
			}
		}
	
		for (int i = 32; i >= 0; i--)
		{
			if (m_index < 0)				// 맵의 끝까지 갔을 때 index 가 - 값이 되서 맵 처음이 나오는 것 방지
				break;
			ch = str[m_index--];
			if (ch != '\n')
				_cMap[6][i] = ch;

			// 새로 보이는 줄에 적이 있으면 적 추가
			if (_cMap[6][i] >= 'G' && _cMap[6][i] <= 'L'){
				m_game->_Ene[Enemy::_EnemyCount].x = i * 25;
				m_game->_Ene[Enemy::_EnemyCount].y = 6 * 25 - 25;
				m_game->_Ene[Enemy::_EnemyCount].type = TRUE;
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
		for (int j = 0; j < 33; j++){
			if (_cMap[i][j] >= 'A' && _cMap[i][j] <= 'F'){
				objectdc.SelectObject(_hMapEle[_cMap[i][j] - 65]);
				memdc.TransparentBlt(j * 25, i * 25 + m_game->_adjY, 25, 25, &objectdc, 0, 0, 25, 25, RGB(0, 0, 0));
			}
		}
	}
	
	for (int i = 0; i < m_game->_iLevel; i++)
	{
		BITMAP info;
		m_game->_Item[0]._hFruit[i].GetBitmap(&info);
		objectdc.SelectObject(&m_game->_Item[0]._hFruit[i]);
		memdc.TransparentBlt((670 - (m_game->_iLevel - 1) * 55) + i * 55, 70, info.bmWidth, info.bmHeight, &objectdc, 0, 0, info.bmWidth, info.bmHeight, RGB(0, 0, 0));
	}


	// 'SCORE'
	objectdc.SelectObject(&m_game->_hScore);
	memdc.TransparentBlt(25, 25, 75, 23, &objectdc, 0, 0, 75, 23, RGB(0, 0, 0));

	// 남은 너구리 수
	for (int i = 0; i < Raccoon::_iLive; i++)
	{
		objectdc.SelectObject(&m_game->_Rac._hStand);
		memdc.BitBlt(840, 600 - (i * 55), 50, 50, &objectdc, 0, 0, SRCCOPY);
	}
	
}


