#include <stdio.h>

#define MAX_SIZE 256

int main() {
  char input[MAX_SIZE];

  if (fgets(input, MAX_SIZE, stdin) != NULL) {
    for (int i = 0; input[i] != '\0'; i++) {
      if (input[i] == ',') {
        putchar('\n');
      } else if (input[i] != '\n' && input[i] != '\r') {
        putchar(input[i]);
      }
    }
    putchar('\n');
  }

  return 0;
}