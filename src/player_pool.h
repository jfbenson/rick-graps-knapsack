#ifndef PLAYER_POOL_H
#define PLAYER_POOL_H

#include "player.h"

#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, player_t> player_pool_t;

player_pool_t player_pool;

bool player_pool_import(string filename);
void player_pool_filter();

#endif /* PLAYER_POOL_H */
