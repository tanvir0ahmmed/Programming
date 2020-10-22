#include<iostream>
#include<map>
#define x 100000
using namespace std;
int vis[x+5],color[x+5],q[x+5],red[x+5],black[x+5];
int k=1,j=0,j1=0,l=1;
map<int,map<int,int> >arr;
void bfs(int s)
{

    for(int i=1;i<=x+5;i++)vis[i]=0;
    for(int i=1;i<=x+5;i++)color[i]=0;
    for(int i=1;i<=x+5;i++)q[i]=0;
    for(int i=1;i<=x+5;i++)red[i]=0;
    for(int i=1;i<=x+5;i++)black[i]=0;
    q[k]=s;
    vis[s]=1;
    color[s]=1;
    red[++j]=s;
    while(l<k+1)
    {
        int u=q[l];
        ++l;
        for(int i=1;i<=100000;i++)
        {

            if(arr[u][i]==1&&vis[i]==0)
            {
                //cout<<u<<" "<<i<<"\n";
            //cout<<arr[u][i]<<" "<<vis[i]<<"\n\n";

                if(color[u]==1)
                {

                    q[++k]=i;
                    color[i]=2;
                    vis[i]=1;
                    black[++j1]=i;
                }
                else if(color[u]==2)
                {
                    q[++k]=i;
                    color[i]=1;
                    vis[i]=1;
                    red[++j]=i;
                }
            }
        }
    }
}
int main()
{
    int n,u,v,c=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    //cout<<arr[1][2]<<"\n";
    bfs(1);
    //cout<<j<<" "<<j1<<"\n";
    for(int i=1;i<=j;i++)
    {
        //cout<<red[i]<<"\n";
        for(int m=1;m<=j1;m++)
        {
            //cout<<black[m]<<"\n";
            if(arr[red[i]][black[m]]!=1)
            {
                c++;
            }
        }
        cout<<"\n";
    }
    cout<<c<<"\n";
}
