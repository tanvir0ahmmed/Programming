#include<iostream>
#define ll long long
using namespace std;
ll n,arr[1001],r,i,j,mp[1001],temp,r1=0;
int main()
{
    cin>>n;
    arr[0]=1;
    arr[n+1]=1;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    for(i=1; i<=n; i++)
    {
        cout<<i<<": \n";
        for(j=1;j<=n;j++)mp[j]=0;
        r=0;
        for(j=i; j<=n; j++)
        {
            mp[arr[i]]=1;
            r=r+(arr[j]*arr[j-1]*arr[j+1]);
            temp=arr[i-1];
            arr[i-1]=arr[i];
            arr[i]=temp;
        }
        cout<<r<<"\n";
        if(mp[arr[n]]==0)
            r+=arr[n];
        cout<<r<<"\n";
        for(j=1; j<=n; j++)
        {
            if(mp[arr[j]]==0&&mp[arr[j-1]]==1&&mp[arr[j+1]]==1)
            {
                mp[arr[i]]=1;
                r=r+(arr[j]*arr[j-1]*arr[j+1]);
                temp=arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=temp;
            }
        }
        cout<<r<<"\n";
        for(j=1;j<=n;j++)
            if(mp[arr[j]]==0)r+=arr[j];
        cout<<r<<"\n\n";
        if(r1<r)r1=r;
    }
    //cout<<r1<<"\n";
}
