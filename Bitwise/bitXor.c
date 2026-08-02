#include <stdio.h>

/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 */
int bitXor(int x, int y) { return ~(~x & ~y) & ~(x & y); }

int main() {
  int x = 4;
  int y = 5;

  int result = bitXor(x, y);

  printf("bitXor(%d, %d) = %d\n", x, y, result);

  return 0;
}