# Count Islands With Total Value Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` matrix `grid` and a positive integer `k`. An  **island**  is a group of  **positive**  integers (representing land) that are  **4-directionally**  connected (horizontally or vertically).

The  **total value**  of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value  **divisible by**  `k`.

 

 **Example 1:** 

 **Input:**  grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

 **Output:**  2

 **Explanation:** 

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

 **Example 2:** 

 **Input:**  grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

 **Output:**  6

 **Explanation:** 

The grid contains six islands, each with a total value that is divisible by 3.

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 0 <= grid[i][j] <= 106
- 1 <= k <= 106

## Solution

**Language:** C++  
**Runtime:** 179 ms (beats 14.13%)  
**Memory:** 207.7 MB (beats 15.21%)  
**Submitted:** 2026-10-26T10:35:59.494Z  

```cpp
class Solution {
public:
    #define ll long long 
    ll mod;
    int  dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int bfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& visited){
        ll sm=0;
        int m=grid.size();
        int n=grid[0].size();
        visited[r][c]=true;
        queue<pair<int,int>> q;
        q.push({r,c});
        sm+=grid[r][c];
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && grid[nx][ny]>0){
                    visited[nx][ny]=1;
                    sm=(sm+grid[nx][ny])%mod;
                    q.push({nx,ny});
                }
            }
        }
        return sm;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        mod=1ll*k;
        vector<vector<int>> visited(m,vector<int>(n));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]>0){
                    ll sm=bfs(i,j,grid,visited);
                    if(sm%k ==0 )cnt++;
                }
            }
        }
        return cnt;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)