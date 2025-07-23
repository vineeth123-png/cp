# Graphs

## Table of Contents
- [Graph Algorithms](#graph-algorithms)
  - [Resources](#resources)
  - [DFS](#dfs)
  - [BFS](#bfs)
  - [0-1 BFS](#0-1-bfs)
    - [Examples](#examples)
  - [Topological Sort](#topological-sort)
    - [Topological Sort using Kahn's Algorithm](#topological-sort-using-kahns-algorithm)
    - [Examples](#examples-1)
  - [Floyd-Warshall Algorithm](#floyd-warshall-algorithm)
  - [Dijkstra's Algorithm](#dijkstras-algorithm)
  - [Bellman-Ford Algorithm](#bellman-ford-algorithm)
  - [Connected Components](#connected-components)
  - [Bridges and Articulation Points](#bridges-and-articulation-points)
  - [Strongly Connected Components (SCC)](#strongly-connected-components-scc)
  - [Minimum Spanning Tree (MST)](#minimum-spanning-tree-mst)
  - [Bipartite Graphs and Matching](#bipartite-graphs-and-matching)
  - [Network Flow](#network-flow)

## Types of Graphs

Graphs can be classified based on their structure and properties:

- **Directed vs. Undirected Graphs**:  
    - *Directed*: Edges have a direction (from u to v).
    - *Undirected*: Edges have no direction.

- **Weighted vs. Unweighted Graphs**:  
    - *Weighted*: Edges have associated weights or costs.
    - *Unweighted*: All edges are considered equal.

- **Simple Graphs**:  
    No loops (edges from a node to itself) or multiple edges between the same pair of nodes.

- **Multigraphs**:  
    May have multiple edges (parallel edges) between the same pair of nodes.

- **Cyclic vs. Acyclic Graphs**:  
    - *Cyclic*: Contains at least one cycle.
    - *Acyclic*: Contains no cycles (e.g., trees, DAGs).

- **Connected vs. Disconnected Graphs**:  
    - *Connected*: There is a path between every pair of nodes (in undirected graphs).
    - *Disconnected*: Not all nodes are reachable from each other.

- **Complete Graphs**:  
    Every pair of distinct nodes is connected by a unique edge.

- **Bipartite Graphs**:  
    Nodes can be divided into two sets with edges only between sets.

- **Trees**:  
    Connected, acyclic undirected graphs.

- **Directed Acyclic Graphs (DAGs)**:  
    Directed graphs with no cycles.

## Graph Properties

- **Degree**:  
    Number of edges incident to a node (in-degree and out-degree for directed graphs).

- **Path**:  
    Sequence of edges connecting a sequence of nodes.

- **Cycle**:  
    Path that starts and ends at the same node without repeating edges or nodes (except the start/end).

- **Connectivity**:  
    Whether the graph is connected or how strongly nodes are connected.

- **Components**:  
    Maximal connected subgraphs.

- **Planarity**:  
    Can the graph be drawn on a plane without edge crossings?

- **Density**:  
    Ratio of the number of edges to the number of possible edges.

These classifications and properties are fundamental for choosing appropriate algorithms and understanding graph-based problems.

## Degrees, Edges, and Related Theorems

### Degrees

- **Degree of a vertex**: The number of edges incident to a vertex.
    - **In-degree**: Number of incoming edges (for directed graphs).
    - **Out-degree**: Number of outgoing edges (for directed graphs).
- In undirected graphs, the sum of the degrees of all vertices equals twice the number of edges.

### Edges

- **Edge**: A connection between two vertices.
- In a simple undirected graph with \( n \) vertices:
    - Maximum number of edges: \( \frac{n(n-1)}{2} \) (complete graph).
- In a simple directed graph:
    - Maximum number of edges: \( n(n-1) \).

### Key Theorems

- **Handshaking Lemma**:  
    In any undirected graph, the sum of the degrees of all vertices is twice the number of edges:
    \[
    \sum_{v \in V} \deg(v) = 2|E|
    \]
- **Degree Sum Formula (Directed Graphs)**:  
    The sum of all in-degrees equals the sum of all out-degrees, both equal to the number of edges:
    \[
    \sum_{v \in V} \deg^+(v) = \sum_{v \in V} \deg^-(v) = |E|
    \]
- **Parity Theorem**:  
    In any undirected graph, the number of vertices with odd degree is even.

These properties are fundamental for analyzing graph structure and are often used in proofs and algorithm design.

## Resources

[cp-algorithms](https://cp-algorithms.com/graph/breadth-first-search.html)

## DFS

## BFS

## 0-1 BFS

Dijkstra's algorithm works well for finding the shortest path, but some problems have a unique feature: the path costs are either 0 or 1. This is key because any path with only 0-cost edges, no matter how long, will always be better than one that uses even a single 1-cost edge. Therefore, it makes sense to prioritize exploring 0-cost edges first. Only after all 0-cost edges have been explored, should we move on to the 1-cost edges. This insight leads us to a modification of the Breadth-First Search (BFS) algorithm, known as 0-1 BFS.

In 0-1 BFS, we adjust the traditional BFS by using a deque (double-ended queue) instead of a regular queue. The deque allows us to prioritize 0-cost edges more efficiently. Each element of the deque will store the row and column indices of a cell, and we will maintain a minCost grid to track the minimum cost to reach each cell.

As we visit each cell, we evaluate its four neighboring cells. If moving to a neighbor doesn’t require a sign change (i.e., the move is a 0-cost move), we add that neighbor to the front of the deque because we want to explore it immediately. On the other hand, if a sign change is required (making it a 1-cost move), we add the neighbor to the back of the deque, ensuring it gets explored later, after all the 0-cost moves.

For each neighbor we explore, we calculate the cost to reach it and compare it to the current value in the minCost grid. If the calculated cost is lower, we update minCost with the new, cheaper value.

Once the BFS traversal completes and all cells have been processed, the minimum cost to reach the bottom-right corner will be stored in minCost. We return this value as the solution to problems.

### Examples
[1368. Minimum cost to make at least one valid path in a grid](https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18)

## Topological Sort

Topological sorting is an algorithm used in directed graphs to arrange nodes such that for every directed edge from node u to node v, node u comes before v. This is a natural approach when dealing with dependencies, like in project scheduling, task ordering, or handling prerequisites.

### Topological Sort using Kahn's Algorithm

### Examples
[Course Schedule IV](https://leetcode.com/problems/course-schedule-iv/editorial/?envType=daily-question&envId=2025-01-27)

## Floyd-Warshall Algorithm

The Floyd-Warshall algorithm is a dynamic programming technique used to find the shortest paths between all pairs of vertices in a weighted graph (with positive or negative edge weights, but no negative cycles). It works by iteratively improving the path between every pair of nodes, considering each node as an intermediate point.

### Pseudocode

```python
def floyd_warshall(graph):
    n = len(graph)
    dist = [[float('inf')] * n for _ in range(n)]
    for u in range(n):
        for v in range(n):
            if u == v:
                dist[u][v] = 0
            elif graph[u][v]:
                dist[u][v] = graph[u][v]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist
```

### Applications

- All-pairs shortest path
- Detecting negative cycles
- Transitive closure of a directed graph

---

### Dijkstra's Algorithm

Finds the shortest path from a single source to all other nodes in a graph with non-negative edge weights. Uses a priority queue for efficiency.

### Bellman-Ford Algorithm

Handles graphs with negative edge weights and can detect negative cycles. Slower than Dijkstra's but more flexible.

### Connected Components

Identifies all connected subgraphs in an undirected graph. Useful for clustering and network analysis.

### Bridges and Articulation Points

- **Bridges**: Edges whose removal increases the number of connected components.
- **Articulation Points**: Nodes whose removal increases the number of connected components.

### Strongly Connected Components (SCC)

In directed graphs, SCCs are maximal sets of nodes where each node is reachable from every other node in the same set. Kosaraju's and Tarjan's algorithms are commonly used.

### Minimum Spanning Tree (MST)

Finds a subset of edges that connects all vertices with the minimum total edge weight. Algorithms: Kruskal's and Prim's.

### Bipartite Graphs and Matching

A graph is bipartite if its nodes can be divided into two sets such that no two nodes within the same set are adjacent. Matching algorithms (like Hopcroft-Karp) are used for maximum matching.

### Network Flow

Solves problems involving the flow of resources through a network, such as the maximum flow problem (Ford-Fulkerson, Edmonds-Karp algorithms).

---