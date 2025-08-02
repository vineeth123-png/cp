# Two Pointers

## Resources

Two Pointers Section in [Antti Laakonsen's Handbook](https://usaco.guide/CPH.pdf#page=87)


## Standard Problems
1. DNF - Dutch National Flag algorithm

## Good Problems
- [LC - Longest Repeating Character Replacement](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

## Sliding Window/Two Pointers templates

### Minimum window substring problem
```cpp
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }
  ```