#include<bits/stdc++.h>
using namespace std;

class dice
{
    int noOfDice;
    
    public:
        dice()
        {
            srand(time(NULL));
        }
        
        dice(int no)
        {
            srand(time(NULL));
            this->noOfDice = no;
        }
        
        int roll()
        {
            int ans = rand() %( 6*noOfDice - 1*noOfDice + 1) + (1*noOfDice);
            return ans;
        }
};
