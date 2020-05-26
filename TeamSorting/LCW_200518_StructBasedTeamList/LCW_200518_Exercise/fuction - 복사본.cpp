#include "fuction.h"

int fileIO(Team* t, int tnum, char buf)
{
	FILE* f;
	switch (buf)
	{
	case 'r':
		if ((fopen_s(&f, "C:\\Users\\USER\\Desktop\\채채\\프로젝트\\Result\\서울반 교육생 명단_한국표준협회.csv", "rt")) == 0)
		{
			char line[RLEN];
			char* token;
			int flag = 0;

			while (!feof(f))
			{
				//fgetws(line, RLEN, f);
				fread(line, RLEN, 1, f);
				//printf("%s", line);
				//printf("\n\nNew Line!\n");
				token = strtok(line, ",");
				while (token != NULL)
				{
					//printf("%s\n", token);
					if (!flag)
					{
						if (strcmp(token, "\n조장") == 0)
							t[tnum].isLeader = 1;
						else if (token[0] == _T('?'))
							flag = 1;
					}

					switch (flag)
					{
					case 1:
						strcpy(t[tnum].company, token);
						flag++;
						break;
					case 2:
						strcpy(t[tnum].name, token);
						flag++;
						break;
					case 3:
						strcpy(t[tnum].email, token);
						flag++;
						break;
					case 4:
						strcpy(t[tnum].school, token);
						flag++;
						break;
					case 5:
						strcpy(t[tnum++].major, token);
						flag = 0;

						/*printf("%d\t", t[tnum-1].isLeader);
						printf("%s\t", t[tnum-1].company);
						printf("%s\t", t[tnum-1].name);
						printf("%s\t", t[tnum-1].email);
						printf("%s\t", t[tnum-1].school);
						printf("%s\n\n", t[tnum-1].major);*/
						break;
					}
					token = strtok(NULL, ",");
				}
			}			
		}
		else
			printf("파일 입력 오류!\n");
		break;
	case 'w':
		if ((f = (fopen("data.txt", "w"))) != 0)
		{
			for (int i = 0; i < tnum; i++)
			{
				char line[MAXLEN * 3];

				//_itoa(t[i].id, line, 10);
				strcat(line, "\t");

				strcat(line, t[i].name);
				strcat(line, "\t");

				strcat(line, t[i].company);
				//strcat(line, "\n");

				//fputs(line, f);
			}
		}
		else
			printf("오류!\n");
		break;
	default:
		printf("오류!\n");
		exit(1);
	}
	fclose(f);
	return tnum;
}

void sortID(Team* t, int tnum)
{
	for (int i = 0; i < tnum - 1; i++)
	{
		for (int j = 0; j < tnum - 1 - i; j++)
		{
			/*if (t[j].id > t[j + 1].id)
			{
				Team temp;
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}*/
		}
	}
}

void sortTeamName(Team* t, int tnum)
{
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
}

void sortCompany(Team* t, int tnum)
{
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
}

void ExitProgram(Team* t, int tnum)
{
	getchar();

	char res;
	printf("저장하시겠습니까?(y/n) ");
	scanf("%c", &res);
	while (1)
	{
		switch (res)
		{
		case 'y':
			fileIO(t, tnum, 'w');
			printf("저장되었습니다.\n");
			exit(0);
			break;
		case 'n':
			exit(0);
			break;
		default:
			printf("y나 n을 입력해주세요.\n");
		}
	}
}

void SearchLeaderName(Team* t, int tnum)
{
	int num = 0;
	char name[MAXLEN] = { NULL, };
	char* content[MAXLEN] = { NULL, };

	getchar();
	printf("검색하실 조장의 이름을 입력해주세요 : ");
	//scanf_s("%s", &name);
	fgets(name, MAXLEN, stdin);
	name[strlen(name) - 1] = '\0';

	for (int i = 0; i < tnum; i++)
	{
		if (strcmp(name, t[i].name) == 0)
		{
			if (t[i].isLeader)
			{
				content[0] = new char[MAXLEN];
				strcpy(content[0], t[i].company);
				strcat(content[0], "\t");
				strcat(content[0], t[i].name);
				strcat(content[0], "\t");
				strcat(content[0], t[i].email);
				strcat(content[0], "\t");
				strcat(content[0], t[i].school);
				strcat(content[0], "\t");
				strcat(content[0], t[i].major);
				strcat(content[0], "\n");
				num++;
				printf("%s\n", content[0]);

				for (int j = i + 1; strcmp(t[i].company, t[j].company) == 0; j++)
				{
					content[j - i] = new char[MAXLEN];
					strcpy(content[j - i], t[j].company);
					strcat(content[j - i], "\t");
					strcat(content[j - i], t[j].name);
					strcat(content[j - i], "\t");
					strcat(content[j - i], t[j].email);
					strcat(content[j - i], "\t");
					strcat(content[j - i], t[j].school);
					strcat(content[j - i], "\t");
					strcat(content[j - i], t[j].major);
					strcat(content[j - i], "\n");
					num++;
					printf("%s\n", content[j-i]);
				}
				saveSearchResult(content, num);
				return;
			}
		}
	}
	printf("해당하는 조장 이름이 없습니다.\n");
	saveSearchResult(NULL, num);
}

