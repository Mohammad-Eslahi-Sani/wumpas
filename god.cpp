#include<iostream>
#include<vector>
#include<string>
#include"god.h"
#include"board.h"
#include"human.h"
#include"monster.h"
using namespace std;
god::god()
{
	pair<int,int> human_firstpos;
	pair<int,int> monster_firstpos;	
	human_firstpos = b.get_human_pos();
	monster_firstpos = b.get_monster_pos();
	h.set_firstpos(human_firstpos.first,human_firstpos.second);
	m.set_firstpos(monster_firstpos.first,monster_firstpos.second);
}
void god::update_board()
{
	/*
	for(int i=0;i<19;i++)
		for(int j=0;j<19;j++)
			if(b.get_cell(i,j) == 2 || b.get_cell(i,j) ==3 )
				b.board1[i][j]=0;
	*/
	if(b.gold_exist()==false)
	{
		pair<int,int> gold=b.get_gold_pos();
		b.board1[gold.first][gold.second]=4;
	}
	if(m.get_lastmove()==true)
	{
		b.board1[monster_lastmove.first][monster_lastmove.second]=1;
		m.set_lastmove(false);
	}
	 
	b.set_human_pos(h.get_pos());
	b.board1[h.get_pos().first][h.get_pos().second] = 2;
	
	b.set_monster_pos(m.get_pos());
	
	b.show();
}
void god::get_key()
{
	
	v = h.get_pos().first;
	w = h.get_pos().second;
	
	char key;
	cin>>key;
	
	switch (key)
	{
	case 97:
		if(b.board1[v][w-1]==3 || b.board1[v][w-1]==1)
			{
				b.board1[v][w]=0;
				//h.set_alive(false);
				//h.position.first = 0;
				//h.position.second = 0;
				break;
			}
		h.set_pos("left");
		break;
	case 119:
		if(b.board1[v-1][w]==3 || b.board1[v-1][w]==1)
			{
				b.board1[v][w]=0;
				//h.set_alive(false);
				//h.position.first = 0;
				//h.position.second = 0;
				
				break;
			}
		h.set_pos("up");
		break;
	case 100:
		if(b.board1[v][w+1]==3 || b.board1[v][w+1]==1)
			{
				b.board1[v][w]=0;
				//h.set_alive(false);
				//h.position.first = 0;
				//h.position.second = 0;
				
				break;
			}
		h.set_pos("right");
		break;
	case 115:
		if(b.board1[v+1][w]==3 || b.board1[v+1][w]==1)
			{
				b.board1[v][w]=0;
				//h.set_alive(false);
				//h.position.first = 0;
				//h.position.second = 0;
				
				break;
			}
		h.set_pos("down");
		break;
	default:
		break;
	}
	if(m.bget_see_human()==true)
		m.set_pos(m.see_move(h.get_pos()));
	else
		m.set_pos(m.move());
	
	b.board1[v][w] = 0;
}
void god::check_human()
{
	pair <int,int> human_pos=h.get_pos();
	if(human_pos.first>0)
		if(b.get_cell(human_pos.first-1,human_pos.second)==1 || b.get_cell(human_pos.first-1,human_pos.second)==4 ||
			b.get_cell(human_pos.first-1,human_pos.second)==3)
			h.setfeel(b.get_cell(human_pos.first-1,human_pos.second));
	if(human_pos.first<19)
		if(b.get_cell(human_pos.first+1,human_pos.second)==1 || b.get_cell(human_pos.first+1,human_pos.second)==4 ||
			b.get_cell(human_pos.first+1,human_pos.second)==3)
			h.setfeel(b.get_cell(human_pos.first+1,human_pos.second));
	if(human_pos.second>0)
		if(b.get_cell(human_pos.first,human_pos.second-1)==1 || b.get_cell(human_pos.first,human_pos.second-1)==4 ||
			b.get_cell(human_pos.first,human_pos.second-1)==3)
			h.setfeel(b.get_cell(human_pos.first,human_pos.second-1));
	if(human_pos.second<19)
		if(b.get_cell(human_pos.first,human_pos.second+1)==1 || b.get_cell(human_pos.first,human_pos.second+1)==4 ||
			b.get_cell(human_pos.first,human_pos.second+1)==3)
			h.setfeel(b.get_cell(human_pos.first,human_pos.second+1));
	cout<<"feeling gold"<<h.getfeel_gold()<<"\nfeeling peat"<< h.getfeel_peat()<<"\nfeeling monster"<<h.getfeel_monster()<<endl;
}
void god::check_monster()
{
	pair <int,int> monster_pos=m.get_pos();
	if(monster_pos.first>0)
		if(b.get_cell(monster_pos.first-1,monster_pos.second)==2)
			m.set_see(true);
	if(monster_pos.first<19)
		if(b.get_cell(monster_pos.first+1,monster_pos.second)==2)
			m.set_see(true);
	if(monster_pos.second>0)
		if(b.get_cell(monster_pos.first,monster_pos.second-1)==2)
			m.set_see(true);
	if(monster_pos.second<19)
		if(b.get_cell(monster_pos.first,monster_pos.second+1)==2)
			m.set_see(true);
}
void god::big_check()
{
	pair<int,int> missed;
	if(b.get_numberOfPeat()!=40)
	{
		if(b.get_numberOfPeat()==39)
		{
			missed=b.which_peat_missed();
			if(missed==h.get_pos())
				h.set_alive(false);
			if(missed==m.get_pos())
			{
				m.set_lastmove(true);
				monster_lastmove=missed;
			}
		}
		else
			h.set_alive(false);
	}
	
	if(b.gold_exist()==false)
	{
		if(false)
			h.set_win(true);
	}
	
	if(b.human_die())
		h.set_alive(false);

}
int god::Win_Or_Lose()
{
	/*
	if(!h.get_alive())
		return 0;
	if(h.get_win())
		return 1;
	*/
	return 2;
}
