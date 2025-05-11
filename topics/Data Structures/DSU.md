# Disjoint Set Union (DSU)
- [Disjoint Set Union (DSU)](#disjoint-set-union-dsu)
  - [Introduction](#introduction)
  - [Resources](#resources)

## Introduction
DSU (Disjoint Set Union), also known as Union-Find, is not exclusively a graph algorithm, but it's often used in graph-related problems. It's a data structure that helps manage and merge disjoint sets efficiently. The main idea of a “disjoint set” is to have all connected vertices have the same parent node or root node, whether directly or indirectly connected. To check if two vertices are connected, we only need to check if they have the same root node.

DSU supports two main operations:

1. Find: Determine which set a particular element belongs to. This helps in checking if two elements are in the same set.
2. Union: Merge two sets into a single set.
In graph theory, DSU is commonly used in:

Kruskal's Algorithm: For finding the Minimum Spanning Tree (MST) of a graph by efficiently managing edge connectivity.  
Cycle Detection: To check whether adding an edge between two vertices would form a cycle.  
Connected Components: To identify and count connected components in a graph.  
So while DSU itself isn't a graph algorithm, it plays a crucial role as a supporting data structure in many graph algorithms.

## Different ways to implement DSU

1. Quick Find Implementation - find() runs in O(1) time, but union takes O(N) time.
2. Quick Union Implementation - find() takes O(N) time, and union takes O(N) time, as union method calls find() twice. But, Quick Union is more efficient than Quick find!
3. Union by Rank Implementation - We've a rank array that stores the depth of a node. This way during union(), you can choose parent and child based on their ranks, and eliminate creating skewed trees. Here, as height will almost be log(N)+1, find operation and union operations take O(logN) time.
4. When we use Union by rank implementation and find parents using path compression, find and union operations take O(1) on average (References - Inverse Ackermann function, [link](https://www.cs.tau.ac.il/~michas/ufind.pdf))

## Resources
A good introduction and implementation articles in [leetcode](https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3881/).  
The above link has a list of articles, that explain Quick Union, Quick Find, and optimizations in DSU using Path Compression. Clear and concise explanations.

## Code
```
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
	// Some ranks may become obsolete so they are not updated
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

// Test Case
int main() {
    // for displaying booleans as literal strings, instead of 0 and 1
    cout << boolalpha;
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);
    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true

    return 0;
}
```