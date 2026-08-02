#include <stdio.h>

int fitsBits(int x, int n) {
  return !(((x << (32 + ~n + 1)) >> (32 + ~n + 1)) ^ x);
}

int main() {
  printf("%d\n", fitsBits(5, 3));
  printf("%d\n", fitsBits(-4, 3));

  return 0;
}