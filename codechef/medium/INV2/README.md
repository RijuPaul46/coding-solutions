# INV2

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Inversions II

Let $f(A)$ denote the maximum value of $A_i + A_j$ such that $1 \le i < j \le |A|$ and $A_i > A_j$. If no such valid pair exists, $f(A)$ is $0$.

Given $N$, find the sum of $f(A)$ over all permutations of $[1, N]$ modulo $998244353$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of each test case contains a single integer $N$.
### Output Format

For each test case, output the sum of $f(A)$ over all permutations modulo $998244353$.

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
22
140
504678165

```

### Explanation:

 **Test Case 1:**  $f([1, 2]) = 0$ because there is no valid pair, and $f([2, 1]) = 3$ because $(i, j) = (1, 2)$ is valid with $A_i + A_j = 3$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-02T16:00:41.855Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/INV2)