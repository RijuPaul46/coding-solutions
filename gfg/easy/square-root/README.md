# Square Root

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a positive integer  **n,**  find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number.

 **Examples:** 

```
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.

```

```
Input: n = 11
Output: 3
Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
```

```
Input: n = 1
Output: 1
Explanation: 1 is a perfect square, so its square root is 1.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-06T08:28:27.599Z  

```cpp
class Solution {
  public:
    bool check(int x,int n){
        return x*x<=n;
    }
    int floorSqrt(int n) {
        // code here
        //we can find it in logn time .... 
        // concept let x=sqrt(n)
        // y<x  y*y<n  .... 
        int l=0,r=n;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,n)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/square-root/1)