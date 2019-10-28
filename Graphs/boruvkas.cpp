#include <bits/stdc++.h>


std::vector<pair<int, pair<int,int>> borkuvas(std::unordered_map<int, pair<int,int>>& edges, std::vector<int> nodes) { 
    
    std::vector<pair<int,pair<int, int>> mst;
    for (auto vertex : nodes) {
    	std::vector<bool> vis(v.size(), false);

    std::vector<bool> vis(v.size(), false);
	int best_dest = -1, best_weight = INT_MAX;
	for (auto edge : edges[vertex]) {
        	int dest = edge.first;
        	int weight = edge.second;
		
		if (weight < best_weight) {
			best_dest = dest;
			best_weight = weight;
		}
	}
        
        if (!vis[vertex] || !vis[best_dest]) {
            vis[vertex] = true;
            vis[best_dest] = true;
            
            mst.emplace_back(edge);
        }
    }
    
    return mst;
}
