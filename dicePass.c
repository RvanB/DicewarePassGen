#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int rollDie() {
 return (rand() % 6); 
}

void getWord(char* word) {
  int i = 0;

  int digits[5];
  for (i = 0; i < 5; ++i)
    digits[i] = rollDie();

  int line = (digits[0] * pow(6, 4) + digits[1] * pow(6, 3) + digits[2] * pow(6, 2) + digits[3] * 6 + digits[4]) + 3;

  i = 0;

  FILE* file = fopen("diceware.wordlist.asc", "r");

  while (i < line) {
    fgets(word, 20, file);
    ++i;
  }
}

int main() {
  srand(time(0));
  char word[20];
  for (int i = 0; i < 4; i++) {
    getWord(word);
    word[strlen(word) - 1] = 0;
    printf("%s ", &word[6]);
  }
  printf("\n");
  return 0;
}
