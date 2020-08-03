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

  int best = 0;
  deque<pair<int, set<int>::iterator>> order;
  set<int> songs;
  for (int i = 0; i < N; ++i) {
    int val;
    cin >> val;

    if (songs.find(val) != songs.end()) {
      while (order.front().first != val) {
        songs.erase(order.front().second);
        order.pop_front();
      }
      // order.front() == val
      songs.erase(order.front().second);
      order.pop_front();
    }
    
    order.push_back({val, songs.insert(val).first});

    if (songs.size() > best)
      best = songs.size();
  }
  cout << best << '\n';
  return 0;
}

