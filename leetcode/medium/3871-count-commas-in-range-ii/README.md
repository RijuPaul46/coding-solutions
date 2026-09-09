# Count Commas in Range II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer `n`.

Return the  **total**  number of commas used when writing all integers from `[1, n]` (inclusive) in  **standard**  number formatting.

In  **standard**  formatting:

- A comma is inserted after every three digits from the right.
- Numbers with fewer than 4 digits contain no commas.

 

 **Example 1:** 

 **Input:**  n = 1002

 **Output:**  3

 **Explanation:** 

The numbers `"1,000"`, `"1,001"`, and `"1,002"` each contain one comma, giving a total of 3.

 **Example 2:** 

 **Input:**  n = 998

 **Output:**  0

 **Explanation:** 

 **​​​​​​​** All numbers from 1 to 998 have fewer than four digits. Therefore, no commas are used.

 

 **Constraints:** 

- 1 <= n <= 1015

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.3 MB (beats 7.73%)  
**Submitted:** 2026-09-09T18:59:24.858Z  

```cpp
#define ll long long
class Solution {
public:

    long long countCommas(long long n) {
        ll d=0;
        ll temp=n;
        while(temp>0){
            d++;
            temp/=10;
        }
        if(d<4)return 0;
        ll ans=0;
        for(int i=4;i<d;i++){
            ans=ans+9*pow(10,i-1)*((i-1)/3);
        }
        ans+=((d-1)/3)*(n-pow(10,d-1)+1);
        return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-commas-in-range-ii/)