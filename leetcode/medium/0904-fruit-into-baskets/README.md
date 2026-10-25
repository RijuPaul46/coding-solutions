# Fruit Into Baskets

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the  **type**  of fruit the `ith` tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

Given the integer array `fruits`, return  *the  **maximum**  number of fruits you can pick*.

 

 **Example 1:** 

```
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

```

 **Example 2:** 

```
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

```

 **Example 3:** 

```
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

```

 

 **Constraints:** 

- 1 <= fruits.length <= 105
- 0 <= fruits[i] < fruits.length

## Solution

**Language:** C++  
**Runtime:** 46 ms (beats 47.97%)  
**Memory:** 84.9 MB (beats 34.56%)  
**Submitted:** 2026-10-25T14:18:53.996Z  

```cpp
class Solution {
public:
    //find longest subarray having maximum 2 distinct elm 
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size();
        int j=0;
        int mx=0;
        for(int i=0;i<n;i++){
            int x=fruits[i];
            mp[x]++;
            while((int)mp.size()>2){
                int y=fruits[j];
                mp[y]--;
                if(mp[y]==0)mp.erase(y);
                j++;
            }
            mx=max(mx,i-j+1);
        }
        return mx;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/fruit-into-baskets/)