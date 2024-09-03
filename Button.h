#pragma once
#include "GameObject.h"


class Button abstract  : public GameObject
{
public:
	Button();
	virtual ~Button();

#pragma region Variable


public :

	HBITMAP  m_Image;
	BITMAP   m_InageInfo;
	UINT m_TransparentColor = RGB(0, 0, 0);
	//특정 색상 제외 
	bool m_UseTransParent = false;

private :
	int  _ButtonState = 0;
	bool _IsPressed   = false;
	bool _IsClicked   = false;

public :

	bool m_Hover = false;


#pragma endregion


#pragma region Method

	private:

		//버튼 이미지 랜더
    void BMPRender(HDC hdc);
	
	//자르기 시작할 y 위치 반환
	int StartcropY();


public:
	//버튼 상태 확인
	int CheckState();
	//버튼이 클릭되었는지 확인 
	bool CheckClick();
	//BaseUpdate BaseRender
	
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

#pragma endregion

};

