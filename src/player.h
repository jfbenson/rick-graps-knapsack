#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

typedef enum {
    P_PG = 0,
    P_SG = 1,
    P_SF = 2,
    P_PF = 3,
    P_C = 4,
} pos_t;

typedef struct player_s {
    string name;
    unsigned char position_ids;
    long double salary;
    long double proj_pts;
} player_t;

player_t player_populate(string row);
void player_print(player_t &p);

#endif /* PLAYER_H */
