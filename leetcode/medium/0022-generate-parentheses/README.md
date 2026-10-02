# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 30.41%)  
**Memory:** 17.3 MB (beats 7.36%)  
**Submitted:** 2026-10-02T16:18:50.902Z  

```cpp
class Solution {
public:
    vector<string> ans;
    void solve(int n,int open,int close,string str){
        if(open==n && close==n){
            ans.push_back(str);
            return;
        }
        // keep opening if open<n 
        string nstr=str+"(";
        if(open<n)solve(n,open+1,close,nstr);
        str.push_back(')');
        if(close<open)solve(n,open,close+1,str);
        return ;
    }
    vector<string> generateParenthesis(int n) {
        solve(n,0,0,"");
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)