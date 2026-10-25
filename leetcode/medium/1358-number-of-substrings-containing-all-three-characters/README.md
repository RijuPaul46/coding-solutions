# Number of Substrings Containing All Three Characters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s` consisting only of characters  *a*,  *b*  and  *c*.

Return the number of substrings containing  **at least**  one occurrence of all these characters  *a*,  *b*  and  *c*.

 

 **Example 1:** 

```
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

```

 **Example 2:** 

```
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

```

 **Example 3:** 

```
Input: s = "abc"
Output: 1

```

 

 **Constraints:** 

- 3 <= s.length <= 5 x 104
- s only consists of 'a', 'b' or 'c' characters.

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 65.46%)  
**Memory:** 11 MB (beats 79.63%)  
**Submitted:** 2026-10-25T17:24:24.970Z  

```cpp
class Solution {
public:
    bool check(vector<int>&arr){
        for(int i=0;i<3;i++){
            if(arr[i]==0)return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        // for each index as ending index ... find the smallest index such that condition satisfy 
        // if i-1 already have x subarray .. then i will have +x 
        int n=s.size();
        int l=0;
        vector<int> arr(3,0);
        int cnt=0;
        for(int r=0;r<n;r++){
            if(s[r]=='a')arr[0]++;
            if(s[r]=='b')arr[1]++;
            if(s[r]=='c')arr[2]++;
            while(check(arr) && l<r){
                int idx=s[l]-'a';
                if(idx<3)arr[idx]--;
                l++;
            }
            cnt+=l;
        }
        return cnt;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)