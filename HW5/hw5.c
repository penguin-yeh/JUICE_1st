
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define IN 0
# define OUT 1

int main()
{
    int SpaceCnt=0;
    int WhitespaceCnt=0;
    int LowercaseCnt=0;
    int UppercaseCnt=0;
    int digit[10];//數字
    int alpha1[26];//小寫
    int alpha2[26];//大寫
    int DigitCnt=0;
    int ByteCnt=0;
    int WordCnt=0;//最後一個算不到
    int LineCnt=0,LineCnt1=0,LineCnt2=0;
    int c,i,k=0;
    int state=OUT;
    int state2=OUT;
    int state3=OUT;
    int length=0;
    int maxlength=0;
    char longestWord[100]="\0";
    char word[100];
    memset(digit,0,sizeof(digit));
    memset(alpha1,0,sizeof(alpha1));
    memset(alpha2,0,sizeof(alpha2));
    memset(word,0,sizeof(word));
    while((c=getchar())!=EOF)
    {
        ByteCnt++;
        if(c==' ') SpaceCnt++;
        if(isspace(c)) WhitespaceCnt++;
        if(c>='a'&&c<='z')  LowercaseCnt++;
        if(c>='A'&&c<='Z')  UppercaseCnt++;
        if((c=='\n')&&(state2==IN))
        {
            state2=OUT;
        }
        else if(state2==OUT)
        {
            LineCnt1++;
            state2=IN;
        }
        if(c=='\n')
        {
            LineCnt2++;
            state3=IN;
        }
        else state3=OUT;

        if(isdigit(c))
        {
            DigitCnt+=1;
            digit[c-'0']++;
        }
        if(c>='a'&&c<='z')
        {
            alpha1[c-'a']++;
        }
        if(c>='A'&&c<='Z')
        {
            alpha2[c-'A']++;
        }
        if((isspace(c)||c==' ')&&(state==IN))
        {
            state=OUT;
        }
        else
        {
            if((state==OUT)&&(c!=' ')&&(!isspace(c)))
        {
            WordCnt++;
            state=IN;
            length=1;
        }
           else if(state==IN)
        {
            length++;
        }
        }
        if(length>maxlength)
        {
            maxlength=length;//ok
        }
        if(!isspace(c))
        {
            word[k]=c;
            k++;
        }
        else if(isspace(c))
        {
            word[k]='\0';
           if(strlen(word)>strlen(longestWord))
            {
                strcpy(longestWord,word);
            }
            else if(strlen(word)==strlen(longestWord))
            {
                if(strcmp(word,longestWord)<0)
                {
                strcpy(longestWord,word);
                }
            }
            memset(word,0,sizeof(word));
            k=0;
         }
    }
      if(strlen(word)>strlen(longestWord))
      {
            strcpy(longestWord,word);
      }
            else if(strlen(word)==strlen(longestWord))
                 {
                 if(strcmp(word,longestWord)<0)  strcpy(longestWord,word);
                 }
      if((LineCnt2>=LineCnt1)&&(state3==OUT))  LineCnt=1;
      if(LineCnt1>LineCnt2)  LineCnt=LineCnt+LineCnt1;
      else                   LineCnt=LineCnt+LineCnt2;
      printf("===\n");
      printf("[0] Overview Stats\n");
      printf("===\n");
      printf("Space Count: %d\n",SpaceCnt);
      printf("Whitespace Count: %d\n",WhitespaceCnt);
      printf("Lowercase Count: %d\n",LowercaseCnt);
      printf("Uppercase Count: %d\n",UppercaseCnt);
      printf("Digit Count: %d\n",DigitCnt);
      printf("Case-insensitive Count: %d\n",LowercaseCnt+UppercaseCnt);
      printf("Byte Count: %d\n",ByteCnt);
      printf("Word Count: %d\n",WordCnt);
      printf("Total Line: %d\n",LineCnt);
      printf("===\n");
      printf("[1] Longest Word\n");
      printf("===\n");
      printf("Word: %s\n",longestWord);
      printf("Length: %d\n",maxlength);
      printf("===\n");
      printf("[2] Case-Sensitive Stats\n");
      printf("===\n");
      for(i=0;i<26;i++)
      {
          printf("%c: %d\t%c: %d\n",'A'+i,alpha2[i],'a'+i,alpha1[i]);
      }
      printf("===\n");
      printf("[3] Case-Insensitive Stats\n");
      printf("===\n");
      for(i=0;i<26;i++)
      {
          printf("%c: %d\n",'a'+i,alpha2[i]+alpha1[i]);
      }
      printf("===\n");
      printf("[4] Digit Stats\n");
      printf("===\n");
      for( i=0;i<10;i++)
      {
          printf("%c: %d\n",'0'+i,digit[i]);
      }

       return 0;
}
