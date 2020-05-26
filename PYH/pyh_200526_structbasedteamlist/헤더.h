#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct list
{
    char mana[10] = { "Á¶¿ø", };
    char comp[20];
    char name[20];
    char mail[50];
    char grad[50];
    char majo[50];
};

void file_I(list* L);
//void check(list* L);
int search(list* L);
int Mana_Sear(list* L);
int Comp_Sear(list* L);
int Name_Sear(list* L);
int Grad_Sear(list* L);
int Majo_Sear(list* L);
