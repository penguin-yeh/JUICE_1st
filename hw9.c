
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc,char **argv)
{
    char *word;
    char **words;
    char *tmp;
    char *temp;
    char **temporary;
    int i=0;
    int j=0;
    int k=0;
    int idx;
    int len;
    int result=0;//1>>有-n or -r
    int flag=10;
    int state=0;
    word=malloc(sizeof(char)*105);
    words=malloc(sizeof(char)*105);
    tmp=malloc(sizeof(char)*105);
    temporary=malloc(sizeof(char)*105);
    temp=malloc(sizeof(char)*105);
    for(i=1;i<argc;i++)
    {
        if(strcmp(*(argv+i),"-h")==0)
        {
             flag=0;
        }
    }
    if(flag==0)
    {
        printf("Usage:\n\t-h --help usage\n\t-n numerical\n\t-r reverse\n");
        exit(1);
    }
    for(i=1;i<argc;i++)
    {
      if((strcmp(*(argv+i),"-h")!=0  && strcmp(*(argv+i),"-n")!=0 && strcmp(*(argv+i),"-r")!=0))
        {
            printf("Undefined parameter: %s.\n",*(argv+i));
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("Usage:\n\t-h --help usage\n\t-n numerical\n\t-r reverse\n");
        exit(1);
    }
    i=0;
    while(scanf("%s",word)!=EOF)
    {
        len=strlen(word);
        *(words+i)=malloc(sizeof(char)*(len+1));
        strcpy(*(words+i),word);
        i++;
    }
    idx=i;
    for(i=1;i<argc;i++)
    {
        if(strcmp(*(argv+i),"-r")==0)
        {
            result=1;
            if(argc>=3)
            {
              if(strcmp(*(argv+i+1),"-n")==0)
              {
                 state=1;//第一個-r;第二個-n
              }
            }
            if(i==1 && state==0)//第一個是-r 第二個不是-n
            {
              for(j=0;j<idx-1;j++)
              {
                 for(k=0;k<idx-1-j;k++)
                  {
                      if(strcmp(*(words+k),*(words+k+1))>0)
                      {
                          strcpy(tmp,*(words+k));
                          strcpy(*(words+k),*(words+k+1));
                          strcpy(*(words+k+1),tmp);
                      }
                  }
              }
            }
            for(j=0;j<idx;j++)
            {
                *(temporary+j)=malloc(sizeof(char)*(strlen(*(words+j))+1));
                strcpy(*(temporary+j),*(words+j));
            }
            for(j=0;j<idx;j++)
            {
                strcpy(*(words+j),*(temporary+idx-1-j));
            }
        }
        if(strcmp(*(argv+i),"-n")==0)
        {
            result=1;
            for(j=0;j<idx-1;j++)
            {
                for(k=0;k<idx-1-j;k++)
                {
                    if(atoi(*(words+k))>atoi(*(words+k+1)))
                    {
                        strcpy(temp,*(words+k));
                        strcpy(*(words+k),*(words+k+1));
                        strcpy(*(words+k+1),temp);
                    }
                }
            }
        }
        if(state==1)
        {
            for(j=0;j<idx-1;j++)
            {
                for(k=0;k<idx-1-j;k++)
                {
                    if(atoi(*(words+k))<atoi(*(words+k+1)))
                    {
                        strcpy(temp,*(words+k));
                        strcpy(*(words+k),*(words+k+1));
                        strcpy(*(words+k+1),temp);
                    }
                }
            }
        }
    }
    if(result==0)
    {
         for(i=0;i<idx-1;i++)
         {
             for(j=0;j<idx-1-i;j++)
              {
                  if(strcmp(*(words+j),*(words+j+1))>0)
                  {
                      strcpy(tmp,*(words+j));
                      strcpy(*(words+j),*(words+j+1));
                      strcpy(*(words+j+1),tmp);
                  }
              }
          }
    }
    for(i=0;i<idx;i++)
    {
       printf("%s\n",*(words+i));
    }
    for(i=0;i<idx;i++)
    {
        free(*(words+i));
        free(*(temporary+i));
    }
    //printf("result\t%d\nargc\t%d",result,argc);
    return 0;
}