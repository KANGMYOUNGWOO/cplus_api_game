#pragma once
#include "GameObject.h"
class IceCream
	:
	public GameObject
{
public:
	// 활성화 변수
	bool IsEnable;

private:
	// 플레이어를 참조할 변수
	class Enemy* EnemyInstance;

	

	// 머리 이미지 가져올 변수
	Bitmap* IceCreamBitmap;

	// 머리의 크기
	Point IceCreamSize;

	// 머리의 영역
	RECT IceCreamArea;

	// 플레이어 여역과 겹친 영역을 저장할 RECT 변수
	RECT Dest;

	//떨어지는 속도	
	// 플레이어와의 거리를 저장할 변수
	float EnemyDistance;

private:
	// 화면 밖으로 나갔을 때를 체크하고
	// 만약 화면 밖으로 나갔다면 오브젝트를 비활성화 상태로 설정할 함수
	void CheckDisable();

	// 플레이어와 겹쳤는지 검사하는 함수
	bool CheckOverlapPlayer();

public:
	// Head 오브젝트를 초기화합니다.
	void InitializeIceCream();
	void SetEnemyInstance(class Enemy* enemyInstance);

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

protected:
	virtual void UpdateArea()		override;

};

