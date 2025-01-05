#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  long long n;
  float x,y;
  int y2;
  for(x = 0;x < 10000000;x++)  {
    for(y = 0;y < 10000000;y++)  {
      n = y;
      y2=0;
      do  {
            n /= 10;
            ++y2;
          } while (n != 0);
      if(((pow(10,y2))*x)+y == (x+y)*((fabs(x-y)+1)/2))  { 
        if(x == y)  {
          printf("\nX = %.0f\nY = %.0f\nThe two numbers together is %.0f%.0f, and %.0f = %.0f\n",x,x,x,x,x,x);
        }
        else if(fabs(x-y) < 2)  {
          printf("\nX = %.0f\nY = %.0f\nThe two numbers together is %.0f%.0f, and %.0f + %.0f = %.0f\n",x,y,x,y,x,y,x+y);
        }
        else if(x < y)  {
          printf("\nX = %.0f\nY = %.0f\nThe two numbers together is %.0f%.0f, and %.0f + %.0f... + %.0f = %.0f\n",x,y,x,y,x,x+1,y,(x+y)*((fabs(x-y)+1)/2));
        }
        else if(x < y)  {
          printf("\nX = %.0f\nY = %.0f\nThe two numbers together is %.0f%.0f, and %.0f + %.0f... + %.0f = %.0f\n",x,y,x,y,y,y+1,x,(x+y)*((fabs(x-y)+1)/2));
        }       
      }
    }
  }    
  return 0;
}