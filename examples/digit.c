#include <stdio.h>

int main(int argc, char *argv[]){
	int num, a, b, c;
	printf("Enter an integer between 0 and 999 \n");
	scanf("%d", &num);
	a=num%10;
	b=(num/10)%10;
	c=num/100;
	printf("100's digit is : %d ", c);
	printf("10's digit is : %d , b);
	printf("1's digit is : %d , a);
	return 0;
}