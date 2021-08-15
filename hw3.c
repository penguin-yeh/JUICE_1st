#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i,j,tmp,N;
  int score[100];
  float ave,sum=0;
  scanf("%d",&N);
      for(i=0;i<N;i++)
      {
        scanf("%d",&score[i]);
      }
 
      for(i=0;i<N;i++)
      {
          for(j=0;j<N-1-i;j++)
          {
               if(score[j]>score[j+1])
               {
                   tmp=score[j+1];
                   score[j+1]=score[j];
                   score[j]=tmp;
               }
 
          }
 
      }
      for(i=0;i<N;i++)
      {
          sum=sum+score[i];
      }
 
 
      ave=sum/N;
 
      printf("maxScore=%d\n",score[N-1]);
      printf("minScore=%d\n",score[0]);
      printf("avgScore=%.2f\n",ave);
      printf("Min to Max=");
      for(i=0;i<N;i++)
      {
          printf("%d ",score[i]);
      }
      printf("\n");
 
      printf("Max to Min=");
 
      for(i=0;i<N;i++)
      {
          printf("%d ",score[N-1-i]);
      }
      printf("\n");
    return 0;
 
}