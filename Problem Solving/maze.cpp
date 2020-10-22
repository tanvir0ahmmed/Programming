#include<iostream>
using namespace std;
int main()
{
    char s[505],s1[505][505];
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        //k=K;
        for(int j=0; j<sizeof(s); j++)
        {
            s1[i][j]=s[j];
        }
        //cout<<s1[0][i]<<"\n";
        for(int j=0; j<m; j++)
        {
            if((s[j]=='.'&&s[j+1]=='#')&&k!=0)
            {
                s1[i][j]='X';
                //cout<<"X";
                k--;
            }
            else if((s[j]=='#'&&s[j+1]=='.')&&k!=0)
            {
                s1[i][j+1]='X';
                //cout<<"X";
                k--;
            }
        }
        //cout<<"\n";
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<sizeof(s1[i]); j++)
        {
            s[j]=s1[i][j];
        }
        for(int j=0; j<sizeof(s); j++)
        {
            if(s[j]=='.'&&k!=0)
            {
                s1[i][j]='X';
                //cout<<"X";
                k--;
            }
        }
    }
    for(int i=1; i<=n; i++)
        cout<<s1[i]<<"\n";
}
