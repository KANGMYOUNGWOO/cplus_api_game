#pragma once
#include "GameObject.h"


class Player :
	public GameObject
{
public:
	// 플레이어 방향
	enum PlayerDirection{LEFT, RIGHT,DOWN,UP};

	// 플레이어 상태
	enum PlayerState{IDLE, MOVE };
	PlayerDirection Direction;




protected:
	virtual void UpdateArea() override;

public :
	// 충돌영역을 가져올 포인터 변수
	RECT * GetPlayerArea();
	

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;

private:
	// 애니메이션과 관련된 데이터를 초기화합니다.
	void InitializeSpriteAnimData();

	// 키 입력을 처리합니다.
	void InputKey();

	

private:
	// 대기 이미지(IDLE)
	class Bitmap* PlayerLeft;
	class Bitmap* PlayerRight;
	class Bitmap* SalvaDor;

	// 플레이어 방향 변수
	

	// 플레이어 상태
	PlayerState State;

	// 이동속도
	float MoveSpeed;

	// 플레이어 충돌 영역 가로 세로
	Point PlayerSize;

	// 플레이어와 Head Object가 충돌했는지 검사할 때 사용할 RECT
	RECT PlayerArea;

#pragma region Sprite Variable
	// 스프라이트 인덱스
	int SpriteIndex;
	int SpriteIndexForS;

	// 스프라이트 딜레이
	int SpriteDelay;

	// 스프라이트 딜레이 체크타임
	int SpriteDelayCheckTime;

	// 프레임 가로 세로 사이즈
	const int FRAME_IMAGE_SIZE = 30;

};

