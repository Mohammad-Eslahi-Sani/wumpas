#include<iostream>
#include<vector>
using namespace std;
/*
20*20
num_of_peat = 40;
gold=4
peat=1
human=2
monster=3
null=0
*/
#ifndef BOARD_H
#define BOARD_H
class board
{
private:
	pair<int,int> human_pos;
	pair<int,int> monster_pos;
	vector< pair<int,int> > peat_pos;
	pair<int,int> gold_pos;

public:
	board();
	vector< vector < int > > board1;
	int get_cell(int,int);	//adade motenazere ba mojoode dar an khane ra barmigardanad!
	pair<int,int> get_human_pos();
	pair<int,int> get_monster_pos();
	void set_human_pos(pair<int,int>);
	void set_monster_pos(pair<int,int>);
	int get_numberOfPeat();
	bool human_die();
	bool gold_exist();
	void show();
	pair<int,int> which_peat_missed();
	pair<int,int> get_gold_pos();
};
#endif
