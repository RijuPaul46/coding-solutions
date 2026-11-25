# Smallest Unique Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums`.

Find the  **minimum** length of a subarray that is  **not**   **identical**  to any other  **subarray**  in `nums`.

Return an integer denoting the  **minimum possible length**  of such a  **subarray**.

Two  **subarrays**  are considered identical if they have the same length and the same elements in corresponding positions.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [3,3,3]

 **Output:**  3

 **Explanation:** 

- Subarrays of length 1: [3] → appears 3 times
- Subarrays of length 2: [3, 3] → appears 2 times
- Subarrays of length 3: [3, 3, 3] → appears once

The subarray `[3, 3, 3]` is unique, so the smallest unique subarray length is 3.

 **Example 2:** 

 **Input:**  nums = [2,1,2,3,3]

 **Output:**  1

 **Explanation:** 

Subarrays of length 1:

- [2] → appears 2 times
- [1] → appears once
- [3] → appears 2 times
The subarray `[1]` is unique, so the smallest unique subarray length is 1.

 **Example 3:** 

 **Input:**  nums = [1,1,2,2,1]

 **Output:**  2

 **Explanation:** 

Subarrays of length 1:

- [1] → appears 3 times
- [2] → appears 2 times

Subarrays of length 2:

- [1, 1] → appears once
- [1, 2] → appears once
- [2, 2] → appears once
- [2, 1] → appears once
There is at least one subarray of length 2 that is unique, so the smallest unique subarray length is 2.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 2837 ms (beats 5.81%)  
**Memory:** 371.7 MB (beats 59.30%)  
**Submitted:** 2026-11-25T17:35:04.838Z  

```cpp
class Solution {
public:
    #define ll long long
    ll mod=1e9+7;
    ll base=1e5+1;
    ll pow(ll n,ll r){
        if(r==0)return 1;
        if(r%2==0){
            return pow((n*n)%mod,r/2);
        }
        return (n*pow((n*n)%mod,r/2))%mod;
    }
    ll modInv(ll n){
        return pow(n,mod-2)%mod;
    }
    bool check(int len,vector<int>&nums){
        //use rolling hash
        unordered_map<ll,ll>visited;
        
        int n=nums.size();
        int l=0;
        ll num=0;
        for(int i=0;i<n;i++){
            
            num= (num+nums[i]*pow(base,i-l+1))%mod;
            
             if(i>=(len-1)){
                
                visited[num]++;
                num=(num-(1ll*nums[l++]*base)%mod +mod)%mod;
                num=(num*modInv(base))%mod;
            }
        }
        for(auto &[_,count]:visited){
            if(count==1)return true;
        }
        return false;

    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-unique-subarray/)