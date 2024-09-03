#include "Enemy.h"
#include "Player.h"
#include "DebugLog.h"
#include "math.h"
#include "SceneManager.h"
#include "GameInstance.h"

// �� ���� �浹�ϸ� GetTickCount�� �ð��� ��� ���Դϴ�. �ٵ� 
// ������ �� ���� ����Ǽ� �ٷ� Stun�� Ǯ���� �׷��� �ι� �ϰ� ���� 
int i = 0;

//���̽�ũ�� ���� �� ���� �浹 �װ�
RECT* Enemy::GetEnemyArea()
{
	return &EnemyArea;
}


// �뽬 �Լ� �Ⱦ�����
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


//�÷��̾�� �浹�� �˻��ϱ����� 
bool Enemy::CheckOverlapPlayer()
{
	return IntersectRect(&Dest, &EnemyArea, PlayerInstance->GetPlayerArea());
}

//�浹�ϸ� ���¸� �ٲ��� �� CanShock�� ����� �ٲ�����
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
	

	// ������Ʈ ũ��(���)
	SetObejctSize(Point(90, 90));
	
	CurEnemyState = EnemyState::MOVE;
	//�ӵ� �ʱ�ȭ ->> ���̽�ũ�� ������ ������ 
	MoveSpeed = 0.3f;

	// ������Ʈ �ʱ� ��ǥ ����
	SetObjectPosition(Point(100, 90));

	SpriteIndex = SpriteDelayCheckTime = 0;
	SpriteDelay = 100;

	ShockDelayCheckTime = 0.0f;
	ShockeDelay = 3000.0f;

	// Head ���� ����
	EnemySize = { 90,90 };

	// Ȱ��ȭ ���� �ʱ�ȭ
	IsEnable = true;

	//�浹 ���� ���� �ʱ�ȭ
	CanShock = true;

	Score = 0;
	

	InitializeEnemy();
}

void Enemy::Tick()
{

	

	// ��� ����(�ٱ��� �ƴԡ�) �϶� �����̴� �ִϸ��̼��� ����
	if ((CurEnemyState == EnemyState::MOVE)) {
		// ��������Ʈ �ε����� ����
		if (GetTickCount() - SpriteDelayCheckTime >= SpriteDelay) {
			SpriteDelayCheckTime = GetTickCount();
			++SpriteIndex;
			SpriteIndex = (SpriteIndex > 5) ? 0 : SpriteIndex;
		}
		//�������°� �ƴϰ� + �Ҷ�԰� �븻 �̵� ����� �׳� �̵��ӵ��� ����
		 FindPlayer();

	}
		// �����ϸ� �� ���� �ִϸ��̼� ��������Ʈ ���̰� �ȴ� �ִϸ��̼� ���� ª�Ƽ� �̷��� ������
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
				
				MessageBox(Hwnd, TEXT("GameOver"), TEXT("���ӿ���"),  MB_OK);
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
			// �̹��� ��� ��ǥ
			GetObjectArea().left, GetObjectArea().top,

			// �̹��� ��� ������
			//GetObejctSize().x, GetObejctSize().y,
			120,100,
			EnemyBitmap->GetMemDC(),
			// �ڸ��� ������ XY��ǥ
			(SpriteIndex * 245), 0,

			// �󸶸�ŭ�� ũ��� �߶� ǥ���Ұ�����
			245, 190,
			RGB(255, 255, 255));
	}
	else if (CurEnemyState == EnemyState::ATTACK) {
		TransparentBlt(
			hdc,
			// �̹��� ��� ��ǥ
			GetObjectArea().left, GetObjectArea().top,

			// �̹��� ��� ������
			GetObejctSize().x, GetObejctSize().y,
			EnemyAttack->GetMemDC(),
			// �ڸ��� ������ XY��ǥ
			(SpriteIndex * 241), 0,

			// �󸶸�ŭ�� ũ��� �߶� ǥ���Ұ�����
			241, 190,
			RGB(255, 255, 255));
	}
	else if (CurEnemyState == EnemyState::STUN) {

		TransparentBlt(
			hdc,
			// �̹��� ��� ��ǥ
			GetObjectArea().left, GetObjectArea().top,

			// �̹��� ��� ������
			//GetObejctSize().x, GetObejctSize().y,
			120, 100,
			EnemyStun->GetMemDC(),
			// �ڸ��� ������ XY��ǥ
			(SpriteIndex * 245), 0,

			// �󸶸�ŭ�� ũ��� �߶� ǥ���Ұ�����
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