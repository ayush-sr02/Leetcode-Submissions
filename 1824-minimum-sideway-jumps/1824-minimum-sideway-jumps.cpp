class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i,vector<int>&ob,int lane){
        if(i==ob.size()-1) return 0;
        if(dp[i][lane]!=-1) return dp[i][lane];
        int jump = 1e6;
        if(ob[i+1]!=lane) jump = solve(i+1,ob,lane);
        else{
            for(int it=1;it<=3;it++){
                if(it!=ob[i] and it!=lane) jump=min(jump,1+solve(i,ob,it));
            }
        }
        return dp[i][lane] = jump;
    }
    
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        dp.resize(n,vector<int> (4,-1));
        return solve(0,obstacles,2);
        
    }
};