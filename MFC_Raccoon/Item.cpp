#include "stdafx.h"
#include "Item.h"
#include "resource.h"

// static 변수 사용을 위해 초기화
int Item::_ItemCount = 0;
char Item::_iEat = 0;

Item::Item()
{
	// 항아리 
	_hPot.LoadBitmapW(IDB_MAP_N);

	// 과일 
	_hFruit[0].LoadBitmapW(IDB_MAP_Q);
	_hFruit[1].LoadBitmapW(IDB_MAP_R);
	_hFruit[2].LoadBitmapW(IDB_MAP_S);
	_hFruit[3].LoadBitmapW(IDB_MAP_T);
}


Item::~Item()
{
}
