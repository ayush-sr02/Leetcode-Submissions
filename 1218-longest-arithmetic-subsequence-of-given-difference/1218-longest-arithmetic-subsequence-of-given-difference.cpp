class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        unordered_map<int,int> dp;
        int ans=0;
        for(auto i:arr){
            dp[i]=dp[i-dif]+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};