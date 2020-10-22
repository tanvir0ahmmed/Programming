#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>ver[50002];
map<ll,map<ll,ll> >cost;
ll vis[50002],d[50002],u1,u,v,w,n,t,r=1,r1=0;

void dfs(ll s)
{
    vector<ll>::iterator it;
    ll u=s;
    vis[u]=1;
    //cout<<u<<" "<<d[u]<<"\n";
    for(it=ver[u].begin();it!=ver[u].end();it++)
    {
        if(vis[*it]==0)
        {
            d[*it]=d[u]+cost[u][*it];
            dfs(*it);
        }
    }
}
void init()
{
    //vector<ll>::iterator it;
    for(ll i=1;i<=50000;i++)
    {
        d[i]=0;
        vis[i]=0;
    }
}
void init1()
{
    //vector<ll>::iterator it;
    for(ll i=1;i<=50000;i++)
    {
        d[i]=0;
        vis[i]=0;
        ver[i].clear();
        cost[i].clear();
    }
}
int main()
{
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        ll x;
        r=1,r1=0;
        init1();
        cin>>n;
        for(ll j=1;j<n;j++)
        {
            cin>>u1>>v>>w;
            if(j==1)x=u1;
            ver[u1].push_back(v);
            ver[v].push_back(u1);
            cost[u1][v]=w;
            cost[v][u1]=w;
        }
        dfs(x);
        for(ll j=1;j<=n;j++)
        {

            if(r1<d[j])
            {
                r1=d[j];
                r=j;
            }
        }
        init();
        //cout<<"\n";
        //cout<<r<<"\n";
        r1=0;
        dfs(r);
        for(ll j=1;j<=n;j++)
        {
            //cout<<d[j]<<" ";
            if(r1<d[j])
            {
                r1=d[j];
                r=j;
            }
        }
        cout<<r1<<"\n";
    }
}
