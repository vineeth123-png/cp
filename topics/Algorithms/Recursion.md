# Recursion

Recursion is a method of solving problems where a function calls itself as a subroutine. This allows the function to be repeated several times, as it can call itself during its execution.

## Useful Links

- [Recursion (GeeksforGeeks)](https://www.geeksforgeeks.org/recursion/)
- [Recursion Patterns (LeetCode)](https://leetcode.com/discuss/general-discussion/460599/blind-75-leetcode-questions-classified)

### Good Questions & Classic Examples of Recursion

-- [https://leetcode.com/problems/count-good-numbers/description/](https://leetcode.com/problems/count-good-numbers/description/)
- GCD
- Binary Search
- Sorting algos, like Mergesort & quicksort...
- modpow(a, x)
- reverse a stack using recursion
- sort a stack using recursion

## Recursion
Recursion is a powerful problem-solving technique and a fundamental concept in computer science. At its core, recursion occurs when a function (or definition) refers to itself, either directly or indirectly. While it might sound circular or confusing at first, the recursive approach often simplifies complex problems by breaking them down into smaller, more manageable pieces.

## 🔍 Core Steps of Divide and Conquer
### Divide
Split the original problem into smaller, simpler subproblems (usually of the same type).
### Conquer
Solve each subproblem recursively. If the subproblem is small enough, solve it directly (base case).
### Combine
Merge the solutions of the subproblems to get the solution to the original problem.

## ✅ When to Use Divide and Conquer
- When the problem can naturally be divided into similar subproblems
- When merging sub-results is feasible
- When recursion simplifies logic


## ❓ Do subproblems overlap in Divide and Conquer?
Short Answer:
No, in traditional Divide and Conquer, subproblems do not overlap — each subproblem is independent and solved once.

### 🔍 Detailed Explanation
Divide and Conquer algorithms:
Break the problem into non-overlapping subproblems.
Solve each subproblem independently (usually via recursion).
Combine results to solve the larger problem.

### ✅ Example: Merge Sort
Array is split into two disjoint halves.
Each half is sorted separately.
Sorted halves are merged.
No overlapping — each element is part of exactly one subproblem at each level.

### 🔄 What about overlapping subproblems?
That concept belongs to a different paradigm:

### ➤ Dynamic Programming (DP)
In DP, subproblems do overlap.
Same subproblems are solved multiple times, unless memoized or tabulated.
Used when recursion leads to recomputing the same results many times.
✅ Example: Fibonacci Sequence (Naive Recursion)