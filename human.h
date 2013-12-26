#include<iostream>
#include<vector>
#include<string>
using namespace std;
#ifndef	HUMAN_H
#define HUMAN_H
class human
{
private:
	int bullet;
	
	bool alive;
	bool feel_gold;
	bool feel_peat,feel_monster,is_win;
public:
	pair<int,int> position;
	human();
	void set_firstpos(int,int);
	void set_pos(string);
	void setfeel(int);
	void set_alive(bool);
	bool is_alive();
	pair<int,int> get_pos();
	bool getfeel_gold();
	bool getfeel_peat();
	bool getfeel_monster();
	bool get_bullet();
	bool get_alive();
	void set_win(bool);//new
	bool get_win();
};
#endif
