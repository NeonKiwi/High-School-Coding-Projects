#include <stdio.h>
#include <math.h>
float piFinder(float, float);
int i;
int main(void) {
  float pi = 3, denom;
  for(i=0,denom=2; i<1000000000; denom+=2,i++)  {
    pi = piFinder(pi,denom);
  }
  printf("%50.49f",pi);
  return 0;
}
float piFinder(float p, float d)  {
  if(i%2 == 0)  {
    p += (4/(d*(d+1)*(d+2)));
  }
  else {
    p -= (4/(d*(d+1)*(d+2)));
  }
  return p;
}