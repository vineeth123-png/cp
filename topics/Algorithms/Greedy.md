# Greedy Algorithms

## Table of Contents
1. [Introduction](#introduction)
2. [Key Concepts](#key-concepts)
3. [Advantages and Disadvantages](#advantages-and-disadvantages)
4. [Common Problems Solved Using Greedy Algorithms](#common-problems-solved-using-greedy-algorithms)
5. [Implementation Strategies](#implementation-strategies)
6. [Examples](#examples)
7. [Practice Problems](#practice-problems)
8. [References](#references)


## Introduction
Given a problem which has some constraints and where we have to minimize cost, all the solutions which satisfy the constraints are called feasible solutions. The set of feasible solutions which costs the minimum are called optimal solutions. Generally, there would be a single optimal solution. Also, a problem which consists of minimizing or maximizing is called an optimization problem.

Some strategies used to solve optimization problems are - 
1. Greedy method
2. Dynamic Programming
3. Branch & Bound

## How Greedy works..
A problem would be solved in stages. Each time, we'd pickup feasible possibilities, which would eventually lead us to the optimal solution. While picking up feasible possibilities, we'd always take a greedy approach, which would be the locally optimal. But in this approach, optimal solution is the one, which comes from picking up the locally optimal one each time. This approach assumes that choosing a local optimum at each stage will lead to the global optimum.

## Standard Problems
1. Knapsack Problem. (Objects are divisible, we can take parts of the objects in the knapsack)
2. Job Sequencing with deadlines - [Link](https://leetcode.com/discuss/post/1065228/job-sequencing-problem-by-avneetsng-l0qw/)
3. Optimal merge pattern
4. Huffman Coding
5. Prim & Kruskal's Algorithms
6. Dijkstra's Algorithm.
7. Dutch National Flag (DNF) Algorithm.
8. Kadane's Algorithm
9. Moore's Majority voting algorithm.


### Credits
Content taken from Abdul Bari's Algorithms [Playlist](https://www.youtube.com/watch?v=ARvQcqJ_-NY&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=39)