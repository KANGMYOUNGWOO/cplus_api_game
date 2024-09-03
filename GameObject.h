#pragma once
#include "Defines.h"
#include "Bitmap.h"

#ifndef base
#define base GameObject
#endif
//  > GameObject Ŭ������ ��ӽ��� ����մϴ�.
/// - �Ļ�Ŭ�������� Initialize(), Tick(), Render(HDC hdc), Release() �� �����մϴ�.

class GameObject abstract {
public:
	GameObject();
	virtual ~GameObject();

	// ĳ���� �������� ���� ���� ����
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
	//  > ������Ʈ ����
	RECT ObjectArea;

	//  > ������Ʈ ���� ���� ũ��
	float Width, Height;

	//  > ������Ʈ ��ǥ
	float PosX, PosY;

protected :
	//  > ������Ʈ ������ ������Ʈ ��ŵ�ϴ�.
	/// - ��ǥ��, ũ�⸦ �������� �� ������ ����ȭ �ǵ��� �մϴ�.
	virtual void UpdateArea();

public :
	//  > ������Ʈ ��ǥ, ũ�� �ʱ�ȭ �޼���
	void InitializeData(int x, int y, int w, int h);

	virtual void Initialize()		PURE;
	virtual void Tick()				PURE;
	virtual void Render(HDC hdc)	PURE;
	virtual void Release()			PURE;
	void SetCropSize(int w, int h);

	//  > ������Ʈ ������ �����մϴ�.
	FORCEINLINE RECT GetObjectArea() 
	{ return ObjectArea; }

	//  > ������Ʈ ��ǥ�� �����մϴ�.
	FORCEINLINE void SetObjectPosition(Point xy) 
	{ PosX = xy.x; PosY = xy.y; }

	//  > ������Ʈ ��ǥ�� �����մϴ�.
	FORCEINLINE Point GetObjectPosition()
	{
		Point position = { PosX , PosY };
		return position;
	}

	//  > ������Ʈ ũ�⸦ �����մϴ�.
	FORCEINLINE void SetObejctSize(Point wh) {
		Width = wh.x;
		Height = wh.y;
	}

	//  > ������Ʈ ũ�⸦ �����ɴϴ�.
	FORCEINLINE Point GetObejctSize() {
		Point size = { Width , Height };
		return size;
	}
};

