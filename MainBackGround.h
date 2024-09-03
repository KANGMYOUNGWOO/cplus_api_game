#pragma once
#include "GameObject.h"
class MainBackGround : public GameObject {

private :
	// ����̹���
	class Bitmap * Background;
	

	// �� �Ŵ����� ������ ����
	class SceneManager * SceneMgr;

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;
};

