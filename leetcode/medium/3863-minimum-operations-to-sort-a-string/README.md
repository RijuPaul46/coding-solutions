# Minimum Operations to Sort a String

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any  **substring**  of `s` that is  **not**  the entire string and  **sort**  it in  **non-descending alphabetical**  order.

Return the  **minimum**  number of operations required to make `s` sorted in  **non-descending**  order. If it is not possible, return -1.

 

 **Example 1:** 

 **Input:**  s = "dog"

 **Output:**  1

 **Explanation:** ​​​​​​​

- Sort substring "og" to "go".
- Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.

 **Example 2:** 

 **Input:**  s = "card"

 **Output:**  2

 **Explanation:** 

- Sort substring "car" to "acr", so s = "acrd".
- Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.

 **Example 3:** 

 **Input:**  s = "gf"

 **Output:**  -1

 **Explanation:** 

- It is impossible to sort s under the given constraints. Thus, the answer is -1.

 

 **Constraints:** 

- 1 <= s.length <= 105
- s consists of only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 85 ms (beats 26.99%)  
**Memory:** 32 MB (beats 23.45%)  
**Submitted:** 2026-10-21T19:05:03.882Z  

```cpp
class Solution {
public:
    //ans could be 1 2 or -1
    //if first or last .... any of them is in correct pos and is 1
    bool balanced(vector<int>&freq){
        for(auto &x:freq)if(x!=0)return false;
        return true;
    }
    int minOperations(string s) {
        int n=s.size();
        string str=s;
        sort(str.begin(),str.end());
        if(s==str)return 0;
        if((s[0]==str[0]) || s[n-1]==str[n-1])return 1;
        if(n==2){
            return -1;
        }
        char mn=str[0],mx=str[n-1];
        bool mni=true,mxi=true;
        for(int i=0;i<n;i++){
            if(i<n-1){
                if(s[i]==mn){
                    mni=false;
                    break;
                }
            }
            if(i>0){
                if(s[i]==mx){
                    mxi=false;
                    break;
                }
            }
        }
        if(mxi && mni)return 3;
        // if(str[0]==s[n-1] && str[n-1]==s[0])return 3;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            freq[str[i]-'a']--;
            if(balanced(freq))return 2;
        }
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-sort-a-string/)