#include "Button.h"
#include "MouseUtill.h"
#include "GameObject.h"


Button::Button()
{
}


Button::~Button()
{
}

void Button::BMPRender(HDC hdc)
{
	HDC memDC = CreateCompatibleDC(hdc);
	SelectObject(memDC, m_Image);
	TransparentBlt(
		hdc,                                                         //화면 제어 DC
		GetObjectPosition().x, GetObjectPosition().y,                // 이미지 출력 시작좌표
		GetObejctSize().x, GetObejctSize().y,                        // 이미지 최종 출력 크기
		memDC,                                                       // 이미지 데이터 저장용 DC
		0,0,                                                         // 자르기 시작할 좌표
		GetObejctSize().x, GetObejctSize().y,                        // 얼마나 잘라서 사용할지
		m_TransparentColor                                           // 특정 색상 제외
		);



}

int Button::StartcropY()
{
	return 0;
}

int Button::CheckState()
{
	return _ButtonState;
}

bool Button::CheckClick()
{
	/*클릭 확인 조건 
	1) 버튼에 마우스 올려진 상태
	2) 바튼을 눌렀다가 뗌
	   ㄴ 버튼이 눌려있지 않은 상태
	   ㄴ 이전에 버튼이 클릭되어있을 때
	   버튼에 마우스가 올려진 상태 && 버튼이 눌려있지 않은 상태

	
	*/
	if (_ButtonState == 1 && !_IsPressed && _IsClicked) {
		//클릭을 관리하는 체크 변수를 초기화
		_IsClicked = false;

		return true;
	}
	
		return false;
}

void Button::Tick()
{
	// 마우스의 좌표를 가져옵니다.
	POINT mousePoint = MouseUtill::GetWindowMousePosition();

	//PtInRect() : Rect와 Point의 충돌여부 검사
	if (PtInRect(&GetObjectArea(), mousePoint)) {
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (_ButtonState != 2) _ButtonState = 2;
			if (!_IsPressed) _IsPressed = true;
			if (!_IsClicked) _IsClicked = true;

		}
		//클릭이 되지 않고 버튼위에 마우스가 올려져 있다면
		else {
			if (_ButtonState != 1) _ButtonState = 1;
			if (_IsPressed) _IsPressed = false;
		}
	}
	//마우스가 버튼 위에 업스면
	else {
		if (_ButtonState != 0) _ButtonState = 0;
		
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (_IsClicked) _IsClicked = false;

		}
	}
}

void Button::Render(HDC hdc)
{
	BMPRender(hdc);
	if (m_UseTransParent) {
		HDC memDC = CreateCompatibleDC(hdc);
		SelectObject(memDC, m_Image);

		TransparentBlt(
			hdc,                                                         //화면 제어 DC
			GetObjectPosition().x, GetObjectPosition().y,                // 이미지 출력 시작좌표
			GetObejctSize().x, GetObejctSize().y,                        // 이미지 최종 출력 크기
			memDC,                                                       // 이미지 데이터 저장용 DC
			0, 0,                                                         // 자르기 시작할 좌표
			GetObejctSize().x, GetObejctSize().y,                        // 얼마나 잘라서 사용할지
			m_TransparentColor                                           // 특정 색상 제외
		);
		DeleteDC(memDC);
	}
	//색상 숨김 속성을 사용안한다면
	else {
		HDC memDC = CreateCompatibleDC(hdc);
		SelectObject(memDC, m_Image);
		//SetStretchBltMode 
		//이미지 축소시 방생되는 이미지 손실 보정
		SetStretchBltMode(hdc,COLORONCOLOR);
		//COLORONCOLOR 축소시 남은 픽셀을 보전하지 않고 픽셀 라인을 제거
		StretchBlt(
			hdc,GetObjectPosition().x,GetObjectPosition().y,
			GetObejctSize().x, GetObejctSize().y,
			memDC,
			0,0,
			GetObejctSize().x, GetObejctSize().y, SRCCOPY);
		DeleteDC(memDC);
	}
}
