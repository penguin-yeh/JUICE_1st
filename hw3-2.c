#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char name[100][100];
  int mathScore[100];
  int englishScore[100];
  float avgScore[100];

  int N;
  int i,j;
  int tmp1,tmp2;
  float tmp3;
  char tmp4[100];

  scanf("%d",&N);

  for(i=0;i<N;i++)
  {
      scanf("%s %d %d",name[i],&mathScore[i],&englishScore[i]);
  }
  for(i=0;i<N;i++)
  {
      avgScore[i]=((float)mathScore[i]+(float)englishScore[i])/2;
  }
  for(i=0;i<N;i++)
  {
      for(j=0;j<N-1-i;j++)
      {
          if(avgScore[j]>avgScore[j+1])
          { tmp3=avgScore[j];
            avgScore[j]=avgScore[j+1];
            avgScore[j+1]=tmp3;

            tmp1=mathScore[j];
            mathScore[j]=mathScore[j+1];
            mathScore[j+1]=tmp1;

            tmp2=englishScore[j];
            englishScore[j]=englishScore[j+1];
            englishScore[j+1]=tmp2;


            strcpy(tmp4,name[j]);
            strcpy(name[j],name[j+1]);
            strcpy(name[j+1],tmp4);


          }
      }
  }
  for(i=0;i<N;i++)
  {
     printf("%s %d %d %.2f\n",name[i],(int)mathScore[i],(int)englishScore[i],avgScore[i]);
  }
    return 0;
}
