#include<stdlib.h>
#include<stdio.h>


float CalculateBMI(float h,float w)
{
 float BMI;
 BMI=w/((h/100)*(h/100));


 return BMI;
}
int main()
{
 float h,w,BMI;

 while(scanf("%f %f",&h,&w)!=EOF)



 printf("BMI is %.1f\n",CalculateBMI(h,w));


 return 0;

}
