#include<stdio.h>
int bm(int a,int b,int m)
{
    int y,k;
    if(b==0)
        return 1;

    if(b%2==0)
    {
        y=bm(a,b/2,m);
        return (y*y)%m;
    }
    else
    {
        k=a*bm(a,b-1,m);
        return k;
    }
}
int main()
{
    int a,b,m;
    while(1)
    {
        if(a==0&&b==0&&m==0)
            break;
        scanf("%d%d%d",&a,&b,&m);
        printf("%d\n",bm(a,b,m));
    }

}
