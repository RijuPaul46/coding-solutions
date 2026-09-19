# Circle and Rectangle Overlapping

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a circle represented as `(radius, xCenter, yCenter)` and an axis-aligned rectangle represented as `(x1, y1, x2, y2)`, where `(x1, y1)` are the coordinates of the bottom-left corner, and `(x2, y2)` are the coordinates of the top-right corner of the rectangle.

Return `true` *if the circle and rectangle are overlapped otherwise return* `false`. In other words, check if there is  **any**  point `(xi, yi)` that belongs to the circle and the rectangle at the same time.

 

 **Example 1:** 

```
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).

```

 **Example 2:** 

```
Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false

```

 **Example 3:** 

```
Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

```

 

 **Constraints:** 

- 1 <= radius <= 2000
- -104 <= xCenter, yCenter <= 104
- -104 <= x1 < x2 <= 104
- -104 <= y1 < y2 <= 104

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.6 MB (beats 95.38%)  
**Submitted:** 2026-09-19T08:20:06.615Z  

```cpp
#define db double 
class Solution {
public:
    db dist(int a,int b,int x,int y){
        return sqrt((a-x)*(a-x)+(b-y)*(b-y));
    }
    bool checkOverlap(int radius, int x, int y, int x1, int y1, int x2, int y2) {
        // any point on the perimeter of rectangle ... 
        // if it is <=r then overlap 
        // case 2: if whole circle inside //
        // what if overlapping region do not contain any integer
        if(x<=x1){
            if(y<y1){
                db d=dist(x1,y1,x,y);
                return d<=radius;
            }
            if(y>y2){
                db d=dist(x1,y2,x,y);
                return d<=radius;
            }
            return (x1-x)<=radius;
        }
        if(x>=x2){
            if(y<y1){
                db d=dist(x2,y1,x,y);
                return d<=radius;
            }
            if(y>y2){
                db d=dist(x2,y2,x,y);
                return d<=radius;
            }
            return (x-x2)<=radius;
        }
        if(y<y2 && y>y1)return true;
        int d=min(abs(y-y1),abs(y-y2));
        return d<=radius;

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/circle-and-rectangle-overlapping/)