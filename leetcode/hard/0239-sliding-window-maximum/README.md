# Sliding Window Maximum

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return  *the max sliding window*.

 

Original
C++
 **Example 1:** 

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

```

 **Example 2:** 

```
Input: nums = [1], k = 1
Output: [1]

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104
- 1 <= k <= nums.length

## Solution

**Language:** C++  
**Runtime:** 23 ms (beats 71.44%)  
**Memory:** 139 MB (beats 80.94%)  
**Submitted:** 2026-11-13T21:16:35.581Z  

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        vector<int>ans;
        int j=0;
        for(int i=0;i<n;i++){
            
                while(!dq.empty() && nums[dq.back()]<= nums[i])dq.pop_back();
                dq.push_back(i);
            if(i>=k){
                if(dq.front()==j)dq.pop_front();
                j++;
            }
            if(i>=(k-1))ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/sliding-window-maximum/)