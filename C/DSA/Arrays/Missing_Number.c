#include <stdio.h>

int missingNumber(int *arr, int n) {
  int xor = 0;
  for (int i = 0; i < n; i++) {
    xor ^= i;
    xor ^= arr[i];
  }
  xor ^= n;
  return xor;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int missinNum = missingNumber(arr, n);
  printf("%d\n", missinNum);
}