#include "GameBackGround.h"

void GameBackGround::Initialize() {
	// �̹��� ���� �ҷ��ɽô�.
	GameBG = (new Bitmap())->LoadBmp(
		TEXT("Resource/ShootBackGround/Ocean.bmp"));
}

void GameBackGround::Tick() {
}

void GameBackGround::Render(HDC hdc) {
	BitBlt(hdc, 0, 0, 800, 600, GameBG->GetMemDC(), 0, 0, SRCCOPY);
}

void GameBackGround::Release() {
	// BMP �̹��� ����
	SafeRelease(GameBG);
}
