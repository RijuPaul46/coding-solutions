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
**Submitted:** 2026-09-07T15:40:13.160Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
signed main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	int mx=INT_MIN;
	int mn=INT_MAX;
	for(int i=0;i<n;i++){cin>>arr[i];
	    mx=max(mx,arr[i]);
	    mn=min(mn,arr[i]);
	}
	if(k>=mx){
	    cout<<"0"<<endl;
	}
	int mid=mn+(mx-mn)/2;
	 mx=INT_MIN;
	 mn=INT_MAX;
	for(auto &x:arr){
	    int p1=x+k;
	    int p2=max(0ll,x-k);
	    if(x>=mid){
	       //mx=max(mx,p1);
	       mx=max(mx,p2);
	       //mn=min(mn,p1);
	       mn=min(mn,p2);
	    }
	    
	   // mx=max(mx,x+k);
	   // mn=min(max(0,x-k),mn);
	}
// 	cout<<mx<<" "<<mn;
	int ans=mx-mn;
	for(auto &x:arr){
	    int p1=x+k;
	    int p2=max(0ll,x-k);
	    if(x<mid){
	        if((p1>=mn && p1<=mx) || (p2>=mn && p2<=mx)){
	            continue;
	        }
	        else{
	            int d0=INT_MAX,d1=INT_MAX,d2=INT_MAX,d3=INT_MAX;
	            if(p1<mn)d0=mx-p1;
	            if(p1>mx)d1=p1-mn;
	            if(p2>mx)d2=p2-mn;
	            if(p2<mn)d3=mx-p2;
	            int mni=min(min(d0,d1),min(d2,d3));
	            ans=mni;
	            if(d0==mni){
	                mn=p1;
	            }
	            if(d1==mni){
	                mx=p1;
	            }
	            if(d2==mni){
	                mx=p2;
	            }
	            if(d3==mni){
	                mn=p2;
	            }
	            
	        }
	        
	    }
	}
	cout<<ans;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/BTTOW)