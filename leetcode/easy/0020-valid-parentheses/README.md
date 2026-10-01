# Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Every close bracket has a corresponding open bracket of the same type.

 

 **Example 1:** 

 **Input:**  s = "()"

 **Output:**  true

 **Example 2:** 

 **Input:**  s = "()[]{}"

 **Output:**  true

 **Example 3:** 

 **Input:**  s = "(]"

 **Output:**  false

 **Example 4:** 

 **Input:**  s = "([])"

 **Output:**  true

 **Example 5:** 

 **Input:**  s = "([)]"

 **Output:**  false

 

 **Constraints:** 

- 1 <= s.length <= 104
- s consists of parentheses only '()[]{}'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.8 MB (beats 66.83%)  
**Submitted:** 2026-10-01T06:23:58.802Z  

```cpp
class Solution {
public:
    bool isOpen(char c){
        return c=='(' || c=='{' || c=='[';
    }
    char opening(char c){
        if(c=='}')return '{';
        if(c==']')return '[';
        return '(';
    }
    bool isValid(string s) {
        vector<char>st;
        for(auto &c:s){
            if(isOpen(c)){
                st.push_back(c);
            }
            else{
                if(st.size()>0){
                    char open=opening(c);
                    if(st.back()!=open)return false;
                    else st.pop_back();
                }
                else return false;
            }
        }
        return st.size()==0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parentheses/)