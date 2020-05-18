#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define MAXLEN 20

struct Team
{
	int id;
	char name[MAXLEN];
	char company[MAXLEN];
};

void print_list(struct Team* tm, int tnum);

int main()
{
	Team t[MAX];
	int tnum = 0;
	int sel1, sel2;

	while (1)
	{
		printf("1. 정보 수정\n");
		printf("2. 팀 정렬\n");
		printf("3. 프로그램 종료\n");
		scanf("%d", &sel1);
		switch (sel1)
		{
		case 1:
			system("cls");
			printf("1. 팀 정보 추가\n");
			printf("2. 팀 정보 수정\n");
			printf("3. 팀 정보 삭제\n");
			scanf("%d", &sel2);
			switch (sel2)
			{
			case 1:
				//이채원
				if (tnum > MAX)
				{
					printf("더이상 추가할 수 없습니다.\n\n");
					break;
				}
				getchar();
				printf("팀명을 입력해주세요[19자까지 입력가능] : ");
				fgets(t[tnum].name, MAXLEN, stdin);

				printf("회사명을 입력해주세요[19자까지 입력가능] : ");
				fgets(t[tnum].company, MAXLEN, stdin);

				t[tnum++].id = tnum + 1;
				break;
			case 2:
				//박윤화
				int a;

				print_list(t, tnum);

				printf("수정할 팀ID를 선택하세요 : \n");
				scanf_s("%d", &a);
				for (int i = 0; i < tnum; i++)
				{
					if (a == t[i].id)
					{
						while (1)
						{
							int b;

							printf("수정할 항목을 선택하세요 : \n");
							printf("1. 팀명\n");
							printf("2. 회사명\n");
							scanf_s("%d", &b);

							if (b == 1)
							{
								char c[MAXLEN];

								getchar();
								printf("수정할 팀명 : \t");
								fgets(c, MAXLEN, stdin);
								strcpy(t[i].name, c);
							}

							else if (b == 2)
							{
								char d[MAXLEN];

								getchar();
								printf("수정할 회사명 : \t");
								fgets(d, MAXLEN, stdin);
								strcpy(t[i].company, d);
							}

							else
							{
								printf("다시 선택하세요 : \n");
								continue;
							}
							break;
						}

					}
				}
				print_list(t, tnum);

				break;
			case 3:
				int e;

				print_list(t, tnum);

				printf("삭제할 팀ID를 선택하세요 : \n");
				scanf_s("%d", &e);

				for (int i = 0; i < tnum; i++)
				{
					if (e >= t[i].id)
					{
						t[i] = t[i + 1];
					}
				}
				tnum--;
				break;
			default:
				printf("값을 다시 입력해주세요\n");
				continue;
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				printf("1. ID순으로 정렬\n");
				printf("2. 팀명순으로 정렬\n");
				printf("3. 회사명순으로 정렬\n");
				scanf("%d", &sel2);
				//이로운
				switch (sel2)
				{
				case 1:
					for (int i = 0; i < tnum - 1; i++)
					{
						for (int j = 0; j < tnum - 1 - i; j++)
						{
							if (t[j].id > t[j + 1].id)
							{
								int temp;
								temp = t[j].id;
								t[j].id = t[j + 1].id;
								t[j + 1].id = temp;
							}
						}
					}
					break;
				case 2:
					for (int i = 0; i < tnum - 1; i++)
					{
						for (int j = 0; j < tnum - 1 - i; j++)
						{
							if (strcmp(t[j].name, t[j + 1].name) == 1)
							{
								Team temp;
								temp = t[j];
								t[j] = t[j + 1];
								t[j + 1] = temp;
							}
						}
					}
					break;
				case 3:
					for (int i = 0; i < tnum - 1; i++)
					{
						for (int j = 0; j < tnum - 1 - i; j++)
						{
							if (strcmp(t[j].company, t[j + 1].company) == 1)
							{
								char temp[20];
								strcpy(temp, t[j].company);
								strcpy(t[j].company, t[j + 1].company);
								strcpy(t[j + 1].company, temp);
							}
						}
					}
					break;
				default:
					printf("값을 다시 입력해주세요.\n");
					continue;
				}
				break;
			}
		case 3:
			printf("프로그램이 종료됩니다.\n");
			exit(0);
			break;
		}
	}
	return 0;
}

void print_list(struct Team* tm, int tnum)
{
	for (int i = 0; i < tnum; i++)
	{
		printf("%d\t", (tm + i)->id);
		for (int j = 0; j < strlen((tm + i)->name) - 1; j++)
			printf("%c", (tm + i)->name[j]);
		printf("\t%s\n", (tm + i)->company);
	}
}