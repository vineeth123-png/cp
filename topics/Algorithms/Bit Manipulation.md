# Bit Manipulation

## Resources
- [Striver's Bit Manipulation Playlist](https://www.youtube.com/playlist?list=PLgUwDviBIf0rnqh8QsJaHyIX7KUiaPUv7)

## 1's Complement and 2's Complement

### 1's Complement
- **Definition**: Flip all bits (0 becomes 1, 1 becomes 0)
- **Example**: 
    - Binary: `1010` → 1's complement: `0101`
    - For 8-bit: `10110010` → `01001101`
- **Formula**: `~n` or `(2^bits - 1) - n`

### 2's Complement
- **Definition**: 1's complement + 1
- **Steps**:
    1. Find 1's complement
    2. Add 1 to the result
- **Example**:
    - Binary: `1010`
    - 1's complement: `0101`
    - 2's complement: `0101 + 1 = 0110`
- **Usage**: Standard representation for negative numbers in most systems
- **Range**: For n-bit numbers: `-(2^(n-1))` to `2^(n-1) - 1`

### Key Properties
- **2's complement of 2's complement** = original number
- **Overflow detection**: Add two positive numbers and get negative result
- **No separate representation** for +0 and -0 (unlike 1's complement)

## Binary Bit Manipulation Operators

### Bitwise AND (&)
- **Operation**: Returns 1 only when both bits are 1
- **Truth Table**: `1 & 1 = 1`, `1 & 0 = 0`, `0 & 1 = 0`, `0 & 0 = 0`
- **Example**: `1010 & 1100 = 1000`
- **Common Uses**:
    - Check if bit is set: `n & (1 << i)`
    - Clear specific bits: `n & ~mask`
    - Extract lower bits: `n & ((1 << k) - 1)`

### Bitwise OR (|)
- **Operation**: Returns 1 when at least one bit is 1
- **Truth Table**: `1 | 1 = 1`, `1 | 0 = 1`, `0 | 1 = 1`, `0 | 0 = 0`
- **Example**: `1010 | 1100 = 1110`
- **Common Uses**:
    - Set specific bits: `n | (1 << i)`
    - Combine flags: `flag1 | flag2`

### Bitwise XOR (^)
- **Operation**: Returns 1 when bits are different
- **Truth Table**: `1 ^ 1 = 0`, `1 ^ 0 = 1`, `0 ^ 1 = 1`, `0 ^ 0 = 0`
- **Example**: `1010 ^ 1100 = 0110`
- **Properties**:
    - `a ^ a = 0`
    - `a ^ 0 = a`
    - Commutative and associative
- **Common Uses**:
    - Toggle bits: `n ^ (1 << i)`
    - Swap variables: `a ^= b; b ^= a; a ^= b;`
    - Find unique element in array

### Bitwise NOT (~)
- **Operation**: Flips all bits (1's complement)
- **Example**: `~1010 = 0101` (in 4-bit representation)
- **Note**: Result depends on data type size
- **Common Uses**:
    - Create masks: `~0` gives all 1s
    - Clear bits: `n & ~mask`

### Left Shift (<<)
- **Operation**: Shifts bits left, fills with 0s from right
- **Example**: `1010 << 2 = 101000`
- **Effect**: Multiplies by 2^n (where n is shift count)
- **Common Uses**:
    - Fast multiplication by powers of 2
    - Create bit masks: `1 << i`
    - Set bit positions

### Right Shift (>>)
- **Logical Right Shift**: Fills with 0s from left
- **Arithmetic Right Shift**: Preserves sign bit for signed numbers
- **Example**: `1010 >> 1 = 0101`
- **Effect**: Divides by 2^n (integer division)
- **Common Uses**:
    - Fast division by powers of 2
    - Extract specific bit ranges
    - Check bit values

### Operator Precedence (High to Low)
1. `~` (NOT)
2. `<<`, `>>` (Shifts)
3. `&` (AND)
4. `^` (XOR)
5. `|` (OR)  

## Negative Number Storage

### How Negative Numbers are Stored
- **Modern computers use 2's complement** for representing negative numbers
- **Most Significant Bit (MSB)** serves as the sign bit:
    - `0` = positive number
    - `1` = negative number

### Storage Process for Negative Numbers
1. **Take absolute value** of the number
2. **Convert to binary** representation
3. **Find 1's complement** (flip all bits)
4. **Add 1** to get 2's complement
5. **Result is the stored representation**

### Example: Storing -5 in 8-bit system
- Absolute value: `5`
- Binary of 5: `00000101`
- 1's complement: `11111010`
- Add 1: `11111010 + 1 = 11111011`
- **Stored as**: `11111011`

### Why 2's Complement?
- **Unified arithmetic**: Same addition/subtraction circuits work for positive and negative
- **No dual zero**: Only one representation for zero
- **Easy negation**: Just take 2's complement
- **Range optimization**: For n-bit: `-(2^(n-1))` to `2^(n-1) - 1`

### Verification
- **To get original number**: Take 2's complement of stored value
- **Example**: `11111011` → 1's comp: `00000100` → Add 1: `00000101` = 5
- **Since MSB was 1**: Result is -5 ✓

## Tips and Tricks

### Swapping Two Numbers Using XOR

#### Method
```
a = a ^ b
b = a ^ b  // Now b = (a ^ b) ^ b = a
a = a ^ b  // Now a = (a ^ b) ^ a = b
```

#### Why It Works
- **XOR Property**: `x ^ x = 0` and `x ^ 0 = x`
- **Step by step**:
    - After step 1: `a = original_a ^ original_b`
    - After step 2: `b = (original_a ^ original_b) ^ original_b = original_a`
    - After step 3: `a = (original_a ^ original_b) ^ original_a = original_b`

#### Example
```
Initial: a = 5 (101), b = 3 (011)
Step 1: a = 5 ^ 3 = 110 (6)
Step 2: b = 6 ^ 3 = 101 (5)
Step 3: a = 6 ^ 5 = 011 (3)
Result: a = 3, b = 5
```

#### One-Line Version
```
a ^= b ^= a ^= b;  // Though less readable
```

#### Advantages
- **No temporary variable** needed
- **Memory efficient**
- **Works with any data type** that supports XOR

#### Limitations
- **Same variable swap**: `a ^= a ^= a ^= a` results in `a = 0`
- **Less readable** than traditional swapping
- **No performance benefit** on modern compilers

### Setting and Clearing Specific Bits

#### Set ith Bit
- **Operation**: `n | (1 << i)`
- **Logic**: Create mask with only ith bit set, then OR with number
- **Example**: Set 2nd bit in `1010` (10)
    ```
    n = 1010 (10)
    mask = 1 << 2 = 0100 (4)
    result = 1010 | 0100 = 1110 (14)
    ```

#### Clear ith Bit
- **Operation**: `n & ~(1 << i)`
- **Logic**: Create mask with only ith bit clear, then AND with number
- **Example**: Clear 3rd bit in `1110` (14)
    ```
    n = 1110 (14)
    mask = 1 << 3 = 1000 (8)
    ~mask = 0111 (7)
    result = 1110 & 0111 = 0110 (6)
    ```

#### Toggle ith Bit
- **Operation**: `n ^ (1 << i)`
- **Logic**: XOR flips the specific bit (0→1, 1→0)
- **Example**: Toggle 1st bit in `1010` (10)
    ```
    n = 1010 (10)
    mask = 1 << 1 = 0010 (2)
    result = 1010 ^ 0010 = 1000 (8)
    ```
- **Another Example**: Toggle 0th bit in `1010` (10)
    ```
    n = 1010 (10)
    mask = 1 << 0 = 0001 (1)
    result = 1010 ^ 0001 = 1011 (11)
    ```

#### Check if ith Bit is Set
- **Operation**: `(n & (1 << i)) != 0`
- **Returns**: True if bit is 1, false if bit is 0
- **Example**: Check 2nd bit in `1010` (10)
    ```
    n = 1010 (10)
    mask = 1 << 2 = 0100 (4)
    result = 1010 & 0100 = 0100 (non-zero) → bit is SET
    ```


    ### Advanced Bit Manipulation Techniques

    #### Set Rightmost Unset Bit
    - **Operation**: `n | (n + 1)`
    - **Logic**: Adding 1 to a number flips all trailing 1s to 0s and the first 0 to 1. OR with original preserves existing 1s.
    - **Example**: Set rightmost unset bit in `1010` (10)
        ```
        n = 1010 (10)
        n + 1 = 1011 (11)
        result = 1010 | 1011 = 1011 (11)
        ```
    - **Another Example**: `1100` (12)
        ```
        n = 1100 (12)
        n + 1 = 1101 (13)
        result = 1100 | 1101 = 1101 (13)
        ```

    #### Unset Rightmost Set Bit
    - **Operation**: `n & (n - 1)`
    - **Logic**: Subtracting 1 flips all trailing 0s to 1s and the rightmost 1 to 0. AND removes the flipped bit.
    - **Example**: Unset rightmost set bit in `1010` (10)
        ```
        n = 1010 (10)
        n - 1 = 1001 (9)
        result = 1010 & 1001 = 1000 (8)
        ```
    - **Another Example**: `1100` (12)
        ```
        n = 1100 (12)
        n - 1 = 1011 (11)
        result = 1100 & 1011 = 1000 (8)
        ```

    #### Count Number of Set Bits (Population Count)

    ##### Method 1: Brian Kernighan's Algorithm
    - **Operation**: Repeatedly apply `n = n & (n - 1)` until n becomes 0
    - **Logic**: Each iteration removes exactly one set bit
    - **Time Complexity**: O(number of set bits)
    - **Example**: Count set bits in `1011` (11)
        ```
        n = 1011 (11), count = 0
        Iteration 1: n = 1011 & 1010 = 1010 (10), count = 1
        Iteration 2: n = 1010 & 1001 = 1000 (8), count = 2
        Iteration 3: n = 1000 & 0111 = 0000 (0), count = 3
        Result: 3 set bits
        ```

    ##### Method 2: Simple Loop
    - **Operation**: Check each bit using `n & 1`, then right shift
    - **Time Complexity**: O(log n) or O(number of bits)
    - **Example**:
        ```
        n = 1011 (11), count = 0
        Check bit 0: 1011 & 1 = 1, count = 1, n = 0101
        Check bit 1: 0101 & 1 = 1, count = 2, n = 0010
        Check bit 2: 0010 & 1 = 0, count = 2, n = 0001
        Check bit 3: 0001 & 1 = 1, count = 3, n = 0000
        ```

    ##### Method 3: Built-in Functions
    - **C++**: `__builtin_popcount(n)` for int, `__builtin_popcountll(n)` for long long
    - **Java**: `Integer.bitCount(n)`
    - **Python**: `bin(n).count('1')`

    #### Check if Number is Power of 2

    ##### Method 1: Using n & (n-1)
    - **Operation**: `n > 0 && (n & (n - 1)) == 0`
    - **Logic**: Powers of 2 have exactly one set bit. Removing it gives 0.
    - **Examples**:
        - `8 (1000)`: `8 & 7 = 1000 & 0111 = 0000` → Power of 2 ✓
        - `6 (0110)`: `6 & 5 = 0110 & 0101 = 0100` → Not power of 2 ✗
        - `16 (10000)`: `16 & 15 = 10000 & 01111 = 00000` → Power of 2 ✓

    ##### Method 2: Count Set Bits
    - **Operation**: Check if exactly one bit is set
    - **Logic**: `popcount(n) == 1 && n > 0`

    ##### Method 3: Mathematical Approach
    - **Operation**: `n > 0 && (n & -n) == n`
    - **Logic**: `n & -n` isolates the rightmost set bit. For powers of 2, this equals the original number.

    ##### Edge Cases
    - **Important**: Always check `n > 0` since 0 is not a power of 2
    - **Powers of 2**: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024...


    #### Finding XOR of Numbers from L to R

    ##### Problem Statement
    Find XOR of all numbers in the range [L, R] inclusive.

    ##### Naive Approach
    - **Operation**: Iterate from L to R and XOR all numbers
    - **Time Complexity**: O(R - L + 1)
    - **Example**: XOR from 3 to 6
        ```
        3 ^ 4 ^ 5 ^ 6 = 011 ^ 100 ^ 101 ^ 110 = 000 (0)
        ```

    ##### Optimized Approach: Using XOR Properties

    ###### Key Insight
    - **XOR from 1 to N** follows a pattern based on N % 4
    - **Formula**: `xor(L, R) = xor(1, R) ^ xor(1, L-1)`
    - **Logic**: XOR cancels out common elements

    ###### Pattern for XOR from 1 to N
    ```
    if N % 4 == 1: result = 1
    if N % 4 == 2: result = N + 1
    if N % 4 == 3: result = 0
    if N % 4 == 0: result = N
    ```

    ###### Why This Pattern Works
    - **XOR properties**: 
        - `a ^ a = 0`
        - `a ^ 0 = a`
    - **Pattern observation**:
        ```
        1 = 1
        1^2 = 3
        1^2^3 = 0
        1^2^3^4 = 4
        1^2^3^4^5 = 1
        1^2^3^4^5^6 = 7
        1^2^3^4^5^6^7 = 0
        1^2^3^4^5^6^7^8 = 8
        ```

    ###### Implementation Steps
    1. **Calculate xor(1, R)** using the pattern
    2. **Calculate xor(1, L-1)** using the pattern
    3. **Return**: `xor(1, R) ^ xor(1, L-1)`

    ###### Example: XOR from 4 to 7
    ```
    xor(1, 7) = 0  (since 7 % 4 = 3)
    xor(1, 3) = 0  (since 3 % 4 = 3)
    xor(4, 7) = 0 ^ 0 = 0
    ```

    ###### Example: XOR from 3 to 6
    ```
    xor(1, 6) = 7  (since 6 % 4 = 2, result = 6 + 1 = 7)
    xor(1, 2) = 3  (since 2 % 4 = 2, result = 2 + 1 = 3)
    xor(3, 6) = 7 ^ 3 = 4
    ```

    ###### Time Complexity
    - **Optimized**: O(1)
    - **Space Complexity**: O(1)

    ###### Edge Cases
    - **L = 1**: `xor(1, R)` directly
    - **L = R**: Result is just R
    - **L > R**: Invalid range, return 0 or handle as error


    #### Find Two Numbers Appearing Odd Times

    ##### Problem Statement
    Given an array where all numbers appear even number of times except two numbers which appear odd number of times. Find these two numbers.

    ##### Approach: Using XOR Properties

    ###### Key Insight
    - **XOR of all elements** will give `a ^ b` where `a` and `b` are the two odd-occurring numbers
    - **All even-occurring elements cancel out** due to `x ^ x = 0`
    - **Need to separate `a` and `b`** from their XOR

    ###### Algorithm Steps
    1. **Find XOR of all elements**: `xor_all = a ^ b`
    2. **Find rightmost set bit** in `xor_all`: This bit differs between `a` and `b`
    3. **Partition array** based on this bit:
        - Group 1: Elements with this bit set
        - Group 2: Elements with this bit unset
    4. **XOR each group separately**: One group gives `a`, other gives `b`

    ###### Why This Works
    - **Rightmost set bit**: `rightmost_bit = xor_all & (-xor_all)`
    - **Different groups**: Since `a` and `b` differ at this bit, they go to different groups
    - **Pairs stay together**: Numbers appearing even times have same bit pattern, so pairs stay in same group and cancel out

    ###### Example: Array [2, 3, 7, 9, 11, 2, 3, 11]
    ```
    Step 1: XOR all elements
    2 ^ 3 ^ 7 ^ 9 ^ 11 ^ 2 ^ 3 ^ 11 = 7 ^ 9 = 14 (1110)

    Step 2: Find rightmost set bit
    xor_all = 14 = 1110
    rightmost_bit = 14 & (-14) = 14 & 2 = 2 (0010)

    Step 3: Partition based on bit 1
    Group 1 (bit 1 set): [2, 3, 2, 3] → XOR = 0 ^ 7 = 7
    Group 2 (bit 1 unset): [7, 9, 11, 11] → XOR = 0 ^ 9 = 9

    Result: 7 and 9
    ```

    ###### Implementation Template
    ```
    xor_all = 0
    for each element in array:
         xor_all ^= element

    rightmost_bit = xor_all & (-xor_all)

    first_number = 0
    second_number = 0

    for each element in array:
         if (element & rightmost_bit):
              first_number ^= element
         else:
              second_number ^= element
    ```

    ###### Time Complexity
    - **Time**: O(n) - Two passes through array
    - **Space**: O(1) - Only using few variables

    ###### Edge Cases
    - **Array size < 2**: Invalid input
    - **All numbers appear even times**: Result would be 0, 0
    - **Only two elements**: Direct answer without XOR logic needed
