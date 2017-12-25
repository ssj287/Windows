#include<Windows.h>
#include<tchar.h>
BOOLEAN InitWindowsClass(HINSTANCE hInstance,int nCmdShow);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowsClass(hInstance, nCmdShow))
	{
		MessageBox(NULL, _T("��������ʧ��"), _T("��������"), NULL);
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
	PAINTSTRUCT PtStr;//ĳӦ�ó���������������ӵ�еĴ��ڿͻ�������Ҫ����Ϣ
	HBRUSH hBrush;//��ˢ
	HPEN hPen;//����
	static int dispMode = -1;
	LPCTSTR str;
	switch (message)
	{
		//��굥��
	case WM_LBUTTONDOWN:
		/*�����������������ͻ�����Ч������һ��WM_PAINT��Ϣ����ʱ�����ػ�������InvalidateRect(hwnd, NULL, true);�ػ�ʱ����������.InvalidateRect(hwnd, NULL, false);�ػ�ʱ������������*/
		InvalidateRect(hwnd, NULL, TRUE); break;
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &PtStr);//��ȡ�豸����
		dispMode = (dispMode + 1) % 6;//���6��������
		switch (dispMode)
		{
		case 0:
			str = _T("ӳ�䷽ʽMM_TEXT:ȱʡ�ĵ�ӳ�䷽ʽ");
			SetMapMode(hDC, MM_TEXT);//����ӳ�䷽ʽΪΪȱʡӳ�䷽ʽ
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 1:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������20*20��ӳ��Ϊ�ӿڳߴ�Ϊ10*10,ͼ����Сһ��");
			SetMapMode(hDC, MM_ISOTROPIC);//����ӳ�䷽ʽ
			SetWindowExtEx(hDC, 20, 20, NULL);//��������;��ǰ�豸���;���߼�Ϊ��λ�´�������߶�;���;lpSize����ǰ��������size�ĵ�ַ,���ΪNULL���ʾ���Ե���ǰ�ĳߴ�
			SetViewportExtEx(hDC, 10, 10, NULL);// �ӿ�����;��ǰ�豸���;���߼�Ϊ��λ���ӿ�����߶�;���;lpSize����ǰ�ӿ�����size�ĵ�ַ,���ΪNULL���ʾ���Ե���ǰ�ĳߴ�
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 2:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*20,ͼ��Ŵ�һ��");
			SetMapMode(hDC, MM_ISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 20, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 3:
			str = _T("ӳ�䷽ʽMM_ANISOTROPIC:��������10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*10,ͼ�����Ŵ�һ��");
			SetMapMode(hDC, MM_ANISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 10, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 4:
			str = _T("ӳ�䷽ʽMM_ANISOTROPIC:��������10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*10,ͼ�����Ŵ�һ����������С1��");
			SetMapMode(hDC, MM_ANISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 5, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		case 5:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*5,ͼ��Ϊ�˱���ԭ�ݺ��,ϵͳ�����ӳ�����");
			SetMapMode(hDC, MM_ISOTROPIC);
			SetWindowExtEx(hDC, 10, 10, NULL);
			SetViewportExtEx(hDC, 20, 5, NULL);
			TextOut(hDC, 0, 0, str, _tcslen(str));
			break;
		}
		hPen=(HPEN)GetStockObject(BLACK_PEN);//��ɫ����
		hBrush = (HBRUSH)GetStockObject(DKGRAY_BRUSH);//��ɫ��ˢ
		SelectObject(hDC, hPen);//����ѡ���豸����
		SelectObject(hDC, hBrush);
		RoundRect(hDC, 50, 120, 100, 200, 15, 15);//Բ�Ǿ���
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);//ǳ��ɫ��ˢ
		SelectObject(hDC, hBrush);
		Ellipse(hDC, 150, 50 ,250, 150);//��Բ
		hBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);//�黭ˢ
		SelectObject(hDC, hBrush);
		Pie(hDC, 250, 50, 300, 100, 250, 50, 300, 50);//����
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
	TCHAR szWindowClass[] = _T("����ʾ��");
	TCHAR szTitle[] = _T("ӳ��ģʽ��ʾ��ͼ");
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