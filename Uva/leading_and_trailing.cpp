#include <bits/stdc++.h>

using namespace std;

template<int size> 
int clip(int x) {
  while (x >= size)
    x/= 10;
  return x;
}

int leading(int x, int y) {
  if (y == 0)
    return 1;
  else if (y % 2) {
    return clip<10000>(clip<10000>(x)*(leading(clip<10000>(x)*clip<10000>(x), (y-1)/2)));
  } else {
    return clip<10000>(leading(clip<10000>(x)*clip<10000>(x), (y-1)/2));
  }
}
int trailing(int x, int y) {
  if (y == 0)
    return 1;
  else if (y % 2) {
    return x*(trailing(x*x%1000, (y-1)/2)%1000)%1000;
  } else {
    return trailing(x*x%1000, y/2)%1000;
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, k;
    cin >> n >> k;

    // double digits = k*log10(n);
    int lead = leading(n, k);
    int trail = trailing(n, k);

    printf("%03d...%03d\n", lead, trail);
  }

}
