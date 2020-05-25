#include <bits/stdc++.h>

using namespace std;

template<int m>
long long int modpow(long long int n, int k) {
  if (k == 0)
    return 1%m;
  else if (k == 1)
    return n%m;

  if (k & 1) 
    return (n%m)*modpow<m>(n*n%m, k/2)%m;
  else
    return modpow<m>(n*n%m, k/2)%m;
}

const int MOD = 10000007;
int n, k;
int main() {
  while (scanf("%d%d", &n, &k) == 2) {
    if (n == 0 && k == 0)
      break;

    int result = (
      2*modpow<MOD>(n-1, n-1) + 
      modpow<MOD>(n, n) +
      2*modpow<MOD>(n-1, k) +
      modpow<MOD>(n, k))%MOD;

    printf("%d\n", (int)result);
  }
  return 0;
}
