#include <stdio.h>
#include <stdlib.h>

float generateRandomFloat() {
    int n;
    n = rand();
    double n_double = (double) n / (double) RAND_MAX;
    return (n_double);

}//end randomNumber

int coins_probab(int c1, int c2, int c3, float threshold) {

    int startc1, startc2, startc3;
    int tossCount = 0;
    float inp1, inp2, inp3;

    startc1 = c1;
    startc2 = c2;
    startc3 = c3;


    while ((c1 != 0) && (c2 != 0) && (c3 != 0)) {
        inp1 = generateRandomFloat();
        inp2 = generateRandomFloat();
        inp3 = generateRandomFloat();
        tossCount++;

        if (((inp1 <= threshold) && (inp2 <= threshold) && (inp3 <= threshold)) || ((inp1 > threshold) && (inp2 > threshold) && (inp3 > threshold))) {


        } else if (((inp1 > threshold) && (inp2 <= threshold) && (inp3 <= threshold)) || ((inp1 <= threshold) && (inp2 > threshold) && (inp3 > threshold))) {
            c1 += 2;
            c2--;
            c3--;

        }
        if (((inp1 > threshold) && (inp2 <= threshold) && (inp3 > threshold)) || ((inp1 <= threshold) && (inp2 > threshold) && (inp3 <= threshold))) {
            c1--;
            c2 += 2;
            c3--;

        }
        if (((inp1 > threshold) && (inp2 > threshold) && (inp3 <= threshold)) || ((inp1 <= threshold) && (inp2 <= threshold) && (inp3 > threshold))) {
            c1--;
            c2--;
            c3 += 2;

        }
    }//while
    return tossCount;

}//coins_probab

int main(int argc, char** argv) {
    int c1, c2, c3;
    int i;
    int iteration_n = 100000;
    float threshold;


    printf( "Enter no. of coins for Player 1 : ");
    scanf("%d",&c1);
    printf( "\nEnter no. of coins for Player 2 : ");
    scanf("%d",&c2);
    printf( "\nEnter no. of coins for Player 3 : ");
    scanf("%d",&c3);

    printf( "\nEnter the probability : ");
    scanf("%f",&threshold);


    int totalFlips = 0;

    for (i = 0; i < iteration_n; i++) {
        int noOfFlipsPerRound = coins_probab(c1, c2, c3, threshold);
        //printf("No.of Flips to find winner : %d \n",noOfFlipsPerRound);
        totalFlips = totalFlips + noOfFlipsPerRound;
    }

    double answer = ((double)totalFlips / iteration_n);
    printf("\n\nAnswer = %f \n",answer);
    return 0;
}
