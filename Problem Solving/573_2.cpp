#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    double h,u,d,f,r,r1,r2,r3,r4;
    while(1)
    {
        int t=0;
        cin>>h>>u>>d>>f;
        r2=u;
        if(h==0.0)
            break;
        r=(f/100.0)*u;
        while(1)
        {
            if(u>=h)
            {
                cout<<"success on day "<<t<<endl;
                    break;
            }
            r=u-d;


        }
    }
}
