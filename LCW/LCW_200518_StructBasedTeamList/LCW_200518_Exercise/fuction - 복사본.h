#pragma once

#include "Team.h"
#include <time.h>

#define RLEN 2048


int fileIO(Team* t, int tnum, char buf);
void ExitProgram(Team* t, int tnum);

void sortID(Team* t, int tnum);
void sortTeamName(Team* t, int tnum);
void sortCompany(Team* t, int tnum);

void SearchLeaderName(Team* t, int tnum);
void SearchCompany(Team* t, int tnum);
void SearchName(Team* t, int tnum);
void SearchSchool(Team* t, int tnum);
void saveSearchResult(char** content, int num);