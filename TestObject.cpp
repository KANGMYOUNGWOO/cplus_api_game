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

		//  > �̹��� ��� ���� ��ǥ
		GetObjectArea().left, GetObjectArea().top,

		//  > �̹����� ���������� �󸶳� ũ�� ����� ������ �����մϴ�.
		GetObjectArea().right, GetObjectArea().bottom,

		testBmp->GetMemDC(),

		//  > �ڸ��� ������ ��ǥ
		0, 0,

		//  > ��ŭ�� ũ��� �ڸ� ������
		300, 200,

		//  > � ������ ���� ������
		RGB(255, 0, 255));
}

void TestObject::Release() {
	SafeRelease(testBmp);
}
