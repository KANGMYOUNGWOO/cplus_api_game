#include "SampleScene.h"

//  > �ش� ������ ����� ������Ʈ ����� �����մϴ�.
#include "TestObject.h"

SampleScene::SampleScene() {
}
SampleScene::~SampleScene() {
}

void SampleScene::Initialize() {

	//  > SampleScene ���� ����� ������Ʈ�� ����մϴ�.
	ObjectList.push_back(new TestObject());

	base::Initialize();
}

void SampleScene::Tick() {
	base::Tick();
}

void SampleScene::Render(HDC hdc) {
	base::Render(hdc);
}

void SampleScene::Release() {
	base::Release();
}
