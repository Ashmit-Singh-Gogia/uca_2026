#include <stdio.h>

int removeDups(int *arr, int n) {
  int i = 0, j = 0;
  while (j < n) {
    while (j < n && arr[j] == arr[i]) {
      j++;
    }
    if (j < n) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int k = removeDups(arr, n);
  printf("%d\n", k);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}