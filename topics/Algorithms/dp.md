# Dynamic Programming

### Those who forget the past are condemned to repeat it...

## TOC
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
- [Striver's DP Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY)



### A different way to think of subproblems
Refer to this [LC Question](https://leetcode.com/problems/map-of-highest-peak/editorial/?envType=daily-question&envId=2025-01-22) - This can be easily solved using bfs, but look at how this problem is solved using dp. How he evaluated different minimum for different subproblems is good.

## DP Patterns
- [Min Path sum](https://leetcode.com/problems/minimum-path-sum/description/)
- [House Robber]()
- [Subset sum equals target](https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15)


### Important notes
- For questions which you've already solved or whose initial dp implementation is trivial, think of improving its space complexity based on different patterns you see.
Example questions - 
. [Min. path sum](https://leetcode.com/problems/minimum-path-sum/description/) - Trivial DP's space complexity - O(m*n), you can optimize and bring the space complexity down to O(min(m, n));
. [House Robber](https://leetcode.com/problems/house-robber/description/) - Trivial DP's space complexity is O(n), you can optimize and bring down the space complexity down to O(1);
. [Subset Sum Equals Target](https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15) - Trivial dp's space complexity is O(n*target), you can bring it down to O(target)

. [LCS](https://www.youtube.com/watch?v=NPZn9jBrX8U) - Checkout space optimized approach

## Articles worth checking
- [LC Article on buy and sell stock series](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/75924/most-consistent-ways-of-dealing-with-the-series-of-stock-problems/)