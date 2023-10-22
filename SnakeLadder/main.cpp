#include<bits/stdc++.h>
#include "board.hpp"
using namespace std;

int main()
{
    player p1(1, "sakruthi", "sakruthi@gmail.com");
    player p2(2, "bunny", "bunny@gmail.com");
    
    unordered_map<int, int> mp;
    mp[1] = 0;
    mp[2] = 0;
    
    queue<player> q;
    q.push(p1);
    q.push(p2);

    dice d(1);
    
    vector<snakesLadder> snakes;
    vector<snakesLadder> ladders;
    
    snakesLadder snake1(80, 5);
    snakesLadder snake2(40, 10);
    snakesLadder snake3(66, 25);
    
    snakes.push_back(snake1);
    snakes.push_back(snake2);
    snakes.push_back(snake3);
    
    snakesLadder ladder1(12, 70);
    snakesLadder ladder2(30, 85);
    snakesLadder ladder3(23, 92);
    
    ladders.push_back(ladder1);
    ladders.push_back(ladder2);
    ladders.push_back(ladder3);
    
    board *b = board::getInstance();
    b->initilize( 100, q, snakes, ladders, d, mp);
    board * b1 = board::getInstance();
        board * b2 = board::getInstance();

    

    b2->start();
}
