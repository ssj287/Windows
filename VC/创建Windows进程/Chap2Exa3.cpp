#include<windows.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{
	STARTUPINFO info;//用于指于进程窗口参数的结构对象
	memset(&info,0,sizeof(info));
	info.cb=sizeof(info);
	PROCESS_INFORMATION pinfo;//用于获取进程句柄的结构对象
	cout<<"Chap2Exa3.exe:Chap2Exa3.exe is starting "<<endl;
	if(!CreateProcess(NULL,"Chap2Exa4.exe",NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&info,&pinfo))
		cout<<"Chap2Exa3:Chap2Exa4.exe didn't start"<<endl;
	cout<<"Chap2Exa3.exe:ChapExa3.exe sleeping"<<endl;
	cout.flush();
	Sleep(10000);
	exit(0);
}
