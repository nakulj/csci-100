#include <stdio.h>
#include <math.h>

int main(){
	double t;
	int i, j, x;
	printf("Enter an angle between 15 and 75 degrees");
	scanf("%lf", &t);
	t*=M_PI/180;
	for(i=1;i<=30;i++){
		x=i*tan(t);
		if(20<=x&&x<=30)
			x=20;
		for(j=1;j<=x;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
