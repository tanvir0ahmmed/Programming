#include<stdio.h>
#include<string.h>
int main()
{
    int n,l,i;
    char ch[100];
    while(gets(ch))
    {
        l=strlen(ch);
        for(i=0;i<l;i++)
            printf("%c",ch[i]);
        printf("\n");
    }
    return 0;
}
