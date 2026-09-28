# MATNEARESTO

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Distance to Nearest 0

Given is a `N x M` binary matrix, for each cell find its distance from the nearest `0`.

 **Note:**  Distance between vertically or horizontally adjacent cells is `1`. (See the sample input/output for more clarity)

### Input Format
- The first line of input will contain two space separated integers $N$ and $M$, denoting the no. of rows and columns in the matrix.
- Next $N$ lines containing $M$ space separated integers, the elements of the matrix.
### Output Format
- Output $N$ lines containing $M$ space separated integers, the distance of each cell from nearest 0.
### Constraints
- $1 \leq N, M \leq 100$
- The elements of the matrix are either 0 or 1.
- There is at least one 0 in the matrix.
### Sample 1:
Input
Output

```
3 3
0 1 1
0 1 0
1 1 1
```

```
0 1 1
0 1 0
1 2 1
```

### Explanation:

Positions are written as $(row, column)$, starting from $1$.

- Cells $(1,1)$, $(2,1)$, and $(2,3)$ contain $0$, so their distance is $0$.
- Cells $(1,2)$, $(1,3)$, $(2,2)$, $(3,1)$, and $(3,3)$ are horizontally or vertically adjacent to a cell containing $0$, so their distance is $1$.
- Cell $(3,2)$ requires at least $2$ moves to reach a $0$. For example, move left to $(3,1)$, then up to $(2,1)$. Its distance is therefore $2$.

Only horizontal and vertical moves are allowed; diagonal moves are not allowed.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-28T14:07:44.673Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;
vector < vector < int >> dir = {
    {
        1,
        0
    },
    {
        -1,
        0
    },
    {
        0,
        1
    },
    {
        0,
        -1
    }
};
int main() {
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector < vector < int >> dist(n, vector < int > (m, INT_MAX));
    queue < pair < int, int >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                dist[i][j] = 0;
                q.push({
                    i,
                    j
                });
            }
        }
    }
    int d = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto[x, y] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = d + 1;
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        q.push({
                            nx,
                            ny
                        });
                    }
                }
            }
        }
        d++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

}
```

---

[View on CodeChef](https://www.codechef.com/problems/MATNEARESTO)