#include<windows.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
void main()
{
	STARTUPINFO info;//����ָ�ڽ��̴��ڲ����Ľṹ����
	memset(&info,0,sizeof(info));
	info.cb=sizeof(info);
	PROCESS_INFORMATION pinfo;//���ڻ�ȡ���̾���Ľṹ����
	cout<<"Chap2Exa3.exe:Chap2Exa3.exe is starting "<<endl;
	if(!CreateProcess(NULL,"Chap2Exa4.exe",NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&info,&pinfo))
		cout<<"Chap2Exa3:Chap2Exa4.exe didn't start"<<endl;
	cout<<"Chap2Exa3.exe:ChapExa3.exe sleeping"<<endl;
	cout.flush();
	Sleep(10000);
	exit(0);
}
