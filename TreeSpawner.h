#pragma once
#include "GameObject.h"

class TreeSpawner : public GameObject
{
private:
	// ����Ʈ�� Papaya ������Ʈ�� ������ ����Ʈ�Դϴ�.
	std::list<class papaya*> PapayaList;

	

	// �÷��̾ ������ ����
	class Enemy* EnemyInstance;

private:
	

	// Head������Ʈ ����
	class papaya* SpawnPapaya();
	class papaya* FindDisablePapaya();
	
	
	int PapayaCount = 0;

public:
	void SetEnemyInstance(class Enemy* enemyInstance);


public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;


};



