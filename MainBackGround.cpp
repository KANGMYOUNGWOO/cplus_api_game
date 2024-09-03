#include "MainBackGround.h"
#include "GameInstance.h"
#include "SceneManager.h"

#include "Defines.h"
#include "DebugLog.h"

void MainBackGround::Initialize() {
	// 이미지로드
	Background = (new Bitmap())->LoadBmp(TEXT("Resource/BackGround/SORABackGround.bmp"));
	

	// 오브젝트 좌표, 크기 초기화
	InitializeData(WND_WIDTH / 2, WND_HEIGHT / 2, 800, 640);
}

void MainBackGround::Tick() {
	// 엔터키가 눌렸다면
	if (GetAsyncKeyState(VK_RETURN)) {
		(GameInst->SceneMgr)->SetNextScene(TEXT("GameScene"));
	}
}

void MainBackGround::Render(HDC hdc) {
	// 불러온 Background.bmp를 그려줍니다.
	BitBlt(hdc,
		GetObjectArea().left, GetObjectArea().top,
		WND_WIDTH, WND_HEIGHT,
		Background->GetMemDC(),
		0, 0, SRCCOPY);

	// Textout 정렬 기준 설정
	
}

void MainBackGround::Release() {
	SafeRelease(Background);
	
}
