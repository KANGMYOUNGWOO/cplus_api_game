#pragma once
#include "GameObject.h"
class Spawner :
public GameObject{

private:
	// ����Ʈ�� Head ������Ʈ�� ������ ����Ʈ�Դϴ�.
	std::list<class Head *> HeadList;

	// Head�� ����Ʈ���� ����� ������ ����
	int SpawnDelay, SpawnDelayCheckTime;

	// �÷��̾ ������ ����
	class Player *  PlayerInstance;

private:
	// ��Ȱ��ȭ���� Head������Ʈ�� ã�� �����մϴ�.
	class Head * FindDisableHead();

	// Head������Ʈ ����
	class Head * SpawnHead();

public :
	void SetPlayerInstance(class Player* playerInstance);


public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

	

};

