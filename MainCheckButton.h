#pragma once
#include "Button.h"

class MainCheckButton : public Button
{
public:
	MainCheckButton();
	virtual ~MainCheckButton();


public :

	virtual void Initialize() override;
	virtual void Tick()       override;
	virtual void Render(HDC hdc) override;
	 
	class Bitmap* BtnCheck;
};

