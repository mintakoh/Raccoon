#pragma once

#include "resource.h"
#include "afxwin.h"


// ��ȣ ������ ���ϱ� ���� �̸��� ���� �� .cpp ���� ������� ����
class Enemy;
class Item;
class Raccoon;
class CGame;

class Map
{
public:
	Map(CGame *game);
	~Map();

	// �� ���� ����ϰ� �ִ� CGame �ν��Ͻ�
	CGame* m_game;

	// �⺻ �� ���� �̹���
	CBitmap _hMapEle[6];

	//�ϼ��� ���̹��� 
	//���� �� ������ǰ���� ���� ����� �ϼ��� ���� �ϳ��� �̹����� ���� 
	CBitmap		_hMap;

	//������ 
	//���������� �� ó���� �ϱ� ���� 
	char _cMap[26][33];
	
	void LoadMap(CRect& rect, Enemy* _Ene, Item* _Item, Raccoon& _Rac, int _iLevel, int _iScore, CBitmap& _hScore);
	void MoveMap();
	int m_index;

	void MakeRadder();
};

