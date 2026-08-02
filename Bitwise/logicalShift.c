#include <stdio.h>

int logicalShift(int x, int n) { return (x >> n) & ~(((1 << 31) >> n) << 1); }

int main() {
  int x = 0x87654321;
  int n = 4;

  int result = logicalShift(x, n);

  printf("0x%08X\n", result);

  return 0;
}