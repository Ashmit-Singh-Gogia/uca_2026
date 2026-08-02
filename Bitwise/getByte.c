#include <stdio.h>

int getByte(int x, int n) { return (x >> (n << 3)) & 0xFF; }

int main() {
  int x = 0x12345678;
  int n = 1;

  int result = getByte(x, n);

  printf("0x%X\n", result);

  return 0;
}