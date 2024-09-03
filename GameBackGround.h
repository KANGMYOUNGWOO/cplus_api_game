#pragma once
#include "GameObject.h"
class GameBackGround :
	public GameObject {

private : 
	class Bitmap* GameBG;

public:
	virtual void Initialize()	override;
	virtual void Tick()			override;
	virtual void Render(HDC hdc)override;
	virtual void Release()		override;

};

