#include <bits/stdc++.h>

using namespace std;

int pow(int x, int y, int m) {
  if (y == 0)
    return 1;
  else if (y == 1)
    return x;
  else if (y%2) {
    int half = pow(x, (y-1)/2, m);
    return (((half*half)%m)*x)%m;
  } else {
    int half = pow(x, y/2, m);
    return (half*half)%m;
  }

}

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    int x, y, n;
    cin >> x >> y >> n;
    cout << pow(x, y, n) << endl;
  }
}
