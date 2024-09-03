#include "MainBackGround.h"
#include "GameInstance.h"
#include "SceneManager.h"

#include "Defines.h"
#include "DebugLog.h"

void MainBackGround::Initialize() {
	// �̹����ε�
	Background = (new Bitmap())->LoadBmp(TEXT("Resource/BackGround/SORABackGround.bmp"));
	

	// ������Ʈ ��ǥ, ũ�� �ʱ�ȭ
	InitializeData(WND_WIDTH / 2, WND_HEIGHT / 2, 800, 640);
}

void MainBackGround::Tick() {
	// ����Ű�� ���ȴٸ�
	if (GetAsyncKeyState(VK_RETURN)) {
		(GameInst->SceneMgr)->SetNextScene(TEXT("GameScene"));
	}
}

void MainBackGround::Render(HDC hdc) {
	// �ҷ��� Background.bmp�� �׷��ݴϴ�.
	BitBlt(hdc,
		GetObjectArea().left, GetObjectArea().top,
		WND_WIDTH, WND_HEIGHT,
		Background->GetMemDC(),
		0, 0, SRCCOPY);

	// Textout ���� ���� ����
	
}

void MainBackGround::Release() {
	SafeRelease(Background);
	
}
