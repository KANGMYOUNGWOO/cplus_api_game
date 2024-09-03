#pragma once
#include <iostream>
using namespace std;

// 로그창을 띄울 것인지 설정합니다.
#define USE_LOG_WINDOW true

// 로그창을 띄운다면
#if USE_LOG_WINDOW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// 클래스 외부에서도 사용할 수 있는 로그 출력 매크로 함수
#define Log(log) \
if (USE_LOG_WINDOW)\
cout << "[" << "LINE: " << __LINE__ << "] " << log << endl;

// 클래스 내부에서도 사용할 수 있는 로그 출력 매크로 함수
#define LogDt(log) \
if(USE_LOG_WINDOW)  \
cout<< "[" << typeid(this).name() << " :: LINE :: " << __LINE__ << "]" << log << endl;