// Chap2Exa1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
//hinstance��Ψһ��ʾ�������ʵ�����,ϵͳ������Ӧ�ó���ͨ���þ���뱾����ͨ��
//hprevinsttance�Ǳ������ǰһ��ʵ�����������32λWindows�����߳�ģʽ,ÿ���߳�ӵ���Լ��ľ��,��˸ò���ʼ��Ϊ��
//lpCmdLine��һ���ַ���ָ��,ָ�������в����ַ���,û�������в���ʱΪ��
//nCmdLineָ�������������ʱ���ڴ򿪷�ʽ,��������ʽ,��󻯻���С������
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	return 0;
}
//��һ������ָ������Ϣ��ĸ����ڣ�Ϊnull��˵��û�и�����
//��2,3���������;�Ϊ�ַ���ָ��,�ֱ�ָ����Ϣ������ʾ���ַ�������Ϣ���������ʾ���ַ���
//��4��������һ���޷�������,������Ϣ������ʾ�İ�ť�ͷ��
int MessageBox(NULL,LPCTSTR lpszText,LPCTSTR lpszCaption=NULL,UINT nType=MB_OK);
//lpszText��ʾ��Ϣ���ڲ�,nIDPromptΪ��ʾ���ַ������ַ������е�ID��
int AfxMessageBox(LPCTSTR lpszText,UINT nType=MB_OK,UNIT nIDHelp=0);
int AFXAPI AfxMessageBox(UINT nIDPrompt,UINT nType=MB_OK,UINT nIDHelp=(UINT)-1);