#include<iostream>
using namespace std;
int n,e,arr[1001][1001],vis[1001],color[1001],k=0,f=0,i,j,s,d,node[1001],mp[1001],q[100001],set1[1001],l=0,t,i1;
void bfs(int s1)
{
    int k1=0,k2=0;
    for(j=0; j<=1000; j++)
        color[node[j]]=0;
    vis[s1]=1;
    color[s1]=1;
    set1[++k]=s1;
    q[++k1]=s1;
    while(k1>k2)
    {
        k2++;
        int u=q[k2];
        for(j=1; j<=1000; j++)
        {
            if(arr[u][j]==1&&vis[j]==0)
            {
                if(color[u]==1)
                {
                    vis[j]=1;
                    q[++k1]=j;
                    color[j]=2;
                }
                else
                {
                    vis[j]=1;
                    q[++k1]=j;
                    color[j]=1;
                    set1[++k]=j;
                }

            }
            else if(arr[u][j]==1&&vis[j]==1&&color[u]==color[j])
            {
                f=1;
                break;
            }
        }
        if(f==1)
            break;
    }
}
void init()
{
    for(j=0; j<=1000; j++)
    {
        vis[j]=0;
        color[j]=0;
        mp[j]=0;
        k=0;
        l=0;
        f=0;
        for(i=0;i<=1000;i++)
            arr[j][i]=0;
    }
}
int main()
{
    cin>>t;
    for(i1=1; i1<=t; i1++)
    {
        init();
        cin>>n>>e;
        for(i=1; i<=e; i++)
        {
            cin>>s>>d;
            arr[s][d]=1;
            arr[d][s]=1;
            if(mp[s]==0)
            {
                node[++l]=s;
                mp[s]=1;
            }
            if(mp[d]==0)
            {
                node[++l]=d;
                mp[d]=1;
            }
        }
        for(i=1; i<=n; i++)
        {
            f=0;
            if(vis[node[i]]==0)
                bfs(node[i]);
            if(f==1)
            {
                cout<<"Case "<<i1<<": -1\n";
                break;
            }
        }
        if(f==0)
        {
            cout<<"Case "<<i1<<": ";
            for(i=1; i<=k; i++)
                cout<<set1[i]<<" ";
            cout<<"\n";
        }

    }

}
