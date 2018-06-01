#include <bits/stdc++.h>
#include "node.h"


// Returns the length of the shortest path
int bfs(Node* source, Node* dest) {
    if (source == dest)
        return 0;
        
    std::queue<Node*> q;
    
    source->dist = 0;
    // Add this to the queue
    q.push_back(source);
    
    while(! q.empty()) {
        Node* cur = q.front();
        q.pop_front();
        
        for (auto child : children) {
            if (child == dest) {
                child->dist = cur->dist+1;
                return child->dist;
            }
            
            if (child->dist == -1) { // if it has not been visited
                child->dist = cur->dist+1;
                q.push_back(child);
            }
        }
    }
}
