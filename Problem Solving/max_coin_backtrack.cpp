#include<iostream>
using namespace std;
///char s[100][100];
int  s[100][100];
int i,j,k,t,c=0,r=0,r1=0,r2=0,r3=0,test,line;
void rec(int r,int p,int cnt)
{
    if(r<0)
    {
        if(r2<cnt)
            r2=cnt;
        return;
    }
    else if(p<0)
        return;
    else if(p>4)
        return;
    else if(s[r][p]==1)
        cnt++;
    else if(s[r][p]==2)
        return;
    rec(r-1,p,cnt);
    rec(r-1,p-1,cnt);
    rec(r-1,p+1,cnt);


}
int main()
{
    cin>>test;
    while(test--)
    {
        c=0,r=0,r1=0,r2=0,r3=0;
        cin>>line;
       // for(i=0; i<line; i++)
            //cin>>s[i];
        for(i=0;i<line;i++)
            for(j=0;j<5;j++)cin>>s[i][j];
        for(i=line-2; i>=0; i--)
        {
            t=0;
            j=i;
            c=0;
            while(j>=0)
            {
                t++;
                if(t>5)
                    break;
                for(k=0; k<5; k++)
                {
                    if(s[j][k]==2)
                        c++;
                }
                j--;
            }
            if(r<c)
            {
                r=c;
                r1=i;
            }
        }
        j=0;
        r1=line-2;
        while(r1>=0)
        {
            j++;
            if(j>5)
                break;
            for(i=0; i<5; i++)
            {
                if(s[r1][i]==2)
                    s[r1][i]=0;
            }
            r1--;
        }
        for(i=line-2;i>=0;i--)
        {
            for(j=i,t=0;t<5&&j>=0;j--,t++)
            {
                for(k=0;k<5;k++)
                    if(s[j][k]==2)s[j][k]=3;
            }
            rec(line-1,2,0);
            for(j=i,t=0;t<5&&j>=0;j--,t++)
            {
                for(k=0;k<5;k++)
                    if(s[j][k]==3)s[j][k]=2;
            }
            if(r3<r2)r3=r2;
        }

        cout<<r3<<"\n";
    }
}
