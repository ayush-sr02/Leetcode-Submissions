class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int dif = target-nums[i];
            if(mp.find(dif)!=mp.end()){
                return {i,mp[dif]};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};