class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=0,h=m-1;
        int row=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(matrix[mid][0]<=target){
                row=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(row==-1)return false;
        int col=lower_bound(matrix[row].begin(),matrix[row].end(),target)-matrix[row].begin();
        if(col==n || matrix[row][col]!=target)return false;
        return true;

    }
};