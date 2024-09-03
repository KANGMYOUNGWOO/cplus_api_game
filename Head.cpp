#include "Head.h"
#include "Player.h"
#include "DebugLog.h"
#include "math.h"
#include "SceneManager.h"
#include "GameInstance.h"


void Head::CheckDisable() {
	// 화면 밑으로 내려갔다면
	if (GetObjectPosition().y > WND_HEIGHT + 50)
		IsEnable = false;
}

bool Head::CheckOverlapPlayer() {
	// 플레이어와 겹쳤는지 검사합니다.
	// IntersectRect : RECT간의 충돌을 검사합니다.
	return IntersectRect(&Dest, &HeadArea, PlayerInstance->GetPlayerArea());
}

void Head::InitializeHead() {
	// 초기 좌표 설정합니다
	Point InitializePosition(
		(rand() % WND_WIDTH), -50);

	// 떨어지는 값
	//FallSpeed = ((rand() % 17) + 3)*0.1f;
	FallSpeed = 0;

	// 설정한 좌표로 이동시킵니다.
	SetObjectPosition(InitializePosition);

	UpdateArea();
}

void Head::SetPlayerInstance(Player * playerInstance) {
	PlayerInstance = playerInstance;
}

void Head::Initialize() {
	HeadBitmap = (new Bitmap())->LoadBmp(TEXT("Resource/Head/Head.bmp"));

	// 오브젝트 크기(헤드)
	SetObejctSize(Point(64, 64));

	// 오브젝트 초기 좌표 설정
	SetObjectPosition(Point(400, 50));

	SpriteIndex = SpriteDelayCheckTime = 0;
	SpriteDelay = 100;

	// Head 영역 설정
	HeadSize = { 40,40 };

	// 활성화 상태 초기화
	IsEnable = true;

	InitializeHead();

}

void Head::Tick() {

	// 비활성화 체크
	CheckDisable();

	if (IsEnable) {
		// 스프라이트 인덱스를 증가
		if (GetTickCount() - SpriteDelayCheckTime >= SpriteDelay) {
			SpriteDelayCheckTime = GetTickCount();
			++SpriteIndex;
			SpriteIndex = (SpriteIndex > 3) ? 0 : SpriteIndex;
		}
		// 밑으로 떨어트려줍니다.
		Point currentPosition = GetObjectPosition();
		currentPosition.y += FallSpeed;
		SetObjectPosition(currentPosition);

		// 플레이어와의 거리 계산
		PlayerDistance =
			sqrt(pow((GetObjectPosition().x - PlayerInstance->GetObjectPosition().x), 2.0) +
				pow((GetObjectPosition().y - PlayerInstance->GetObjectPosition().y), 2.0));

		// 게임오버처리
		if (PlayerDistance <= 100.0f) {
			if (CheckOverlapPlayer()) {
				MessageBox(Hwnd, TEXT("GameOver"), TEXT("게임오버"), MB_OK);
				((SceneManager*)GameInst->GetManagerClass(ManagerClassType::MT_SceneManager))->
					SetNextScene("MainScene");
			}
		}

	}
	UpdateArea();
}

void Head::Render(HDC hdc) {
	if (IsEnable) {
		TransparentBlt(
			hdc,
			// 이미지 출력 좌표
			GetObjectArea().left, GetObjectArea().top,

			// 이미지 출력 사이즈
			GetObejctSize().x, GetObejctSize().y,
			HeadBitmap->GetMemDC(),
			// 자르기 시작할 XY좌표
			(SpriteIndex * 64), 0,

			// 얼마만큼의 크기로 잘라 표시할것인지
			64, 64,
			RGB(255, 0, 255));
	}
}

void Head::Release() {
	SafeRelease(HeadBitmap);
}

void Head::UpdateArea() {
	base::UpdateArea();

	HeadArea = {
		(int)(GetObjectPosition().x - (HeadSize.x / 2)),
		(int)(GetObjectPosition().y - (HeadSize.y / 2)),
		(int)(GetObjectPosition().x + (HeadSize.x / 2)),
		(int)(GetObjectPosition().y + (HeadSize.y / 2))
	};
}
