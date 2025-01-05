#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(void) {
  int num = 1234; // some number you want to test
  printf("%d\n", num);
  
  for(/* nop */; num != 1; /* nop */)  {
    if(num % 2 == 0)  {
      num /= 2;
      printf("\033[0;32m%d\n", num);
    }
    else  {
      num *= 3;
      num += 1;
      printf("\033[0;31m%d\n", num);
    }
  }
  
  return 0;
}