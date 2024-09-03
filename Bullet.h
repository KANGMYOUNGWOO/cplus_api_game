#pragma once
#include "GameObject.h"


class Bullet : public GameObject
{

private:
	// 플레이어를 참조할 변수
	class Player* PlayerInstance;


private:
	//총알 재활용을 위한 리스트
	std::list<class Bullet*> BulletList;

	//총알 재활용 함수
	class Bullet* FindDisableBullet();
	
	void InputKey();

	// 총알 생성
	class Bullet* FireBullet();

	

public:
	// 활성화 변수
	bool IsEnable;
	Bitmap* BulletBitmap;

	Point BulletSize;
	void SetPlayerInstance(class Player* playerInstance);
	
	

private:
	// 화면 밖으로 나갔을 때를 체크하고
	// 만약 화면 밖으로 나갔다면 오브젝트를 비활성화 상태로 설정할 함수
	void CheckDisable();

	// 적과 겹쳤는지 검사하는 함수
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

