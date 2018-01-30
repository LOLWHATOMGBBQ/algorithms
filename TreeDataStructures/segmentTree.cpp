#include <bits/stdc++.h>

using namespace std;

// Maximum size for segment trees problems is usually 100000




template class <T>
class SegmentTree {
	struct Node {
		T value; // Current value of the segment tree
		T delta; // Value for lazy prop
		Node* left; // Pointer to the left child
		Node* right; // Pointer to right child
	}

	void build(T values[], int low_idx, int high_idx, T (* cmp)(T, T)) {
		 
	}
	void build(T values[], T (* cmp)(T, T)) {
		for 
	}
}
const int MAX_SIZE = 1e5+1;

int N;
// Original array for seg tree
int array[MAX_SIZE];
// Segment tree where each of the children of an index idx are:
// 2*idx and 2*idx+1. (Actually in this implementation we use a nice trick
// where we use idx>>1|1 and idx>>1 as bit operations are faster)
// idx>>1 is the same as idx*2 so |1 would be the same as +1
int tree[2*MAX_SIZE];
int lazy[2*MAX_SIZE];

void build(int idx) {
	while (idx > 1) {
		idx >>= 1;

}
