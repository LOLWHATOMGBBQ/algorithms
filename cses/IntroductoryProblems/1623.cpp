#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {

  int N;
  cin >> N;

  ll arr[N];
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  ll cur_best = LLONG_MAX;
  for (int i = 0; i < (1 << N); ++i) {
    ll cur_tot = 0;
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        cur_tot += arr[j];
      } else {
        cur_tot -= arr[j];
      }
    }
    cur_best = min(abs(cur_tot), cur_best);
  }
  cout << cur_best << '\n';
  return 0;
}

