# Minimum XOR Path in a Grid

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a 2D integer array `grid` of size `m * n`.

You start at the  **top-left**  cell `(0, 0)` and want to reach the  **bottom-right**  cell `(m - 1, n - 1)`.

At each step, you  **may**  move either  **right or down**.

The  **cost**  of a path is defined as the  **bitwise XOR**  of all the values in the cells along that path,  **including**  the start and end cells.

Return the  **minimum**  possible XOR value among all valid paths from `(0, 0)` to `(m - 1, n - 1)`.

 

 **Example 1:** 

 **Input:**  grid = [[1,2],[3,4]]

 **Output:**  6

 **Explanation:** 

There are two valid paths:

- (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
- (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6

The minimum XOR value among all valid paths is 6.

 **Example 2:** 

 **Input:**  grid = [[6,7],[5,8]]

 **Output:**  9

 **Explanation:** 

There are two valid paths:

- (0, 0) → (0, 1) → (1, 1) with XOR: 6 XOR 7 XOR 8 = 9
- (0, 0) → (1, 0) → (1, 1) with XOR: 6 XOR 5 XOR 8 = 11

The minimum XOR value among all valid paths is 9.

 **Example 3:** 

 **Input:**  grid = [[2,7,5]]

 **Output:**  0

 **Explanation:** 

There is only one valid path:

- (0, 0) → (0, 1) → (0, 2) with XOR: 2 XOR 7 XOR 5 = 0

The XOR value of this path is 0, which is the minimum possible.

 

 **Constraints:** 

- 1 <= m == grid.length <= 1000
- 1 <= n == grid[i].length <= 1000
- m * n <= 1000
- 0 <= grid[i][j] <= 1023​

## Solution

**Language:** C++  
**Runtime:** 534 ms (beats 32.65%)  
**Memory:** 364.1 MB (beats 38.84%)  
**Submitted:** 2026-10-28T18:50:08.287Z  

```cpp
class Solution {
public:
    // void solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){

    // }
    //max xor value can be 1024 
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,0)));
        dp[0][0][grid[0][0]]=1;
        for(int i=1;i<n;i++){
            for (int j=0;j<1024;j++){
                if(dp[0][i-1][j]){
                int a=j^grid[0][i];
                dp[0][i][a]=1;
                }
            }
            
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<1024;j++){
                if(dp[i-1][0][j]){
                    int a=j^grid[i][0];
                    dp[i][0][a]=1;
                }
            }
            
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                for(int k=0;k<1024;k++){
                    if(dp[i][j-1][k] || dp[i-1][j][k]){
                        int a=k^grid[i][j];
                        dp[i][j][a]=1;
                    }
                }
            }
        }
        for(int k=0;k<1024;k++){
            if(dp[m-1][n-1][k])return k;
        }
        return 0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-xor-path-in-a-grid/)