void SearchCompany(Team* t, int tnum)
{
	int num = 0;
	char name[MAXLEN] = { NULL, };
	char* content[MAXLEN] = { NULL, };

	getchar();
	printf("검색하실 기업의 이름을 입력해주세요 : ");
	fgets(name, MAXLEN, stdin);
	name[strlen(name) - 1] = '\0';

	for (int i = 0; i < tnum; i++)
	{
		if (strcmp(name, t[i].company) == 0)
		{
			content[0] = new char[MAXLEN];
			strcpy(content[0], t[i].company);
			strcat(content[0], "\t");
			strcat(content[0], t[i].name);
			strcat(content[0], "\t");
			strcat(content[0], t[i].email);
			strcat(content[0], "\t");
			strcat(content[0], t[i].school);
			strcat(content[0], "\t");
			strcat(content[0], t[i].major);
			strcat(content[0], "\n");
			num++;
			printf("%s\n", content[0]);

			for (int j = i + 1; strcmp(t[i].company, t[j].company) == 0; j++)
			{
				content[j - i] = new char[MAXLEN];
				strcpy(content[j - i], t[j].company);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].name);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].email);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].school);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].major);
				strcat(content[j - i], "\n");
				num++;
				printf("%s\n", content[j - i]);
			}
			saveSearchResult(content, num);
			return;
		}
	}
	printf("해당하는 기업에 배당된 사람이 없습니다.\n");
	saveSearchResult(NULL, num);
}

void SearchName(Team* t, int tnum)
{
	int num = 0;
	char name[MAXLEN] = { NULL, };
	char* content[MAXLEN] = { NULL, };

	getchar();
	printf("검색하실 사람의 이름을 입력해주세요 : ");
	fgets(name, MAXLEN, stdin);
	name[strlen(name) - 1] = '\0';

	for (int i = 0; i < tnum; i++)
	{
		if (strcmp(name, t[i].name) == 0)
		{
			content[0] = new char[MAXLEN];
			strcpy(content[0], t[i].company);
			strcat(content[0], "\t");
			strcat(content[0], t[i].name);
			strcat(content[0], "\t");
			strcat(content[0], t[i].email);
			strcat(content[0], "\t");
			strcat(content[0], t[i].school);
			strcat(content[0], "\t");
			strcat(content[0], t[i].major);
			strcat(content[0], "\n");
			num++;
			printf("%s\n", content[0]);
			saveSearchResult(content, num);
			return;
		}
	}
	printf("찾으시는 사람이 없습니다.\n");
	saveSearchResult(NULL, num);
}

void SearchSchool(Team* t, int tnum)
{
	int num = 0;
	char name[MAXLEN] = { NULL, };
	char* content[MAXLEN] = { NULL, };

	getchar();
	printf("검색하실 학교를 입력해주세요 : ");
	fgets(name, MAXLEN, stdin);
	name[strlen(name) - 1] = '\0';

	for (int i = 0; i < tnum; i++)
	{
		if (strcmp(name, t[i].school) == 0)
		{
			content[0] = new char[MAXLEN];
			strcpy(content[0], t[i].company);
			strcat(content[0], "\t");
			strcat(content[0], t[i].name);
			strcat(content[0], "\t");
			strcat(content[0], t[i].email);
			strcat(content[0], "\t");
			strcat(content[0], t[i].school);
			strcat(content[0], "\t");
			strcat(content[0], t[i].major);
			strcat(content[0], "\n");
			num++;
			printf("%s\n", content[0]);

			for (int j = i + 1; strcmp(t[i].school, t[j].school) == 0; j++)
			{
				content[j - i] = new char[MAXLEN];
				strcpy(content[j - i], t[j].company);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].name);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].email);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].school);
				strcat(content[j - i], "\t");
				strcat(content[j - i], t[j].major);
				strcat(content[j - i], "\n");
				num++;
				printf("%s\n", content[j - i]);
			}
			saveSearchResult(content, num);
			return;
		}
	}
	printf("해당하는 학교가 없습니다.\n");
	saveSearchResult(NULL, num);
}

void saveSearchResult(char** content, int num)
{
	time_t t = time(NULL);
	tm tm = *localtime(&t);
	FILE* f;

	if ((f = (fopen("C:\\Users\\USER\\Desktop\\채채\\프로젝트\\Result\\result.txt", "w"))) != 0)
	{
		if (num)
		{
			for (int i = 0; i < num; i++)
			{
				fprintf(f, "%s", content[i]);
			}
			fprintf(f, "TIME : %d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		}
		else
		{
			fprintf(f, "찾으시는 검색 결과가 없습니다.\n");
			fprintf(f, "TIME : %d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
		}
	}
	fclose(f);
}