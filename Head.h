#pragma once
#include "GameObject.h"
class Head :
	public GameObject
{
	public:
		// Ȱ��ȭ ����
		bool IsEnable;

private: 
	// �÷��̾ ������ ����
	class Player * PlayerInstance;

	// �Ӹ� �̹��� ������ ����
	Bitmap * HeadBitmap;

	// �Ӹ��� ũ��
	Point HeadSize;

	// �Ӹ��� ����
	RECT HeadArea;

	// �÷��̾� ������ ��ģ ������ ������ RECT ����
	RECT Dest;
	
	//�������� �ӵ�
	float FallSpeed;

	int SpriteDelay;
	int SpriteDelayCheckTime;
	int SpriteIndex;

	// �÷��̾���� �Ÿ��� ������ ����
	float PlayerDistance;

private:
	// ȭ�� ������ ������ ���� üũ�ϰ�
	// ���� ȭ�� ������ �����ٸ� ������Ʈ�� ��Ȱ��ȭ ���·� ������ �Լ�
	void CheckDisable();

	// �÷��̾�� ���ƴ��� �˻��ϴ� �Լ�
	bool CheckOverlapPlayer();

public:
	// Head ������Ʈ�� �ʱ�ȭ�մϴ�.
	void InitializeHead();
	void SetPlayerInstance(class Player * playerInstance);

public :
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

protected:
	virtual void UpdateArea()		override;

};

