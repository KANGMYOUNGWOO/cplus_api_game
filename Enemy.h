#pragma once
#include "GameObject.h"
#include "Player.h"
class Enemy	 : public GameObject
	{
#pragma region Variable
	public:
		// Ȱ��ȭ ����
		bool IsEnable;
		RECT* GetEnemyArea();

	private:
		// �÷��̾ ������ ����
		class Player* PlayerInstance;

		//���ľ߸� ���� ���� ����
		class papaya* PapayaInstance;


		Point PlayerPosition;
		enum EnemyState{MOVE,ATTACK,STUN};
		EnemyState CurEnemyState;

		// �Ӹ� �̹��� ������ ����
		Bitmap* EnemyBitmap;
		Bitmap* EnemyAttack;
		Bitmap* EnemyStun;
		

		// �Ӹ��� ũ��
		Point EnemySize;

		// �Ӹ��� ����
		RECT EnemyArea;

		//���� : int�� �Լ����� �����
		UINT Score;
		
		char * StringScore;
		

		// �÷��̾� ������ ��ģ ������ ������ RECT ����
		RECT Dest;

		//�����̴� �ӵ�
		float MoveSpeed;

		int SpriteDelay;
		int SpriteDelayCheckTime;
		int SpriteIndex;
		

		// �÷��̾���� �Ÿ��� ������ ����
		float PlayerDistance;

		//�� ���� �ʱⰪ true�� �ְ� ������ ������ false ���� ��ȯ�ϰ� 3���ִٰ� �ٽ� true�� ���ƿ� 
		bool CanShock;

		// ���� �ð��� �������� ����
		float ShockeDelay;
		float ShockDelayCheckTime;
#pragma endregion 
	private:
		
		// ���� �뽬�� �� �� �Լ�(�� �� ����) 
		void EnemyDash();
		


		// �÷��̾�� ���ƴ��� �˻��ϴ� �Լ�
		bool CheckOverlapPlayer();

		
		
		

	public:
		// Enemy ������Ʈ�� �ʱ�ȭ�մϴ�.
		void InitializeEnemy();
		void FindPlayer();
		void SetPlayerInstance(class Player* playerInstance);
		void SetPapayaInstance(class papaya* papayaInstance);
		void ChangeState();
		//�ϵ� �־���� �� ���� ������ ��������
		void SpeedUp();
		//���� Ż��
		void ExitStun();
		//������ ������ �ӵ� �ʱ�ȭ
		void ResetSpeed();

	public:
		virtual void Initialize()		override;
		virtual void Tick()				override;
		virtual void Render(HDC hdc)	override;
		virtual void Release()			override;

	protected:
		virtual void UpdateArea()		override;

	};



