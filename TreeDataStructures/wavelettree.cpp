#include <bits/stdc++.h>


class WaveletTree {


public:
    int low, high, median;
    WaveletTree* left_tree, right_tree;
    std::vector<int> new_arr;
    std::vector<pair<int,int>> mapped_index;
    
    // Default constructor
    // Array is in range [x, y]
    // @param from: represents the begining of the numbers in the array
    // @param to: represents the end of the numbers in the array
    // the variables x, y represent the indicies that we are trying to
    // represent
    WaveletTree(std::vector<int> arr)
    {
        low = min(arr.begin(), arr.end());
        high = max(arr.begin(), arr.end());
        mid = (low + high)/2;
        
        int lidx=-1, ridx=-1;
        std::vector<int> left_arr, right_arr;
        for (int val : arr) {
            if (val <= mid) {
                left_arr.emplace_back(val);
                ++lidx;
            }
            else {
                right_arr.emplace_back(val);
                ++ridx;
            }
            mapped_index.emplace_back(make_pair(lidx, ridx));
        }
        if (!left_arr.empty() && low != high) {
            left_tree = new WaveletTree(left_arr);
        }
        if (!right_arr.empty() && low != high) {
            right_tree = new WaveletTree(right_arr);
        }
    }
    
    // Appends the element to the end and updates the mapped indicies of this 
    // magic
    int append(int val) {
        new_arr.emplace_back(val);
        if (val <= median && left_tree) {
            // Get the mapped index of this new thingy l m a o
            mappend_index.emplace_back(left_tree->append(val));
        }
        else if (val > median && right_tree){
            mapped_index.emplace_back(right_tree.append(val));
        }
        else if (val <= median){
            left_tree = new WaveletTree()
        }
        
        return new_arr.size() - 1; // Returns the current index? Or should 
        // i return the bottom most index idk no clue lmao
    }
    
    // Returns the k-th smallest element in the interval [left_idx, right_idx]
    int quartile(int k, int left_idx, int right_idx) {
        if (right_idx - left_idx < k) {
            // Things are broken!!
            return 999999999;
        }
        
        pair<int,int> mapped_left = mapped_index[left_idx];
        pair<int,int> mapped_right = mapped_index[right_idx];
        
        if (mapped_right.first - mapped_left.first < k) {
            int new_k = k - (mapped_right.first - mapped_left.first);
            
            return right_tree->quartile(new_k, mapped_left.second, mapped_right.second);
            // This means we have to go to the right tree
        }
        else if (low == high && k < new_arr.size()){
            // This is if we reached the bottom
            return new_arr[k];
        }
        else {
            // Then we query for the value in the left subtree
            return left_tree->quartile(k, mapped_left.first, mapped_right.first);
        }
    }
};



int main() {
    int arr [] = {2, 1, 7, 6, 4, 8, 9, 4, 3, 5, 2, 7};
    int n = 11;
    
    WaveletTree wtree = WaveletTree(arr, arr+n);
}
