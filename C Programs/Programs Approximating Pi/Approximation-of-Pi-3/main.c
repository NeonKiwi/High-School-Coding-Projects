#include <stdio.h>
#include <math.h>
float piFinder(float, float);
int i;
int main(void) {
  float pi = 0, denom;
  for(i=0,denom=1; i<100000; denom+=2,i++)  {
    pi = piFinder(pi,denom);
  }
  printf("%50.49f",pi);
  return 0;
}
float piFinder(float p, float d)  {
  if(i%2 == 0)  {
    p += (4/d);
  }
  else {
    p -= (4/d);
  }
  return p;
}