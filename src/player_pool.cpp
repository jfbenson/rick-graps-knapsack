#include "player_pool.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool PlayerPool::import(string const &filename)
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
        insert(p);

        player_print(p);

    }

    cout << "\n=========================\n" << "     POINT GUARDS     \n" << "=========================\n" << endl; 
    for (auto& pg : pg_map)
    {
        auto p = pg.second;
        cout << p.name << "\t\t:\t$" << p.salary << "\t:\t" << p.proj_pts << endl;
    }
}

bool PlayerPool::insert(player_t& p)
{
    pool.insert({p.name, p});

    if (p.pos_ids & P_PG)
        pg_map.insert({p.proj_pts, p});
    if (p.pos_ids & P_SG)
        sg_map.insert({p.proj_pts, p});
    if (p.pos_ids & P_SF)
        sf_map.insert({p.proj_pts, p});
    if (p.pos_ids & P_PF)
        pf_map.insert({p.proj_pts, p});
    if (p.pos_ids & P_C)
        c_map.insert({p.proj_pts, p});
}
