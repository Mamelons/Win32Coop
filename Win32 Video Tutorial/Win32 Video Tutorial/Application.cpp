#include <Windows.h>
#include "resource.h"

#define BTN1 1
#define BTN2 2
#define BTN3 3
#define BTN4 4
#define BTN5 5
#define BTN6 6
#define BTN7 7
#define BTN8 8
#define BTN9 9
#define BTN0 0



const char szClassName[] = "Window Class 1";

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void addControls(HWND);

HWND field;

HWND btn1;
HWND btn2;
HWND btn3;
HWND btn4;
HWND btn5;
HWND btn6;
HWND btn7;
HWND btn8;
HWND btn9;
HWND btn0;

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hWnd;
	MSG msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(30, 30, 30)));
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "RegisterClass failed!", "ERROR!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, szClassName, "hWnd Top Level", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 300, 300, NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
	{
		MessageBox(NULL, "CreateWindowEX failed!", "ERROR!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		addControls(hWnd);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILE_EXIT:
			PostMessage(hWnd, WM_CLOSE, 0, 0);
			break;
		case ID_HELP_ABOUT:
			break;
		case 1:
			MessageBox(hWnd, "1", "1", MB_OK);
			break;
		case 2:
			MessageBox(hWnd, "2", "2", MB_OK);
			break;
		case 3:
			MessageBox(hWnd, "3", "3", MB_OK);
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

void addControls(HWND hWnd) // next, try to add this in a for loop to get real crazy!!!
{
	field = CreateWindow("static", "", WS_VISIBLE | WS_CHILD, 130, 50, 100, 20, hWnd, NULL, NULL, NULL);

	btn1 = CreateWindow("button", "1", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 50, 20, 20, hWnd, (HMENU)BTN1, NULL, NULL);
	btn2 = CreateWindow("button", "2", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 35, 50, 20, 20, hWnd, (HMENU)BTN2, NULL, NULL);
	btn3 = CreateWindow("button", "3", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 60, 50, 20, 20, hWnd, (HMENU)BTN3, NULL, NULL);

	btn4 = CreateWindow("button", "4", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 75, 20, 20, hWnd, (HMENU)BTN4, NULL, NULL);
	btn5 = CreateWindow("button", "5", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 35, 75, 20, 20, hWnd, (HMENU)BTN5, NULL, NULL);
	btn6 = CreateWindow("button", "6", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 60, 75, 20, 20, hWnd, (HMENU)BTN6, NULL, NULL);

	btn7 = CreateWindow("button", "7", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 100, 20, 20, hWnd, (HMENU)BTN7, NULL, NULL);
	btn8 = CreateWindow("button", "8", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 35, 100, 20, 20, hWnd, (HMENU)BTN8, NULL, NULL);
	btn9 = CreateWindow("button", "9", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 60, 100, 20, 20, hWnd, (HMENU)BTN9, NULL, NULL);

	btn0 = CreateWindow("button", "0", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 35, 125, 20, 20, hWnd, (HMENU)BTN0, NULL, NULL);
}



/*		---- WHAT TO ADD INTO THE PROGRAM NEXT ----
	- Add grid controls for calculator in a for loop
	- 





	






*/