#include<iostream>
#include<stdio.h>
using namespace std;
int c,r,a,b;
char s[30],s1[30][30];
int vis[30][30],cnt=0;
void dfs(int i,int j)
{
    int xr=i;
    int xc=j;
    vis[i][j]=1;
    cnt++;
    if(s1[xr+1][xc]=='.'&&xr+1<r&&vis[xr+1][xc]==0)
    {

        dfs(xr+1,xc);
    }
    if(s1[xr-1][xc]=='.'&&xr-1>=0&&vis[xr-1][xc]==0)
    {
        dfs(xr-1,xc);
    }
    if(s1[xr][xc+1]=='.'&&xc+1<c&&vis[xr][xc+1]==0)
    {
        dfs(xr,xc+1);
    }
    if(s1[xr][xc-1]=='.'&&xc-1>=0&&vis[xr][xc-1]==0)
    {
        dfs(xr,xc-1);
    }
    ///cnt++;
}
void init()
{
    cnt=0;
    for(int i=0; i<=25; i++)
        for(int j=0; j<=25; j++)
        {
            vis[i][j]=0;
            s1[i][j]='#';
        }
}
int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>c>>r;
        for(int i=0; i<r; i++)
        {
            cin>>s1[i];
            for(int j=0; j<sizeof(s1[i]); j++)
            {
                if(s1[i][j]=='@')
                {
                    a=i;
                    b=j;
                }
            }
        }
        dfs(a,b);
        cout<<"Case "<<k<<": "<<cnt<<"\n";
        init();
    }
}
