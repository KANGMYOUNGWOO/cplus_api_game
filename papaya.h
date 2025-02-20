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
	
	
	//督督醤 蟹巷 3鯵 是帖研 沓棋生稽 隔嬢捜
	
	void InitializePapaya();
	
	
	//旋 昔什渡什研 達焼匝 敗呪 ばばばばばば

	void SetEnemyInstance(class Enemy * enemyInstance);
	

	//惟績 神獄 鞠檎 蟹巷研 disable稽 郊荷壱 陥獣 獣拙吃 獣 是帖研 段奄鉢 杯艦陥
	bool IsEnable;
	

private:
	
	//中宜獣 節獣疑照 慎蝕聖 {0,0}生稽 限仲匝闇汽 益 獣娃聖 端滴拝 痕呪
	float DisableCheckDelay;
	float DisableDelay;

	//中宜 食採 溌昔 災 展脊
	bool IsDisable;

	// GetTickCount稽 朝錘闘 幻級獣 巷繕闇 廃 腰精 郊稽 叔楳鞠澗 庚薦研 号走馬奄 是廃 痕呪
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

