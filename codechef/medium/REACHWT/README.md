# REACHWT

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Reach Weight

You need to buy some weights that total to exactly $N$ kg.

You can buy either $1$ kg weights for $20$ rupees, or $2$ kg weights for $30$ rupees.

Find the minimum cost to buy such a set of weights that sum to $N$ kg.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line contains a single integer $N$.
### Output Format

For each test case, output on a new line the minimum total cost of buying a set of weights that total to exactly $N$ kg.

### Constraints
- $1 \le T \le 100$
- $1 \le N \le 100$
### Sample 1:
Input
Output

```
3
1
2
3

```

```
20
30
50

```

### Explanation:

 **Test Case 1:**  You buy $1$ one-kg weight for a cost of $20$.

 **Test Case 2:**  You buy $1$ two-kg weight for a cost of $30$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-02T14:33:48.412Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int cost=0;
    cost+=(n/2)*30;
    cost+=(n%2)*20;
    cout<<cost<<endl;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)solve();

}

```

---

[View on CodeChef](https://www.codechef.com/problems/REACHWT)