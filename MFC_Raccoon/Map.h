#pragma once

#include "resource.h"


// 상호 참조를 피하기 위해 이름만 선언 후 .cpp 에서 헤더파일 참조
class Enemy;
class Item;
class Raccoon;
class CGame;

class Map
{
public:
	Map();
	~Map();

	// 기본 맵 구성 이미지
	CBitmap _hMapEle[6];

	//완성된 맵이미지 
	//위의 맵 구성부품으로 맵을 만든뒤 완성된 맵을 하나의 이미지로 저장 
	CBitmap		_hMap;

	//맵정보 
	//내부적으로 맵 처리를 하기 위해 
	char _cMap[26][33];
	
	void LoadMap(CRect& rect, Enemy* _Ene, Item* _Item, Raccoon& _Rac, int _iLevel, int _iScore, CBitmap& _hScore);
	void MoveMap(CGame* _Ene);
	int m_index;
};

