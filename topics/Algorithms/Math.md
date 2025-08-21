# Math

## Euclidean Algorithm for GCD
### Euclid's Lemma
If a prime number p divides the product ab, then p divides either a or b (or both).

### Algorithm
The Euclidean algorithm finds the greatest common divisor (GCD) of two integers using the principle that gcd(a,b) = gcd(b, a mod b).

```python
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
```

**Time Complexity:** O(log min(a,b))

**Example:** gcd(48, 18)
- gcd(48, 18) = gcd(18, 12) = gcd(12, 6) = gcd(6, 0) = 6