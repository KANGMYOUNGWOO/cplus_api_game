#pragma once
#include "Defines.h"

// �Ŵ��� Ŭ���� Ÿ��
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
	// �Ŵ��� Ŭ���� �ν��Ͻ��� ������ �ֵ��� �� map
	std::map<ManagerClassType, class ManagerClassBase *> Managers;

public :
	class SceneManager * SceneMgr;
	

public :
	void Initialize();
	void Tick();
	void Render();

	// ����� �Ŵ��� Ŭ���� ������ �����ɴϴ�.
	class ManagerClassBase * GetManagerClass(ManagerClassType managerClassType);

private :
	void Release(); 

//  �Ŵ��� Ŭ������ ��Ͻ�ŵ�ϴ�.
	class ManagerClassBase * RegisterManagerClass(
		ManagerClassType managerClassType, class ManagerClassBase * managerInstance);
};

