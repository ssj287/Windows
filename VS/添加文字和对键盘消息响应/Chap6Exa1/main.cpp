#include<Windows.h>
#include<tchar.h>
#define MAXLINE 100//�������
#define MAXNUMCHAR 40//һ��������ַ�
BOOLEAN InitWindowsClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowsClass(hInstance, nCmdShow))
	{
		MessageBox(NULL, _T("��������ʧ��"), _T("��������"), NULL);
		return 1;
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
	static TCHAR cCharInfo[MAXLINE][MAXNUMCHAR];//���þ�̬�����ַ������������ַ�
	static int nNumLine = 0;//��������
	static int nArrayPos[MAXLINE];//���һ�����һ��λ��
	static int nX = 0, nY = 0;//���ַ�λ��
	static int nLnHeight = 0;//�и�
	static int nCharWidth;//�ַ��Ŀ��
	static int nXCaret = 0, nYCaret = 0;//���ַ�λ��
	int x;
	HDC hDC;
	TEXTMETRIC tm;//TEXTMETRIC���͵ı������ڴ洢װ������ṹ��Ϣ
	PAINTSTRUCT PtStr;//ĳӦ�ó���������������ӵ�еĴ��ڿͻ�������Ҫ����Ϣ
	switch (message)
	{
	case WM_CREATE:
	{
		hDC = GetDC(hwnd);
		GetTextMetrics(hDC, &tm);//��ȡ������Ϣ
		nLnHeight = tm.tmHeight + tm.tmExternalLeading;//����ÿ�еĸ߶����м��
		nCharWidth = tm.tmAveCharWidth;//�����ַ���ƽ�����
		CreateCaret(hwnd, NULL, nCharWidth / 10, tm.tmHeight);//�������ַ�
		ShowCaret(hwnd);//��ʾ���ַ�
		ReleaseDC(hwnd, hDC);
	}
	break;
	case WM_CHAR://������ϵͳ�ַ��Ĵ���
	{
		if (wParam == VK_BACK)//�����»��˼�����Ϣ
		{
			if (nX == 0)//�����һ�еĳ�ʼλ��
			{
				if (nNumLine > 0)
				{
					nY--;
					nX = nArrayPos[nY];
				}
				else
				{
					nX = nY = nNumLine = nArrayPos[0] = 0;
					MessageBox(hwnd, _T("�ѵ��ļ�ͷ������ɾ���ַ�"), NULL, MB_OK);
					break;
				}
			}
			else
			{
				nArrayPos[nY] = nArrayPos[nY] - 1;//ÿ��һ�λ��˼��ͻ���һ��λ��
				for (int i = nX; i < nArrayPos[nY]; i++)
				{
					cCharInfo[nY][i] = cCharInfo[nY][i - 1];//�������ַ����е���
				}
				nX--;//�������ַ�λ��
			}
			InvalidateRect(hwnd, NULL, TRUE);//ˢ���û�����������WM_PAINT��Ϣ
			break;
		}
		else if (wParam == VK_RETURN)//���س�����Ҫ���л��д���
		{
			nNumLine++;//����������
			if (nNumLine >= MAXLINE)//���������������������û�
			{
				nY = nNumLine;
				MessageBox(hwnd, _T("�Ѿ��������������������ַ�"), NULL, MB_OK);
				break;
			}
			nArrayPos[nY] = nX;//���ַ��ĺ�������Ǳ��н�����λ��
			for (int i = nNumLine; i > nY + 1; i--)
				//�������ϵ���ʹ��ǰ�ж��һ������
			{
				_tcscpy(cCharInfo[i], cCharInfo[i - 1]);
				nArrayPos[i] = nArrayPos[i - 1];
			}
			_tcscpy(cCharInfo[nY + 1], &cCharInfo[nY][nX]);//����ǰ�е����ಿ�ָ��Ƶ���һ��
			cCharInfo[nY][nX] = '\0';//��ǰ�н�����־
			nY++;
			nX = 0;//�����ַ�λ�õ�������һ������
			nArrayPos[nY] = _tcslen(cCharInfo[nY]);//�������е��ַ�����
		}
		else//�����ַ�
		{
			//�����ǰ���ַ�����û�г������ƾͲ������ַ�
			if (nArrayPos[nY] < MAXNUMCHAR - 1)
			{
				cCharInfo[nY][nArrayPos[nY] + 1] = '\0';//��ǰ�н�����־�����λ
				//�����ַ�Ҳ��λ��Ϊ���ַ����λ��
				for (x = nArrayPos[nY]; x > nX; x = x - 1)
				{
					cCharInfo[nY][x] = cCharInfo[nY][x - 1];
				}
				cCharInfo[nY][x] = cCharInfo[nY][x - 1];
				cCharInfo[nY][nX] = (TCHAR)wParam;//���²�����ַ��ŵ���ǰλ��
				nArrayPos[nY] = nArrayPos[nY] + 1;
				nX++;//�������ַ�λ��
			}
			//��ǰ�ַ����ﵽ���ͻ���
			else
			{
				nNumLine++;
				if (nNumLine > MAXLINE)
				{
					nY = nNumLine;
					MessageBox(hwnd, _T("�ѳ����������,���ܼ��������ַ�"), NULL, MB_OK);
					break;
				}
				for (int i = nNumLine; i < nY + 1; i++)
				{
					_tcscpy(cCharInfo[i], cCharInfo[i - 1]);
					nArrayPos[i] = nArrayPos[i - 1];
				}
				_tcscpy(cCharInfo[nY + 1], &cCharInfo[nY][nX]);
				cCharInfo[nY][nX] = '\0';
				nArrayPos[nY] = nX;
				nY++;
				nX = 0;
				nArrayPos[nY] = _tcslen(cCharInfo[nY]);
			}
		}
		InvalidateRect(hwnd, NULL, TRUE);
	}
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_END:
			nX = nArrayPos[nY];//����λ�ôӱ���ĩβ��ʼ
			break;
		case VK_HOME:
			nX = 0;//����λ��Ϊ������ʼλ��
			break;
		case VK_DELETE:
			if (nArrayPos[nY] == nX)
				MessageBox(hwnd, _T("���е�ǰλ���Ժ�λ���ѿ�,û��λ�ÿɹ�ɾ��"), NULL, MB_OK);
			else
			{
				for(x=nX;x<nArrayPos[nY];x=x+1)
				{
					cCharInfo[nY][x] = cCharInfo[nY][x + 1];//ɾ��һ���ַ��������ַ�λ�õ���
				}
				nArrayPos[nY] = nArrayPos[nY] - 1;//ÿɾ��һ���ַ����ַ�����һ
			}
			break;
		case VK_LEFT:
			if (nX > 0)
			{
				nX = nX - 1;
			}
			else
			{
				MessageBox(hwnd, _T("����������޷��ƶ�"), NULL, MB_OK);
			}
			break;
		case VK_RIGHT:
			if (nArrayPos[nY] > nX)
			{
				nX++;
			}
			else
			{
				MessageBox(hwnd, _T("�������ң��޷������ƶ�"), NULL, MB_OK);
			}
			break;
		case VK_UP:
			if (nY > 0)
			{
				nY--;
				if (nX > nArrayPos[nY])
					nX = nArrayPos[nY];
			}
			else
			{
				MessageBox(hwnd, _T("���Ѿ��ƶ�����һ���ˣ��޷��ƶ�"), NULL, MB_OK);
			}
			break;
		case VK_DOWN:
			if (nY < nNumLine)
			{
				nY++;
				if (nX > nArrayPos[nY])
					nX = nArrayPos[nY];
			}
			else
			{
				MessageBox(hwnd, _T("�Ѿ������һ���޷�����"), NULL, MB_OK);
			}
			break;
		}
		InvalidateRect(hwnd, NULL, TRUE);
	}
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &PtStr);
		for (int i = 0; i < nNumLine; i++)
		{
			TextOut(hDC, 0, nLnHeight*i,cCharInfo[i], nArrayPos[i]);
		}
		SIZE size;
		GetTextExtentPoint(hDC, cCharInfo[nY], nX, &size);//��ȡ���ֺ�����ߴ�
		nXCaret = size.cx;//������ַ�����
		nYCaret = nLnHeight*nY;
		SetCaretPos(nXCaret, nYCaret);//���ò��ַ�λ��
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
	TCHAR szTitle[] = _T("Ӧ�ó���Դ�����Ϣ��Ӧ");
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