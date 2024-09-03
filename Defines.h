#pragma once

#include <windows.h>
#include <map>
#include <list>
#include <string>

#pragma comment (lib, "Msimg32.lib")


// 창 크기를 정의합니다.
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


//  > extern : 외부 변수
/// - 해당하는 이름의 변수를 전역에서 사용하겠다 라는 뜻
/// - 외부 변수는 선언시 정의 불가능하며, 다른 곳에 선언, 정의 후
///   사용할 수 있습니다.
extern HWND Hwnd;
extern class GameInstance * GameInst;


template<typename T>
FORCEINLINE void SafeRelease(T& instance) {
	if (instance != null) {
		delete instance;
		instance = null;
	}
}

//  > 문자열이 같은지 검사합니다.
FORCEINLINE bool StrEquals(LPCTSTR str1, LPCTSTR str2) {
	return !lstrcmp(str1, str2);
}

FORCEINLINE bool StrEquals(std::string str1, std::string str2) {
	return !str1.compare(str2);
}




