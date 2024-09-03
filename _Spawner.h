#pragma once
#include "GameObject.h"
class _Spawner :public GameObject 

{

private:
	// ����Ʈ�� Head ������Ʈ�� ������ ����Ʈ�Դϴ�.
	std::list<class IceCream*> IceCreamList;

	// Head�� ����Ʈ���� ����� ������ ����
	int SpawnDelay, SpawnDelayCheckTime;

	// �÷��̾ ������ ����
	class Enemy* EnemyInstance;

private:
	// ��Ȱ��ȭ���� Head������Ʈ�� ã�� �����մϴ�.
	class IceCream* FindDisableIceCream();

	// Head������Ʈ ����
	class IceCream* SpawnIceCream();

public:
	void SetEnemyInstance(class Enemy* enemyInstance);


public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;


};

