#include "Head.h"
#include "Player.h"
#include "DebugLog.h"
#include "math.h"
#include "SceneManager.h"
#include "GameInstance.h"


void Head::CheckDisable() {
	// ȭ�� ������ �������ٸ�
	if (GetObjectPosition().y > WND_HEIGHT + 50)
		IsEnable = false;
}

bool Head::CheckOverlapPlayer() {
	// �÷��̾�� ���ƴ��� �˻��մϴ�.
	// IntersectRect : RECT���� �浹�� �˻��մϴ�.
	return IntersectRect(&Dest, &HeadArea, PlayerInstance->GetPlayerArea());
}

void Head::InitializeHead() {
	// �ʱ� ��ǥ �����մϴ�
	Point InitializePosition(
		(rand() % WND_WIDTH), -50);

	// �������� ��
	//FallSpeed = ((rand() % 17) + 3)*0.1f;
	FallSpeed = 0;

	// ������ ��ǥ�� �̵���ŵ�ϴ�.
	SetObjectPosition(InitializePosition);

	UpdateArea();
}

void Head::SetPlayerInstance(Player * playerInstance) {
	PlayerInstance = playerInstance;
}

void Head::Initialize() {
	HeadBitmap = (new Bitmap())->LoadBmp(TEXT("Resource/Head/Head.bmp"));

	// ������Ʈ ũ��(���)
	SetObejctSize(Point(64, 64));

	// ������Ʈ �ʱ� ��ǥ ����
	SetObjectPosition(Point(400, 50));

	SpriteIndex = SpriteDelayCheckTime = 0;
	SpriteDelay = 100;

	// Head ���� ����
	HeadSize = { 40,40 };

	// Ȱ��ȭ ���� �ʱ�ȭ
	IsEnable = true;

	InitializeHead();

}

void Head::Tick() {

	// ��Ȱ��ȭ üũ
	CheckDisable();

	if (IsEnable) {
		// ��������Ʈ �ε����� ����
		if (GetTickCount() - SpriteDelayCheckTime >= SpriteDelay) {
			SpriteDelayCheckTime = GetTickCount();
			++SpriteIndex;
			SpriteIndex = (SpriteIndex > 3) ? 0 : SpriteIndex;
		}
		// ������ ����Ʈ���ݴϴ�.
		Point currentPosition = GetObjectPosition();
		currentPosition.y += FallSpeed;
		SetObjectPosition(currentPosition);

		// �÷��̾���� �Ÿ� ���
		PlayerDistance =
			sqrt(pow((GetObjectPosition().x - PlayerInstance->GetObjectPosition().x), 2.0) +
				pow((GetObjectPosition().y - PlayerInstance->GetObjectPosition().y), 2.0));

		// ���ӿ���ó��
		if (PlayerDistance <= 100.0f) {
			if (CheckOverlapPlayer()) {
				MessageBox(Hwnd, TEXT("GameOver"), TEXT("���ӿ���"), MB_OK);
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
			// �̹��� ��� ��ǥ
			GetObjectArea().left, GetObjectArea().top,

			// �̹��� ��� ������
			GetObejctSize().x, GetObejctSize().y,
			HeadBitmap->GetMemDC(),
			// �ڸ��� ������ XY��ǥ
			(SpriteIndex * 64), 0,

			// �󸶸�ŭ�� ũ��� �߶� ǥ���Ұ�����
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
