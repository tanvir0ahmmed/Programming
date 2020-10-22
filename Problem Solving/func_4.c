#include<stdio.h>
void us()
{
    static int c=1;
    printf("main() calls us() %d times\n",c);
    c++;
}
int main()
{
    us();
    us();
    us();
    us();
    us();
    us();
}
