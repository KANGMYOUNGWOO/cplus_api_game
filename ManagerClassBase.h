#pragma once
#include "Defines.h"
class ManagerClassBase abstract {
public:
	ManagerClassBase();
	virtual ~ManagerClassBase();

public:
	void SetGameInstance(class GameInstance * gameInstance);
	class GameInstance * GetGameInstance();

private :
	// GameInstance Ŭ���� �ν��Ͻ��� ������ �����ͺ���
	class GameInstance * GmInstance;
};

