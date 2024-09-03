#include "Bitmap.h"



Bitmap::Bitmap() {

}


Bitmap::~Bitmap() {
	Release();
}

HDC Bitmap::GetMemDC() {
	return MemDC;
}

Bitmap * Bitmap::LoadBmp(LPCTSTR path) {

	Hdc = GetDC(Hwnd);
	MemDC = CreateCompatibleDC(Hdc);


	Bmp = (HBITMAP)LoadImage(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	//  > LoadImage : ���� ������ �̹����� ���� �� �ֽ��ϴ�.
	/// - hinst	   : �̹��� ���ҽ��� ���� ����� �ڵ�, ���Ͽ��� ���� �� NULL �� ����մϴ�.
	/// - lpszName : ���� �̹����� �����մϴ�.
	/// - uType	   : �а��� �ϴ� Ÿ���� �����մϴ�.
	/// - cx, cy   : �������̳� Ŀ���� �ʺ�� ����
	///              ���� 0�̸�, fuLoad ���� LR_DEFAULTSIZE �÷��װ� �����Ǿ����� ���� ���
	///              ���� ũ��� �ε��մϴ�.
	/// - fuLoad   : �̹����� �о�� ����� �����ϴ� �÷����Դϴ�.
	///   - LR_DEFAULTCOLOR : ����Ʈ �÷���, ������� ���� �ʵ��� �մϴ�.
	///   - LR_DEFAULTSIZE	: cx, cy �� 0�� ��� ����Ʈ ũ���� �̹����� �о�ɴϴ�.
	///   - LR_LOADFROMFILE	: lpszName �μ��� ���ҽ� �̸� ��ſ�, ���ϸ����� �ν��Ͽ� ���ҽ��� �н��ϴ�.
	///   - LR_MONOCHROME  	: �̹����� ������� �н��ϴ�.


	if (Bmp == null) {
		TCHAR message[256];
		wsprintf(message, TEXT("������ �ε����� ���߽��ϴ�.\n��� : %s"), path);
		MessageBox(Hwnd, message, TEXT("Bmp Load Failed"), MB_OK);
	}

	OldBmp = (HBITMAP)SelectObject(MemDC, Bmp);

	//  > HDC ����
	ReleaseDC(Hwnd, Hdc);

	return this;
}

void Bitmap::Release() {

	//  > Bmp �� �����ް� �����մϴ�.
	DeleteObject(SelectObject(MemDC, OldBmp));

	//  MemDC ����
	DeleteDC(MemDC);
}
