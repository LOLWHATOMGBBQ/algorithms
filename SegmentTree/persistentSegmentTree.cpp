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
        SegmentTree(int left_idx, int right_idx, T values[]) :
            left_child{left_idx >= right_idx ? nullptr : new SegmentTree(left_idx, (right_idx + left_idx)/2, values)},
    		right_child{left_idx >= right_idx ? nullptr : new SegmentTree((right_idx + left_idx)/2 + 1, right_idx, values)},
    		
    		left_idx{left_idx},
    		right_idx{right_idx} {
    		
    		// Update the tree
    		if (left_idx < right_idx) {
    			// printf("[%d, %d] made [%d, %d] = %d and [%d %d] = %d\n", left_idx, right_idx, left_idx, mid, getVal(left_idx, mid), mid+1, right_idx, getVal(mid+1, right_idx));
    			// Update current value
    			value = left_child->getVal(left_idx, (right_idx + left_idx)/2) +
    					right_child->getVal((right_idx + left_idx)/2+1, right_idx);
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
            right_idx{right_range} {
            
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
            left_child{tree->left_child},
            right_child{tree->right_child},
            left_idx{tree->left_idx},
            right_idx{tree->right_idx},
            value{tree->value},
            delta{tree->delta},
            childrenExist{childrenExist}{
            // NOTHING TO SEE HERE
        }
        
        // Update current node and push deltas down
        SegmentTree* pushLazy(T val = T()) {
            SegmentTree* st = new SegmentTree(this, false);
            st->updateLazy(val);
            
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
                left_child->updateRange(left_range, right_range, val), // Update the left and right
                right_child->updateRange(left_range, right_range, val), // and then links to the other segments
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
                    if (left_child) {
                        left_child->updateLazy(delta);
                    }
                    if (right_child) {
                        right_child->updateLazy(delta);
                    }
                }
                // If both are kill
                else {
                    if (left_child) {
                        left_child = new SegmentTree(left_child, false);
                        left_child->updateLazy(delta);
                    }
                    if (right_child) {
                        right_child = new SegmentTree(right_child, false);
                        right_child->updateLazy(delta);
                    }
                }
    			delta = T();
    		}
            
            // If it's fully contained
    		if (left_range <= left_idx && right_idx <= right_range) {
    			return value;
    		}
    		
    		return left_child->getVal(left_range, right_range) + right_child->getVal(left_range, right_range);	
    	}
        
        void printTree() {
    		printf("eval([%d, %d]) = %d\n", left_idx, right_idx, value);
    		if (left_child)
    			left_child->printTree();
    		if (right_child)
    			right_child->printTree();
    	}
    };
    
    vector<SegmentTree*> treeArr;
    int cur_idx = 0;
public:
    
    PersistentSegmentTree(int size, T arr[]) {
        treeArr.push_back(new SegmentTree(0, size-1, arr));
    }
    
    T query(int left_idx, int right_idx) {
        return treeArr[cur_idx]->getVal(left_idx, right_idx);
    }
    
    T query(int left_idx, int right_idx, int k) {
        return treeArr[k-1]->getVal(left_idx, right_idx);
    }
    
    void updateRange(int left_idx, int right_idx, T val) {
        treeArr.push_back(treeArr[cur_idx]->updateRange(left_idx, right_idx, val));
        ++cur_idx;
    }
    
    void printTree() {
        for (auto t : treeArr) {
            t->printTree();
            printf("\n");
        }
    }
};

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	
	PersistentSegmentTree<int>* stree = new PersistentSegmentTree<int>(8, a);
	
	stree->printTree();
	cout << stree->query(3, 6) << endl;
    
	stree->updateRange(2, 5, 10);
	cout << stree->query(3, 6) << endl;
    stree->updateRange(2, 5, -10);
    
    cout << stree->query(3, 6) << endl;
    cout << stree->query(3, 6, 1) << endl;
	stree->printTree();
	
	delete stree;
}
