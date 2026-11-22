class Solution {
public:
    bool checkString(string s) {
        bool b_occured=false;
        for(auto &c:s){
            if(c=='a'){
                if(b_occured)return false;
            }
            else b_occured=true;
        }
        return true;
    }
};