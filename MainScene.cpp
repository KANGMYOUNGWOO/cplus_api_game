#include "MainScene.h"

// Main Scene���� ����ϴ� ������Ʈ���� ����� ���Խ�ŵ�ϴ�.
#include "MainBackGround.h"
#include "GameInstance.h"
#include "SceneManager.h"


void MainScene::Initialize() {

	// Initialize-> �ش� ������ ����ϴ� ������Ʈ�� ��� �߰��մϴ�.
	ObjectList.push_back(new MainBackGround());

	// �θ�Ŭ������ Initialize()�� ȣ���մϴ�.
	base::Initialize();
}

void MainScene::Tick() {
	base::Tick();
}
