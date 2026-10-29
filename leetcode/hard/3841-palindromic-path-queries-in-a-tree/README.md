# Palindromic Path Queries in a Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an undirected tree with `n` nodes labeled 0 to `n - 1`. This is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates an undirected edge between nodes `ui` and `vi`.

You are also given a string `s` of length `n` consisting of lowercase English letters, where `s[i]` represents the character assigned to node `i`.

You are also given a string array `queries`, where each `queries[i]` is either:

- "update ui c": Change the character at node ui to c. Formally, update s[ui] = c.
- "query ui vi": Determine whether the string formed by the characters on the unique path from ui to vi (inclusive) can be rearranged into a palindrome.

Return a boolean array `answer`, where `answer[j]` is `true` if the `jth` query of type `"query ui vi"​​​​​​​` can be rearranged into a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]

 **Output:**  [true,false]

 **Explanation:** 

- "query 0 2": Path 0 → 1 → 2 gives "aac", which can be rearranged to form "aca", a palindrome. Thus, answer[0] = true.
- "update 1 b": Update node 1 to 'b', now s = "abc".
- "query 0 2": Path characters are "abc", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.

Thus, `answer = [true, false]`.

 **Example 2:** 

 **Input:**  n = 4, edges = [[0,1],[0,2],[0,3]], s = "abca", queries = ["query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"]

 **Output:**  [false,false,true]

 **Explanation:** 

- "query 1 2": Path 1 → 0 → 2 gives "bac", which cannot be rearranged to form a palindrome. Thus, answer[0] = false.
- "update 0 b": Update node 0 to 'b', now s = "bbca".
- "query 2 3": Path 2 → 0 → 3 gives "cba", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.
- "update 3 a": Update node 3 to 'a', s = "bbca".
- "query 1 3": Path 1 → 0 → 3 gives "bba", which can be rearranged to form "bab", a palindrome. Thus, answer[2] = true.

Thus, `answer = [false, false, true]`.

 

 **Constraints:** 

- 1 <= n == s.length <= 5 * 104
- edges.length == n - 1
- edges[i] = [ui, vi]
- 0 <= ui, vi <= n - 1
- s consists of lowercase English letters.
- The input is generated such that edges represents a valid tree.
- 1 <= queries.length <= 5 * 104​​​​​​​queries[i] = "update ui c" or queries[i] = "query ui vi" 0 <= ui, vi <= n - 1 c is a lowercase English letter.

## Solution

**Language:** C++  
**Runtime:** 709 ms (beats 31.82%)  
**Memory:** 461.3 MB (beats 7.95%)  
**Submitted:** 2026-10-29T09:10:39.889Z  

```cpp
class Solution {
public:
    //simple xor with euler tour 
    // segtree will give range xor ..... in a range find xor
    // palindrome if xor is 0 even length .... and for odd lenth only one bit survive ... 26 char poss a-0th bit , b-1st bit , c-2nd bit 
    vector<int>tin,tout,euler;
    vector<vector<int>> adj,up;
    int max_log=17;
    string str;
    vector<int>segTree;
    bool isAnc(int a,int b){
        if(tin[a]<=tin[b] && tout[b]<=tout[a])return 1;
        return 0;
    }
    int lca(int a,int b){
        if(isAnc(a,b))return a;
        if(isAnc(b,a))return b;
        for(int j=max_log-1;j>=0;j--){
            if(!isAnc(up[a][j],b))a=up[a][j];
        }
        return up[a][0];
    }
    void buildTree(int i,int l,int r){
        int mid=l+(r-l)/2;
        if(l==r){
           segTree[i]=euler[l];
            return;
        }
        int left=2*i+1;
        int right=2*i+2;
        buildTree(left,l,mid);
        buildTree(right,mid+1,r);
        segTree[i]=segTree[left]^segTree[right];
        return;
    }
    void update(int tgt,int val,int i,int l,int r){
        if(l==r && l==tgt){
            euler[tgt]=val;
            segTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        int left=2*i+1;
        int right=2*i+2;
        if(tgt<=mid){
            update(tgt,val,left,l,mid);
        }
        else update(tgt,val,right,mid+1,r);
        segTree[i]=segTree[left]^segTree[right];
        return;

    }
    int getxor(int from,int to,int i,int l,int r){
        if(r<from || l>to )return 0;
        if(l>=from && r<=to)return segTree[i];
        int mid=l+(r-l)/2;
        int left=2*i+1;
        int right=2*i+2;
        int lft=getxor(from,to,left,l,mid);
        int rt=getxor(from,to,right,mid+1,r);
        return lft^rt;
    }
    void euler_tour(int node,int par,int &time){
        up[node][0]=par;
        tin[node]=time++;
        int idx=str[node]-'a';
        euler.push_back((1<<idx));
        for(auto &ch:adj[node]){
            euler_tour(ch,node,time);
        }
        euler.push_back((1<<idx));
        tout[node]=time++;

    }
    bool isPalindrome(int n){
        if(n==0)return true;
        if( (n & (n-1)) ==0)return true;
        return false;
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.resize(n);
        up.resize(n,vector<int>(max_log+1));
        str=s;
        vector<int>indegree(n);
        for(auto &ed:edges){
            int u=ed[0];
            int v=ed[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        // i need for each node i will keep track of tin index 
        tin.resize(n);
        tout.resize(n);
        int root=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                root=i;
                break;
            }
        }
        int time=0;
        euler_tour(root,root,time);
        for(int j=1;j<max_log;j++){
            for(int i=0;i<n;i++){
                up[i][j]=up[up[i][j-1]][j-1];
            }
        }
        int len=euler.size();
        segTree.resize(4*len);
        buildTree(0,0,len-1);
        vector<bool>ans;
        for (auto &qr:queries){
            stringstream ss(qr);
            vector<string>words;
            string word;
            while(ss>>word){
                words.push_back(word);
            }
            if(words[0]=="query"){
                int u=stoi(words[1]);
                int v=stoi(words[2]);
                int uin=tin[u],vin=tin[v];
                int uout=tout[u],vout=tout[v];
                if(uout<vin){
                    int from=uout;
                    int to=vin;
                    int val=getxor(from,to,0,0,len-1);
                    int lc=lca(u,v);
                    int idx=1<<(str[lc]-'a');
                    val^=idx;
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                if(vout<uin){
                    int from=vout,to=uin;
                    int val=getxor(from,to,0,0,len-1);
                    int lc=lca(u,v);
                    int idx=1<<(str[lc]-'a');
                    val^=idx;
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                else if(vin>=uin && vin<=uout){
                    int from=uin,to=vin;
                    int val=getxor(from,to,0,0,len-1);
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                else if(uin>=vin && uin<=vout){
                    int from=vin,to=uin;
                    int val=getxor(from,to,0,0,len-1);
                    if(isPalindrome(val))ans.push_back(true);
                    else ans.push_back(false);
                }
                
            }
            else{
                int tgt=stoi(words[1]);
                char ch=words[2][0];
                str[tgt]=ch;
                int val=1<<(ch-'a');
                int in=tin[tgt],out=tout[tgt];
                update(in,val,0,0,len-1);
                update(out,val,0,0,len-1);
            }
        }
        return ans;


    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindromic-path-queries-in-a-tree/)