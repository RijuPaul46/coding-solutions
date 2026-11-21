# Find Subtree Sizes After Changes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a tree rooted at node 0 that consists of `n` nodes numbered from `0` to `n - 1`. The tree is represented by an array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node 0 is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

We make the following changes on the tree  **one**  time  **simultaneously**  for all nodes `x` from `1` to `n - 1`:

- Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
- If node y does not exist, do nothing.
- Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.

Return an array `answer` of size `n` where `answer[i]` is the  **size**  of the subtree rooted at node `i` in the  **final**  tree.

 

Original
C++
 **Example 1:** 

 **Input:**  parent = [-1,0,0,1,1,1], s = "abaabc"

 **Output:**  [6,3,1,1,1,1]

 **Explanation:** 

The parent of node 3 will change from node 1 to node 0.

 **Example 2:** 

 **Input:**  parent = [-1,0,4,0,1], s = "abbba"

 **Output:**  [5,2,1,1,1]

 **Explanation:** 

The following changes will happen at the same time:

- The parent of node 4 will change from node 1 to node 0.
- The parent of node 2 will change from node 4 to node 1.

 

 **Constraints:** 

- n == parent.length == s.length
- 1 <= n <= 105
- 0 <= parent[i] <= n - 1 for all i >= 1.
- parent[0] == -1
- parent represents a valid tree.
- s consists only of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 2151 ms (beats 8.75%)  
**Memory:** 527.9 MB (beats 5.00%)  
**Submitted:** 2026-11-21T22:53:41.465Z  

```cpp
class Solution {
public:
    void solve(vector<unordered_set<int>> &adj,int node,vector<int>&par,vector<int>curr,string &s){
        char c=s[node];
        if(curr[c-'a']!=-1){
            par[node]=curr[c-'a'];
        }
        curr[c-'a']=node;
        for(auto &ch:adj[node]){
            solve(adj,ch,par,curr,s);
        }
    }
    int count(vector<int>&ans,int node,vector<unordered_set<int>> &adj){
        int cnt=1;
        for(auto &ch:adj[node]){
            cnt+=count(ans,ch,adj);
        }
        return ans[node]=cnt;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        vector<unordered_set<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].insert(i);
        }
        vector<int>curr(26,-1);
        solve(adj,0,parent,curr,s);
        vector<int>ans(n);
        adj.assign(n, unordered_set<int>());
        for(int i=1;i<n;i++){
            adj[parent[i]].insert(i);
        }
        count(ans,0,adj);
        return ans;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-subtree-sizes-after-changes/)