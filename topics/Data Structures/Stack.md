# Stack
- [Stack](#stack)
  - [Introduction](#introduction)
  - [Implementation](#implementation)
  - [Resources \& Problem list](#resources--problem-list)
  - [Monotonic Stack](#monotonic-stack)
    - [Rods:](#rods)

## Introduction
LIFO principle's brand ambassador

Stack's usability - it stacks things up, and is useful for scenarios like recursion.
This property of having to peek the top element and pop it off based on a scenario, and continue this until its empty is seen in problems in next greater element.

This property might be the prinicple for monotonic stack, this def/statement would be updated later.

## Implementation
- C++ - [Implementation](https://learn.microsoft.com/en-us/cpp/standard-library/stack-class?view=msvc-170)
- Java - [Implementation](https://docs.oracle.com/javase/10/docs/api/java/util/Stack.html)
- Python - [Implementation](https://docs.python.org/3/tutorial/datastructures.html)
- C# - [Implementation](https://learn.microsoft.com/en-us/dotnet/api/system.collections.stack?view=net-8.0)

## Implement stack using queues

### Using Two Queues

To implement a stack using two queues (`q1` and `q2`):

- **Push:** Enqueue the new element to `q2`. Then dequeue all elements from `q1` and enqueue them to `q2`. Swap the names of `q1` and `q2`.
- **Pop:** Dequeue from `q1`.
- **Top:** Peek the front of `q1`.
- **Empty:** Check if `q1` is empty.

This ensures the newest element is always at the front of `q1`, maintaining LIFO order.

**Python Example:**
```python
from collections import deque

class Stack:
  def __init__(self):
    self.q1 = deque()
    self.q2 = deque()

  def push(self, x):
    self.q2.append(x)
    while self.q1:
      self.q2.append(self.q1.popleft())
    self.q1, self.q2 = self.q2, self.q1

  def pop(self):
    return self.q1.popleft()

  def top(self):
    return self.q1[0]

  def empty(self):
    return not self.q1
```

---

### Using One Queue

To implement a stack using a single queue:

- **Push:** Enqueue the new element. Then, for all previous elements, dequeue and enqueue them back (rotate the queue) so the new element moves to the front.
- **Pop:** Dequeue from the queue.
- **Top:** Peek the front of the queue.
- **Empty:** Check if the queue is empty.

**Python Example:**
```python
from collections import deque

class Stack:
  def __init__(self):
    self.q = deque()

  def push(self, x):
    self.q.append(x)
    for _ in range(len(self.q) - 1):
      self.q.append(self.q.popleft())

  def pop(self):
    return self.q.popleft()

  def top(self):
    return self.q[0]

  def empty(self):
    return not self.q
```

## Resources & Problem list

Striver's Queue and Stack [Playlist](https://www.youtube.com/watch?v=NdDIaH91P0g&list=PLgUwDviBIf0pOd5zvVVSzgpo6BaCpHT9c&index=4) - Has Good Problems

## Monotonic Stack
Guides:
- [LC Guide 1](https://leetcode.com/discuss/study-guide/2347639/a-comprehensive-guide-and-template-for-monotonic-stack-based-problems)

- [A medium article](https://medium.com/@florian_algo/introduction-to-monotonic-stack-that-everyone-can-understand-e5f54467faaf)

- [LC Guide 2](https://leetcode.com/discuss/study-guide/3773642/Mastering-Monotonic-Stack%3A-Unlocking-Efficient-Problem-Solving-Pattern-Technique-Once-and-Forever)

- [An article in a book](https://liuzhenglaichn.gitbook.io/algorithm/monotonic-stack)

### Rods: 
- [Min Stack](https://leetcode.com/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150)
