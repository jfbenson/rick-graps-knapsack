#include "player.h"
#include "player_pool.h"

using namespace std;


static bool is_valid_lineup(player_t *roster, size_t num_players);

int main(int argc, char** argv)
{
    PlayerPool player_pool;
    string filename("../data/projections.txt");
    player_pool.import(filename);
    return 0;
}

static bool is_valid_lineup(player_t *roster, size_t num_players)
{
}
