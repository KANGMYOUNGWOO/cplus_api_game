#include "GameInstance.h"

HWND Hwnd;
GameInstance * GameInst;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow) {
	HWND hWnd;
	MSG Msg;
	WNDCLASS WndClass;

#pragma region 1_ ������ Ŭ���� �ʱ�ȭ
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


#pragma region 2_ ������ Ŭ���� ���
	RegisterClass(&WndClass);
#pragma endregion


#pragma region 3_ ������ â ����

	hWnd = CreateWindow(
		WndClass.lpszClassName,
		TEXT("Window Title"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WND_WIDTH, WND_HEIGHT, // ������ ũ��
		NULL,
		NULL,
		hInstance,
		NULL);
#pragma endregion


#pragma region 4_ ������ â ��� (ShowWindow())
	ShowWindow(hWnd, nCmdShow);
#pragma endregion


#pragma region 5_ �޽��� ���� ó��(CallBack Window Procedure)


	Msg.message = WM_NULL;

	GameInstance gameInst;
	GameInst = &gameInst;

	GameInst->Initialize();

	while (Msg.message != WM_QUIT) {

		// ó���� �޽����� �ִٸ�
		//  > PeekMessage()
		/// - wRemoveMsg : ������ �޽����� ó���� ����� �����մϴ�.
		/// - PM_NOREMOVE       �޽����� ���� �� ť���� �޽����� �������� �ʽ��ϴ�.
		/// - PM_REMOVE         �޽����� ���� �� ť���� �޽����� �����մϴ�.
		/// - PM_NOYIELD        �ٸ� ������� ��� �纸���� �ʽ��ϴ�.
		/// - PM_QS_INPUT       ���콺�� Ű���� ���� �Է� �޽����� ó���մϴ�.
		/// - PM_QS_PAINT       �׸��� �޽����� ó���մϴ�.
		/// - PM_QS_POSTMESSAGE Ÿ�̸� �޽����� ó���մϴ�.
		/// - PM_QS_SENDMESSAGE ���������� �޽����� ó���մϴ�.
		if (PeekMessage(&Msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}

		//  > ó���� �޽����� ���ٸ�
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