class Solution {
  public:
    bool check(vector<int>&arr,int k,int x){
        int n=arr.size();
        int prev=arr[0];
        int poss=1;
        for(int i=1;i<n;i++){
            if(arr[i]-prev >=x){
                poss++;
                prev=arr[i];
            }
        }
        return poss>=k;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int l=1,h=1e14;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(arr,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
            
        }
        return ans;
        
    }
};