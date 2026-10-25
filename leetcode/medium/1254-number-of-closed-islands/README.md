# Number of Closed Islands

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An  *island*  is a maximal 4-directionally connected group of `0s` and a  *closed island*  is an island  **totally**  (all left, top, right, bottom) surrounded by `1s.`

Return the number of  *closed islands*.

 

 **Example 1:** 

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

 **Example 2:** 

```
Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

```

 **Example 3:** 

```
Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

```

 

 **Constraints:** 

- 1 <= grid.length, grid[0].length <= 100
- 0 <= grid[i][j] <=1

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 19.35%)  
**Memory:** 18.3 MB (beats 10.74%)  
**Submitted:** 2026-10-25T18:02:30.657Z  

```cpp
class Solution {
public:
    // for 0 if any side is boundary of grid then only it is not closed 
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<int>>& grid,vector<vector<int>> &visited,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        bool flag=true;
        queue<pair<int,int>> q;
        visited[r][c]=true;
        q.push({r,c});
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dir[i][0];
                int ny=y+dir[i][1];
                if(nx<0 || nx>=m || ny<0 || ny>=n){
                    flag=false;
                }
                else{
                    if(grid[nx][ny]!=1 && !visited[nx][ny]){
                        visited[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    cnt+=find(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/number-of-closed-islands/)