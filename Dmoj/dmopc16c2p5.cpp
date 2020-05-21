#include <bits/stdc++.h>

using namespace std;

// TLDR: persistent segment tree + sliding window maximum

int N, M, K;

// nodes[i][0] = val
// nodes[i][1] = left index
// nodes[i][2] = right index
int nodes[1000000][3];
int node_count = 1;


int new_node(int val, int left, int right) {
  int cur_node_idx = node_count++;

  nodes[cur_node_idx][0] = val;
  nodes[cur_node_idx][1] = left;
  nodes[cur_node_idx][2] = right;
  nodes[cur_node_idx][0] += nodes[left][0] + nodes[right][0];

  return cur_node_idx;
}
int new_node(int left, int right) {
  return new_node(0, left, right);
}
int new_node(int val) {
  return new_node(val, 0, 0);
}

int build(int low, int high) {
  if (low == high)
    return new_node(0);
  else {
    int mid = (low+high)/2;
    
    return new_node(
        build(low, mid),  // left
        build(mid+1, high) // right
    );
  }
}

int update(int root, int lo, int hi, int update_idx, bool val) {
  if (lo == hi)
    return new_node(val);
  else {
    int mid = (lo+hi)/2;

    if (update_idx <= mid)
      return new_node(
          update(nodes[root][1], lo, mid, update_idx, val),  // update left
          nodes[root][2] // right
      );
    else 
      return new_node(
          nodes[root][1], // right
          update(nodes[root][2], mid+1, hi, update_idx, val)  // update left
      );
  }
}

int queries[200001] = {};
bool flipped[200001] = {};

deque<int> max_k;
queue<int> prev_vals;

int main() {
  scanf("%d%d%d", &N, &M, &K);

  bool cur_flipped = false; 
  // Build initial segment tree
  queries[0] = build(1, N);
  flipped[0] = false;

  for (int i = 1; i <= M; ++i) {
    char c;
    scanf(" %c", &c);


    if (c == 'F') {
      int p;
      scanf("%d", &p);
      queries[i] = update(queries[i-1], 1, N, p, !cur_flipped);
    } else if (c == 'D') {
      int p;
      scanf("%d", &p);

      queries[i] = update(queries[i-1], 1, N, p, cur_flipped);
    } else if (c == 'R') {
      int q;
      scanf("%d", &q);

      queries[i] = queries[q];
      cur_flipped = flipped[q];
    } else {
      queries[i] = queries[i-1];
      cur_flipped = !cur_flipped;
    }
    flipped[i] = cur_flipped;

    int cur_val = nodes[queries[i]][0];
    if (cur_flipped)
      cur_val = N-cur_val;

    if (prev_vals.size() == K) {
      if (prev_vals.front() == max_k.front()) 
        max_k.pop_front();
      prev_vals.pop();
    }
    prev_vals.push(cur_val);

    while (!max_k.empty() && max_k.back() < cur_val)
      max_k.pop_back();
    max_k.push_back(cur_val);

    printf("%d %d\n", cur_val, max_k.front());
  }
  return 0;
}
