#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int d[200][200],q[200],q1[200],vis[200][200],n,m,t,i,j,l;
char s[200][200];
int bfs(int x,int y)
{
    int i1,j1;
    for(i1=0; i1<200; i1++)
        for(j1=0; j1<200; j1++)
        {
            d[i1][j1]=0;
            vis[i1][j1]=0;
        }
    int k=0,k1=0;
    vis[x][y]=1;
    d[x][y]=0;
    q[++k]=x;
    q1[k]=y;
    while(k>=k1)
    {
        ++k1;
        int r=q[k1];
        int c=q1[k1];
        if(r+1<=n && vis[r+1][c]==0)
        {
            d[r+1][c]=d[r][c]+1;
            vis[r+1][c]=1;
            q[++k]=r+1;
            q1[k]=c;
            /*if(s[r+1][c]=='1')
            {
                //return d[r+1][c];
            }*/
        }
        if(r-1>=0 && vis[r-1][c]==0)
        {
            d[r-1][c]=d[r][c]+1;
            vis[r-1][c]=1;
            q[++k]=r-1;
            q1[k]=c;
            /*if(s[r-1][c]=='1')
            {
                //return d[r-1][c];
            }*/
        }
        if(c-1>=0 && vis[r][c-1]==0)
        {
            d[r][c-1]=d[r][c]+1;
            vis[r][c-1]=1;
            q[++k]=r;
            q1[k]=c-1;
            /*if(s[r][c-1]=='1')
            {
                //return d[r][c-1];
            }*/
        }
        if(c+1<=m && vis[r][c+1]==0)
        {
            d[r][c+1]=d[r][c]+1;
            vis[r][c+1]=1;
            q[++k]=r;
            q1[k]=c+1;
            /*if(s[r][c+1]=='1')
            {
                //return d[r][c+1];
            }*/
        }
    }
}
int main()
{
    cin>>t;
    for(j=1; j<=t; j++)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
        {
            cin>>s[i];
        }
        bfs(0,0);
        int r,r1,i2,j2,f=0,r2=INT_MAX;
        for(i=0; i<n; i++)
        {
            for(l=0; l<m; l++)
            {
                f=0;
                r2=INT_MAX;
                if(s[i][l]=='0')
                {
                    for(i2=0;i2<n;i2++)
                    {
                        for(j2=0;j2<m;j2++)
                        {
                            if(s[i2][j2]=='1')
                            {
                                r=d[i2][j2];
                                r1=d[i][l];
                                r2=min(r2,abs(r-r1));
                                //f=1;
                                //break;
                            }
                        }
                        //if(f==1)break;
                    }
                    cout<<r2<<" ";
                }
                else cout<<"0 ";
            }
            cout<<"\n";
        }

    }
}
