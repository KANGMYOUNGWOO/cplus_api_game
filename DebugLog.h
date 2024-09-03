#pragma once
#include <iostream>
using namespace std;

// �α�â�� ��� ������ �����մϴ�.
#define USE_LOG_WINDOW true

// �α�â�� ���ٸ�
#if USE_LOG_WINDOW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

// Ŭ���� �ܺο����� ����� �� �ִ� �α� ��� ��ũ�� �Լ�
#define Log(log) \
if (USE_LOG_WINDOW)\
cout << "[" << "LINE: " << __LINE__ << "] " << log << endl;

// Ŭ���� ���ο����� ����� �� �ִ� �α� ��� ��ũ�� �Լ�
#define LogDt(log) \
if(USE_LOG_WINDOW)  \
cout<< "[" << typeid(this).name() << " :: LINE :: " << __LINE__ << "]" << log << endl;