# Longest Common Subsequence

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two strings `text1` and `text2`, return  *the length of their longest  **common subsequence**.* If there is no  **common subsequence**, return `0`.

A  **subsequence**  of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, "ace" is a subsequence of "abcde".

A  **common subsequence**  of two strings is a subsequence that is common to both strings.

 

 **Example 1:** 

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

```

 **Example 2:** 

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

```

 **Example 3:** 

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

```

 

 **Constraints:** 

- 1 <= text1.length, text2.length <= 1000
- text1 and text2 consist of only lowercase English characters.

## Solution

**Language:** C++  
**Runtime:** 51 ms (beats 6.90%)  
**Memory:** 27.7 MB (beats 6.53%)  
**Submitted:** 2026-09-04T14:44:40.711Z  

```cpp
class Solution {
public:
    int solve(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        int m=t1.size();
        int n=t2.size();
        if(i==m || j==n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(t1[i]==t2[j]){
            return dp[i][j]=1+solve(i+1,j+1,t1,t2,dp);
        }
        return dp[i][j]=max(solve(i+1,j,t1,t2,dp),solve(i,j+1,t1,t2,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // memset(dp,-1,sizeof(dp));
        return solve(0,0,t1,t2,dp);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-common-subsequence/)