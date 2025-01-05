#include <stdio.h>
#include <math.h>

int main(void) {
  int num, num2, lim=10000, munNum; // lim is some number to check up to
  for(num=1; num<lim; num++)  {
    munNum=0;
    num2=num;
    for(/*nul*/; num>0; num/=10)  { 
      munNum+=pow((num%10), (num%10));
    }
    if(munNum==num2)  {
      printf("%i\n",munNum);
    }
    num=num2;
  }
  return 0;
}