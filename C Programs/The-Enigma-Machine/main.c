#include <ctype.h>
#include <stdio.h>
#include <string.h>

char message[200];
char mappedRotor[27];

void popeyesChickenSandwich(void);
void shiftTheLettuce(void);
void fourPicklesAtATime(void);
void popeyesChickenDeconstructor(void);
void turnTheTomatoes(int);

int main(void) {
  int choice, j;
  char x;
  do  {
    printf("Would you like to encode (1) or decode (2) a message?\n");
    scanf("%i",&choice);
  }
  while(choice != 1 && choice != 2);
  //we don't need to have this choice because we just want to encode
  printf("\nWhat is the message? (Type in all caps please)\n");
  scanf("%c%s",&x,message);
  if(choice == 1) {
    popeyesChickenSandwich();
  }
  else if(choice == 2)  {
    popeyesChickenDeconstructor();
    //we don't need the decrypter right now
  }
  return 0;
}

void popeyesChickenSandwich(void)  {
  int rcount = 0;
  int i,l,backwards = 0;
  for(i = 0;i < strlen(message);i++) {
    while(rcount < 3) {
      if(rcount == 0) {
        strcpy(mappedRotor,"EKMFLGDQVZNTOWYHXUSPAIBRCJ");
        for(l = i;l > 0;l--) {
          shiftTheLettuce();
        }
        turnTheTomatoes(i);
      }
      else if(rcount == 1)  {
        strcpy(mappedRotor,"AJDKSIRUXBLHWTMCQGZNPYFVOE");
        if(i >= 6)  {
          for(l = i;l > 6;l--) {
            shiftTheLettuce();
          }
        }
        turnTheTomatoes(i);
      }
      else if(rcount == 2)  {
        strcpy(mappedRotor,"BDFHJLCPRTXVZNYEIWGAKMUSQO");
        if(i >= 25)  {
          for(l = i;l > 25;l--) {
            shiftTheLettuce();
          }
        }
        turnTheTomatoes(i);
      }
      if(backwards == 0 && rcount == 2)  {
        strcpy(mappedRotor,"EJMZALYXVBWFCRQUONTSPIKHGD");
        turnTheTomatoes(i);
        rcount=3;
        backwards=1;
      }
      if(backwards == 0){
        rcount++;
      }
      else if(backwards == 1)  {
        if(rcount == 0) {
          break;
        }
        else  {
          rcount--;
        }
      }
    }
    rcount = 0;
    backwards = 0;
  }
  fourPicklesAtATime();
}

void shiftTheLettuce(void) {
  int k;
  char lastLetter;
  lastLetter = mappedRotor[0];
  for(k = 1;k < strlen(mappedRotor);k++)  {
    mappedRotor[k-1] = mappedRotor[k];
  }
  mappedRotor[25] = lastLetter;
}

void fourPicklesAtATime(void) {
  int i;
  for(i = 0;i < strlen(message);i++)  {
    if(i%4 == 0)  {
      printf("\n%c",message[i]);
    }
    else  {
      printf("%c",message[i]);
    }
  }
}

void turnTheTomatoes(int i)  {
  int letter = message[i]-65;
  message[i] = mappedRotor[letter];
}

//from this point forward is the decrypt function, we don't need this as of right now

void popeyesChickenDeconstructor (void) {
  
  int rcount = 0;
  int i,l,k,backwards = 0;
  for(i = 0;i < strlen(message);i++) {
    while(rcount < 3) {
      if(rcount == 0) {
        strcpy(mappedRotor,"EKMFLGDQVZNTOWYHXUSPAIBRCJ");
        for(l = i;l > 0;l--) {
          shiftTheLettuce();
        }
        for(k = 0;k < strlen(mappedRotor);k++)  {
          if(message[i] == mappedRotor[k]) {
            message[i] = k+65;
            break;
          }
        }
      }
      else if(rcount == 1)  {
        strcpy(mappedRotor,"AJDKSIRUXBLHWTMCQGZNPYFVOE");
        if(i >= 6)  {
          for(l = i;l > 6;l--) {
          shiftTheLettuce();
          }
        }
        for(k = 0;k < strlen(mappedRotor);k++)  {
          if(message[i] == mappedRotor[k]) {
            message[i] = k+65;
            break;
          }
        }
      }
      else if(rcount == 2)  {
        strcpy(mappedRotor,"BDFHJLCPRTXVZNYEIWGAKMUSQO");
        if(i >= 25)  {
          for(l = i;l > 25;l--) {
          shiftTheLettuce();
          }
        }
        for(k = 0;k < strlen(mappedRotor);k++)  {
          if(message[i] == mappedRotor[k]) {
            message[i] = k+65;
            break;
          }
        }
      }
      char reflector[27] = "EJMZALYXVBWFCRQUONTSPIKHGD";
      if(backwards == 0 && rcount == 2)  {
        for(k = 0;k < strlen(reflector);k++)  {
          if(message[i] == reflector[k]) {
            message[i] = k+65;
            break;
          }
        }
        rcount=3;
        backwards=1;
      }
      if(backwards == 0){
        rcount++;
      }
      else if(backwards == 1)  {
        if(rcount == 0) {
          break;
        }
        else  {
          rcount--;
        }
      }
    }
    rcount = 0;
    backwards = 0;
  }
  printf("%s",message);
}