#pragma once

//����, �׾Ƹ� 
class Item
{
public:
	Item();
	~Item();

	int x;
	int y;
	char ch;

	//���� ���� ��
	static char		_iEat;

	// �׾Ƹ�
	CBitmap		_hPot;

	//����
	CBitmap		_hFruit[4];
};

