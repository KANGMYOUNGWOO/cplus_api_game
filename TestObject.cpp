#include "TestObject.h"


TestObject::TestObject() {
}


TestObject::~TestObject() {
}

void TestObject::Initialize() {

	testBmp = (new Bitmap)->LoadBmp(TEXT("Resource/TestResource/MyCharacter.bmp"));
	InitializeData(WND_WIDTH / 2, WND_HEIGHT / 2, 300, 200);
}

void TestObject::Tick() {
}

void TestObject::Render(HDC hdc) {

	TransparentBlt(
		hdc,

		//  > 이미지 출력 시작 좌표
		GetObjectArea().left, GetObjectArea().top,

		//  > 이미지를 최종적으로 얼마나 크게 출력할 것인지 지정합니다.
		GetObjectArea().right, GetObjectArea().bottom,

		testBmp->GetMemDC(),

		//  > 자르기 시작할 좌표
		0, 0,

		//  > 얼만큼의 크기로 자를 것인지
		300, 200,

		//  > 어떤 색상을 숨길 것인지
		RGB(255, 0, 255));
}

void TestObject::Release() {
	SafeRelease(testBmp);
}
