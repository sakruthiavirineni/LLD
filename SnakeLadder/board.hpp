#include<bits/stdc++.h>
#include "player.cpp"
#include "dice.cpp"
#include "snakesladder.cpp"
using namespace std;

class board
{
    int size;
    queue<player>q;
    vector<snakesLadder> snakes;
    vector<snakesLadder> ladders;
    dice d;
    unordered_map<int, int> mp;
    static board* b;
    
    private :
        board() {}
        
    public:
        
        static board *getInstance()
        {
            if(b == nullptr)
            {
                cout<<"sunny---";
                b = new board();
            }
            return b;
        }
        
        void initilize( int size, queue<player> q, vector<snakesLadder> snakes, vector<snakesLadder> ladders, dice d,
                        unordered_map<int, int> mp )
        {
            this->size = size;
            this->q = q;
            this->snakes = snakes;
            this->ladders = ladders;
            this->d = d;
            this->mp = mp;
        }
        
        void start()
        {
            while(q.size()>1)
            {
                auto it = q.front();
                q.pop();
                int curPos = mp[it.id];
                
                int rollNo = d.roll();
                cout<<"dice rolling ..... it's "<<it.name<<" turn :) standing at "<<curPos<<endl;
                cout<<"diced number : "<<rollNo<<endl;
                cout<<endl;
                int tempPos = rollNo + curPos;
                
                if( tempPos > size )
                {
                    q.push(it);
                    continue;
                }
                
                for( auto i : snakes)
                {
                    if(i.start == tempPos)
                    {
                         tempPos = i.end;
                         cout<<it.name<<" has bitten by a snake ans is currently at "<<tempPos<<endl;
                    }
                }
                
                for( auto i : ladders)
                {
                    if(i.start == tempPos)
                    {
                         tempPos = i.end;
                         cout<<it.name<<" has climbed a ladder ans is currently at "<<tempPos<<endl;
                    }
                }
                
                if( tempPos == size )
                {
                    cout<<it.name<<" has won the game"<<endl;
                }
                else
                {
                    q.push(it);
                    mp[it.id] = tempPos;
                    cout<<it.name<<" is currently at "<<tempPos<<endl;
                }
                                cout<<endl;                cout<<endl;
            }
        }
        
};

board *board::b = nullptr;
