#include<iostream>
using namespace std;
int arr[105][105],d[105][105],vis[105][105],q[1000000],q1[1000000],i,j,t,n,sx,sy,dx,dy,x,y,r1=10000000;
void dfs(int s1,int d1,int cnt,int w)
{

    int r=s1;
    int c=d1;
    //cout<<r<<" "<<c<<"\n";
    if(arr[r][c]==3)
        cnt++;
    if(arr[r][c]==2&&cnt==n)
    {
        if(r1>w)
            r1=w;
        //cout<<r1<<"\n";
        return;
    }
    else if(arr[r][c]==2)return;
    vis[r][c]=1;
    if(r+1<=2&&vis[r+1][c]==0&&((arr[r+1][c]==2&&cnt==n)||(arr[r+1][c]!=2)))
    {
        dfs(r+1,c,cnt,w+1);
        vis[r+1][c]=0;
    }
    if(r-1>=0&&vis[r-1][c]==0&&((arr[r-1][c]==2&&cnt==n)||(arr[r-1][c]!=2)))
    {
        dfs(r-1,c,cnt,w+1);
        vis[r-1][c]=0;
    }
    if(c-1>=0&&vis[r][c-1]==0&&((arr[r][c-1]==2&&cnt==n)||(arr[r][c-1]!=2)))
    {
        dfs(r,c-1,cnt,w+1);
        vis[r][c-1]=0;
    }
    if(c+1<=2&&vis[r][c+1]==0&&((arr[r][c+1]==2&&cnt==n)||(arr[r][c+1]!=2)))
    {
        dfs(r,c+1,cnt,w+1);
        vis[r][c+1]=0;
    }
    ///return cnt;
}
void init()
{
    for(i=0; i<=100; i++)
    {
        for(j=0; j<=100; j++)
        {
            vis[i][j]=0;
            d[i][j]=0;
        }
    }
}
int main()
{
    for(t=1; t<=1; t++)
    {
        cin>>n>>sx>>sy>>dx>>dy;
        arr[sx][sy]=1;
        arr[dx][dy]=2;
        for(i=0; i<n; i++)
        {
            cin>>x>>y;
            arr[x][y]=3;
        }
        dfs(sx,sy,0,0);
        //cout<<sx<<" "<<sy<<"\n";
        cout<<r1<<"\n";
    }
}

