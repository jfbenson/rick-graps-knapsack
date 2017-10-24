#include "player.h"
#include "player_pool.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static bool is_valid_lineup(player_t *roster, size_t num_players);

int main(int argc, char** argv)
{
    // Populate player list
    ifstream projections_file;

    string line = "";
    projections_file.open("../data/projections.txt");
    getline(projections_file, line);

    while (true)
    {
        getline(projections_file, line);
        if (!projections_file)
            break;

        player_t p = player_populate(line);
        player_print(p);
    }

    return 0;
}

static bool is_valid_lineup(player_t *roster, size_t num_players)
{
}
