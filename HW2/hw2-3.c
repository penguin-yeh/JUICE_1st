#include <stdlib.h>
#include <stdio.h>

int GetCycleLength(int n)
{
  int cycle_length =0;

  while(n!=1)

   if(n%2!=0)
{    n=3*n+1;
    cycle_length++;
}
   else if(n%2==0)
{    n=n/2;
     cycle_length++;
}
     cycle_length++;

  return cycle_length;

}
 int main()

{
int min,max,Maxlength=0,i,j;



      while(scanf("%d %d",&i,&j)!=EOF)
 {
     if( i==0 && j==0 )
        break;

      if(i>j)
{     min=j;
      max=i;
}      else
{
      min=i;
      max=j;
}
      for( int k=min;k<=max;k++)
{
      if(GetCycleLength(k)>Maxlength)
        Maxlength=GetCycleLength(k);
}

    printf("%d %d %d\n",i,j,Maxlength);
    Maxlength=0;
 }
    return 0;
}



