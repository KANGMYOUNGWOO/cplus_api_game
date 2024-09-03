#include "papaya.h"
#include "SceneManager.h"
#include "GameInstance.h"
#include "Enemy.h"
#include "DebugLog.h"




void papaya::Initialize()
{
	SetObejctSize(Point(80, 80));
	PapayaSize = { 80,80 };
	PapayaImage = (new Bitmap())->LoadBmp(TEXT("Resource/GameBackGround/PAPAYA.bmp"));
	PapayaCount = 0;
	IsEnable = true;
	
	DONTDOIT = 0;
	DisableCheckDelay = 0.0f;
	DisableDelay = 10000.0f;
	IsDisable = false;

	InitializePapaya();
}

void papaya::Tick()
{
	
	
	
		UpdateArea();

		EnemyDistance =
			sqrt(pow((GetObjectPosition().x - EnemyInstance->GetObjectPosition().x), 2.0) +
				pow((GetObjectPosition().y - EnemyInstance->GetObjectPosition().y), 2.0));
		if (!IsDisable) {
			if (EnemyDistance <= 100.0f) {
				if (CheckOverlapEnemy()) {
					EnemyInstance->ChangeState();
					EnemyInstance->ResetSpeed();
					IsDisable = true;

					//SetObjectPosition(Point(700, 700));
					
				}
			}
		}
		else {
			if (GetTickCount() - DisableCheckDelay >= DisableDelay) {
				DisableCheckDelay = GetTickCount();
				DONTDOIT++;
				if (DONTDOIT > 1) {
					IsDisable = false;
					DONTDOIT = 0;
				}
				
			}
		}
	
}

void papaya::Render(HDC hdc)
{
	
		TransparentBlt(
			hdc,
			// 이미지 출력 좌표
			GetObjectArea().left, GetObjectArea().top,

			// 이미지 출력 사이즈
			GetObejctSize().x, GetObejctSize().y,
			PapayaImage->GetMemDC(),
			// 자르기 시작할 XY좌표
			0, 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
			416, 416,
			RGB(255, 255, 255));
	
}

void papaya::Release()
{
	SafeRelease(PapayaImage);
}

void papaya::InitializePapaya()
{
	
	//나무 4개만 만들자
	
		Point InitializePosition(
			(rand() % (630) + 50), (rand() % (490) + 50));
		SetObjectPosition(InitializePosition);

		UpdateArea();
		

	
	
}

void papaya::SetEnemyInstance(class Enemy *enemyInstance)
{
	EnemyInstance = enemyInstance;
}



bool papaya::CheckOverlapEnemy()
{
	return IntersectRect(&Dest, &PapayaArea, EnemyInstance->GetEnemyArea());
}

void papaya::UpdateArea()
{
	base::UpdateArea();

	PapayaArea = {
		(int)(GetObjectPosition().x - (PapayaSize.x / 2)),
		(int)(GetObjectPosition().y - (PapayaSize.y / 2)),
		(int)(GetObjectPosition().x + (PapayaSize.x / 2)),
		(int)(GetObjectPosition().y + (PapayaSize.y / 2))
	};
}
