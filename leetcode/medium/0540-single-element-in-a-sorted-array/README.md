# Single Element in a Sorted Array

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return  *the single element that appears only once*.

Your solution must run in `O(log n)` time and `O(1)` space.

 

 **Example 1:** 

```
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

```

 **Example 2:** 

```
Input: nums = [3,3,7,7,10,11,11]
Output: 10

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 26.1 MB (beats 72.97%)  
**Submitted:** 2026-10-04T17:38:04.482Z  

```cpp
class Solution {
public:
    // we can eliminate portion where elm are present in pair and starting point is odd ... mean left has that elm and the right part is useless ..
    //if pair starting point is even ...mean left has no such elm .. discard that portion
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int x=nums[mid];
            int sp=-1;
            if(mid-1>=0 && nums[mid-1]==nums[mid]){
                sp=mid-1;
            }
            if(mid+1<n && nums[mid+1]==nums[mid]){
                sp=mid;
            }
            if(sp==-1)return x;
            if(sp%2==0){
                l=mid+1;
            }
            else h=mid-1;
        }
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/single-element-in-a-sorted-array/)