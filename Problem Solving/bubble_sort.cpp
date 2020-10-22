#include<stdio.h>
int main()
{
    int arr[]={5,3,4,2,1},i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<5;i++)printf("%d ",arr[i]);
}
