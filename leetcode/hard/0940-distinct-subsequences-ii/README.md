# Distinct Subsequences II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string s, return  *the number of  **distinct non-empty subsequences**  of*  `s`. Since the answer may be very large, return it  **modulo**  `109 + 7`.

A  **subsequence**  of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not.

 

 **Example 1:** 

```
Input: s = "abc"
Output: 7
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

```

 **Example 2:** 

```
Input: s = "aba"
Output: 6
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".

```

 **Example 3:** 

```
Input: s = "aaa"
Output: 3
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.8 MB (beats 91.16%)  
**Submitted:** 2026-09-07T20:44:14.185Z  

```cpp
#define ll long long
class Solution {
public:
    const ll m=1e9+7;
    // i need distinct .... dp[i]=no of distinct subseq ending at i... 
    // now the problem is appending this char can lead to make duplicate ... How to find it ...find it by storing how many time it is occured as last elements... they were made by some addition .. if we add them again it can generate only duplicate 
    int distinctSubseqII(string s) {
        vector<ll>freq(26,0);
        int n=s.size();
        ll ans=0;
        for(auto &c:s){
            int idx=c-'a';
            ll contri=((ans+1)-freq[idx]+m)%m;
            ans=(ans+contri)%m;
            freq[idx]=(freq[idx]+contri)%m;
        }
        return (int)ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences-ii/)