#ifndef PLAYER_POOL_H
#define PLAYER_POOL_H

#include "player.h"

#include <map>
#include <string>
#include <unordered_map>
using namespace std;

typedef unordered_map<string, player_t> player_pool_t;

typedef map<long double, player_t, std::greater<long double> > player_map_t;
typedef map<long double, player_t, std::greater<long double> > pg_map_t;
typedef map<long double, player_t, std::greater<long double> > sg_map_t;
typedef map<long double, player_t, std::greater<long double> > sf_map_t;
typedef map<long double, player_t, std::greater<long double> > pf_map_t;
typedef map<long double, player_t, std::greater<long double> > c_map_t;


class PlayerPool {
  public:
    player_pool_t pool;

    bool import(string const &filename);

  private:
    // These are sorted by projected value
    player_map_t player_map;
    pg_map_t pg_map;
    sg_map_t sg_map;
    sf_map_t sf_map;
    pf_map_t pf_map;
    c_map_t c_map;

    bool insert(player_t& player);
};

#endif /* PLAYER_POOL_H */
