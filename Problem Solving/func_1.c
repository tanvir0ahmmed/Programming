#include<stdio.h>
int n;
int ab(int x)
{
    printf("Before Recursion = %d\n",x);
    if(x==0)
    {

        return x;
    }
    printf("After Recursion = %d\n",x);
        return x+ab(x-1);

}
int main()
{
    int r[10],i=-1;
    r[++i]=ab(5);
    printf("ab(5)=%d\n",r[0]);
    //printf("ab(5)=%d\n",ab(5));
}
