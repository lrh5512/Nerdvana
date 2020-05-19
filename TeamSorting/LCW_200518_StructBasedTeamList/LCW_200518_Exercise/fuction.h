#pragma once
#include "Team.h"

int fileIO(Team* t, int tnum, char buf);
void ExitProgram(Team* t, int tnum);

void sortID(Team* t, int tnum);
void sortTeamName(Team* t, int tnum);
void sortCompany(Team* t, int tnum);