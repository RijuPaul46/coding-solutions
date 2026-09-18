# Maximum Number of Non-Overlapping Substrings

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string `s` of lowercase letters, you need to find the maximum number of  **non-empty**  substrings of `s` that meet the following conditions:

- The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
- A substring that contains a certain character c must also contain all occurrences of c.

Find  *the maximum number of substrings that meet the above conditions*. If there are multiple solutions with the same number of substrings,  *return the one with minimum total length.* It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in  **any**  order.

 

 **Example 1:** 

```
Input: s = "adefaddaccc"
Output: ["e","f","ccc"]
Explanation: The following are all the possible substrings that meet the conditions:
[
  "adefaddaccc"
  "adefadda",
  "ef",
  "e",
  "f",
  "ccc",
]
If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.

```

 **Example 2:** 

```
Input: s = "abbaccd"
Output: ["d","bb","cc"]
Explanation: Notice that while the set of substrings ["d","abba","cc"] also has length 3, it's considered incorrect since it has larger total length.

```

 

 **Constraints:** 

- 1 <= s.length <= 105
- s contains only lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 14 ms (beats 52.83%)  
**Memory:** 25.2 MB (beats 34.81%)  
**Submitted:** 2026-09-18T18:22:47.703Z  

```cpp
class Solution {
public:
    // int solve(int idx,vector<pair<int,int>> &arr){
    //     int n=arr.size();
    //     if(idx==n)return 0;
    //     // let take this 
    //     int ei=arr[idx].second;
    //     auto next=upper_bound(arr.begin(),arr.end(),make_pair(ei,INT_MIN))-arr.begin();
    //     int take=1+solve(next,arr);
    //     int skip=solve(idx+1,arr);
    //     return max(take,skip);
    // }
    pair<int,int> getInterval(int start,string &s,vector<int>&si,vector<int>&ei){
        char first=s[start];
        int end=ei[first-'a'];
        for(int i=start+1;i<=end;i++){
            char c=s[i];
            int s=si[c-'a'];
            if(s<start)return {-1,-1};
            end=max(end,ei[c-'a']);
        }
        return {start,end};
    }
    vector<vector<pair<int,int>>> dp;
    vector<bool>visited;
    vector<pair<int,int>> solve(int i,vector<pair<int,int>>&arr){
        int n=arr.size();
        if(i==n){
            vector<pair<int,int>> ans;
            return ans;
        }
        if(visited[i])return dp[i];
        visited[i]=true;
        // let take this 
        int ei=arr[i].second;
        auto next=upper_bound(arr.begin(),arr.end(),ei,[](int x,pair<int,int>&p){
            return x<p.first;
        })-arr.begin();
        auto take=solve(next,arr);
        take.push_back({arr[i].first,arr[i].second});
        auto skip=solve(i+1,arr);
        if(take.size()>skip.size())return dp[i]=take;
        if(take.size()<skip.size())return dp[i]=skip;
        //both are same
        int len1=0,len2=0;
        for(auto &[u,v]:take)len1+=(v-u+1);
        for(auto &[u,v]:skip)len2+=(v-u+1);
        if(len1<len2)return dp[i]=take;
        return dp[i]=skip;
    }
    vector<string> maxNumOfSubstrings(string s) {
        
        dp.resize(27);
        visited.resize(27,false);
        vector<int> si(26,-1),ei(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            int idx=c-'a';
            if(si[idx]==-1){
                si[idx]=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            char c=s[i];
            int idx=c-'a';
            if(ei[idx]==-1){
                ei[idx]=i;
            }
        }
        // substring .... such that all char c inside it has si,ei inside 
        //this range ....
        //first i need to find such substring intervals 
        // inside a interval ... i need to find how many unique char are 
        //there inside a range all unique char ...
        // go to each char ask si , ei .. and change the range accordingly
        // atmost 26 asking needed .... but segTree ... if store set<char>
        // total 4*n box ... set can contain 26 elm ... 4*n*26==1e7 memory 
        // a-z if i want this char ... find si,ei ... iterate overit ...
        //inside char shoudl ... should we use dsu ??? 
        /// if we want to take a ... we must take d ,,, if we want to take d it does not mean we must take a ... so no dsu 
        // we only want substring ... both end should have same char ..
        // si , ei inside if any char has si,ei not in range it is not possible 
        // have to check only 26
        vector<pair<int,int>> interval;
        // interval.push_back({0,n-1});
        vector<int>a;
        for(int i=0;i<26;i++){
            if(si[i]!=-1)a.push_back(si[i]);
        }
        sort(a.begin(),a.end());
        for(auto &x:a){
            
                auto [u,v]=getInterval(x,s,si,ei);
                if(u!=-1)interval.push_back({u,v});
            
        }
        //max 26 interval possible ... no redundant acabb  not aca,bb 
        //now we need to take max number of interval ... which do not overlap
        sort(interval.begin(),interval.end());
        // max 26 substring possible 
        auto intv=solve(0,interval);
        vector<string>ans;
        for(auto &[u,v]:intv){
            ans.push_back(s.substr(u,v-u+1));
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)