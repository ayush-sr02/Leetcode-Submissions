class Solution {
public:
    int ans=0;
    
    void backtrack(vector<int>&nums,int k,unordered_map<int,int> &mp,int i){
        if(i==nums.size()){
            ans++;return;
        }
        if(mp[nums[i]-k]==0 and mp[nums[i]+k]==0){
            mp[nums[i]]++;
            backtrack(nums,k,mp,i+1);
            mp[nums[i]]--;
        }
        backtrack(nums,k,mp,i+1);
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        backtrack(nums,k,mp,0);
        
        return ans-1;
    }
};