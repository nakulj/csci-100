#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int flip();
double P;		//Probability of getting a head

int main(int arc, char* argv[]){

struct timeval start, finish;
	unsigned long long usec;
	gettimeofday(&start, NULL);
	int N= atoi(argv[1]),		    //Initial number of coins, held constant
		Tri= atoi(argv[2]),			//number of trials
		f=0,		//number of flips
		t,			//total from each round
		u, 			//the unique flip
		i,j;		//Loop variable
	P= atof(argv[3]);
	double avg;
	int n[3],
		c[3];		
	for(i=1;i<=Tri;i++){							//Iterate through trials
		for(j=0;j<3;j++)							//Initialise all coin values
			n[j]=N;
		while(n[0]!=0 && n[1]!=0 && n[2]!=0){		//Continue game so long as noone has been eliminated
			f++;									//Add to the total number of flips
			t=0;									//Reset 't' every trial
			for(j=0;j<3;j++){						//Flip all three coins
				c[j]=flip();
				t+=c[j];
			}
			if(t==0 || t==3)						//If all coins are equal, skip to the next flip
				continue;
			u=(t==1)?1:0;							//If the total from all flips is 1, then 1 must be the unique flip.
													//If the total is 2, 0 is the unique flip.
													//The other possibilities are eliminated by the previous continue.
			for(j=0;j<3;j++)
				n[j]+=(u==c[j])?2:-1;				//Give the winner 2 coins and take a coin each from the losers.
		}
	}
	avg=(double)f/Tri;
	printf("The average number of flips per game is %lf \n",avg);

	gettimeofday(&finish, NULL);
	usec = finish.tv_sec*1000*1000 + finish.tv_usec;
	usec -= (start.tv_sec*1000*1000 + start.tv_usec);
	printf("Time taken is %lld microseconds\n",usec);
	

	return 0;
}

int flip(){
	double c=rand();
	c/=RAND_MAX;						//Make 'c' a random value between zero and one.
	return c<P?1:0;									//Give the chance of a head a weight proportional to 'P'
}
