// File name : datarep1.c
// Author    : Mark Redekopp
// Date      : 2010-08-23
// Purpose   : Digital Representation activity for CS 100
// Notes     : Students should predict the values printed to the screen

#include <stdio.h>

int main()
{
  char d1 = 'A';  // Initialize d1-d3 to a text character
                  //  (must be in single quotes
  char d2 = 'Z';  //  as in 'A') and use it to find
                  //  the ASCII (binary) values
  char d3 = 'a';  //  for the corresponding characters

  
  unsigned char e1 = 0x68;  // Initialize e to a specific hex/binary value
  unsigned char e2 = 255;   // Initialize a char to a decimal value
  unsigned char e3 = 256;   // Initialize a char to another decimal value
  unsigned char e4 = 257;   // Initialize a char to another decimal value
  
  // Print d1's character code in hex
  printf("d1 = 0x%x\n",d1);  
  // Print d2's character code in hex
  printf("d2 = 0x%x\n",d2);  
  // Print d3's character code in hex
  printf("d3 = 0x%x\n",d3);  

  // Print e1's character code as an ASCII character
  printf("e1 = %c\n",e1);
  // Print the decimal value stored in the e2 variable
  printf("e2 = %d\n",e2);  
  // Print the decimal value stored in the e3 variable
  printf("e3 = %d\n",e3);  
  // Print the decimal value stored in the e4 variable
  printf("e4 = %d\n",e4);  

  return 0;
}
  
