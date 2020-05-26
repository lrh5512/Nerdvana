#include "헤더.h"

void file_I(list* L)
{
    FILE* p_file;
    char* tmp;
    char str[100];

    p_file = fopen("list.csv", "r");
    fgets(str, 100, p_file);
    int k = 0;
    int i = 0;

    while (k < 24)
    {
        fgets(str, 100, p_file);
        //printf("%s\n", str);
        tmp = strtok(str, ",?");

        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
        {
            //printf("%s\n", tmp);

            if (0 == strcmp(tmp, "조장"))
            {
                strcpy(L[i].mana, tmp);
                tmp = strtok(NULL, ",?");
                //printf("%s\n", L[i].mana);
                //printf("%s\n", tmp);
            }
        }
        
        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
        {
            strcpy_s(L[i].comp, tmp);
            tmp = strtok(NULL, ",?");
            printf("%s\t", L[i].mana);
            printf("%s\t", L[i].comp);
        }
        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
        {
            strcpy_s(L[i].name, tmp);
            tmp = strtok(NULL, ",?");
            printf("%s\t", L[i].name);
        }
        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
        {
            strcpy_s(L[i].mail, tmp);
            tmp = strtok(NULL, ",?");
            printf("%s\t", L[i].comp);
        }
        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
        {
            strcpy_s(L[i].grad, tmp);
            tmp = strtok(NULL, ",?");
            printf("%s\t", L[i].grad);
        }
        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
        {
            strcpy_s(L[i].majo, tmp);
            tmp = strtok(NULL, ",?");
            printf("%s\n", L[i].majo);

            i++;
            k++;

            continue;
        }        
    }
    fclose(p_file);
}



//void file_O(list* L) 
//{
//    FILE* p_file;
//    char* tmp;
//    char str[100];
//
//    p_file = fopen("list.csv", "r");
//    fgets(str, 100, p_file);
//    int k = 0;
//    int i = 0;
//
//    while (k < 24)
//    {
//        fgets(str, 100, p_file);
//        //printf("%s\n", str);
//        tmp = strtok(str, ",");
//
//        if (!(tmp == NULL || !strcmp(tmp, "\n")))    //tmp == NULL이게되면 strcmp를 하지 못해요
//        {
//            printf("%s\n", tmp);
//
//            if (0 == strcmp(tmp, "조장"))
//            {
//                strcpy(L[i].mana, tmp);
//                tmp = strtok(NULL, ",");
//                //printf("%s\n", L[i].mana);
//                //printf("%s\n", tmp);
//            }
//
//            strcpy_s(L[i].comp, tmp);
//            tmp = strtok(NULL, ",");
//            printf("%s\t", L[i].comp);
//
//            strcpy_s(L[i].name, tmp);
//            tmp = strtok(NULL, ",");
//            printf("%s\t", L[i].name);
//
//            strcpy_s(L[i].mail, tmp);
//            tmp = strtok(NULL, ",");
//            printf("%s\t", L[i].comp);
//
//            strcpy_s(L[i].grad, tmp);
//            tmp = strtok(NULL, ",");
//            printf("%s\t", L[i].grad);
//
//            strcpy_s(L[i].majo, tmp);
//            tmp = strtok(NULL, ",");
//            printf("%s\n", L[i].majo);
//
//            i++;
//            k++;
//
//            continue;
//        }
//    }
//    fclose(p_file);
//}

//void check(list* L)
//{
    //for (int i = 0; i < 24; i++)
    //{
    //    if (L[i].comp[0] == '?')
    //    {
    //        for (int j = 0; j<strlen(L[i].comp) - 1; j++)
    //        {
    //            printf("%c", L[i].comp[j]);
    //            //L[i].comp[j] = L[i].comp[j + 1];
    //        }
    //    }
    //    if (L[i].name[0] == '?')
    //    {
    //        for (int j = 0; j < strlen(L[i].name) - 1; j++)
    //        {
    //            L[i].name[j] = L[i].name[j + 1];
    //        }
    //    }
    //    if (L[i].mail[0] == '?')
    //    {
    //        for (int j = 0; j < strlen(L[i].mail) - 1; j++)
    //        {
    //            L[i].mail[j] = L[i].mail[j + 1];
    //        }
    //    }
    //    if (L[i].grad[0] == '?')
    //    {
    //        for (int j = 0; j < strlen(L[i].grad) - 1; j++)
    //        {
    //            L[i].grad[j] = L[i].grad[j + 1];
    //        }
    //    }
    //    if (L[i].majo[0] == '?')
    //    {
    //        for (int j = 0; j < strlen(L[i].majo); j++)
    //        {
    //            L[i].majo[j] = L[i].majo[j + 1];
    //        }
    //    }
        /*for (int j = 0; j < 50; j++)
        {
            if (L[i].comp[0] == '?')
            {
                L[i].comp[j] = L[i].comp[j + 1];
            }
            if (L[i].name[0] == '?')
            {
                L[i].name[j] = L[i].name[j + 1];
            }
            if (L[i].mail[0] == '?')
            {
                L[i].mail[j] = L[i].mail[j + 1];
            }
            if (L[i].grad[0] == '?')
            {
                L[i].grad[j] = L[i].grad[j + 1];
            }
            if (L[i].majo[0] == '?')
            {
                L[i].majo[j] = L[i].majo[j + 1];
            }
        }*/
//    }
//}

