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

	// 활성화 상태 초기화
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
			// 이미지 출력 좌표
			GetObjectArea().left, GetObjectArea().top,

			// 이미지 출력 사이즈
			GetObejctSize().x, GetObejctSize().y,
			IceCreamBitmap->GetMemDC(),
			// 자르기 시작할 XY좌표
			0, 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
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
