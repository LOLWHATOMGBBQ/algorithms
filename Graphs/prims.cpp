#include <bits/stdc++.h>


std::vector<pair<int, pair<int,int>> v; prims(std::vector<pair<int,pair<int,int>>>& edges, std::vector<nodes> v) {
    // Sorts the edges in place
    sort(edges.begin(), edges.end());
    
    
    std::vector<bool> vis(v.size(), false);
    
    std::vector<pair<int,pair<int, int>> mst;
    for (auto edge : edges) {
        int souce = edge.first;
        int dest = edge.second.first;
        int weight = edge.second.second;
        
        if (!vis[source] || !vis[dest]) {
            vis[source] = true;
            vis[dest] = true;
            
            mst.emplace_back(edge);
        }
    }
    
    return mst;
}
