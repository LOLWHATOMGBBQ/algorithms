#include <cstdio>

using namespace std;

int N;


int main() {
  scanf("%d", &N);

  for (int i = 1; i <= N; ++i) {
    long long int squares = i*i;
    // number of ways for 2 knights
    long long int num_ways = squares*(squares-1)/2;

    // number of ways for 2 attacking knights
    long long int num_bad = 4*(i-1)*(i-2);

    printf("%lld\n", num_ways-num_bad);
  }
  return 0;
}
