#include <iostream>
#include <vector>
#include "board.h"
#include "human.h"
#include "monster.h"
#include <string>
using namespace std;
class god
{
	pair<int,int> monster_lastmove;
public:
	int v,w;
	board b;
	human h;
	monster m;
	god();
	void update_board();
	void get_key();
	void check_human();
	void check_monster();
	void big_check();//new
	int Win_Or_Lose();
};
