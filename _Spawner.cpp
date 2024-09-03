#include "_Spawner.h"
#include "IceCream.h"

IceCream* _Spawner::FindDisableIceCream()
{
	for (std::list<class IceCream*>::iterator iter = IceCreamList.begin();
		iter != IceCreamList.end(); iter++) {
		// ��Ȱ��ȭ���� Head ������Ʈ�� ã�Ҵٸ�
		if (!((*iter)->IsEnable)) {
			// ã�� ������Ʈ�� �����մϴ�.
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

		// ��Ȱ��ȭ���� Head�� ã���ϴ�.
		IceCream* spawnIceCream = FindDisableIceCream();

		// ���� Head�� ã�� ���ߴٸ�
		if (!spawnIceCream) {
			spawnIceCream = SpawnIceCream();
			spawnIceCream->Initialize();
		}
		// ���� ã�Ҵٸ�
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
