#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define StuNum 24
#define ColNum 6
#define MAXLINE 256
#define CharNum 4
typedef struct
{
	bool lea;
	char company[30];
	char name[10];
	char email[50];
	char school[30];
	char major[50];
}Info;
void SearchByName(Info*, char*);
void SearchByCom(Info*, char*);
void SearchBySchool(Info*, char*);
void SearchByLeader(Info*, char*);
void print_info(Info);
int ReadCsvFile(char*, Info *);
