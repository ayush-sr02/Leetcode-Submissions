class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int ans[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=0;
            }
        }
        for(int i=0;i<queries.size();i++){
            int row=queries[i][0];
            int col=queries[i][1];
            int x=queries[i][2];
            int y=queries[i][3];
            for(int j=row;j<=x;j++){
                for(int k=col;k<=y;k++){
                    ans[j][k]++;
                }
            }
        }
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res[i][j] = ans[i][j];
            }
        }
        return res;
    }
};