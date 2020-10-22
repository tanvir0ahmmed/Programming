#include<iostream>
using namespace std;
int main()
{
    int m,a,b,c,ccw,ccw1,ccw2,r;
    while(1)
    {
        cin>>m>>a>>b>>c;
        if(m==0&&a==0&&b==0&&c==0)
            break;
        if(m>a)
            swap(m,a);
        if(a<b)
            swap(a,b);
        if(c<b)
            swap(c,b);
        ccw=360-(a-m)*9;
        ccw1=360-(a-b)*9;
        ccw2=360-(c-b)*9;
        r=1080+ccw+ccw1+ccw2;
        cout<<r<<endl;
    }
}
