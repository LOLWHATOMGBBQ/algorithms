#include <bits/stdc++.h>

using namespace std;

int N;

long long int ii(long long int i) {
  return i*(i-1)+1;
}

long long int calc(long long int x, long long int y) {
  if (x > y) {
    long long int mid = ii(x);
    long long int diff = x - y;

    if (x & 1)
      return mid - diff;
    else
      return mid + diff;
  }
  else if (y > x) {
    long long int mid = ii(y);
    long long int diff = y - x;

    if (y & 1)
      return mid + diff;
    else
      return mid - diff;

  } else {
    return ii(x);
  }
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%lld\n", calc(x, y));
  }
  //for (int i = 1; i < N; ++i) {
  //  for (int j = 1; j < N; ++j) {
  //    printf("%lld ", calc(i, j));
  //  }
  //  printf("\n");
  //}
  return 0;
}
