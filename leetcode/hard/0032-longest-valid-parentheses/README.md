# Longest Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string containing just the characters `'('` and `')'`, return  *the length of the longest valid (well-formed) parentheses **substring*.

 

 **Example 1:** 

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

 **Example 2:** 

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

 **Example 3:** 

```
Input: s = ""
Output: 0

```

 

 **Constraints:** 

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 10.88%)  
**Memory:** 13.6 MB (beats 5.65%)  
**Submitted:** 2026-10-03T08:08:30.745Z  

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>valid(n,0);
        vector<int>st;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push_back(i);
            }
            else {
                if(st.size()>0 && s[st.back()]=='('){
                    valid[st.back()]=1;
                    valid[i]=1;
                    st.pop_back();
                }
            }
        }
        int streak=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(valid[i]){
                streak++;
            }
            else{
                mx=max(mx,streak);
                streak=0;
            }
        }
        mx=max(mx,streak);
        return mx;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)