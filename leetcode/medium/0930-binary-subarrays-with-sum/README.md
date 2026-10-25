# Binary Subarrays With Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary array `nums` and an integer `goal`, return  *the number of non-empty  **subarrays**  with a sum*  `goal`.

A  **subarray**  is a contiguous part of the array.

 

 **Example 1:** 

```
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

```

 **Example 2:** 

```
Input: nums = [0,0,0,0,0], goal = 0
Output: 15

```

 

 **Constraints:** 

- 1 <= nums.length <= 3 * 104
- nums[i] is either 0 or 1.
- 0 <= goal <= nums.length

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 64.25%)  
**Memory:** 32.6 MB (beats 81.16%)  
**Submitted:** 2026-10-25T16:04:02.492Z  

```cpp
class Solution {
public:
    // by two pointer approach we can easily calculate number of subarray having sum<=x easily ... because we shrink the left pointer untill the sum>goal ... so we stop at the largest subarray having sum=goal so all inside subarray will have sum<=goal ...and for our answer we can do 
    // no of subarray with sum<=goal - no of subarray with sum<=goal-1 
    int subarray(vector<int>&nums,int goal){
        int n=nums.size();
        int l=0;
        int sm=0;
        int cnt=0;
        for(int r=0;r<n;r++){
            sm+=nums[r];
            while(sm > goal && l<r){
                sm-=nums[l++];
            }
            if(sm <=goal)
            cnt+=(r-l+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=subarray(nums,goal);
        int b=0;
        if((goal-1) >=0)
        b=subarray(nums,goal-1);
        return a-b;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/)