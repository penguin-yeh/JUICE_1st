#include <stdio.h>
#include <stdlib.h>

float mysqrt(float a)
{
    float x=0.00;
    while(x*x<=a)
    {
        x=x+0.01;
    }


    return x-0.01;//算出來的值會比正確的值大一點點(誤差) ex:25==>5.099998，故-0.1會扣太多//

}

int main()
{
  int i,j,tmp,N;
  int score[100];
  float ave,sum1=0,sum2=0,variation;
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
          sum1=sum1+score[i];
      }


      ave=sum1/N;

      printf("maxScore=%d\n",score[N-1]);
      printf("minScore=%d\n",score[0]);
      printf("avgScore=%.2f\n",ave);

      for(i=0;i<N;i++)
      {
          sum2=sum2+(score[i]-ave)*(score[i]-ave);
      }
      variation=sum2/N;
      printf("variation=%.2f\n",variation);

      printf("standard deviatio=%.2f\n",mysqrt(variation));
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
