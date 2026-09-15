# Maximum Number of Non-overlapping Palindrome Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` and a  **positive**  integer `k`.

Select a set of  **non-overlapping**  substrings from the string `s` that satisfy the following conditions:

- The length of each substring is at least k.
- Each substring is a palindrome.

Return  *the  **maximum**  number of substrings in an optimal selection*.

A  **substring**  is a contiguous sequence of characters within a string.

 

 **Example 1:** 

```
Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.

```

 **Example 2:** 

```
Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.

```

 

 **Constraints:** 

- 1 <= k <= s.length <= 2000
- s consists of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 247 ms (beats 29.32%)  
**Memory:** 19.5 MB (beats 53.14%)  
**Submitted:** 2026-09-15T18:31:56.226Z  

```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n));

        for (int len = 1; len <= n; ++len) {
            for (int left = 0; left + len <= n; ++left) {
                int right = left + len - 1;
                isPalindrome[left][right] =
                    s[left] == s[right] &&
                    (len <= 2 || isPalindrome[left + 1][right - 1]);
            }
        }

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j = 0; j + k <= i; ++j) {
                if (isPalindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)