#include "human.h" // class's header file

human::human()
{
	alive = true;
	is_win = false;
	
}

void human::set_firstpos(int x,int y)
{
	
	position.first = x;
	position.second = y;

}

void human::set_pos(string in_command)
{
	//check();	
	if(in_command == "up")
		position.first--;
			
	else if(in_command == "down")
		position.first++;
			
	else if(in_command == "right")
		position.second++;
	
	else if(in_command == "left"){
		position.second--;
	}
}

void human::setfeel(int in_feel)
{
	switch(in_feel)
	{
		case 1:
			feel_peat = true;
			break;
			
		case 3:
			feel_monster = true;
			break;
			
		case 4:
			feel_gold = true;
			break;
	}
}

void human::set_alive(bool a)
{
	alive = a;
}

bool human::is_alive()
{
	return alive;
}

pair<int,int> human::get_pos()
{
	return position;
}

bool human::getfeel_gold()
{
	return feel_gold;
}

bool human::getfeel_peat()
{
	return feel_peat;
}

bool human::getfeel_monster()
{
	return feel_monster;
}

bool human::get_bullet()
{
	return bullet;
}

bool human::get_alive()
{
	return alive;
}

void human::set_win(bool w)//new
{
	is_win = w;
}

bool human::get_win()
{
	return is_win;
}

