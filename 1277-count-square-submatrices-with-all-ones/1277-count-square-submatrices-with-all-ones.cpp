class Solution {
public:
    
    int solve(int i,int j,int &ans,vector<vector<int>>&dp,vector<vector<int>> &matrix){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(i,j+1,ans,dp,matrix);
        int down=solve(i+1,j,ans,dp,matrix);
        int diag=solve(i+1,j+1,ans,dp,matrix);
        
        if(matrix[i][j]==1){
            int temp = min(right,min(down,diag))+1;
            ans+=temp;
            return dp[i][j] = temp;
        }
        else return dp[i][j]=0;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        solve(0,0,ans,dp,matrix);
        return ans;
    }
};