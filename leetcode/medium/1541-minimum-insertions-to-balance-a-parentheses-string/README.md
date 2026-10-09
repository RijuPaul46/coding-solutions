# Minimum Insertions to Balance a Parentheses String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is  **balanced**  if:

- Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
- Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

- For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return  *the minimum number of insertions*  needed to make `s` balanced.

 

 **Example 1:** 

```
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.

```

 **Example 2:** 

```
Input: s = "())"
Output: 0
Explanation: The string is already balanced.

```

 **Example 3:** 

```
Input: s = "))())("
Output: 3
Explanation: Add '(' to match the first '))', Add '))' to match the last '('.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of '(' and ')' only.

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.8 MB  
**Submitted:** 2026-10-09T20:39:38.642Z  

```cpp
#define db double
class Solution {
public:
    int minInsertions(string s) {
        db score=0;
        int need=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(score<0){
                    db val=abs(score);
                    db add=floor(val)+2*((val-floor(val))>0);
                    need+=add;
                    score=0;
                }
                score+=1.0;
            }
            else{
                score-=0.5;
            }
        }
        if(score<0)
        need+=floor(abs(score))+2*(abs(score)-floor(abs(score)));
        else need+=2*score;
        return (int)need;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)