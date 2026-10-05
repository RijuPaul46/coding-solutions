# SKOD

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Skip One Day

Chef has recorded his trading results for $N$ days in an array $A$. On day $i$, he earned $A_i$ coins. A negative value represents a loss.

Chef wonders what his total profit would have been if he had  **skipped exactly one day**. Skipping a day removes its profit or loss from the total; the results of all other days remain unchanged.

Find the  **maximum total profit**  he could have earned. The answer may be negative.

### Input Format
- The first line contains an integer $T$ — the number of test cases.
- For each test case: The first line contains an integer $N$ — the number of days. The second line contains $N$ space-separated integers $A_1,A_2,\ldots,A_N$.
### Output Format

For each test case, print the maximum total profit after skipping exactly one day on a separate line.

### Constraints
- $1 \leq T \leq 1000$
- $1 \leq N \leq 10^5$
- $-100 \leq A_i \leq 100$
- The sum of $N$ over all test cases won't exceed $10^6$.
### Sample 1:
Input
Output

```
2
4
6 -4 2 -1
3
5 2 8
```

```
7
13
```

### Explanation:

 **Test case 1:**  Skip day $2$, avoiding the loss of $4$ coins. The total becomes $6+2-1=7$.

 **Test case 2:**  Skip day $2$, which has the smallest profit. The total becomes $5+8=13$. Chef must skip one day even though every day was profitable.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T13:34:55.059Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    int mn=INT_MAX;
    int sum=0;
    for(int i=0;i<n;i++){
        int&x=arr[i];
        cin>>x;
        mn=min(mn,x);
        sum+=x;
    }
    
    cout<<sum-mn<<endl;
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)solve();

}

```

---

[View on CodeChef](https://www.codechef.com/problems/SKOD)