# NODESDIST

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Distance between two nodes

Given an undirected connected tree with  **N**  nodes, numbered from  **1**  to  **N**, and rooted at node  **1**, and two nodes $u$ and $v$, find the distance between these two nodes. (**Note:**  the distance between two nodes is the no. of edges in the simple path between them.)

For example, in the following tree, the distance between nodes $3$ and $7$ is $4$.

### Input Format
- The first line of the input contains three space separated integers $N$, $u$ and $v$ — the number of nodes, and two given nodes.
- The next $N - 1$ lines describe the edges. The $i$-th of these $N - 1$ lines contains two space-separated integers $u_i$ and $v_i$, denoting a bidirectional edge between $u_i$ and $v_i$.
### Output Format
- Output on the single line, the distance between the nodes $u$ and $v$.
### Constraints
- $1 \leq N \leq 100000$
- $1 \leq u_i, v_i \leq N$
- $1 \leq u, v \leq N$
### Sample 1:
Input
Output

```
7 3 7
1 2
1 4
2 5
2 3
2 6
4 7
```

```
4
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T14:03:00.486Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
int lca(int par,int node, vector<vector<int>>&adj,int src,int dst){
    if(node==src || node==dst){
        return node;
    }
    int child=adj[node].size();
    vector<int>f(child-1,-1);
    int j=0;
    for(auto &ch:adj[node]){
        if(ch!=par){
            f[j++]=lca(node,ch,adj,src,dst);
        }
    }
    int pos=0;
    int a=-1;
    for(int i=0;i<child-1;i++){
        if(f[i]!=-1){a=f[i];pos++;}
    }
    if(pos>=2)return node;
    if(pos==1)return a;
    return -1;
}
int dist(int par,int node, vector<vector<int>>&adj,int dst){
    if(node==dst)return 0;
    vector<int>f(2,-1);
    int j=0;
    for(auto &ch:adj[node]){
        if(ch!=par){
            f[j++]=dist(node,ch,adj,dst);
        }
    }
    int left=f[0];
    int right=f[1];
    if(left==-1 && right==-1)return -1;
    return 1+(left==-1?right :left);
}
int main() {
	// your code goes here
	int n,src,dst;
	cin>>n>>src>>dst;
	vector<vector<int>>adj(n+1);
	for(int i=0;i<n-1;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	int lc=lca(0,1,adj,src,dst);
	int lc_u=dist(0,lc,adj,src);
	int lc_v=dist(0,lc,adj,dst);
	cout<<lc_u+lc_v<<endl;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/NODESDIST)