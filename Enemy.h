#pragma once
#include "GameObject.h"
#include "Player.h"
class Enemy	 : public GameObject
	{
#pragma region Variable
	public:
		// 활성화 변수
		bool IsEnable;
		RECT* GetEnemyArea();

	private:
		// 플레이어를 참조할 변수
		class Player* PlayerInstance;

		//파파야를 집어 넣을 변수
		class papaya* PapayaInstance;


		Point PlayerPosition;
		enum EnemyState{MOVE,ATTACK,STUN};
		EnemyState CurEnemyState;

		// 머리 이미지 가져올 변수
		Bitmap* EnemyBitmap;
		Bitmap* EnemyAttack;
		Bitmap* EnemyStun;
		

		// 머리의 크기
		Point EnemySize;

		// 머리의 영역
		RECT EnemyArea;

		//점수 : int형 함수에서 상승함
		UINT Score;
		
		char * StringScore;
		

		// 플레이어 여역과 겹친 영역을 저장할 RECT 변수
		RECT Dest;

		//움직이는 속도
		float MoveSpeed;

		int SpriteDelay;
		int SpriteDelayCheckTime;
		int SpriteIndex;
		

		// 플레이어와의 거리를 저장할 변수
		float PlayerDistance;

		//그 뭐냐 초기값 true로 주고 나무에 박으면 false 값을 반환하고 3초있다가 다시 true로 돌아옴 
		bool CanShock;

		// 스턴 시간을 관리해줄 변수
		float ShockeDelay;
		float ShockDelayCheckTime;
#pragma endregion 
	private:
		
		// 적이 대쉬할 때 쓸 함수(안 쓸 거임) 
		void EnemyDash();
		


		// 플레이어와 겹쳤는지 검사하는 함수
		bool CheckOverlapPlayer();

		
		
		

	public:
		// Enemy 오브젝트를 초기화합니다.
		void InitializeEnemy();
		void FindPlayer();
		void SetPlayerInstance(class Player* playerInstance);
		void SetPapayaInstance(class papaya* papayaInstance);
		void ChangeState();
		//하드 주어먹을 때 마다 빨라짐 ㅎㅎㅎㅎ
		void SpeedUp();
		//기절 탈출
		void ExitStun();
		//나무에 박으면 속도 초기화
		void ResetSpeed();

	public:
		virtual void Initialize()		override;
		virtual void Tick()				override;
		virtual void Render(HDC hdc)	override;
		virtual void Release()			override;

	protected:
		virtual void UpdateArea()		override;

	};



