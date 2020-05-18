#include<stdio.h>
#include<stdlib.h>
#define exernum 2
/*typedef struct
{
	int team_id;
	char team_name[20];
	char company[20];

}team;*/
int main()
{
	int sel1,sel2,sel3;
	
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
			printf("1. 팀 정보 입력\n");
			printf("2. 팀 정보 수정\n");
			printf("3. 팀 정보 삭제\n");
			scanf("%d", &sel2);
			switch (sel2)
			{
			case 1:
				//이채원
				break;
			case 2:
				//박윤화
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
				scanf("%d", &sel3);
				switch (sel3)
				{
				case 1:

					break;
				case 2:

					break;
				case 3:
					break;
				default:
					printf("값을 다시 입력해주세요\n");
					continue;
				}
				break;
			}
		case 3:
			exit(0);
			break;
		}
		
	
	}
	return 0;
}
