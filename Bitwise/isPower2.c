#include <stdio.h>

int isPower2(int x) { return !(x & (x + ~0)) & !!x & !(x >> 31); }

int main() {

  printf("isPower2(%d) = %d\n", 5, isPower2(5));
  printf("isPower2(%d) = %d\n", 8, isPower2(8));
  printf("isPower2(%d) = %d\n", 0, isPower2(0));

  return 0;
}