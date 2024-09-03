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
		// ��Ȱ��ȭ���� Head ������Ʈ�� ã�Ҵٸ�
		if (!((*iter)->IsEnable)) {
			// ã�� ������Ʈ�� �����մϴ�.
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

	// ���� Head�� ã�� ���ߴٸ�
	if (GetAsyncKeyState(VK_SPACE)) {
		if (!spawnBullet) {
			spawnBullet = FireBullet();
			spawnBullet->Initialize();
		}
		// ���� ã�Ҵٸ�
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
			// �̹��� ��� ��ǥ
			PlayerInstance->GetObjectArea().left, PlayerInstance->GetObjectArea().top,

			// �̹��� ��� ������
			GetObejctSize().x, GetObejctSize().y,
			BulletBitmap->GetMemDC(),
			// �ڸ��� ������ XY��ǥ
			0, 0,

			// �󸶸�ŭ�� ũ��� �߶� ǥ���Ұ�����
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

	// ������Ʈ ũ��(���)
	SetObejctSize(Point(30,30));

	// ������Ʈ �ʱ� ��ǥ ����
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
	// Head ���� ����
	BulletSize = { 40,40 };

	// Ȱ��ȭ ���� �ʱ�ȭ
	IsEnable = true;

}
