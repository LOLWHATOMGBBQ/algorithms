#include <bits/stdc++.h>


class WaveletTree {


public:
    int low, high, median;
    WaveletTree* left_tree, right_tree;
    std::vector<int> new_arr;
    std::vector<int> mapped_index;
    
    // Default constructor
    // Array is in range [x, y]
    // @param from: represents the begining of the numbers in the array
    // @param to: represents the end of the numbers in the array
    // the variables x, y represent the indicies that we are trying to
    // represent
    WaveletTree(int* arr, int pivot)
    {
        for
    }
    WaveletTree(int val) {
        
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
};



int main() {
    int arr [] = {2, 1, 7, 6, 4, 8, 9, 4, 3, 5, 2, 7};
    int n = 11;
    
    WaveletTree wtree = WaveletTree(arr, arr+n);
}
