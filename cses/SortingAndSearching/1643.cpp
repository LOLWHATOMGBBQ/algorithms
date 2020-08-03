#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  ll best = LLONG_MIN;
  ll cur = 0;
  for (int i = 0; i < N; ++i) {
    int val;
    cin >> val;

    cur += val;
    best = max(best, cur);
    if (cur < 0) {
      cur = 0;
    } 
  }
  cout << best << '\n';

  return 0;
}

