class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool solve(int i,int prev,int size,bool flag,vector<int>&nums){
        if(i==nums.size()) return size==0 or (size==2 and !flag);
        if(dp[i][size]!=-1) return dp[i][size];
        bool pick = false;
        if(prev==-1) pick = solve(i+1,i,1,flag,nums);
        else{
            if(size==1){
                if(nums[i]==nums[prev]) pick = solve(i+1,-1,0,flag,nums) or solve(i+1,i,size+1,flag,nums);
                if(nums[i]==nums[prev]+1) pick = solve(i+1,i,size+1,true,nums);
            }
            if(size==2){
                if(nums[prev]==nums[i] and !flag) pick = solve(i+1,-1,0,false,nums);
                if(flag and nums[prev]+1==nums[i]) pick = solve(i+1,-1,0,false,nums);
            }
        }
        return dp[i][size]=pick;
    }
    
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int> (4,-1));
        return solve(0,-1,0,false,nums);
    }
};