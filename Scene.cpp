#include "Scene.h"
#include "GameObject.h"
#include "DebugLog.h"

Scene::Scene() { }
Scene::~Scene() { } 

Bitmap * Scene::GetBmpResource(LPCTSTR resourceName) {

	auto iter = BmpResource.find(resourceName);

	//  > ���� ã�� ���ߴٸ� nullptr �� �����մϴ�.
	//    ã�Ҵٸ� Bitmap ��ü�� �����մϴ�.
	return (iter == BmpResource.end() ? null : iter->second);
}

void Scene::Initialize() {

	//  > ȭ���� �׸��� �� �� ���� �׷��� �̹����� ����� ���� ����մϴ�.
	BmpResource[TEXT("Eraser")] = (new Bitmap())->LoadBmp(TEXT("Resource/Back/BackBuffer.bmp")); 

	BmpResource[TEXT("BackBuffer")] =  BackBuffer = 
		(new Bitmap())->LoadBmp(TEXT("Resource/Back/BackBuffer.bmp"));

	//  > �ش� ���� �߰��� ������Ʈ���� Initialize�� ȣ���մϴ�.
	for (std::list<GameObject * >::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); iter++) {
		(*iter)->Initialize();
	}
}

void Scene::Tick() {
	//  > �ش� ���� �߰��� ������Ʈ���� Tick�� ȣ���մϴ�.
	for (std::list<GameObject * >::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); iter++) {
		(*iter)->Tick();
	}
}

void Scene::Render(HDC hdc) {

	// �� ���� �� ���� �׷����� �̹������� ��� ����ϴ�(���� ���ϴ�.).
	BitBlt(BmpResource[TEXT("BackBuffer")]->GetMemDC(), 0, 0, WND_WIDTH, WND_HEIGHT,
		BmpResource[TEXT("Eraser")]->GetMemDC(), 0, 0, SRCCOPY);


	//  > �ش� ���� �߰��� ������Ʈ���� Render�� ȣ���մϴ�.
	for (std::list<GameObject * >::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); iter++) {
		(*iter)->Render(BmpResource[TEXT("BackBuffer")]->GetMemDC());
	}

	//  > �� ���� �׷ȴ� ������ ��� �����ϴ�.
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
