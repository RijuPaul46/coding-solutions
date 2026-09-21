# LBBS

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Longest Balanced Binary Substring

You are given a binary string $s$ of length $n$, consisting only of the characters `0` and `1`, and an integer $k$.

You may choose any  **substring**  of $s$ and flip at most $k$ characters in it. A flip changes $0$ to $1$ or $1$ to $0$. The chosen substring is called  **balanced**  if it contains an equal number of $0$ and $1$ after performing the flips.

Find the  **maximum possible length**  of a balanced substring. If no balanced substring can be formed, print $0$.

 **substring:**  A substring is a continuous part of a string. For example, if $s=\texttt{10110}$, then `011` is a substring of $s$, while `100` is not.

### Input Format
- The first line contains the binary string $s$.
- The second line contains an integer $k$ — the maximum number of allowed flips.
### Output Format

Print a single integer — the maximum possible length of a balanced substring after performing at most $k$ flips.

### Constraints
- $1 \le n \le 100$
- $0 \le k \le n$
- $s$ contains only 0 and 1.
### Sample 1:
Input
Output

```
110001
1
```

```
6
```

### Explanation:

The entire string contains three `0`s and three `1`s, so it is already balanced. Therefore, the maximum possible length is $6$.

### Sample 2:
Input
Output

```
1111
2
```

```
4
```

### Explanation:

Flip any two characters from `1` to `0`. For example, the string can become: 0011
It contains two `0`s and two `1`s, so the entire string becomes balanced. Therefore, the maximum possible length is $4$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-21T13:43:36.498Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	int k;
	cin>>s>>k;
	int n=s.size();
	int mx=0;
	for(int i=0;i<n;i++){
	    int one=0,zero=0;
	    for(int j=i;j<n;j++){
	       if(s[j]=='1')one++;
	       else zero++;
	       int diff=abs(one-zero);
	       if(diff%2==0){
	           if((diff/2) <=k){
	               mx=max(mx,j-i+1);
	           }
	       }
	    }
	}
	cout<<mx<<endl;
	return 0;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/LBBS)