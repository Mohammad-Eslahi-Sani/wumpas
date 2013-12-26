#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include "board.h"
#include "god.h"
#include "human.h"
#include "monster.h"
using namespace std;
int main()
{
	int n;
	srand(time(NULL));
	god g;
	while(1)
	{
		g.update_board();
		if(g.Win_Or_Lose()==0)
		{
			cout<<"you lose";
			break;
		}
		else
			if(g.Win_Or_Lose()==1)
			{
				cout<<"you won"<<endl;
				break;
			}
		g.check_human();
		g.check_monster();
		g.get_key();
		g.big_check();
		
	}
	cin>>n;
	
	return 0;
}
