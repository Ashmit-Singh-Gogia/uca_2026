#include <stdio.h>
#include <string.h>

int find_substring(const char *haystack, const char *needle) {
  int n1 = strlen(haystack), n2 = strlen(needle);
  int i = 0, j = 0;
  int startIndex = -1;
  while (i < n1 - 1 && j < n2 - 1) {
    char c1 = haystack[i], c2 = needle[j];
    if (c1 == c2) {
      if (startIndex == -1) {
        startIndex = i;
      }
      j++;
    } else {
      j = 0;
      startIndex = -1;
    }
    i++;
  }
  return startIndex;
}

int main() {
  char haystack[256];
  char needle[256];
  printf("Enter the haystack string\n");
  fgets(haystack, 256, stdin);
  printf("Enter the needle string\n");
  fgets(needle, 256, stdin);

  printf("%d\n", find_substring(haystack, needle));

  return 0;
}