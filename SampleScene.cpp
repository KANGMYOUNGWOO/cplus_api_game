#include "SampleScene.h"

//  > 해당 씬에서 사용할 오브젝트 헤더를 포함합니다.
#include "TestObject.h"

SampleScene::SampleScene() {
}
SampleScene::~SampleScene() {
}

void SampleScene::Initialize() {

	//  > SampleScene 에서 사용할 오브젝트를 등록합니다.
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
