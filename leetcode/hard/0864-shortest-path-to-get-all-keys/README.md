# Shortest Path to Get All Keys

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an `m x n` grid `grid` where:

- '.' is an empty cell.
- '#' is a wall.
- '@' is the starting point.
- Lowercase letters represent keys.
- Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some `1 <= k <= 6`, there is exactly one lowercase and one uppercase letter of the first `k` letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return  *the lowest number of moves to acquire all keys*. If it is impossible, return `-1`.

 

 **Example 1:** 

```
Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.

```

 **Example 2:** 

```
Input: grid = ["@..aA","..B#.","....b"]
Output: 6

```

 **Example 3:** 

```
Input: grid = ["@Aa"]
Output: -1

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 30
- grid[i][j] is either an English letter, '.', '#', or '@'. 
- There is exactly one '@' in the grid.
- The number of keys in the grid is in the range [1, 6].
- Each key in the grid is unique.
- Each key in the grid has a matching lock.

## Solution

**Language:** C++  
**Runtime:** 327 ms (beats 7.32%)  
**Memory:** 14.3 MB (beats 91.04%)  
**Submitted:** 2026-09-02T06:37:14.626Z  

```cpp
class State {
    public:
    int x, y, mask;
    State(int a, int b, int c) {
        x = a;
        y = b;
        mask = c;
    }
};
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> pos(m, vector<int>(n, -1));
        int key = 0;
        int lock = 6;
        unordered_map<char, int> lock_key;
        int sx = -1, sy = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    sx = i;
                    sy = j;
                }
                if (isalpha(c)) {
                    if (islower(c)) {
                        char lock_ = toupper(c);
                        pos[i][j] = key;
                        lock_key[lock_] = key++;
                    }
                }
            }
        }
        int final_state=(1<<key)-1;
        cout<<final_state;
        int visited[m + 1][n + 1][final_state+1];
        memset(visited,false , sizeof(visited));
        queue<State> q;
        q.push(State(sx, sy, 0));
        visited[sx][sy][0]=1;
        int mov = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                auto st = q.front();
                q.pop();
                int x = st.x, y = st.y, mask = st.mask;
                cout<<mask<<" ";
                // visited[x][y][mask]=1;
                
                char c = grid[x][y];
                if (isalpha(c)) {
                    if (isupper(c)) {
                        int key_pos = lock_key[c];
                        if(((mask) &(1<<key_pos))==0){
                            continue;
                        }
                        
                    } else {
                        int pos_ = pos[x][y];
                        mask = mask | (1 << pos_);
                    }
                }
                if ((mask&((1<<6)-1) )== final_state)
                    return mov;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                        grid[nx][ny] != '#' && !visited[nx][ny][mask]) {
                        visited[nx][ny][mask]=true;
                        q.push(State(nx, ny, mask));
                    }
                }
            }
            mov++;
        }
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/shortest-path-to-get-all-keys/)