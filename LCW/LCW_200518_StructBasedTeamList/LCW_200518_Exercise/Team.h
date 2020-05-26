#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define MAXLEN 50

struct Team
{
	int id;
	char name[MAXLEN];
	char company[MAXLEN];
};

//struct Team {
//	int isLeader;
//	char company[MAXLEN];
//	char name[MAXLEN];
//	char email[MAXLEN];
//	char school[MAXLEN];
//	char major[MAXLEN];
//};

void print_list(struct Team* t, int tnum);
int addTeamInfo(Team* t, int tnum);
void modifyTeamInfo(Team* t, int tnum);
int deleteTeamInfo(Team* t, int tnum);