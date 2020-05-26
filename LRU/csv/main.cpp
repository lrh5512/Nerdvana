#include "header.h"

int main()
{
    KSA list[24];
    file(list);
    FILE* fp = fopen("result.txt", "w");

    while (1)
    {
        int i;
        printf("\n1.조장 검색 \n 2.배정 기업 검색 \n 3.이름 검색 \n 4.학교 검색");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            search_leader(list);
            break;
        case 2:
            search_company(list);
            break;
        case 3:
            search_name(list);
            break;
        case 4:
            search_school(list);
            break;
        default:
            printf("잘못 입력하셨습니다.\n");
        }
    }fclose(fp);
    return 0;
}

