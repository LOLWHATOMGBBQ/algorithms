#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, X;
  cin >> N >> X;

  map<int, vi> vals;
  for (int i = 0; i < N; ++i) {
    int val;
    cin >> val;

    vals[val].push_back(i+1);
  }
  
  for (const auto&[val, vec] : vals) {
    auto result = vals.find(X-val);
    if (result != vals.end() && result->second.back() != vec.front()) {
      cout  << vec.front() << ' ' << result->second.back() << '\n';
      return 0;
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}

