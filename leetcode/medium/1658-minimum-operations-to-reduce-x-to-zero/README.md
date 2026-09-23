# Minimum Operations to Reduce X to Zero

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this  **modifies**  the array for future operations.

Return  *the  **minimum number**  of operations to reduce* `x`  *to  **exactly***  `0`  *if it is possible**, otherwise, return* `-1`.

 

 **Example 1:** 

```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

```

 **Example 2:** 

```
Input: nums = [5,6,7,8,9], x = 4
Output: -1

```

 **Example 3:** 

```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 104
- 1 <= x <= 109

## Solution

**Language:** C++  
**Runtime:** 223 ms (beats 9.47%)  
**Memory:** 172.3 MB (beats 7.59%)  
**Submitted:** 2026-09-23T06:54:35.936Z  

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int>pre;
        int n=nums.size();
        pre[0]=-1;
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            pre[sm]=i;
        }
        sm=0;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int rem=x-sm;
            if(pre.count(rem)){
                int idx=pre[rem];
                if(idx<=i){
                    ans=min(ans,idx+n-i);
                }
            }
            sm+=nums[i];
        }
        return ans==INT_MAX?-1:ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)