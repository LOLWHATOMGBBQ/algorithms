#pragma once
#include <vector>
#include <algorithm>

template<class Type, class Id>
struct Node {
    // Values
    Id id;
    Type val;
    int dist=999999;
    std::vector<Node*> children;
    
    
    // Functions
    Node(Type val, Id id) : val{val}, id{id} {};
    
    void addEdge(const Node* dest) {
        children.emplace_back(dest);
    }
    
    void removeEdge(const Node* dest) {
        children.erase(find(children.begin(), children.end(), dest));
    }
    
};
