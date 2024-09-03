#pragma once
#include "GameObject.h"
class MainBackGround : public GameObject {

private :
	// 배경이미지
	class Bitmap * Background;
	

	// 씬 매니저를 참조할 변수
	class SceneManager * SceneMgr;

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;
};

