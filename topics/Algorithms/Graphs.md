# Graph Algorithms

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


## Disjoint Set Union (DSU)
A good introduction and implementation articles in [leetcode](https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3881/).  
The above link has a list of articles, that explain Quick Union, Quick Find, and optimizations in DSU using Path Compression. Clear and concise explanations.