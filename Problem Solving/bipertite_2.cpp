#include<iostream>
#include<map>
#include<vector>
#include<queue>
#define x 100000
using namespace std;
int vis[x+5],color[x+5],d[x+5],red[x+5],black[x+5],pre[x+5],co[x+5];
int k=1,j=0,j1=0,l=1,r=0;
vector<int>arr[x+2];
vector<int>v[x+2];
void bfs(int s)
{

    //for(int i=1;i<=x+5;i++)vis[i]=0;
    //for(int i=1;i<=x+5;i++)color[i]=0;
    //for(int i=1;i<=x+5;i++)q[i]=0;
    //for(int i=1;i<=x+5;i++)red[i]=0;
    //for(int i=1;i<=x+5;i++)black[i]=0;
    //q[k]=s;
    vis[s]=1;
    d[s]=0;
    color[s]=1;
    red[++j]=s;
    queue<int>q;
    q.push(s);
    vector<int>::iterator it;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ++l;
        for(it=arr[u].begin();it!=arr[u].end();it++)
        {

            if(vis[*it]==0)
            {
                //
            //cout<<arr[u][i]<<" "<<vis[i]<<"\n\n";

                if(color[u]==1)
                {
                    pre[*it]=u;
                    //q[++k]=*it;
                    q.push(*it);
                    d[*it]=d[u]+1;
                    co[d[*it]]++;
                    v[d[*it]].push_back(*it);
                    r=max(r,co[d[*it]]);
                    color[*it]=2;
                    vis[*it]=1;
                    black[++j1]=*it;
                    //cout<<black[j1]<<" ";
                }
                else if(color[u]==2)
                {
                    pre[*it]=u;
                    //cout<<u<<" "<<*it<<"\n";
                    d[*it]=d[u]+1;
                    co[d[*it]]++;
                    r=max(r,co[d[*it]]);
                    //q[++k]=*it;
                    q.push(*it);
                    color[*it]=1;
                    vis[*it]=1;
                    red[++j]=*it;

                }
            }
        }
    }
    //cout<<"\n";
}
int main()
{
    int n,u,v,c=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    bfs(1);
    cout<<"\n";
    for(int i=1;i<=j;i++)
    {
        cout<<d[red[i]]<<" "<<co[d[red[i]]+3]<<"\n";
        if(d[red[i]]+3<=r)
        {
            c+=co[d[red[i]]+3];
        }
        /*for(int j2=0;j2<arr[red[i]].size();j2++)
        {
            d[arr[red[i]][j2]]=1;
        }
        for(int m=1;m<=j1;m++)
        {
               if(pre[black[m]]!=red[i]&&pre[red[i]]!=black[m])
               {
                   c++;
               }
        }
        for(int j2=0;j2<arr[red[i]].size();j2++)
        {
            d[arr[red[i]][j2]]=0;
        }*/
    }
    cout<<"\n";
    for(int i=1;i<=j1;i++)
    {
        cout<<d[black[i]]<<" "<<co[d[black[i]]+3]<<"\n";
        if(d[black[i]]+3<=r)
        {
            c+=co[d[black[i]]+3];
        }
        /*for(int j2=0;j2<arr[red[i]].size();j2++)
        {
            d[arr[red[i]][j2]]=1;
        }
        for(int m=1;m<=j1;m++)
        {
               if(pre[black[m]]!=red[i]&&pre[red[i]]!=black[m])
               {
                   c++;
               }
        }
        for(int j2=0;j2<arr[red[i]].size();j2++)
        {
            d[arr[red[i]][j2]]=0;
        }*/
    }
    cout<<c<<"\n";
}

