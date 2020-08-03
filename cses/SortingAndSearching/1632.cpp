#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, K;
  cin >> N >> K;

  vector<pii> end_start;
  end_start.reserve(N);
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    end_start.push_back({b, a});
  }

  sort(end_start.begin(), end_start.end());

  priority_queue<int, vi, greater<int>> pq;

  int cnt = 0;
  for (const auto&[end, start] : end_start) {
    if (!pq.empty() && pq.top() <= start) {
      pq.pop();
      pq.push(end);
      ++cnt;
    } else if (pq.size() < K) {
      pq.push(end);
      ++cnt;
    }
  }
  cout << cnt << '\n';

  return 0;
}

