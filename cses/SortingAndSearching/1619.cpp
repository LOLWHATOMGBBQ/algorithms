#include <bits/stdc++.h>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<pair<int, bool>> custs(2*N);
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    custs[i<<1] = make_pair(a, true);
    custs[i<<1|1] = make_pair(b, false);
  }
  sort(custs.begin(), custs.end());

  int best = 0;
  int cur = 0;
  for (const auto&[start, val] : custs) {
    cur += val ? 1 : -1;
    best = max(best, cur);
  }
  cout << best << '\n';
  return 0;
}

