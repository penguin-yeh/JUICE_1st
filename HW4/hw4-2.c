#include <stdio.h>
#include <stdlib.h>

int main()
{
  int Q;
  int i,j;

  while(scanf("%d",&Q)!=EOF)
  {
      if(Q%2==0)
  {
      Q=Q-1;
  }
  for(i=1;i<=(Q+1)/2;i++)
  {
      for(j=1;j<=(Q-(2*i-1))/2;j++)
      {
          printf(" ");
      }

      for(j=1;j<=2*i-1;j++)
      {

          printf("*");
      }
          printf("\n");
  }
  for(i=(Q+1)/2-1;i>=1;i--)
  {
      for(j=1;j<=(Q-(2*i-1))/2;j++)
      {
          printf(" ");
      }

      for(j=1;j<=2*i-1;j++)
      {

          printf("*");
      }
          printf("\n");
  }
  }
  return 0;
}
