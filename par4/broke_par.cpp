#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>


int flip();
double P;		//Probability of getting a head

int main(int argc, char* argv[]){

	struct timeval start, finish;
	unsigned long long usec;
	omp_set_num_threads(atoi(argv[4]));

	int N,		    //Initial number of coins, held constant
		Tri,			//number of trials
		f=0;	//number of flips
	double avg;		
	N= atoi(argv[1]);
	P= atof(argv[2]);
	Tri= atof(argv[3]);
	gettimeofday(&start, NULL);
	#pragma omp parallel for reduction(+:f)
	for(int i=1;i<=Tri;i++)
	{							//Iterate through trials

		int j, u, t;
		int n[3], c[3];
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


	gettimeofday(&finish, NULL);
	usec = finish.tv_sec*1000*1000 + finish.tv_usec;
	usec -= (start.tv_sec*1000*1000 + start.tv_usec);
	printf("Time taken: %lld microseconds\n",usec);
	printf("The average number of flips per game is %lf \n",avg);
	return 0;
}

int flip(){
	unsigned int ri;
	double c=rand_r(&ri);					//Make 'c' a random value between zero and one.
	c/= RAND_MAX;
	return c<P?1:0;									//Give the chance of a head a weight proportional to 'P'
}
