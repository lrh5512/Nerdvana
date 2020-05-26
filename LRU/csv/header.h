#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXLEN 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    bool leader{ false };
    char company[MAXLEN]{ 0, };
    char name[MAXLEN]{ 0, };
    char email[MAXLEN]{ 0, };
    char school[MAXLEN]{ 0, };
    char major[MAXLEN]{ 0, };
} KSA;

void file(KSA* list);
void search_leader(KSA* list);
void search_company(KSA* list);
void search_name(KSA* list);
void search_school(KSA* list);

