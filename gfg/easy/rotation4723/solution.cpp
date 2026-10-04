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
