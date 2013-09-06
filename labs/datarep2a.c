// File name : datarep2.c
// Author    : Mark Redekopp
// Date      : 2010-08-23
// Purpose   : Digital Representation activity for CS 100
// Notes     : Students will examine how negative representations of
//             of integer and floating point numbers

#include <stdio.h>

int gv = 1;
int dummy_global = 5;

int main()
{
  double a = 9.3;
  float f = 2.5;
  int x = 4;
  char c = 'Z';

  // Examine the addresses (shown in hex) where each of the variables
  // declared above are allocated.  Which set of variables appear to
  // be contiguously allocated (i.e. sequentially)?
  printf("gv is located at address (in hex)  0x%p\n", &gv);
  printf("a is located at address (in hex)  0x%p\n", &a);
  printf("f is located at address (in hex)  0x%p\n", &f);
  printf("x is located at address (in hex)  0x%p\n", &x);
  printf("c is located at address (in hex)  0x%p\n", &c);

  return 0;
  
}
