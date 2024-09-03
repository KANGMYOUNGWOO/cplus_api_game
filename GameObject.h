#pragma once
#include "Defines.h"
#include "Bitmap.h"

#ifndef base
#define base GameObject
#endif
//  > GameObject 클래스를 상속시켜 사용합니다.
/// - 파생클래스에서 Initialize(), Tick(), Render(HDC hdc), Release() 를 구현합니다.

class GameObject abstract {
public:
	GameObject();
	virtual ~GameObject();

	// 캐릭터 영역에서 가로 세로 길이
	struct Point {
		float x; float y;
		Point(){}
		Point(float x, float y) 
		{ this->x = x; this->y = y;}

		void AddPoint(Point point) {
			this->x += point.x;
			this->y += point.y;
		}
	};

private :
	//  > 오브젝트 영역
	RECT ObjectArea;

	//  > 오브젝트 가로 세로 크기
	float Width, Height;

	//  > 오브젝트 좌표
	float PosX, PosY;

protected :
	//  > 오브젝트 영역을 업데이트 시킵니다.
	/// - 좌표나, 크기를 변경했을 때 영역과 동기화 되도록 합니다.
	virtual void UpdateArea();

public :
	//  > 오브젝트 좌표, 크기 초기화 메서드
	void InitializeData(int x, int y, int w, int h);

	virtual void Initialize()		PURE;
	virtual void Tick()				PURE;
	virtual void Render(HDC hdc)	PURE;
	virtual void Release()			PURE;
	void SetCropSize(int w, int h);

	//  > 오브젝트 영역을 리턴합니다.
	FORCEINLINE RECT GetObjectArea() 
	{ return ObjectArea; }

	//  > 오브젝트 좌표를 설정합니다.
	FORCEINLINE void SetObjectPosition(Point xy) 
	{ PosX = xy.x; PosY = xy.y; }

	//  > 오브젝트 좌표를 리턴합니다.
	FORCEINLINE Point GetObjectPosition()
	{
		Point position = { PosX , PosY };
		return position;
	}

	//  > 오브젝트 크기를 설정합니다.
	FORCEINLINE void SetObejctSize(Point wh) {
		Width = wh.x;
		Height = wh.y;
	}

	//  > 오브젝트 크기를 가져옵니다.
	FORCEINLINE Point GetObejctSize() {
		Point size = { Width , Height };
		return size;
	}
};

