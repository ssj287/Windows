#include<afxwin.h>
class Chap3Exa3App : public CWinApp
{
public:
	virtual BOOL InitInstance()
	{
		//������Ϣ��
		MessageBox(NULL, _T("The Simplest MFC Application "), "Chap3Ex3", MB_OK);
		return TRUE;
	}
}; Chap3Exa3App theApp;