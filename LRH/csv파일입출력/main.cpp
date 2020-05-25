#include "init.h"
int main()
{
	Info in[50];
	char path[50] = "list.csv";
	char path1[50] = "result.txt";
	ReadCsvFile(path,in);
	int i = 0;
	FILE *fp = fopen("result.txt", "w");
	fclose(fp);
	while (1)
	{
		int a;
		char input[20];
		system("cls");
		printf("1. 이름으로 검색\n");
		printf("2. 회사명으로 검색\n");
		printf("3. 학교명으로 검색\n");
		printf("4. 조장이름으로 검색\n");
		printf("5. 프로그램 종료\n");
		scanf("%d", &a);
		if(a == 5)
			exit(0);
		else if(a>=1&&a<=4)
			scanf("%s", input);
		switch (a)
		{
		case 1:
			SearchByName(in, input);
			break;
		case 2:
			SearchByCom(in, input);
			break;
		case 3:
			SearchBySchool(in, input);
			break;
		case 4:
			SearchByLeader(in, input);
			break;
		}
	}
	return 0;
}