# Backtracking

Backtracking is a general algorithmic technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, and removing solutions that fail to satisfy the constraints of the problem at any point (i.e., backtrack).

## Leetcode definition
Backtracking is an algorithm for finding all solutions by exploring all potential candidates. If the solution candidate turns out to be not a solution (or at least not the last one), the backtracking algorithm discards it by making some changes on the previous step, i.e. backtracks and then tries again.

## Key Concepts

- **Recursive Exploration:** Backtracking explores all possible options for a solution by recursively making choices.
- **Pruning:** If a partial solution cannot possibly lead to a valid solution, it is abandoned (pruned).
- **State Restoration:** After exploring a choice, the algorithm undoes the choice (backtracks) to explore other possibilities.

## Typical Use Cases

- **Combinatorial Problems:** Generating permutations, combinations, and subsets.
- **Constraint Satisfaction:** Solving puzzles like Sudoku, N-Queens, and crosswords.
- **Path Finding:** Maze solving, finding paths in graphs.

## Example: N-Queens Problem

Place N queens on an N×N chessboard so that no two queens threaten each other.

```python
def solve_n_queens(n):
    def is_safe(row, col, diagonals, anti_diagonals, cols):
        return col not in cols and (row - col) not in diagonals and (row + col) not in anti_diagonals

    def backtrack(row, diagonals, anti_diagonals, cols, state):
        if row == n:
            result.append(state[:])
            return
        for col in range(n):
            if is_safe(row, col, diagonals, anti_diagonals, cols):
                cols.add(col)
                diagonals.add(row - col)
                anti_diagonals.add(row + col)
                state.append(col)
                backtrack(row + 1, diagonals, anti_diagonals, cols, state)
                # Backtrack
                cols.remove(col)
                diagonals.remove(row - col)
                anti_diagonals.remove(row + col)
                state.pop()

    result = []
    backtrack(0, set(), set(), set(), [])
    return result
```

## General Backtracking Template

```python
def backtrack(candidate):
    if is_solution(candidate):
        output(candidate)
        return
    for next_candidate in generate_candidates(candidate):
        if is_valid(next_candidate):
            backtrack(next_candidate)
```

## Pros and Cons

**Pros:**
- Simple to implement for many problems.
- Guarantees finding all solutions.

**Cons:**
- Can be slow for large search spaces.
- May require optimization (e.g., pruning, memoization).

## Further Reading

- [Backtracking - GeeksforGeeks](https://www.geeksforgeeks.org/backtracking-algorithms/)
- [Backtracking - LeetCode Explore](https://leetcode.com/explore/learn/card/recursion-ii/472/backtracking/)
- [LC Discuss on various implementations](https://leetcode.com/problems/combination-sum/solutions/16502/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partitioning/) - has skeleton for various backtracking algos.
