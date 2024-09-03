#pragma once
#include "Defines.h"


class Bitmap final {
public:
	Bitmap();
	~Bitmap();

private :
	HDC Hdc, MemDC;
	HBITMAP Bmp, OldBmp;

public :
	HDC GetMemDC();
	Bitmap * LoadBmp(LPCTSTR path);
	void Release();
};

