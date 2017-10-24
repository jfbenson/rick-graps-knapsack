#include "player_pool.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

player_pool_t player_pool;

bool player_pool_import(string const &filename)
{
    // Populate player list
    ifstream projections_file;

    string line = "";
    projections_file.open(filename);
    getline(projections_file, line);

    while (true)
    {
        getline(projections_file, line);
        if (!projections_file)
            break;

        player_t p = player_populate(line);
        player_pool.insert({p.name, p});
        player_print(p);
    }
}
