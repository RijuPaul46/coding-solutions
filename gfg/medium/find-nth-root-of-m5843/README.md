# Nth Root of M

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then return -1.

 **Examples :** 

```
Input: n = 3, m = 8
Output: 2
Explanation: 23 = 8

```

```
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
```

```
Input: n = 4, m = 16
Output: 2
Explanation: 24 = 16
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-11T19:11:04.935Z  

```cpp
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        // we can apply binary search on answer ... 
        // let x be the nth root of m ..
        // so all number y<x power(y,n)<=m.... 
        // monotonic ... T T T F F ... will exceed
        int l=0;
        int h=m;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if((int)pow(mid,n)<=m){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            
        }
        if((int)pow(ans,n)==m)return ans;
        return -1;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1)