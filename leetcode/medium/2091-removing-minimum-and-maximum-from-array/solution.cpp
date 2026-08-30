class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int mni=-1,mxi=-1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x<mn){
                mn=x;
                mni=i;
            }
            if(x>mx){
                mx=x;
                mxi=i;
            }
        }
        // case 1 in one side removal both removed
        int mnn=min(mni,mxi);
        int mxx=max(mni,mxi);
        int c1=mxx+1;
        int c2=n-mnn;
        int c3=mnn+1 +n-mxx;
        return min(min(c1,c2),c3);
        
    }
};