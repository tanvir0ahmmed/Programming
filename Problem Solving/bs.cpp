#include<stdio.h>
#define ll long long int
ll Binary_Search(ll x)
{
    ll low=0,hi=1e18,move=0,mid=0;
    while(low<hi)
    {
        mid=(low+hi)/2;
        printf("%lld\n",mid);
        if(mid<x)low=mid+1;
        else hi=mid;
        printf("%lld %lld\n",low,hi);
        move++;

    }
    return move;
}

int main()
{
    ll x;
    scanf("%lld",&x);
    printf("%lld\n",Binary_Search(x)); //out put always 60 , why??
}

