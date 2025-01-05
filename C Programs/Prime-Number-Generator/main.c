#include <stdio.h>

int main(void) {
  int num, lim=1000, div, yes=1;
  for(num=1; num<lim; num++)  {
    for(div=num/2; div>1; div--)  {
      if(num%div==0)  {
        yes=2;
      }
    }
    if(yes==1)  {
      printf("%i\n",num);
    }
    yes=1;
  }
  return 0;
}