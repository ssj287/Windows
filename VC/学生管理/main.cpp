#include<windows.h>
#include<windowsx.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
void studentmessage(HWND hWnd);/*���������ļ��ĺ���*/
void showmessage(HWND hWnd);/*������ʾѧ��ѧ����Ϣ�ĺ���*/
void findoutmessage(HWND hWnd);/*������ѯѧ����Ϣ�ĺ���*/
void changemessage(HWND hWnd);/*�����޸���Ϣ�ĺ���*/
void delmessage(HWND hWnd);/*����ɾ����Ϣ�ĺ���*/
void savefile(HWND hWnd);/*���������ļ��ĺ���*/
void joinmessage(HWND hWnd);/*���������Ϣ�ĺ���*/
void leavestudent(HWND hWnd);/*������ʾ���Ա�ҵѧ���ĺ���*/
int messagejy(HWND hWnd);/*����У����������ݵĺ���*/
void allaverage(HWND hWnd);/*����ͳ�Ƹ���Ŀƽ���ֵĺ���*/
void qingkong(HWND hWnd);/*��������ı���ĺ���*/
typedef struct student {
 char name[20];
 char no[20];
 char banji[20];
 int year,month,day;
 int score1,score2,score3,
  score4,score5;
 struct student *next;
}STU;
STU head,*p,*tail;
RECT rect;
HDC hDC;
PAINTSTRUCT paint;
FILE *fp;
char end[5000]="",number[20]="",name[20]="",Class[20]="",y[10]="",m[10]="",d[10]="",
s1[10],s2[10],s3[10],s4[10],s5[10];
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    char *cName = "myWindow";
    WNDCLASS wc;
    HWND hWnd;
    MSG Msg;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground =(HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.hCursor = NULL;
    wc.hIcon = NULL;
    wc.hInstance = hInstance;
    wc.lpfnWndProc = WinProc;
    wc.lpszClassName =cName;
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&wc);
    hWnd = CreateWindow(cName,"ѧ�ֹ���ϵͳ",WS_OVERLAPPEDWINDOW,50,100,1200,900,NULL,NULL,hInstance,NULL) ;
     ShowWindow(hWnd,nShowCmd);
  UpdateWindow(hWnd);
 while(GetMessage(&Msg,NULL,0,0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.message;
}
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam)
{
 static HWND btnHwnd ;
 static HWND inputHwnd ;
    switch(Msg)
    {
 case WM_PAINT:
  hDC=BeginPaint(hWnd,&paint);
  SetRect(&rect,250,10,90,70);
  DrawText(hDC,"��ӭʹ��ѧ�ֹ���ϵͳ��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1200,50,30);
  DrawText(hDC,"ѧ�ţ�",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,630,1200,50,30);
  DrawText(hDC,"������",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1150,1200,50,30);
  DrawText(hDC,"��ѧʱ�䣺",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1920,1200,50,30);
  DrawText(hDC,"�༶��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1450,1210,20,20);
  DrawText(hDC,"��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1650,1210,20,20);
  DrawText(hDC,"��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1840,1210,20,20);
  DrawText(hDC,"��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1310,50,20);
  DrawText(hDC,"������:",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,550,1310,50,20);
  DrawText(hDC,"רҵ�Σ�",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,950,1310,50,20);
  DrawText(hDC,"ѡ�޿Σ�",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1400,1310,50,20);
  DrawText(hDC,"�����ࣺ",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1950,1310,50,20);
  DrawText(hDC,"ʵ��Σ�",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1410,50,30);
  DrawText(hDC,"�ļ���",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1510,50,50);
  DrawText(hDC,"  ����: ",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,180,120,30,30);
  DrawText(hDC,"����",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,340,120,30,30);
  DrawText(hDC,"ѧ��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,510,120,50,30);
  DrawText(hDC,"�༶",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,710,120,50,30);
  DrawText(hDC,"��ѧ����",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,940,120,30,30);
  DrawText(hDC,"������",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1190,120,30,30);
  DrawText(hDC,"רҵ��",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1440,120,30,30);
  DrawText(hDC,"ѡ�޿�",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1690,120,30,30);
  DrawText(hDC,"���Ŀ�",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1940,120,30,30);
  DrawText(hDC,"ʵ���  ",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1440,1370,150,30);
  DrawText(hDC,"������ | רҵ�� | ѡ�޿� | ���Ŀ� | ʵ���",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  EndPaint(hWnd,&paint);
  return 0;
 case WM_CREATE:
        inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |WS_VSCROLL|ES_LEFT | ES_MULTILINE ,80,100,1000,450,hWnd,(HMENU)1,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*������ʾ���ݵ��ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,130,600,100,30,hWnd,(HMENU)9,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*����ѧ�ŵ��ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,370,600,100,30,hWnd,(HMENU)10,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*�����������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,650,600,50,30,hWnd,(HMENU)11,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*������ݵ��ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,750,600,50,30,hWnd,(HMENU)12,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*�����·ݵ��ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,850,600,50,30,hWnd,(HMENU)13,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*�������ڵ��ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,1015,600,120,30,hWnd,(HMENU)14,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*����༶���ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,150,650,50,30,hWnd,(HMENU)15,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*��������η������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,340,650,50,30,hWnd,(HMENU)16,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*����רҵ�η������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,540,650,50,30,hWnd,(HMENU)17,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*����ѡ�޿η������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,770,650,50,30,hWnd,(HMENU)18,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*�������Ŀη������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,1050,650,50,30,hWnd,(HMENU)19,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*����ʵ��η������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,150,710,280,30,hWnd,(HMENU)20,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*�����ļ������ı���*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,650,710,300,30,hWnd,(HMENU)22,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*��ʾƽ���ֵ��ı���*/
  btnHwnd = CreateWindow( "button", "ѧ����Ϣ",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,150,760,80,30,hWnd,(HMENU)2,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "��ѯѧ��",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,250,760,80,30,hWnd,(HMENU)4,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "�޸���Ϣ",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,350,760,80,30,hWnd,(HMENU)3,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "ɾ��",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,450,760,80,30,hWnd,(HMENU)5,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "����",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,550,760,80,30,hWnd,(HMENU)6,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "�ϸ����",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,650,760,80,30,hWnd,(HMENU)7,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "����",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,450,710,80,30,hWnd,(HMENU)8,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "�����Ϣ",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,750,760,80,30,hWnd,(HMENU)21,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "ƽ����",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,560,710,80,30,hWnd,(HMENU)23,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "���",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,990,710,80,30,hWnd,(HMENU)24,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  return 0 ;
  btnHwnd = CreateWindow( "button", "��",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,110,760,80,30,hWnd,(HMENU)25,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  return 0 ;
   case WM_COMMAND:
  {
   switch(LOWORD(wParam))
   {
   case 2: showmessage(hWnd);return 0;
   case 3: changemessage(hWnd);return 0;
   case 4: findoutmessage(hWnd);return 0;
   case 5: delmessage(hWnd);return 0;
   case 6: savefile(hWnd); return 0;
   case 7: leavestudent(hWnd);return 0;
   case 8: studentmessage(hWnd);return 0;
   case 21: joinmessage(hWnd);return 0;
   case 23: allaverage(hWnd);return 0;
   case 24: qingkong(hWnd);return 0;
   }
   return 0;
  }
    case WM_CLOSE:
    DestroyWindow(hWnd);
       return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd,Msg,wParam,lParam);
}
void studentmessage(HWND hWnd)/*���������ļ��ĺ���*/
{
 int n;
 char filename[100];
 GetDlgItemText(hWnd,20,filename,100);
 fp=fopen(filename,"r");
 if(fp==NULL)
 {
  MessageBox(hWnd,"�ļ��������ڣ��������","",MB_OK);
  return ;
 }
 tail=&head;
 p=head.next;
 head.next=NULL;
 while(!feof(fp))
 {
  p=(STU*)malloc(sizeof(STU));
  n=fscanf(fp,"%s%s%s%d/%d/%d%d%d%d%d%d",p->name,p->no,p->banji,&p->year,
  &p->month,&p->day,&p->score1,&p->score2,&p->score3,&p->score4,&p->score5);
  p->next=NULL;
  tail->next=p;
  tail=p;
 }
 MessageBox(hWnd,"�ļ�����ɹ���","",MB_OK);
 fclose(fp);
}
void showmessage(HWND hWnd)/*������ʾѧ��ѧ����Ϣ�ĺ���*/
{
 strcpy(end,"");
 p=head.next;
 while(p!=NULL)
 {
 sprintf(end,"%s%s\t%s\t%s\t%d/ %d/ %d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\r\n",end,p->name,p->no,p->banji,p->year,
   p->month,p->day,p->score1,p->score2,p->score3,p->score4,p->score5);
 p=p->next;
 }
SetDlgItemText(hWnd,1,end);
return ;
}
void findoutmessage(HWND hWnd)/*������ѯѧ����Ϣ�ĺ���*/
{
 char jiguo[5000]="";
 GetDlgItemText(hWnd,9,number,20);
 p=head.next;
 while(p!=NULL)
 {
 if(strcmp(number,p->no)==0)break;
 p=p->next;
 }
    if(p==NULL)
 {
  MessageBox(hWnd,"δ�ҵ���ѧ����ѧ����Ϣ","",MB_OK);
  return ;
 }
    SetDlgItemText(hWnd,1,"");
 sprintf(jiguo,"%s%s\t%s\t%s\t%d/ %d/ %d\t%d\t%d\t%d\t%d\t%d\t\r\n",jiguo,p->name,p->no,p->banji,p->year,p->month,p->day,
  p->score1,p->score2,p->score3,p->score4,p->score5);
 SetDlgItemText(hWnd,1,jiguo);
 /*SetDlgItemText(hWnd,10,p->name);
 ltoa(p->year,y,10);
 ltoa(p->month,m,10);
 ltoa(p->day,d,10);
 ltoa(p->score1,s1,10);
 ltoa(p->score2,s2,10);
 ltoa(p->score3,s3,10);
 ltoa(p->score4,s4,10);
 ltoa(p->score5,s5,10);
 SetDlgItemText(hWnd,11,y);
 SetDlgItemText(hWnd,12,m);
 SetDlgItemText(hWnd,13,d);
 SetDlgItemText(hWnd,14,p->banji);
 SetDlgItemText(hWnd,15,s1);
 SetDlgItemText(hWnd,16,s2);
 SetDlgItemText(hWnd,17,s3);
 SetDlgItemText(hWnd,18,s4);
 SetDlgItemText(hWnd,19,s5);*/
}
void changemessage(HWND hWnd)/*�����޸���Ϣ�ĺ���*/
{
 GetDlgItemText(hWnd,9,number,20);
 GetDlgItemText(hWnd,10,name,20);
 GetDlgItemText(hWnd,14,Class,20);
 GetDlgItemText(hWnd,11,y,10);
 GetDlgItemText(hWnd,12,m,10);
 GetDlgItemText(hWnd,13,d,10);
 GetDlgItemText(hWnd,15,s1,10);
 GetDlgItemText(hWnd,16,s2,10);
 GetDlgItemText(hWnd,17,s3,10);
 GetDlgItemText(hWnd,18,s4,10);
 GetDlgItemText(hWnd,19,s5,10);
    messagejy(hWnd);
 if(messagejy(hWnd)==1)
 return ;
 p=&head;
 while(p!=NULL)
 {
  if(strcmp(number,p->no)==0)
  {
  strcpy(p->no,number);
  strcpy(p->name,name);
        strcpy(p->banji,Class);
        p->year=atoi(y);
  p->month=atoi(m);
     p->day=atoi(d);
  p->score1=atoi(s1);
  p->score2=atoi(s2);
  p->score3=atoi(s3);
  p->score4=atoi(s4);
  p->score5=atoi(s5);
  MessageBox(hWnd,"�޸ĳɹ���","",MB_OK);
  showmessage(hWnd);
  return ;
  }
  p=p->next;
 }
 if(p==NULL)
 {
    MessageBox(hWnd,"��ѧ�Ų����ڣ�","",MB_OK);
 return ;
 }
}
void delmessage(HWND hWnd)/*����ɾ����Ϣ�ĺ���*/
{
 STU *pd;
 GetDlgItemText(hWnd,9,number,20);
 p=&head;
 while(p->next!=NULL)
 {
  if(strcmp(number,p->next->no)==0)
  {
   pd=p->next->next;
   free(p->next);
   p->next=pd;
            showmessage(hWnd);
   MessageBox(hWnd,"ɾ����Ϣ�ɹ���","",MB_OK);
   return ;
  }
  p=p->next;
    }
   if(p==NULL)
 {
    MessageBox(hWnd,"��ѧ�Ų����ڣ�","",MB_OK);
 return ;
   }
}
void savefile(HWND hWnd)/*���������ļ��ĺ���*/
{
 TCHAR strFileName[MAX_PATH] = "";
 OPENFILENAME ofn = { sizeof(OPENFILENAME),hWnd, NULL,  
  "�ı��ĵ�\0*.txt\0�����ļ�\0*.*\0\0", NULL,  
  0, 1, strFileName, MAX_PATH, NULL, 0, NULL,  
  TEXT("����"),  
  OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST |  
  OFN_HIDEREADONLY    | OFN_NOREADONLYRETURN,  
  0, 0, "txt", 0, NULL, NULL };  
 if(GetSaveFileName(&ofn))
 {
  FILE *fp;
  if((fp = fopen(strFileName, "w"))==NULL)
  {
   MessageBox(hWnd, "�ļ�����ʧ��", "��ʾ", MB_OK);
   return;
  }
  p=head.next;
  while(p!=NULL)
  {
   fprintf(fp, "%s\t%s\t%s\t%d/ %d/ %d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p->name,p->no,p->banji,p->year,
   p->month,p->day,p->score1,p->score2,p->score3,p->score4,p->score5);
   p = p->next;
  }
  fflush(fp);
  fclose(fp);
 }
}
void joinmessage(HWND hWnd)/*���������Ϣ�ĺ���*/
{  
 GetDlgItemText(hWnd,9,number,20);
 GetDlgItemText(hWnd,10,name,20);
 GetDlgItemText(hWnd,14,Class,20);
 GetDlgItemText(hWnd,11,y,10);
 GetDlgItemText(hWnd,12,m,10);
 GetDlgItemText(hWnd,13,d,10);
 GetDlgItemText(hWnd,15,s1,10);
 GetDlgItemText(hWnd,16,s2,10);
 GetDlgItemText(hWnd,17,s3,10);
 GetDlgItemText(hWnd,18,s4,10);
 GetDlgItemText(hWnd,19,s5,10);
 messagejy(hWnd);
 if(messagejy(hWnd)==1)
 return ;
 p=&head;
 while(p!=NULL)
 {
  if(strcmp(p->no,number)==0)
  {
         MessageBox(hWnd,"ѧ���Ѵ��ڣ�","",MB_OK);
   return ;
  }
  p=p->next;
 }
 p=(STU*)malloc(sizeof(STU));
 strcpy(p->no,number);
 strcpy(p->name,name);
 strcpy(p->banji,Class);
 p->year=atoi(y);
 p->month=atoi(m);
 p->day=atoi(d);
 p->score1=atoi(s1);
 p->score2=atoi(s2);
 p->score3=atoi(s3);
 p->score4=atoi(s4);
 p->score5=atoi(s5);
 p->next=NULL;
 tail->next=p;
 tail=p;
    showmessage(hWnd);
 MessageBox(hWnd,"�����Ϣ�ɹ���","",MB_OK);
 free(p);
 return ;
}
void leavestudent(HWND hWnd)/*������ʾ���Ա�ҵѧ���ĺ���*/
{
 char bye[5000]="";
 p=head.next;
    while(p!=NULL)
 {
  if(p->score1>=50&&p->score2>=50&&p->score3>=24&&p->score4>=8&&p->score5>=20)
  {
          sprintf(bye,"%s%s\t%s\t%s\t%d/ %d/ %d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\r\n",bye,p->name,p->no,p->banji,p->year,
   p->month,p->day,p->score1,p->score2,p->score3,p->score4,p->score5);
    p=p->next;
  }
  else p=p->next;
 }
strcmp(end,"");
SetDlgItemText(hWnd,1,bye);
}
void allaverage(HWND hWnd)/*����ͳ�Ƹ���Ŀƽ���ֵĺ���*/
{
int i=0;
float average1=0,average2=0,average3=0,average4=0,average5=0;
char scroe[5000]="";
p=head.next;
while(p!=NULL)
{
i++;
average1+=p->score1;
average2+=p->score2;
average3+=p->score3;
average4+=p->score4;
average5+=p->score5;
p=p->next;
}
sprintf(scroe,"%s%.2f\t%.2f\t%.2f\t%.2f\t%.2f",scroe,average1/i,average2/i,average3/i,average4/i,average5/i);
SetDlgItemText(hWnd,22,scroe);
return ;
}

int messagejy(HWND hWnd)/*����У����������ݵĺ���*/
{
    GetDlgItemText(hWnd,9,number,20);
    GetDlgItemText(hWnd,10,name,20);
    GetDlgItemText(hWnd,14,Class,20);
    GetDlgItemText(hWnd,11,y,10);
    GetDlgItemText(hWnd,12,m,10);
    GetDlgItemText(hWnd,13,d,10);
    GetDlgItemText(hWnd,15,s1,10);
    GetDlgItemText(hWnd,16,s2,10);
    GetDlgItemText(hWnd,17,s3,10);
    GetDlgItemText(hWnd,18,s4,10);
    GetDlgItemText(hWnd,19,s5,10);
    if(atoi(y)<1970||atoi(y)>2017)
 {
 MessageBox(hWnd,"�����������","",MB_OK);
  return 1;
 }
 if(atoi(m)<1||atoi(m)>12)
 {
 MessageBox(hWnd,"�·���������","",MB_OK);
  return 1;
 }
 if((atoi(m)==4||atoi(m)==6||atoi(m)==9||atoi(m)==11)&&(atoi(d)<1&&atoi(d)>30))
 {
 MessageBox(hWnd,"������������","",MB_OK);
  return 1;
 }
 if(atoi(d)<1||atoi(d)>31)
 {
 MessageBox(hWnd,"������������","",MB_OK);
  return 1;
 }
 if(atoi(m)==2)
 {
  if((atoi(y)%4==0&&atoi(y)%100!=0)||atoi(y)%400==0)
  {
   if((atoi(d)<1)||(atoi(d)>29))
   {
    MessageBox(hWnd,"������������","",MB_OK);
    return 1;
   }
  }
  else if((atoi(d)<1)||(atoi(d)>28))
  {
   MessageBox(hWnd,"������������","",MB_OK);
    return 1;
  }
 }
 if((atoi(s1)<0||atoi(s1)>100)||(atoi(s2)<0||atoi(s2)>100)||(atoi(s3)<0||atoi(s3)>100)||(atoi(s4)<0||atoi(s4)>100)||(atoi(s5)<0||atoi(s5)>100))
 {
  MessageBox(hWnd,"ѧ����Ϣ����","",MB_OK);
  return 1;
 }
}
void qingkong(HWND hWnd)
{
 SetDlgItemText(hWnd,9,"");
 SetDlgItemText(hWnd,10,"");
 SetDlgItemText(hWnd,11,"");
 SetDlgItemText(hWnd,12,"");
 SetDlgItemText(hWnd,13,"");
 SetDlgItemText(hWnd,14,"");
 SetDlgItemText(hWnd,15,"");
 SetDlgItemText(hWnd,16,"");
 SetDlgItemText(hWnd,17,"");
 SetDlgItemText(hWnd,18,"");
 SetDlgItemText(hWnd,19,"");
 SetDlgItemText(hWnd,1,"");
 SetDlgItemText(hWnd,22,"");
 return ;
}