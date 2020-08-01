#include <bits/stdc++.h>

using namespace std;

int T, N;
string s;

int main() {
  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> N;
    char c;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      cin >> c;
      cnt += c =='A' ? 1 : -1;
    }
    cout << "Case #"<< t+1 << ((cnt == 1 || cnt == -1) ? ": Y\n" : ": N\n");
  }
}
