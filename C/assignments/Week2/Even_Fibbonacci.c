#include <stdio.h>

long long sumEvenFibBruteForce(long long n) {
  long long a = 0, b = 1, c = 1;
  long long ans = 0;
  while (c < n) {
    a = b;
    b = c;
    c = a + b;
    if (c % 2 == 0) {
      ans += c;
    }
  }
  return ans;
}

long long sumEvenFibOptimized(long long n) {
  // Formula we can derive is Fk = 4 * Fk-3 + Fk-6
  if (n < 2)
    return 0;
  long long prevEven = 0; // this is f(k-6)
  long long currEven = 2; // this is f(k-3)
  long long sum = 0;
  while (currEven <= n) {
    sum += currEven;
    long long nextEven = 4 * currEven + prevEven; // nextEven represents Fk
    prevEven = currEven;
    currEven = nextEven;
  }
  return sum;
}

int main() {
  long long n;
  scanf("%lld", &n);
  printf("%lld\n", sumEvenFibOptimized(n));
  return 0;
}