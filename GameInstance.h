#pragma once
#include "Defines.h"

// 매니저 클래스 타입
enum class ManagerClassType : short {
	MT_SceneManager
};

class GameInstance {
public:
	GameInstance();
	~GameInstance();

private :
	HDC hdc;

public:
	// 매니저 클래스 인스턴스를 가지고 있도록 할 map
	std::map<ManagerClassType, class ManagerClassBase *> Managers;

public :
	class SceneManager * SceneMgr;
	

public :
	void Initialize();
	void Tick();
	void Render();

	// 등록한 매니저 클래스 정보를 가져옵니다.
	class ManagerClassBase * GetManagerClass(ManagerClassType managerClassType);

private :
	void Release(); 

//  매니저 클래스를 등록시킵니다.
	class ManagerClassBase * RegisterManagerClass(
		ManagerClassType managerClassType, class ManagerClassBase * managerInstance);
};

