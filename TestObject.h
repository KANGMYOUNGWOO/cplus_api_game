#pragma once
#include "GameObject.h"

class TestObject :
	public GameObject {
public:
	TestObject();
	virtual ~TestObject();


private :
	Bitmap * testBmp;


public :
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;
};

