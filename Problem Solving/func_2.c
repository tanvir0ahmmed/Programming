#include<stdio.h>
void bp()
{
    char ch;
    if((ch=getchar())!='\n')
    {
        bp();
    }
    putchar(ch);
}
int main()
{
    printf("Type a lin of text: ");
    bp();
    getch();
}
