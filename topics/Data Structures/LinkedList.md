# Linked List
- [Linked List](#linked-list)
  - [Introduction](#introduction)
  - [Types of Linked Lists](#types-of-linked-lists)
  - [Common Operations](#common-operations)
  - [Applications](#applications)
  - [Resources](#resources)

## Introduction
A Linked List is a linear data structure where elements are stored in nodes, and each node points to the next node in the sequence. Unlike arrays, linked lists do not require contiguous memory and allow efficient insertions and deletions.

Linked lists are fundamental in computer science and are frequently asked about in software interviews. They are used to implement other data structures and solve various algorithmic problems.

## Types of Linked Lists
1. **Singly Linked List**: Each node points to the next node.
2. **Doubly Linked List**: Each node points to both the next and previous nodes.
3. **Circular Linked List**: The last node points back to the first node, forming a circle.

## Common Operations
- Insertion (at head, tail, or middle)
- Deletion (by value or position)
- Traversal (iterative and recursive)
- Reversal of a linked list
- Finding the middle node
- Detecting cycles (Floyd’s Tortoise and Hare algorithm)
- Merging two sorted linked lists
- Removing duplicates

## Applications
- Implementing stacks and queues
- Memory management (free lists)
- Adjacency lists for graphs
- Undo functionality in editors

## Resources
- [GeeksforGeeks: Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [LeetCode Linked List Problems](https://leetcode.com/tag/linked-list/)
- [InterviewBit: Linked List Interview Questions](https://www.interviewbit.com/linked-list-interview-questions/)

## Code Example
```cpp
// Singly Linked List Node definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
```


## Tortoise and Hare Algorithm - Floyd's Cycle Algorithm

### Resources & Good Questions
[cp-algorithms](https://cp-algorithms.com/others/tortoise_and_hare.html) - Has algorithm.  
[Find the intersection point of Y LL](https://leetcode.com/problems/intersection-of-two-linked-lists/description/) - [explanation](https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/6624269/master-linked-list-intersection-unlock-the-two-pointer-reset-trick-to-detect-overlap/)  
[Remove Nth node from the back of the LL](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)  
[Sort a LL](https://leetcode.com/problems/sort-list/)  
[Rotate List](https://leetcode.com/problems/rotate-list/description/) - [Best Implementation](https://leetcode.com/problems/rotate-list/description/)  
[Reverse LL in group of given size K](https://leetcode.com/problems/reverse-nodes-in-k-group/description/)  
[Flattening of LL](https://takeuforward.org/data-structure/flattening-a-linked-list/) or [Flatten a multilevel doubly linked list](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/)

#### Striver's Explanation
- [Detect a loop in LL](https://youtu.be/wiOo4DC5GGA) - Has Proof on why cycle algorithm runs in O(n) time.
- [Find the starting point of the loop](https://youtu.be/2Kd0KKmmHFc) - Has proof on why find the starting point algo works.
- [Check loop's length in LL](https://youtu.be/I4g1qbkTPus)

Striver's explanations are good, explained proofs in a simple way.

## Main Points
- When we solve linkedlist problems, we've to think how we can use slow & fast pointers (Tortoise-Hare) or how two pointers (remove Nth node from back of LL) can be used to solve the problem. We can also use recursion to solve problems here.

