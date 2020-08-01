#include <bits/stdc++.h>

using namespace std;

int T;
int N;

int main() {

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> N;

    bool I[N];
    bool O[N];
    char c;
    for (int i = 0; i < N; ++i) {
      cin >> c;
      I[i] = c == 'Y';
    }
    for (int i = 0; i < N; ++i) {
      cin >> c;
      O[i] = c == 'Y';
    }

    vector<vector<bool>> dp(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) {
      dp[i][i] = true;

      if (0 <= i-1 && O[i] && I[i-1]) {
        dp[i][i-1] = true;
      }
      
      if (i+1 < N && O[i] && I[i+1]) {
        dp[i][i+1] = true;
      }
    }

    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (dp[i][k] && dp[k][j]) {
            dp[i][j] = true;
          }
        }
      }
    }

    cout << "Case #" << t+1 << ":\n";
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << (dp[i][j] ? 'Y' : 'N');
      }
      cout << '\n';
    }
  }

  
  return 0;
}
