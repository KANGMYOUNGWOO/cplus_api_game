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
	// GameInstance 클래스 인스턴스를 참조할 포인터변수
	class GameInstance * GmInstance;
};

