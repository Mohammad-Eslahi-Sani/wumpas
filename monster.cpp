#include "monster.h" // class's header file
#include <cstdlib>
#include "god.h"
#include "board.h"
#include <vector>
#include <iostream>
using namespace std;
monster::monster()
{
	
}

void monster::set_firstpos(int x,int y)
{
	position.first = x;
	position.second = y;
}

string monster::move()
{
	int randnum = rand()%4;
	
	switch(randnum)
	{
		case 0:
			return "up";
		case 1:
			return "down";
		case 2:
			return "left";
		case 3:
			return "right";
	}		
}

string monster::see_move(pair<int,int> in_pos)
{
	
	if(in_pos.first > position.first )
		return "right";
	
	else if(in_pos.first < position.first )
		return "left";
	
	else if(in_pos.second > position.second)
		return "down";

	else if(in_pos.second < position.second)
		return "up";
}

void monster::set_see(bool in_see)
{
	see_human = in_see;
}

void monster::set_pos(string in_s)
{
	if(in_s == "up")
		position.second--;
		
	else if(in_s == "down")
		position.second++;
		
	else if(in_s == "right")
		position.first++;
	
	else if(in_s == "left")
		position.first--;
	
}

pair<int,int> monster::get_pos()
{
	return position;
}

bool monster::is_alive()
{
	return alive;
}

void monster::set_alive(bool in_alive)
{
	alive = in_alive;
}

bool monster::bget_see_human()
{
	return see_human;
}

void monster::set_lastmove(bool in_lastmove)//new
{
	last_moveon_peat = in_lastmove;
}

bool monster::get_lastmove()//new
{
	return last_moveon_peat;
}

/*
pair<int,int> monster::get_see_human()
{
	pair<int,int> result;
	for(int i=-1; i<2; i++)
	{
		for(int j=-1; j<2; j++)
		{
			if(b.board1[i + position.first][j + position.second]==2)
			{
				result.first = i + position.first;
				result.second = j + position.second;
			}
			
		}
	} 
	return result;
}
*/

