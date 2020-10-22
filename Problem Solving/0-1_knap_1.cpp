
#include<stdio.h>
int dp[7][31][610];
int m[10],sec[10],le[10],a[10];
int DP(int i,int d,int h)
{
    if(d==0)
        return 0;
    if(i>5)
        return 999999;
        if(dp[i][d][h]!=-1)
            return dp[i][d][h];
    int p1=999999;
    int p2=999999;
    if(h-le[i]>=0)
        p1=a[i]+DP(i,d-1,h-le[i]);
    p2=DP(i+1,d,h);
    if(p1<p2)
        return p1;
    else return p2;
}

int main()
{
    int i,j,k,d,h;
    scanf("%d %d",&d,&h);
    for(i=1;i<=5;i++)
    {
        scanf("%d %d %d",&m[i],&sec[i],&le[i]);
        a[i]=m[i]*60+(sec[i]);
    }
    for(i=0;i<7;i++)
    {
        for(j=0;j<31;j++)
        {
            for(k=0;k<610;k++)
                dp[i][j][k]=-1;
        }
    }
    int ans=DP(1,d,h);
    printf("%d %d",ans/60,ans%60);
}
