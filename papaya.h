#pragma once
#include "GameObject.h"
#include "Enemy.h"



class papaya : public GameObject
{

public:
	virtual void Initialize()		override;
	virtual void Tick()				override;
	virtual void Render(HDC hdc)	override;
	virtual void Release()			override;
	
	
	//파파야 나무 3개 위치를 랜덤으로 넣어줌
	
	void InitializePapaya();
	
	
	//적 인스턴스를 찾아줄 함수 ㅠㅠㅠㅠㅠㅠ

	void SetEnemyInstance(class Enemy * enemyInstance);
	

	//게임 오버 되면 나무를 disable로 바꾸고 다시 시작될 시 위치를 초기화 합니다
	bool IsEnable;
	

private:
	
	//충돌시 잠시동안 영역을 {0,0}으로 맞춰줄건데 그 시간을 체크할 변수
	float DisableCheckDelay;
	float DisableDelay;

	//충돌 여부 확인 불 타입
	bool IsDisable;

	// GetTickCount로 카운트 만들시 무조건 한 번은 바로 실행되는 문제를 방지하기 위한 변수
	int DONTDOIT;


	class Bitmap* PapayaImage;

	class Enemy* EnemyInstance;
	float EnemyDistance;
	Point PapayaSize;
	int   PapayaCount;


	RECT PapayaArea;

	RECT Dest;
	
	bool CheckOverlapEnemy();

protected:
	virtual void UpdateArea()		override;



};

