#pragma once
#include "GameObject.h"
#include "Enemy.h"



class papaya : public GameObject
{

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;
	
	
	//���ľ� ���� 3�� ��ġ�� �������� �־���
	
	void InitializePapaya();
	
	
	//�� �ν��Ͻ��� ã���� �Լ� �ФФФФФ�

	void SetEnemyInstance(class Enemy * enemyInstance);
	

	//���� ���� �Ǹ� ������ disable�� �ٲٰ� �ٽ� ���۵� �� ��ġ�� �ʱ�ȭ �մϴ�
	bool IsEnable;
	

private:
	
	//�浹�� ��õ��� ������ {0,0}���� �����ٰǵ� �� �ð��� üũ�� ����
	float DisableCheckDelay;
	float DisableDelay;

	//�浹 ���� Ȯ�� �� Ÿ��
	bool IsDisable;

	// GetTickCount�� ī��Ʈ ����� ������ �� ���� �ٷ� ����Ǵ� ������ �����ϱ� ���� ����
	int DONTDOIT;


	class Bitmap* PapayaImage;

	class Enemy* EnemyInstance;
	float EnemyDistance;
	Point PapayaSize;
	int   PapayaCount;


	RECT PapayaArea;

	RECT Dest;
	
	bool CheckOverlapEnemy();

protected:
	virtual void UpdateArea()		override;



};

