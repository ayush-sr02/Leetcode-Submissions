class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n,vector<int> (n));
        
        for(int i=0;i<n;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            ans[i]=row;
        }
        return ans;
    }
};