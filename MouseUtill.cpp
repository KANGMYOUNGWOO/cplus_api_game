#include "MouseUtill.h"



MouseUtill::MouseUtill()
{
}


MouseUtill::~MouseUtill()
{
}

POINT MouseUtill::GetWindowMousePosition()
{
	//�Ф����� ����ü�� ����
	POINT mouse;
	//ȭ��� ���콺 ��ġ���� �����´�
	GetCursorPos(&mouse);

	return mouse;
}

POINT MouseUtill::GetClientMousePosition()
{/*
	//�Ф����� ����ü�� ����
	POINT mouse;
	//Ŭ���̾�Ʈ ���콺 ��ġ���� �����´�
	GetCursorPos(&mouse);
	//Ŭ���̾�Ʈ �������� ��ȯ
	//ScreenToClient(, &mouse);
	return mouse;
	*/
}
