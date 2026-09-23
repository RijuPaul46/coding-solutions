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