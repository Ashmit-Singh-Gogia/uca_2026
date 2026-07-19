#include <stdio.h>

void reverse_string(char *str) {
  int len = 0;

  while (str[len] != '\0' && str[len] != '\n') {
    len++;
  }
  str[len] = '\0';

  int start = 0;
  int end = len - 1;

  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

int main() {
  char str[256];

  fgets(str, 256, stdin);
  reverse_string(str);

  printf("%s\n", str);

  return 0;
}