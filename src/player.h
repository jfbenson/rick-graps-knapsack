#ifndef PLAYER_H
#define PLAYER_H

#include <bitset>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

typedef enum pos_t {
    P_PG = 0,
    P_SG = 1,
    P_SF = 2,
    P_PF = 3,
    P_C = 4,
};

typedef struct player_t {
    string name;
    unsigned char position_ids;
    long double salary;
    long double proj_pts;
} player_t;

player_t player_populate(string row)
{
    player_t p;
    vector<string> parts;
    split(parts, row, is_any_of("\t"));

    p.name = parts[0];

    p.position_ids = 0;
    p.position_ids |= (parts[1].find("PG") != string::npos) ? 1 << P_PG : 0;
    p.position_ids |= (parts[1].find("SG") != string::npos) ? 1 << P_SG : 0;
    p.position_ids |= (parts[1].find("SF") != string::npos) ? 1 << P_SF : 0;
    p.position_ids |= (parts[1].find("PF") != string::npos) ? 1 << P_PF : 0;
    p.position_ids |= (parts[1].find("C") != string::npos) ? 1 << P_C : 0;

    istringstream sal(parts[3]);
    sal.imbue(locale("en_US.UTF-8"));
    sal >> get_money(p.salary);

    p.proj_pts = stold(parts[15]);

    return p;
}

void player_print(player_t &p)
{
    cout << p.name;
    cout << "\t" << bitset<16>((int)p.position_ids);
    cout << "\t" << p.salary;
    cout << "\t" << p.proj_pts << endl;
}

#endif /* PLAYER_H */
