#include <stdio.h>

int bitAnd(int x, int y) { return ~(~x | ~y); }

int main() {
  int x = 6;
  int y = 5;

  int result = bitAnd(x, y);

  printf("%d\n", result);

  return 0;
}