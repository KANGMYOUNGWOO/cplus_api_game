#include "GameInstance.h"

HWND Hwnd;
GameInstance * GameInst;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Msg;
	WNDCLASS WndClass;

#pragma region 1_ 윈도우 클래스 초기화
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.cbClsExtra = WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = TEXT("WndClass");
	WndClass.lpszMenuName = NULL;
#pragma endregion


#pragma region 2_ 윈도우 클래스 등록
	RegisterClass(&WndClass);
#pragma endregion


#pragma region 3_ 윈도우 창 생성

	hWnd = CreateWindow(
		WndClass.lpszClassName,
		TEXT("Window Title"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WND_WIDTH, WND_HEIGHT, // 윈도우 크기
		NULL,
		NULL,
		hInstance,
		NULL);
#pragma endregion


#pragma region 4_ 윈도우 창 출력 (ShowWindow())
	ShowWindow(hWnd, nCmdShow);
#pragma endregion


#pragma region 5_ 메시지 루프 처리(CallBack Window Procedure)


	Msg.message = WM_NULL;

	GameInstance gameInst;
	GameInst = &gameInst;

	GameInst->Initialize();

	while (Msg.message != WM_QUIT) {

		// 처리할 메시지가 있다면
		//  > PeekMessage()
		/// - wRemoveMsg : 조사한 메시지를 처리할 방식을 지정합니다.
		/// - PM_NOREMOVE       메시지를 읽은 후 큐에서 메시지를 제거하지 않습니다.
		/// - PM_REMOVE         메시지를 읽은 후 큐에서 메시지를 제거합니다.
		/// - PM_NOYIELD        다른 쓰레드로 제어를 양보하지 않습니다.
		/// - PM_QS_INPUT       마우스나 키보드 등의 입력 메시지만 처리합니다.
		/// - PM_QS_PAINT       그리기 메시지만 처리합니다.
		/// - PM_QS_POSTMESSAGE 타이머 메시지만 처리합니다.
		/// - PM_QS_SENDMESSAGE 보내어지는 메시지만 처리합니다.
		if (PeekMessage(&Msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}

		//  > 처리할 메시지가 없다면
		else {
			GameInst->Tick();
			GameInst->Render();
		}
	}

#pragma endregion

	return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {

	case WM_CREATE :
		Hwnd = hwnd;
		srand(GetTickCount());
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}