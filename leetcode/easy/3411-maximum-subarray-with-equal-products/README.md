# Maximum Subarray With Equal Products

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given an array of  **positive**  integers `nums`.

An array `arr` is called  **product equivalent**  if `prod(arr) == lcm(arr) * gcd(arr)`, where:

- prod(arr) is the product of all elements of arr.
- gcd(arr) is the GCD of all elements of arr.
- lcm(arr) is the LCM of all elements of arr.

Return the length of the  **longest**   **product equivalent**  subarray of `nums`.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [1,2,1,2,1,1,1]

 **Output:**  5

 **Explanation:**  

The longest product equivalent subarray is `[1, 2, 1, 1, 1]`, where `prod([1, 2, 1, 1, 1]) = 2`, `gcd([1, 2, 1, 1, 1]) = 1`, and `lcm([1, 2, 1, 1, 1]) = 2`.

 **Example 2:** 

 **Input:**  nums = [2,3,4,5,6]

 **Output:**  3

 **Explanation:**  

The longest product equivalent subarray is `[3, 4, 5].`

 **Example 3:** 

 **Input:**  nums = [1,2,3,1,4,5,1]

 **Output:**  5

 

 **Constraints:** 

- 2 <= nums.length <= 100
- 1 <= nums[i] <= 10

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 28 MB (beats 73.31%)  
**Submitted:** 2026-11-24T17:22:42.275Z  

```cpp
class Solution {
public:
    #define ll long long
    //lcm(a,b,c)=lcm(lcm(a,b),c)
    //same for gcd also
    ll lcm(ll a, ll b){
        return (a*b)/gcd(a,b);
    } 
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ll prdt=1,_lcm=1,_gd=0;
            for(int j=i;j<n;j++){
                prdt*=1ll*nums[j];
                
                _lcm=lcm(_lcm,nums[j]);
                _gd=gcd(_gd,nums[j]);
                if(prdt>(_gd*_lcm))break;
                if(prdt==(_lcm*_gd)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-subarray-with-equal-products/)