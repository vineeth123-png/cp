# Priority Queue

## Custom Comparator in C++

```cpp
struct compare{
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
```