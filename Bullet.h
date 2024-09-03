#pragma once
#include "GameObject.h"


class Bullet : public GameObject
{

private:
	// �÷��̾ ������ ����
	class Player* PlayerInstance;


private:
	//�Ѿ� ��Ȱ���� ���� ����Ʈ
	std::list<class Bullet*> BulletList;

	//�Ѿ� ��Ȱ�� �Լ�
	class Bullet* FindDisableBullet();
	
	void InputKey();

	// �Ѿ� ����
	class Bullet* FireBullet();

	

public:
	// Ȱ��ȭ ����
	bool IsEnable;
	Bitmap* BulletBitmap;

	Point BulletSize;
	void SetPlayerInstance(class Player* playerInstance);
	
	

private:
	// ȭ�� ������ ������ ���� üũ�ϰ�
	// ���� ȭ�� ������ �����ٸ� ������Ʈ�� ��Ȱ��ȭ ���·� ������ �Լ�
	void CheckDisable();

	// ���� ���ƴ��� �˻��ϴ� �Լ�
	bool CheckOverlapEnemy();

	enum BulletDirection {LEFT,RIGHT,DOWN,UP};
     
	BulletDirection bul;
  

	 

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

protected:
	virtual void UpdateArea()		override;




};

