#include <bits/stdc++.h>

using namespace std;

int lc[26] = {0};
string s;

int main() {
  cin >> s;

  for (char c : s) {
    lc[c-'A']++;
  }
  bool mid = (s.size() & 1);
  char mid_char = 0;

  for (int i = 0; i < 26; ++i) {
    if (lc[i] & 1) {
      if (mid && !mid_char) {
        mid_char = i + 'A';
        lc[i]--;
      } else {
        cout << "NO SOLUTION\n";
        return 0;
      }
    }
  }

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < lc[i]; j += 2) {
      cout << (char) (i+'A');
    }
  }
  if (mid) {
    cout << mid_char;
  }
  for (int i = 25; i >= 0; --i) {
    for (int j = 0; j < lc[i]; j += 2) {
      cout << (char) (i+'A');
    }
  }
  cout << '\n';

  return 0;
}
