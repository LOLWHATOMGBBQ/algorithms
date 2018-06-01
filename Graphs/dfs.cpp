#include <bits/stdc++.h>
#include "node.h"

// Finds the path to get to the da way
std::vector<Node*> dfs(Node* cur, Node* dest) {
    if (cur == dest) {
        return std::vector<int>(1, cur);
    }
    for (auto child : cur->children) {
        std::vector<int> v = dfs(child);
        if (v.size() != 0) {
            v.push_back(cur);
            return v;
        }
    }
}
