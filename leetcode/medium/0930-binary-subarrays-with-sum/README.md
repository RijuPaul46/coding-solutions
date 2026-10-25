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
**Runtime:** 2 ms (beats 58.37%)  
**Memory:** 34.2 MB (beats 37.03%)  
**Submitted:** 2026-10-25T15:43:22.826Z  

```cpp
class Solution {
public:
    //for each index record next 1 is where 
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>nxt(n,n);
        vector<int>st;
        for(int i=0;i<n;i++){
            if(nums[i]==0)st.push_back(i);
            else{
                while(!st.empty()){
                    nxt[st.back()]=i;
                    st.pop_back();
                }
            }

        }
        int l=0;
        int cnt=0,sm=0;
        for(int r=0;r<n;r++){
            sm+=nums[r];
            while(sm>goal && l<r){
                sm-=nums[l++];
            }
            if(sm==goal){
                if(nums[l]==0){
                int next=min(r,nxt[l]);
                cnt+=(next-l+1);
                }
                else cnt++;
            }
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/)