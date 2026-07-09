#include <bits/stdc++.h>
using namespace std;

int main() {
    // Your code here
    int n = 25;
    
    cout << __builtin_clz(n) << endl; //return leading zeros in left side;
    cout << __builtin_ctz(n) << endl; //return trailing zeros in right side;
    cout << __builtin_popcount(n) << endl; //return number of set bits in n;


    auto number= 0b111010101; // so this is a binary literal which is used to represent binary numbers and if we want to represent a binary number in C++, we can use the 0b prefix.
    cout<< number;
    return 0;
}

//Rules XOR
   /* 1 -- 1  --- 1
    2 -- 3  --- N+1
    3 -- 0  --- 0
    4 -- 4  --- N
    5 -- 1  --- 1                       // formulae (x-1)%4+1 eg:-- x=19
    6 -- 7  --- N+1                     // 18%4+1=3 = 0
    7 -- 0  --- 0
    8 -- 8  --- N
    */

//

/*

# C++ `std::bitset` Notes

## What is `bitset`?

`std::bitset` is a Standard Library container that stores a **fixed-size sequence of bits (0 or 1)**. It is memory-efficient and provides fast bit manipulation operations.

**Header:**

```cpp
#include <bitset>
```

**Declaration:**

```cpp
bitset<8> b;
```

* Stores exactly 8 bits.
* Size must be known at compile time.
* Bit indices range from `0` to `N-1`.
* **Index 0 is the rightmost (least significant) bit.**

Example:

```
Bitset : 10110010
Index  : 76543210
```

---

# Initialization

### Default

```cpp
bitset<8> b;
```

Output:

```
00000000
```

### From an integer

```cpp
bitset<8> b(13);
```

Output:

```
00001101
```

### From a binary string

```cpp
bitset<8> b("10110010");
```

---

# Accessing Bits

```cpp
b[0]
b[3]
```

or

```cpp
b.test(3)
```

Returns `0` or `1`.

---

# Important Functions

## 1. set()

Set all bits to 1.

```cpp
b.set();
```

Output:

```
11111111
```

Set one bit:

```cpp
b.set(3);
```

Set a bit to a specific value:

```cpp
b.set(3, false);
```

---

## 2. reset()

Reset all bits to 0.

```cpp
b.reset();
```

Reset one bit:

```cpp
b.reset(2);
```

---

## 3. flip()

Toggle all bits.

```cpp
b.flip();
```

Toggle one bit.

```cpp
b.flip(5);
```

---

## 4. test()

Check if a bit is set.

```cpp
b.test(4)
```

Returns `true` or `false`.

---

## 5. count()

Returns number of set bits.

```cpp
b.count();
```

Example:

```
10110100
```

Output:

```
4
```

---

## 6. size()

Returns total number of bits.

```cpp
b.size();
```

---

## 7. any()

Returns `true` if at least one bit is set.

```cpp
b.any();
```

---

## 8. none()

Returns `true` if every bit is 0.

```cpp
b.none();
```

---

## 9. all()

Returns `true` if every bit is 1.

```cpp
b.all();
```

---

## 10. to_ulong()

Convert bitset to an unsigned long.

```cpp
b.to_ulong();
```

---

## 11. to_ullong()

Convert to unsigned long long.

```cpp
b.to_ullong();
```

---

## 12. to_string()

Convert bitset to a string.

```cpp
string s = b.to_string();
```

---

# Bitwise Operators

## AND

```cpp
a & b
```

Example:

```
1100
1010
----
1000
```

---

## OR

```cpp
a | b
```

Example:

```
1100
1010
----
1110
```

---

## XOR

```cpp
a ^ b
```

Example:

```
1100
1010
----
0110
```

---

## NOT

```cpp
~a
```

Example:

```
1100
----
0011
```

---

# Shift Operators

## Left Shift

```cpp
b << 2
```

Example:

```
00001101
```

↓

```
00110100
```

---

## Right Shift

```cpp
b >> 2
```

Example:

```
00001101
```

↓

```
00000011
```

---

# Comparison

```cpp
a == b
a != b
```

---

# Input and Output

Input:

```cpp
cin >> b;
```

Output:

```cpp
cout << b;
```

---

# Common Operations

### Check kth bit

```cpp
if (b[k])
```

or

```cpp
if (b.test(k))
```

---

### Set kth bit

```cpp
b.set(k);
```

---

### Clear kth bit

```cpp
b.reset(k);
```

---

### Toggle kth bit

```cpp
b.flip(k);
```

---

### Count set bits

```cpp
b.count();
```

---

### Check if all bits are zero

```cpp
b.none();
```

---

# Time Complexity

| Operation    | Complexity       |                  |
| ------------ | ---------------- | ---------------- |
| `[]`         | O(1)             |                  |
| `set(pos)`   | O(1)             |                  |
| `reset(pos)` | O(1)             |                  |
| `flip(pos)`  | O(1)             |                  |
| `test(pos)`  | O(1)             |                  |
| `count()`    | O(N / word size) |                  |
| `any()`      | O(N / word size) |                  |
| `none()`     | O(N / word size) |                  |
| `all()`      | O(N / word size) |                  |
| `&`, `       | `, `^`           | O(N / word size) |
| `<<`, `>>`   | O(N / word size) |                  |

---

# Advantages

* Very memory efficient.
* Fast bitwise operations.
* Easy syntax.
* Built into the C++ Standard Library.
* Great for competitive programming.

---

# Limitations

* Size must be known at compile time.
* Cannot resize after creation.
* Not suitable when the number of bits is determined at runtime.

---

# `bitset` vs Integer vs `vector<bool>`

| Feature           | `bitset<N>` | Integer                                        | `vector<bool>` |
| ----------------- | ----------- | ---------------------------------------------- | -------------- |
| Fixed Size        | Yes         | Yes                                            | No             |
| Dynamic Size      | No          | No                                             | Yes            |
| Memory Efficient  | Yes         | Yes                                            | Yes            |
| Bitwise Operators | Yes         | Yes                                            | No             |
| Count Set Bits    | `count()`   | `std::popcount()` (C++20) / compiler built-ins | Manual         |

---

# When to Use `bitset`

Use `bitset` when:

* Number of bits is fixed.
* Solving bitmask problems.
* Working with subsets.
* Storing flags.
* Implementing state compression DP.
* Implementing prime sieves.
* Performing fast set operations in graphs.

---

# Quick Reference

```cpp
bitset<8> b;

b.set();          // Set all bits
b.set(3);         // Set bit 3
b.set(3, false);  // Set bit 3 to 0

b.reset();        // Reset all bits
b.reset(2);       // Reset bit 2

b.flip();         // Flip all bits
b.flip(5);        // Flip bit 5

b.test(4);        // Check bit 4

b.count();        // Number of 1s

b.any();          // At least one bit is 1
b.none();         // All bits are 0
b.all();          // All bits are 1

b.size();         // Total bits

b.to_ulong();     // Convert to unsigned long
b.to_ullong();    // Convert to unsigned long long
b.to_string();    // Convert to string

cout << b;
cin >> b;

a & b;
a | b;
a ^ b;
~a;
a << 2;
a >> 2;
```

*/