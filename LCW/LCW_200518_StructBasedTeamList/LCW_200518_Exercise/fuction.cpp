#include "fuction.h"

int fileIO(Team* t, int tnum, char buf)
{
	FILE* f;
	switch (buf)
	{
	case 'r':
		if ((f = (fopen("data.txt", "r"))) != 0)
		{
			char line[MAXLEN * 3];
			char* token;

			while (feof(f) == 0)
			{
				fgets(line, sizeof(line), f);
				if (line[0] == '\0') break;
				token = strtok(line, "\t");
				t[tnum].id = atoi(token);
				token = strtok(NULL, "\t");
				strcpy(t[tnum].name, token);
				token = strtok(NULL, "\n");
				strcpy(t[tnum].company, token);
				memset(line, '\0', sizeof(line));
				tnum++;
			}
		}
		else
			printf("오류!\n");
		break;
	case 'w':
		if ((f = (fopen("data.txt", "w"))) != 0)
		{
			for (int i = 0; i < tnum; i++)
			{
				char line[MAXLEN * 3];

				_itoa(t[i].id, line, 10);
				strcat(line, "\t");

				strcat(line, t[i].name);
				strcat(line, "\t");

				strcat(line, t[i].company);
				strcat(line, "\n");

				fputs(line, f);
			}
		}
		else
			printf("오류!\n");
		break;
	default:
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
			if (t[j].id > t[j + 1].id)
			{
				Team temp;
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
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
	printf("저장하시겠습니까?(y/n)");
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