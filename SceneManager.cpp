#include "SceneManager.h"

//  > 사용될 씬의 헤더를 포함합니다.
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
	//  > 첫 번째로 플레이시킬 씬
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
	// 다음 씬 요청이 없다면 실행을 취소합니다.
	if (!NextSceneName) return;

	// > 만약 플레이중인 씬이 있다면 해제 합니다.
	if (CurrentScene) {
		CurrentScene->Release();
		SafeRelease(CurrentScene);
	}

	// 다음 씬을 변경합니다.

	if (StrEquals(NextSceneName, TEXT("MainScene"))) CurrentScene = new MainScene();
	else if (StrEquals(NextSceneName, TEXT("GameScene"))) CurrentScene = new GameScene();

	//사용할 씬 초기화
	if (CurrentScene) CurrentScene->Initialize();

	// 다음 씬 이름 초기화
	NextSceneName = null;

}
