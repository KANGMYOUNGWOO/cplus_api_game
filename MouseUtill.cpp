#include "MouseUtill.h"



MouseUtill::MouseUtill()
{
}


MouseUtill::~MouseUtill()
{
}

POINT MouseUtill::GetWindowMousePosition()
{
	//ㅠㅗ인터 구조체의 변수
	POINT mouse;
	//화면상 마우스 위치값을 가져온다
	GetCursorPos(&mouse);

	return mouse;
}

POINT MouseUtill::GetClientMousePosition()
{/*
	//ㅠㅗ인터 구조체의 변수
	POINT mouse;
	//클라이언트 마우스 위치값을 가져온다
	GetCursorPos(&mouse);
	//클라이언트 기준으로 변환
	//ScreenToClient(, &mouse);
	return mouse;
	*/
}
