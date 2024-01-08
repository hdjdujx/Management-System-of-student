#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
#pragma warning (disable: 4996)
#define Len 100

typedef struct
{
	float sx;//数学
	float dy;//大英
	float sz;//思政
	float sm;//总成绩
}Score;
typedef struct
{
	char xh[4];
	char xm[16];
	char xb[5];
	Score all;
}Student;
void Add(FILE*fp);//添加信息
void Rea(FILE*fp);//读取信息
void Del(FILE* fp);//删除信息
void Mot(FILE* fp);//修改信息
void Hel();      //打印使用说明
void Sor(FILE* fp);
int Meanu1();    //教师菜单    可用于添加信息
int Meanu2();    //学生菜单    只可用于查询信息 

int  Login();
void ss();
long bd(FILE *fp);

int main()
{
	int (*Meanu)();  //定义函数指针，用于指向两个菜单函数

	FILE* fp1;           //设置指向要打开文件的的文件指针的全局变量
	if ((fp1 = fopen("8.txt", "w+")) == NULL)
	{
		printf("ERROR! 系统运行异常！");
		exit(EXIT_FAILURE);
	}
	int a=0;
	while (a != 8)
	{ 
		a = Login();
		switch (a)
		{
		case 1:Meanu=Meanu1; break;     //函数指针指向教师菜单
		case 2:Meanu=Meanu2; break;		//函数指针指向学生菜单
		case 3:exit(0);                 //在登陆界面直接退出系统
		}
		while (a!=7 && a!=8)					//如果用户选择退出菜单返回登录界面或者退出系统
		{
			a = Meanu();
			if (a != 7 && a != 8)				//判断：如果选择退出菜单或系统将不参与一下循环
			{
				switch (a)
				{
				case 1:Hel(fp1); break;				//查看帮助
				case 2:Add(fp1); break;				//添加信息 
				case 3:Del(fp1); fp1 = fopen("8.txt", "r+"); break;				//删除信息  修改fp1指向的文件
				case 4:Rea(fp1); break;				//读取信息
				case 5:Mot(fp1); break;				//修改信息
				case 6:Sor(fp1); break;				//排序信息
				}
				Sleep(2000);						//2000ms=2s
			}
			
			system("cls");
		}
	}
	fclose(fp1);
	return 0;
}
void ss()
{
	int y = 0;
	while (y != 1)
	{

		scanf_s("%d", &y);
		if (y ==1 )  printf("页面将在2秒后自动关闭");
		else printf("关闭该页面请输入1\n");
	}
}
//首先寻找字符“*”再对比学号
long bd(FILE *fp)
{
	rewind(fp);   //每次查询都要从头开始 否则指针的位置在后面 要查的东西在前面就无法正常读取
	char per[4] = { '\0' };
	getchar();
	fgets(per,4,stdin);
	char sdr[4] = { '\0' };
	char o='\0';
	int q = 1;
	long l = 0L;
	while (q != 0)
	{
		while (o != '*')
		{
			o = getc(fp);
			if (o == EOF)break;
		}
		if (o == EOF)
		{
			l = 0L;
			return l;
		}
		l = ftell(fp);           
		fgets(sdr, 4, fp);
		q = strcmp(sdr, per);
		o = '\0';
	}
	return l;
}
int Login()
{
	printf("欢迎来到学生信息管理系统登录页面\n");
	printf("教师登录请输入1\n");
	printf("学生登录请输入2\n");
	printf("退出系统请输入3\n");
	printf("提示：输入数字完成登录或退出程序\n");
	int a = 0;
	for (; a < 1 || a>3;)
	{
		scanf("%d", &a);
		if (a >= 1 && a <= 3) break;
		else printf("\n输入错误！请输入1到3之间的整数\n");
	}
	return a;
}
int  Meanu1()
{
	printf("*********学生管理系统菜单***********\n");
	printf("***********1.查看帮助  *************\n");
	printf("***********2.添加学生信息***********\n");
	printf("***********3.删除信息    ***********\n");
	printf("***********4.查询学生信息***********\n");
	printf("***********5.修改信息    ***********\n");
	printf("***********6.获取成绩排名***********\n");
	printf("***********7.退出当前菜单***********\n");
	printf("***********8.直接退出系统***********\n");
	printf("提示：输入菜单项目前的序号，进入相关页面\n");
	int a = 0;
	for (; a < 1 || a>8;)
	{
		scanf_s("%d", &a);
		if (a >= 1 && a <= 8) break;
		else printf("\n输入错误！请输入1到8之间的整数\n");
	}
	return a;
}
int Meanu2()
{
	printf("*********学生管理系统菜单***********\n");
	printf("***********1.查看帮助  *************\n");
	printf("***********2.查询成绩    ***********\n");
	printf("***********3.退出当前菜单***********\n");
	printf("***********4直接退出系统************\n");
	int a = 0;
	for (; a < 1 || a>4;)
	{
		scanf_s("%d", &a);
		if (a >= 1 && a <= 4) break;
		else printf("\n输入错误！请输入1到4之间的整数\n");
	}
	switch (a)
	{
	case 2:a = 4; break;
	case 3:a = 7; break;
	case 4:a = 8; break;
	}
	return a;
}

