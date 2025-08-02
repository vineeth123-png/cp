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

- [cp-algorithms](https://cp-algorithms.com/graph/breadth-first-search.html)
- [Graphs Playlist by Striver](https://www.youtube.com/playlist?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn) - Has great videos, good explanations.
- [USACO Guide](https://usaco.guide/) - covers great resources like CP Handbook, USACO books, cp-algo...

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
Topological sort is a linear ordering of the vertices in a directed acyclic graph (DAG) such that for every directed edge \( u \rightarrow v \), vertex \( u \) comes before \( v \) in the ordering. This is essential for scheduling tasks with dependencies, resolving compilation order, and more.

### When is Topological Sort Possible?

Topological sorting is only possible for DAGs. If the graph contains a cycle, no valid ordering exists.

---

## Algorithms for Topological Sort

There are two main approaches: DFS-based and BFS-based (Kahn's Algorithm).

### 1. DFS-Based Topological Sort

This method uses depth-first search. The key idea is to visit all descendants of a node before the node itself. When a node finishes (all its neighbors are visited), it is added to the ordering.

#### Steps:
1. Mark all nodes as unvisited.
2. For each unvisited node, perform DFS.
3. After visiting all neighbors, add the node to a stack or list.
4. Reverse the stack/list to get the topological order.

#### Pseudocode

```python
def dfs_topological_sort(graph):
    n = len(graph)
    visited = [False] * n
    order = []

    def dfs(u):
        visited[u] = True
        for v in graph[u]:
            if not visited[v]:
                dfs(v)
        order.append(u)

    for u in range(n):
        if not visited[u]:
            dfs(u)
    return order[::-1]  # reverse for correct order
```

#### Notes:
- Detects cycles if a node is visited twice in the same DFS path (using a recursion stack).
- Time complexity: \( O(V + E) \).

---

### 2. BFS-Based Topological Sort (Kahn's Algorithm)

This approach uses in-degree counts and a queue. Nodes with zero in-degree (no dependencies) are processed first.

#### Steps:
1. Compute in-degree for each node.
2. Add all nodes with zero in-degree to a queue.
3. While the queue is not empty:
    - Remove a node, add it to the ordering.
    - Decrease in-degree of its neighbors.
    - If a neighbor's in-degree becomes zero, add it to the queue.
4. If all nodes are processed, the ordering is valid. If not, the graph has a cycle.

#### Pseudocode

```python
from collections import deque

def kahn_topological_sort(graph):
    n = len(graph)
    in_degree = [0] * n
    for u in range(n):
        for v in graph[u]:
            in_degree[v] += 1

    queue = deque([u for u in range(n) if in_degree[u] == 0])
    order = []

    while queue:
        u = queue.popleft()
        order.append(u)
        for v in graph[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                queue.append(v)

    if len(order) == n:
        return order
    else:
        return []  # cycle detected
```

#### Notes:
- Efficient for large graphs.
- Can be used to detect cycles (if not all nodes are processed).
- Time complexity: \( O(V + E) \).

---

## Comparison

| Method      | Approach | Cycle Detection | Output Order | Use Case         |
|-------------|----------|----------------|--------------|------------------|
| DFS         | Recursive| Yes (with stack)| Reverse postorder | When recursion is natural |
| Kahn's (BFS)| Iterative| Yes (by count) | As processed | When explicit dependency tracking is needed |

---

## Applications

- Task scheduling with dependencies
- Build systems (compilation order)
- Resolving package dependencies
- Course prerequisite ordering

---

## Example

Given a graph:
```
0 → 1
0 → 2
1 → 3
2 → 3
```
Possible topological orders: `[0, 2, 1, 3]`, `[0, 1, 2, 3]`

---

Topological sort is a fundamental tool for reasoning about dependencies in directed acyclic graphs, with both DFS and BFS approaches widely used in practice.

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

## Dijkstra's Algorithm

Finds the shortest path from a single source to all other nodes in a graph with non-negative edge weights. Uses a priority queue for efficiency. 

**Apporach/Intuition** - Whenever we calculate distance from source to target nodes, we always makes sure to find distances from the nearest node first in a greedy manner, and then to pickup longer distances as we go. This way, we always end up finding shortest distances, as there are no negative edges in the graph.

### Dijkstra's Algorithm Implementations

#### 1. Using `priority_queue` (heapq in Python)

This is the standard and most efficient way to implement Dijkstra's algorithm. The priority queue always gives the node with the smallest current distance.

```python
import heapq

def dijkstra_priority_queue(graph, source):
    n = len(graph)
    dist = [float('inf')] * n
    dist[source] = 0
    pq = [(0, source)]  # (distance, node)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue  # Already found a better path
        for v, w in graph[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist
```

- `graph` is an adjacency list: `graph[u] = [(v, weight), ...]`
- Time complexity: \(O((V + E) \log V)\)

---

#### 2. Using `set`

A set can also be used to always extract the node with the smallest distance. This is less efficient than a priority queue but sometimes used for educational purposes or in languages with efficient ordered sets.

```python
def dijkstra_set(graph, source):
    import bisect

    n = len(graph)
    dist = [float('inf')] * n
    dist[source] = 0
    s = set()
    s.add((0, source))

    while s:
        d, u = min(s)
        s.remove((d, u))
        for v, w in graph[u]:
            if dist[v] > dist[u] + w:
                if (dist[v], v) in s:
                    s.remove((dist[v], v))
                dist[v] = dist[u] + w
                s.add((dist[v], v))
    return dist
```

- `graph` is an adjacency list: `graph[u] = [(v, weight), ...]`
- Time complexity: \(O(V^2)\) (since `min(s)` is \(O(V)\))

---

**Note:**  
- Both implementations assume 0-based node indexing.
- Use the priority queue version for performance; the set version is mainly for conceptual clarity or when using languages with efficient ordered sets (like C++'s `std::set`).


## Bellman-Ford Algorithm

Handles graphs with negative edge weights and can detect negative cycles. Slower than Dijkstra's but more flexible. This algorithm gives us shortest distances from a source to all the nodes, and also detects if there's a negative loop in the graph, something which dijkstra's algorithm can't do. (If we apply dijkstra's algorithm to a graph which has negative weights, it would fall in an infinite loop)

**Striver's Video on Bellman-Ford** - [Bellman-Ford](https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=41)

## Connected Components

Identifies all connected subgraphs in an undirected graph. Useful for clustering and network analysis.

## Bridges and Articulation Points

- **Bridges**: Edges whose removal increases the number of connected components.
- **Articulation Points**: Nodes whose removal increases the number of connected components.

## Strongly Connected Components (SCC)

In directed graphs, SCCs are maximal sets of nodes where each node is reachable from every other node in the same set. Kosaraju's and Tarjan's algorithms are commonly used.

## Minimum Spanning Tree (MST)

Finds a subset of edges that connects all vertices with the minimum total edge weight. Algorithms: Kruskal's and Prim's.

Given a graph consisting of N nodes and M edges, a spanning tree is a tree which has all the N nodes of the graph, but only N-1 edges connecting all the nodes. All the nodes are reachable from each other, using the N-1 edges.
A spanning tree whose sum of its edges would be the minimum of all the spanning trees possible in a graph is the minimum spanning tree (MST). There can be more than one MST given a graph.

### Prim's Algorithm

### Kruskal's Algorithm

## Bipartite Graphs and Matching

A graph is bipartite if its nodes can be divided into two sets such that no two nodes within the same set are adjacent. Matching algorithms (like Hopcroft-Karp) are used for maximum matching.

## Network Flow

Solves problems involving the flow of resources through a network, such as the maximum flow problem (Ford-Fulkerson, Edmonds-Karp algorithms).

---

## Good Questions
### Word Ladder

The Word Ladder problem involves transforming a start word into an end word by changing one letter at a time, with each intermediate word required to be in a given dictionary. The goal is to find the shortest transformation sequence.

This problem can be modeled as a graph where each word is a node, and an edge exists between two words if they differ by exactly one letter. Breadth-First Search (BFS) is typically used to find the shortest path from the start word to the end word.

#### Example

[127. Word Ladder](https://leetcode.com/problems/word-ladder/)

#### Approach

- Build a graph where each word is connected to all words that differ by one letter.
- Use BFS to find the shortest transformation sequence.

#### Pseudocode

```python
from collections import deque

def word_ladder(beginWord, endWord, wordList):
    wordSet = set(wordList)
    queue = deque([(beginWord, 1)])
    while queue:
        word, steps = queue.popleft()
        if word == endWord:
            return steps
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i+1:]
                if next_word in wordSet:
                    wordSet.remove(next_word)
                    queue.append((next_word, steps + 1))
    return 0
```

#### Key Concepts

- Graph modeling of word transformations
- BFS for shortest path
- Efficient neighbor generation using character replacement
