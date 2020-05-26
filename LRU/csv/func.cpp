#include "header.h"

void file(KSA* list)
{
    FILE* fp;
    char* tmp1;
    char str[100];
    char strtmp[100];
    fp = fopen("C:\\LRU\\team.csv", "r");
    fgets(str, 100, fp);
    int k = 0;
    while (k < 24)
    {
        fgets(str, 100, fp);
        tmp1 = strtok(str, ",""?");
        if (tmp1 != NULL && strcmp(tmp1, "\n"))
        {
            if (!strcmp(tmp1, "조장"))
            {
                list[k].leader = 1;
                strcpy(list[k].company, strtok(NULL, ",""?"));
                strcpy(list[k].name, strtok(NULL, ","));
                strcpy(list[k].email, strtok(NULL, ",""?"));
                strcpy(list[k].school, strtok(NULL, ",""?"));
                strcpy(list[k].major, strtok(NULL, ",""?"));
            }
            else
            {
                list[k].leader = 0;
                strcpy(list[k].company, tmp1);
                strcpy(list[k].name, strtok(NULL, ","));
                strcpy(list[k].email, strtok(NULL, ",""?"));
                strcpy(list[k].school, strtok(NULL, ",""?"));
                strcpy(list[k].major, strtok(NULL, ",""?"));
            }
            //printf("%s %s %s %s %s \n", list[k].company, list[k].name, list[k].email, list[k].school, list[k].major);
            k++;
        }

    }
    fclose(fp);

}

void search_leader(KSA* list)
{
    char search_leader[MAXLEN]{ 0 };
    int i[10] = { 0 }, a = 0;
    int k;
    FILE* fp;
    fp = fopen("C:\\LRU\\team.csv", "r");
    FILE* f = fopen("result.txt", "a");
    printf("조장 이름을 입력하시오 : ");
    scanf("%s", search_leader);

    for (k = 0; k < 24; k++)
    {
        if (strcmp(list[k].name, search_leader) == 0)
        {
            i[a] = k;
            a++;
        }
    }
    time_t ti;
    struct tm* t;
    ti = time(NULL);
    t = localtime(&ti);
    fprintf(f, "검색 시간 : %d시 %d분\n", t->tm_hour, t->tm_min);
    for (int j = 0; j < a; j++)
    {
        for (int x = 0; x < 24; x++)
        {
            if (strcmp(list[i[j]].company, list[x].company) == 0)
            {
                if (list[x].leader == 1)
                {
                   
                    fprintf(fp, "조장 ");
                }
                else {
                 
                    fprintf(fp, "조원 ");
                }
                fprintf(f,"%s %s %s %s %s \n", list[x].company, list[x].name, list[x].email, list[x].school, list[x].major);
            }
            else if (list[i[j]].leader == 0)
            {
                printf("\n조장이 아닙니다.\n");
                break;
            }
        }
    }

    fclose(f);
    fclose(fp);
   

}
void search_company(KSA* list)
{
    char search_company[MAXLEN]{ 0, };
    int i[10] = { 0 }, a = 0;
    int k{ 0 };
    FILE* fp;
    fp = fopen("C:\\LRU\\team.csv", "r");
    FILE* f = fopen("result.txt", "a");
    printf("기업 이름을 입력하시오 : ");
    scanf("%s", search_company);

    for (k = 0; k < 24; k++)
    {
        if (strcmp(list[k].company, search_company) == 0)
        {
            i[a] = k;
            a++;
        }
    }
    time_t ti;
    struct tm* t;
    ti = time(NULL);
    t = localtime(&ti);
    fprintf(f, "검색 시간 : %d시 %d분\n", t->tm_hour, t->tm_min);
    for (int j = 0; j < a; j++)
    {
        if (list[i[j]].leader == 1)
        {
     
            fprintf(f, "조장 ");
        }
        else {
            
            fprintf(f, "조원 ");
        }
      
        fprintf(f,"%s %s %s %s %s \n", list[i[j]].company, list[i[j]].name, list[i[j]].email, list[i[j]].school, list[i[j]].major);
    }

    fclose(f);
    fclose(fp);

}
void search_name(KSA* list)
{
    char search_name[MAXLEN]{ 0, };
    int k{ 0 };
    FILE* fp;
    FILE* f = fopen("result.txt", "a");
    fp = fopen("C:\\LRU\\team.csv", "r");
    printf("이름을 입력하시오 : ");
    scanf("%s", search_name);

    for (k = 0; k < 24; k++)
    {
        if (strcmp(list[k].name, search_name) == 0)break;
    }
    time_t ti;
    struct tm* t;
    ti = time(NULL);
    t = localtime(&ti);
    fprintf(f, "검색 시간 : %d시 %d분\n", t->tm_hour, t->tm_min);
    if (list[k].leader == 1)
    {
       
        fprintf(fp, "조장 ");
    }
    else {
      
        fprintf(fp, "조원 ");
    }
   
    fprintf(f, "%s %s %s %s %s \n", list[k].company, list[k].name, list[k].email, list[k].school, list[k].major);


    fclose(f);
    fclose(fp);
}
void search_school(KSA* list)
{
    {
        char search_school[MAXLEN]{ 0, }, timestr[30]{ 0 };
        int i[10] = { 0 }, a = 0;
        int k{ 0 };
        FILE* fp;
        FILE* f = fopen("result.txt", "a");
        fp = fopen("C:\\LRU\\team.csv", "r");
        printf("학교 이름을 입력하시오 : ");
        scanf("%s", search_school);

        for (k = 0; k < 24; k++)
        {
            if (strcmp(list[k].school, search_school) == 0)
            {
                i[a] = k;
                a++;
            }
        }
        time_t ti;
        struct tm* t;
        ti = time(NULL);
        t = localtime(&ti);
        fprintf(f, "검색 시간 : %d시 %d분\n", t->tm_hour, t->tm_min);
       
        for (int j = 0; j < a; j++)
        {
            if (list[i[j]].leader == 1)
            {
                printf("조장 ");
                fprintf(fp, "조장 ");
            }
            else {
                printf("조원 ");
                fprintf(fp, "조원 ");
            }
           
            fprintf(f, "%s %s %s %s %s \n", list[i[j]].company, list[i[j]].name, list[i[j]].email, list[i[j]].school, list[i[j]].major);
        }

        fclose(f);
        fclose(fp);

    }

}
