# COIFL

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Coin Flip

A coin has $1$ printed on one side and $2$ on the other. Each flip adds the number on the face-up side to a running sum, initially $0$.

Find the number of distinct sequences of flips whose sum is exactly $S$. Two sequences are different if they differ in length or in the result of at least one flip. For example, $(1, 2)$ and $(2, 1)$ are different sequences.

### Input Format

The input contains a single integer $S$, the required sum.

### Output Format

Print the number of distinct sequences of flips whose sum is exactly $S$.

### Constraints
- $1 \le S \le 20$
### Sample 1:
Input
Output

```
3
```

```
3
```

### Explanation:

To achieve a sum of 3, there are three ways:

- (1, 2)
- (2, 1)
- (1, 1, 1)
### Sample 2:
Input
Output

```
2
```

```
2
```

### Explanation:

To achieve a sum of 2, there are two ways:

- (1, 1)
- (2)

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T13:50:06.069Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
int dp[25];
int solve(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;
    if(dp[n]!=-1)return dp[n];
    int one=solve(n-1);
    int two=solve(n-2);
    return dp[n]=(one+two);
}
int main() {
	// your code goes here
	int s;
	cin>>s;
	memset(dp,-1,sizeof(dp));
	cout<< solve(s)<<endl;
	return 0;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/COIFL)