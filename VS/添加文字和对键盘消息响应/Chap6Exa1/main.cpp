#include<Windows.h>
#include<tchar.h>
#define MAXLINE 100//最多行数
#define MAXNUMCHAR 40//一行中最多字符
BOOLEAN InitWindowsClass(HINSTANCE hInstance, int nCmdShow);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	if (!InitWindowsClass(hInstance, nCmdShow))
	{
		MessageBox(NULL, _T("创建窗口失败"), _T("创建窗口"), NULL);
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
	static TCHAR cCharInfo[MAXLINE][MAXNUMCHAR];//设置静态数组字符串存放输入的字符
	static int nNumLine = 0;//现有行数
	static int nArrayPos[MAXLINE];//最后一行最后一个位置
	static int nX = 0, nY = 0;//插字符位置
	static int nLnHeight = 0;//行高
	static int nCharWidth;//字符的宽度
	static int nXCaret = 0, nYCaret = 0;//插字符位置
	int x;
	HDC hDC;
	TEXTMETRIC tm;//TEXTMETRIC类型的变量用于存储装置字体结构信息
	PAINTSTRUCT PtStr;//某应用程序用来绘制它所拥有的窗口客户区所需要的信息
	switch (message)
	{
	case WM_CREATE:
	{
		hDC = GetDC(hwnd);
		GetTextMetrics(hDC, &tm);//获取字体信息
		nLnHeight = tm.tmHeight + tm.tmExternalLeading;//保存每行的高度与行间距
		nCharWidth = tm.tmAveCharWidth;//保存字符的平均宽度
		CreateCaret(hwnd, NULL, nCharWidth / 10, tm.tmHeight);//创建插字符
		ShowCaret(hwnd);//显示插字符
		ReleaseDC(hwnd, hDC);
	}
	break;
	case WM_CHAR://遇见非系统字符的处理
	{
		if (wParam == VK_BACK)//处理按下回退键的消息
		{
			if (nX == 0)//如果在一行的初始位置
			{
				if (nNumLine > 0)
				{
					nY--;
					nX = nArrayPos[nY];
				}
				else
				{
					nX = nY = nNumLine = nArrayPos[0] = 0;
					MessageBox(hwnd, _T("已到文件头，不能删除字符"), NULL, MB_OK);
					break;
				}
			}
			else
			{
				nArrayPos[nY] = nArrayPos[nY] - 1;//每按一次回退键就回退一个位置
				for (int i = nX; i < nArrayPos[nY]; i++)
				{
					cCharInfo[nY][i] = cCharInfo[nY][i - 1];//对现有字符进行调整
				}
				nX--;//调整插字符位置
			}
			InvalidateRect(hwnd, NULL, TRUE);//刷新用户区，并发出WM_PAINT消息
			break;
		}
		else if (wParam == VK_RETURN)//按回车键就要进行换行处理
		{
			nNumLine++;//总行数增加
			if (nNumLine >= MAXLINE)//如果大于最大行数就提醒用户
			{
				nY = nNumLine;
				MessageBox(hwnd, _T("已经超过最大行数不能添加字符"), NULL, MB_OK);
				break;
			}
			nArrayPos[nY] = nX;//插字符的横坐标就是本行结束的位置
			for (int i = nNumLine; i > nY + 1; i--)
				//由下往上调整使当前行多出一个空行
			{
				_tcscpy(cCharInfo[i], cCharInfo[i - 1]);
				nArrayPos[i] = nArrayPos[i - 1];
			}
			_tcscpy(cCharInfo[nY + 1], &cCharInfo[nY][nX]);//将当前行的其余部分复制到下一行
			cCharInfo[nY][nX] = '\0';//当前行结束标志
			nY++;
			nX = 0;//将插字符位置调整到下一行行首
			nArrayPos[nY] = _tcslen(cCharInfo[nY]);//保存新行的字符总数
		}
		else//其他字符
		{
			//如果当前行字符总数没有超过限制就插入新字符
			if (nArrayPos[nY] < MAXNUMCHAR - 1)
			{
				cCharInfo[nY][nArrayPos[nY] + 1] = '\0';//当前行结束标志向后移位
				//后续字符也移位，为新字符添加位置
				for (x = nArrayPos[nY]; x > nX; x = x - 1)
				{
					cCharInfo[nY][x] = cCharInfo[nY][x - 1];
				}
				cCharInfo[nY][x] = cCharInfo[nY][x - 1];
				cCharInfo[nY][nX] = (TCHAR)wParam;//将新插入的字符放到当前位置
				nArrayPos[nY] = nArrayPos[nY] + 1;
				nX++;//调整插字符位置
			}
			//当前字符数达到最大就换行
			else
			{
				nNumLine++;
				if (nNumLine > MAXLINE)
				{
					nY = nNumLine;
					MessageBox(hwnd, _T("已超过最大行数,不能继续插入字符"), NULL, MB_OK);
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
			nX = nArrayPos[nY];//输入位置从本行末尾开始
			break;
		case VK_HOME:
			nX = 0;//输入位置为本行起始位置
			break;
		case VK_DELETE:
			if (nArrayPos[nY] == nX)
				MessageBox(hwnd, _T("本行当前位置以后位置已空,没有位置可供删除"), NULL, MB_OK);
			else
			{
				for(x=nX;x<nArrayPos[nY];x=x+1)
				{
					cCharInfo[nY][x] = cCharInfo[nY][x + 1];//删除一个字符后其余字符位置调整
				}
				nArrayPos[nY] = nArrayPos[nY] - 1;//每删除一个字符总字符数减一
			}
			break;
		case VK_LEFT:
			if (nX > 0)
			{
				nX = nX - 1;
			}
			else
			{
				MessageBox(hwnd, _T("已在最左边无法移动"), NULL, MB_OK);
			}
			break;
		case VK_RIGHT:
			if (nArrayPos[nY] > nX)
			{
				nX++;
			}
			else
			{
				MessageBox(hwnd, _T("已在最右，无法往后移动"), NULL, MB_OK);
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
				MessageBox(hwnd, _T("你已经移动到第一行了，无法移动"), NULL, MB_OK);
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
				MessageBox(hwnd, _T("已经到最后一行无法下移"), NULL, MB_OK);
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
		GetTextExtentPoint(hDC, cCharInfo[nY], nX, &size);//获取文字后输出尺寸
		nXCaret = size.cx;//计算插字符坐标
		nYCaret = nLnHeight*nY;
		SetCaretPos(nXCaret, nYCaret);//设置插字符位置
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
	TCHAR szTitle[] = _T("应用程序对窗口消息响应");
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