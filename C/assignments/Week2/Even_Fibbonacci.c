#include <stdio.h>

long long sumEvenFibBruteForce(long long n) {
  if (n < 2)
    return 0;

  long long a = 1;
  long long b = 1;
  long long sum = 0;

  while (1) {
    long long next = a + b;

    if (next > n) {
      break;
    }

    if (next % 2 == 0) {
      sum += next;
    }

    a = b;
    b = next;
  }

  return sum;
}

long long sumEvenFibOptimized(long long n) {
  if (n < 2)
    return 0;

  long long prev_even = 0;
  long long curr_even = 2;
  long long sum = prev_even + curr_even;

  while (1) {
    long long next_even = 4 * curr_even + prev_even;

    if (next_even > n) {
      break;
    }

    sum += next_even;

    prev_even = curr_even;
    curr_even = next_even;
  }

  return sum;
}

int main() {
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", sumEvenFibOptimized(n));
  return 0;
}