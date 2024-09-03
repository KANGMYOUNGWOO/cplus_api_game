#include "Enemy.h"
#include "Player.h"
#include "DebugLog.h"
#include "math.h"
#include "SceneManager.h"
#include "GameInstance.h"

// 그 뭐냐 충돌하면 GetTickCount로 시간을 잰단 말입니다. 근데 
// 무조건 한 번은 실행되서 바로 Stun이 풀려요 그래서 두번 하게 만듬 
int i = 0;

//아이스크림 먹을 떄 쓰는 충돌 그거
RECT* Enemy::GetEnemyArea()
{
	return &EnemyArea;
}


// 대쉬 함수 안쓸거임
void Enemy::EnemyDash()
{
	float AttackDelayTime = 0.0f;
		float AttackDelay = 3.0f;
	CurEnemyState = EnemyState::ATTACK;
	if (GetTickCount() - AttackDelayTime >= AttackDelay) {
		AttackDelayTime = GetTickCount();
		MoveSpeed = 0.0f;
	}
	MoveSpeed = 0.22f;
	Point currentPosition = GetObjectPosition();
	
	if (PlayerPosition.x > GetObjectPosition().x) {
		currentPosition.x += MoveSpeed;
	}
	else
		currentPosition.x -= MoveSpeed;
		
	
		if (PlayerPosition.y > GetObjectPosition().y) {
			currentPosition.y += MoveSpeed;
		}
		else
			currentPosition.y -= MoveSpeed;
	
	SetObjectPosition(currentPosition);


}


//플레이어와 충돌을 검사하기위한 
bool Enemy::CheckOverlapPlayer()
{
	return IntersectRect(&Dest, &EnemyArea, PlayerInstance->GetPlayerArea());
}

//충돌하면 상태를 바꿔줌 그 CanShock도 겸사겸사 바꿔주자
void Enemy::ChangeState()
{
	/*
	if (CurEnemyState == EnemyState::MOVE && CanShock) {
		CurEnemyState = EnemyState::STUN;
		CanShock = false;
	}
	if (CurEnemyState == EnemyState::STUN && !CanShock) {
		CurEnemyState = EnemyState::MOVE;
		CanShock = true;
	}
	
	*/

	CurEnemyState = EnemyState::STUN;


}

void Enemy::SpeedUp()
{
	if (MoveSpeed == 2.5f) MoveSpeed = 2.5f;
	else
	MoveSpeed += 0.04f;


	Score += 10;
	
}

void Enemy::ExitStun()
{
	if (GetTickCount() - ShockDelayCheckTime >= ShockeDelay) {
		ShockDelayCheckTime = GetTickCount();
		CanShock = true;
		CurEnemyState = EnemyState::MOVE;

	}
}

void Enemy::ResetSpeed()
{
	MoveSpeed = 0.3f;
}

void Enemy::FindPlayer()
{
	CurEnemyState = EnemyState::MOVE;
	PlayerPosition =
		PlayerInstance->GetObjectPosition();
	

	Point currentPosition = GetObjectPosition();
	if (PlayerPosition.x > GetObjectPosition().x) {
		currentPosition.x += MoveSpeed;
	}
	else
		currentPosition.x -= MoveSpeed;
	
		if (PlayerPosition.y > GetObjectPosition().y) {
			currentPosition.y += MoveSpeed;
		}
		else
			currentPosition.y -= MoveSpeed;
	
	SetObjectPosition(currentPosition);
}



void Enemy::InitializeEnemy()
{
	Point InitializePosition(30, 30);
}





void Enemy::SetPlayerInstance(Player* playerInstance)
{
	PlayerInstance = playerInstance;

}

void Enemy::SetPapayaInstance(papaya * papayaInstance)
{
	PapayaInstance = papayaInstance;
}

void Enemy::Initialize()
{
	EnemyBitmap = (new Bitmap())->LoadBmp(TEXT("Resource/Player/EnemyMove.bmp"));
	EnemyAttack = (new Bitmap())->LoadBmp(TEXT("Resource/Player/EnemyAttack.bmp"));
	EnemyStun   = (new Bitmap())->LoadBmp(TEXT("Resource/Player/EnemyStun.bmp"));
	

	// 오브젝트 크기(헤드)
	SetObejctSize(Point(90, 90));
	
	CurEnemyState = EnemyState::MOVE;
	//속도 초기화 ->> 아이스크림 먹으면 빨라짐 
	MoveSpeed = 0.3f;

	// 오브젝트 초기 좌표 설정
	SetObjectPosition(Point(100, 90));

	SpriteIndex = SpriteDelayCheckTime = 0;
	SpriteDelay = 100;

	ShockDelayCheckTime = 0.0f;
	ShockeDelay = 3000.0f;

	// Head 영역 설정
	EnemySize = { 90,90 };

	// 활성화 상태 초기화
	IsEnable = true;

	//충돌 가능 변수 초기화
	CanShock = true;

	Score = 0;
	

	InitializeEnemy();
}

