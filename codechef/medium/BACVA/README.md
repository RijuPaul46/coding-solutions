# BACVA

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Bank Account Validator

You are given an account number represented by a positive integer $A$.
An account number is considered  **valid**  if the sum of all its digits is divisible by $10$. Otherwise, it is considered  **invalid**.

For example, for the account number $12340$, the sum of its digits is:

$1+2+3+4+0=10$

Since $10$ is divisible by $10$, the account number is valid.

For each account number, determine whether it is  **valid**.

### Input Format
- The first line contains an integer $T$ — the number of test cases.
- Each of the next $T$ lines contains an integer $A$ — the account number.
### Output Format

For each test case, print `Valid` if the account number is valid, or `Invalid` otherwise, on a separate line.

### Constraints
- $1 \le T \le 1000$
- $1 \le A \le 10^{18}$
### Sample 1:
Input
Output

```
3
12340
987654321
1111111111
```

```
Valid
Invalid
Valid
```

### Explanation:

For the first account number, the digit sum is $10$, which is divisible by $10$. Therefore, it is `Valid`.

For the second account number, the digit sum is $45$, which is not divisible by $10$. Therefore, it is `Invalid`.

For the third account number, the digit sum is $10$, which is divisible by $10$. Therefore, it is `Valid`.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T14:18:36.093Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
int digitsum(int n){
    int sm=0;
    while(n>0){
        int d=n%10;
        sm+=d;
        n/=10;
    }
    return sm;
}
signed main() {
	// your code goes here
	 ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
	    int a;
	    cin>>a;
	    
	    int sm=digitsum(a);
	    
	    if((sm%10) ==0){
	        cout<<"Valid"<<endl;
	    }
	    else cout<<"Invalid"<<endl;
	}

}

```

---

[View on CodeChef](https://www.codechef.com/problems/BACVA)