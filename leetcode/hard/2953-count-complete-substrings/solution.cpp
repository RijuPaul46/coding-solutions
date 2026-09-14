class Solution {
public:
    int solve(int start,int end,string &word,int k){
        int mx_window=end-start+1;
        int window=k;
        int cnt=0;
        while(window<=mx_window){
            // cout<<window<<endl;
            unordered_map<char,int> mp;
            int j=start;
            for(int i=start;i<=end;i++){
                if(i<start+window){
                    mp[word[i]]++;
                }
                else{
                    mp[word[i]]++;
                    mp[word[j]]=mp[word[j]]-1;
                    if(mp[word[j]]==0)mp.erase(word[j]);
                    j++;
                    

                }
                if(i>=start+window-1){
                    if(mp.size()*k==(i-j+1)){
                    cout<<j<<" "<<i<<endl;
                    cnt++;
                    }
                }
                
            }
            window+=k;
        }
        return cnt;
    }
    int countCompleteSubstrings(string word, int k) {
        int n=word.size();
        int j=0;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(abs(word[i]-word[i-1])>2){
                cout<<j<<" "<<i-1<<endl;
                cnt+=solve(j,i-1,word,k);
                j=i;
            }
        }
        cnt+=solve(j,n-1,word,k);
        return cnt;
    }
};