class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=0;
        int lower=1,higher=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) lower=higher+1;
            else if(nums[i]<nums[i-1]) higher=lower+1;
        }
        
        return max(lower,higher);
    }
};