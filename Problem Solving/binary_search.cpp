///3 2 0 729814
#include<iostream>
#include<stdio.h>
using namespace std;
long long int l,h,mid,a,b,c,y,r,ans=0;
int main()
{
    cin>>a>>b>>c>>y;
    if(c==0)
    {
        l=0;
        h=1000000000000000000;
        //cout<<h<<"\n";
        while(l<=h)
        {
            mid=(l+h)/2;
            r=(2*b+a*mid)+(2*a*mid)+(c*mid*mid*mid);
            ///cout<<r<<"\n";
            if(r==y)
                break;
            else if(r<y)
                l=mid+1;
            else
                h=mid-1;
        }
        if(r==y)
            cout<<mid<<"\n";
        else
            cout<<"0\n";
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
