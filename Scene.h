#pragma once
#include "Defines.h"
#include "Bitmap.h"

#ifndef base
#define base Scene
#endif


//  > Scene 클래스를 상속시켜서 사용합니다.
/// - 파생클래스에서 기반 클래스의 메서드인
///   Initialize(), Tick(), Render(HDC hdc), Release() 를 호출합니다.


class Scene abstract {
public:
	Scene();
	virtual ~Scene();

protected :
	//  > 후면 버퍼
	Bitmap * BackBuffer;

	//  > 사용할 리소스(이미지)를 가지고 있을 map
	std::map<LPCTSTR, Bitmap*> BmpResource;

	//  > 사용할 오브젝트를 가지고 있을 list
	std::list<class GameObject * > ObjectList;

public :
	Bitmap * GetBmpResource(LPCTSTR resourceName);


public :
	virtual void Initialize();
	virtual void Tick();

	virtual void Render(HDC hdc);
	virtual void Release();


	void ReleaseResource();

	void ReleaseGameObject();
};