void Hel()
{
	printf("学生信息管理系统使用说明如下：\n");
	printf("1根据菜单输入每一项功能前的数字即可进入相关功能界面\n");
	printf("2完成相应功能后可选择返回到登录界面也可直接退出系统\n");
	printf("3注意！要实现相关功能要严格按照指示进行操作\n");
	printf("4注意！若是运行该程序，请先添加信息，再查询修改或删除信息\n");
	printf("关闭帮助请输入1\n");
	ss();
}
void Add(FILE* fp)
{
	printf("*********添加学生信息**********\n");
	printf("提示根据现实输入合适的数据\n");
	Student per[Len] =
	{ [0] =
		{
			.xh = "\0",
			.xm = "\0",
			.xb = "\0",
			.all.sx=0.00,
			.all.dy=0.00,
			.all.sz=0.00,
			.all.sm=0.00,


		}
	};
	int i = 0;
	int m = 1;
	static long l = 0L;
	fseek(fp, l,SEEK_SET);//使用静态局部变量，使得再次选择添加信息功能时，文件指针会停在上次输入的末尾，
	for (i = 0; m==1; i++)
	{
		getchar();
		printf("学号eg:001到999\n:");
		gets(per[i].xh);
		printf("姓名eg:张三\n:");
		fgets(per[i].xm, 16, stdin);
		printf("性别eg:男/女\n:");
		fgets(per[i].xb, 5, stdin);
		printf("微积分eg:0.00~100.00\n:");
		int o = 0;
		while (o != 1)
		{
			
			o = scanf_s("%f", &(per[i].all.sx));
			if (o == 1)break;
			else printf("输入的数据错误，请重新输入！");
		}
		o = 0;
		printf("大学英语eg:0.00~100.00\n:");
		while (o != 1)
		{
			
			o = scanf_s("%f", &(per[i].all.dy));
			if (o == 1)break;
			else printf("输入的数据错误，请重新输入！");
		}
		o = 0;
		printf("军理eg:0.00~100.00\n:");
		while (o != 1)
		{
			
			o = scanf_s("%f", &(per[i].all.sz));
			if (o == 1)break;
			else printf("输入的数据错误，请重新输入！");
		}
		o = 0;
		per[i].all.sm = per[i].all.dy + per[i].all.sx + per[i].all.sz;
		int q = 0;
		
		while (o != 1)
		{
		
			printf("该同学的信息已完成录入，是否确认保存？确认保存输入1，其他任意数字取消保存\n");
        	o=scanf_s("%d", &q);
		}
		if (q == 1)
		{
		
			fprintf(fp, "*%s %s %s %.2f %.2f %.2f %.2f\n", per[i].xh, per[i].xm, per[i].xb, per[i].all.sx, per[i].all.dy, per[i].all.sz, per[i].all.sm);
		}
		else  i--;
		o = 0;
		while ( o != 1)
		{
			
			printf("是否继续录入学生信息，继续录入请输入1，输入任意的数字结束\n");
			o=scanf_s("%d", &m);
		}
 	}
	l = ftell(fp);
	printf("此页面将于2秒后自动关闭\n");
}
void Rea(FILE* fp)
{
	Student per;
	long l = 0L;
	printf("输入要查询学生信息的学号:\n");
	l = bd(fp);
	if (l == 0L) printf("查询不到该学生的信息");
	else {
		fseek(fp, l, SEEK_SET);
		fscanf(fp, "%s %s %s %f %f %f %f", per.xh, per.xm, per.xb, &per.all.sx, &per.all.dy, &per.all.sz, &per.all.sm);
		printf("学号：%s	姓名： %s	性别： %s	微积分： %.2f	大学英语： %.2f		军理： %.2f		总分： %.2f", per.xh, per.xm, per.xb, per.all.sx, per.all.dy, per.all.sz, per.all.sm);
	}
	printf("\n关闭查询页面请输入1\n");
	ss();

}
void Del(FILE* fp)
{ 
	FILE* ft;
	Student per =
	{
			.xh = "\0",
			.xm = "\0",
			.xb = "\0",
			.all.sx = 0.00,
			.all.dy = 0.00,
			.all.sz = 0.00,
			.all.sm = 0.00,
	};
	if ((ft = fopen("new.txt", "w+")) == NULL)
	{
		printf("新文件创建失败！");
		exit(EXIT_FAILURE);
	}
	printf("请输入要删除信息的学生的学号:\n");//通过学号找到文件中存储该学生的信息的位置
	rewind(fp);   //每次查询都要从头开始 否则指针的位置在后面 要查的东西在前面就无法正常读取
	char oer[4] = { '\0' };
	getchar();
	fgets(oer, 4, stdin);
	char sdr[4] = { '\0' };
	char o = '\0';
	int q = 0;
	long l = 0L;
	while (TRUE)
	{
		do
		{
			o = getc(fp);
		} while (o != '*'&&o!=EOF);
		if (o == EOF) break;
		l = ftell(fp);
		fgets(sdr, 4, fp);
		if ((q = strcmp(sdr, oer)) != 0)
		{
			fseek(fp, l, SEEK_SET);
			fscanf(fp, "%s %s %s %f %f %f %f", per.xh, per.xm, per.xb, &per.all.sx, &per.all.dy, &per.all.sz, &per.all.sm);
			fprintf(ft,"*%s %s %s %.2f %.2f %.2f %.2f\n", per.xh, per.xm, per.xb, per.all.sx, per.all.dy, per.all.sz, per.all.sm);
		}
		o = '\0';
	}
	fclose(fp);
	fclose(ft);
	remove("8.txt");
	if(rename("new.txt", "8.txt")==0);
	fp = fopen("8.txt", "r+");
	printf("删除成功！\n");
	printf("关闭删除页面请输入1\n");
	ss();

}
void Mot(FILE* fp)
{
	printf("请输入要修改信息的学生的学号");
	long l = 0L;
	l = bd(fp);
	fseek(fp, l, SEEK_SET);
	Student per =
	{
			.xh = "\0",
			.xm = "\0",
			.xb = "\0",
			.all.sx = 0.00,
			.all.dy = 0.00,
			.all.sz = 0.00,
			.all.sm = 0.00,
	};
	getchar();
	printf("学号eg:001到999\n:");
	gets(per.xh);
	printf("姓名eg:张三\n:");
	fgets(per.xm, 16, stdin);
	printf("性别eg:男/女\n:");
	fgets(per.xb, 5, stdin);
	printf("微积分eg:0.00~100.00\n:");
	int o = 0;
	while (o != 1)
	{

		o = scanf_s("%f", &(per.all.sx));
		if (o == 1)break;
		else printf("输入的数据错误，请重新输入！");
	}
	o = 0;
	printf("大学英语eg:0.00~100.00\n:");
	while (o != 1)
	{

		o = scanf_s("%f", &(per.all.dy));
		if (o == 1)break;
		else printf("输入的数据错误，请重新输入！");
	}
	o = 0;
	printf("思政eg:0.00~100.00\n:");
	while (o != 1)
	{

		o = scanf_s("%f", &(per.all.sz));
		if (o == 1)break;
		else printf("输入的数据错误，请重新输入！");
	}
	o = 0;
	per.all.sm = per.all.dy + per.all.sx + per.all.sz;
	int q = 0;

	while (o != 1)
	{

		printf("该同学的信息已完成录入，是否确认保存修改？确认保存输入1，其他任意数字取消保存\n");
		o = scanf_s("%d", &q);
	}
	if (q == 1)
	{

		fprintf(fp, "%s %s %s %.2f %.2f %.2f %.2f", per.xh, per.xm, per.xb, per.all.sx, per.all.dy, per.all.sz, per.all.sm);
	}
	printf("\n关闭修改页面请输入1\n");
	ss();
}
typedef struct
{
	int i;			//位置
	float sm;		//总成绩
}Px;
void Sor(FILE* fp)
{
	rewind(fp);
	Student per[100] =
	{
		[0] =
		{.xh = "\0",
		.xm = "\0",
		.xb = "\0",
		.all.sx = 0.00,
		.all.dy = 0.00,
		.all.sz = 0.00,
		.all.sm=0.00,
	    }
	};//定义一个结构体并初始化
	Px k[100]=
	{
		[0] =
		{
			.i = 0,
			.sm = 0.00,
			}
	};
	long l = 0L;
	int i = 0;
	char o = '\0';
	for (i = 0;; i++)
	{
		do
		{
			o = getc(fp);
		} while (o != '*' && o != EOF);
		if (o == EOF) break;
			fscanf(fp, "%s %s %s %f %f %f %f", per[i].xh, per[i].xm, per[i].xb, &per[i].all.sx, &per[i].all.dy, &per[i].all.sz, &per[i].all.sm);
	}
	
	for (int j = 0; j < i; j++)
	{
		k[j].i = j;
		k[j].sm = per[j].all.sm;
	}
	for (int h = 0; h < i-1; h++)
	{
		for (int t = 0; t < i-1 - h; t++)
		{
			int a=0;
			float b=0.00;
			if (k[t].sm > k[t+1].sm)
			{
				b = k[t].sm;
				k[t].sm = k[t + 1].sm;
				k[t + 1].sm = b;
				a = k[t].i;
				k[t].i = k[t + 1].i;
				k[t + 1].i = a;
			}
		}
	}
	//按总成绩由小到大的顺序将学生信息输出到终端
	for (int c = 0; c < i; c++)
	{
		int v = k[c].i;
		printf(" %s %s %s %f %f %f %f\n", per[v].xh, per[v].xm, per[v].xb, per[v].all.sx, per[v].all.dy, per[v].all.sz, per[v].all.sm);
	}
	printf("\n关闭界面输入1：\n");
	ss();
}
