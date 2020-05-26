#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define StuNum 24
#define ColNum 6
#define MAXLINE 256
#define CharNum 4
typedef struct
{
	bool lea;
	char company[30] ;
	char name[10] ;
	char email[50] ;
	char school [30] ;
	char major[50];
}Info;
void SearchByName(Info*,char*);
void SearchByCom(Info*, char*);
void SearchBySchool(Info*, char*);
void SearchByLeader(Info*, char*);
void print_info(Info);

int main()
{
	int err;
	FILE* fp1;
	int i=0;
	Info in[50];
	char tmp[256];
	char *com;
	char str[MAXLINE];
	err = fopen_s(&fp1,"list.csv", "r");
	fgets(tmp, 256, fp1);
	for(i=0;i<StuNum;i++)
	{
		fgets(str, 256, fp1);
		strcpy(tmp,strtok(str, "?"));
		for (int j = 0; j < CharNum;j++)
			strcat(tmp, strtok(NULL, "?"));

		com = strtok(tmp, ",");
		if (tmp[0] == ',')
		{
			in[i].lea = false;
			strcpy(in[i].company, com);
		}
		else
		{
			in[i].lea = true;
			strcpy(in[i].company ,strtok(NULL, ","));
		}
		
		strcpy(in[i].name,strtok(NULL, ","));
		strcpy(in[i].email, strtok(NULL, ","));
		strcpy(in[i].school ,strtok(NULL, ","));
		strcpy(in[i].major ,strtok(NULL, ","));
		
		
	}

	while (1)
	{
		
		int a;
		char input[20];
		system("cls");
		printf("1. 이름으로 검색\n");
		printf("2. 회사명으로 검색\n");
		printf("3. 학교명으로 검색\n");
		printf("4. 조장으로 검색\n");
		printf("4. 프로그램 종료\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			scanf("%s", input);
			SearchByName(in, input);
			break;
		case 2:
			scanf("%s", input);
			SearchByCom(in, input);
			break;
		case 3:
			scanf("%s", input);
			SearchBySchool(in, input);
			break;
		case 4:
			scanf("%s", input);
			SearchByLeader(in, input);
			break;
		case 5:
			exit(0);
			break;
		}
		break;
	}
	
	
	fclose(fp1);
	return 0;
}
void SearchByName(Info* k,char* input)
{
	int a[StuNum] = { 0 };
	int offset = 0;
	for (int i = 0; i < StuNum; i++)
	{
		if (!strcmp(k[i].name , input))
		{
			a[offset] = i;
			offset++;
		}
	}
	if (offset == 0)
	{
		printf("찾으시는 이름이 명단에 없습니다\n");
	}
	else
		for (int i = 0; i < offset; i++)
		{
			print_info(k[a[i]]);
		}
}
void SearchByCom(Info* k, char* input)
{
	int a[StuNum] = { 0 };
	int offset = 0;
	for (int i = 0; i < StuNum; i++)
	{
		if (!strcmp(k[i].company, input))
		{
			a[offset] = i;
			offset++;
		}
	}
	if (offset == 0)
	{
		printf("찾으시는 회사가 명단에 없습니다\n");
	}
	else
		for (int i = 0; i < offset; i++)
		{
			print_info(k[a[i]]);
		}
}
void SearchBySchool(Info* k, char* input)
{
	int a[StuNum] = { 0 };
	int offset = 0;
	for (int i = 0; i < StuNum; i++)
	{
		if (!strcmp(k[i].school, input))
		{
			a[offset] = i;
			offset++;
		}
	}
	if (offset == 0)
	{
		printf("찾으시는 대학교가 명단에 없습니다\n");
	}
	else
		for (int i = 0; i < offset; i++)
		{
			print_info(k[a[i]]);
		}
}
void SearchByLeader(Info* k, char* input)
{
	int a[StuNum] = { 0 };
	int offset = 0;
	for (int i = 0; i < StuNum; i++)
	{
		if (!strcmp(k[i].name, input))
		{
			a[offset] = i;
			offset++;
		}
	}
	if (offset == 0)
	{
		printf("찾으시는 이름이 명단에 없습니다\n");
	}
	else
		
		for (int i = 0; i < offset; i++)
		{
			if (k[a[i]].lea)
				SearchByCom(k, k[a[i]].company);
			else
				printf("%s는 조장이 아닙니다", k[a[i]].name);
		}
}

void print_info(Info k)
{
	if (k.lea)
		printf("조장 %s %s %s %s %s\n", k.company, k.name, k.email, k.school, k.major);
	else
		printf("%s %s %s %s %s\n", k.company, k.name, k.email, k.school, k.major);
}