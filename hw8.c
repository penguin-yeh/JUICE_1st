#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *getword(char *text,char *word)
{
    char *ptr;
    char *qtr;
    char *textend;
    ptr=text;
    qtr=word;
    textend=text+strlen(text);
    word[0]='\0';
    while(isspace(*ptr))  ptr++;
    while(!isspace(*ptr) && ptr<textend)
    {
        *qtr++=*ptr++;
    }
    *qtr='\0';
    if(word[0]=='\0')   return NULL;
    return ptr;
}
int main()
{
    char names[256][1000];
    char math[256][1000];
    char english[256][1000];
    char program[256][1000];
    char line[8192];
    char word[256];
    char words[256][1000];
    char *ptr;
    char deletedName[256];
    char updatedName[256];
    char updatedData[256];
    int a=0;
    int b=0;
    int i=0;
    int j=0;
    int k=0;//names的個數
    int m=0;//names的位置
    int n=0;//math的個數
    int o=0;//math的位置
    int p=0;//english的個數
    int q=0;//english的位置
    int r=0;//program的個數
    int s=0;//program的位置
    int idx;//有幾個word
    int len;
    while(fgets(line,8192,stdin)!=NULL)
    {
        i=0;
        ptr=line;
        while((ptr=getword(ptr,word))!=NULL)
        {
            strcpy(words[i],word);
            i++;
        }
        idx=i;
        if(strcmp(words[0],"i")==0)
        {
            for(i=1;i<idx;i++)
            {
                if(words[i][0]=='n')
                {
                    m=0;
                    len=strlen(words[i]);
                    for(j=2;j<len;j++)
                    {
                        names[k][m]=words[i][j];
                        m++;
                    }
                    k++;
                }
                if(words[i][0]=='m')
                {
                    o=0;
                    len=strlen(words[i]);
                    for(j=2;j<len;j++)
                    {
                        math[n][o]=words[i][j];
                        o++;
                    }
                    n++;
                }
                if(words[i][0]=='e')
                {
                    q=0;
                    len=strlen(words[i]);
                    for(j=2;j<len;j++)
                    {
                        english[p][q]=words[i][j];
                        q++;
                    }
                    p++;
                }
                if(words[i][0]=='p')
                {
                    s=0;
                    len=strlen(words[i]);
                    for(j=2;j<len;j++)
                    {
                        program[r][s]=words[i][j];
                        s++;
                    }
                    r++;
                }
            }
        }
        if(strcmp(words[0],"d")==0)
        {
            j=0;
            len=strlen(words[1]);
            for(i=2;i<len;i++)
            {
                deletedName[j]=words[1][i];
                j++;
            }
            for(i=0;i<k;i++)
            {
                if(strcmp(names[i],deletedName)==0)
                {
                    strcpy(names[i]," ");
                }
            }
        }
        if(strcmp(words[0],"u")==0)
        {
            j=0;
            len=strlen(words[1]);
            for(i=2;i<len;i++)
            {
                updatedName[j]=words[1][i];
                j++;
            }
            for(i=0;i<k;i++)
            {
                if(strcmp(names[i],updatedName)==0)
                {
                    for(j=2;j<idx;j++)
                    {
                        if(words[j][0]=='m')
                        {
                            len=strlen(words[j]);
                            for(a=2;a<len;a++)
                            {
                                updatedData[b]=words[j][a];
                                b++;
                            }
                            strcpy(math[i],updatedData);
                            memset(updatedData,'\0',len);
                            b=0;
                        }
                        if(words[j][0]=='e')
                        {
                            len=strlen(words[j]);
                            for(a=2;a<len;a++)
                            {
                                updatedData[b]=words[j][a];
                                b++;
                            }
                            strcpy(english[i],updatedData);
                            memset(updatedData,'\0',len);
                            b=0;
                        }
                        if(words[j][0]=='p')
                        {
                            len=strlen(words[j]);
                            for(a=2;a<len;a++)
                            {
                                updatedData[b]=words[j][a];
                                b++;
                            }
                            strcpy(program[i],updatedData);
                            memset(updatedData,'\0',len);
                            b=0;
                        }
                    }
                }
            }
        }
        if(strcmp(words[0],"p")==0)
        {
            printf("name\tmathscore\tenglishscore\tprogscore\n");
            for(i=0;i<r;i++)
            {
               if(strcmp(names[i]," ")==0)
              {
                   continue;
              }
              printf("%s\t%s\t\t%s\t\t%s\n",names[i],math[i],english[i],program[i]);
            }
        }
    }
    

    return 0;
}
