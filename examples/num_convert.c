#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[])
{
  double f, c;
  printf("Enter the temperature  in Farenheit:");
  scanf("%lf", &f);
  c=5*(f-32)/9;
  printf("The temperature in celsius is %lf \n",c);
  return 0;
  
}

