    #include <stdio.h>
    #include <stdlib.h>



    int main()
    {
       int n,m;
       int a,b;

       while(scanf("%d %d",&n,&m)!=EOF)
       {


           printf("*\t");

       for(b=1;b<=m;b++)
       {
           printf("%d\t",b);

       }
           printf("\n");

       for(a=1;a<=n;a++)
       {
           printf("%d\t",a);

           for(b=1;b<=m;b++)
           {

              printf("%d\t",a*b);
           }

            printf("\n");
       }
       }
     return 0;

    }
