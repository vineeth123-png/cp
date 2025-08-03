# Sorting Algorithms
## Selection Sort

Selection sort finds the minimum element from the unsorted portion and swaps it with the first unsorted element.

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

```python
def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
```

## Bubble Sort

Bubble sort repeatedly steps through the list, compares adjacent elements, and swaps them if they're in the wrong order.

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
```

## Insertion Sort

Insertion sort builds the sorted array one element at a time by inserting each element into its correct position.

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

```python
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
```

## Merge Sort

Merge sort divides the array into halves, recursively sorts them, and then merges the sorted halves.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(n)

```python
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    
    result.extend(left[i:])
    result.extend(right[j:])
    return result
```

## Quick Sort

Quick sort selects a pivot element and partitions the array around it, then recursively sorts the partitions.

**Time Complexity:** O(n log n) average, O(n²) worst case  
**Space Complexity:** O(log n)

```python
def quick_sort(arr, low=0, high=None):
    if high is None:
        high = len(arr) - 1
    
    if low < high:
        pivot = partition(arr, low, high)
        quick_sort(arr, low, pivot - 1)
        quick_sort(arr, pivot + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1
```

## Heap Sort
Heap sort uses a binary heap data structure to sort elements. It first builds a max heap from the array, then repeatedly extracts the maximum element and places it at the end.

**Time Complexity:** O(n log n)  
**Space Complexity:** O(1)

```python
def heap_sort(arr):
    n = len(arr)
    
    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    
    # Extract elements from heap one by one
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]  # Move current root to end
        heapify(arr, i, 0)  # Call heapify on reduced heap

def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    left = 2 * i + 1
    right = 2 * i + 2
    
    # If left child exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    # If right child exists and is greater than largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    # If largest is not root
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)  # Recursively heapify affected subtree
```

## Radix Sort

Radix sort sorts integers by processing individual digits, starting from the least significant digit.

**Time Complexity:** O(d × (n + k)) where d is digits, k is range  
**Space Complexity:** O(n + k)

```python
def radix_sort(arr):
    max_num = max(arr)
    exp = 1
    
    while max_num // exp > 0:
        counting_sort_by_digit(arr, exp)
        exp *= 10

def counting_sort_by_digit(arr, exp):
    output = [0] * len(arr)
    count = [0] * 10
    
    for num in arr:
        digit = (num // exp) % 10
        count[digit] += 1
    
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    for i in range(len(arr) - 1, -1, -1):
        digit = (arr[i] // exp) % 10
        output[count[digit] - 1] = arr[i]
        count[digit] -= 1
    
    for i in range(len(arr)):
        arr[i] = output[i]
```

## Bucket Sort

Bucket sort distributes elements into buckets, sorts each bucket individually, and then concatenates the sorted buckets.

**Time Complexity:** O(n + k) average, O(n²) worst case  
**Space Complexity:** O(n + k)

```python
def bucket_sort(arr):
    if not arr:
        return arr
    
    # Create buckets
    bucket_count = len(arr)
    max_val = max(arr)
    min_val = min(arr)
    
    # Calculate bucket range
    bucket_range = (max_val - min_val) / bucket_count
    
    # Initialize buckets
    buckets = [[] for _ in range(bucket_count)]
    
    # Distribute elements into buckets
    for num in arr:
        if bucket_range == 0:
            bucket_index = 0
        else:
            bucket_index = int((num - min_val) / bucket_range)
            if bucket_index == bucket_count:
                bucket_index -= 1
        buckets[bucket_index].append(num)
    
    # Sort individual buckets and concatenate
    sorted_arr = []
    for bucket in buckets:
        bucket.sort()  # Can use any sorting algorithm
        sorted_arr.extend(bucket)
    
    return sorted_arr
```