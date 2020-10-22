/*
cell count including source cell
n m move
6 6 3
011011
111000
001011
110110
011010
001101
2 2 //source cell

n m move
7 6 3
110110
110111
110101
011110
111011
110111
111111
3 2 //source cell
*/


#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,x,y,d[100][100],q[100],q1[100],k2,vis[100][100],cnt=0;
char s[100][100];
void bfs(int i,int j)
{
    int ui=i;
    int uj=j;
    int k=0,k1=0;
    d[ui][uj]=0;
    q[++k]=ui;
    q1[k]=uj;
    vis[ui][uj]=1;
    while(k1<k)
    {
        ++k1;
        ui=q[k1];
        uj=q1[k1];
        if(d[ui][uj]>=k2)break;
        if(s[ui+1][uj]=='1'&&vis[ui+1][uj]==0)
        {
            cnt++;
            d[ui+1][uj]=d[ui][uj]+1;
            vis[ui+1][uj]=1;
            q[++k]=ui+1;
            q1[k]=uj;
        }
        if(s[ui-1][uj]=='1'&&vis[ui-1][uj]==0)
        {
            cnt++;
            d[ui-1][uj]=d[ui][uj]+1;
            vis[ui-1][uj]=1;
            q[++k]=ui-1;
            q1[k]=uj;
        }
        if(s[ui][uj+1]=='1'&&vis[ui][uj+1]==0)
        {
            cnt++;
            d[ui][uj+1]=d[ui][uj]+1;
            vis[ui][uj+1]=1;
            q[++k]=ui;
            q1[k]=uj+1;
        }
        if(s[ui][uj-1]=='1'&&vis[ui][uj-1]==0)
        {
            cnt++;
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
    {
        cin>>s[i];
    }
    cin>>x>>y;
    bfs(x,y);
    cout<<cnt<<"\n";
}
