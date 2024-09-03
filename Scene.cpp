#include "Scene.h"
#include "GameObject.h"
#include "DebugLog.h"

Scene::Scene() { }
Scene::~Scene() { } 

Bitmap * Scene::GetBmpResource(LPCTSTR resourceName) {

	auto iter = BmpResource.find(resourceName);

	//  > 만약 찾지 못했다면 nullptr 를 리턴합니다.
	//    찾았다면 Bitmap 객체를 리턴합니다.
	return (iter == BmpResource.end() ? null : iter->second);
}

void Scene::Initialize() {

	//  > 화면을 그리기 전 이 전에 그려진 이미지를 지우기 위해 사용합니다.
	BmpResource[TEXT("Eraser")] = (new Bitmap())->LoadBmp(TEXT("Resource/Back/BackBuffer.bmp")); 

	BmpResource[TEXT("BackBuffer")] =  BackBuffer = 
		(new Bitmap())->LoadBmp(TEXT("Resource/Back/BackBuffer.bmp"));

	//  > 해당 씬에 추가한 오브젝트들의 Initialize를 호출합니다.
	for (std::list<GameObject * >::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); iter++) {
		(*iter)->Initialize();
	}
}

void Scene::Tick() {
	//  > 해당 씬에 추가한 오브젝트들의 Tick을 호출합니다.
	for (std::list<GameObject * >::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); iter++) {
		(*iter)->Tick();
	}
}

void Scene::Render(HDC hdc) {

	// 맨 먼저 이 전에 그려졌던 이미지들을 모두 지웁니다(덮어 씁니다.).
	BitBlt(BmpResource[TEXT("BackBuffer")]->GetMemDC(), 0, 0, WND_WIDTH, WND_HEIGHT,
		BmpResource[TEXT("Eraser")]->GetMemDC(), 0, 0, SRCCOPY);


	//  > 해당 씬에 추가한 오브젝트들의 Render를 호출합니다.
	for (std::list<GameObject * >::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); iter++) {
		(*iter)->Render(BmpResource[TEXT("BackBuffer")]->GetMemDC());
	}

	//  > 이 전에 그렸던 내용을 모두 덮어씌웁니다.
	BitBlt(hdc, 0, 0, WND_WIDTH, WND_HEIGHT,
		BmpResource[TEXT("BackBuffer")]->GetMemDC(), 0, 0, SRCCOPY);
}

void Scene::Release() {
	ReleaseResource();
	ReleaseGameObject();
}

void Scene::ReleaseResource() {
	for (auto iter = BmpResource.begin(); iter != BmpResource.end(); iter++)
		SafeRelease(iter->second);
	BmpResource.clear();
}

void Scene::ReleaseGameObject() {
	for (auto iter = ObjectList.begin(); iter != ObjectList.end(); iter++) {
		(*iter)->Release();
		SafeRelease(*iter);
	}
	ObjectList.clear();
}
