# Valid Parenthesis String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s` containing only three types of characters: `'('`, `')'` and `' *'`, return `true`* if *`s`* is  **valid** *.

The following rules define a  **valid**  string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

 **Example 1:** 

```
Input: s = "()"
Output: true

```

 **Example 2:** 

```
Input: s = "(*)"
Output: true

```

 **Example 3:** 

```
Input: s = "(*))"
Output: true

```

 **Example 4:** 

```
Input: s = "("
Output: false

```

 

 **Constraints:** 

- 1 <= s.length <= 100
- s[i] is '(', ')' or '*'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.1 MB (beats 74.67%)  
**Submitted:** 2026-10-04T08:12:50.019Z  

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        vector<char>st;
        for(auto c:s){
            if(c=='(' || c=='*')st.push_back(c);
            else{
                int cnt=0;
                
                while(st.size()>0 && st.back()=='*'){st.pop_back();cnt++;}
                if(st.size()==0){
                    if(cnt>0){
                        cnt--;
                    }
                    else return false;
                }
                else{
                    if(st.back()=='('){
                        st.pop_back();
                    }
                    else if(st.back()==')'){
                        if(cnt>0){cnt--;}
                        else return false;
                    }
                }
                for(int i=0;i<cnt;i++)st.push_back('*');
            }
        }
        vector<char>st1;
        for(auto &c:st){
            if(c=='(')st1.push_back(c);
            else if(c=='*'){
                if(st1.size()>0)st1.pop_back();
            }
        }
        return st1.size()==0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)