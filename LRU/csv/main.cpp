#include "header.h"

int main()
{
    KSA list[24];
    file(list);
    FILE* fp = fopen("result.txt", "w");

    while (1)
    {
        int i;
        printf("\n1.���� �˻� \n 2.���� ��� �˻� \n 3.�̸� �˻� \n 4.�б� �˻�");
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
            printf("�߸� �Է��ϼ̽��ϴ�.\n");
        }
    }fclose(fp);
    return 0;
}

