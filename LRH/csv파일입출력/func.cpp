#include"Init.h"
void SearchByName(Info* k, char* input)
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
		printf("ã���ô� �̸��� ��ܿ� �����ϴ�\n�ƹ�Ű�� �����ּ���");
		getchar();
		getchar();
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
		printf("ã���ô� ȸ�簡 ��ܿ� �����ϴ�\n�ƹ�Ű�� �����ּ���");
		getchar();
		getchar();
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
		printf("ã���ô� ���б��� ��ܿ� �����ϴ�\n�ƹ�Ű�� �����ּ���");
		getchar();
		getchar();
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
		printf("ã���ô� �̸��� ��ܿ� �����ϴ�\n�ƹ�Ű�� �����ּ���");
		getchar();
		getchar();
	}
	else

		for (int i = 0; i < offset; i++)
		{
			if (k[a[i]].lea)
				SearchByCom(k, k[a[i]].company);
			else {
				printf("%s��(��) ������ �ƴմϴ�\n�ƹ�Ű�� �����ּ���", k[a[i]].name);
				getchar();
				getchar();
			}
		}
}

void print_info(Info k)
{
	FILE *fp = fopen("result.txt", "a");
	if (k.lea)
		fprintf(fp,"����  %s  %s  %s  %s  %s\n", k.company, k.name, k.email, k.school, k.major);
	else
		fprintf(fp,"����  %s  %s  %s  %s  %s\n", k.company, k.name, k.email, k.school, k.major);
	fclose(fp);
}
int ReadCsvFile(char* path, Info *in)
{
	int err;
	FILE* fp1; 
	char tmp[256];
	char *com;
	char str[MAXLINE];
	char st;
	int i = 0;
	memset(str, '\0', MAXLINE);
	err = fopen_s(&fp1, path, "r");
	fgets(tmp, 256, fp1);
	for (int t = 0; t < StuNum; t++)
	{
		while (fgetc(fp1) == ',')
			;
		fseek(fp1, -1, SEEK_CUR);
		for (int comma = 0; comma < 6;)
		{
			st = fgetc(fp1);
			if (st == '?' || st == '\n')
				continue;
			if (st == ',')
			{
				if (comma == 0)
					if (!strcmp(str, "����"))
						in[t].lea = true;
					else
						in[t].lea = false;
				else if (comma == 1)
					strcpy(in[t].company, str);
				else if (comma == 2)
					strcpy(in[t].name, str);
				else if (comma == 3)
					strcpy(in[t].email, str);
				else if (comma == 4)
					strcpy(in[t].school, str);
				else if (comma == 5)
					strcpy(in[t].major, str);
				memset(str, '\0', MAXLINE);
				i = 0;
				comma++;
			}
			else
			{
				str[i] = st;
				i++;
			}
		}

	}
	fclose(fp1);
	return 0;
}
