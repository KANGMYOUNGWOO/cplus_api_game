#pragma once
#include "Scene.h"
class MainScene :
	public Scene {
public:
	virtual void Initialize()	override;
	virtual void Tick()			override;
};

