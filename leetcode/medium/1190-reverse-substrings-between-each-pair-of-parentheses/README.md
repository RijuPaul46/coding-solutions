# Reverse Substrings Between Each Pair of Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should  **not**  contain any brackets.

 

 **Example 1:** 

```
Input: s = "(abcd)"
Output: "dcba"

```

 **Example 2:** 

```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

```

 **Example 3:** 

```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

```

 

 **Constraints:** 

- 1 <= s.length <= 2000
- s only contains lower case English characters and parentheses.
- It is guaranteed that all parentheses are balanced.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.5 MB (beats 6.69%)  
**Submitted:** 2026-09-27T07:15:58.241Z  

```cpp
class Solution {
public:
    string solve(string &s,int l,int r,unordered_map<int,int> &mp){
        int n=s.size();
        if(l>r)return "";
        string str="";
        for(int i=l;i<=r;i++){
            if(s[i]=='('){
                int next=mp[i];
                string ans=solve(s,i+1,next-1,mp);
                reverse(ans.begin(),ans.end());
                str+=ans;
                i=next;
            }
            else str+=s[i];
        }
        // reverse(str.begin(),str.end());
        return str;
    }
    // string solve(string &s,int i,int j){
    //     int n=s.size();
    //     string str="";
    //     for(int k=i;k<=j;k++){
    //         if(s[k]=='('){
    //             // string key="";
    //             int score=1;
    //             int next=k+1;
    //             while(next<=j && score>0){
    //                 // key+=s[next];
    //                 if(s[next]=='(')score++;
    //                 if(s[next]==')')score--;
    //                 next++;
    //             }
                
    //             string ans=solve(s,k+1,next-2);
    //             str+=ans;
    //             k=next;
    //         }
    //         else str+=s[k];
    //     }
        
    //     reverse(str.begin(),str.end());
    //     return str;
    // }
    string reverseParentheses(string s) {
        int n=s.size();
        // first find all the matching pair so that it need not to be recalculated....
        vector<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push_back(i);
            else if(s[i]==')'){
                int tp=st.back();
                mp[tp]=i;
                st.pop_back();
            }
        }
        return solve(s,0,n-1,mp);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)