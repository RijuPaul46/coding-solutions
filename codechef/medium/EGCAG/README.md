# EGCAG

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Card Game

Egor has a deck of $N$ cards. The $i$-th card from the top has a positive integer $A[i]$ written on it.

In each round, Egor chooses a  **non-empty prefix of the remaining deck**  and removes all cards in that prefix.

If the sum of the removed cards is between $L$ and $R$, inclusive, he  **wins**  that round. Otherwise, he loses the round.

Egor continues playing until the deck becomes empty. A winning round may be followed by one or more losing rounds.

Find the  **maximum number of rounds Egor can win**.

### Input Format
- The first line contains three space-separated integers $N$, $L$, and $R$.
- The second line contains $N$ space-separated integers $A[1], A[2], \ldots, A[N]$, in order from top to bottom.
### Output Format

Print a single integer — the maximum number of rounds Egor can win.

### Constraints
- $1 \le N \le 10^5$
- $1 \le L \le R \le 10^9$
- $1 \le A[i] \le 10^9$
### Sample 1:
Input
Output

```
5 3 10
2 1 11 3 7
```

```
3
```

### Explanation:

Egor can play the following rounds:

- Take $[2, 1]$. The sum is $3$, so he wins.
- Take $[11]$. The sum exceeds $10$, so he loses.
- Take $[3]$. The sum is $3$, so he wins.
- Take $[7]$. The sum is $7$, so he wins.

The maximum number of winning rounds is $3$.

### Sample 2:
Input
Output

```
6 5 7
9 4 3 2 8 1
```

```
1
```

### Explanation:

Egor can take $[9]$, $[4, 3]$, $[2]$, $[8]$, and $[1]$ in successive rounds. Only $[4, 3]$, whose sum is $7$, wins.

The only consecutive groups with sums between $5$ and $7$ are $[4, 3]$ and $[3, 2]$. They share a card, so both cannot be used as separate rounds.

Therefore, the maximum number of winning rounds is $1$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-21T13:52:10.514Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/EGCAG)