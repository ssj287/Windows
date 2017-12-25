#include<Windows.h>
//窗口函数声明
LRESULT  CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//入口函数 WinMain()
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	WNDCLASS wndclass;//定义窗口类结构变量
	HWND hwnd;//定义窗口句柄
	MSG msg;//定义消息机构变量
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//改变窗口大小则重画
	wndclass.lpfnWndProc = WndProc;//窗口函数为WndProc
	wndclass.cbClsExtra = 0;//窗口类无扩展
	wndclass.cbWndExtra = 0;//窗口实例无扩展
	wndclass.hInstance = hInstance;//注册窗口类的实例句柄
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//窗口用默认图标
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//窗口用箭头光标
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//背景为白色
	wndclass.lpszMenuName = NULL;//窗口默认无菜单
	wndclass.lpszClassName = "Chap1Exal";//窗口类名
	if (!RegisterClass(&wndclass))return FALSE;//注册窗口,失败则返回
	hwnd = CreateWindow("Chap1Exal","Chap1Exal", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance,NULL);//创建窗口
	ShowWindow(hwnd, nCmdShow);//显示窗口
	UpdateWindow(hwnd);//更新窗口的客户区
	//以下消息循环
	while (GetMessage(&msg,NULL,0,0))//获取消息，遇到WM_QUIT退处消息
	{
		TranslateMessage(&msg);//键盘消息转换
		DispatchMessage(&msg);//消息给窗口函数
	}
	return msg.wParam;
}
//窗口函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)//根据消息值转换相应的消息处理
	{
	case WM_PAINT://重画窗口客户区消息
		HDC hdc;//定义设备描述句柄
		PAINTSTRUCT ps;//定义绘图信息结构变量
		hdc = BeginPaint(hwnd, &ps);//获取需重画窗口的设备描述句柄
		//用户坐标(20,60)处显示文本，限制为35个字母
		TextOut(hdc, 20, 60, "Hello World!",12);
		EndPaint(hwnd, &ps);//结束要重画的窗口
		return 0;
	case WM_DESTROY://撤销窗口消息
		PostQuitMessage(0);//产生退出程序消息WM_QUIT
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);//其他转默认窗口函数
}