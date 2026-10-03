# Median in a Row-Wise Sorted Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a row-wise sorted matrix  **mat[][]**  of size  **n x m**, where the number of rows and columns is always  **odd**. Return the  **median**  of the matrix.

 **Examples:** 

```
Input: mat[][] = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

```

```
Input: mat[][] = [[2, 4, 9], [3, 6, 7], [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
```

```
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T10:28:48.273Z  

```cpp
class Solution {
  public:
    pair<int,int> cnt(vector<vector<int>> &mat,int x){
        int m=mat.size();
        int n=mat[0].size();
        int less=0,equal=0;
        for(int i=0;i<m;i++){
            auto low=lower_bound(mat[i].begin(),mat[i].end(),x);
            auto high=upper_bound(mat[i].begin(),mat[i].end(),x);
            equal+=(high-low);
            less+=(low-mat[i].begin());
        }
        return {less,equal};
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int medn=(m*n+1)/2;
        // clearly bs on answer i will check how many elm <x
        // and how many ==x if 
        // use lower bound and upper bound to count ==x
        int l=1,h=2*(1e3);
        while(l<=h){
            int mid=l+(h-l)/2;
            auto [less,equal]=cnt(mat,mid);
            // cout<<"mid="<<mid<<" "<<less<<" "<<equal<<endl;
            if(less>=medn){
                h=mid-1;
            }
            else if(less+equal<=(medn-1))l=mid+1;
            else{
                if(equal==0)h=mid-1;
                else return mid;
            }
            
        }
        return -1;
        
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1)