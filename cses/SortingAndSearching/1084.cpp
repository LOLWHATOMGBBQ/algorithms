#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int N, M, K;
  cin >> N >> M >> K;

  vi apps(N);
  vi apts(M);

  for (int i = 0; i < N; ++i) {
    cin >> apps[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> apts[i];
  }

  sort(apps.begin(), apps.end());
  sort(apts.begin(), apts.end());

  int tot = 0;
  int i = 0;
  for (int applicant : apps) {
    // remove lower apts
    while (i < M && apts[i] < applicant-K) {
      ++i;
    }
    if (i == M)
      break;

    if (abs(apts[i] - applicant) <= K) {
      ++i;
      ++tot;
      if (i == M)
        break;
    }
  }
  cout << tot << '\n';

  return 0;
}

