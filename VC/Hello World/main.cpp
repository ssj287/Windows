#include<Windows.h>
//���ں�������
LRESULT  CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
//��ں��� WinMain()
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	WNDCLASS wndclass;//���崰����ṹ����
	HWND hwnd;//���崰�ھ��
	MSG msg;//������Ϣ��������
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//�ı䴰�ڴ�С���ػ�
	wndclass.lpfnWndProc = WndProc;//���ں���ΪWndProc
	wndclass.cbClsExtra = 0;//����������չ
	wndclass.cbWndExtra = 0;//����ʵ������չ
	wndclass.hInstance = hInstance;//ע�ᴰ�����ʵ�����
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//������Ĭ��ͼ��
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//�����ü�ͷ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//����Ϊ��ɫ
	wndclass.lpszMenuName = NULL;//����Ĭ���޲˵�
	wndclass.lpszClassName = "Chap1Exal";//��������
	if (!RegisterClass(&wndclass))return FALSE;//ע�ᴰ��,ʧ���򷵻�
	hwnd = CreateWindow("Chap1Exal","Chap1Exal", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance,NULL);//��������
	ShowWindow(hwnd, nCmdShow);//��ʾ����
	UpdateWindow(hwnd);//���´��ڵĿͻ���
	//������Ϣѭ��
	while (GetMessage(&msg,NULL,0,0))//��ȡ��Ϣ������WM_QUIT�˴���Ϣ
	{
		TranslateMessage(&msg);//������Ϣת��
		DispatchMessage(&msg);//��Ϣ�����ں���
	}
	return msg.wParam;
}
//���ں���
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)//������Ϣֵת����Ӧ����Ϣ����
	{
	case WM_PAINT://�ػ����ڿͻ�����Ϣ
		HDC hdc;//�����豸�������
		PAINTSTRUCT ps;//�����ͼ��Ϣ�ṹ����
		hdc = BeginPaint(hwnd, &ps);//��ȡ���ػ����ڵ��豸�������
		//�û�����(20,60)����ʾ�ı�������Ϊ35����ĸ
		TextOut(hdc, 20, 60, "Hello World!",12);
		EndPaint(hwnd, &ps);//����Ҫ�ػ��Ĵ���
		return 0;
	case WM_DESTROY://����������Ϣ
		PostQuitMessage(0);//�����˳�������ϢWM_QUIT
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);//����תĬ�ϴ��ں���
}