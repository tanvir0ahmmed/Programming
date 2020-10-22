#include<stdio.h>
int n;
int ab(int x,int a)
{
    printf("%d\n",a);
    if(x==0)
    {
        return x;
    }
    ab(x-1,a+1);
    //printf("after-%d\n",a);
    return a;
}
int main()
{
    int r;
    r=ab(5,0);
    printf("ab(5)=%d\n",r);
    //printf("ab(5)=%d\n",ab(5));
}

