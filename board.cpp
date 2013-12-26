#include "board.h" // class's header file
#include <cstdlib>
#include "god.h"
board::board()
{
	//initialize all to 0

	
	
	for(int i=0 ; i<20 ; i++)
	{
		vector<int> v(20);
		
		board1.push_back(v);
		
		for(int j=0 ; j<20 ; j++)
		{
			board1[i][j] = 0;
		}
	}


	int rand_num = 0 ;
	int i=0 , j=0 ;
	bool ch = true;
	
		//randomly initialize the peats positions	
	for(int index=0 ; index<40 ; index++)
	{
		pair<int,int> tempPair;
		peat_pos.push_back(tempPair);
	
		ch = true ;
		while(ch)
		{
			rand_num = rand() % 400;
			i = rand_num / 20;
			j = rand_num % 20;
			if( board1[i][j] == 0)
			{
				board1[i][j] = 1;
				peat_pos[index].first = i;
				peat_pos[index].second = j;
				ch = false;
			}		 	
		}
	}

	//randomly initialize the human position
	ch = true;
	
	while(ch)
	{
		rand_num = rand() % 400;
		i = rand_num / 20;
		j = rand_num % 20;
		if( board1[i][j] == 0)
		{
			board1[i][j] = 2 ;
			ch = false;
		}		 	
	}
	
	
	//randomly initilaize the monster position
	ch = true;
	while(ch)
	{
		rand_num = rand() % 400;
		i = rand_num / 20;
		j = rand_num % 20;
		if( board1[i][j] == 0)
		{
			board1[i][j] = 3;
			ch = false;
		}		 	
	
	}
	
	//randomly initilaize the gold position
	ch = true;
	while(ch)
	{
		rand_num = rand() % 400;
		i = rand_num / 20;
		j = rand_num % 20;
		if( board1[i][j] == 0)
		{
			board1[i][j] = 4;
			ch = false;
		}		 	
		
	}
	
}

int board::get_cell(int x,int y)
{
	return board1[x][y];
}

pair<int,int> board::get_human_pos()
{
	pair<int,int> result;
	
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			if( board1[i][j] == 2 )
			{
				result.first = i;
				result.second = j;
			}
		}
	}
	return result;
}

pair<int,int> board::get_monster_pos()
{
	pair<int,int> result;
	
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			if( board1[i][j] == 3 )
			{
				result.first = i;
				result.second = j;
			}
		}
	}
	return result;	
}

void board::set_human_pos(pair<int,int> in_pos)
{
	human_pos.first = in_pos.first;
	human_pos.second = in_pos.second;
}

void board::set_monster_pos(pair<int,int> in_pos)
{
	human_pos.first = in_pos.first;
	human_pos.second = in_pos.second;
}

int board::get_numberOfPeat()
{
	int num_peat = 0;
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			if( board1[i][j] == 1 )
				num_peat++;
		}
	}
	return num_peat;	
	
}

bool board::human_die()
{
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			if( board1[i][j] == 2 )
				cout<<"humand is not dead!\n";
				return false;
		}
	}
	cout<<"human is dead!\n";
	return true;
}

bool board::gold_exist()
{
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			if( board1[i][j] == 4 )
				return true;
		}
	}
	return false;
}

void board::show()
{
	cout<<endl;
	
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			switch(board1[i][j])
			{
				case 0:
					cout<<" ";
					break;
					
				case 1:
					cout<<"P";
					break;
				
				case 2:
					cout<<"H";
					break;
				
				case 3:
					cout<<"M";
					break;
				
				case 4:
					cout<<"G";	//gold
					break;			
			}
			cout<<" ";				
		}
		cout<<endl;
	}	
	cout<<endl;
	cout<<"____________________________________________________\n";
	
}

pair<int,int> board::which_peat_missed()
{
	if(get_numberOfPeat()<40)
		return get_monster_pos();
}

pair<int,int> board::get_gold_pos()
{
	pair<int,int> result;
		
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			if( board1[i][j] == 4 )
			{
				result.first = i;
				result.second = j;
			}
		}
	}
	return result;		
}
