
#include<iostream>
#include<stdio.h>
using namespace std;
long long int a,b,c,y,r,ans=0;
int main()
{
    cin>>a>>b>>c>>y;
    if(c==0)
    {
        if((y-(2*b))%(3*a)==0)
            cout<<(y-(2*b))/(3*a)<<"\n";
        else cout<<"0\n";

    }
    else
    {
        for(int i=1;i<=1000000;i++)
        {
            r=(2*b+a*i)+(2*a*i)+(c*i*i*i);
            if(r==y){ans=i;break;}
        }
        cout<<ans<<"\n";
    }
}
