#include <bits/stdc++.h>
#define MAX_N 300001
#define NUM_TYPES 21

using namespace std;

// Fast implementation of an array of k segment trees.
// 4*MAX_N
// count of [val] in [start, end] 
int segment_tree[NUM_TYPES][MAX_N << 2];
// left, right 
vector<int> arr;
int N, M;
int query;
int ai, bi;
int gi, li, ri, ci;

void build(int kthtree, int index=1, int left=0, int right=N-1) {
    if (left >= right) {
        if (arr[left] == kthtree) {
            segment_tree[kthtree][index] = 1;
        }
        else {
            segment_tree[kthtree][index] = 0;
        }
        // segment_tree[kthtree][index] = (arr[left] == kthtree);
    }
    else {
        int mid = left + (right - left)/2;
        build(kthtree, index << 1, left, mid);
        build(kthtree, index << 1 | 1, mid+1, right);

        segment_tree[kthtree][index] = segment_tree[kthtree][index << 1] + segment_tree[kthtree][index << 1 | 1];
    }
}

void modify(int index, int kthtree, int tree_idx = 1, int left=0, int right=N-1) {
    if (left == right) {
        // if at bottom
        segment_tree[kthtree][tree_idx] ^= 1;
    }
    else {
        // otherwise go into the set
        int mid = left + (right-left)/2;
        if (index <= mid) {
            modify(index, kthtree, tree_idx<<1,left, mid);
        }
        else {
            modify(index, kthtree, tree_idx<<1 | 1, mid+1, right);
        }
        segment_tree[kthtree][tree_idx] = segment_tree[kthtree][tree_idx << 1] + segment_tree[kthtree][tree_idx << 1 | 1];
    }
}

int sum(int kthtree, int left_range, int right_range, int tree_idx = 1, int left_idx=0, int right_idx = N-1) {
    if (left_range > right_range) {
        return 0;
    }
    else if (left_range == left_idx && right_range == right_idx) {
        return segment_tree[kthtree][tree_idx];
    }
    else {
        int mid = left_idx + (right_idx - left_idx)/2;
        return sum(kthtree,             left_range, min(right_range, mid), tree_idx << 1    , left_idx,       mid) + 
               sum(kthtree, max(left_range, mid+1),           right_range, tree_idx << 1 | 1,    mid+1, right_idx);
    }
}
