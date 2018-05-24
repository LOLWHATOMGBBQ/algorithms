#include <bits/stdc++.h>
#define MAX 10001


using namespace std;

int segmentTree[MAX];
int lazyTree[MAX];


void build(int left, int right, int arr[]) {
    int mid = (left+right)/2;
    
    build(left, mid);
    build(mid+1, right);
}

void update(int left, int right, int val) {
    // left_tree: segmentTree[x << 1|1];
    // right_tree: segmentTree[x << 1]
    
    
    
}

int query(int left_range, int right_range) {
    
}
