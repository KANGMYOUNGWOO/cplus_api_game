#pragma once
#include "Defines.h"
#include "GameInstance.h"



class MouseUtill
{
public:
	MouseUtill();
	~MouseUtill();

public :
	//����� ȭ���� �������� ���콺�� ��ǥ���� �޾ƿ´�.
	static POINT GetWindowMousePosition();
	//Ŭ���̾�Ʈ ȭ���� �������� ���콺 ��ǥ ���� �޾ƿ´�
	static POINT GetClientMousePosition();
};

