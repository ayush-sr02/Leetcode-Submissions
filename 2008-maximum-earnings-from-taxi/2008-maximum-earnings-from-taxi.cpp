class Solution {
public:
    #define ll long long
    vector<ll> dp;
    
    ll solve(vector<vector<int>>&rides,int i){
        if(i>=rides.size()) return 0;
        if(dp[i]!=-1) return dp[i]; 
        ll notPick = solve(rides,i+1);
        ll pick=rides[i][1]-rides[i][0]+rides[i][2];
        int low=i+1,high=rides.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(rides[mid][0]<rides[i][1]) low=mid+1;
            else high=mid-1;
        }
        pick+=solve(rides,low);
        return dp[i] = max(pick,notPick);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(begin(rides),end(rides));
        int size=rides.size();
        dp.resize(size+1,-1);
        return solve(rides,0);
    }
};