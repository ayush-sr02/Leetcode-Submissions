class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        vector<int> v;
        sort(rbegin(nums),rend(nums));
        int cur=0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            v.push_back(nums[i]);
            if(cur>sum-cur) break;
        }
        
        return v;
    }
};