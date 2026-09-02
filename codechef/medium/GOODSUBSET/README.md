# GOODSUBSET

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Good Subset

A set $S$ is said to be good if the following condition holds:

- for all $x, y \in S$, $x \oplus y < x$ $\&$ $y$, where $\oplus$ represents the bitwise XOR operator, and $\&$ represents the Bitwise AND operator.

Define $f(S)$ as the size of the largest good subset of $S$.

You are given an integer $N$. Consider all $2^N - 1$ non-empty subsets of $[1, N]$, and find the sum of $f(S)$ over all of them, modulo $998244353$

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of input contains a single integer $N$.
### Output Format

For each test case, output the sum of $f(S)$ over the $2^N - 1$ non-empty subsets modulo $998244353$.

### Constraints
- $1 \le T \le 100$
- $2 \le N \le 2 \cdot 10^5$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
4
2
3
4
100

```

```
3
9
19
848191366
```

### Explanation:

 **Test Case 1:**  There are $3$ subsets to consider, $\{1\}, \{2\}$ and $\{1, 2\}$. Each of them have a $f$ value of $1$, because $\{1, 2\}$ is not a good subset, and the single element subsets are good.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-02T15:37:41.930Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/GOODSUBSET)