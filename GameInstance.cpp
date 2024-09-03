#include "GameInstance.h"

#include "SceneManager.h"


GameInstance::GameInstance() {
	hdc = null;
}


GameInstance::~GameInstance() {
	Release();
}

void GameInstance::Initialize() {
	hdc = GetDC(Hwnd);
	SceneMgr = (SceneManager*)RegisterManagerClass(
		ManagerClassType::MT_SceneManager, new SceneManager());
	SceneMgr->Initialize();
}

void GameInstance::Tick() {
	SceneMgr->Tick();
}

void GameInstance::Render() {
	SceneMgr->Render(hdc);
}

ManagerClassBase * GameInstance::GetManagerClass(ManagerClassType managerClassType) {
	return Managers[managerClassType];
}

void GameInstance::Release() {

	for (auto iter = Managers.begin(); iter != Managers.end(); iter++) {
		SafeRelease(iter->second);
	}
	Managers.clear();

	//  > 할당받은 DC 를 해제합니다.
	if (hdc) ReleaseDC(Hwnd, hdc);

}

ManagerClassBase * GameInstance::RegisterManagerClass
(ManagerClassType managerClassType, ManagerClassBase * managerInstance) {
	// Map에 요소를 추가합니다.
	ManagerClassBase * newManagerClass = managerInstance;
	//Managers.insert(std::make_pair(managerClassType, managerInstance));
	Managers[managerClassType] = managerInstance;

	// 추가한 매니저 클래스에 GameInstance를 전달시킵니다.
	newManagerClass->SetGameInstance(this);
	
	return newManagerClass;
}
