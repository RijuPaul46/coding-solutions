# Count Non-Decreasing Subarrays After K Operations

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array `nums` of `n` integers and an integer `k`.

For each subarray of `nums`, you can apply  **up to**  `k` operations on it. In each operation, you increment any element of the subarray by 1.

 **Note**  that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make  **non-decreasing**  ​​​​​after performing at most `k` operations.

An array is said to be  **non-decreasing**  if each element is greater than or equal to its previous element, if it exists.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [6,3,1,2,4,4], k = 7

 **Output:**  17

 **Explanation:** 

Out of all 21 possible subarrays of `nums`, only the subarrays `[6, 3, 1]`, `[6, 3, 1, 2]`, `[6, 3, 1, 2, 4]` and `[6, 3, 1, 2, 4, 4]` cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is `21 - 4 = 17`.

 **Example 2:** 

 **Input:**  nums = [6,3,1,3,6], k = 4

 **Output:**  12

 **Explanation:** 

The subarray `[3, 1, 3, 6]` along with all subarrays of `nums` with three or fewer elements, except `[6, 3, 1]`, can be made non-decreasing after `k` operations. There are 5 subarrays of a single element, 4 subarrays of two elements, and 2 subarrays of three elements except `[6, 3, 1]`, so there are `1 + 5 + 4 + 2 = 12` subarrays that can be made non-decreasing.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= k <= 109

## Solution

**Language:** C++  
**Runtime:** 325 ms (beats 26.00%)  
**Memory:** 216.8 MB (beats 38.00%)  
**Submitted:** 2026-11-13T21:19:32.118Z  

```cpp
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long operations = 0;
        // Maintain the window maximum with a priority queue
        priority_queue<pair<int, int>> q;
        // Record the set of elements covered by this index
        vector<vector<int>> cnt(n);
        // Index of the first greater-or-equal element to the right
        vector<int> pos(n, n);
        // Decreasing monotonic stack
        stack<int> st;

        for (int left = 0, right = 0; right < n; right++) {
            // Maintain the monotonic stack
            while (!st.empty() && nums[right] >= nums[st.top()]) {
                pos[st.top()] = right;
                st.pop();
            }
            // The stack top is the nearest greater element to the left of
            // nums[right]
            if (!st.empty()) {
                cnt[st.top()].push_back(right);
            }
            st.push(right);

            // The priority queue front is the window maximum
            q.emplace(nums[right], right);
            // Adding nums[right] increases the operation count
            operations += max(0, q.top().first - nums[right]);

            // The minimum operation count exceeds k; shrink the window
            while (operations > k) {
                // Removing nums[left] from the window decreases the operation
                // count
                for (int i : cnt[left]) {
                    // Subtract the contribution
                    operations -=
                        (long long)(nums[left] - nums[i]) *
                        (min(pos[i], right + 1) - i);
                }
                left++;
            }

            // Remove elements with indices less than left from the priority
            // queue
            while (!q.empty() && q.top().second < left) {
                q.pop();
            }

            // There are right - left + 1 valid contiguous subarrays ending at
            // right
            ans += right - left + 1;
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/)