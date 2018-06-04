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
// The below is not my code
class Node {
    int s, my_s, on, id;
    boolean flip, my_flip;
    Node l, r, p;

    Node(int c, int i) : s{c}, my_s{c}, id{i}{
    	on = 0;
    	l = r = p = null;
    	flip = my_flip = false;
    }

    boolean isroot() {
	       return p==null || (p.l != this && p.r != this);
    }

    /* If this node is flipped, we unflip it, and push the change
       down the tree, so that it represents the same thing. */
    void normalize() {
    	if (flip) {
    	    flip = false;
    	    on = s-on;
    	    my_flip = !my_flip;
    	    if (l != null) l.flip = !l.flip;
    	    if (r != null) r.flip = !r.flip;
    	}
    }

    /* The tree structure has changed in the vicinity of this node
       (for example, if this node is linked to a different left
       child in a rotation).  This function fixes up the data fields
       in the node to maintain invariants. */
    void update() {
    	s = my_s;
    	on = (my_flip)?my_s:0;
    	if (l != null) {
    	    s += l.s;
    	    if (l.flip) on += l.s-l.on; else on += l.on;
    	}
    	if (r != null) {
    	    s += r.s;
    	    if (r.flip) on += r.s-r.on; else on += r.on;
    	}
    }
}

class LinkCutTree {
public:
    static void rotR (Node p) {
        Node q = p.p;
        Node r = q.p;
        q.normalize();
        p.normalize();
        if ((q.l=p.r) != null) q.l.p = q;
        p.r = q;
        q.p = p;
        if ((p.p=r) != null) {
            if (r.l == q) r.l = p;
            else if (r.r == q) r.r = p;
        }
        q.update();
    }

    static void rotL (Node p) {
        Node q = p.p;
        Node r = q.p;
        q.normalize();
        p.normalize();
        if ((q.r=p.l) != null) q.r.p = q;
        p.l = q;
        q.p = p;
        if ((p.p=r) != null) {
            if (r.l == q) r.l = p;
            else if (r.r == q) r.r = p;
        }
        q.update();
    }

    static void splay(Node p) {
        while (!p.isroot()) {
            Node q = p.p;
            if (q.isroot()) {
                if (q.l == p) 
                    rotR(p); 
                else 
                rotL(p);
            } 
            else {
                Node r = q.p;
                if (r.l == q) {
                    if (q.l == p) {
                        rotR(q); 
                    }
                    else {
                        rotL(p); 
                    }
                    rotR(p);
                } else {
                    if (q.r == p) {
                        rotL(q);     
                    }
                    else {
                        rotR(p); 
                    }
                    rotL(p);
                }
            }
        }
        p.normalize(); // only useful if p was already a root.
        p.update();    // only useful if p was not already a root
    }

    /* This makes node q the root of the virtual tree, and also q is the 
       leftmost node in its splay tree */
    static void expose(Node q) {
        Node r = null;
        for (Node p=q; p != null; p=p.p) {
            splay(p);
            p.l = r;
            p.update();
            r = p;
        };
        splay(q);
    }

    /* assuming p and q are nodes in different trees and  
       that p is a root of its tree, this links p to q */ 
    static void link(Node p, Node q) throws MyException {
        expose(p);
        if (p.r != null)
            throw new MyException("non-root link"); 
        p.p = q;
    }

    /* Toggle all the edges on the path from p to the root
       return the count after - count before */
    static int toggle(Node p) {
        expose(p);
        int before = p.on;
        p.flip = !p.flip;
        p.normalize();
        int after = p.on;
        return after - before;
    }

    /* this returns the id of the node that is the root of the tree containing p */
    static int rootid(Node p) {
        expose(p);
        while(p.r != null) 
            p = p.r;
        splay(p);
        return p.id;
    }
};
