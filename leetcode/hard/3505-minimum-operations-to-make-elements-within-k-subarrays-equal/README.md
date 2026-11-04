# Minimum Operations to Make Elements Within K Subarrays Equal

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums` and two integers, `x` and `k`. You can perform the following operation any number of times (**including zero**):

- Increase or decrease any element of nums by 1.

Return the  **minimum**  number of operations needed to have  **at least**  `k`  *non-overlapping subarrays*  of size  **exactly**  `x` in `nums`, where all elements within each subarray are equal.

 

 **Example 1:** 

 **Input:**  nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2

 **Output:**  8

 **Explanation:** 

- Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
- Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
- Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.

 **Example 2:** 

 **Input:**  nums = [9,-2,-2,-2,1,5], x = 2, k = 2

 **Output:**  3

 **Explanation:** 

- Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
- Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.

 

 **Constraints:** 

- 2 <= nums.length <= 105
- -106 <= nums[i] <= 106
- 2 <= x <= nums.length
- 1 <= k <= 15
- 2 <= k * x <= nums.length

## Solution

**Language:** C++  
**Runtime:** 929 ms (beats 69.44%)  
**Memory:** 404 MB (beats 38.89%)  
**Submitted:** 2026-11-04T19:41:04.753Z  

```cpp
class Solution {
public:
    #define ll long long
    // first i have to run a sliding window which calculate number of operation needed to make all equal ... i have to carry info ei, op needed ...
    // then run a dp ... if i have selected take or skip n*k 
    // sliding window to calculate number of operation needed 
    // brute force will be n*x-x2  x=n/2 t.c=n2/4 
    // from prev median how much changed let say increased by y then operation +=(no of elm less than median)*y -= no of elm greater than median*y  operation=operation+(no of elm <median - no of elm >med)*y
    // then i have to adjust for discarded elm too ... but set cannot find median iterator 
    // B.S on answer ... because let say x is min number of operation needed ... then x+1 will also satisfy this 
    //k<=15 ... i need to select only about 15 subarray starting point
    // dp[i][k]

    long long minOperations(vector<int>& nums, int x, int k) {
              int n = nums.size();
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        unordered_map<int, int> delayed;
        int leftSize = 0, rightSize = 0;
        vector<long long> ops(n);
        long long sumL = 0, sumR = 0;

        auto prune = [&](auto& heap) {
            while (!heap.empty()) {
                if (delayed[heap.top()]) {
                    --delayed[heap.top()];
                    heap.pop();
                } else {
                    break;
                }
            }
        };

        auto balance = [&]() {
            if (leftSize > rightSize + 1) {
                int num = left.top();
                right.push(num);
                sumR += num;
                sumL -= num;
                left.pop();
                ++rightSize;
                --leftSize;
                prune(left);
            } else if (rightSize > leftSize) {
                int num = right.top();
                left.push(num);
                sumL += num;
                sumR -= num;
                right.pop();
                ++leftSize;
                --rightSize;
                prune(right);
            }
        };

        for (int i = 0; i < n; i++) {
            if (left.empty() || nums[i] <= left.top()) {
                left.push(nums[i]);
                ++leftSize;
                sumL += nums[i];
            } else {
                right.push(nums[i]);
                ++rightSize;
                sumR += nums[i];
            }
            balance();
            if (i >= x) {
                int num = nums[i - x];
                if (num <= left.top()) {
                    --leftSize;
                    ++delayed[num];
                    sumL -= num;
                    if (num == left.top()) {
                        prune(left);
                    }
                } else {
                    --rightSize;
                    ++delayed[num];
                    sumR -= num;
                    if (num == right.top()) {
                        prune(right);
                    }
                }
                balance();
            }

            if (i >= x - 1) {
                long long mid = left.top();
                ops[i] = sumR - sumL + mid * (leftSize - rightSize);
            }
        }

        vector<vector<long long>> dp(n, vector<long long>(k + 1, LLONG_MAX));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[x - 1][j] = ops[x - 1];
            } else {
                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
            }
        }
        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i < n; i++) {
                dp[i][j] = min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
            }
        }

        return dp[n - 1][k];
        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/)