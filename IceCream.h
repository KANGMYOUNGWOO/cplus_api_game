#pragma once
#include "GameObject.h"
class IceCream
	:
	public GameObject
{
public:
	// Ȱ��ȭ ����
	bool IsEnable;

private:
	// �÷��̾ ������ ����
	class Enemy* EnemyInstance;

	

	// �Ӹ� �̹��� ������ ����
	Bitmap* IceCreamBitmap;

	// �Ӹ��� ũ��
	Point IceCreamSize;

	// �Ӹ��� ����
	RECT IceCreamArea;

	// �÷��̾� ������ ��ģ ������ ������ RECT ����
	RECT Dest;

	//�������� �ӵ�	
	// �÷��̾���� �Ÿ��� ������ ����
	float EnemyDistance;

private:
	// ȭ�� ������ ������ ���� üũ�ϰ�
	// ���� ȭ�� ������ �����ٸ� ������Ʈ�� ��Ȱ��ȭ ���·� ������ �Լ�
	void CheckDisable();

	// �÷��̾�� ���ƴ��� �˻��ϴ� �Լ�
	bool CheckOverlapPlayer();

public:
	// Head ������Ʈ�� �ʱ�ȭ�մϴ�.
	void InitializeIceCream();
	void SetEnemyInstance(class Enemy* enemyInstance);

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

protected:
	virtual void UpdateArea()		override;

};

