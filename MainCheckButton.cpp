#include "MainCheckButton.h"



MainCheckButton::MainCheckButton()
{
}


MainCheckButton::~MainCheckButton()
{
}

void MainCheckButton::Initialize()
{
	BtnCheck = (new Bitmap())->LoadBmp(TEXT("Resourec/Button.BtnCheck.bmp"));
	Point Size = { 96 * 3, 46 * 3 };
	SetObejctSize(Size);


	SetCropSize(96, 47);
	m_Hover = true;
	SetObjectPosition(Point(800, 400));
}

void MainCheckButton::Tick()
{
	base::Tick();
}

void MainCheckButton::Render(HDC hdc)
{
	base::Render(hdc);
}
