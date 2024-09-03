#include "_Spawner.h"
#include "IceCream.h"

IceCream* _Spawner::FindDisableIceCream()
{
	for (std::list<class IceCream*>::iterator iter = IceCreamList.begin();
		iter != IceCreamList.end(); iter++) {
		// 비활성화중인 Head 오브젝트를 찾았다면
		if (!((*iter)->IsEnable)) {
			// 찾은 오브젝트를 리턴합니다.
		}
	}
	return null;
}

IceCream* _Spawner::SpawnIceCream()
{
	IceCream* newIceCream = new IceCream();
	newIceCream->Initialize();
	newIceCream->SetEnemyInstance(EnemyInstance);
	IceCreamList.push_back(newIceCream);
	return newIceCream;
}

void _Spawner::SetEnemyInstance(Enemy* enemyInstance)
{
	EnemyInstance = enemyInstance;
}

void _Spawner::Initialize()
{
	SpawnDelay = 1000;
	SpawnDelayCheckTime = 0;
}

void _Spawner::Tick()
{
	if (GetTickCount() - SpawnDelayCheckTime >= SpawnDelay) {
		SpawnDelayCheckTime = GetTickCount();

		// 비활성화중인 Head를 찾습니다.
		IceCream* spawnIceCream = FindDisableIceCream();

		// 만약 Head를 찾지 못했다면
		if (!spawnIceCream) {
			spawnIceCream = SpawnIceCream();
			spawnIceCream->Initialize();
		}
		// 만약 찾았다면
		else {
			spawnIceCream->IsEnable = true;
			spawnIceCream->InitializeIceCream();
		}
	}
	for (std::list<class IceCream*>::iterator iter = IceCreamList.begin();
		iter != IceCreamList.end();
		iter++) {
		(*iter)->Tick();
	}
}

void _Spawner::Render(HDC hdc)
{
	for (std::list<class IceCream*>::iterator iter = IceCreamList.begin();
		iter != IceCreamList.end();
		iter++) {
		(*iter)->Render(hdc);
	}
}

void _Spawner::Release()
{
	for (std::list<class IceCream*>::iterator iter = IceCreamList.begin();
		iter != IceCreamList.end();
		iter++) {
		(*iter)->Release();
		SafeRelease((*iter));
	}
}
