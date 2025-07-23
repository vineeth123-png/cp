# Binary Search

Binary search is an efficient algorithm for finding an item from a sorted list of elements. It works by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, the search continues in the lower half, or if it's greater, in the upper half. This process continues until the value is found or the interval is empty.

## Basic Binary Search Algorithm

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
```

## Common Binary Search Questions

- **Find the first or last occurrence of a target in a sorted array**
- **Search in a rotated sorted array**
- **Find the peak element in a mountain array**
- **Find the minimum or maximum in a sorted/rotated array**
- **Find the square root of a number**
- **Search for an element in a 2D matrix**


## Binary Search Intuition
- Whenever you encounter binary search or think about implementing it in a problem, think this way - How can I eliminate half of the search space in each iteration. This proves to be a good way to approach binary search problems, especially the ones like rotated array series. It is how striver explains problems.

## Advanced Binary Search Concepts

### 1. Binary Search on Answer (Parametric Search)
Used when the answer lies within a range and you need to find the minimum or maximum value that satisfies a condition.

**Example:**  
- Find the minimum capacity to ship packages within D days.
- Allocate minimum number of pages to students.

### 2. Lower Bound and Upper Bound
- **Lower Bound:** First position where the value is not less than the target.
- **Upper Bound:** First position where the value is greater than the target.

### 3. Binary Search on Monotonic Functions
Binary search can be applied to functions that are monotonic (always increasing or decreasing).

### 4. Binary Search in Infinite or Unknown Sized Arrays
Special techniques are used to find the search boundaries before applying binary search.

## Tips

- Always ensure the array or search space is sorted or monotonic.
- Be careful with integer overflow when calculating the middle index.
- Consider edge cases (empty array, single element, duplicates).

## References

- [LeetCode Binary Search Problems](https://leetcode.com/tag/binary-search/)
- [Binary Search (Wikipedia)](https://en.wikipedia.org/wiki/Binary_search_algorithm)
- [Binary Search Patterns (GeeksforGeeks)](https://www.geeksforgeeks.org/binary-search/)

## Series of Questions in Rotated Sorted Arrays

Rotated sorted arrays are arrays that were originally sorted but then rotated at some pivot. Binary search can be adapted to solve several problems in such arrays:

- **Search for a target in a rotated sorted array:**  
    Find the index of a given target value in a rotated sorted array.

    **Approach:**  
    1. Use binary search to find the pivot (the index of the smallest element).
    2. Decide which part of the array to search (left or right of the pivot) based on the target value.
    3. Perform standard binary search in the selected subarray.

    **Example (Python):**
    ```python
    def search_rotated(arr, target):
        left, right = 0, len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] == target:
                return mid
            # Left half is sorted
            if arr[left] <= arr[mid]:
                if arr[left] <= target < arr[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # Right half is sorted
            else:
                if arr[mid] < target <= arr[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1
    ```

- **Find the minimum element in a rotated sorted array:**  
    Locate the smallest element, which is the rotation point.

    **Approach:**  
    1. Use binary search to compare the middle element with the rightmost element.
    2. If `arr[mid] > arr[right]`, the minimum is in the right half; otherwise, it's in the left half (including mid).
    3. Continue until the search space is reduced to one element.

    **Example (Python):**
    ```python
    def find_min_rotated(arr):
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) // 2
            if arr[mid] > arr[right]:
                left = mid + 1
            else:
                right = mid
        return arr[left]
    ```

- **Find the number of rotations:**  
    Determine how many times the array has been rotated.

    **Approach:**  
    1. The index of the minimum element is equal to the number of rotations.
    2. Use the same logic as finding the minimum element, but return the index instead of the value.

    **Example (Python):**
    ```python
    def count_rotations(arr):
        left, right = 0, len(arr) - 1
        while left < right:
            mid = (left + right) // 2
            if arr[mid] > arr[right]:
                left = mid + 1
            else:
                right = mid
        return left
    ```

- **Search for a target with duplicates in a rotated sorted array:**  
    Handle cases where the array contains duplicate elements.

    **Approach:**  
    1. Use binary search, but when `arr[left] == arr[mid] == arr[right]`, increment `left` and decrement `right` to skip duplicates.
    2. Otherwise, proceed as in the standard rotated array search.

    **Example (Python):**
    ```python
    def search_rotated_with_duplicates(arr, target):
        left, right = 0, len(arr) - 1
        while left <= right:
            mid = (left + right) // 2
            if arr[mid] == target:
                return True
            if arr[left] == arr[mid] == arr[right]:
                left += 1
                right -= 1
            elif arr[left] <= arr[mid]:
                if arr[left] <= target < arr[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if arr[mid] < target <= arr[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return False
    ```

These problems require careful adjustment of the binary search logic to account for the rotation and possible duplicates.

### Resources for rotated series
- Striver's explanations were good - [link1](https://www.youtube.com/watch?v=5qGrJbHhqFs&feature=youtu.be), [link2](https://www.youtube.com/watch?v=w2G2W8l__pc)