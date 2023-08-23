class Solution {
public:
    
    vector<int> dp;
    
    int solve(int i,vector<vector<int>>&offers){
        if(i>=offers.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int notPick = solve(i+1,offers);
        int pick = offers[i][2];
        int low=i+1,high=offers.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(offers[mid][0]<=offers[i][1]) low=mid+1;
            else high=mid-1;
        }
        pick+=solve(low,offers);
        return dp[i] = max(pick,notPick);
    } 
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int size=offers.size();
        dp.resize(size+1,-1);
        sort(begin(offers),end(offers));
        return solve(0,offers);
    }
};