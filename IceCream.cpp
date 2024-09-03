#include "IceCream.h"
#include "Enemy.h"
#include "DebugLog.h"

#include "SceneManager.h"
#include "GameInstance.h"

void IceCream::CheckDisable()
{
	
}

bool IceCream::CheckOverlapPlayer()
{
	return IntersectRect(&Dest, &IceCreamArea, EnemyInstance->GetEnemyArea());
}

void IceCream::InitializeIceCream()
{
	Point InitializePosition(
		(rand() % (770) + 10), (rand() % (560) +10 ));
	SetObjectPosition(InitializePosition);

	UpdateArea();
}

void IceCream::SetEnemyInstance(class Enemy* enemyInstance)
{
	EnemyInstance = enemyInstance;
}

void IceCream::Initialize()
{
	SetObejctSize(Point(30, 70));

	IceCreamBitmap = (new Bitmap())->LoadBmp(TEXT("Resource/Player/NEWICECREAM.bmp"));
	SetObjectPosition(Point(400, 50));
	
	
	IceCreamSize = { 30,70 };

	// Ȱ��ȭ ���� �ʱ�ȭ
	IsEnable = true;

	InitializeIceCream();
}

void IceCream::Tick()
{
	if (IsEnable) {

		EnemyDistance =
			sqrt(pow((GetObjectPosition().x - EnemyInstance->GetObjectPosition().x), 2.0) +
				pow((GetObjectPosition().y - EnemyInstance->GetObjectPosition().y), 2.0));

		if (EnemyDistance <= 100.0f) {
			if (CheckOverlapPlayer()) {
				IsEnable = false;
				SetObjectPosition(Point(700, 700));
				EnemyInstance->SpeedUp();
			}
		}
		UpdateArea();
	}
}

void IceCream::Render(HDC hdc)
{
	if (IsEnable) {
		TransparentBlt(
			hdc,
			// �̹��� ��� ��ǥ
			GetObjectArea().left, GetObjectArea().top,

			// �̹��� ��� ������
			GetObejctSize().x, GetObejctSize().y,
			IceCreamBitmap->GetMemDC(),
			// �ڸ��� ������ XY��ǥ
			0, 0,

			// �󸶸�ŭ�� ũ��� �߶� ǥ���Ұ�����
			300, 426,
			RGB(246, 225,134));
	}
}

void IceCream::Release()
{
	SafeRelease(IceCreamBitmap);
}

void IceCream::UpdateArea()
{
	base::UpdateArea();

	IceCreamArea = {
		(int)(GetObjectPosition().x - (IceCreamSize.x / 2)),
		(int)(GetObjectPosition().y - (IceCreamSize.y / 2)),
		(int)(GetObjectPosition().x + (IceCreamSize.x / 2)),
		(int)(GetObjectPosition().y + (IceCreamSize.y / 2))
	};
}
