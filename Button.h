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
	//Ư�� ���� ���� 
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

		//��ư �̹��� ����
    void BMPRender(HDC hdc);
	
	//�ڸ��� ������ y ��ġ ��ȯ
	int StartcropY();


public:
	//��ư ���� Ȯ��
	int CheckState();
	//��ư�� Ŭ���Ǿ����� Ȯ�� 
	bool CheckClick();
	//BaseUpdate BaseRender
	
	virtual void Tick() override;
	virtual void Render(HDC hdc) override;

#pragma endregion

};

