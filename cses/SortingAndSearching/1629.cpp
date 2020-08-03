#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<pii> movies(N);
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;

    movies[i] = {b, a};
  }

  sort(movies.begin(), movies.end());

  int cur_end = 0;
  int cnt = 0;
  for (const auto&[end, start] : movies) {
    if (cur_end <= start) {
      cur_end = end;
      ++cnt;
    }
  }
  cout << cnt << '\n';

  return 0;
}

