#include<bits/stdc++.h>
using namespace std;
int arr[10002][10002],vis[10002],pre[10002];
int n,m,u,v,c=0;
bool isCycle(int s)
{
    int u=s;
    vis[u]=1;
    c++;
    for(int i=1;i<=10000;i++)
    {
        if(arr[u][i]==1&&vis[i]==0)
        {
            pre[i]=u;
            vis[i]=1;
            isCycle(i);
        }
        else if(arr[u][i]==1&&vis[i]==1&&pre[u]!=i)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    pre[1]=-1;
    if(isCycle(1)||c!=n)cout<<"NO\n";
    else cout<<"YES\n";
}
