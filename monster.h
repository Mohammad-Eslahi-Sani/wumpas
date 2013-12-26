#include<iostream>
#include<vector>
#include<string>
using namespace std;
#ifndef MONSTER_H
#define MONSTER_H
class monster 
{
	pair<int,int> position;
	bool alive,see_human,last_moveon_peat;
public:
	monster();
	void set_firstpos(int,int);
	string move();
	string see_move(pair<int,int>);
	void set_see(bool);
	void set_pos(string);
	pair<int,int> get_pos();
	bool is_alive();
	void set_alive(bool);
	bool bget_see_human();
	void set_lastmove(bool);//new
	bool get_lastmove();//new
	pair<int,int> get_see_human();
};
#endif
