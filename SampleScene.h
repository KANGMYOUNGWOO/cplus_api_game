#pragma once
#include "Scene.h"


class SampleScene :
	public Scene {
public:
	SampleScene();
	virtual ~SampleScene();

public :
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;
};

