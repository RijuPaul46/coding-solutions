class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m=arr.size();
        int n=arr[0].size();
        int mx=0,mxi=-1;
        for(int i=0;i<m;i++){
            auto it=upper_bound(arr[i].begin(),arr[i].end(),0)-arr[i].begin();
            int one=n-it;
            if(one>mx){mx=one;mxi=i;}
        }
        return mxi;
        
    }
};