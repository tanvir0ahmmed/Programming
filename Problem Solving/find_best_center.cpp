///find_best_center
/*
n m total_point
6 6 4
101011
101010
101110
110110
111100
111111
0 0
0 5
5 0
5 5

4 4 3
1100
1001
1111
0010
0 0 ->A
1 3 ->B
2 2 ->C
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,x,y,d[55][55],q[55],point_i[55],point_j[55],q1[55],k2,vis[55][55],cnt=0,ans=0;
char s[100][100];
void bfs(int i,int j)
{
    for(int i1=0; i1<=50; i1++)
        for(int j1=0; j1<=50; j1++)
        {
            vis[i1][j1]=0;
            d[i1][j1]=0;
        }
    int ui=i;
    int uj=j;
    int k=0,k1=0;
    d[ui][uj]=0;
    q[++k]=ui;
    q1[k]=uj;
    vis[ui][uj]=1;
    printf("q  %d %d\n",ui,uj);
    while(k1<k)
    {
        ++k1;
        ui=q[k1];
        uj=q1[k1];
        if(s[ui+1][uj]=='1'&&vis[ui+1][uj]==0)
        {
            d[ui+1][uj]=d[ui][uj]+1;
            vis[ui+1][uj]=1;
            q[++k]=ui+1;
            q1[k]=uj;
        }
        if(s[ui-1][uj]=='1'&&vis[ui-1][uj]==0)
        {
            d[ui-1][uj]=d[ui][uj]+1;
            vis[ui-1][uj]=1;
            q[++k]=ui-1;
            q1[k]=uj;
        }
        if(s[ui][uj+1]=='1'&&vis[ui][uj+1]==0)
        {
            d[ui][uj+1]=d[ui][uj]+1;
            vis[ui][uj+1]=1;
            q[++k]=ui;
            q1[k]=uj+1;
        }
        if(s[ui][uj-1]=='1'&&vis[ui][uj-1]==0)
        {
            d[ui][uj-1]=d[ui][uj]+1;
            vis[ui][uj-1]=1;
            q[++k]=ui;
            q1[k]=uj-1;
        }
    }
}
int main()
{
    cin>>n>>m>>k2;
    for(int i=0; i<n; i++)
        cin>>s[i];
    int r=0,r1=INT_MAX;
    for(int i=1; i<=k2; i++)
        cin>>point_i[i]>>point_j[i];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]!='0')
            {
                r=0;
                bfs(i,j);
                for(int i1=1; i1<=k2; i1++)
                {
                    if(vis[point_i[i1]][point_j[i1]]==1)
                        r=max(r,d[point_i[i1]][point_j[i1]]);
                    else
                    {
                        r=0;
                        break;
                    }
                }
                if(r!=0&&r1>r)
                {
                    r1=min(r1,r);
                    ans=r;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
