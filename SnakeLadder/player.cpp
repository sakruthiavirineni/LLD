#include<bits/stdc++.h>
using namespace std;

struct stats
{
    int wins;
    int loss;
    int total;
    double winPercentage;
};

class player
{
    public:
        int id;
        string name;
        string email;
        int level;
        stats s;
      
    public:

        player(int id, string name, string email)
        {
            this->id = id;
            this->name = name;
            this->email = email;
        }
};
