#include<bits/stdc++.h>
using namespace std;
int arr[1002][1002];
void bfs(int s, int d,int arr[1002][1002])
{
    int vis[1002],prev[1002],q[1002];
    for(int i=0;i<=1000;i++)vis[i]=0;
    for(int i=0;i<=1000;i++)prev[i]=-1;
    int i=0,j=0;
    q[i]=s;
    vis[s]=1;
    prev[s]=-1;
    while(i<=1000)
    {
        int u=q[i];
        ++i;
        for(int k=1;k<=1000;k++)
        {
            if(arr[u][k]==1&&vis[k]==0)
            {
                vis[k]=1;
                prev[k]=u;
                q[++j]=k;
            }
        }
    }
    int out[1002],k=0;
    out[++k]=d;
    while(prev[d]!=-1)
    {
        out[++k]=prev[d];
        //cout<<prev[d];
        d=prev[d];
    }
    for(int i=k;i>0;i--)
        cout<<out[i]<<" ";
}
int main()
{
    int s,d,v,e;
    cin>>v>>e;
    for(int i = 1;i<=e;i++)
    {
        cin>>s>>d;
        arr[s][d]=1;
        arr[d][s]=1;
    }
    cin>>s>>d;
    bfs(s,d,arr);
}
