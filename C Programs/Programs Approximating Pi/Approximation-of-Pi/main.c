#include <math.h>
#include <stdio.h>
float piFinder(float);
float pi = 1;
int main(void) {
  float num = sqrt(2);
  int i;
  for (i = 0; i < 20; i++) {
    num = piFinder(num);
  }
  pi = 2 / pi;
  printf("%50.49f", pi);
  return 0;
}
float piFinder(float n) {
  pi = pi / 2 * n;
  n = sqrt(2 + n);
  return n;
}