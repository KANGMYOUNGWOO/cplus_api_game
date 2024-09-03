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
		// ��Ȱ��ȭ���� papaya ������Ʈ�� ã�Ҵٸ�
		if (!((*iter)->IsEnable)) {
			// ã�� ������Ʈ�� �����մϴ�.
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

	// ���� Head�� ã�� ���ߴٸ�
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