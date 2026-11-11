# Minimum Cost to Acquire Required Items

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given five integers `cost1`, `cost2`, `costBoth`, `need1`, and `need2`.

There are three types of items available:

- An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
- An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
- An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.

You must collect enough items so that the total contribution toward type 1 is  **at least**  `need1` and the total contribution toward type 2 is  **at least**  `need2`.

Return an integer representing the  **minimum**  possible total cost to achieve these requirements.

 

Original
C++
 **Example 1:** 

 **Input:**  cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2

 **Output:**  3

 **Explanation:** 

After buying three type 3 items, which cost `3 * 1 = 3`, the total contribution to type 1 is 3 (`>= need1 = 3`) and to type 2 is 3 (`>= need2 = 2`).
Any other valid combination would cost more, so the minimum total cost is 3.

 **Example 2:** 

 **Input:**  cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3

 **Output:**  22

 **Explanation:** 

We buy `need1 = 2` items of type 1 and `need2 = 3` items of type 2: `2  *5 + 3*  4 = 10 + 12 = 22`.
Any other valid combination would cost more, so the minimum total cost is 22.

 **Example 3:** 

 **Input:**  cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0

 **Output:**  0

 **Explanation:** 

Since no items are required (`need1 = need2 = 0`), we buy nothing and pay 0.

 

 **Constraints:** 

- 1 <= cost1, cost2, costBoth <= 106
- 0 <= need1, need2 <= 109

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 21.76%)  
**Memory:** 9.3 MB (beats 52.35%)  
**Submitted:** 2026-11-11T09:12:57.110Z  

```cpp
class Solution {
public:
    #define ll long long
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //let a b c are taken a+c>=need1 b+c>=need2 
        // find min((need1-c)*cost1+(need2-c)*cost2+c*cb)
        // let try bs on answer let answer be x(min total cost) now >=x we can fulfil the condition 
        // can we think greedy ... yes ... whose cost is least 
        // c1<c2<cb take c1 as much as possible 
        // if cb<c1<c2 then answer is cb*(max(n1,n2))
        
        if(1ll*costBoth>=(cost1+cost2)){
            ll ans=1ll*(1ll*need1*cost1+1ll*need2*cost2);
            return ans;
        }
        // let i have taken c elm for cb min(0,need1-cb)
        //let c>=need1 need2 cost is c*cb 
        // c< both need1*c1 + n2*c2 +c(cb-c1-c2)  all are const
        // if cb>(c1+c2) take c=0   if cb< (c1+c2)
        if(1ll*costBoth<=min(cost1,cost2)) {
        ll ans=1ll*costBoth*(1ll*max(need1,need2));
        return ans;}
        ll both=min(need1,need2);
        ll total=1ll*both*costBoth;
        need1-=both;
        need2-=both;
        if(need1>0){
            total+=1ll*(need1)*min(cost1,costBoth);
        }
        else if(need2>0){
            total+=1ll*(need2)*min(cost2,costBoth);
        }
        // c1<=cb<=c2

        return total;
        

    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-to-acquire-required-items/)