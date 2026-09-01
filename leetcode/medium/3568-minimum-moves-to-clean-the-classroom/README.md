# Minimum Moves to Clean the Classroom

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` grid `classroom` where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:

- 'S': Starting position of the student
- 'L': Litter that must be collected (once collected, the cell becomes empty)
- 'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
- 'X': Obstacle the student cannot pass through
- '.': Empty space

You are also given an integer `energy`, representing the student's maximum energy capacity. The student starts with this energy from the starting position `'S'`.

Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area `'R'`, which resets the energy to its  **maximum**  capacity `energy`.

Return the  **minimum**  number of moves required to collect all litter items, or `-1` if it's impossible.

 

 **Example 1:** 

 **Input:**  classroom = ["S.", "XL"], energy = 2

 **Output:**  2

 **Explanation:** 

- The student starts at cell (0, 0) with 2 units of energy.
- Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
- A valid sequence of moves to collect all litter is as follows: Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining. Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
- The student collects all the litter using 2 moves. Thus, the output is 2.

 **Example 2:** 

 **Input:**  classroom = ["LS", "RL"], energy = 4

 **Output:**  3

 **Explanation:** 

- The student starts at cell (0, 1) with 4 units of energy.
- A valid sequence of moves to collect all litter is as follows: Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining. Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4. Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
- The student collects all the litter using 3 moves. Thus, the output is 3.

 **Example 3:** 

 **Input:**  classroom = ["L.S", "RXL"], energy = 3

 **Output:**  -1

 **Explanation:** 

No valid path collects all `'L'`.

 

 **Constraints:** 

- 1 <= m == classroom.length <= 20
- 1 <= n == classroom[i].length <= 20
- classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
- 1 <= energy <= 50
- There is exactly one 'S' in the grid.
- There are at most 10 'L' cells in the grid.

## Solution

**Language:** C++  
**Runtime:** 283 ms (beats 63.00%)  
**Memory:** 93.5 MB (beats 89.00%)  
**Submitted:** 2026-09-01T20:14:00.870Z  

```cpp
// there are atmost 10 L in the cell 
// i can store them in bitmask 
// but each state must be visited once to get answer
// but i will visit state for many time if we get fewer move 
// so conceptually okay but tle 
// we can optimise it : BFS will ensure that move is already min ... 
// we will visit a state iff we have better energy 
// so same state is being already visited with lower energy and it is also exploring next state ... we will only visit that state again iff we have greater energy .... higher possibiity .... if at any state we come across final state .. we immediately return the mov .. because bfs ensure that the mov is min
class State{
    public:
    int x,y,mask,energy;
    State(int a,int b,int c,int d){
        x=a;
        y=b;
        mask=c;
        energy=d;
    }
} ;
class Solution {
public:
    int best[21][21][1<<10];
    vector<vector<int>> pos;
    // we have to make min move ... for x,y,same mask,energy
    // try storing min number of move to reach there
    int final_state;
    int mx_energy;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int xx,int yy,int ee,int maskk,int mov,vector<string>& cr){
        int m=cr.size();
        int n=cr[0].size();
        queue<State>q;
        q.push(State(xx,yy,maskk,ee));
        
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
            auto st=q.front();
            q.pop();
            int x=st.x,y=st.y,mask=st.mask,e=st.energy;
            if(cr[x][y]=='R')e=mx_energy;
            if(cr[x][y]=='L'){
                int ps=pos[x][y];
                mask=mask|(1<<ps);
            }
            if(mask==final_state)return mov;
                if(e>0){
                    for(int i=0;i<4;i++){
                    int nx=x+dir[i][0];
                    int ny=y+dir[i][1];
                    
                    if(nx>=0 && nx<m && ny>=0 && ny<n && cr[nx][ny]!='X' && best[nx][ny][mask]<e-1){
                        best[nx][ny][mask]=e-1;
                        // cout<<"hi";
                        q.push(State(nx,ny,mask,e-1));
                        }
                    }
                }
            }
            mov++;

        }
        return -1;
        
    }
    
    int minMoves(vector<string>& cr, int e) {
        int m=cr.size();
        int n=cr[0].size();
        mx_energy=e;
        fill(&best[0][0][0],
     &best[0][0][0] + 21*21*(1<<10),
     INT_MIN);
        pos.resize(m,vector<int>(n,-1));
        int cnt=0;
        int sx=-1,sy=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(cr[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                if(cr[i][j]=='L'){
                    pos[i][j]=cnt++;

                }
            }
        }
        final_state=(1<<cnt)-1;
        cout<<final_state<<endl;
        // max val = 2^10
        // all one if collected
        best[sx][sy][0]=e;
        int ans=dfs(sx,sy,e,0,0,cr);
        return ans;

        
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/)