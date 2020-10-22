#include<bits/stdc++.h>
using namespace std;
int a,b,c,c2=0,n,dp[10000];
void rec1(int n,int c1)
{
    if(n<0)
        return;
    else if(n==0)
    {
        c2=max(c1,c2);
        return;
    }
    else if(dp[n]==1)return;
    dp[n]=1;
    rec1(n-a,c1+1);
    rec1(n-b,c1+1);
    rec1(n-c,c1+1);
}
int main()
{
    int a1[5];
    cin>>n>>a1[0]>>a1[1]>>a1[2];
    sort(a1,a1+3);
    a=a1[0];
    b=a1[1];
    c=a1[2];
    rec1(n,0);
    cout<<c2<<"\n";
}
