#pragma once
#include "Defines.h"
#include "GameInstance.h"



class MouseUtill
{
public:
	MouseUtill();
	~MouseUtill();

public :
	//모니터 화면을 기준으로 마우스의 좌표값을 받아온다.
	static POINT GetWindowMousePosition();
	//클라이언트 화면을 기준으로 마우스 좌표 값을 받아온다
	static POINT GetClientMousePosition();
};

