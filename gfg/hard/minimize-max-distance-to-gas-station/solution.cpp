#define db double
class Solution {
  public:
    bool check(vector<int>&stations,int k,double x){
        int n=stations.size();
        int cnt=0;
        double prev=(db)stations[0];
        for(int i=1;i<n;i++){
            db pos=(db)stations[i];
            double d=pos-prev;
            db req=ceil(d/x);
            cnt+=req-1;
            prev=pos;
            
        }
        return cnt<=k;
    }
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        db l=0.000000,h=1e6;
        db ans=-1;
        while(l<=h){
            db mid=(db)(h+l)/(db)2;
            // cout<<mid<<endl;
            if(check(stations,k,mid)){
                ans=mid;
                h=mid-0.000001;
            }
            else l=mid+0.000001;
        }
        return ans;
        
    }
};