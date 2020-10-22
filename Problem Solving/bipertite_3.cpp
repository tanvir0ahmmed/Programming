#include<iostream>
#include<map>
#include<vector>
#include<queue>
#define x 100000
using namespace std;
long long int vis[x+5],color[x+5],red[x+5],black[x+5];
long long int k=1,j=0,j1=0,l=1,child[x+5];
vector<long long int>arr[x+2];
void bfs(long long int s)
{
    vis[s]=1;
    color[s]=1;
    red[++j]=s;
    queue<long long int>q;
    q.push(s);
    vector<long long int>::iterator it;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ++l;
        for(it=arr[u].begin();it!=arr[u].end();it++)
        {

            if(vis[*it]==0)
            {

                if(color[u]==1)
                {
                    child[u]++;
                    q.push(*it);
                    color[*it]=2;
                    vis[*it]=1;
                    black[++j1]=*it;
                }
                else if(color[u]==2)
                {
                    child[u]++;
                    q.push(*it);
                    color[*it]=1;
                    vis[*it]=1;
                    red[++j]=*it;

                }
            }
            else child[u]++;
        }
    }
}
int main()
{
    long long int n,u,v,c=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    bfs(1);
    for(int i=1;i<=j;i++)
    {
        c+=j1-child[red[i]];
    }
    cout<<c<<"\n";
}
