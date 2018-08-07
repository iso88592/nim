#include <iostream>

using namespace std;

int main(void)
{
    int nextStep[26];
    nextStep[0] = 0;
    nextStep[1] = 1;
    nextStep[2] =-1;
    nextStep[3] = 3;
    for (int i = 4; i < 26; i++)
    {
        nextStep[i] = -4;
        for (int j = 4; j >= 1; j--)
        {
            if (j == 2) continue;
            if (nextStep[i-j] <=0) 
            {
                nextStep[i] = j;
                break;
            }
        }
    }
    int floor = 25;
    while (floor != 0)
    {
        cout<<"You are on floor "<<floor<<"! Lower the level by 1, 3, or 4!"<<endl;
        int lower = 0;
        while ((lower < 1) || 
               (lower == 2) ||
               (lower > 4) ||
               (floor - lower < 0))
        {
            cout<<"Lower the level by: ";
            cin>>lower;
        }
        floor -= lower;
        if (floor == 0)
        {
            cout<<"Congratulations, you won!"<<endl;
            return 0;
        }
        lower = nextStep[floor];
        if (lower < 0) lower *= -1;
        cout<<"The mighty NIM chooses to lower the level by " << lower <<endl;
        floor -= lower;
        if (floor == 0)
        {
            cout<<"You fool! NIM always wins!"<<endl;
            return 0;
        }
    }
}