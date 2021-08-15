#include <stdio.h>
#include <stdlib.h>

int main()
{
char input1[100];
int a;
while(scanf("%s",input1)!=EOF)
{

for(a=0;a<strlen(input1);a++)
{
  printf("%c",input1[strlen(input1)-a-1]);
}

  printf("\n");
}
return 0;

}
