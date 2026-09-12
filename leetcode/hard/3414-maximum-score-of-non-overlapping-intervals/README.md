# Maximum Score of Non-overlapping Intervals

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer array `intervals`, where `intervals[i] = [li, ri, weighti]`. Interval `i` starts at position `li` and ends at `ri`, and has a weight of `weighti`. You can choose  *up to*  4  **non-overlapping**  intervals. The  **score**  of the chosen intervals is defined as the total sum of their weights.

Return the lexicographically smallest array of at most 4 indices from `intervals` with  **maximum**  score, representing your choice of non-overlapping intervals.

Two intervals are said to be  **non-overlapping**  if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.

 

 **Example 1:** 

 **Input:**  intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]

 **Output:**  [2,3]

 **Explanation:** 

You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.

 **Example 2:** 

 **Input:**  intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]

 **Output:**  [1,3,5,6]

 **Explanation:** 

You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.

 

 **Constraints:** 

- 1 <= intevals.length <= 5 * 104
- intervals[i].length == 3
- intervals[i] = [li, ri, weighti]
- 1 <= li <= ri <= 109
- 1 <= weighti <= 109

## Solution

**Language:** C++  
**Runtime:** 2920 ms (beats 5.43%)  
**Memory:** 353.1 MB (beats 31.52%)  
**Submitted:** 2026-09-12T18:53:53.900Z  

```cpp
#define ll long long
class Solution {
public:
    int visited[50001][4];
    pair<ll,vector<int>> dp[50001][4];
    bool isSmaller(vector<int>a,vector<int>b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return a<b;
    }
    pair<ll,vector<int>> solve(int i,vector<vector<int>> &arr,int cnt){
        int n=arr.size();
        if(i==n || cnt==4)return {0ll,{}};
        // skip this
        if(visited[i][cnt])return dp[i][cnt];
        auto &ref=dp[i][cnt];
        visited[i][cnt]=true;
        auto [skp_sm,skp_str]=solve(i+1,arr,cnt);
        int x=arr[i][1];
        auto it=upper_bound(arr.begin(),arr.end(),x,
        [](int x,const vector<int>&a){
            return x<a[0];
        })
        -arr.begin();

        auto [tk_sm,tk_str]=solve(it,arr,cnt+1);
        tk_sm+=arr[i][2];
        tk_str.push_back(arr[i][3]);
        if(tk_sm>skp_sm)return ref={tk_sm,tk_str};
        if(tk_sm<skp_sm)return ref={skp_sm,skp_str};
        auto smaller=tk_str;
        if(isSmaller(skp_str,tk_str))smaller=skp_str;
        return ref={tk_sm,smaller};
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        vector<vector<int>> arr;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            auto a=intervals[i];
            a.push_back(i);
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        auto [sm,idx]=solve(0,arr,0);
        sort(idx.begin(),idx.end());
        return idx;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/)