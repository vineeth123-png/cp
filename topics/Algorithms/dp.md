# Dynamic Programming
- [Dynamic Programming](#dynamic-programming)
  - [Introduction](#introduction)
  - [Resources](#resources)
    - [A different way to think of subproblems](#a-different-way-to-think-of-subproblems)

## Introduction
Dynamic Programming (DP) is a method for solving complex problems by breaking them down into simpler subproblems. It is applicable when the problem can be divided into overlapping subproblems which can be solved independently. DP is often used in optimization problems where the goal is to find the best solution among many possible solutions.

## Resources
- [Introduction to Dynamic Programming by GeeksforGeeks](https://www.geeksforgeeks.org/dynamic-programming/)
- [Dynamic Programming Tutorial by TopCoder](https://www.topcoder.com/thrive/articles/Dynamic%20Programming:%20From%20Novice%20to%20Advanced)
- [Dynamic Programming in Wikipedia](https://en.wikipedia.org/wiki/Dynamic_programming)
- [0-1 Knapsack DP](https://leetcode.com/discuss/study-guide/1152328/01-Knapsack-Problem-and-Dynamic-Programming#:~:text=Statement%3A%20Given%20a%20set%20of,equal%20to%20the%20knapsack's%20capacity.)



### A different way to think of subproblems
Refer to this [LC Question](https://leetcode.com/problems/map-of-highest-peak/editorial/?envType=daily-question&envId=2025-01-22) - This can be easily solved using bfs, but look at how this problem is solved using dp. How he evaluated different minimum for different subproblems is good.