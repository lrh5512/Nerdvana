#include "���.h"

int search(list* L)
{
	while (1)
	{
		int sel = 0;

		printf("�˻��� �׸��� �����ϼ���.\n");
		printf("1. ����\n");		
		printf("2. �������\n");
		printf("3. �̸�\n");
		printf("4. �б�\n");
		printf("5. �а�\n");
		printf("��ȣ�Է� : ");

		scanf("%d", &sel);

		switch (sel)
		{
		case 1:
			Mana_Sear(L);
			break;

		case 2:
			Comp_Sear(L);
			break;

		case 3:
			Name_Sear(L);
			break;
			
		case 4:
			Grad_Sear(L);
			break;

		case 5:
			Majo_Sear(L);
			break;

		default:
			printf("�ٽ��Է����ּ���.\n");
		}

	}
}

int Mana_Sear(list* L)
{
	FILE* o_file;
	o_file = fopen("result.txt", "a");

	char temp[20];

	getchar();
	printf("�����̸��Է� : ");
	fgets(temp, 20, stdin);
	temp[strlen(temp) - 1] = '\0';

	time_t ti;
	struct tm* t;
	ti = time(NULL);
	t = localtime(&ti);
	fprintf(o_file, "�˻� �ð� : %d�� %d��\n", t->tm_hour, t->tm_min);

	for (int i = 0; i < 24; i++)
	{
		if (!strcmp(temp, L[i].name))
		{
			if (!strcmp(L[i].mana, "����"))
			{
				fprintf(o_file, "%s\t", L[i].mana);
				fprintf(o_file, "%s\t", L[i].comp);
				fprintf(o_file, "%s\t", L[i].name);
				fprintf(o_file, "%s\t", L[i].mail);
				fprintf(o_file, "%s\t", L[i].grad);
				fprintf(o_file, "%s\n", L[i].majo);
				for (int j = i+1; j < 24; j++)
				{
					if (!strcmp(L[j].comp, L[i].comp))
					{
						fprintf(o_file, "%s\t", L[j].mana);
						fprintf(o_file, "%s\t", L[j].comp);
						fprintf(o_file, "%s\t", L[j].name);
						fprintf(o_file, "%s\t", L[j].mail);
						fprintf(o_file, "%s\t", L[j].grad);
						fprintf(o_file, "%s\n", L[j].majo);
					}
				}
			}
		}
	}
	fclose(o_file);
	return 0;
}

int Comp_Sear(list* L)
{
	FILE* o_file;
	o_file = fopen("result.txt", "a");

	char temp[20];

	getchar();
	printf("��������Է� : ");
	fgets(temp, 20, stdin);
	temp[strlen(temp) - 1] = '\0';
		
	time_t ti;
	struct tm* t;
	ti = time(NULL);
	t = localtime(&ti);
	fprintf(o_file, "�˻� �ð� : %d�� %d��\n", t->tm_hour, t->tm_min);

	for (int i = 0; i < 24; i++)
	{
		if (!strcmp(temp, L[i].comp))
		{
			fprintf(o_file, "%s\t", L[i].comp);
			fprintf(o_file, "%s\t", L[i].name);
			fprintf(o_file, "%s\t", L[i].mail);
			fprintf(o_file, "%s\t", L[i].grad);
			fprintf(o_file, "%s\n", L[i].majo);
		}
	}
	fclose(o_file);
	return 0;
}

int Name_Sear(list* L)
{
	FILE* o_file;
	o_file = fopen("result.txt", "a");

	char temp[20];

	getchar();
	printf("�̸��Է� : ");
	fgets(temp, 20, stdin);
	temp[strlen(temp) - 1] = '\0';

	time_t ti;
	struct tm* t;
	ti = time(NULL);
	t = localtime(&ti);
	fprintf(o_file, "�˻� �ð� : %d�� %d��\n", t->tm_hour, t->tm_min);

	for (int i = 0; i < 24; i++)
	{
		if (!strcmp(temp, L[i].name))
		{
			fprintf(o_file, "%s\t", L[i].comp);
			fprintf(o_file, "%s\t", L[i].name);
			fprintf(o_file, "%s\t", L[i].mail);
			fprintf(o_file, "%s\t", L[i].grad);
			fprintf(o_file, "%s\n", L[i].majo);
		}
	}
	fclose(o_file);
	return 0;
}

int Grad_Sear(list* L)
{
	FILE* o_file;
	o_file = fopen("result.txt", "a");

	char temp[20];

	getchar();
	printf("�����б��Է� : ");
	fgets(temp, 50, stdin);
	temp[strlen(temp) - 1] = '\0';
	
	time_t ti;
	struct tm* t;
	ti = time(NULL);
	t = localtime(&ti);
	fprintf(o_file, "�˻� �ð� : %d�� %d��\n", t->tm_hour, t->tm_min);

	for (int i = 0; i < 24; i++)
	{
		if (!strcmp(temp, L[i].grad))
		{
			fprintf(o_file, "%s\t", L[i].comp);
			fprintf(o_file, "%s\t", L[i].name);
			fprintf(o_file, "%s\t", L[i].mail);
			fprintf(o_file, "%s\t", L[i].grad);
			fprintf(o_file, "%s\n", L[i].majo);
		}
	}
	fclose(o_file);
	return 0;
}

int Majo_Sear(list* L)
{
	FILE* o_file;
	o_file = fopen("result.txt", "a");

	char temp[20];

	getchar();
	printf("�����а��Է� : ");
	fgets(temp, 50, stdin);
	temp[strlen(temp) - 1] = '\0';

	time_t ti;
	struct tm* t;
	ti = time(NULL);
	t = localtime(&ti);
	fprintf(o_file, "�˻� �ð� : %d�� %d��\n", t->tm_hour, t->tm_min);

	for (int i = 0; i < 24; i++)
	{
		if (!strcmp(temp, L[i].majo))
		{
			fprintf(o_file, "%s\t", L[i].comp);
			fprintf(o_file, "%s\t", L[i].name);
			fprintf(o_file, "%s\t", L[i].mail);
			fprintf(o_file, "%s\t", L[i].grad);
			fprintf(o_file, "%s\n", L[i].majo);
		}
	}
	fclose(o_file);
	return 0;
}



