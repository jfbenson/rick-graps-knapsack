#ifndef ROSTER_H
#define ROSTER_H

#include "player.h"

bool is_roster_valid(roster_t &roster);
bool is_roster_complete(roster_t &roster);
long unsigned int calc_roster_cost(roster_t &roster);
long unsigned int calc_roster_points(roster_t &roster);

void print_roster(roster_t &roster);

#endif /* ROSTER_H */
