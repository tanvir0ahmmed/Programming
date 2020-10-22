#include<stdio.h>
int arr[505][505];
int n,m,k,p,f1=0,a,b;
char s[505],s1[505][505];
int vis[505][505];
void dfs(int r,int c,int f3)
{
    int f=0;
    int i=r;
    int j=c;
    vis[i][j]=1;
    if(s1[i][j]=='.'&&s1[i-1][j]=='.'&&i-1>=0&&vis[i-1][j]==0)
    {
        f=1;
        vis[i-1][j]=1;
        dfs(i-1,j,f3);
    }
    if(s1[i][j]=='.'&&s1[i+1][j]=='.'&&i+1<n&&vis[i+1][j]==0)
    {
        f=1;
        vis[i+1][j]=1;
        dfs(i+1,j,f3);
    }
    if(s1[i][j]=='.'&&s1[i][j-1]=='.'&&j-1>=0&&vis[i][j-1]==0)
    {
        f=1;
        vis[i][j-1]=1;
        dfs(i,j-1,f3);
    }
    if(s1[i][j]=='.'&&s1[i][j+1]=='.'&&j+1<m&&vis[i][j+1]==0)
    {
        f=1;
        vis[i][j+1]=1;
        dfs(i,j+1,f3);
    }
    if(f3==1&&k>0)
    {
        k--;
        s1[i][j]='X';
    }
    if(f==0&&k>0&&f3==0)
    {
        k--;
        s1[i][j]='X';
    }
    f=0;
}
void init1()
{
    int i,j;
    for(i=0;i<=500;i++)
    {
        for(j=0;j<=500;j++)
            vis[i][j]=0;
    }
}
int main()
{
    int j,i;
    scanf("%d%d%d",&n,&m,&k);
    ///cin>>n>>m>>k;
    for(int i=0; i<n; i++)
    {
        scanf("%s",&s);
        //cin>>s;
        for(j=0; j<sizeof(s); j++)
        {
            if(f1==0&&s[j]=='.')
            {
                a=i;
                b=j;
                f1=1;
            }
            s1[i][j]=s[j];
        }
    }
    dfs(a,b,0);
    init1();
    f1=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<sizeof(s1[i]); j++)
        {
            if(f1==0&&s1[i][j]=='.')
            {
                a=i;
                b=j;
                f1=1;
            }
            if(f1==1)break;
        }
        if(f1==1)break;
    }
    dfs(a,b,1);
    for(i=0; i<n; i++)
        printf("%s\n",s1[i]);
        ///cout<<s1[i]<<"\n";
}
