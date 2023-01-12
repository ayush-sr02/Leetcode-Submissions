class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int colns = strs[0].size();
        int ans =0;
        for(int i=0;i<colns;i++){
            for(int j=1;j<rows;j++){
                if(strs[j-1][i]>strs[j][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};