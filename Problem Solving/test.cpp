#include<stdio.h>
int main()
{
    int a, b, c, n,  y;
    a=b=2;c=1; y=100000;

    if(c==0)
    {
        int l=0, r=100000000000000000;
        while(l<=r)
        {
            mid = l+r/2;
            res = a*b + b*mid + c*mid*mid*mid;
            if(mid==y){printf("Found\n");}
            if(r<mid){l = mid+1;}
            else{r=mid-1;}
        }
    }else
    {
        for(int i=0; i<=1000000; i+)
        {
            res = res = a*b + b*mid + c*mid*mid*mid;
            if(res==y){printf("Found\n");break;}
        }
    }

    return 0;
}
