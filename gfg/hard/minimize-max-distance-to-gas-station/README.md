# Minimize Max Distance of Adjacent Gas Stations

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1],..., stations[n-1]. Now, we add  **k**  more gas stations so that  **d**, the maximum distance between adjacent gas stations is minimized. Find the smallest possible value of d. Find the answer exactly to 6 decimal places.
 **Note** : stations sorted is in a strictly increasing order.

 **Examples:** 

```
Input: stations[] = [1, 2, 3, 4, 5], k = 2
Output: 1.00
Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.
```

```
Input: stations[] = [3, 6, 12, 19, 33], k = 3
Output: 6.00 
Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-01T07:04:20.061Z  

```cpp
#define db double
class Solution {
  public:
    bool check(vector<int>&stations,int k,double x){
        int n=stations.size();
        int cnt=0;
        double prev=(db)stations[0];
        for(int i=1;i<n;i++){
            db pos=(db)stations[i];
            double d=pos-prev;
            db req=ceil(d/x);
            cnt+=req-1;
            prev=pos;
            
        }
        return cnt<=k;
    }
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        db l=0.000000,h=1e6;
        db ans=-1;
        while(l<=h){
            db mid=(db)(h+l)/(db)2;
            // cout<<mid<<endl;
            if(check(stations,k,mid)){
                ans=mid;
                h=mid-0.000001;
            }
            else l=mid+0.000001;
        }
        return ans;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1)