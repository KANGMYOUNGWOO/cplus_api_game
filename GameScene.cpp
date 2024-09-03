#include "GameScene.h"

#include "GameBackGround.h"
#include "Player.h"

#include "Enemy.h"
#include "_Spawner.h"
#include "IceCream.h"
#include "TreeSpawner.h" 
#include "papaya.h"


void GameScene::Initialize() {
	ObjectList.push_back(new GameBackGround());

	// 플레이어의 인스턴스 변수를 할당합니다.
	Player * playerInstance = new Player();
	ObjectList.push_back(playerInstance);

	Enemy* enemy = new Enemy();
	enemy->SetPlayerInstance(playerInstance);
	ObjectList.push_back(enemy);

	_Spawner* spawner = new _Spawner();
	spawner->SetEnemyInstance(enemy);
	ObjectList.push_back(spawner);

	TreeSpawner* treespawner = new TreeSpawner();
	treespawner->SetEnemyInstance(enemy);
	ObjectList.push_back(treespawner);

	// 스포너 
	


	base::Initialize();
}
