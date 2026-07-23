#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

int main() {
  // using strtok()
  char input[256];
  fgets(input, 256, stdin);
  char separators[] = ",";
  char *token = strtok(input, separators);
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, separators); // pass null here so old string is taken
  }
  return 0;
}