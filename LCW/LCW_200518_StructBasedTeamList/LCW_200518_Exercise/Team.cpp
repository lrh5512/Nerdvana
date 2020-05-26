#include "Team.h"

void print_list(struct Team* t, int tnum)
{
	for (int i = 0; i < tnum; i++)
	{
		printf("%d\t", (t + i)->id);
		for (int j = 0; j < strlen((t + i)->name) - 1; j++)
			printf("%c", (t + i)->name[j]);
		printf("\t%s\n", (t + i)->company);
	}
}

int addTeamInfo(Team* t, int tnum)
{
	if (tnum > MAX)
	{
		printf("���̻� �߰��� �� �����ϴ�.\n\n");
		return 1;
	}
	getchar();

	char tmp[MAXLEN];
	printf("����ȣ�� �Է����ּ��� : ");
	fgets(tmp, MAXLEN, stdin);
	t[tnum].id = atoi(tmp);

	printf("������ �Է����ּ���[%d�ڱ��� �Է°���] : ", MAXLEN-1);
	fgets(t[tnum].name, MAXLEN, stdin);
	t[tnum].name[strlen(t[tnum].name) - 1] = '\0';

	printf("ȸ����� �Է����ּ���[%d�ڱ��� �Է°���] : ", MAXLEN - 1);
	fgets(t[tnum].company, MAXLEN, stdin);
	t[tnum].company[strlen(t[tnum].company) - 1] = '\0';

	return 0;
}

void modifyTeamInfo(Team* t, int tnum)
{
	int a;

	print_list(t, tnum);

	printf("������ ��ID�� �����ϼ��� : \n");
	scanf_s("%d", &a);
	for (int i = 0; i < tnum; i++)
	{
		if (a == t[i].id)
		{
			while (1)
			{
				int b;

				printf("������ �׸��� �����ϼ��� : \n");
				printf("1. ����\n");
				printf("2. ȸ���\n");
				scanf_s("%d", &b);

				if (b == 1)
				{
					char c[MAXLEN];

					getchar();
					printf("������ ���� : \t");
					fgets(c, MAXLEN, stdin);
					strcpy(t[i].name, c);
					t[i].name[strlen(t[i].name) - 1] = '\0';
				}

				else if (b == 2)
				{
					char d[MAXLEN];

					getchar();
					printf("������ ȸ��� : \t");
					fgets(d, MAXLEN, stdin);
					strcpy(t[i].company, d);
					t[i].company[strlen(t[i].company) - 1] = '\0';
				}

				else
				{
					printf("�ٽ� �����ϼ��� : \n");
					continue;
				}
				break;
			}
		}
	}
	print_list(t, tnum);
}

int deleteTeamInfo(Team* t, int tnum)
{
	int e;

	print_list(t, tnum);

	printf("������ ��ID�� �����ϼ��� : \n");
	scanf_s("%d", &e);

	for (int i = 0; i < tnum; i++)
	{
		if (e >= t[i].id)
		{
			t[i] = t[i + 1];
		}
	}
	return --tnum;
}