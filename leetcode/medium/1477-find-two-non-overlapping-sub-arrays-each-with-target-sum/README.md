# Find Two Non-overlapping Sub-arrays Each With Target Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an array of integers `arr` and an integer `target`.

You have to find  **two non-overlapping sub-arrays**  of `arr` each with a sum equal `target`. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is  **minimum**.

Return  *the minimum sum of the lengths*  of the two required sub-arrays, or return `-1` if you cannot find such two sub-arrays.

 

 **Example 1:** 

```
Input: arr = [3,2,2,4,3], target = 3
Output: 2
Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.

```

 **Example 2:** 

```
Input: arr = [7,3,4,7], target = 7
Output: 2
Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.

```

 **Example 3:** 

```
Input: arr = [4,3,2,6,2,3,4], target = 6
Output: -1
Explanation: We have only one sub-array of sum = 6.

```

 

 **Constraints:** 

- 1 <= arr.length <= 105
- 1 <= arr[i] <= 1000
- 1 <= target <= 108

## Solution

**Language:** C++  
**Runtime:** 5 ms (beats 81.70%)  
**Memory:** 92.4 MB (beats 47.68%)  
**Submitted:** 2026-09-17T14:12:15.504Z  

```cpp
class Solution {
public:

    int minSumOfLengths(vector<int>& arr, int target) {
        // i need min length of subarray of sum=tgt ending at i-1
        // and starting at i .... then starting at i
        int mn=INT_MAX;
        int n=arr.size();
        vector<int>pre(n+1),suff(n+1);
        pre[0]=INT_MAX;
        int i=0,j=0;
        int sm=0;
        while(j<n){
            sm+=arr[j];
            while(sm>target && i<j){
                sm-=arr[i++];
            }
            if(sm==target){
                mn=min(mn,j-i+1);
            }
            pre[j+1]=mn;
            j++;
        }
        i=n-1,j=n-1;
        mn=INT_MAX;
        sm=0;
        while(i>=0){
            sm+=arr[i];
            while(sm>target && j>i){
                sm-=arr[j--];
            }
            if(sm==target){
                mn=min(mn,j-i+1);
            }
            suff[i--]=mn;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(pre[i]!=INT_MAX && suff[i]!=INT_MAX)
            ans=min(ans,pre[i]+suff[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)