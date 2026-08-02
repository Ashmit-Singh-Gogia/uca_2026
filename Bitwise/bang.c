#include <stdio.h>

int bang(int x) { return (((~x + 1) | x) >> 31) + 1; }

int main() {
  printf("bang(%d) = %d\n", 3, bang(3));
  printf("bang(%d) = %d\n", 0, bang(0));

  return 0;
}