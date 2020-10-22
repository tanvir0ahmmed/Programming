
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>ver[50002];
map<ll,map<ll,ll> >cost;
ll vis[50002],d[50002],q[50002],u1,u,v,w,n,t,r=1,r1=0;

void dfs(ll s)
{
    vector<ll>::iterator it;
    for(ll i=1; i<=50000; i++)
    {
        d[i]=0;
        vis[i]=0;
    }
    int u=s,k=0,k1=0;
    vis[u]=1;
    d[u]=0;
    q[++k]=u;
    while(k>=k1)
    {
        k1++;
        u=q[k1];
        for(it=ver[u].begin(); it!=ver[u].end(); it++)
        {
            if(vis[*it]==0)
            {
                d[*it]=d[u]+cost[u][*it];
                q[++k]=*it;
                vis[*it]=1;
            }
        }
    }
}
void init1()
{
    for(ll i=1; i<=50000; i++)
    {
        ver[i].clear();
        cost[i].clear();
    }
}
int main()
{
    cin>>t;
    for(ll i=1; i<=t; i++)
    {
        ll x;
        r=1,r1=0;
        init1();
        cin>>n;
        for(ll j=1; j<n; j++)
        {
            cin>>u1>>v>>w;
            if(j==1)
                x=u1;
            ver[u1].push_back(v);
            ver[v].push_back(u1);
            cost[u1][v]=w;
            cost[v][u1]=w;
        }
        dfs(x);
        for(ll j=1; j<=n; j++)
        {

            if(r1<d[j])
            {
                r1=d[j];
                r=j;
            }
        }
        r1=0;
        dfs(r);
        for(ll j=1; j<=n; j++)
        {
            if(r1<d[j])
            {
                r1=d[j];
                r=j;
            }
        }
        cout<<r1<<"\n";
    }
}
