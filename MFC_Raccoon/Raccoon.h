#pragma once

// ��ȣ ������ ���ϱ� ���� �̸��� ���� �� .cpp ���� ������� ����
class Map;
class Enemy;
class Item;

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

	// �ʱ��� �̹��� 
	CBitmap		_hLeft;
	CBitmap		_hSuperLeft;
	CBitmap		_hRight;
	CBitmap		_hSuperRight;
	CBitmap		_hUpDown;
	CBitmap		_hSuperUpDown;
	CBitmap		_hStand;
	CBitmap		_hSuperStand;
	CBitmap		_hLeftJump;
	CBitmap		_hSuperLeftJump;
	CBitmap		_hRightJump;
	CBitmap		_hSuperRightJump;
	CBitmap		_hDrop;
	CBitmap		_hDie;

	//��¦ ��� ����
	CBitmap _hSurprise;

	// �浹 �˻�
	void CheckCollision(Map& _Map, Item* _Item, Enemy* _Ene, int& _iItemScoreRate, int& _iTime, int& _iScore, char& _iLevel, const int& _adjY);
	void CheckCollision_Enemy(Enemy* _Ene);

	// ����
	int ghost_time;
	bool is_ghost;
	bool is_collision;

	// ��ٸ� ����
	int ladder_count;

	void CheckCollision_Magma(int& _Magma_index, bool& _OnMagma);

};

