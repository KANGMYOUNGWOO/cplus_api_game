#pragma once
#include "Defines.h"
#include "Bitmap.h"

#ifndef base
#define base Scene
#endif


//  > Scene Ŭ������ ��ӽ��Ѽ� ����մϴ�.
/// - �Ļ�Ŭ�������� ��� Ŭ������ �޼�����
///   Initialize(), Tick(), Render(HDC hdc), Release() �� ȣ���մϴ�.


class Scene abstract {
public:
	Scene();
	virtual ~Scene();

protected :
	//  > �ĸ� ����
	Bitmap * BackBuffer;

	//  > ����� ���ҽ�(�̹���)�� ������ ���� map
	std::map<LPCTSTR, Bitmap*> BmpResource;

	//  > ����� ������Ʈ�� ������ ���� list
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

