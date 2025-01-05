#include <stdio.h>
#include <math.h>
float piFinder(float, float);
int i;
int main(void) {
  float pi = 0, denom;
  for(i=0,denom=1; i<100000; denom+=1,i++)  {
    pi = piFinder(pi,denom);
  }
  pi= sqrt(pi*6);
  printf("%50.49f",pi);
  return 0;
}
float piFinder(float p, float d)  {
  p += 1/pow(d, 2);
  return p;
}