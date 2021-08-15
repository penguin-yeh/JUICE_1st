#include<stdio.h>
#include<stdlib.h>
 
int main()
{
int n;

while(scanf("%d",&n)!=EOF)
 
if ((n%4==0 )&&(n%100!= 0))
    printf("Leap year!\n");
else if(n%400==0)
    printf("Leap year!\n");
 
else
    printf("Common year!\n");
 
    return 0;
 
 
}