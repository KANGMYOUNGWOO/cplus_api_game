#pragma once
#include "GameObject.h"


class Player :
	public GameObject
{
public:
	// �÷��̾� ����
	enum PlayerDirection{LEFT, RIGHT,DOWN,UP};

	// �÷��̾� ����
	enum PlayerState{IDLE, MOVE };
	PlayerDirection Direction;




protected:
	virtual void UpdateArea() override;

public :
	// �浹������ ������ ������ ����
	RECT * GetPlayerArea();
	

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

private:
	// �ִϸ��̼ǰ� ���õ� �����͸� �ʱ�ȭ�մϴ�.
	void InitializeSpriteAnimData();

	// Ű �Է��� ó���մϴ�.
	void InputKey();

	

private:
	// ��� �̹���(IDLE)
	class Bitmap* PlayerLeft;
	class Bitmap* PlayerRight;
	class Bitmap* SalvaDor;

	// �÷��̾� ���� ����
	

	// �÷��̾� ����
	PlayerState State;

	// �̵��ӵ�
	float MoveSpeed;

	// �÷��̾� �浹 ���� ���� ����
	Point PlayerSize;

	// �÷��̾�� Head Object�� �浹�ߴ��� �˻��� �� ����� RECT
	RECT PlayerArea;

#pragma region Sprite Variable
	// ��������Ʈ �ε���
	int SpriteIndex;
	int SpriteIndexForS;

	// ��������Ʈ ������
	int SpriteDelay;

	// ��������Ʈ ������ üũŸ��
	int SpriteDelayCheckTime;

	// ������ ���� ���� ������
	const int FRAME_IMAGE_SIZE = 30;

};

