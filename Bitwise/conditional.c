#include <stdio.h>

int conditional(int x, int y, int z) {
  return (y & (~(!!x) + 1)) | (z & ~(~(!!x) + 1));
}

int main() {
  int x = 2;
  int y = 4;
  int z = 5;

  int result = conditional(x, y, z);

  printf("%d\n", result);

  return 0;
}