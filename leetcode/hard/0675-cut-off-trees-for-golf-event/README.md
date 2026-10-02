# Cut Off Trees for Golf Event

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an `m x n` matrix. In this matrix:

- 0 means the cell cannot be walked through.
- 1 represents an empty cell that can be walked through.
- A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.

In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.

You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes `1` (an empty cell).

Starting from the point `(0, 0)`, return  *the minimum steps you need to walk to cut off all the trees*. If you cannot cut off all the trees, return `-1`.

 **Note:**  The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.

 

 **Example 1:** 

```
Input: forest = [[1,2,3],[0,0,4],[7,6,5]]
Output: 6
Explanation: Following the path above allows you to cut off the trees from shortest to tallest in 6 steps.

```

 **Example 2:** 

```
Input: forest = [[1,2,3],[0,0,0],[7,6,5]]
Output: -1
Explanation: The trees in the bottom row cannot be accessed as the middle row is blocked.

```

 **Example 3:** 

```
Input: forest = [[2,3,4],[0,0,5],[8,7,6]]
Output: 6
Explanation: You can follow the same path as Example 1 to cut off all the trees.
Note that you can cut off the first tree at (0, 0) before making any steps.

```

 

 **Constraints:** 

- m == forest.length
- n == forest[i].length
- 1 <= m, n <= 50
- 0 <= forest[i][j] <= 109
- Heights of all trees are distinct.

## Solution

**Language:** C++  
**Runtime:** 655 ms (beats 49.61%)  
**Memory:** 250.6 MB (beats 50.08%)  
**Submitted:** 2026-10-02T20:55:56.166Z  

```cpp
class Solution {
public:
    #define pr pair<int,int>
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int step(pr src,pr dst,vector<vector<int>>&forest){
    int m=forest.size();
    int n=forest[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    auto [sr,sc]=src;
    if(forest[sr][sc]==0)return -1;
    visited[sr][sc]=1;
    queue<pr>q;
    
    q.push(src);
    
    int cnt=0;
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto nd=q.front();
            auto [x,y]=nd;
            if(nd==dst){
                forest[x][y]=1;
                return cnt;}
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && forest[nx][ny]!=0 && !visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        cnt++;
    }
    return -1;
}
    int cutOffTree(vector<vector<int>>& forest) {
         int m=forest.size();
    int n=forest[0].size();
    vector<pair<int,pr>> arr;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int val=forest[i][j];
            if(val>1){
                arr.push_back({val,make_pair(i,j)});
            }
        }
    }
    sort(arr.begin(),arr.end());
    pr src={0,0};
    int stp=0;
    for(int i=0;i<(int)arr.size();i++){
        pr dst=arr[i].second;
        int st=step(src,dst,forest);
        if(st==-1)return -1;
        stp+=st;
        src=arr[i].second;
    }
    return stp;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/cut-off-trees-for-golf-event/)