#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct our_biography
{
char name[5][20];
int age[5];
double gpa[5];
};
int main()
{
struct our_biography info;
struct our_biography temp;
int i,j;
for(i=0;i<5;++i)
{
scanf("%s%d%lf",info.name[i],&info.age[i],&info.gpa[i]);
}
for(i=0;i<4;i+=1)
{
for(j=i+1;j<5;j++)
{
if(strcmp(info.name[i],info.name[j])>0)
{
strcpy(temp.name,info.name[i]);
temp.age=info.age[i];
temp.gpa=info.gpa[i];

strcpy(info.name[i],info.name[j]);
info.age[i]=info.age[j];
info.gpa[i]=info.gpa[j];

strcpy(info.name[j],temp.name);
info.age[j]=temp.age;
info.gpa[j]=temp.gpa;
}
}
}
return 0;
}
