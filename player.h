#ifndef PLAYER_H
#define PLAYER_H

#include <string>

typedef enum pos_t {
    P_PG = 0,
    P_SG = 1,
    P_SF = 2,
    P_PF = 3,
    P_C = 4,
};

typedef struct player_t {
    string name;
    float cost;
    float value;
    pos_t position;
} player_t;

#endif /* PLAYER_H */
