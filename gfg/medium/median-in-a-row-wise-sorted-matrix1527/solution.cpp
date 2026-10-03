class Solution {
  public:
    pair<int,int> cnt(vector<vector<int>> &mat,int x){
        int m=mat.size();
        int n=mat[0].size();
        int less=0,equal=0;
        for(int i=0;i<m;i++){
            auto low=lower_bound(mat[i].begin(),mat[i].end(),x);
            auto high=upper_bound(mat[i].begin(),mat[i].end(),x);
            equal+=(high-low);
            less+=(low-mat[i].begin());
        }
        return {less,equal};
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int medn=(m*n+1)/2;
        // clearly bs on answer i will check how many elm <x
        // and how many ==x if 
        // use lower bound and upper bound to count ==x
        int l=1,h=2*(1e3);
        while(l<=h){
            int mid=l+(h-l)/2;
            auto [less,equal]=cnt(mat,mid);
            // cout<<"mid="<<mid<<" "<<less<<" "<<equal<<endl;
            if(less>=medn){
                h=mid-1;
            }
            else if(less+equal<=(medn-1))l=mid+1;
            else{
                if(equal==0)h=mid-1;
                else return mid;
            }
            
        }
        return -1;
        
    }
};
