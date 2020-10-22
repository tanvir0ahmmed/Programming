#include<iostream>
using namespace std;
int n,m,t,a,b,c,dd,e,f,i,i1,j,k,k3,k4,c1[500],c2[500],m1[500],q[100000],q1[100000],d[110][110],vis[110][110];
void bfs(int s,int s1)
{
    for(i1=1; i1<=n; i1++)
    {
        for(j=1; j<=m; j++)
        {
            vis[i1][j]=0;
            d[i1][j]=0;
        }
    }
    int k1=0,k2=0;
    d[s][s1]=0;
    vis[s][s1]=0;
    q[++k1]=s;
    q1[k1]=s1;
    while(k1>k2)
    {
        ++k2;
        int row=q[k2];
        int col=q1[k2];
        if(row+1<=n&&vis[row+1][col]==0)
        {
            d[row+1][col]=d[row][col]+1;
            vis[row+1][col]=1;
            q[++k1]=row+1;
            q1[k1]=col;
        }
        if(row-1>=1&&vis[row-1][col]==0)
        {
            d[row-1][col]=d[row][col]+1;
            vis[row-1][col]=1;
            q[++k1]=row-1;
            q1[k1]=col;
        }
        if(col+1<=m&&vis[row][col+1]==0)
        {
            d[row][col+1]=d[row][col]+1;
            vis[row][col+1]=1;
            q[++k1]=row;
            q1[k1]=col+1;
        }
        if(col-1>=1&&vis[row][col-1]==0)
        {
            d[row][col-1]=d[row][col]+1;
            vis[row][col-1]=1;
            q[++k1]=row;
            q1[k1]=col-1;
        }
    }
}
int main()
{
    cin>>n>>m>>t;
    for(i=1; i<=t; i++)
    {
        f=k=k3=k4=0;
        cin>>a>>b>>c>>dd>>e>>f;
        bfs(a,b);
        for(j=1; j<=n; j++)
            m1[++k]=d[j][1];
        for(j=1; j<=m; j++)
            m1[++k]=d[1][j];
        for(j=1; j<=n; j++)
            m1[++k]=d[j][m];
        for(j=1; j<=m; j++)
            m1[++k]=d[n][j];
        bfs(c,dd);
        for(j=1; j<=n; j++)
            c1[++k3]=d[j][1];
        for(j=1; j<=m; j++)
            c1[++k3]=d[1][j];
        for(j=1; j<=n; j++)
            c1[++k3]=d[j][m];
        for(j=1; j<=m; j++)
            c1[++k3]=d[n][j];
        bfs(e,f);
        for(j=1; j<=n; j++)
            c2[++k4]=d[j][1];
        for(j=1; j<=m; j++)
            c2[++k4]=d[1][j];
        for(j=1; j<=n; j++)
            c2[++k4]=d[j][m];
        for(j=1; j<=m; j++)
            c2[++k4]=d[n][j];
        for(j=1; j<=k4; j++)
        {
            if(m1[j]<c1[j]&&m1[j]<c2[j])
            {
                f=1;
                break;
            }
        }
        if(f==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
