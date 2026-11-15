# Number of Sub-arrays With Odd Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of integers `arr`, return  *the number of subarrays with an  **odd**  sum*.

Since the answer can be very large, return it modulo `109 + 7`.

 

Original
C++
 **Example 1:** 

```
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

```

 **Example 2:** 

```
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

```

 **Example 3:** 

```
Input: arr = [1,2,3,4,5,6,7]
Output: 16

```

 

 **Constraints:** 

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 21.1 MB  
**Submitted:** 2026-11-15T17:46:37.661Z  

```cpp
class Solution {
public:
    // 1 0 1 0 1 0 1
    
    #define ll long long
    ll mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        ll a=0,b=0,last=-1,ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
                ll temp1=a,temp2=b;
                b=temp1;
                a=temp2+(i-last);
                last=i;
                

            }
            ans=(ans+a)%mod;
            
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)