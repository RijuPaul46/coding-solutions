# Image Overlap

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two images, `img1` and `img2`, represented as binary, square matrices of size `n x n`. A binary matrix has only `0`s and `1`s as values.

We  **translate**  one image however we choose by sliding all the `1` bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the  **overlap**  by counting the number of positions that have a `1` in  **both**  images.

Note also that a translation does  **not**  include any kind of rotation. Any `1` bits that are translated outside of the matrix borders are erased.

Return  *the largest possible overlap*.

 

 **Example 1:** 

```
Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).

```

 **Example 2:** 

```
Input: img1 = [[1]], img2 = [[1]]
Output: 1

```

 **Example 3:** 

```
Input: img1 = [[0]], img2 = [[0]]
Output: 0

```

 

 **Constraints:** 

- n == img1.length == img1[i].length
- n == img2.length == img2[i].length
- 1 <= n <= 30
- img1[i][j] is either 0 or 1.
- img2[i][j] is either 0 or 1.

## Solution

**Language:** Python  
**Runtime:** 143 ms (beats 96.03%)  
**Memory:** 19.5 MB (beats 78.84%)  
**Submitted:** 2026-09-13T16:43:07.734Z  

```py
class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        A = [(i, j) for i in range(n) for j in range(n) if img1[i][j] == 1]
        B = [(i, j) for i in range(n) for j in range(n) if img2[i][j] == 1]
        cnt = [[0] * (2 * n) for _ in range(2 * n)]
        best = 0
        for ax, ay in A:
            for bx, by in B:
                dx = bx - ax + n
                dy = by - ay + n
                cnt[dx][dy] += 1
                best = max(best, cnt[dx][dy])
        return best
```

---

[View on LeetCode](https://leetcode.com/problems/image-overlap/)