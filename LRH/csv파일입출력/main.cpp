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
		printf("1. �̸����� �˻�\n");
		printf("2. ȸ������� �˻�\n");
		printf("3. �б������� �˻�\n");
		printf("4. �����̸����� �˻�\n");
		printf("5. ���α׷� ����\n");
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