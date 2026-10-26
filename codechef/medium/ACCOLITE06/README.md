# ACCOLITE06

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Equal Sum Partition

You are given an array $A$ containing $N$ positive integers.

Determine whether its elements can be divided into two non-empty groups with equal sums. Every array element must belong to exactly one group. Elements with the same value are treated as separate occurrences.

### Input Format
- The first line contains an integer $T$, the number of test cases.
- For each test case: The first line contains an integer $N$, the size of the array. The second line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, print `YES` if such a partition exists, or `NO` otherwise, on a separate line.

### Constraints
- $1 \le T \le 100$
- $1 \le N \le 100$
- $1 \le A_i \le 100$
### Sample 1:
Input
Output

```
2
4
1 5 11 5
3
1 3 5
```

```
YES
NO
```

### Explanation:

 **Test Case 1:**  Can be divided into [1,5,5] and [11]
 **Test Case 2:**  Cannot be divided

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T14:00:55.237Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)solve();

}

```

---

[View on CodeChef](https://www.codechef.com/problems/ACCOLITE06)