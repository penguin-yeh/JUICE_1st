#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define  MaxLine 1000
#define  MaxWord  1005
#define  TRUE  1
#define  FALSE 0
int getWord(char text[],int offset,char word[])
{
    int k=0;
    int i=offset;//從offset的位置開始跑,不能在這設初值,因為主程式的getWord在while裡面
    while(isspace(text[i])||text[i]=='.'||text[i]==','||text[i]=='"'||text[i]==':'||text[i]=='!'||text[i]=='?'||text[i]=='('||text[i]==')')  i++;//前面是空格的情況
    while(!isspace(text[i])&&text[i]!='.'&&text[i]!=','&&text[i]!='"'&&text[i]!=':'&&text[i]!='!'&&text[i]!='?'&&text[i]!='('&&text[i]!=')')
    {
        word[k]=text[i];
        k++;
        i++;
    }
    //word[k]='\0';
    return i;//為了回傳i值,再從i位置開始跑
}

int main()
{
    char line[MaxLine];
    char originalLine[MaxLine];
    char repeatedLine[1050][MaxLine];
    char word[MaxWord];
    char firstWord[MaxWord];
    char longestWord[MaxWord];
    longestWord[0]='\0';
    char revisedWord[1005][MaxWord];
    char revisedWord2[1050][MaxWord];
    char sameLength[1005][MaxWord];
    char tmp[MaxWord];
    int  sameLengthCnt=0;
    int  longestWordLength;
    int i=0,j=0,k=0,m=0,offset;
    int state=TRUE;//TRUE>>每句第一個字
    int state2=FALSE;//FALSE>>後面沒重複
    int result;
    int wordCnt=0;
    //int wordCnt1=0;
    int repeatedLineCnt=0;
    while(fgets(line,MaxLine,stdin)!=NULL)
    {
        if(strcmp(line,"\n")==0)   continue;
        int state=TRUE;//TRUE>>每句第一個字
        int state2=FALSE;//FALSE>>後面沒重複
        int length=strlen(line);

        if(line[length-1]=='\n')  line[length-1]='\0';
        strcpy(originalLine,line);
    /*    for(i=0;i<length;i++)
        {
            if(line[i]=='.'||line[i]==','||line[i]=='"'||line[i]==':'||line[i]=='!'||line[i]=='?'||line[i]=='('||line[i]==')')
            {
                line[i]='\0';
            }

        }
     */
        offset=0;
        while(offset<length-1)
        {
            memset(word, '\0', sizeof(word));
            offset=getWord(line,offset,word);//getWord會回傳i值,i值存進offest裡面
            //wordCnt++;
            if(word[0]!='\0')
            {
                //printf("%s", word);
                wordCnt++;//一行只有\n時
                strcpy(revisedWord[k],word);
                k++;
            }
            //if(word[0]!='\0')

            if(state==TRUE)
            {
                strcpy(firstWord,word);
                state=FALSE;
            }
            else if(state==FALSE && (strcmp(firstWord,word))==0 && state2==FALSE)
            {
                state2=TRUE;
                repeatedLineCnt++;
            }
            if(strlen(word)>strlen(longestWord))
            {
                strcpy(longestWord,word);
            }
        }
        if(state2==TRUE)
        {
            strcpy(repeatedLine[j],originalLine);
            j++;
        }
     }
     longestWordLength=strlen(longestWord);

     //printf("\n%d\n", k);

     for(k=0;k<=wordCnt;k++)
     {
         //if(strcmp(revisedWord[k],"\0")!=0)

             strcpy(revisedWord2[k],revisedWord[k]);
         if(longestWordLength==strlen(revisedWord[k])&&k==0)
         {
                 strcpy(sameLength[m],revisedWord[k]);
                 m++;
                 sameLengthCnt++;
         }

         if(longestWordLength==strlen(revisedWord[k])&&k!=0)
         {
             result=0;
             for(i=0;i<k;i++)
             if(strcmp(revisedWord[k],revisedWord2[i])==0)
             {
                 result=1;

             }
             if(result!=1)
             {
                 strcpy(sameLength[m],revisedWord[k]);
                 m++;
                 sameLengthCnt++;
             }
         }
     }

     printf("--- [0] The line that the first word occurs more than twice in the line ---\n");
     if(repeatedLineCnt==0)   printf("It is not exist!\n");
     else
     {
         printf("Repeated line count: %d\n",repeatedLineCnt);
         for(i=0;i<repeatedLineCnt;i++)
         {

             printf("[%d]: %s\n",i,repeatedLine[i]);//換行問題(solved)//b b c c問題
         }
     }
     printf("--- [1] The longest words and their length ---\n");
     printf("Word length: %d\n",strlen(longestWord));
     for(i=0;i<sameLengthCnt;i++)
     {
         printf("[%d]: %s\n",i,sameLength[i]);
     }
     printf("--- [2] The words appear in the article ---\n");
     printf("Total words: %d\n",wordCnt);
     for(k=0;k<=wordCnt;k++)//n,n,n問題(solved)//標點符號後面是換行的話輸出會有問題
     {
         //printf("%s",revisedWord[k]);
             if(k%10==0&&k!=0)      printf("\n");
             if(k%10==9)            printf("%s",revisedWord[k]);
             else                   printf("%s ",revisedWord[k]);
     }
     //for(k=0;k<=wordCnt;k++)  printf("%s\n",revisedWord[k]);
     return 0;
}


