# BTTOW

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Balance the Towers

You are given $N$ towers with heights $A_1,A_2,\ldots,A_N$ and an integer $K$.

For each tower, you must perform  **exactly one**  of the following operations:

- increase its height by $K$, or
- decrease its height by $K$.

A tower cannot have a negative height after the operation.

After modifying all $N$ towers, let the tallest tower have height $H_{\max}$ and the shortest tower have height $H_{\min}$.

Find the  **minimum possible value of $H_{\max}-H_{\min}$**.

### Input Format

The first line contains two space-separated integers $N$ and $K$ — the number of towers and the amount by which each tower must be increased or decreased.

The second line contains $N$ space-separated integers $A_1,A_2,\ldots,A_N$ — the initial heights of the towers.

### Output Format

Print a single integer — the minimum possible difference between the tallest and shortest tower after all towers are modified.

### Constraints
- $1 \le N \le 10^5$
- $1 \le K \le 10^7$
- $1 \le A_i \le 10^7$
### Sample 1:
Input
Output

```
4 2
1 5 8 10
```

```
5
```

### Explanation:

One optimal modification is:

`1 5 8 10` $\rightarrow$ `3 3 6 8`

The tallest tower has height $8$ and the shortest has height $3$.

Therefore, the minimum possible difference is $8-3=5$.

### Sample 2:
Input
Output

```
5 3
3 9 12 16 20
```

```
11
```

### Explanation:

One optimal modification is:

`3 9 12 16 20` $\rightarrow$ `6 6 9 13 17`

The difference between the tallest and shortest towers is $17-6=11$.

Therefore, the minimum possible difference is `11`.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-07T20:59:24.395Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
vector<pair<int,int>> dp;
vector<int>visited;
pair<int,int> solve(int i,vector<int>&arr,int k){
    int n=arr.size();
    if(i==n)return {INT_MIN,INT_MAX};
    if(visited[i])return dp[i];
    visited[i]=true;
    int x=arr[i];
    int p1=max(0ll,x-k);
    int p2=x+k;
    auto [mx,mn]=solve(i+1,arr,k);
    if(p1>=mn && p1<=mx)return dp[i]={mx,mn};
    if(p2>=mn && p2<=mx)return dp[i]={mx,mn};
    int d0=INT_MAX,d1=INT_MAX,d2=INT_MAX,d3=INT_MAX;
    if(p1<mn)d0=mn-p1;
    if(p1>mx)d1=p1-mx;
    if(p2<mn)d2=mn-p2;
    if(p2>mx)d3=p2-mx;
    int mni=min(min(d0,d1),min(d2,d3));
    if(d0==mni){
        return dp[i]={mx,p1};
    }
    if(d1==mni){
        return dp[i]={p1,mn};
    }
    if(d2==mni){
        return dp[i]={mx,p2};
    }
    return dp[i]={p2,mn};
}
signed main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++)cin>>arr[i];
	dp.resize(n+1);
	visited.resize(n+1,0);
	auto [mx,mn]=solve(0,arr,k);
	cout<<mx-mn<<endl;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/BTTOW)