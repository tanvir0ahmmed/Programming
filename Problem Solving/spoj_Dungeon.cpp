#include<iostream>
using namespace std;
int d[105][105],d1[105][105],i,j,k,a,b,w,n,m,t,q[1000000],q1[1000000];
void bfs(int s,int d2)
{
    int k1=0,k2=0;
    d[s][d2]=d1[s][d2];
    q[++k2]=s;
    q1[k2]=d2;
    while(k1<k2)
    {
        ++k1;
        int r=q[k1];
        int c=q1[k1];
        if(r+1<=m&&d[r][c]+d1[r+1][c]<d[r+1][c])
        {
            q[++k2]=r+1;
            q1[k2]=c;
            d[r+1][c]=d[r][c]+d1[r+1][c];
        }
        if(r-1>=1&&d[r][c]+d1[r-1][c]<d[r-1][c])
        {
            q[++k2]=r-1;
            q1[k2]=c;
            d[r-1][c]=d[r][c]+d1[r-1][c];
        }
        if(c-1>=1&&d[r][c]+d1[r][c-1]<d[r][c-1])
        {
            q[++k2]=r;
            q1[k2]=c-1;
            d[r][c-1]=d[r][c]+d1[r][c-1];
        }
        if(c+1<=n&&d[r][c]+d1[r][c+1]<d[r][c+1])
        {
            q[++k2]=r;
            q1[k2]=c+1;
            d[r][c+1]=d[r][c]+d1[r][c+1];
        }

    }
}
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>m>>n;
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=n;k++)
            {
                d[j][k]=999999;
            }
        }
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=n;k++)
            {
                cin>>w;
                d1[j][k]=w;
            }
        }
        bfs(1,1);
        cin>>a>>b>>w;
        if(d[a][b]<=w)cout<<"YES\n"<<w-d[a][b]<<"\n";
        else cout<<"NO\n";
    }
}
