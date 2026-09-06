# Distinct Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings s and t, return  *the number of distinct*   ***subsequences** ** of  *s*  which equals *t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

 **Example 1:** 

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

```

 **Example 2:** 

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
```

 

 **Constraints:** 

- 1 <= s.length, t.length <= 1000
- s and t consist of English letters.

## Solution

**Language:** C++  
**Runtime:** 26 ms (beats 73.05%)  
**Memory:** 13.2 MB (beats 78.14%)  
**Submitted:** 2026-09-06T13:55:39.399Z  

```cpp
class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string &s,string &t){
        int m=s.size();
        int n=t.size();
        if(j==n)return 1;
        if(i==m)return 0;
        auto &ref=dp[i][j];
        if(ref!=-1)return ref;
        int take=0;
        if(s[i]==t[j]){
            take=solve(i+1,j+1,s,t);
        }
        int skip=solve(i+1,j,s,t);
        return ref=take+skip;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    } 
}; 
 

```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences/)