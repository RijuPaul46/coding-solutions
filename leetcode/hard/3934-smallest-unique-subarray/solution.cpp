class Solution {
public:
    #define ll long long
    ll mod=1e9+7;
    ll base=1e5+1;
    ll pow(ll n,ll r){
        if(r==0)return 1;
        if(r%2==0){
            return pow((n*n)%mod,r/2);
        }
        return (n*pow((n*n)%mod,r/2))%mod;
    }
    ll modInv(ll n){
        return pow(n,mod-2)%mod;
    }
    bool check(int len,vector<int>&nums){
        //use rolling hash
        unordered_map<ll,ll>visited;
        
        int n=nums.size();
        int l=0;
        ll num=0;
        for(int i=0;i<n;i++){
            
            num= (num+nums[i]*pow(base,i-l+1))%mod;
            
             if(i>=(len-1)){
                
                visited[num]++;
                num=(num-(1ll*nums[l++]*base)%mod +mod)%mod;
                num=(num*modInv(base))%mod;
            }
        }
        for(auto &[_,count]:visited){
            if(count==1)return true;
        }
        return false;

    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return ans;
    }
};