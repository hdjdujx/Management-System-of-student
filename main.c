#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
#pragma warning (disable: 4996)
#define Len 100

typedef struct
{
	float sx;//��ѧ
	float dy;//��Ӣ
	float sz;//˼��
	float sm;//�ܳɼ�
}Score;
typedef struct
{
	char xh[4];
	char xm[16];
	char xb[5];
	Score all;
}Student;
void Add(FILE*fp);//�����Ϣ
void Rea(FILE*fp);//��ȡ��Ϣ
void Del(FILE* fp);//ɾ����Ϣ
void Mot(FILE* fp);//�޸���Ϣ
void Hel();      //��ӡʹ��˵��
void Sor(FILE* fp);
int Meanu1();    //��ʦ�˵�    �����������Ϣ
int Meanu2();    //ѧ���˵�    ֻ�����ڲ�ѯ��Ϣ 

int  Login();
void ss();
long bd(FILE *fp);

int main()
{
	int (*Meanu)();  //���庯��ָ�룬����ָ�������˵�����

	FILE* fp1;           //����ָ��Ҫ���ļ��ĵ��ļ�ָ���ȫ�ֱ���
	if ((fp1 = fopen("8.txt", "w+")) == NULL)
	{
		printf("ERROR! ϵͳ�����쳣��");
		exit(EXIT_FAILURE);
	}
	int a=0;
	while (a != 8)
	{ 
		a = Login();
		switch (a)
		{
		case 1:Meanu=Meanu1; break;     //����ָ��ָ���ʦ�˵�
		case 2:Meanu=Meanu2; break;		//����ָ��ָ��ѧ���˵�
		case 3:exit(0);                 //�ڵ�½����ֱ���˳�ϵͳ
		}
		while (a!=7 && a!=8)					//����û�ѡ���˳��˵����ص�¼��������˳�ϵͳ
		{
			a = Meanu();
			if (a != 7 && a != 8)				//�жϣ����ѡ���˳��˵���ϵͳ��������һ��ѭ��
			{
				switch (a)
				{
				case 1:Hel(fp1); break;				//�鿴����
				case 2:Add(fp1); break;				//�����Ϣ 
				case 3:Del(fp1); fp1 = fopen("8.txt", "r+"); break;				//ɾ����Ϣ  �޸�fp1ָ����ļ�
				case 4:Rea(fp1); break;				//��ȡ��Ϣ
				case 5:Mot(fp1); break;				//�޸���Ϣ
				case 6:Sor(fp1); break;				//������Ϣ
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
		if (y ==1 )  printf("ҳ�潫��2����Զ��ر�");
		else printf("�رո�ҳ��������1\n");
	}
}
//����Ѱ���ַ���*���ٶԱ�ѧ��
long bd(FILE *fp)
{
	rewind(fp);   //ÿ�β�ѯ��Ҫ��ͷ��ʼ ����ָ���λ���ں��� Ҫ��Ķ�����ǰ����޷�������ȡ
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
	printf("��ӭ����ѧ����Ϣ����ϵͳ��¼ҳ��\n");
	printf("��ʦ��¼������1\n");
	printf("ѧ����¼������2\n");
	printf("�˳�ϵͳ������3\n");
	printf("��ʾ������������ɵ�¼���˳�����\n");
	int a = 0;
	for (; a < 1 || a>3;)
	{
		scanf("%d", &a);
		if (a >= 1 && a <= 3) break;
		else printf("\n�������������1��3֮�������\n");
	}
	return a;
}
int  Meanu1()
{
	printf("*********ѧ������ϵͳ�˵�***********\n");
	printf("***********1.�鿴����  *************\n");
	printf("***********2.���ѧ����Ϣ***********\n");
	printf("***********3.ɾ����Ϣ    ***********\n");
	printf("***********4.��ѯѧ����Ϣ***********\n");
	printf("***********5.�޸���Ϣ    ***********\n");
	printf("***********6.��ȡ�ɼ�����***********\n");
	printf("***********7.�˳���ǰ�˵�***********\n");
	printf("***********8.ֱ���˳�ϵͳ***********\n");
	printf("��ʾ������˵���Ŀǰ����ţ��������ҳ��\n");
	int a = 0;
	for (; a < 1 || a>8;)
	{
		scanf_s("%d", &a);
		if (a >= 1 && a <= 8) break;
		else printf("\n�������������1��8֮�������\n");
	}
	return a;
}
int Meanu2()
{
	printf("*********ѧ������ϵͳ�˵�***********\n");
	printf("***********1.�鿴����  *************\n");
	printf("***********2.��ѯ�ɼ�    ***********\n");
	printf("***********3.�˳���ǰ�˵�***********\n");
	printf("***********4ֱ���˳�ϵͳ************\n");
	int a = 0;
	for (; a < 1 || a>4;)
	{
		scanf_s("%d", &a);
		if (a >= 1 && a <= 4) break;
		else printf("\n�������������1��4֮�������\n");
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
	printf("ѧ����Ϣ����ϵͳʹ��˵�����£�\n");
	printf("1���ݲ˵�����ÿһ���ǰ�����ּ��ɽ�����ع��ܽ���\n");
	printf("2�����Ӧ���ܺ��ѡ�񷵻ص���¼����Ҳ��ֱ���˳�ϵͳ\n");
	printf("3ע�⣡Ҫʵ����ع���Ҫ�ϸ���ָʾ���в���\n");
	printf("4ע�⣡�������иó������������Ϣ���ٲ�ѯ�޸Ļ�ɾ����Ϣ\n");
	printf("�رհ���������1\n");
	ss();
}
void Add(FILE* fp)
{
	printf("*********���ѧ����Ϣ**********\n");
	printf("��ʾ������ʵ������ʵ�����\n");
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
	fseek(fp, l,SEEK_SET);//ʹ�þ�̬�ֲ�������ʹ���ٴ�ѡ�������Ϣ����ʱ���ļ�ָ���ͣ���ϴ������ĩβ��
	for (i = 0; m==1; i++)
	{
		getchar();
		printf("ѧ��eg:001��999\n:");
		gets(per[i].xh);
		printf("����eg:����\n:");
		fgets(per[i].xm, 16, stdin);
		printf("�Ա�eg:��/Ů\n:");
		fgets(per[i].xb, 5, stdin);
		printf("΢����eg:0.00~100.00\n:");
		int o = 0;
		while (o != 1)
		{
			
			o = scanf_s("%f", &(per[i].all.sx));
			if (o == 1)break;
			else printf("��������ݴ������������룡");
		}
		o = 0;
		printf("��ѧӢ��eg:0.00~100.00\n:");
		while (o != 1)
		{
			
			o = scanf_s("%f", &(per[i].all.dy));
			if (o == 1)break;
			else printf("��������ݴ������������룡");
		}
		o = 0;
		printf("����eg:0.00~100.00\n:");
		while (o != 1)
		{
			
			o = scanf_s("%f", &(per[i].all.sz));
			if (o == 1)break;
			else printf("��������ݴ������������룡");
		}
		o = 0;
		per[i].all.sm = per[i].all.dy + per[i].all.sx + per[i].all.sz;
		int q = 0;
		
		while (o != 1)
		{
		
			printf("��ͬѧ����Ϣ�����¼�룬�Ƿ�ȷ�ϱ��棿ȷ�ϱ�������1��������������ȡ������\n");
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
			
			printf("�Ƿ����¼��ѧ����Ϣ������¼��������1��������������ֽ���\n");
			o=scanf_s("%d", &m);
		}
 	}
	l = ftell(fp);
	printf("��ҳ�潫��2����Զ��ر�\n");
}
void Rea(FILE* fp)
{
	Student per;
	long l = 0L;
	printf("����Ҫ��ѯѧ����Ϣ��ѧ��:\n");
	l = bd(fp);
	if (l == 0L) printf("��ѯ������ѧ������Ϣ");
	else {
		fseek(fp, l, SEEK_SET);
		fscanf(fp, "%s %s %s %f %f %f %f", per.xh, per.xm, per.xb, &per.all.sx, &per.all.dy, &per.all.sz, &per.all.sm);
		printf("ѧ�ţ�%s	������ %s	�Ա� %s	΢���֣� %.2f	��ѧӢ� %.2f		���� %.2f		�ܷ֣� %.2f", per.xh, per.xm, per.xb, per.all.sx, per.all.dy, per.all.sz, per.all.sm);
	}
	printf("\n�رղ�ѯҳ��������1\n");
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
		printf("���ļ�����ʧ�ܣ�");
		exit(EXIT_FAILURE);
	}
	printf("������Ҫɾ����Ϣ��ѧ����ѧ��:\n");//ͨ��ѧ���ҵ��ļ��д洢��ѧ������Ϣ��λ��
	rewind(fp);   //ÿ�β�ѯ��Ҫ��ͷ��ʼ ����ָ���λ���ں��� Ҫ��Ķ�����ǰ����޷�������ȡ
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
	printf("ɾ���ɹ���\n");
	printf("�ر�ɾ��ҳ��������1\n");
	ss();

}
void Mot(FILE* fp)
{
	printf("������Ҫ�޸���Ϣ��ѧ����ѧ��");
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
	printf("ѧ��eg:001��999\n:");
	gets(per.xh);
	printf("����eg:����\n:");
	fgets(per.xm, 16, stdin);
	printf("�Ա�eg:��/Ů\n:");
	fgets(per.xb, 5, stdin);
	printf("΢����eg:0.00~100.00\n:");
	int o = 0;
	while (o != 1)
	{

		o = scanf_s("%f", &(per.all.sx));
		if (o == 1)break;
		else printf("��������ݴ������������룡");
	}
	o = 0;
	printf("��ѧӢ��eg:0.00~100.00\n:");
	while (o != 1)
	{

		o = scanf_s("%f", &(per.all.dy));
		if (o == 1)break;
		else printf("��������ݴ������������룡");
	}
	o = 0;
	printf("˼��eg:0.00~100.00\n:");
	while (o != 1)
	{

		o = scanf_s("%f", &(per.all.sz));
		if (o == 1)break;
		else printf("��������ݴ������������룡");
	}
	o = 0;
	per.all.sm = per.all.dy + per.all.sx + per.all.sz;
	int q = 0;

	while (o != 1)
	{

		printf("��ͬѧ����Ϣ�����¼�룬�Ƿ�ȷ�ϱ����޸ģ�ȷ�ϱ�������1��������������ȡ������\n");
		o = scanf_s("%d", &q);
	}
	if (q == 1)
	{

		fprintf(fp, "%s %s %s %.2f %.2f %.2f %.2f", per.xh, per.xm, per.xb, per.all.sx, per.all.dy, per.all.sz, per.all.sm);
	}
	printf("\n�ر��޸�ҳ��������1\n");
	ss();
}
typedef struct
{
	int i;			//λ��
	float sm;		//�ܳɼ�
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
	};//����һ���ṹ�岢��ʼ��
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
	//���ܳɼ���С�����˳��ѧ����Ϣ������ն�
	for (int c = 0; c < i; c++)
	{
		int v = k[c].i;
		printf(" %s %s %s %f %f %f %f\n", per[v].xh, per[v].xm, per[v].xb, per[v].all.sx, per[v].all.dy, per[v].all.sz, per[v].all.sm);
	}
	printf("\n�رս�������1��\n");
	ss();
}
