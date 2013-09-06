//--------------------------------------------------------
// File:     chromakey.cpp
//
// Author:   Nakul
//
// Date:     2010-Oct-05
//
// Usage:    chromakey greenscreen.bmp background.bmp DIST meth1.bmp meth2.bmp
//
// Notes:
// This program performs the chroma key operation  on an input 
// using two different methods.
//
// Method 1 Take average pixel value of first twenty rows/columns and then
//          take a user-defined distance threshold from that
//          pixel value as a discriminator
//
// Method 2 Take the average pixel of the first twenty rows/columns and the maximum displacement
//			from the average as the threshold, then apply method one.
//
//--------------------------------------------------------

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bmplib.h"
#include <math.h>
#include <omp.h>
#include <time.h>

#define NUM_METHODS 2
using namespace std;

unsigned char OutputImage[SIZE][SIZE][RGB];	// Output image
unsigned char InputImage[SIZE][SIZE][RGB];	// Input image
unsigned char BgrndImage[SIZE][SIZE][RGB];	// Background image

unsigned char Mask[NUM_METHODS][SIZE][SIZE];	// Mask arrays (one for each method)


int avgRGB[3]={0,0,0};	// average rgb

double getDeviation(int rgb[]) {
	double diff=0;
	int i;
	for(i=0; i<3; i++)
		diff+= pow((rgb[i]-avgRGB[i]),2);
	diff= sqrt(diff);
	return diff;
}// use rgb values as vectors and find seperation between them

int check(double threshold, int rgb[]) {
	double deviation= getDeviation(rgb);
	if(floor(deviation)<threshold)
		return 0;
	else
		return 1;
}// check if the pixel is 'green' by comparing it's rgb against average


int main(int argc, char *argv[]) {


	struct timeval start, finish;
	unsigned long long usec;
	int h,i,j,k;	// loop variables
	int threshold;	// threshold specified in command-line
	double maxDev=0, dev;	// deviation of pixel rgb from average 'green'

	if(argc < 7){
		cout << "usage: program_name input.bmp background.bmp dist_threshold output1.bmp output2.bmp" << endl;
		return 0;
	}// For incorrectly formatted commands, print usage instructions and exit
	
	if(readRGBBMP(argv[1], InputImage) || readRGBBMP(argv[2], BgrndImage)) {
		cout << "Error reading file: " << argv[1] << endl;
		exit(1);
	}// Reads background and foreground images, and reports file input errors if any

	for(j= 0; j<SIZE; j++)
		for(k= 0; k<3; k++)
			avgRGB[k]+= InputImage[0][j][k]+InputImage[j][0][k];
	// Add all the rgb values of the first row/column of pixels

	for(k=0;k<3;k++) {
		avgRGB[k]/= 2*SIZE;
	}// Divide sum by size to get average

	threshold= atoi(argv[3]);
	omp_set_num_threads(atoi(argv[6]));
	gettimeofday(&start, NULL);

	// Method 1: Create the mask using the distance threshold method in Mask[0][i][j]
	int rgb[3]={0, 0, 0};	// rgb of a pixel
	#pragma omp parallel for private(i,j)
	for(i=0; i<256; i++)
	{
		#pragma omp parallel for private(j)
		for(j=0; j<256; j++)
		{
			rgb[0]= InputImage[i][j][0];
			rgb[1]= InputImage[i][j][1];
			rgb[2]= InputImage[i][j][2];
			Mask[0][i][j]= check((double)threshold, rgb);
		}
	}
	

	// Method 2: Find the maximum deviation from the average, and set that as the threshold deviation
	#pragma omp parallel for private(j,k,dev)
	for(j=0; j<256; j++)
	{
		int rgb[3]={0, 0, 0};	// rgb of a pixel
		for(k=0; k<3; k++)
			rgb[k]=InputImage[0][j][k];
		dev= getDeviation(rgb);
		#pragma omp critical
		{
		if(dev>maxDev)
			maxDev= dev;	// Maximum deviation in row
		}
		for(k=0; k<3; k++)
			rgb[k]=InputImage[j][0][k];
		dev= getDeviation(rgb);
		#pragma omp critical
		{
		if(dev>maxDev)
			maxDev= dev;	// Maximum deviation in column
		}
	}// Find the deviation of each pixel in the first row from the average

	#pragma omp parallel for private(i,j)
	for(i=0; i<256;i++)
	{
		int rgb[3]={0, 0, 0};	// rgb of a pixel
		#pragma omp parallel for private(j)
		for(j=0; j<256; j++)
		{
			rgb[0]= InputImage[i][j][0];
			rgb[1]= InputImage[i][j][1];
			rgb[2]= InputImage[i][j][2];
			Mask[1][i][j]= check(maxDev, rgb);
		}
	}
	
	gettimeofday(&finish, NULL);
	usec = finish.tv_sec*1000*1000 + finish.tv_usec;
	usec -= (start.tv_sec*1000*1000 + start.tv_usec);
	printf("Time taken with is %lld microseconds\n",usec);




	// Create an output image for each method by checking
	// Uses the masks created above (0=Replace w/ background image /
	//  1 = Input Image)
	// This code is complete and need not be altered provided you created
	// the mask arrays correctly.
  for(h=0; h<NUM_METHODS; h++){
    for(i=0; i<SIZE; i++){
      for(j=0; j<SIZE; j++){
		if(Mask[h][i][j] == 1){
		  for(k=0; k<3; k++){
			OutputImage[i][j][k] = InputImage[i][j][k];
		  }
		}
		// Otherwise select the background image pixel
		else {
		  for(k=0; k<3; k++){
			OutputImage[i][j][k] = BgrndImage[i][j][k];
		  }
		}
      }
    }
    
    if (writeRGBBMP(argv[4+h], OutputImage) ){
      //      printf("Error writing file: %s\n", argv[4+h]);
      cout << "Error writing file: " << argv[4+h] << endl;
      exit(1);
    }	
  }

  return 0;
}
