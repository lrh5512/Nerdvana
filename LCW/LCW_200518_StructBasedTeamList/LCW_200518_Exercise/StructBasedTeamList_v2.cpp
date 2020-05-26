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
		printf("1. 정보 수정\n");
		printf("2. 팀 정렬\n");
		printf("3. 프로그램 종료\n");
		scanf("%d", &sel1);
		switch (sel1)
		{
		case 1:
			//system("cls");
			printf("\n1. 팀 정보 추가\n");
			printf("2. 팀 정보 수정\n");
			printf("3. 팀 정보 삭제\n");
			scanf("%d", &sel2);
			switch (sel2)
			{
			case 1:
				//이채원
				if (addTeamInfo(t, tnum) == 0) tnum++;				
				break;
			case 2:
				//박윤화
				modifyTeamInfo(t, tnum);
				break;
			case 3:
				//박윤화
				tnum = deleteTeamInfo(t, tnum);
				break;
			default:
				printf("값을 다시 입력해주세요\n");
				continue;
			}
			break;
		case 2:
			while (1)
			{
				//system("cls");
				printf("\n1. ID순으로 정렬\n");
				printf("2. 팀명순으로 정렬\n");
				printf("3. 회사명순으로 정렬\n");
				scanf("%d", &sel2);
				//이로운
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
					printf("값을 다시 입력해주세요.\n");
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