#include<windows.h>
#include<windowsx.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
LRESULT WINAPI WinProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam);
void studentmessage(HWND hWnd);/*用来导入文件的函数*/
void showmessage(HWND hWnd);/*用来显示学生学分信息的函数*/
void findoutmessage(HWND hWnd);/*用来查询学分信息的函数*/
void changemessage(HWND hWnd);/*用来修改信息的函数*/
void delmessage(HWND hWnd);/*用来删除信息的函数*/
void savefile(HWND hWnd);/*用来保存文件的函数*/
void joinmessage(HWND hWnd);/*用来添加信息的函数*/
void leavestudent(HWND hWnd);/*用来显示可以毕业学生的函数*/
int messagejy(HWND hWnd);/*用来校验输入的数据的函数*/
void allaverage(HWND hWnd);/*用来统计各科目平均分的函数*/
void qingkong(HWND hWnd);/*用来清空文本框的函数*/
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
    hWnd = CreateWindow(cName,"学分管理系统",WS_OVERLAPPEDWINDOW,50,100,1200,900,NULL,NULL,hInstance,NULL) ;
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
  DrawText(hDC,"欢迎使用学分管理系统！",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1200,50,30);
  DrawText(hDC,"学号：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,630,1200,50,30);
  DrawText(hDC,"姓名：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1150,1200,50,30);
  DrawText(hDC,"入学时间：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1920,1200,50,30);
  DrawText(hDC,"班级：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1450,1210,20,20);
  DrawText(hDC,"年",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1650,1210,20,20);
  DrawText(hDC,"月",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1840,1210,20,20);
  DrawText(hDC,"日",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1310,50,20);
  DrawText(hDC,"基础课:",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,550,1310,50,20);
  DrawText(hDC,"专业课：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,950,1310,50,20);
  DrawText(hDC,"选修课：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1400,1310,50,20);
  DrawText(hDC,"人文类：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1950,1310,50,20);
  DrawText(hDC,"实验课：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1410,50,30);
  DrawText(hDC,"文件：",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,150,1510,50,50);
  DrawText(hDC,"  操作: ",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,180,120,30,30);
  DrawText(hDC,"姓名",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,340,120,30,30);
  DrawText(hDC,"学号",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,510,120,50,30);
  DrawText(hDC,"班级",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,710,120,50,30);
  DrawText(hDC,"入学日期",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,940,120,30,30);
  DrawText(hDC,"基本课",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1190,120,30,30);
  DrawText(hDC,"专业课",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1440,120,30,30);
  DrawText(hDC,"选修课",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1690,120,30,30);
  DrawText(hDC,"人文课",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1940,120,30,30);
  DrawText(hDC,"实验课  ",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  SetRect(&rect,1440,1370,150,30);
  DrawText(hDC,"基础课 | 专业课 | 选修课 | 人文课 | 实验课",-1,&rect,DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  EndPaint(hWnd,&paint);
  return 0;
 case WM_CREATE:
        inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |WS_VSCROLL|ES_LEFT | ES_MULTILINE ,80,100,1000,450,hWnd,(HMENU)1,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*用来显示数据的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,130,600,100,30,hWnd,(HMENU)9,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入学号的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,370,600,100,30,hWnd,(HMENU)10,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入姓名的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,650,600,50,30,hWnd,(HMENU)11,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入年份的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,750,600,50,30,hWnd,(HMENU)12,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入月份的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,850,600,50,30,hWnd,(HMENU)13,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入日期的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,1015,600,120,30,hWnd,(HMENU)14,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入班级的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,150,650,50,30,hWnd,(HMENU)15,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入基础课分数的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,340,650,50,30,hWnd,(HMENU)16,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入专业课分数的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,540,650,50,30,hWnd,(HMENU)17,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入选修课分数的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,770,650,50,30,hWnd,(HMENU)18,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入人文课分数的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,1050,650,50,30,hWnd,(HMENU)19,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入实验课分数的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,150,710,280,30,hWnd,(HMENU)20,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*输入文件名的文本框*/
  inputHwnd = CreateWindow( "edit", NULL,
  WS_CHILD | WS_VISIBLE  | WS_BORDER |ES_LEFT | ES_MULTILINE ,650,710,300,30,hWnd,(HMENU)22,((LPCREATESTRUCT) lParam) -> hInstance,
   NULL ) ;/*显示平均分的文本框*/
  btnHwnd = CreateWindow( "button", "学分信息",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,150,760,80,30,hWnd,(HMENU)2,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "查询学分",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,250,760,80,30,hWnd,(HMENU)4,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "修改信息",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,350,760,80,30,hWnd,(HMENU)3,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "删除",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,450,760,80,30,hWnd,(HMENU)5,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "保存",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,550,760,80,30,hWnd,(HMENU)6,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "合格情况",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,650,760,80,30,hWnd,(HMENU)7,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "导入",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,450,710,80,30,hWnd,(HMENU)8,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "添加信息",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,750,760,80,30,hWnd,(HMENU)21,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "平均分",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,560,710,80,30,hWnd,(HMENU)23,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  btnHwnd = CreateWindow( "button", "清空",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,990,710,80,30,hWnd,(HMENU)24,
   (HINSTANCE) GetWindowLong(hWnd, GWL_HINSTANCE ),
   NULL ) ;
  return 0 ;
  btnHwnd = CreateWindow( "button", "：",
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
void studentmessage(HWND hWnd)/*用来导入文件的函数*/
{
 int n;
 char filename[100];
 GetDlgItemText(hWnd,20,filename,100);
 fp=fopen(filename,"r");
 if(fp==NULL)
 {
  MessageBox(hWnd,"文件名不存在，导入错误！","",MB_OK);
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
 MessageBox(hWnd,"文件导入成功！","",MB_OK);
 fclose(fp);
}
void showmessage(HWND hWnd)/*用来显示学生学分信息的函数*/
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
void findoutmessage(HWND hWnd)/*用来查询学分信息的函数*/
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
  MessageBox(hWnd,"未找到该学生的学分信息","",MB_OK);
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
void changemessage(HWND hWnd)/*用来修改信息的函数*/
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
  MessageBox(hWnd,"修改成功！","",MB_OK);
  showmessage(hWnd);
  return ;
  }
  p=p->next;
 }
 if(p==NULL)
 {
    MessageBox(hWnd,"该学号不存在！","",MB_OK);
 return ;
 }
}
void delmessage(HWND hWnd)/*用来删除信息的函数*/
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
   MessageBox(hWnd,"删除信息成功！","",MB_OK);
   return ;
  }
  p=p->next;
    }
   if(p==NULL)
 {
    MessageBox(hWnd,"该学号不存在！","",MB_OK);
 return ;
   }
}
void savefile(HWND hWnd)/*用来保存文件的函数*/
{
 TCHAR strFileName[MAX_PATH] = "";
 OPENFILENAME ofn = { sizeof(OPENFILENAME),hWnd, NULL,  
  "文本文档\0*.txt\0所有文件\0*.*\0\0", NULL,  
  0, 1, strFileName, MAX_PATH, NULL, 0, NULL,  
  TEXT("保存"),  
  OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST |  
  OFN_HIDEREADONLY    | OFN_NOREADONLYRETURN,  
  0, 0, "txt", 0, NULL, NULL };  
 if(GetSaveFileName(&ofn))
 {
  FILE *fp;
  if((fp = fopen(strFileName, "w"))==NULL)
  {
   MessageBox(hWnd, "文件保存失败", "提示", MB_OK);
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
void joinmessage(HWND hWnd)/*用来添加信息的函数*/
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
         MessageBox(hWnd,"学号已存在！","",MB_OK);
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
 MessageBox(hWnd,"添加信息成功！","",MB_OK);
 free(p);
 return ;
}
void leavestudent(HWND hWnd)/*用来显示可以毕业学生的函数*/
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
void allaverage(HWND hWnd)/*用来统计各科目平均分的函数*/
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

int messagejy(HWND hWnd)/*用来校验输入的数据的函数*/
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
 MessageBox(hWnd,"年份输入有误！","",MB_OK);
  return 1;
 }
 if(atoi(m)<1||atoi(m)>12)
 {
 MessageBox(hWnd,"月份输入有误！","",MB_OK);
  return 1;
 }
 if((atoi(m)==4||atoi(m)==6||atoi(m)==9||atoi(m)==11)&&(atoi(d)<1&&atoi(d)>30))
 {
 MessageBox(hWnd,"日期输入有误！","",MB_OK);
  return 1;
 }
 if(atoi(d)<1||atoi(d)>31)
 {
 MessageBox(hWnd,"日期输入有误！","",MB_OK);
  return 1;
 }
 if(atoi(m)==2)
 {
  if((atoi(y)%4==0&&atoi(y)%100!=0)||atoi(y)%400==0)
  {
   if((atoi(d)<1)||(atoi(d)>29))
   {
    MessageBox(hWnd,"日期输入有误！","",MB_OK);
    return 1;
   }
  }
  else if((atoi(d)<1)||(atoi(d)>28))
  {
   MessageBox(hWnd,"日期输入有误！","",MB_OK);
    return 1;
  }
 }
 if((atoi(s1)<0||atoi(s1)>100)||(atoi(s2)<0||atoi(s2)>100)||(atoi(s3)<0||atoi(s3)>100)||(atoi(s4)<0||atoi(s4)>100)||(atoi(s5)<0||atoi(s5)>100))
 {
  MessageBox(hWnd,"学分信息有误！","",MB_OK);
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