# DISBAT

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Dish Battle

A cooking tournament begins with $N$ chefs and $N$ dishes, both numbered from $1$ to $N$. Initially, chef $i$ owns only dish $i$, whose score is $S_i$.

During the tournament, chefs compete in battles. When two chefs battle, each competes using the  **highest-scoring dish**  currently owned by them.

The chef whose chosen dish has the higher score wins the battle. The winner takes ownership of  **all dishes**  owned by the losing chef, and the loser is eliminated from the tournament.

If both chosen dishes have the same score, the battle ends in a tie and ownership remains unchanged.

You must process $Q$ queries in the given order. Each query is one of the following types:

- 0 x y — The chefs currently owning dishes $x$ and $y$ battle each other. If both dishes already belong to the same chef, print Invalid query!.
- 1 x — Print the index of the chef who currently owns dish $x$.
### Input Format

The first line contains an integer $T$ — the number of test cases. For each test case:

- The first line contains an integer $N$ — the number of chefs and dishes.
- The second line contains $N$ space-separated integers $S_1,S_2,\ldots,S_N$ — the scores of the dishes.
- The third line contains an integer $Q$ — the number of queries.

Each of the next $Q$ lines contains a query in one of the following forms:

- 0 x y — The chefs currently owning dishes $x$ and $y$ battle each other. If both dishes are already owned by the same chef, print Invalid query!. Otherwise, process the battle according to the given rules.
- 1 x — Print the index of the chef who currently owns dish $x$.
### Output Format
- For every query of type 1 x, print the index of the chef who currently owns dish $x$.
- For every query of type 0 x y where dishes $x$ and $y$ are already owned by the same chef, print: Invalid query!

Print each answer on a separate line.

### Constraints
- $1 \le T \le 25$
- $1 \le N \le 10^4$
- $0 \le S_i \le 10^6$
- $1 \le Q \le 10^4$
- $1 \le x,y \le N$
### Sample 1:
Input
Output

```
1
4
5 3 8 6
6
1 2
0 1 2
1 2
0 2 3
1 1
0 1 3
```

```
2
1
3
Invalid query!
```

### Explanation:

Initially, dish $2$ belongs to chef $2$, so the first query prints `2`.

Chef $1$ then battles chef $2$. Since $5>3$, chef $1$ wins and acquires dish $2$. Therefore, the next query prints `1`.

Next, the chef owning dish $2$ battles chef $3$. Since chef $3$ owns the dish with score $8$, chef $3$ wins and acquires all dishes owned by chef $1$. Thus, dish $1$ is now owned by chef $3$.

In the final query, dishes $1$ and $3$ already belong to the same chef, so `Invalid query!` is printed.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-07T14:05:05.744Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)solve();
}

```

---

[View on CodeChef](https://www.codechef.com/problems/DISBAT)