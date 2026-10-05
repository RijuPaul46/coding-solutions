# BTFEA

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Birthday Feast

Tushar is hosting a party for $N$ friends. The $i$-th friend needs exactly $A_i$ units of food to be satisfied.

There are $M$ types of dishes available. The $j$-th dish provides $B_j$ units of filling and costs $C_j$.

Each friend may order any dish type any number of times, but a single serving cannot be shared between friends. A friend is considered satisfied only when the total filling provided by the dishes they eat is  **exactly equal**  to their eating capacity.

Find the  **minimum total cost**  required to satisfy all friends.

It is guaranteed that at least one dish has filling capacity $1$, so a valid solution always exists.

### Input Format
- The first line contains two space-separated integers $N$ and $M$ — the number of friends and the number of dish types.
- The second line contains $N$ space-separated integers $A_1,A_2,\ldots,A_N$ — the eating capacities of the friends.
- The third line contains $M$ space-separated integers $B_1,B_2,\ldots,B_M$ — the filling capacities of the dishes.
- The fourth line contains $M$ space-separated integers $C_1,C_2,\ldots,C_M$ — the cost of each dish.
### Output Format
- Print a single integer — the minimum total cost required to satisfy all friends.
### Constraints
- $1 \le N \le 1000$
- $1 \le M \le 1000$
- $1 \le A_i \le 1000$
- $1 \le B_i \le 1000$
- $1 \le C_i \le 10^4$
- At least one dish has filling capacity $1$
### Sample 1:
Input
Output

```
2 2
4 6
1 3
5 3
```

```
14
```

### Explanation:

For the first friend with capacity $4$, choose one dish of filling capacity $1$ and one dish of filling capacity $3$. The cost is $5+3=8$.

For the second friend with capacity $6$, choose the dish of filling capacity $3$ twice. The cost is $3+3=6$.

Therefore, the minimum total cost is:

$8+6=14$

### Sample 2:
Input
Output

```
3 3
2 5 7
1 3 4
3 4 5
```

```
23
```

### Explanation:

For the friend with capacity $2$, choose the dish of filling capacity $1$ twice. The cost is $3+3=6$.

For the friend with capacity $5$, choose dishes of filling capacities $4$ and $1$. The cost is $5+3=8$.

For the friend with capacity $7$, choose dishes of filling capacities $3$ and $4$. The cost is $4+5=9$.

Therefore, the minimum total cost is:

$6+8+9=23$

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T14:25:36.303Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

}

```

---

[View on CodeChef](https://www.codechef.com/problems/BTFEA)