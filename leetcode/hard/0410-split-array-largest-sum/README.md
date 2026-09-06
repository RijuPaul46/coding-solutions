# Split Array Largest Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty subarrays such that the largest sum of any subarray is  **minimized**.

Return  *the minimized largest sum of the split*.

A  **subarray**  is a contiguous part of the array.

 

 **Example 1:** 

```
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

```

 **Example 2:** 

```
Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

```

 

 **Constraints:** 

- 1 <= nums.length <= 1000
- 0 <= nums[i] <= 106
- 1 <= k <= min(50, nums.length)

## Solution

**Language:** C++  
**Runtime:** 211 ms (beats 4.51%)  
**Memory:** 11 MB (beats 7.70%)  
**Submitted:** 2026-09-06T05:20:00.338Z  

```cpp
#include <bits/stdc++.h>
class Solution {
public:
    int dp[1001][51];
    int solve(int idx,vector<int>& nums, int k,vector<int>&pre){
        int n=nums.size();
        if(k==0){
            int a= pre[n-1];
            if(idx-1>=0)a-=pre[idx-1];
            return a;
        }
        if(idx>=n-1)return INT_MAX;
        auto &ref=dp[idx][k];
        if(ref!=-1)return ref;
        int sm=INT_MAX;
        int sum=0;
        for(int i=idx;i<n;i++){
            sum+=nums[i];
            sm=min(sm,max(sum,solve(i+1,nums,k-1,pre)));
            
        }
        return ref=sm;


    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k-1,pre);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/split-array-largest-sum/)