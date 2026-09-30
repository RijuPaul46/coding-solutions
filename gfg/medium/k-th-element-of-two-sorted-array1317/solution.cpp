class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        // let x elm are taken from a then y=k-x elm from b
        // valid if l1<r2 && l2<r1
        // we can do binary search on x
        // x is too small then l1<r2 okay .... but l2<r1 does not hold
        // we need to increase x 
        // x is too large l2<r1 hold but l1<r2 does not ... decrease x
        // kth elm will be max(l1,l2)
        int m=a.size(),n=b.size();
        int l=max(0,k-n),h=min(m,k);
        while(l<=h){
            int mid=l+(h-l)/2;
            int y=k-mid;
            int l1=INT_MIN,r1=INT_MAX,l2=INT_MIN,r2=INT_MAX;
            if(mid-1>=0)l1=a[mid-1];
            if(mid<m)r1=a[mid];
            if(y-1>=0)l2=b[y-1];
            if(y<n)r2=b[y];
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2){
                h=mid-1;
            }
            else l=mid+1;
        }
        return -1;
    }
};