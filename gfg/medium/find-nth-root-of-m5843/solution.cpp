class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        // we can apply binary search on answer ... 
        // let x be the nth root of m ..
        // so all number y<x power(y,n)<=m.... 
        // monotonic ... T T T F F ... will exceed
        int l=0;
        int h=m;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if((int)pow(mid,n)<=m){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
            
        }
        if((int)pow(ans,n)==m)return ans;
        return -1;
        
    }
};