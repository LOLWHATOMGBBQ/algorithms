#include <bits/stdc++.h>

// Suppose we want to  maintain a forest of rooted trees whose each node has an arbitrary
// number of unordered child nodes.  The data structure has to support the following operations in
// O(log(n)) amortized time:
//      - maketree()  ~ Returns a new vertex in a singleton tree. 
//                      This operation allows us to addelements and later manipulate them.
//      - link(v,w)   ~ Makes vertex v a new child of vertex w, i.e. adds an edge (v, w).  
//                      In order for the representation to remain valid this operation assumes 
//                      that v is the root of its tree and that v and w are nodes of distinct trees.
//      - cut(v)      ~ Deletes the edge between vertex v and its parent, parent(v) where v is not the root.
//      - findroot(v) ~ Returns the root of the tree that vertex v is a node of. This operation is 
//                      interesting because path to root can be very long.  The operation can be used to 
//                      determine if two nodes u and v are connected.
//      - pathagg(v)  ~ Returns an aggregate, such as max/min/sum, of the weights of the edges on the path from
//                      the root of the tree to nodev. It is also possible to augment the datastructure to return
//                      many kinds of statistics about the path.

class LinkCutTree {
public:

};