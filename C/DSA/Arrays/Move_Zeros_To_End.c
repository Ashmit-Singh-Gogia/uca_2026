#include <stdio.h>

void moveZeros(int *arr, int n) {
  int i = 0, j = 1;
  while (j < n && i < n) {
    while (i < n && arr[i] != 0) {
      i++;
    }
    j = i + 1;
    while (j < n && arr[j] == 0) {
      j++;
    }
    // swap
    if (i < n && j < n) {
      arr[i] = arr[j];
      arr[j] = 0;
    }
    i++;
    j = i + 1;
  }
}
int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  moveZeros(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
