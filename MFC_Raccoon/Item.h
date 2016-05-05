#pragma once

//과일, 항아리 
class Item
{
public:
	Item();
	~Item();

	int x;
	int y;
	char ch;

	//먹은 과일 수
	static char		_iEat;

	// 항아리
	CBitmap		_hPot;

	//과일
	CBitmap		_hFruit[4];
};

