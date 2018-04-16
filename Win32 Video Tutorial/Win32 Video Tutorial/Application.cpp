#include <Windows.h>
#include <tchar.h>

#define FILE_MENU_NEW 1		// All this does is assign an ID to UINT_PTR uiNewMenuItem
#define FILE_MENU_OPEN 2	// in the AppendMenu() function.
#define FILE_MENU_EXIT 3

// HWND hWnd;  // Can either use this in the global scope or in local scope...
// HMENU hMenu; // You can also keep this in the local scope of AddMenus(HWND);

TCHAR szTitle[] = _T("Title");
TCHAR szWinClass[] = _T("WindowClass");

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void AddMenus(HWND);
void AddControls(HWND);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int showCmd)
{
	// STEP 1 --> Set up the window class (in this case, and most cases, it is WNDCLASSEX)

	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = szWinClass;
	wc.lpszMenuName = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_PIN);
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(0, 0, 0)));

	// STEP 2 --> Register the class with Windows OS. If registering fails, show error message.
	RegisterClassEx(&wc);

	if (!&wc)
	{
		MessageBoxA(NULL, "Call to RegisterClassEx failed!", "ERROR!", MB_ABORTRETRYIGNORE | MB_ICONERROR);
		return -1;
	}

	// STEP 3 --> Create the window
	HWND hWnd = CreateWindowEx(WS_EX_LEFTSCROLLBAR, szWinClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, hInstance, NULL);

	// STEP 4 --> Check to make sure the window was created. If not, show error message.
	if (!hWnd)
	{
		MessageBoxA(NULL, "Call to CreateWindowEx failed!", "ERROR!", MB_OK | MB_ICONERROR);
		return -1;
	}

	// STEP 5 --> Show the window and update it.
	ShowWindow(hWnd, showCmd);
	UpdateWindow(hWnd);

	// STEP 6
	MSG msg;

	SecureZeroMemory(&msg, sizeof(MSG));
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
		switch (wParam)
		{
		case 1:
			MessageBeep(MB_OK);
			break;
		case FILE_MENU_EXIT:
			MessageBeep(MB_ICONINFORMATION);
			const int exit = MessageBox(hWnd, "Are you sure you want to quit?", "Exit", MB_YESNO);
			switch (exit)
			{
			case IDYES:
				DestroyWindow(hWnd);
			case IDNO:
				break;
			default:
				break;
			}
		}
	case WM_CREATE:
		AddMenus(hWnd);
		AddControls(hWnd);
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	/*case WM_LBUTTONUP:
		MessageBoxA(NULL, "Left Click", "Event", MB_OK);
		break;*/
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

void AddMenus(HWND hWnd)
{
	HMENU hMenu = CreateMenu();
	HMENU hFile = CreateMenu();
	HMENU hSub = CreateMenu();

	AppendMenu(hSub, MF_STRING, NULL, "Open Recent");

	AppendMenu(hFile, MF_POPUP, FILE_MENU_NEW, "New");
	AppendMenu(hFile, MF_POPUP, (UINT_PTR)hSub, "Open");
	AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFile, MF_POPUP, FILE_MENU_EXIT, "Exit");


	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFile, "File");
	AppendMenu(hMenu, MF_STRING, NULL, "Help");

	SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd) {
	CreateWindow("Static", "Enter your text here: ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 100, 80, 100, 20, hWnd, NULL, NULL, NULL);
	CreateWindow("edit", "Window Name", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 100, 101, 100, 20, hWnd, NULL, NULL, NULL);
	CreateWindowEx(NULL, _T("Edit"), _T("Window Name"), WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 100, 121, 100, 20, hWnd, NULL, NULL, NULL);
}