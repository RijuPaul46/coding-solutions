# Find Rotation Count

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given an increasing sorted rotated array  **arr[]** of distinct integers. The array is right-rotated  **k**  times. Find the value of  **k**.

 **Examples:** 

```
Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.

```

```
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated.
```

```
Input: arr = [6, 9, 2, 4]
Output: 2
Explanation: The original array is [2, 4, 6, 9] and we get the above array after two rotations.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T17:42:52.576Z  

```cpp
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        //find min elm index ... 
        int n=arr.size();
        int l=0,h=n-1;
        int mni=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]<arr[mni])mni=mid;
            if(arr[h]>arr[mid]){
                h=mid-1;
            }
            else if(arr[l]<arr[mid]){
                if(arr[l]<arr[mni])mni=l;
                l=mid+1;
            }
            else l=mid+1;
        }
        return mni;
    }
    
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/rotation4723/1)