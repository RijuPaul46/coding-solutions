class Solution {
  public:
    // unordered_set<string>ans;
    int visited[51][51];
    unordered_set<string> solve(int i,int j,string &t1,string &t2,vector<vector<unordered_set<string>>>&dp){
        int m=t1.size();
        int n=t2.size();
        if(i==m || j==n){ unordered_set<string> ans;
            ans.insert("");
            return ans;
        }
        if(visited[i][j]){
            return dp[i][j];
        }
        visited[i][j]=1;
        if(t1[i]==t2[j]){
            auto st=solve(i+1,j+1,t1,t2,dp);
            unordered_set<string>ans;
            for(auto &s:st){
                ans.insert((t1[i]+s));
            }
            return dp[i][j]=ans;
        }
        auto left=solve(i+1,j,t1,t2,dp);
        auto right=solve(i,j+1,t1,t2,dp);
        int mx=0;
        for(auto &s:left)mx=max(mx,(int)s.size());
        for(auto &s:right)mx=max(mx,(int)s.size());
        unordered_set<string>ans;
        for(auto &s:left){
            if((int)s.size()==mx)ans.insert(s);

        }
        for(auto &s:right){
            if((int)s.size()==mx)ans.insert(s);

        }
        return dp[i][j]=ans;
    }

    vector<string> allLCS(string &t1, string &t2) {
        // code here
        int m=t1.size();
        int n=t2.size();
        vector<vector<unordered_set<string>>>dp(m,vector<unordered_set<string>>(n));
        memset(visited,0,sizeof(visited));// 
        // memset(dp,-1,sizeof(dp));
        auto st=solve(0,0,t1,t2,dp);
        // sort(ans.begin(),ans.end());
        vector<string>str;
        for(auto &s:st )str.push_back(s);
        sort(str.begin(),str.end());
        return str;

    }
};