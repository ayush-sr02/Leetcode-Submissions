class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        sort(begin(nums),end(nums));
        int pos=0,neg=0;
        for(auto i:nums){
            if(i<0) neg++;
            else pos++;
        }
        if(neg<=1 or pos==0) return nums[n-1]*nums[n-2]*nums[n-3];
        int left = nums[0]*nums[1];
        int right = nums[n-3]*nums[n-2];
        return max(left,right)*nums[n-1];
    }
};