void Enemy::Tick()
{

	

	// 평시 상태(☆기절 아님☆) 일때 움직이는 애니메이션을 구현
	if ((CurEnemyState == EnemyState::MOVE)) {
		// 스프라이트 인덱스를 증가
		if (GetTickCount() - SpriteDelayCheckTime >= SpriteDelay) {
			SpriteDelayCheckTime = GetTickCount();
			++SpriteIndex;
			SpriteIndex = (SpriteIndex > 5) ? 0 : SpriteIndex;
		}
		//기절상태가 아니고 + 소라게가 노말 이동 모드라면 그냥 이동속도로 걸음
		 FindPlayer();

	}
		// 기절하면 그 기절 애니메이션 스프라이트 길이가 걷는 애니메이션 보다 짧아서 이렇게 해주자
	else {
		if (GetTickCount() - SpriteDelayCheckTime >= SpriteDelay) {
			SpriteDelayCheckTime = GetTickCount();
			++SpriteIndex;
			SpriteIndex = (SpriteIndex > 3) ? 0 : SpriteIndex;
			
		}

		//ExitStun(); 
		if (GetTickCount() - ShockDelayCheckTime >= ShockeDelay) {
			ShockDelayCheckTime = GetTickCount();
			
			i++;
			if (i > 1) {
				CanShock = true;
				CurEnemyState = EnemyState::MOVE;
				i = 0;
			}
		}
		

	}

		PlayerDistance =
			sqrt(pow((GetObjectPosition().x - PlayerInstance->GetObjectPosition().x), 2.0) +
				pow((GetObjectPosition().y - PlayerInstance->GetObjectPosition().y), 2.0));

		if (PlayerDistance <= 50.0f) {
			if (CheckOverlapPlayer()) {
				
				MessageBox(Hwnd, TEXT("GameOver"), TEXT("게임오버"),  MB_OK);
				((SceneManager*)GameInst->GetManagerClass(ManagerClassType::MT_SceneManager))->
					SetNextScene("MainScene");
			}
		}

		
		else if (CurEnemyState == EnemyState::ATTACK) EnemyDash();
		
	
	UpdateArea();

}




void Enemy::Render(HDC hdc)
{
	//TextOut(hdc, 100, 10, (LPCTSTR)Score, strlen((LPCTSTR)Score));

	if (CurEnemyState == EnemyState::MOVE) {
		TransparentBlt(
			hdc,
			// 이미지 출력 좌표
			GetObjectArea().left, GetObjectArea().top,

			// 이미지 출력 사이즈
			//GetObejctSize().x, GetObejctSize().y,
			120,100,
			EnemyBitmap->GetMemDC(),
			// 자르기 시작할 XY좌표
			(SpriteIndex * 245), 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
			245, 190,
			RGB(255, 255, 255));
	}
	else if (CurEnemyState == EnemyState::ATTACK) {
		TransparentBlt(
			hdc,
			// 이미지 출력 좌표
			GetObjectArea().left, GetObjectArea().top,

			// 이미지 출력 사이즈
			GetObejctSize().x, GetObejctSize().y,
			EnemyAttack->GetMemDC(),
			// 자르기 시작할 XY좌표
			(SpriteIndex * 241), 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
			241, 190,
			RGB(255, 255, 255));
	}
	else if (CurEnemyState == EnemyState::STUN) {

		TransparentBlt(
			hdc,
			// 이미지 출력 좌표
			GetObjectArea().left, GetObjectArea().top,

			// 이미지 출력 사이즈
			//GetObejctSize().x, GetObejctSize().y,
			120, 100,
			EnemyStun->GetMemDC(),
			// 자르기 시작할 XY좌표
			(SpriteIndex * 245), 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
			245, 190,
			RGB(255, 255, 255));

	}

}

void Enemy::Release()
{
	SafeRelease(EnemyBitmap);
	SafeRelease(EnemyAttack);
}

void Enemy::UpdateArea()
{
	base::UpdateArea();

	EnemyArea = {
		(int)(GetObjectPosition().x - (EnemySize.x / 2)),
		(int)(GetObjectPosition().y - (EnemySize.y / 2)),
		(int)(GetObjectPosition().x + (EnemySize.x / 2)),
		(int)(GetObjectPosition().y + (EnemySize.y / 2))
	};
}