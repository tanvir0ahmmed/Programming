#include<iostream>
using namespace std;
int arr[105][105],d[105][105],vis[105][105],q[1000000],q1[1000000],i,j,cnt=0,t,n,sx,sy,dx,dy,x,y;
int bfs(int s1,int d1)
{
    for(i=0;i<=100;i++)
    {
        for(j=0;j<=100;j++)
        {
            vis[i][j]=0;
            d[i][j]=0;
        }
    }
    int k=0,k1=0;
    vis[s1][d1]=1;
    d[s1][d1]=0;
    q[++k]=s1;
    q1[k]=d1;
    cnt=0;
    while(k1<k)
    {
        ++k1;
        int r=q[k1];
        int c=q1[k1];
        cout<<r<<" "<<c<<": "<<cnt<<"\n";
        if(r+1<=2&&vis[r+1][c]==0&&((arr[r+1][c]==2&&cnt==n)||(arr[r+1][c]!=2)))
        {
            vis[r+1][c]=1;
            d[r+1][c]=d[r][c]+1;
            q[++k]=r+1;
            q1[k]=c;
            if(arr[r+1][c]==3)cnt++;
            if(arr[r+1][c]==2)return d[r+1][c];
        }
        if(r-1>=0&&vis[r-1][c]==0&&((arr[r-1][c]==2&&cnt==n)||(arr[r-1][c]!=2)))
        {
            vis[r-1][c]=1;
            d[r-1][c]=d[r][c]+1;
            q[++k]=r-1;
            q1[k]=c;
            if(arr[r-1][c]==3)cnt++;
            if(arr[r-1][c]==2)return d[r-1][c];
        }
        if(c-1>=0&&vis[r][c-1]==0&&((arr[r][c-1]==2&&cnt==n)||(arr[r][c-1]!=2)))
        {
            vis[r][c-1]=1;
            d[r][c-1]=d[r][c]+1;
            q[++k]=r;
            q1[k]=c-1;
            if(arr[r][c-1]==3)cnt++;
            if(arr[r][c-1]==2)return d[r][c-1];
        }
        if(c+1<=2&&vis[r][c+1]==0&&((arr[r][c+1]==2&&cnt==n)||(arr[r][c+1]!=2)))
        {
            vis[r][c+1]=1;
            d[r][c+1]=d[r][c]+1;
            q[++k]=r;
            q1[k]=c+1;
            if(arr[r][c+1]==3)cnt++;
            if(arr[r][c+1]==2)return d[r][c+1];
        }
    }
    return cnt;
}
int main()
{
    for(t=1;t<=10;t++)
    {
        cin>>n>>sx>>sy>>dx>>dy;
        arr[sx][sy]=1;
        arr[dx][dy]=2;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            arr[x][y]=3;
        }
        //cout<<sx<<" "<<sy<<"\n";
        cout<<bfs(sx,sy)<<"\n";
    }
}
