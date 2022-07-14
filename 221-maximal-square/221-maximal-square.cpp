class Solution {
public:
    int solve(int i,int j,vector<vector<char>>&matrix,int &mx,vector<vector<int>>&dp){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=solve(i,j+1,matrix,mx,dp);
        int down=solve(i+1,j,matrix,mx,dp);
        int diag=solve(i+1,j+1,matrix,mx,dp);
        
        if(matrix[i][j]=='1'){
            int ans=min(right,min(diag,down))+1;
            mx=max(mx,ans);
            return dp[i][j] = ans;
        }
        
        else return dp[i][j]=0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int mx=0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        solve(0,0,matrix,mx,dp);
        return mx*mx;
    }
};