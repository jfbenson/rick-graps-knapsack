#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

typedef enum {
    P_PG = 1,
    P_SG = 2,
    P_SF = 4,
    P_PF = 8,
    P_C = 16,
} pos_t;

struct player_t {
    string name;

    unsigned char pos_ids;
    long double salary;
    long double proj_pts;
};

player_t player_populate(string row);
void player_print(player_t &p);

#endif /* PLAYER_H */
