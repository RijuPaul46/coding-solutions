# Longest Repeating Character Replacement

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return  *the length of the longest substring containing the same letter you can get after performing the above operations*.

 

 **Example 1:** 

```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

```

 **Example 2:** 

```
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of only uppercase English letters.
- 0 <= k <= s.length

## Solution

**Language:** C++  
**Runtime:** 14 ms (beats 17.67%)  
**Memory:** 11.3 MB (beats 7.36%)  
**Submitted:** 2026-10-25T14:39:28.000Z  

```cpp
class Solution {
public:
    int mx_freq(unordered_map<char,int>&mp){
        int mx=0;
        for(auto & [u,v]:mp)mx=max(mx,v);
        return mx;
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while((i-j+1-mx_freq(mp))>k){
                char c=s[j];
                mp[c]--;
                if(mp[c]==0)mp.erase(c);
                j++;
            }
            ans=max(ans,i-j+1);

        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/)