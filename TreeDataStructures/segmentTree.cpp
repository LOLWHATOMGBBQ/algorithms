#include <bits/stdc++.h>

using namespace std;

// Maximum size for segment trees problems is usually 100000


template <class T>
class SegmentTree {
	SegmentTree* left; // Pointer to the left child
	SegmentTree* right; // Pointer to right child
		
	T value = T(); // Current value of the segment tree
	T delta = T(); // Value for lazy prop
	
	int left_idx; // Represents the interval [left_idx, right_idx]
	int right_idx; // inclusive interval
	
	void updateLazy(T val) {
		delta += val;
		value += (right_idx - left_idx + 1) * val;
	}
	
	
public:
	// This is the default constructor using addition as the evaluation
	SegmentTree(int left_idx, int right_idx, T values[]) :
		left{left_idx >= right_idx ? nullptr : new SegmentTree(left_idx, (right_idx + left_idx)/2, values)},
		right{left_idx >= right_idx ? nullptr : new SegmentTree((right_idx + left_idx)/2 + 1, right_idx, values)},
		
		left_idx{left_idx},
		right_idx{right_idx} {
		
		// Update the tree
		if (left_idx < right_idx) {
			// printf("[%d, %d] made [%d, %d] = %d and [%d %d] = %d\n", left_idx, right_idx, left_idx, mid, getVal(left_idx, mid), mid+1, right_idx, getVal(mid+1, right_idx));
			// Update current value
			value = left->getVal(left_idx, (right_idx + left_idx)/2) +
					right->getVal((right_idx + left_idx)/2+1, right_idx);
		}
		else if (left_idx == right_idx) {
			// Our current value
			value = values[left_idx];
		}
	}

	~SegmentTree() {
		// Recursively delete the left side
		delete left;
		// Recursively delete the right side
		delete right;
	}
	
	// Gets the value for the range [left_range, right_range]
	T getVal(int left_range, int right_range) {
		// printf("getval([%d, %d] : [%d, %d]) = %d\n", left_idx, right_idx, left_range, right_range, value);
		if (right_range < left_idx || right_idx < left_range){
			return 0;
		}
		else if (left_range <= left_idx && right_idx <= right_range) {
			return value;
		}
		
		// Push lazy deltas into children
		if (delta){
			left->updateLazy(delta);
			right->updateLazy(delta);
			delta = 0;
		}
		
		return left->getVal(left_range, right_range) + right->getVal(left_range, right_range);
			
	}
	
	void updateRange(int left_range, int right_range, T val) {
		// Let I = [left_idx, right_idx)
		// Let I_q = [left_range, right_range)
		// Let I_left = [left->left_idx, left->right_idx)
		// Let I_right = [right->left_idx, right->right_idx)
		// If I \subseteq I_q
		// printf("updating: [left_idx: %d, right_idx: %d] on [%d, %d]", left_idx, right_idx, left_range, right_range);
		if (right_range <= left_idx || right_idx <= left_range) {
			return;
		}
		else if (left_range <= left_idx  && right_idx <= right_range) {
			// Lazy delta
			updateLazy(val);
			return;
		}
		// This value is guarunteed to be positive since we have the following 
		// preconditions
		// left_range <= right_range
		// left_idx <= right_idx
		// left_idx < right_range
		// left_range < right_idx
		//
		// So we get:
		// left_range, left_idx <= right_idx
		// and
		// left_range <= right_range
		// left_idx < right_range,
		// so
		// left_range, left_idx <= right_range, right_idx
		value += (min(right_range, right_idx) - max(left_idx, left_range) + 1) * val;
		
		left->updateRange(left_range, right_range, val);
		right->updateRange(left_range, right_range, val);
		
	}
	
	
	// Helper function for printing the tree (Will fix later)
	// TODO: better formatting make it actually look like a tree
	void printTree() {
		// printf("eval([%d, %d]) = %d\n", left_idx, right_idx, value);
		if (left)
			left->printTree();
		if (right)
			right->printTree();
	}
};

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	
	SegmentTree<int>* stree = new SegmentTree<int>(0, 6, a);
	
	stree->printTree();
	
	stree->updateRange(2, 5, 10);
	cout << stree->getVal(3, 6) << endl;
	stree->printTree();
	
	delete stree;
}
