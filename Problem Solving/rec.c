#include<stdio.h>
int rec(int a)
{
    if(a<5)
    {
        printf("a5=%d\n",a);
        a=rec(a+1);

    }
    else if(a<10)
    {
        printf("a10=%d\n",a);
        a=rec(a+1);
    }
    else if(a<15)
    {
        printf("a15=%d\n",a);
        a=rec(a+1);
    }
    printf("a=%d\n",a);
    return a;
}
int main()
{
    int r=rec(0);
    printf("%d",r);
}
