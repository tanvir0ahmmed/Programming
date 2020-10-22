#include<iostream>
using namespace std;
int arr[1002][1002],vis[1002][1002],d[1002][1002],cnt=0,q[5000000],q1[5000000];
int n,m,x,y,l,t,i,i1,i2,j,r1=0;
void bfs(int s, int d2)
{
    for(i1=0; i1<n; i1++)
        for(i2=0; i2<m; i2++)
        {
            vis[i1][i2]=0;
            d[i1][i2]=0;
        }
    int k=0,k1=0;
    vis[s][d2]=1;
    d[s][d2]=0;
    q[++k]=s;
    q1[k]=d2;
    r1=0;
    while(k1<k)
    {
        ++k1;
        int r=q[k1];
        int c=q1[k1];
        if(d[r][c]<l)
            cnt++;
        if((r-1>=0&&vis[r-1][c]==0)&&(arr[r][c]==1||arr[r][c]==2||arr[r][c]==4||arr[r][c]==7)
                &&(arr[r-1][c]==2||arr[r-1][c]==5||arr[r-1][c]==6||arr[r-1][c]==1))
        {

            d[r-1][c]=d[r][c]+1;
            vis[r-1][c]=1;
            q[++k]=r-1;
            q1[k]=c;
            //if(d[r-1][c]<l)cnt++;
        }
        if((r+1<n&&vis[r+1][c]==0)&&(arr[r][c]==1||arr[r][c]==2||arr[r][c]==5||arr[r][c]==6)
                &&(arr[r+1][c]==2||arr[r+1][c]==4||arr[r+1][c]==7||arr[r+1][c]==1))
        {
            d[r+1][c]=d[r][c]+1;
            vis[r+1][c]=1;
            q[++k]=r+1;
            q1[k]=c;
            //if(d[r+1][c]<l)cnt++;
        }
        if((c+1<m&&vis[r][c+1]==0)&&(arr[r][c]==1||arr[r][c]==3||arr[r][c]==4||arr[r][c]==5)
                &&(arr[r][c+1]==3||arr[r][c+1]==6||arr[r][c+1]==7||arr[r][c+1]==1))
        {
            d[r][c+1]=d[r][c]+1;
            vis[r][c+1]=1;
            q[++k]=r;
            q1[k]=c+1;
            //if(d[r][c+1]<l)cnt++;
        }
        if((c-1>=0&&vis[r][c-1]==0)&&(arr[r][c]==1||arr[r][c]==3||arr[r][c]==6||arr[r][c]==7)
                &&(arr[r][c-1]==3||arr[r][c-1]==4||arr[r][c-1]==5||arr[r][c-1]==1))
        {
            d[r][c-1]=d[r][c]+1;
            vis[r][c-1]=1;
            q[++k]=r;
            q1[k]=c-1;
            //if(d[r][c-1]<l)cnt++;
        }
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>m>>x>>y>>l;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>arr[i][j];
            }
        }
        if(arr[x][y]!=0)
        {
            bfs(x,y);
            cout<<cnt<<"\n";
        }
        else cout<<"0\n";

    }
}

