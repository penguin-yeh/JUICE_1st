#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *getword(char *text,char *word)
{
    char *ptr=text;
    char *qtr=word;
    char *textend;
    textend=text+strlen(text);
    word[0]='\0';
    while(isspace(*ptr)) ptr++;
    while(!isspace(*ptr)&& ptr<textend)
    {
        *qtr=*ptr;
        ptr++;
        qtr++;
    }
    *qtr='\0';
    if(word[0]=='\0')  return NULL;
    return ptr;
}

void swap(char *a,char *b)
{
    char tmp[8192];
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
}
void bubbleSortDigit(int a,char words[][1024])
{
    int i,j;
    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-1-i;j++)
        {
            if(atoi(words[j])<atoi(words[j+1]))
            swap(words[j],words[j+1]);
        }
    }
}
void bubbleSortAlphabet(int a,char words[][1024])
{
    int i,j;
    for(i=0;i<a-1;i++)
    {
        for(j=0;j<a-1-i;j++)
        {
            if(strcmp(words[j],words[j+1])>0)
            swap(words[j],words[j+1]);
        }
    }
}

int main()
{
    char line[8192];
    char word[1024];
    char words[1024][1024];
    char wordss[1024][1024];//沒重複的
    char *ptr;
    int wordCnt=0;
    int i,j,k=0;
    int result=0;
    int status=0;

    while(fgets(line,8192,stdin)!=NULL)
    {
        ptr=line;
        while((ptr=getword(ptr,word))!=NULL)
        {
            strcpy(words[wordCnt],word);
            wordCnt++;
        }
    }
    for(i=0;i<wordCnt;i++)
    {
        if(atoi(words[i])!=0)   result=1;//全部除了0以外的都是整數
        if(atoi(words[i])==0)
        {
            if(words[i]=="0")     result=1;
            else                result=0;
        }
    }

    if(result==1)  //全部都是整數
    {
        for(i=0;i<wordCnt;i++)
        {
            if(atoi(words[i])<=0)  status=1;//有負數或零
        }
        if(status==0)
        {
           bubbleSortDigit(wordCnt,words);
        }
        for(i=0;i<wordCnt;i++)
        {
            printf("%s\n",words[i]);
        }
    }
    if(result==0)
    {
        bubbleSortAlphabet(wordCnt,words);

    for(i=0;i<wordCnt;i++)
    {
        if((strcmp(words[i],words[i+1]))==0) continue;
        if((strcmp(words[i],words[i+1]))!=0)
        {
            strcpy(wordss[k],words[i]);
            k++;
        }
    }
    strcpy(wordss[k],words[wordCnt]);//最後一個進不去
    for(i=0;i<k;i++)
    {
        printf("%s\n",wordss[i]);
    }
    }
   return 0;
}