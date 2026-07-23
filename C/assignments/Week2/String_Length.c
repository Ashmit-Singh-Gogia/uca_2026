#include <stdio.h>

int main() {
  char str[256];
  int len = 0;
  fgets(str, 256, stdin);
  while (str[len] != '\0' && str[len] != '\n') {
    len++;
  }
  printf("%d\n", len);
}