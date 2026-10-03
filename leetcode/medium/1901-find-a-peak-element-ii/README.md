# Find a Peak Element II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A  **peak**  element in a 2D grid is an element that is  **strictly greater**  than all of its  **adjacent** neighbors to the left, right, top, and bottom.

Given a  **0-indexed**  `m x n` matrix `mat` where  **no two adjacent cells are equal**, find  **any**  peak element `mat[i][j]` and return  *the length 2 array* `[i,j]`.

You may assume that the entire matrix is surrounded by an  **outer perimeter**  with the value `-1` in each cell.

You must write an algorithm that runs in `O(m log(n))` or `O(n log(m))` time.

 

 **Example 1:** 

```
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

```

 **Example 2:** 

```
Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

```

 

 **Constraints:** 

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 500
- 1 <= mat[i][j] <= 105
- No two adjacent cells are equal.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 50.9 MB (beats 11.02%)  
**Submitted:** 2026-10-03T09:55:08.806Z  

```cpp
class Solution {
public:
    // it is surrounded by -1 so there must be a peak inside MVT 
    // if right >curr there must be a peak in right side ...because 
    // let say that peak is in the same row ... then we got it 
    // if it is not in same row .. then there must be some elm 
    // which is bigger than that .. and it will be obviously in right side 
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l/2);
            // find max elm idx of that column
            int mx=0;
            for(int i=1;i<m;i++){
                if(mat[i][mid]>mat[mx][mid])mx=i;
            }
            int right=-1,left=-1;
            int curr=mat[mx][mid];
            if(mid+1<n)right=mat[mx][mid+1];
            if(mid-1>=0)left=mat[mx][mid-1];
            if(curr>right && curr>left)return vector<int>{mx,mid};
            else if(curr<right){
                l=mid+1;
            }
            else h=mid-1;
        }
        return vector<int>{-1,-1};
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-a-peak-element-ii/)