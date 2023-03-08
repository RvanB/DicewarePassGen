#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void getWord(char* word) {
  // Create line number from dice rolls
  int line = 0;
  for (int i = 0; i < 5; ++i) {
    int roll = rand() % 5;
    line += roll * pow(6, 4 - i);
  }

  // Open word list
  FILE* file = fopen("diceware.wordlist.asc", "r");
  
  // Read word on line number
  int i = 0;
  while (i < line) {
    // Read up to newline character
    fgets(word, 20, file);
    i++;
  }
}

int main(int argc, char** argv) {
  // Check if word count supplied
  int wordCount = 4;
  if (argc == 2) {
    int val = atoi(argv[1]);
    if (val) {
      wordCount = val;
    } else {
      fprintf(stderr, "dicePass: Invalid word count \"%s\"", argv[1]);
      return 1;
    }
  }
  // Seed random with current time
  srand(time(0));

  char word[20];
  for (int i = 0; i < wordCount; i++) {
    // Store a new word in the buffer
    getWord(word);

    // Add string terminator
    word[strlen(word) - 1] = 0;

    // Skip number before word
    printf("%s ", &word[6]);
  }
  printf("\n");
  return 0;
}
