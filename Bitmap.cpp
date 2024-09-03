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
	//  > LoadImage : 파일 형태의 이미지를 읽을 수 있습니다.
	/// - hinst	   : 이미지 리소스를 가진 모듈의 핸들, 파일에서 일을 때 NULL 을 사용합니다.
	/// - lpszName : 읽을 이미지를 지정합니다.
	/// - uType	   : 읽고자 하는 타입을 지정합니다.
	/// - cx, cy   : 아이콘이나 커서의 너비와 높이
	///              값이 0이며, fuLoad 에서 LR_DEFAULTSIZE 플레그가 지정되어있지 않은 경우
	///              원본 크기로 로드합니다.
	/// - fuLoad   : 이미지를 읽어올 방법을 지정하는 플래그입니다.
	///   - LR_DEFAULTCOLOR : 디폴트 플레그, 흑백으로 읽지 않도록 합니다.
	///   - LR_DEFAULTSIZE	: cx, cy 가 0일 경우 디폴트 크기대로 이미지를 읽어옵니다.
	///   - LR_LOADFROMFILE	: lpszName 인수를 리소스 이름 대신에, 파일명으로 인식하여 리소스를 읽습니다.
	///   - LR_MONOCHROME  	: 이미지를 흑백으로 읽습니다.


	if (Bmp == null) {
		TCHAR message[256];
		wsprintf(message, TEXT("파일을 로드하지 못했습니다.\n경로 : %s"), path);
		MessageBox(Hwnd, message, TEXT("Bmp Load Failed"), MB_OK);
	}

	OldBmp = (HBITMAP)SelectObject(MemDC, Bmp);

	//  > HDC 해제
	ReleaseDC(Hwnd, Hdc);

	return this;
}

void Bitmap::Release() {

	//  > Bmp 를 돌려받고 해제합니다.
	DeleteObject(SelectObject(MemDC, OldBmp));

	//  MemDC 삭제
	DeleteDC(MemDC);
}
