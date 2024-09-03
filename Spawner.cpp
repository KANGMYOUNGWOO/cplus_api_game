#include "Spawner.h"
#include "Head.h"

Head * Spawner::FindDisableHead() {

	for (std::list<class Head *>::iterator iter = HeadList.begin();
		iter != HeadList.end(); iter++) {
		// ��Ȱ��ȭ���� Head ������Ʈ�� ã�Ҵٸ�
		if (!((*iter)->IsEnable)) {
			// ã�� ������Ʈ�� �����մϴ�.
		}
	}
	return null;
}

Head * Spawner::SpawnHead() {

	Head * newHead = new Head();
	newHead->Initialize();
	newHead->SetPlayerInstance(PlayerInstance);
	HeadList.push_back(newHead);
	return newHead;
}

void Spawner::SetPlayerInstance(Player * playerInstance) {
	PlayerInstance = playerInstance;
}

void Spawner::Initialize() {
	SpawnDelay = 150;
	SpawnDelayCheckTime = 0;
}

void Spawner::Tick() {
	if (GetTickCount() - SpawnDelayCheckTime >= SpawnDelay) {
		SpawnDelayCheckTime = GetTickCount();

		// ��Ȱ��ȭ���� Head�� ã���ϴ�.
		Head * spawnHead = FindDisableHead();
		
		// ���� Head�� ã�� ���ߴٸ�
		if (!spawnHead) {
			spawnHead = SpawnHead();
			spawnHead->Initialize();
		}
		// ���� ã�Ҵٸ�
		else {
			spawnHead->IsEnable = true;
			spawnHead->InitializeHead();
		}
	}
	for (std::list<class Head *>::iterator iter = HeadList.begin();
		iter != HeadList.end();
		iter++) {
		(*iter)->Tick();
	}
}

void Spawner::Render(HDC hdc) {
	for (std::list<class Head *>::iterator iter = HeadList.begin();
		iter != HeadList.end();
		iter++) {
		(*iter)->Render(hdc);
	}
}

void Spawner::Release() {
	for (std::list<class Head *>::iterator iter = HeadList.begin();
		iter != HeadList.end();
		iter++) {
		(*iter)->Release();
		SafeRelease((*iter));
	}
}
