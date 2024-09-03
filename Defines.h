#pragma once

#include <windows.h>
#include <map>
#include <list>
#include <string>

#pragma comment (lib, "Msimg32.lib")


// â ũ�⸦ �����մϴ�.
#define WND_WIDTH	800
#define WND_HEIGHT	640

#ifndef null
#define null nullptr
#endif

#ifndef PURE
#define PURE =0
#endif

#ifndef FORCEINLINE
#define FORCEINLINE __forceinline
#endif


//  > extern : �ܺ� ����
/// - �ش��ϴ� �̸��� ������ �������� ����ϰڴ� ��� ��
/// - �ܺ� ������ ����� ���� �Ұ����ϸ�, �ٸ� ���� ����, ���� ��
///   ����� �� �ֽ��ϴ�.
extern HWND Hwnd;
extern class GameInstance * GameInst;


template<typename T>
FORCEINLINE void SafeRelease(T& instance) {
	if (instance != null) {
		delete instance;
		instance = null;
	}
}

//  > ���ڿ��� ������ �˻��մϴ�.
FORCEINLINE bool StrEquals(LPCTSTR str1, LPCTSTR str2) {
	return !lstrcmp(str1, str2);
}

FORCEINLINE bool StrEquals(std::string str1, std::string str2) {
	return !str1.compare(str2);
}




