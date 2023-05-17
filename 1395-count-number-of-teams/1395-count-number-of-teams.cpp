class Solution {
public:
    
    int dp[1001][1001][4];
    int d1[1001][1001][4];
    
    int solveF(int i,vector<int>&rating,int left,int prev){
        if(left==3) return 1;
        if(i>=rating.size()) return 0;
        if(dp[i][prev+1][left]!=-1) return dp[i][prev+1][left];
        int notPick = solveF(i+1,rating,left,prev);
        int pick=0;
        if(prev==-1 or rating[i]>rating[prev]) pick = solveF(i+1,rating,left+1,i);
        return dp[i][prev+1][left]=pick+notPick;
    }
    
    int solveB(int i,vector<int>&rating,int left,int prev){
        if(left==3) return 1;
        if(i>=rating.size()) return 0;
        if(d1[i][prev+1][left]!=-1) return d1[i][prev+1][left];
        int notPick = solveB(i+1,rating,left,prev);
        int pick=0;
        if(prev==-1 or rating[i]<rating[prev]) pick = solveB(i+1,rating,left+1,i);
        return d1[i][prev+1][left]=pick+notPick;
    }
    
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        memset(dp,-1,sizeof(dp));
        memset(d1,-1,sizeof(d1));
        int left=0;
        int prev=-1;
        int c1=solveF(0,rating,left,prev);
        prev=-1;
        int c2=solveB(0,rating,left,prev);
        return c1+c2;
    }
};