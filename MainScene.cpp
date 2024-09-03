#include "MainScene.h"

// Main Scene에서 사용하는 오브젝트들의 헤더를 포함시킵니다.
#include "MainBackGround.h"
#include "GameInstance.h"
#include "SceneManager.h"


void MainScene::Initialize() {

	// Initialize-> 해당 씬에서 사용하는 오브젝트를 모두 추가합니다.
	ObjectList.push_back(new MainBackGround());

	// 부모클래스의 Initialize()를 호출합니다.
	base::Initialize();
}

void MainScene::Tick() {
	base::Tick();
}
