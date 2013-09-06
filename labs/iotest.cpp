
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    int intc;
    float doublec;

    int intcpp;
    float doublecpp;


    printf("Enter an integer and a double\n");
    scanf("%d %f", &intc, &doublec);
    printf("You entered  %d  %f\n", intc, doublec);


    cout << "Enter an integer and a double\n";
    cin >> intcpp;
    cin >> doublecpp;
    cout << "You entered " << intcpp << " " << doublecpp << endl;
}
