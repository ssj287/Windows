#include<Windows.h>
#include<tchar.h>
BOOLEAN InitWindows(HINSTANCE hInstance, int nCmdShow);
BOOLEAN InitWindowsClass(HINSTANCE hInstance);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowsClass(hInstance))
	{
		return FALSE;
	}
	if (!InitWindows(hInstance,nCmdShow))
	{
		return FALSE;
	}
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	WORD x,y;
	HCURSOR hCuror;
	switch (message)
	{
	case WM_MOUSEMOVE:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (x >= 50 && x <= 400 && y >= 50 && y <= 300)
		{
			if (x >= 50 && x <= 100 && y >= 50 && y <= 100)
			{
				hCuror = LoadCursor(NULL, IDC_CROSS);
				SetCursor(hCuror);
			}
			if (x >= 100 && x <= 150 && y >= 50 && y <= 100)
			{
				hCuror = LoadCursor(NULL, IDC_SIZEALL);
				SetCursor(hCuror);
			}
			if (x >= 150 && x <= 200 && y >= 50 && y <= 100)
			{
				hCuror = LoadCursor(NULL, IDC_HELP);
				SetCursor(hCuror);
			}
			if (x >= 50 && x <= 100 && y >= 100 && y <= 150)
			{
				hCuror = LoadCursor(NULL, IDC_SIZEALL);
				SetCursor(hCuror);
			}
		}
		else
		{
			hCuror = LoadCursor(NULL, IDC_ARROW);
			SetCursor(hCuror);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}
BOOLEAN InitWindowsClass(HINSTANCE hInstance) 
{
	WNDCLASS wcex;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hIcon = LoadIcon(NULL, "END");
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = "WinMouse"; 
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	return RegisterClass(&wcex);
}
BOOLEAN InitWindows(HINSTANCE hInstance,int nCmdShow)
{
	
	HWND  hWnd;
	hWnd = CreateWindow("WinMouse", "鼠标和光标", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
	if (!hWnd)return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}