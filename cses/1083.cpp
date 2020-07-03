#include <bits/stdc++.h>

using namespace std;

long long int N;
long long int tot;

int main() {
  scanf("%lld", &N);
  tot = N*(N+1)/2;
  for (int i = 1; i < N; ++i) {
    int d;
    scanf("%d", &d);
    tot -= d;
  }

  printf("%d\n", tot);
}
