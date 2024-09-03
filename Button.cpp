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
		hdc,                                                         //ȭ�� ���� DC
		GetObjectPosition().x, GetObjectPosition().y,                // �̹��� ��� ������ǥ
		GetObejctSize().x, GetObejctSize().y,                        // �̹��� ���� ��� ũ��
		memDC,                                                       // �̹��� ������ ����� DC
		0,0,                                                         // �ڸ��� ������ ��ǥ
		GetObejctSize().x, GetObejctSize().y,                        // �󸶳� �߶� �������
		m_TransparentColor                                           // Ư�� ���� ����
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
	/*Ŭ�� Ȯ�� ���� 
	1) ��ư�� ���콺 �÷��� ����
	2) ��ư�� �����ٰ� ��
	   �� ��ư�� �������� ���� ����
	   �� ������ ��ư�� Ŭ���Ǿ����� ��
	   ��ư�� ���콺�� �÷��� ���� && ��ư�� �������� ���� ����

	
	*/
	if (_ButtonState == 1 && !_IsPressed && _IsClicked) {
		//Ŭ���� �����ϴ� üũ ������ �ʱ�ȭ
		_IsClicked = false;

		return true;
	}
	
		return false;
}

void Button::Tick()
{
	// ���콺�� ��ǥ�� �����ɴϴ�.
	POINT mousePoint = MouseUtill::GetWindowMousePosition();

	//PtInRect() : Rect�� Point�� �浹���� �˻�
	if (PtInRect(&GetObjectArea(), mousePoint)) {
		if (GetAsyncKeyState(VK_LBUTTON)) {
			if (_ButtonState != 2) _ButtonState = 2;
			if (!_IsPressed) _IsPressed = true;
			if (!_IsClicked) _IsClicked = true;

		}
		//Ŭ���� ���� �ʰ� ��ư���� ���콺�� �÷��� �ִٸ�
		else {
			if (_ButtonState != 1) _ButtonState = 1;
			if (_IsPressed) _IsPressed = false;
		}
	}
	//���콺�� ��ư ���� ������
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
			hdc,                                                         //ȭ�� ���� DC
			GetObjectPosition().x, GetObjectPosition().y,                // �̹��� ��� ������ǥ
			GetObejctSize().x, GetObejctSize().y,                        // �̹��� ���� ��� ũ��
			memDC,                                                       // �̹��� ������ ����� DC
			0, 0,                                                         // �ڸ��� ������ ��ǥ
			GetObejctSize().x, GetObejctSize().y,                        // �󸶳� �߶� �������
			m_TransparentColor                                           // Ư�� ���� ����
		);
		DeleteDC(memDC);
	}
	//���� ���� �Ӽ��� �����Ѵٸ�
	else {
		HDC memDC = CreateCompatibleDC(hdc);
		SelectObject(memDC, m_Image);
		//SetStretchBltMode 
		//�̹��� ��ҽ� ����Ǵ� �̹��� �ս� ����
		SetStretchBltMode(hdc,COLORONCOLOR);
		//COLORONCOLOR ��ҽ� ���� �ȼ��� �������� �ʰ� �ȼ� ������ ����
		StretchBlt(
			hdc,GetObjectPosition().x,GetObjectPosition().y,
			GetObejctSize().x, GetObejctSize().y,
			memDC,
			0,0,
			GetObejctSize().x, GetObejctSize().y, SRCCOPY);
		DeleteDC(memDC);
	}
}
