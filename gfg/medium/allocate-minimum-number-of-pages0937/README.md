# Allocate Minimum Pages

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]** of integers, where each element  **arr[i]**  represents the number of pages in the i-th book. You also have an integer  **k**  representing the number of students. The task is to allocate books to each student such that:

- Each student receives atleast one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.
- All books must be allocated.

The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum. If it is not possible to allocate books to all students, return  **-1** ;

 **Examples:** 

```
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
```

```
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-23T07:23:35.887Z  

```cpp
class Solution {
  public:
  // let answer is x .... it is very easy to make arrangement >x
  // binary search on answer
  bool check(vector<int>&arr,int k,int x){
      int n=arr.size();
      int cnt=0,sm=0;
      for(int i=0;i<n;i++){
          if(sm+arr[i]>x){
              cnt++;
              sm=arr[i];
          }
          else sm+=arr[i];
          
      }
      return (cnt+1)<=k;
      
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n<k)return -1;
        int l=*max_element(arr.begin(),arr.end());
        int h=1e10;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(arr,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)