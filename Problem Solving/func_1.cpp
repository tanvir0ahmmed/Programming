#include<bits/stdc++.h>
using namespace std;
int res;
void ab(int x)
{
  if(x==0)
    {
        res=x;///final vlaue of x
        return;
    }
  cout<<"before function call value of x="<<x<<endl;
  ab(x-1);
  cout<<"after call value of x="<<x<<endl;
}
int main()
{
    ab(5);
    cout<<res<<endl;
}
