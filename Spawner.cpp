#include "Spawner.h"
#include "Head.h"

Head * Spawner::FindDisableHead() {

	for (std::list<class Head *>::iterator iter = HeadList.begin();
		iter != HeadList.end(); iter++) {
		// 비활성화중인 Head 오브젝트를 찾았다면
		if (!((*iter)->IsEnable)) {
			// 찾은 오브젝트를 리턴합니다.
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

		// 비활성화중인 Head를 찾습니다.
		Head * spawnHead = FindDisableHead();
		
		// 만약 Head를 찾지 못했다면
		if (!spawnHead) {
			spawnHead = SpawnHead();
			spawnHead->Initialize();
		}
		// 만약 찾았다면
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
