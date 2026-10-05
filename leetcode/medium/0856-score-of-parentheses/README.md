# Score of Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a balanced parentheses string `s`, return  *the  **score**  of the string*.

The  **score**  of a balanced parentheses string is based on the following rule:

- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.

 

 **Example 1:** 

```
Input: s = "()"
Output: 1

```

 **Example 2:** 

```
Input: s = "(())"
Output: 2

```

 **Example 3:** 

```
Input: s = "()()"
Output: 2

```

 

 **Constraints:** 

- 2 <= s.length <= 50
- s consists of only '(' and ')'.
- s is a balanced parentheses string.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.5 MB (beats 7.86%)  
**Submitted:** 2026-10-05T09:46:43.085Z  

```cpp
class Solution {
public:
    int solve(vector<int>&closing,string &s,int i,int j){
        int n=s.size();
        if((i+1)==j)return 1;
        if(i>=j)return 0;
        int inner=0;
        int k=i+1;
        while(k<j){
            inner+=solve(closing,s,k,closing[k]);
            k=closing[k]+1;
        }
        return 2*inner;
    }
    int scoreOfParentheses(string s) {
        vector<char>st;
        int n=s.size();
        vector<int>closing(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push_back(i);
            else {
                closing[st.back()]=i;
                st.pop_back();
            }
        }
        int ans=0;
        int i=0;
        while(i<n){
            ans+=solve(closing,s,i,closing[i]);
            i=closing[i]+1;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/score-of-parentheses/)