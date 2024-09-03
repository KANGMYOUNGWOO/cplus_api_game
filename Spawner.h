#pragma once
#include "GameObject.h"
class Spawner :
public GameObject{

private:
	// 떨어트릴 Head 오브젝트를 저장할 리스트입니다.
	std::list<class Head *> HeadList;

	// Head를 떨어트릴때 사용할 딜레이 변수
	int SpawnDelay, SpawnDelayCheckTime;

	// 플레이어를 참조할 변수
	class Player *  PlayerInstance;

private:
	// 비활성화중인 Head오브젝트를 찾아 리턴합니다.
	class Head * FindDisableHead();

	// Head오브젝트 스폰
	class Head * SpawnHead();

public :
	void SetPlayerInstance(class Player* playerInstance);


public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

	

};

