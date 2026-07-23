#include <stdio.h>
#include <string.h>
void reverseString(char *str) {
  int left = 0, right = strlen(str) - 2;

  while (left < right) {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
    left++;
    right--;
  }
}

int main() {

  char str[256];
  fgets(str, 256, stdin);

  printf("Actual String : %s\n", str);
  printf("String length before reverse %lu\n", strlen(str));
  reverseString(str);
  printf("Reversed String : %s\n", str);
  printf("String length after reverse %lu\n", strlen(str));
  return 0;
}
