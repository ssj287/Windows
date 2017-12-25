// Chap2Exa1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
//hinstance是唯一表示本程序的实例句柄,系统和其他应用程序通过该句柄与本程序通信
//hprevinsttance是本程序的前一个实例句柄，由于32位Windows采用线程模式,每个线程拥有自己的句柄,因此该参数始终为空
//lpCmdLine是一个字符串指针,指向命令行参数字符串,没有命令行参数时为空
//nCmdLine指明程序最初运行时窗口打开方式,如正常方式,最大化或最小化运行
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	return 0;
}
//第一个参数指明此消息框的父窗口，为null则说明没有父窗口
//第2,3个参数类型均为字符型指针,分别指向消息框中显示的字符串和消息框标题栏显示的字符串
//第4个参数是一个无符号整数,表明消息框中显示的按钮和风格
int MessageBox(NULL,LPCTSTR lpszText,LPCTSTR lpszCaption=NULL,UINT nType=MB_OK);
//lpszText表示消息框内部,nIDPrompt为显示的字符串在字符串表中的ID。
int AfxMessageBox(LPCTSTR lpszText,UINT nType=MB_OK,UNIT nIDHelp=0);
int AFXAPI AfxMessageBox(UINT nIDPrompt,UINT nType=MB_OK,UINT nIDHelp=(UINT)-1);