#include<bits/stdc++.h>
using namespace std;
int d[1002],temp[1002],temp1[1002],f1=-1,vis[1002],prev[1002],f[1002],u,t=0,adj[1002][1002];
void dfs(int s)
{
    int u=s;
    t=t+1;
    d[u]=t;
    vis[u]=1;
    for(int i=1; i<=1000; i++)
    {
        if(adj[u][i]==1)
        {
            if(vis[i]==1)
            {
                temp[++f1]=u;
                temp1[f1]=i;
                //temp=u;
                //f1=1;
            }
            if(vis[i]==0)
            {
                prev[i]=u;
                //vis[i]=1;
                dfs(i);
            }
        }
    }
    vis[u]=2;
    t=t+1;
    f[u]=t;
    //cout<<u<<" "<<f[u]<<"\n";
    return;
}
void intit()
{
    t=0,f1=-1;
    for( int i=1; i<=1000; i++)
    {
        temp[i]=0;
        d[i]=0;
        f[i]=0;
        prev[i]=-1;
        vis[i]=0;
    }
}
void print(int d1)
{
    cout<<"Cycle: ";
    int out[1002],k=0;
    out[++k]=d1;
    while(prev[d1]!=-1)
    {
        out[++k]=prev[d1];
        //cout<<prev[d];
        d1=prev[d1];
    }
    for(int i=k; i>0; i--)
        cout<<out[i]<<" ";
    cout<<"\n";
    for(int i=1; i<=4; i++)
    {
        cout<<d[i]<<" "<<f[i]<<"\n";
    }
    cout<<"\n\n";
    if(f1!=-1)
    {
        int d1;
        for(int j=0;j<=f1;j++)
        {
            int t1;
           // cout<<temp1[j]<<" "<<temp[j]<<"\n";
            cout<<"Cycle: "<<temp1[j]<<" ";
            int out[1002],k=0;
            out[++k]=temp[j];
            d1=temp[j];
            t1=temp1[j];
            while(prev[d1]!=t1)
            {
                //break;
                out[++k]=prev[d1];
                //cout<<prev[d];
                d1=prev[d1];
            }
            for(int i=k; i>0; i--)
                cout<<out[i]<<" ";
            cout<<"\n";
        }
    }
    cout<<"\n";
}
int main()
{
    int edge,d1;
    scanf("%d",&edge);
    int x,y,i=0;
    for(i=1; i<=edge; i++)
    {
        scanf("%d %d",&x,&y);
        adj[x][y]=1;
        //adj[y][x]=1;
    }
    int src;
    //scanf("%d%d",&src,&d1);
    intit();
    prev[src]=-1;
    dfs(1);
    print(d1);
}
