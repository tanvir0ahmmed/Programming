#include<iostream>
#include<stdio.h>
using namespace std;
int arr[10002][10002],r=0,vis[10002],pre[10002],d[10002];
void dfs(int s)
{
    int u=s;
    vis[u]=1;
    for(int i=1;i<=10000;i++)
    {
        if(arr[u][i]==1&&vis[i]==0)
        {
            pre[i]=u;
            d[i]=d[u]+1;
            dfs(i);
        }
    }
    r=max(r,d[u]);
}
int main()
{
    int n,u,v,r1=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    dfs(1);
    for(int i=1;i<=10001;i++)
    {
        if(r1<d[i])
        {
            r1=d[i];
            u=i;
        }
    }
    //cout<<u<<"\n";
    for(int i=0;i<=10001;i++)vis[i]=0;
    for(int i=0;i<=10001;i++)d[i]=0;
    for(int i=0;i<=10001;i++)pre[i]=-1;
    dfs(u);
    r1=0;
    for(int i=1;i<=10001;i++)
    {
        if(r1<d[i])
        {
            r1=d[i];
            u=i;
        }
    }
    cout<<u<<" ";
    while(pre[u]!=-1)
    {
        cout<<pre[u]<<" ";
        u=pre[u];
    }
    cout<<"\n";
    cout<<r<<"\n";
}
