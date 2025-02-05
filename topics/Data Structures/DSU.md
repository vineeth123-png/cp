# Disjoint Set Union (DSU)
- [Disjoint Set Union (DSU)](#disjoint-set-union-dsu)
  - [Introduction](#introduction)
  - [Resources](#resources)

## Introduction
DSU (Disjoint Set Union), also known as Union-Find, is not exclusively a graph algorithm, but it's often used in graph-related problems. It's a data structure that helps manage and merge disjoint sets efficiently. DSU supports two main operations:

1. Find: Determine which set a particular element belongs to. This helps in checking if two elements are in the same set.
2. Union: Merge two sets into a single set.
In graph theory, DSU is commonly used in:

Kruskal's Algorithm: For finding the Minimum Spanning Tree (MST) of a graph by efficiently managing edge connectivity.  
Cycle Detection: To check whether adding an edge between two vertices would form a cycle.  
Connected Components: To identify and count connected components in a graph.  
So while DSU itself isn't a graph algorithm, it plays a crucial role as a supporting data structure in many graph algorithms.

## Resources
A good introduction and implementation articles in [leetcode](https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3881/).  
The above link has a list of articles, that explain Quick Union, Quick Find, and optimizations in DSU using Path Compression. Clear and concise explanations.