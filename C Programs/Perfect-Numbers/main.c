#include <stdio.h>

int perfect = 0;
void perfNum(int);
int main(void) {
  int num, divisor;
  for (num = 0; num < 100000000; num += 1) {
    perfect = 0;
    for (divisor = 1; divisor <= num / 2; divisor++) {
      if (num % divisor == 0) {
        perfNum(divisor);
      }
    }
    if (perfect == num) {
      printf("%i\n", perfect);
    }
  }
}

void perfNum(d) {perfect = perfect + d;}