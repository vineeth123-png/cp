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

## Good Questions
- Jump Game Series - [Link](https://leetcode.com/problems/jump-game/), [Link](https://leetcode.com/problems/jump-game-ii/)
- Gas Station Series - [Link](https://leetcode.com/problems/gas-station/)
- Interval Merging series - [Link](https://leetcode.com/problems/merge-intervals/), [Link](https://leetcode.com/problems/insert-interval/), [Link](https://leetcode.com/problems/non-overlapping-intervals/)
- Mininum number of platforms required - [Link](https://takeuforward.org/data-structure/minimum-number-of-platforms-required-for-a-railway/)

## Harder Questions
- Job Sequencing Series - [Link](https://leetcode.com/problems/maximum-profit-in-job-scheduling/), [Link](https://takeuforward.org/data-structure/job-sequencing-problem/)
- LRU Cache - [Link](https://leetcode.com/problems/lru-cache/)

## Kadane's Algorithm
Kadane's Algorithm is a classic greedy approach used to solve the **Maximum Subarray Sum** problem efficiently. The goal is to find the contiguous subarray within a one-dimensional array of numbers that has the largest sum.

### How Kadane's Algorithm Works
- Initialize two variables: `max_so_far` (the answer) and `max_ending_here` (current subarray sum), both set to the first element.
- Iterate through the array from the second element:
    - For each element, update `max_ending_here` as the maximum of the current element and `max_ending_here + current element`.
    - Update `max_so_far` if `max_ending_here` is greater than `max_so_far`.
- At the end, `max_so_far` contains the maximum subarray sum.

### Nuances and Interview Tips
- **Negative Numbers:** Kadane's algorithm works even if the array contains all negative numbers. In such cases, it returns the largest (least negative) element.
- **Subarray Tracking:** To return the actual subarray, keep track of start and end indices whenever `max_ending_here` is reset.
- **Edge Cases:** Be careful with arrays of length 0 or with all negative numbers.
- **Time Complexity:** Kadane's algorithm runs in O(n) time and O(1) space.
- **Variants:** Sometimes, you may be asked for the minimum subarray sum (just invert the logic), or to solve for circular arrays (handle wrap-around by combining Kadane's with total sum minus minimum subarray sum).
- **Common Mistakes:** Forgetting to reset the subarray start index when `max_ending_here` is set to the current element.

### Pseudocode
```python
def kadane(arr):
        max_so_far = arr[0]
        max_ending_here = arr[0]
        for i in range(1, len(arr)):
                max_ending_here = max(arr[i], max_ending_here + arr[i])
                max_so_far = max(max_so_far, max_ending_here)
        return max_so_far
```

Kadane's algorithm is frequently asked in interviews due to its elegant greedy approach and practical applications in dynamic programming and array manipulation problems.

### Credits
Content taken from Abdul Bari's Algorithms [Playlist](https://www.youtube.com/watch?v=ARvQcqJ_-NY&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=39)