# Minimum Window Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings `s` and `t` of lengths `m` and `n` respectively, return  *the  **minimum window***   ***substring**  **of  *`s`*  such that every character in  *`t`*  (** including duplicates**) is included in the window *. If there is no such substring, return* the empty string *`""`.

The testcases will be generated such that the answer is  **unique**.

 

 **Example 1:** 

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

```

 **Example 2:** 

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

```

 **Example 3:** 

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

```

 

 **Constraints:** 

- m == s.length
- n == t.length
- 1 <= m, n <= 105
- s and t consist of uppercase and lowercase English letters.

 

 **Follow up:**  Could you find an algorithm that runs in `O(m + n)` time?

## Solution

**Language:** C++  
**Runtime:** 12 ms (beats 39.46%)  
**Memory:** 11.4 MB (beats 61.51%)  
**Submitted:** 2026-10-25T19:01:16.673Z  

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        
        for(auto &c:t)freq[c]++;
        int si=-1,ei=-1;
        int n=s.size();
        int m=t.size();
        int req=m;
        if(m>n)return "";
        int j=0;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(freq.count(c)){
                freq[c]--;
                if(freq[c]>=0)
                req--;
            }
            while(req==0 && j<=i){
                char ch=s[j];
                if(freq.count(ch)){
                    freq[ch]++;
                    if(freq[ch]>0)req++;
                }
                
                if((i-j+1) < len){
                    si=j;
                    ei=i;
                    len=(i-j+1);
                }
                j++;
            }
            
        }
        if(si!=-1 && ei!=-1)
        return s.substr(si,ei-si+1);
        return "";
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-window-substring/)