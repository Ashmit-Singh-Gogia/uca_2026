#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {
  int i = 0, j = 0;

  if (needle[0] == '\0') {
    return 0;
  }

  while (haystack[i] != '\0') {
    j = 0;
    while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
      j++;
    }
    if (needle[j] == '\0') {
      return i;
    }
    i++;
  }

  return -1;
}

int main() {
  char haystack[256];
  char needle[256];
  int i;

  fgets(haystack, 256, stdin);
  i = 0;
  while (haystack[i] != '\0') {
    if (haystack[i] == '\n') {
      haystack[i] = '\0';
      break;
    }
    i++;
  }

  fgets(needle, 256, stdin);
  i = 0;
  while (needle[i] != '\0') {
    if (needle[i] == '\n') {
      needle[i] = '\0';
      break;
    }
    i++;
  }

  printf("%d\n", find_substring(haystack, needle));

  return 0;
}