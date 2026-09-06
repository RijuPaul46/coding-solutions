class Solution {
  public:
    bool check(int x,int n){
        return x*x<=n;
    }
    int floorSqrt(int n) {
        // code here
        //we can find it in logn time .... 
        // concept let x=sqrt(n)
        // y<x  y*y<n  .... 
        int l=0,r=n;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,n)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};