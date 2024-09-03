#pragma once
#include "GameObject.h"
class _Spawner :public GameObject 

{

private:
	// 떨어트릴 Head 오브젝트를 저장할 리스트입니다.
	std::list<class IceCream*> IceCreamList;

	// Head를 떨어트릴때 사용할 딜레이 변수
	int SpawnDelay, SpawnDelayCheckTime;

	// 플레이어를 참조할 변수
	class Enemy* EnemyInstance;

private:
	// 비활성화중인 Head오브젝트를 찾아 리턴합니다.
	class IceCream* FindDisableIceCream();

	// Head오브젝트 스폰
	class IceCream* SpawnIceCream();

public:
	void SetEnemyInstance(class Enemy* enemyInstance);


public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;


};

