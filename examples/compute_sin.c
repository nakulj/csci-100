#include <stdio.h>
#include <math.h>
int fact(int);

int main(int argc, char *argv[]){
	double x, sinx=0;
	int i;
	printf("Enter x in radians:  ");
	scanf("%lf",&x);
	for(i=0;i<4;i++)
		sinx+=pow(-1,i)*pow(x,i*2+1)/fact(i*2+1);
	printf("%lf",sinx);
	return 0;
}


int fact(int n)
{
  int i;
  int result=1;
  for(i=1; i <= n; i++){
    result = result * i;
  }
  return result;
}

