#include <stdio.h>
#include <stdlib.h>

int main()
{
  char input1[100],input2[100];
  int a=0;

  while(scanf("%s",input1)!=EOF)
{
  for(a=0;a<strlen(input1);a++)

{  input2[a]=input1[a]-5;

   printf("%c",input2[a]);
}
    printf("\n");
}

return 0;




}
