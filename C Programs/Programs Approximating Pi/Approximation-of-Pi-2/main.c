#include <stdio.h>
#include <math.h>
float piFinder(void);
float pi = 1;
int i;
float numer,denom;
int main(void) {
  for(i=0,numer=2,denom=1; i<3990; numer+=2,denom+=2,i++)  {
    pi = piFinder();
  }
  pi*=2;
  printf("%50.49f",pi);
  return 0;
}
float piFinder(void)  {
  pi *= (numer/denom)*(numer/(denom+2));
  return pi;
}