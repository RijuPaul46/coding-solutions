# COTOG

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Couples Together

There are $N$ couples sitting in a row of $2N$ seats, numbered from $1$ to $2N$.

You are given an array $A$ of length $2N$, where $A[i]$ denotes the person sitting in seat $i$.

The people are numbered from $0$ to $2N-1$, and the couples are: $(0,1), (2,3), \ldots, (2N-2, 2N-1)$.

Chef wants every adjacent seat pair $(1,2), (3,4), \ldots, (2N-1,2N)$ to contain  **both people from the same couple**.

In one operation, Chef may choose  **any two people**  and swap their seats.

Find the  **minimum number of swaps**  required to arrange the seats so that every adjacent seat pair contains both people from the same couple.

### Input Format
- The first line contains an integer $N$, the number of couples.
- The second line contains $2N$ space separated integers $A_1,A_2,\ldots,A_{2N}$, the people in seat order.
### Output Format

Print a single integer — the minimum number of swaps required.

### Constraints
- $2 \le N \le 30$
- $0 \le A_i \lt 2N$
- Every integer from 0 to 2N - 1 occurs exactly once in A
### Sample 1:
Input
Output

```
2
0 2 1 3
```

```
1
```

### Explanation:

Swap the people in seats $2$ and $3$. The row becomes $[0,1,2,3]$, so both couples sit together. Initially, neither seat pair contains a couple, so at least one swap is necessary.

### Sample 2:
Input
Output

```
2
3 2 0 1
```

```
0
```

### Explanation:

The seat pairs already contain couples $(3,2)$ and $(0,1)$. No swaps are needed.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-21T13:50:07.939Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/COTOG)