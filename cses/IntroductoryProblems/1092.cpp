#include <cstdio>

using namespace std;

int N;


int main() {
  scanf("%d", &N);

  // the groups are splitable only if the sum is divisible by 2
  // N(N-1)/2 mod 2 = 0
  // N(N-1)   mod 4 = 0
  // so, either
  // N mod 4 = 0
  // or
  // N mod 4 = -1 = 3
  // also note that in the case that when it's divisible by 4,
  // we can split into groups including 
  // {1, N, 3, N-2, ...} and 
  // {2, N-1, 4, N-3, ...}
  // evenly
  // and similarly, when N mod 4 = 3, we can do
  // {1, 2, 4, N, 6, N-2, ...} and
  // {3, 5, N-1, 7, N-3, ...}
  // thus, groups are splitable if and only if N(N-1) mod 4 = 0
  if (N%4 == 0) {
    int half = N/2;
    printf("YES\n%d\n", half);
    for (int i = 1; i <= half; i += 2)
      printf("%d %d ", i, N-(i-1));
    printf("\n%d\n", half);
    for (int i = 2; i <= half; i += 2)
      printf("%d %d ", i, N-(i-1));
    printf("\n");

  } else if (N%4 == 3) {
    int half = (N-3)/2;
    printf("YES\n%d\n1 2 ", half+2);
    for (int i = 1; i <= half; i += 2)
      printf("%d %d ", i+3, N-(i-1));
    printf("\n%d\n3 ", half+1);
    for (int i = 2; i <= half; i += 2)
      printf("%d %d ", i+3, N-(i-1));
    printf("\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
