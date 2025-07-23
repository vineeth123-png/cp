# Tree

## Table of Contents
- [Tree](#tree)
    - [Binary Tree](#binary-tree)
        - [Properties](#properties)
    - [Binary Search Tree (BST)](#binary-search-tree-bst)
    - [Types of Binary Trees](#types-of-binary-trees)
        - [Complete Binary Tree](#complete-binary-tree)
        - [Perfect Binary Tree](#perfect-binary-tree)
        - [Sparse Tree (Degenerate Tree)](#sparse-tree-degenerate-tree)
    - [Summary Table](#summary-table)
    - [Tree Traversals](#tree-traversals)
        - [Inorder Traversal](#inorder-traversal)
        - [Preorder Traversal](#preorder-traversal)
        - [Postorder Traversal](#postorder-traversal)
        - [Level-order Traversal](#level-order-traversal)
    - [Morris Traversal](#morris-traversal)
        - [How Morris Inorder Traversal Works](#how-morris-inorder-traversal-works)
        - [Python Example: Morris Inorder Traversal](#python-example-morris-inorder-traversal)
        - [Advantages and Disadvantages](#advantages-and-disadvantages)
    - [Important Concepts and Good Problems](#important-concepts-and-good-problems)
        - [Morris Traversal](#morris-traversal-1)
        - [Zig Zag Traversal (Spiral Order Traversal)](#zig-zag-traversal-spiral-order-traversal)
        - [Binary Tree Views](#binary-tree-views)
            - [Left View](#left-view)
            - [Right View](#right-view)
            - [Top View](#top-view)
            - [Bottom View](#bottom-view)
            - [Boundary View](#boundary-view)
    - [Lowest Common Ancestor (LCA)](#lowest-common-ancestor-lca)
        - [Applications](#applications)
        - [Approaches](#approaches)
            - [Recursive Approach (Binary Tree)](#1-recursive-approach-binary-tree)
            - [Iterative Approach (Binary Search Tree)](#2-iterative-approach-binary-search-tree)
        - [Key Points](#key-points)
        - [Further Reading](#further-reading)
    - [Preorder, Inorder, and Postorder Traversal in One Traversal](#preorder-inorder-and-postorder-traversal-in-one-traversal)
        - [Approach](#approach)
        - [Python Example](#python-example)
        - [Key Points](#key-points-1)

A **Tree** is a hierarchical data structure consisting of nodes, with a single node designated as the root. Each node can have zero or more child nodes, and there are no cycles. Trees are widely used to represent hierarchical relationships.

## Binary Tree

A **Binary Tree** is a tree data structure where each node has at most two children, referred to as the left child and the right child.

### Properties
- Each node has at most two children.
- The topmost node is called the root.
- Nodes with no children are called leaves.

## Binary Search Tree (BST)

A **Binary Search Tree (BST)** is a type of binary tree where the nodes are arranged in order:
- The left subtree of a node contains only nodes with values less than the node’s value.
- The right subtree contains only nodes with values greater than the node’s value.
- Both left and right subtrees must also be BSTs.

BSTs allow efficient searching, insertion, and deletion operations.

## Types of Binary Trees

### Complete Binary Tree

A **Complete Binary Tree** is a binary tree in which all levels are completely filled except possibly the last, which is filled from left to right.

### Perfect Binary Tree

A **Perfect Binary Tree** is a binary tree in which all internal nodes have exactly two children and all leaf nodes are at the same level.

### Sparse Tree (Degenerate Tree)

A **Sparse Tree** or **Degenerate Tree** is a tree where each parent node has only one child. This structure resembles a linked list, as all nodes are connected in a single line.

---

**Summary Table:**

| Type                | Description                                                      |
|---------------------|------------------------------------------------------------------|
| Binary Tree         | Each node has ≤ 2 children                                       |
| BST                 | Binary tree with ordered nodes                                   |
| Complete Binary Tree| All levels filled except possibly last, filled left to right     |
| Perfect Binary Tree | All internal nodes have 2 children, all leaves at same level     |
| Sparse Tree         | Each node has only one child, resembles a linked list            |


## Tree Traversals

Tree traversal refers to the process of visiting each node in a tree data structure, exactly once, in a specific order. The main types of tree traversals are:

### Inorder Traversal

- Visit the left subtree
- Visit the root node
- Visit the right subtree

In a BST, inorder traversal visits nodes in ascending order.

### Preorder Traversal

- Visit the root node
- Visit the left subtree
- Visit the right subtree

Preorder traversal is useful for copying the tree or creating a prefix expression.

### Postorder Traversal

- Visit the left subtree
- Visit the right subtree
- Visit the root node

Postorder traversal is often used for deleting the tree or evaluating postfix expressions.

### Level-order Traversal

- Visit nodes level by level from top to bottom, left to right

Level-order traversal uses a queue and is also known as Breadth-First Search (BFS).

## Morris Traversal

**Morris Traversal** is a tree traversal algorithm that allows inorder or preorder traversal of a binary tree without using recursion or a stack. It achieves O(1) space complexity by temporarily modifying the tree's structure during traversal and restoring it afterward.

### How Morris Inorder Traversal Works

1. Initialize the current node as the root.
2. While the current node is not null:
        - If the current node has no left child, visit it and move to its right child.
        - If the current node has a left child:
            - Find the rightmost node in the left subtree (predecessor).
            - If the predecessor's right is null, set it to the current node and move to the left child.
            - If the predecessor's right is the current node, revert the change, visit the current node, and move to the right child.

This approach avoids extra space by using the tree's unused right pointers.

### Python Example: Morris Inorder Traversal

```python
class TreeNode:
         def __init__(self, val=0, left=None, right=None):
                    self.val = val
                    self.left = left
                    self.right = right

def morris_inorder_traversal(root):
         result = []
         current = root
         while current:
                    if not current.left:
                                result.append(current.val)
                                current = current.right
                    else:
                                predecessor = current.left
                                while predecessor.right and predecessor.right != current:
                                         predecessor = predecessor.right
                                if not predecessor.right:
                                         predecessor.right = current
                                         current = current.left
                                else:
                                         predecessor.right = None
                                         result.append(current.val)
                                         current = current.right
         return result
```

**Advantages:**  
- O(1) extra space (no stack or recursion)
- Tree structure is restored after traversal

**Disadvantages:**  
- Tree is temporarily modified during traversal
- More complex than standard traversals

Morris traversal is especially useful when memory usage is a concern.

## Important Concepts and Good Problems

### Morris Traversal

Morris Traversal is an efficient way to traverse a binary tree with O(1) extra space by temporarily modifying the tree structure. It is particularly useful for inorder and preorder traversals when minimizing memory usage is important.

### Zig Zag Traversal (Spiral Order Traversal)

**Zig Zag Traversal** (also known as Spiral Order Traversal) visits nodes level by level, but alternates the direction of traversal at each level (left-to-right, then right-to-left, and so on). This can be efficiently implemented using a double-ended queue (`deque`).

#### Python Example: Zig Zag Traversal Using Deque

```python
from collections import deque

def zigzag_level_order(root):
    if not root:
        return []
    result, dq, left_to_right = [], deque([root]), True
    while dq:
        level = []
        for _ in range(len(dq)):
            if left_to_right:
                node = dq.popleft()
                level.append(node.val)
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            else:
                node = dq.pop()
                level.append(node.val)
                if node.right:
                    dq.appendleft(node.right)
                if node.left:
                    dq.appendleft(node.left)
        result.append(level)
        left_to_right = not left_to_right
    return result
```

**Key Points:**
- Uses a deque to efficiently add/remove nodes from both ends.
- Alternates traversal direction at each level.
- Useful for problems requiring level order traversal with alternating directions.

### Binary Tree Views

Binary tree "views" refer to the set of nodes visible when the tree is observed from a particular direction. These views are useful for various tree-based problems and interviews.

#### Left View

The **left view** of a binary tree contains the nodes visible when the tree is viewed from the left side. For each level, the first node encountered from the left is included.

**Key Idea:** Traverse the tree level by level (BFS) or recursively (DFS), and record the first node at each level.

#### Right View

The **right view** of a binary tree contains the nodes visible when the tree is viewed from the right side. For each level, the last node encountered from the left (or the first from the right) is included.

**Key Idea:** Similar to left view, but record the last node at each level.

#### Top View

The **top view** of a binary tree consists of the nodes visible when the tree is viewed from above. For each horizontal distance from the root, only the first node encountered is included.

**Key Idea:** Use a queue for BFS and a map to track the first node at each horizontal distance.

#### Bottom View

The **bottom view** of a binary tree consists of the nodes visible when the tree is viewed from below. For each horizontal distance from the root, the last node encountered is included.

**Key Idea:** Similar to top view, but update the map with the latest node at each horizontal distance.

#### Boundary View

The **boundary view** of a binary tree is the set of nodes visible when the tree is viewed from the boundary (perimeter). It includes:
- The left boundary (excluding leaves)
- All leaf nodes (from left to right)
- The right boundary (excluding leaves, in bottom-up order)

**Key Idea:** Traverse the left boundary, collect leaves, and traverse the right boundary in reverse.

---

**Example Problem Implementations:**  
- [Left/Right View of Binary Tree (LeetCode 199, 102)](https://leetcode.com/problems/binary-tree-right-side-view/)
- [Top/Bottom View of Binary Tree (GeeksforGeeks)](https://www.geeksforgeeks.org/print-the-top-view-of-a-binary-tree/)
- [Boundary Traversal of Binary Tree (GeeksforGeeks)](https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/)

These views are commonly asked in coding interviews and help in understanding tree traversal techniques.

## Lowest Common Ancestor (LCA)

The **Lowest Common Ancestor (LCA)** of two nodes in a binary tree is the deepest node that has both nodes as descendants (where a node can be a descendant of itself). LCA is a fundamental concept in tree algorithms and is frequently asked in coding interviews.

### Applications
- Finding relationships in hierarchical data (e.g., organizational charts, file systems)
- Solving range queries in trees
- Network routing and genealogy problems

### Approaches

#### 1. Recursive Approach (Binary Tree)

For a general binary tree, the LCA can be found using recursion:

- If the current node is `None`, return `None`.
- If the current node matches either of the target nodes, return the current node.
- Recursively search the left and right subtrees.
- If both left and right recursive calls return non-null, the current node is the LCA.
- Otherwise, return the non-null result.

**Python Example:**
```python
def lowest_common_ancestor(root, p, q):
    if not root or root == p or root == q:
        return root
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    if left and right:
        return root
    return left or right
```

#### 2. Iterative Approach (Binary Search Tree)

For a BST, the LCA can be found by leveraging the BST property:

- If both nodes are less than the current node, move to the left child.
- If both nodes are greater, move to the right child.
- Otherwise, the current node is the LCA.

**Python Example:**
```python
def lowest_common_ancestor_bst(root, p, q):
    while root:
        if p.val < root.val and q.val < root.val:
            root = root.left
        elif p.val > root.val and q.val > root.val:
            root = root.right
        else:
            return root
```

### Key Points
- The recursive approach works for any binary tree.
- The iterative approach is efficient for BSTs (O(h) time, where h is the height).
- LCA is useful for many tree-based problems and is a common interview topic.

**Further Reading:**  
- [LeetCode 236: Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [LeetCode 235: Lowest Common Ancestor of a BST](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

## Preorder, Inorder, and Postorder Traversal in One Traversal

It is possible to compute the preorder, inorder, and postorder traversals of a binary tree in a single pass using an iterative approach with a stack. This technique is useful for optimizing traversal when all three orders are needed.

### Approach

- Use a stack to store pairs of `(node, state)`, where `state` indicates the traversal phase:
    - `1`: Preorder (process before left subtree)
    - `2`: Inorder (process after left, before right)
    - `3`: Postorder (process after both subtrees)
- For each node, push it onto the stack with state `1` and update the state as you traverse.

### Python Example

```python
def all_traversals(root):
        if not root:
                return [], [], []
        stack = [(root, 1)]
        preorder, inorder, postorder = [], [], []
        while stack:
                node, state = stack.pop()
                if state == 1:
                        preorder.append(node.val)
                        stack.append((node, 2))
                        if node.left:
                                stack.append((node.left, 1))
                elif state == 2:
                        inorder.append(node.val)
                        stack.append((node, 3))
                        if node.right:
                                stack.append((node.right, 1))
                else:
                        postorder.append(node.val)
        return preorder, inorder, postorder
```

### Key Points

- All three traversals are generated in a single iteration.
- Reduces the need for multiple passes over the tree.
- Useful for interview problems and optimizing tree algorithms.
- The approach can be adapted for iterative tree traversals in other languages as well.

## Construct Binary Tree from Traversals

Constructing a binary tree from traversal orders is a classic problem. The most common cases are:

### 1. Construct Binary Tree from Inorder and Preorder Traversal

Given the preorder and inorder traversal of a binary tree, you can reconstruct the original tree.

**Key Idea:**
- The first element in preorder is always the root.
- Find the root in the inorder array; elements to the left are the left subtree, elements to the right are the right subtree.
- Recursively build left and right subtrees.

**Python Example:**
```python
def build_tree_pre_in(preorder, inorder):
    if not preorder or not inorder:
        return None
    root_val = preorder[0]
    root = TreeNode(root_val)
    idx = inorder.index(root_val)
    root.left = build_tree_pre_in(preorder[1:idx+1], inorder[:idx])
    root.right = build_tree_pre_in(preorder[idx+1:], inorder[idx+1:])
    return root
```

### 2. Construct Binary Tree from Inorder and Postorder Traversal

Given the postorder and inorder traversal of a binary tree, you can reconstruct the original tree.

**Key Idea:**
- The last element in postorder is always the root.
- Find the root in the inorder array; elements to the left are the left subtree, elements to the right are the right subtree.
- Recursively build left and right subtrees.

**Python Example:**
```python
def build_tree_in_post(inorder, postorder):
    if not inorder or not postorder:
        return None
    root_val = postorder[-1]
    root = TreeNode(root_val)
    idx = inorder.index(root_val)
    root.left = build_tree_in_post(inorder[:idx], postorder[:idx])
    root.right = build_tree_in_post(inorder[idx+1:], postorder[idx:-1])
    return root
```

**Key Points:**
- Both methods rely on the unique properties of traversal orders.
- Efficient implementations use hash maps to avoid repeated searches for root indices.
- These problems are frequently asked in coding interviews.

## Delete a node in BST
[LC Question](https://leetcode.com/problems/delete-node-in-a-bst/)

My solution - 
```[cpp]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) {return nullptr;}
        //base case
        if(root->val == key) {
            // delete if its a root node.
            if(root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // else find the next or previous node as per inorder traversal and remove it.
            if(root->left != nullptr) {
                TreeNode* ptr = root->left;
                TreeNode* ptrParent = root;
                while(ptr->right != nullptr) {
                    ptrParent = ptr;
                    ptr = ptr->right;
                }
                root->val = ptr->val;
                root->left = deleteNode(root->left, ptr->val);
            } else {
                TreeNode* ptr = root->right;
                TreeNode *ptrParent = root;
                while(ptr->left != nullptr) {
                    ptrParent = ptr;
                    ptr = ptr->left;
                }
                root->val = ptr->val;
                root->right = deleteNode(root->right, ptr->val);
            }
        }

        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
```

**Further Reading:**
- [LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [LeetCode 106: Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

 ## Good Questions
 - [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/) - My submission - [LC Submission](https://leetcode.com/problems/binary-tree-maximum-path-sum/solutions/6895288/dfs-approach-indirect-dp/)
 - [Flatten Binary Tree to LinkedList](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/1681569384/) - Stack approach is good.