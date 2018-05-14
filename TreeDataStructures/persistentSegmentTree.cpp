#include <bits/stdc++.h>

using namespace std;

// Maximum size for segment trees problems is usually 100000

// For persistent segment tree with range increment
// and range sum querys
template <class T>
class PersistentSegmentTree {
    class SegmentTree {
        SegmentTree* left_child;
        SegmentTree* right_child;
        
        const int left_idx;
        const int right_idx;
        
        T value = T();
        T delta = T();
        
        bool childrenExist = true;
    public:
        SegmentTree(int left_range, int right_range, T arr[]) :
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
        SegmentTree(SegmentTree* left_child, SegmentTree* right_child, int left_range, int right_range) :
            left_child{left_child},
            right_child{right_child},
            left_idx{left_range},
            right_idx{right_range}, {
            
            // Update the value of the current node
            value = left_child->getVal() + right_child->getVal();
        }
        SegmentTree(SegmentTree* left_child, SegmentTree* right_child, int left_range, int right_range, T val, T del = T()) :
            left_child{left_child},
            right_child{right_child},
            left_idx{left_range},
            right_idx{right_range}, 
            value{val},
            delta{del} {
            // NOTHING TO SEE HERE
        }
        
        SegmentTree(SegmentTree* tree, bool childrenExist = true) : 
            childrenExist{childrenExist}{
                
            // Copy all of the values 
            left_child = tree->left_child;
            right_child = tree->right_child;
            
            left_idx = tree->left_idx;
            right_idx = tree->right_idx;
            
            value = tree->value;
            deltas = tree->value;
        }
        
        // Update current node and push deltas down
        void pushLazy(T val = T()) {
            SegmentTree* st = new SegmentTree(this, false);
            st.updateLazy(val);
            
            return st;
        }
        
        // Push delta to current node
        void updateLazy(T val = T()) {
            delta += val;
            value += (right_idx - left_idx + 1) * delta;
        }
        
        SegmentTree* updateRange(int left_range, int right_range, T val) {
            // Let I = [left_idx, right_idx)
    		// Let I_q = [left_range, right_range)
    		// Let I_left = [left->left_idx, left->right_idx)
    		// Let I_right = [right->left_idx, right->right_idx)
    		// If I \subseteq I_q
    		// printf("updating: [left_idx: %d, right_idx: %d] on [%d, %d]", left_idx, right_idx, left_range, right_range);
    		if (right_range <= left_idx || right_idx <= left_range) {
                // This one is right
    			return this;
    		}
    		else if (left_range <= left_idx  && right_idx <= right_range) {
                // This one needs some lazy magic 
    			// Lazy delta
    			return pushLazy(val);
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
            // So (min(right_range, right_idx) - max(left_idx, left_range) + 1) is always
            // positive
    		int newDelta = (min(right_range, right_idx) - max(left_idx, left_range) + 1) * val;
    		
            
            // Make a new node if we did get here
            return new SegmentTree(
                left->updateRange(left_range, right_range, val), // Update the left and right
                right->updateRange(left_range, right_range, val), // and then links to the other segments
                left_idx, right_idx, // Range 
                value + newDelta, // Current value
                delta // Lazy delta
            ); 
        }
        
        // Gets the value for the range [left_range, right_range]
    	T getVal(int left_range, int right_range) {
    		// printf("getval([%d, %d] : [%d, %d]) = %d\n", left_idx, right_idx, left_range, right_range, value);
            // If it's outside
    		if (right_range < left_idx || right_idx < left_range){
    			return T();
    		}
            
            // Honestly I have no idea what this code does anymore
    		// Push lazy deltas into children
    		if (delta){
                if (childrenExist) {
                    if (left) {
                        left->updateLazy(delta);
                    }
                    if (right) {
                        right->updateLazy(delta);
                    }
                }
                // If both are kill
                else {
                    if (left) {
                        left = new SegmentTree(left, false);
                        left->updateLazy(delta);
                    }
                    if (right) {
                        right = new SegmentTree(right, false);
                        right->updateLazy(delta);
                    }
                }
    			delta = T();
    		}
            
            // If it's fully contained
    		if (left_range <= left_idx && right_idx <= right_range) {
    			return value;
    		}
    		
    		return left->getVal(left_range, right_range) + right->getVal(left_range, right_range);	
    	}
    };
    
    vector<SegmentTree*> treeArr;
public:
    
    PersistentSegmentTree(int size, T arr[]) {
        treeArr.push_back(make_shared(new SegmentTree(0, size-1, arr)));
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
