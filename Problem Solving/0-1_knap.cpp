///0-1 knapsack
/*
3 10
3 2 3
3 1 4
3 7 3
3 9 5
2 9 5

5 5
3 1 1
3 2 1
3 3 1
3 4 1
3 5 1
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int mi[10],sec[10],le[10],r=500,r1=500,h,d;
void rec(int c,int c1,int c2,int d1)
{
    if(d1==d)
    {
        if(c2<=h)
        {
            if(r>c)
            {
                r=c;
                r1=c1;
            }
            else if(r==c&&r1>c1)r1=c1;
            //cout<<r<<" "<<r1<<"\n";
            return;
        }
        else
            return;
    }
    for(int i=0; i<5; i++)
    {
        rec(mi[i]+c,sec[i]+c1,le[i]+c2,d1+1);
    }
}
int main()
{
    cin>>d>>h;
    for(int i=0;i<5;i++)
    {
        cin>>mi[i]>>sec[i]>>le[i];
    }
    rec(0,0,0,0);
    cout<<r<<" "<<r1<<"\n";

}
