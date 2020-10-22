#include<stdio.h>
void ab(int);
int main()
{
    int i;
    i=10;
    printf("Now i goes to ab\n");
    ab(i);
    printf("Now i back in main\n");
    i=20;
    printf("Now i goes to ab\n");
    ab(i);
    printf("Now i back in main\n");
}
void ab(int x)
{
    printf("%d\n",x);
}
