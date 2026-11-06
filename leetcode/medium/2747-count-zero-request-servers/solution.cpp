class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int mx_time=*max_element(queries.begin(),queries.end());
        vector<int>req(mx_time+1);
        for(auto &log:logs){
            if(log[1]<=mx_time)
            req[log[1]]++;
        }
        vector<int>ans(mx_time+1);
        int cnt=0;
        int j=1;
        for(int i=1;i<=mx_time;i++){
            cnt+=req[i];
            ans[i]=cnt;
            if(i>x){
                cnt-=req[j++];
            }
        }
        int q=queries.size();
        vector<int>res(q);
        for(int i=0;i<q;i++){
            res[i]=n-ans[queries[i]];
        }
        return res;
    }
};