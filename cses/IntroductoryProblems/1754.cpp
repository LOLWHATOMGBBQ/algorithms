#include <bits/stdc++.h>

using namespace std;

bool check(int a, int b) {
  if (a < b)
    return check(b, a);
  else if (a == b)
    return a%3 == 0;
  else {
    int diff = a - b;
    if (diff > b || 2*diff > a) {
      return false;
    }
    else {
      return check(a-2*diff, b - diff);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;


  for (int i = 0; i < T; ++i) {
    int a, b;
    cin >> a >> b;

    cout << (check(a, b) ? "YES\n" : "NO\n");
  }

  return 0;
}
