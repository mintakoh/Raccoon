#pragma once


//�� (���� ���� ���� ó��, ���̴� ���� ���İ��� ������� �ʴ´�, �츸 ���)
class Enemy
{
public:
	Enemy();
	~Enemy();

	int x;			//x��ǥ
	int y;			//y��ǥ
	int alpha;		//�� ����ϴ� �����ϰ�
	char speed;		//�ӵ�
	bool state;		//����(�¿�)
	bool type;		//�Ϲ����� ��, ��

	// ��
	CBitmap		_hEnemyRight;
	CBitmap		_hEnemyLeft;
	CBitmap		_hEnemyRightRed;
	CBitmap		_hEnemyLeftRed;

	//��
	CBitmap		_hSnakeLeft;
	CBitmap		_hSnakeRight;

	static int _EnemyCount;

};

