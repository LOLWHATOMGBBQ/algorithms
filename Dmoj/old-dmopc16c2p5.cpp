#include <bits/stdc++.h>

using namespace std;

int N, M, K;

struct Node {
  Node* left;
  Node* right;
  int val;

  Node(Node* left, Node* right) : left{left}, right{right}, val{0} {
    if (left != nullptr)
      this->val += left->val;
    if (right != nullptr)
      this->val += right->val;
  }
  Node(int val) : left{nullptr}, right{nullptr}, val{val} {}
  Node() : left{nullptr}, right{nullptr}, val{0} {}
};

// build for range [lo, hi]
Node* build(int lo, int hi) {
  if (lo == hi) // if pitchers[lo] == true, then it is full
    return new Node(0);

  int mid = (lo+hi)/2;

  return new Node(build(lo, mid), build(mid+1, hi));
}

Node* update(Node* root, bool val, const int& idx, const int& lo, const int& hi) {
  // lo == idx == hi
  if (root->left == nullptr) {
    return new Node(val);
  }

  int mid = (lo+hi)/2;
  if (idx <= mid) {
    // idx in range [lo, mid]
    return new Node(update(root->left, val, idx, lo, mid), root->right);
  } else {
    // idx in range [mid+1, hi]
    return new Node(root->left, update(root->right, val, idx, mid+1, hi));
  }
  new_node->val = new_node->left->val + new_node->right->val;
  return new_node;
}

// first represents if it's flipped
pair<bool, Node*> queries[200001];
deque<pair<int, int>> max_k;

int main() {
  cin >> N >> M >> K;

  bool flipped = false;
  Node* root = build(1, N);
  Node* cur_root = root;
  queries[0] = make_pair(flipped, cur_root);

  for (int i = 1; i <= M; ++i) {
    char c; 
    int p;
    cin >> c;
    if (c == 'F') {
      cin >> p; 
      // add the bucket
      queries[i] = make_pair(flipped, update(cur_root, !flipped, p, 1, N));
    } else if (c == 'D') {
      cin >> p;
      queries[i] = make_pair(flipped, update(cur_root, flipped, p, 1, N));
    } else if (c == 'R') {
      cin >> p;
      queries[i] = queries[p];
    } else if (c == 'X') {
      flipped = !flipped;
      queries[i] = make_pair(flipped, queries[i-1].second);
    }
    cur_root = queries[i].second;

    int cur_val = cur_root->val;
    if (flipped)
      cur_val = N-cur_val;
    
    // Remove from the back
    while(!max_k.empty() && max_k.back().first < cur_val)
      max_k.pop_back();
    max_k.push_back(make_pair(cur_val, i));

    cout << cur_val << ' ' << max_k.front().first << '\n';

    if (max_k.front().second == i-K+1)
      max_k.pop_front();
  }

  return 0;
}
