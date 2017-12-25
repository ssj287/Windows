#include<Windows.h>
#include<tchar.h>
BOOLEAN InitWindowsClass(HINSTANCE hInstance,int nCmdShow);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowsClass(hInstance, nCmdShow))
	{
		MessageBox(NULL, _T("创建窗口失败"), _T("创建窗口"), NULL);
		return 1;
	}
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT PtStr;//某应用程序用来绘制它所拥有的窗口客户区所需要的信息
	HBRUSH hBrush;//画刷
	HPEN hPen;//画笔
	static int dispMode = -1;
	LPCTSTR str;
	switch (message)
	{
		//鼠标单击
	case WM_LBUTTONDOWN:
		/*这两个都用于声明客户区无效，当下一个WM_PAINT消息到来时发生重画。其中InvalidateRect(hwnd, NULL, true);重画时将擦除背景.InvalidateRect(hwnd, NULL, false);重画时不擦除背景。*/
		InvalidateRect(hwnd, NULL, TRUE); break;
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &PtStr);//获取设备环境
		dispMode = (dispMode + 1) % 6;//点击6次求余数
		switch (dispMode)
		{
		case 0:
			str = _T("映射方式MM_TEXT:缺省的的映射方式");
			SetMapMode(hDC, MM_TEXT);//设置映射方式为为缺省映射方式
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 1:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标20*20，映射为视口尺寸为10*10,图像缩小一倍");
			SetMapMode(hDC, MM_ISOTROPIC);//设置映射方式
			SetWindowExtEx(hDC, 20, 20, NULL);//窗口区域;当前设备句柄;以逻辑为单位新窗口区域高度;宽度;lpSize保存前窗口区域size的地址,如果为NULL则表示忽略调用前的尺寸
			SetViewportExtEx(hDC, 10, 10, NULL);// 视口区域;当前设备句柄;以逻辑为单位新视口区域高度;宽度;lpSize保存前视口区域size的地址,如果为NULL则表示忽略调用前的尺寸
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 2:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标10*10，映射为视口尺寸为20*20,图像放大一倍");
			SetMapMode(hDC, MM_ISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 20, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 3:
			str = _T("映射方式MM_ANISOTROPIC:窗口坐标10*10，映射为视口尺寸为20*10,图像横向放大一倍");
			SetMapMode(hDC, MM_ANISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 10, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 4:
			str = _T("映射方式MM_ANISOTROPIC:窗口坐标10*10，映射为视口尺寸为20*10,图像横向放大一倍，纵向缩小1倍");
			SetMapMode(hDC, MM_ANISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 5, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 5:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标10*10，映射为视口尺寸为20*5,图形为了保持原纵横比,系统会调整映射比例");
			SetMapMode(hDC, MM_ISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 5, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		}
		hPen=(HPEN)GetStockObject(BLACK_PEN);//黑色画笔
		hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);//黑色画刷
		SelectObject(hDC, hPen);//画笔选入设备环境
		SelectObject(hDC, hBrush);
		RoundRect(hDC, 50, 120, 100, 200, 15, 15);//圆角矩形
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);//浅灰色画刷
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 150, 50 ,250, 150);//椭圆
		hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);//虚画刷
		SelectObject(hDC, hBrush);
		Pie(hDC, 250, 50, 300, 100, 250, 50, 300, 50);//画饼
		EndPaint(hwnd, &PtStr);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}
BOOLEAN InitWindowsClass(HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND  hWnd;
	TCHAR szWindowClass[] = _T("窗口示例");
	TCHAR szTitle[] = _T("映射模式及示例图");
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	if (!RegisterClassEx(&wcex))
	{
		return FALSE;
	}
	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd)return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}