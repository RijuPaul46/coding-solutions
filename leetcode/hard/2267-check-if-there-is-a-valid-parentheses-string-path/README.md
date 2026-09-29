# Check if There Is a Valid Parentheses String Path

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A parentheses string is a  **non-empty**  string consisting only of `'('` and `')'`. It is  **valid**  if  **any**  of the following conditions is  **true** :

- It is ().
- It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
- It can be written as (A), where A is a valid parentheses string.

You are given an `m x n` matrix of parentheses `grid`. A  **valid parentheses string path**  in the grid is a path satisfying  **all**  of the following conditions:

- The path starts from the upper left cell (0, 0).
- The path ends at the bottom-right cell (m - 1, n - 1).
- The path only ever moves down or right.
- The resulting parentheses string formed by the path is valid.

Return `true`  *if there exists a  **valid parentheses string path**  in the grid.*  Otherwise, return `false`.

 

 **Example 1:** 

```
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

```

 **Example 2:** 

```
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- grid[i][j] is either '(' or ')'.

## Solution

**Language:** C++  
**Runtime:** 97 ms (beats 70.92%)  
**Memory:** 34.6 MB (beats 48.61%)  
**Submitted:** 2026-09-29T08:26:25.746Z  

```cpp
class Solution {
public:
    int dp[100][100][400];
    bool solve(vector<vector<char>>& grid,int r,int c,int score){
        int m=grid.size();
        int n=grid[0].size();
        int mask=score+200;
        int nscore=score+(grid[r][c]=='('?1:-1);
        
        if(r==m-1 && c==n-1){
            return nscore==0;
        }
        if(nscore<0)return false;
        auto &ref=dp[r][c][mask];
        if(ref!=-1)return ref;
        bool right=false;
        if(c+1<n)right=solve(grid,r,c+1,nscore);
        if(right)return ref=right;
        bool down=false;
        if(r+1<m)down=solve(grid,r+1,c,nscore);
        return ref=down;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0]==')')return false;
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,0);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)