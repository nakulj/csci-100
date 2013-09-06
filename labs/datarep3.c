// File name : datarep3.c
// Author    : Mark Redekopp
// Date      : 2010-08-23
// Purpose   : Digital Representation activity for CS 100
// Notes     : Students will examine how negative representations of
//             of integer and floating point numbers

#include <stdio.h>

int main()
{

  float fpos =  3.5; // Initialize fpos to a positive floating point number and
  float fneg = -3.5; //  fneg to a neg. floating point number to find how neg.
                     //  numbers are represented for the floating point format vs.
                     //  positive representations

  int   ipos, ineg;  // Initialize ipos to a positive integer and ineg to a neg.

  // How can you change the representation of a floating point number to
  // the opposite sign?
  printf("fpos = %lf decimal and in hex 0x%8x\n",fpos,fpos);
  printf("fneg = %lf decimal and in hex 0x%8x\n",fneg,fneg);
  printf("\n");  // Print a blank line

  // Floating point numbers represent the significant digits with some set
  // of bits and the exponent (power of 2) with another set.  Use the printf
  // statements below and add more of your own to try to determine which bits
  // [ex. bit locations 15 through 0]  of the 32-bit floating point format
  // represent the signicant digit field vs. the exponent field.
  
  // Prints the hex rep. of some FP format numbers between [2 and 4) 
  fpos = 2.0;
  printf("fpos = %lf decimal and in hex 0x%8x\n",fpos,fpos);
  fpos = 2.5;
  printf("fpos = %lf decimal and in hex 0x%8x\n",fpos,fpos);
  fpos = 3.0;
  printf("fpos = %lf decimal and in hex 0x%8x\n",fpos,fpos);
  fpos = 3.75;
  printf("fpos = %lf decimal and in hex 0x%8x\n",fpos,fpos);

  //Enter your own code to print some numbers between [4 and 8)





  
  // Does the same method of flipping sign for floating point numbers
  // used for signed integers?  Challenge:  Do some research on how signed
  // integers are represented.  You can change ineg or add more printf 
  // statements then re-compile and re-run this program to
  // see some more examples and test your hypothesis/findings
  ipos = 1;
  printf("ipos = %d decimal and in hex 0x%8x\n",ipos,ipos);  // %8x prints exactly
                                                        //     8 hex characters
  ineg = -1;
  printf("ineg = %d decimal and in hex 0x%8x\n",ineg,ineg);  // %8x prints exactly
                                                        //     8 hex characters

  // %8x shows the hexadecimal value of a variable with at least 8 characters
  // However, it cuts off any leading 0's.  How could we instruct printf to
  // leave leading 0's in the displayed value? (Use the Internet to lookup
  // relevant documentation for the printf function.

  return 0;
}
  
