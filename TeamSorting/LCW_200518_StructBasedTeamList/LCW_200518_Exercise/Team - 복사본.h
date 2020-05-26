#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#define MAX 30
#define MAXLEN 50

//struct Team
//{
//	int id;
//	char name[MAXLEN];
//	char company[MAXLEN];
//};

typedef struct Team {
	int isLeader = 0;
	char company[MAXLEN];
	char name[MAXLEN];
	char email[MAXLEN];
	char school[MAXLEN];
	char major[MAXLEN];
};

void print_list(struct Team* t, int tnum);

int addTeamInfo(Team* t, int tnum);
void modifyTeamInfo(Team* t, int tnum);
int deleteTeamInfo(Team* t, int tnum);

void Pruning(Team* t, int tnum);