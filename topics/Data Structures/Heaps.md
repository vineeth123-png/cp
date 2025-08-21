# Heaps

## Resources
- CSAcademy - [link](https://csacademy.com/lesson/heaps)

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

## Check if Array is Min Heap

To verify if an array represents a valid min heap, we need to check that every parent node is smaller than or equal to its children.

### Algorithm

```cpp
bool isMinHeap(vector<int>& arr) {
    int n = arr.size();
    
    // Check heap property for all non-leaf nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        // Check left child
        if (left < n && arr[i] > arr[left])
            return false;
            
        // Check right child
        if (right < n && arr[i] > arr[right])
            return false;
    }
    
    return true;
}
```

### Key Points
- Only check non-leaf nodes: indices `0` to `(n-2)/2`
- For each parent at index `i`, check children at `2*i+1` and `2*i+2`
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

### Example Usage

```cpp
vector<int> minHeap = {1, 3, 6, 5, 2, 8};
vector<int> notHeap = {1, 2, 3, 4, 5, 6};

cout << isMinHeap(minHeap);  // true
cout << isMinHeap(notHeap);  // false
```

## Converting Min Heap to Max Heap

There are several approaches to convert a min heap to a max heap, each with different time and space complexities.

### Method 1: Extract All Elements and Rebuild

Extract all elements from min heap and insert them into a new max heap.

```cpp
vector<int> convertMinToMaxHeap_Method1(priority_queue<int, vector<int>, greater<int>>& minHeap) {
    vector<int> maxHeap;
    
    // Extract all elements
    while (!minHeap.empty()) {
        maxHeap.push_back(minHeap.top());
        minHeap.pop();
    }
    
    // Build max heap from extracted elements
    make_heap(maxHeap.begin(), maxHeap.end());
    return maxHeap;
}
```

**Time Complexity**: O(n log n) - n extractions each taking O(log n)  
**Space Complexity**: O(n) - additional array for max heap

### Method 2: In-Place Conversion Using Heapify

Convert the underlying array representation directly by applying max heapify.

```cpp
void convertToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    
    // Build max heap from bottom up
    for (int i = (n - 2) / 2; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
```

**Time Complexity**: O(n) - optimal heapify operation  
**Space Complexity**: O(1) - in-place conversion

### Method 3: Negate Values (Min Heap as Max Heap)

Use mathematical trick by negating all values to simulate max heap behavior with min heap structure.

```cpp
class NegatedMaxHeap {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    void push(int val) {
        minHeap.push(-val);  // Negate before insertion
    }
    
    int top() {
        return -minHeap.top();  // Negate to get original value
    }
    
    void pop() {
        minHeap.pop();
    }
    
    bool empty() {
        return minHeap.empty();
    }
};
```

**Time Complexity**: O(log n) per operation  
**Space Complexity**: O(1) additional space  
**Note**: Only works with numeric types that support negation

### Method 4: Copy to STL Priority Queue

Simply copy elements to a max heap priority queue.

```cpp
priority_queue<int> convertToSTLMaxHeap(vector<int>& minHeapArray) {
    priority_queue<int> maxHeap;
    
    for (int val : minHeapArray) {
        maxHeap.push(val);
    }
    
    return maxHeap;
}
```

**Time Complexity**: O(n log n) - n insertions each O(log n)  
**Space Complexity**: O(n) - new priority queue

### Comparison Summary

| Method | Time Complexity | Space Complexity | In-Place | Best Use Case |
|--------|----------------|------------------|----------|---------------|
| Extract & Rebuild | O(n log n) | O(n) | No | When you need both heaps |
| In-Place Heapify | O(n) | O(1) | Yes | Most efficient conversion |
| Negate Values | O(log n) per op | O(1) | Yes | When structure must remain same |
| STL Copy | O(n log n) | O(n) | No | When using STL containers |

### Recommendation
**Method 2 (In-Place Heapify)** is generally the most efficient approach for one-time conversion, offering O(n) time complexity with constant extra space.