#pragma once

// ��ȣ ������ ���ϱ� ���� �̸��� ���� �� .cpp ���� ������� ����
class Map;
class Enemy;
class Item;

// ó���� �־����� �ʱ��� �� 
#define	LIVE		7

// �Ʒ��� ���� ��ǥ���� �ʱ����� �����Ҷ� ���� ������ �����ֱ� ����
// ���� ������ �������� Ư�� ������ �̿��ؼ� ����ϴ� �ͺ���
// �Ʒ��� ���� ������ ����ϴ� ���� ���� �ڿ������� ����� ����

//�����Ҷ� ��ǥ  
struct jump
{
	char x;
	char y;
	char frame; //��������Ʈ�߿��� � �κ��� ������ ���ΰ�?
};

class Raccoon
{
public:
	Raccoon();
	~Raccoon();

	int x;				// x��ǥ
	int y;				// y��ǥ 
	char state;			// �ʱ��� ���� (���� , ������ , ���� ......) [�ʱ����������̵� ����]
	BOOL step;			// �����϶� ���ϸ��̼��� ���� 
	char speedx;		// �ӵ� 
	char speedy;		// �ӵ� 

	// ���ڸ� ���� 
	jump	_StandJump[10];

	//���� ª�� ���� 
	jump	_LeftShortJump[11];

	//���� �� ����
	jump	_LeftLongJump[17];

	// ������ �����ٶ� �ʿ��� ī����
	char _JumpFrame;

	// ���� �ʱ��� ��
	static char		_iLive;

	// �ʱ��� �̹��� 
	CBitmap		_hLeft;
	CBitmap		_hRight;
	CBitmap		_hUpDown;
	CBitmap		_hStand;
	CBitmap		_hLeftJump;
	CBitmap		_hRightJump;
	CBitmap		_hDrop;
	CBitmap		_hDie;

	//��¦ ��� ����
	CBitmap _hSurprise;

	// �浹 �˻�
	void CheckCollision(Map& _Map, Item* _Item, Enemy* _Ene, int& _iItemScoreRate, int& _iScore);
	void CheckCollision_Enemy(Enemy* _Ene);
};

