
#include<iostream>
using namespace std;
int d[212][212],i,j,k,t,n,m;
char s[212][212];
void bfs(int r,int c)
{
    int k2=0,k1=0,q[212000],q1[212000];
    d[r][c]=0;
    q[++k2]=r;
    q1[k2]=c;
    while(k1<k2)
    {
        ++k1;
        int x=q[k1];
        int y=q1[k1];
        if(x+1<n&&d[x][y]+1<d[x+1][y])
        {
            d[x+1][y]=d[x][y]+1;
            q[++k2]=x+1;
            q1[k2]=y;
        }
        if(x-1>=0&&d[x][y]+1<d[x-1][y])
        {
            d[x-1][y]=d[x][y]+1;
            q[++k2]=x-1;
            q1[k2]=y;
        }
        if(y-1>=0&&d[x][y]+1<d[x][y-1])
        {
            d[x][y-1]=d[x][y]+1;
            q[++k2]=x;
            q1[k2]=y-1;
        }
        if(y+1<m&&d[x][y]+1<d[x][y+1])
        {
            d[x][y+1]=d[x][y]+1;
            q[++k2]=x;
            q1[k2]=y+1;
        }
    }
}
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        for(j=0;j<190;j++)
            for(k=0;k<190;k++)d[j][k]=1000000000;
        cin>>n>>m;
        for(j =0;j<n;j++)
            cin>>s[j];
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(s[j][k]=='1')
                {
                    bfs(j,k);
                }
            }
        }
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(s[j][k]=='1')
                {
                    cout<<"0 ";
                }
                else cout<<d[j][k]<<" ";
            }
            cout<<"\n";
        }

    }
}
