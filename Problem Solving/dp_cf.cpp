#include<stdio.h>
int arr[100],n,d=0,tot,dp[5000];
void cut(int a, int l)
{

    if(a==n)
    {

        if(l>d)
        {
            d=l;
            return;
        }
        return;
    }
    else if(a>n)
    {
        return;
    }
    else if(dp[a] == 1)
    {
        return;
    }
    for(int i=0; i<3; i++)
    {

        cut(arr[i]+a, l+1);
        dp[arr[i]] = 1;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<3; i++)
    {
        scanf("%d",&arr[i]);
    }

    cut(0,0);
    printf("%d\n",d);
    return 0;
}
