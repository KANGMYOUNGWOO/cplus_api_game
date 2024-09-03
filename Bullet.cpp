#include "Bullet.h"
#include "Player.h"
#include "DebugLog.h"
#include "math.h"
#include "SceneManager.h"
#include "GameInstance.h"

Bullet* Bullet::FindDisableBullet()
{
	for (std::list<class Bullet*>::iterator iter = BulletList.begin();
		iter != BulletList.end(); iter++) {
		// 비활성화중인 Head 오브젝트를 찾았다면
		if (!((*iter)->IsEnable)) {
			// 찾은 오브젝트를 리턴합니다.
		}
	}
	return null;
}

void Bullet::InputKey()
{
	if (GetAsyncKeyState(VK_SPACE)) {
		FireBullet();
		
	}
}

Bullet* Bullet::FireBullet()
{
	Bullet* newBullet = new Bullet();
	SetPlayerInstance(PlayerInstance);
	BulletList.push_back(newBullet);
	Initialize();
	return newBullet;
}

void Bullet::SetPlayerInstance(Player* playerInstance)
{
	PlayerInstance = playerInstance;
}

void Bullet::CheckDisable()
{
	if (GetObjectPosition().y > WND_HEIGHT + 30  || GetObjectPosition().y < WND_HEIGHT - 30)
		IsEnable = false;
	else if(GetObjectPosition().x > WND_WIDTH + 30 || GetObjectPosition().x < WND_WIDTH - 30)
		IsEnable = false;
}

bool Bullet::CheckOverlapEnemy()
{
	return false;
}



void Bullet::Tick()
{
	InputKey();

	Bullet* spawnBullet = FindDisableBullet();

	// 만약 Head를 찾지 못했다면
	if (GetAsyncKeyState(VK_SPACE)) {
		if (!spawnBullet) {
			spawnBullet = FireBullet();
			spawnBullet->Initialize();
		}
		// 만약 찾았다면
		else {
			spawnBullet->IsEnable = true;

		}
	}
for (std::list<class Bullet*>::iterator iter = BulletList.begin();
	iter != BulletList.end();
	iter++) {
	(*iter)->Tick();
}

	Point position = GetObjectPosition();

	if (bul == BulletDirection::LEFT)
		position.x -= 10.0f;
	if (bul == BulletDirection::RIGHT)
		position.x += 10.0f;
	if (bul == BulletDirection::DOWN)
		position.y += 10.0f;
	if (bul == BulletDirection::UP)
		position.y += 10.0f;
	
}

void Bullet::Render(HDC hdc)
{
	if (IsEnable) {
		TransparentBlt(
			hdc,
			// 이미지 출력 좌표
			PlayerInstance->GetObjectArea().left, PlayerInstance->GetObjectArea().top,

			// 이미지 출력 사이즈
			GetObejctSize().x, GetObejctSize().y,
			BulletBitmap->GetMemDC(),
			// 자르기 시작할 XY좌표
			0, 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
			64, 64,
			RGB(255, 0, 255));
		for (std::list<class Bullet*>::iterator iter = BulletList.begin();
			iter != BulletList.end();
			iter++) {
			(*iter)->Render(hdc);
		}

	}
}

void Bullet::Release()
{
	for (std::list<class Bullet*>::iterator iter = BulletList.begin();
		iter != BulletList.end();
		iter++) {
		(*iter)->Release();
		SafeRelease((*iter));
	}
}

void Bullet::UpdateArea()
{
}

void Bullet::Initialize() {
	BulletBitmap = (new Bitmap())->LoadBmp(TEXT("Resource/Head/Head.bmp"));

	// 오브젝트 크기(헤드)
	SetObejctSize(Point(30,30));

	// 오브젝트 초기 좌표 설정
	SetObjectPosition(PlayerInstance->GetObjectPosition());
	switch (PlayerInstance->Direction) {
	
	case 0:		
		bul = BulletDirection::LEFT;
		break;
	case 1:
		bul = BulletDirection::RIGHT;
		break;
	case 2:
		bul = BulletDirection::DOWN;
		break;
	case 3:
		bul = BulletDirection::UP;
		break;

	}
	// Head 영역 설정
	BulletSize = { 40,40 };

	// 활성화 상태 초기화
	IsEnable = true;

}
