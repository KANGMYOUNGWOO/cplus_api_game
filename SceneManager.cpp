#include "SceneManager.h"

//  > ���� ���� ����� �����մϴ�.
#include "MainScene.h"
#include "GameScene.h"

#include "DebugLog.h"


SceneManager::SceneManager() {
	NextSceneName = null;
	CurrentScene = null;
}


SceneManager::~SceneManager() {
	Release();
}

void SceneManager::SetNextScene(LPCTSTR sceneName) {
	NextSceneName = sceneName;
}

void SceneManager::Initialize() {
	//  > ù ��°�� �÷��̽�ų ��
	NextSceneName = TEXT("MainScene");
}

void SceneManager::Tick() {
	UpdateScene();
	if (CurrentScene) CurrentScene->Tick();
}

void SceneManager::Render(HDC hdc) {
	if (CurrentScene) CurrentScene->Render(hdc);
}

void SceneManager::Release() {
	SafeRelease(CurrentScene);
}

void SceneManager::UpdateScene() {
	// ���� �� ��û�� ���ٸ� ������ ����մϴ�.
	if (!NextSceneName) return;

	// > ���� �÷������� ���� �ִٸ� ���� �մϴ�.
	if (CurrentScene) {
		CurrentScene->Release();
		SafeRelease(CurrentScene);
	}

	// ���� ���� �����մϴ�.

	if (StrEquals(NextSceneName, TEXT("MainScene"))) CurrentScene = new MainScene();
	else if (StrEquals(NextSceneName, TEXT("GameScene"))) CurrentScene = new GameScene();

	//����� �� �ʱ�ȭ
	if (CurrentScene) CurrentScene->Initialize();

	// ���� �� �̸� �ʱ�ȭ
	NextSceneName = null;

}
