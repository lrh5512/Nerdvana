#define _CRT_SECURE_NO_WARNINGS

#include "fuction.h"


int main()
{
	Team t[MAX];
	int tnum = 0;
	int sel1, sel2;

	tnum = fileIO(t, tnum, 'r');	// r : read, w : write

	while (1)
	{
		printf("1. ���� ����\n");
		printf("2. �� ����\n");
		printf("3. ���α׷� ����\n");
		scanf("%d", &sel1);
		switch (sel1)
		{
		case 1:
			//system("cls");
			printf("\n1. �� ���� �߰�\n");
			printf("2. �� ���� ����\n");
			printf("3. �� ���� ����\n");
			scanf("%d", &sel2);
			switch (sel2)
			{
			case 1:
				//��ä��
				if (addTeamInfo(t, tnum) == 0) tnum++;				
				break;
			case 2:
				//����ȭ
				modifyTeamInfo(t, tnum);
				break;
			case 3:
				//����ȭ
				tnum = deleteTeamInfo(t, tnum);
				break;
			default:
				printf("���� �ٽ� �Է����ּ���\n");
				continue;
			}
			break;
		case 2:
			while (1)
			{
				//system("cls");
				printf("\n1. ID������ ����\n");
				printf("2. ��������� ����\n");
				printf("3. ȸ�������� ����\n");
				scanf("%d", &sel2);
				//�̷ο�
				switch (sel2)
				{
				case 1:
					sortID(t, tnum);
					break;
				case 2:
					sortTeamName(t, tnum);
					break;
				case 3:
					sortCompany(t, tnum);
					break;
				default:
					printf("���� �ٽ� �Է����ּ���.\n");
					continue;
				}
				break;
			}
			break;
		case 3:
			ExitProgram(t, tnum);			
			break;
		}
	}
	return 0;
}