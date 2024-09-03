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

	//  > �Ҵ���� DC �� �����մϴ�.
	if (hdc) ReleaseDC(Hwnd, hdc);

}

ManagerClassBase * GameInstance::RegisterManagerClass
(ManagerClassType managerClassType, ManagerClassBase * managerInstance) {
	// Map�� ��Ҹ� �߰��մϴ�.
	ManagerClassBase * newManagerClass = managerInstance;
	//Managers.insert(std::make_pair(managerClassType, managerInstance));
	Managers[managerClassType] = managerInstance;

	// �߰��� �Ŵ��� Ŭ������ GameInstance�� ���޽�ŵ�ϴ�.
	newManagerClass->SetGameInstance(this);
	
	return newManagerClass;
}
