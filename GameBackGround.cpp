#include "GameBackGround.h"

void GameBackGround::Initialize() {
	// 이미지 파일 불러옵시다.
	GameBG = (new Bitmap())->LoadBmp(
		TEXT("Resource/ShootBackGround/Ocean.bmp"));
}

void GameBackGround::Tick() {
}

void GameBackGround::Render(HDC hdc) {
	BitBlt(hdc, 0, 0, 800, 600, GameBG->GetMemDC(), 0, 0, SRCCOPY);
}

void GameBackGround::Release() {
	// BMP 이미지 해제
	SafeRelease(GameBG);
}
