#include<stdio.h>
long long int bigpow(long long int a,long long int b)
{
    long long int y=0,k=0;
    if(b==0)
        return 1;
    else if(b%2==0)
    {
        y=bigpow(a,b/2);
        printf("even=%lld\n",y);
        k= y*y;
    }
    else
    {
        k=a*bigpow(a,b-1);
        printf("odd=%lld\n",k);
        return k;
    }

}
int main()
{
    printf("%lld",bigpow(2,5));
}
