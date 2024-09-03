#pragma once
#include "GameObject.h"

class TreeSpawner : public GameObject
{
private:
	// 떨어트릴 Papaya 오브젝트를 저장할 리스트입니다.
	std::list<class papaya*> PapayaList;

	

	// 플레이어를 참조할 변수
	class Enemy* EnemyInstance;

private:
	

	// Head오브젝트 스폰
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



