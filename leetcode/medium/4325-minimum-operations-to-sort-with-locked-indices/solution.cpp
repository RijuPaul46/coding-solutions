class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        // if not in correct pos and locked 
        int n=nums.size();
        int cnt=0,lock=0;
        vector<int>idx(n+1);
        for(int i=0;i<n;i++){
            idx[nums[i]]=i;
        }
        for(int i=n;i>=1;i--){
            int id=idx[i];
            if(id==i-1)continue;
            if(locked[i-1]){
                locked[i-1]=0;
                lock++;
            }
            for(int j=id;j<(i-1);j++){
                if(locked[j]){
                    locked[j]=0;
                    lock++;
                }
                int temp=nums[j+1];
                idx[temp]=j;
                swap(nums[j],nums[j+1]);
                cnt++;
            }
        }
        if(lock>k)return -1;
        return cnt+lock;
    }
};