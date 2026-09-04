# All Longest Common Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings  **s1**  and  **s2**, return all  **distinct Longest Common Subsequences** (LCS) in lexicographical order.

 **Note:**  A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

 **Examples:** 

```
Input: s1 = "abaaa", s2 = "baabaca"
Output: ["aaaa", "abaa", "baaa"]
Explanation: Length of lcs is 4, in lexicographical order they are "aaaa", "abaa", "baaa".

```

```
Input: s1 = "aaa", s2 = "a"
Output: ["a"]
Explanation: Length of lcs is 1 and it is "a".
```

```
Input: s1 = "geeksforgeeks", s2 = "abcd"
Output: []
Explanation: There is no common subsequence present in both strings.
```

 **Constraints:** 
1 ≤ s1.size(), s2.size() ≤ 50
s1 and s2 contain only  **lowercase**  English letters.

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-04T18:02:17.700Z  

```cpp
class Solution {
  public:
    // unordered_set<string>ans;
    int visited[51][51];
    unordered_set<string> solve(int i,int j,string &t1,string &t2,vector<vector<unordered_set<string>>>&dp){
        int m=t1.size();
        int n=t2.size();
        if(i==m || j==n){ unordered_set<string> ans;
            ans.insert("");
            return ans;
        }
        if(visited[i][j]){
            return dp[i][j];
        }
        visited[i][j]=1;
        if(t1[i]==t2[j]){
            auto st=solve(i+1,j+1,t1,t2,dp);
            unordered_set<string>ans;
            for(auto &s:st){
                ans.insert((t1[i]+s));
            }
            return dp[i][j]=ans;
        }
        auto left=solve(i+1,j,t1,t2,dp);
        auto right=solve(i,j+1,t1,t2,dp);
        int mx=0;
        for(auto &s:left)mx=max(mx,(int)s.size());
        for(auto &s:right)mx=max(mx,(int)s.size());
        unordered_set<string>ans;
        for(auto &s:left){
            if((int)s.size()==mx)ans.insert(s);

        }
        for(auto &s:right){
            if((int)s.size()==mx)ans.insert(s);

        }
        return dp[i][j]=ans;
    }

    vector<string> allLCS(string &t1, string &t2) {
        // code here
        int m=t1.size();
        int n=t2.size();
        vector<vector<unordered_set<string>>>dp(m,vector<unordered_set<string>>(n));
        memset(visited,0,sizeof(visited));// 
        // memset(dp,-1,sizeof(dp));
        auto st=solve(0,0,t1,t2,dp);
        // sort(ans.begin(),ans.end());
        vector<string>str;
        for(auto &s:st )str.push_back(s);
        sort(str.begin(),str.end());
        return str;

    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1)