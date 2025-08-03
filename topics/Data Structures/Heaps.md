# Heaps

A **heap** is a complete binary tree that satisfies the heap property. In a **max heap**, every parent node is greater than or equal to its children, while in a **min heap**, every parent node is less than or equal to its children.

## Heap vs Binary Search Tree (BST)

| Heap | Binary Search Tree |
|------|-------------------|
| Complete binary tree | Can be any shape |
| Heap property (parent-child relationship) | BST property (left < parent < right) |
| Root is min/max element | In-order traversal gives sorted sequence |
| O(log n) insertion/deletion | O(log n) average, O(n) worst case |
| Array-based implementation efficient | Pointer-based implementation common |

## Heap Implementation

### Array-Based Implementation

```cpp
class MinHeap {
private:
    vector<int> heap;
    
    void heapifyUp(int index) {
        if (index == 0) return;
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }
    
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;
        
        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
            
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    
public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    
    int extractMin() {
        if (heap.empty()) return -1;
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return min;
    }
    
    int top() { return heap.empty() ? -1 : heap[0]; }
    bool empty() { return heap.empty(); }
};
```

### Key Properties
- **Parent index**: `(i-1)/2`
- **Left child**: `2*i + 1`
- **Right child**: `2*i + 2`
- **Time Complexity**: Insert/Delete O(log n), Peek O(1)
- **Space Complexity**: O(n)

## Priority Queue
A **priority queue** is an abstract data type that operates similar to a regular queue, but each element has a priority associated with it. In C++, `std::priority_queue` is implemented using a heap data structure.

### C++ Priority Queue (Max Heap by Default)

```cpp
#include <queue>
#include <vector>

// Default max heap
priority_queue<int> maxHeap;
maxHeap.push(10);
maxHeap.push(5);
maxHeap.push(20);
cout << maxHeap.top(); // Output: 20
```

### Creating Min Heap with Priority Queue

Since C++ priority queue is a max heap by default, we need to use `greater<int>` comparator for min heap:

```cpp
// Min heap using greater comparator
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);
minHeap.push(5);
minHeap.push(20);
cout << minHeap.top(); // Output: 5
```

### Custom Comparators for Complex Scenarios

#### For Custom Objects
```cpp
struct Task {
    string name;
    int priority;
    Task(string n, int p) : name(n), priority(p) {}
};

// Custom comparator for min heap based on priority
struct TaskComparator {
    bool operator()(const Task& a, const Task& b) {
        return a.priority > b.priority; // Min heap: higher priority value = lower priority
    }
};

priority_queue<Task, vector<Task>, TaskComparator> taskQueue;
```

#### Lambda Comparator (C++11+)
```cpp
auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
    return a.second > b.second; // Min heap based on second element
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
```

#### Common Use Cases
- **Dijkstra's Algorithm**: Min heap for shortest path
- **Huffman Coding**: Min heap for frequency-based encoding
- **Task Scheduling**: Custom priority-based ordering
- **K-way Merge**: Min heap for merging sorted arrays

### Key Operations
- `push()`: Insert element - O(log n)
- `top()`: Access top element - O(1)
- `pop()`: Remove top element - O(log n)
- `empty()`: Check if empty - O(1)
- `size()`: Get size - O(1)

### Custom Comparator in C++

```cpp
struct compare{
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
```