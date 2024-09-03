#include "TreeSpawner.h"
#include "papaya.h"

papaya * TreeSpawner::SpawnPapaya()
{
	papaya* newPapaya = new papaya();
	newPapaya->Initialize();
	newPapaya->SetEnemyInstance(EnemyInstance);
	PapayaList.push_back(newPapaya);
	return newPapaya;
}

papaya * TreeSpawner::FindDisablePapaya()
{
	for (std::list<class papaya*>::iterator iter = PapayaList.begin();
		iter != PapayaList.end(); iter++) {
		// 비활성화중인 papaya 오브젝트를 찾았다면
		if (!((*iter)->IsEnable)) {
			// 찾은 오브젝트를 리턴합니다.
		}
	}
	return null;
}

void TreeSpawner::SetEnemyInstance(class Enemy * enemyInstance)
{
	EnemyInstance = enemyInstance;
}

void TreeSpawner::Initialize()
{
	
}

void TreeSpawner::Tick()
{
	papaya* spawnPapaya = FindDisablePapaya();

	// 만약 Head를 찾지 못했다면
	if (PapayaCount < 2) {
		if (!spawnPapaya) {

			spawnPapaya = SpawnPapaya();
			spawnPapaya->Initialize();
			
		}
		PapayaCount++;
	}

	


	for (std::list<class papaya*>::iterator iter = PapayaList.begin();
		iter != PapayaList.end();iter++) {
		(*iter)->Tick();
	}
}

void TreeSpawner::Render(HDC hdc)
{
	for (std::list<class papaya*>::iterator iter = PapayaList.begin();
		iter != PapayaList.end();iter++) {
		(*iter)->Render(hdc);
	}
}



void TreeSpawner::Release()
{
	for (std::list<class papaya*>::iterator iter = PapayaList.begin();
		iter != PapayaList.end(); iter++) {
		(*iter)->Release();
		SafeRelease((*iter));
	}
}