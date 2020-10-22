#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int n,l;
    char ch[100];
    while(gets(ch))
    {
        l=strlen(ch);
        for(int i=0;i<l;i++)
            cout<<ch[i];
        cout<<endl;
    }
    return 0;
}

